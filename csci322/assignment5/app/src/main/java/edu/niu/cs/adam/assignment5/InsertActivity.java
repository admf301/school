
package edu.niu.cs.adam.assignment5;
import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Point;
import android.os.Bundle;
import android.text.InputType;
import android.view.Gravity;
import android.view.View;
import android.widget.EditText;
import android.widget.GridLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class InsertActivity extends AppCompatActivity {

    private DatabaseManager databaseManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_insert);

        databaseManager = new DatabaseManager(this);
        updateScreen();
    }

    //add item to the database
    public void addItem(View view) {
        EditText nameET = findViewById(R.id.itemEditText);
        String nameStr = nameET.getText().toString();

        Toast.makeText(this, "Added = " + nameStr, Toast.LENGTH_LONG).show();

        try {

            Product newItem = new Product(0, nameStr);
            databaseManager.insertProduct(newItem);
        }

        catch(NumberFormatException nfe) {
            Toast.makeText(this, "error", Toast.LENGTH_LONG).show();
        }

        nameET.setText("");
        nameET.requestFocus();
        updateScreen();
    }

    //mini list on the insert screen
    public void updateScreen() {
        String databaseContentsString = "Items in the list\n";
        databaseManager = new DatabaseManager(this);

        ArrayList<Product> products = databaseManager.selectAll();

        for(Product product : products) {
            databaseContentsString += product.productToString() + "\n";
        }

        TextView databaseTV2 = findViewById(R.id.insertView);
        databaseTV2.setText(databaseContentsString);
    }

    public void goBack(View view) {
        finish();
    }
}
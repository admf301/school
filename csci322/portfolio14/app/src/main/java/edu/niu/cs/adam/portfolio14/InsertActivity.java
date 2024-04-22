
package edu.niu.cs.adam.portfolio14;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class InsertActivity extends AppCompatActivity {

    private DatabaseManager databaseManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_insert);

        databaseManager = new DatabaseManager(this);
    }

    //add item to the database
    public void addItem(View view) {
        EditText nameET = findViewById(R.id.toyNameEditText),
                 qtyET = findViewById(R.id.toyQuantityEditText),
                 priceET = findViewById(R.id.toyPriceEditText);

        String nameStr = nameET.getText().toString(),
               qtyStr = qtyET.getText().toString(),
               priceStr = priceET.getText().toString();

        Toast.makeText(this, "Name=" + nameStr + ", qty= " + qtyStr + " price=" + priceStr, Toast.LENGTH_LONG).show();

        try {
            double price = Double.parseDouble(priceStr);
            int quantity = Integer.parseInt(qtyStr);

            Product newItem = new Product(0, nameStr, quantity, price);
            databaseManager.insertProduct(newItem);
        }

        catch(NumberFormatException nfe) {
            Toast.makeText(this, "price or quantity error", Toast.LENGTH_LONG).show();
        }

        nameET.setText("");
        qtyET.setText("");
        priceET.setText("");
        nameET.requestFocus();
    }

    public void goBack(View view) {
        finish();
    }
}
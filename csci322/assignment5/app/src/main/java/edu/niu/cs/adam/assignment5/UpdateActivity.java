
package edu.niu.cs.adam.assignment5;

import static android.widget.ListPopupWindow.WRAP_CONTENT;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Point;
import android.os.Bundle;
import android.text.InputType;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.GridLayout;
import android.widget.ScrollView;
import android.widget.TextView;

import java.util.ArrayList;

public class UpdateActivity extends AppCompatActivity {
    private DatabaseManager databaseManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        databaseManager = new DatabaseManager(this);
        updateView();
    }

    //update the view after updating the table
    public void updateView() {
        ArrayList<Product> products = databaseManager.selectAll();

        if(products.size() > 0) {

            ScrollView scrollView = new ScrollView(this);
            GridLayout gridLayout = new GridLayout(this);
            gridLayout.setRowCount(products.size() + 1);
            gridLayout.setColumnCount(2);

            ButtonHandler handler = new ButtonHandler();

            Point point = new Point();
            getWindowManager().getDefaultDisplay().getSize(point);
            int width = point.x;

            for(Product product : products) {

                EditText nameET = new EditText(this);
                nameET.setText(product.getName());
                nameET.setId(product.getId() * 10);

                gridLayout.addView(nameET, (int) (width * 0.7), WRAP_CONTENT);

                Button updateBtn = new Button(this);
                updateBtn.setText("Update");
                updateBtn.setId(product.getId());
                updateBtn.setOnClickListener(handler);
                gridLayout.addView(updateBtn, (int) (width * 0.3), WRAP_CONTENT);

            }

            Button backBtn = new Button(this);
            backBtn.setText("Go Back");
            backBtn.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    finish();
                }
            });

            gridLayout.addView(backBtn, (int) (width * 0.3), WRAP_CONTENT);

            scrollView.addView(gridLayout);
            setContentView(scrollView);
        }
    }

    private class ButtonHandler implements View.OnClickListener {

        @Override
        public void onClick(View view) {
            int productID = view.getId();

            EditText nameET = findViewById(productID * 10);

            String nameStr = nameET.getText().toString();

            try {
                databaseManager.updateById(productID, nameStr);
                updateView();
            }

            catch(NumberFormatException nfe) {
                nfe.printStackTrace();
            }
        }
    }
}
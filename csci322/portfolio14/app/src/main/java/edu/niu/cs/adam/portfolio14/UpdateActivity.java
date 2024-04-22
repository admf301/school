
package edu.niu.cs.adam.portfolio14;

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
            gridLayout.setColumnCount(5);

            ButtonHandler handler = new ButtonHandler();

            Point point = new Point();
            getWindowManager().getDefaultDisplay().getSize(point);
            int width = point.x;

            for(Product product : products) {
                TextView idTV = new TextView(this);
                idTV.setText("" + product.getId());
                idTV.setGravity(Gravity.CENTER);

                EditText nameET = new EditText(this);
                nameET.setText(product.getName());
                nameET.setId(product.getId() * 10);

                EditText quantityET = new EditText(this);
                quantityET.setText("" + product.getQuantity());
                quantityET.setId(product.getId() * 10 + 1);
                quantityET.setInputType(InputType.TYPE_CLASS_NUMBER);

                EditText priceET = new EditText(this);
                priceET.setText("" + product.getPrice());
                priceET.setId(product.getId() * 10 + 2);
                priceET.setInputType(InputType.TYPE_CLASS_NUMBER);

                // Add views to the GridLayout
                gridLayout.addView(idTV, (int) (width * 0.1), WRAP_CONTENT);
                gridLayout.addView(nameET, (int) (width * 0.2), WRAP_CONTENT);
                gridLayout.addView(quantityET, (int) (width * 0.2), WRAP_CONTENT);
                gridLayout.addView(priceET, (int) (width * 0.2), WRAP_CONTENT);

                // Add the button to the GridLayout
                Button updateBtn = new Button(this);
                updateBtn.setText("Update");
                updateBtn.setId(product.getId());
                updateBtn.setOnClickListener(handler);
                gridLayout.addView(updateBtn, (int) (width * 0.2), WRAP_CONTENT);

            }

            Button backBtn = new Button(this);
            backBtn.setText("Go Back");
            backBtn.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    finish();
                }
            });

            gridLayout.addView(backBtn, (int) (width * 0.2), WRAP_CONTENT);

            //add the GridLayout to the ScrollView
            scrollView.addView(gridLayout);

            //set the ScrollView as the content view of the Activity
            setContentView(scrollView);
        }
    }

    private class ButtonHandler implements View.OnClickListener {

        @Override
        public void onClick(View view) {
            int productID = view.getId();

            EditText nameET = findViewById(productID * 10),
                     quantityET = findViewById(productID * 10 + 1),
                     priceET = findViewById(productID * 10 + 2);

            String nameStr = nameET.getText().toString(),
                   quantityStr = quantityET.getText().toString(),
                   priceStr = priceET.getText().toString();

            try {
                double price = Double.parseDouble(priceStr);
                int quantity = Integer.parseInt(quantityStr);

                databaseManager.updateById(productID, nameStr, quantity, price);
                updateView();
            }

            catch(NumberFormatException nfe) {
                nfe.printStackTrace();
            }
        }
    }
}
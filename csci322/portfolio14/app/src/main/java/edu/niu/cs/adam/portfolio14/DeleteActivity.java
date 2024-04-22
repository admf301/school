
package edu.niu.cs.adam.portfolio14;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RelativeLayout;
import android.widget.ScrollView;
import android.widget.Toast;
import java.util.ArrayList;

public class DeleteActivity extends AppCompatActivity {

    private DatabaseManager databaseManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_delete);

        databaseManager = new DatabaseManager(this);
        updateView();

    }

    //update the view after deleting an item from the table
    @SuppressLint("ResourceAsColor")
    private void updateView() {
        ArrayList<Product> products = databaseManager.selectAll();

        ScrollView scrollView = new ScrollView(this);
        RelativeLayout relativeLayout = new RelativeLayout(this);
        RadioGroup radioGroup = new RadioGroup(this);

        for(Product product : products)
        {
            RadioButton radioButton = new RadioButton(this);

            radioButton.setId(product.getId());
            radioButton.setText(product.productToString());

            radioGroup.addView(radioButton);
        }

        RadioButtonHandler handler = new RadioButtonHandler();
        radioGroup.setOnCheckedChangeListener(handler);

        scrollView.addView(radioGroup);
        relativeLayout.addView(scrollView);

        Button backButton = new Button(this);
        backButton.setText(R.string.back_button_label);
        backButton.setBackgroundResource(R.color.purple_500);
        backButton.setTextColor(R.color.black);

        backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });

        RelativeLayout.LayoutParams params =
                new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);

        params.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
        params.addRule(RelativeLayout.CENTER_HORIZONTAL);
        params.setMargins(0, 0, 0, 50);

        relativeLayout.addView(backButton, params);
        setContentView(relativeLayout);
    }

    private class RadioButtonHandler implements RadioGroup.OnCheckedChangeListener {

        @Override
        public void onCheckedChanged(RadioGroup radioGroup, int checkedId) {
            databaseManager.deleteById(checkedId);
            Toast.makeText(DeleteActivity.this, "product deleted", Toast.LENGTH_SHORT).show();
            updateView();
        }
    }

}
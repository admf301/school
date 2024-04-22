
package edu.niu.cs.adam.portfolio1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private EditText field1, field2;
    private TextView answerTV;
    private Button addBtn, subBtn, mulBtn, divBtn, clearBtn;
    private Integer num1, num2, result;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //connect the instance variables to the items on the screen (on activity_main.xml)
        field1 = findViewById(R.id.num1EditText);
        field2 = findViewById(R.id.num2EditText);
        addBtn = findViewById(R.id.addButton);
        subBtn = findViewById(R.id.subButton);
        mulBtn = findViewById(R.id.mulButton);
        divBtn = findViewById(R.id.divButton);
        clearBtn = findViewById(R.id.clearButton);
        answerTV = findViewById(R.id.answerTextView);

        clearBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //set fields and answer views to empty strings
                field1.setText("");
                field2.setText("");
                answerTV.setText("");
            }
        }); //clear

        addBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //check if fields are valid
                if(field1.getText().toString().matches("") || field2.getText().toString().matches(""))
                {
                    //error message
                    Toast.makeText(MainActivity.this, "Number fields cannot be empty", Toast.LENGTH_LONG).show();
                    return;
                }

                //do math
                num1 = Integer.parseInt(field1.getText().toString());
                num2 = Integer.parseInt(field2.getText().toString());
                result = num1 + num2;

                answerTV.setText("The sum is: " + result.toString());
            }
        }); //add

        subBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //check if fields are valid
                if(field1.getText().toString().matches("") || field2.getText().toString().matches(""))
                {
                    //error message
                    Toast.makeText(MainActivity.this, "Number fields cannot be empty", Toast.LENGTH_LONG).show();
                    return;
                }

                //do math
                num1 = Integer.parseInt(field1.getText().toString());
                num2 = Integer.parseInt(field2.getText().toString());
                result = num1 - num2;

                answerTV.setText("The difference is: " + result.toString());
            }
        }); //sub

        mulBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //check if fields are valid
                if(field1.getText().toString().matches("") || field2.getText().toString().matches(""))
                {
                    //error message
                    Toast.makeText(MainActivity.this, "Number fields cannot be empty", Toast.LENGTH_LONG).show();
                    return;
                }

                //do math
                num1 = Integer.parseInt(field1.getText().toString());
                num2 = Integer.parseInt(field2.getText().toString());
                result = num1 * num2;

                answerTV.setText("The product is: " + result.toString());
            }
        }); //mult

        divBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //check if fields are valid
                if(field1.getText().toString().matches("") || field2.getText().toString().matches(""))
                {
                    //error message
                    Toast.makeText(MainActivity.this, "Number fields cannot be empty", Toast.LENGTH_LONG).show();
                    return;
                }

                //check if divide by 0
                else if(field2.getText().toString().matches("0"))
                {
                    Toast.makeText(MainActivity.this, "Cannot divide by zero", Toast.LENGTH_LONG).show();
                    return;
                }

                //do math
                num1 = Integer.parseInt(field1.getText().toString());
                num2 = Integer.parseInt(field2.getText().toString());
                result = num1 / num2;

                answerTV.setText("The quotient is: " + result.toString());
            }
        }); //div
    }//end onCreate
}
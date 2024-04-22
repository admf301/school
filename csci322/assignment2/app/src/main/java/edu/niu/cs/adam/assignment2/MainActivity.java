
package edu.niu.cs.adam.assignment2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private EditText fieldA, fieldB, fieldC;
    private TextView answerTV1, answerTV2;
    private Button calcBtn, clearBtn;
    private Double numA, numB, numC, discrim, result1, result2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //create links from MainActivity to activity_main
        fieldA = findViewById(R.id.editTextA);
        fieldB = findViewById(R.id.editTextB);
        fieldC = findViewById(R.id.editTextC);
        calcBtn = findViewById(R.id.calcButton);
        clearBtn = findViewById(R.id.clearButton);
        answerTV1 = findViewById(R.id.textViewAnswer1);
        answerTV2 = findViewById(R.id.textViewAnswer2);

        clearBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //clear all 5 text fields/views
                fieldA.setText("");
                fieldB.setText("");
                fieldC.setText("");
                answerTV1.setText("");
                answerTV2.setText("");
            }
        }); 

        calcBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //check if any text fields are empty
                if(fieldA.getText().toString().matches("") || fieldB.getText().toString().matches("") || fieldC.getText().toString().matches(""))
                {
                    Toast.makeText(MainActivity.this, "Number fields cannot be empty", Toast.LENGTH_LONG).show();
                    return;
                }

                else if(fieldA.getText().toString().matches("0"))
                {
                    Toast.makeText(MainActivity.this, "A term cannot be 0", Toast.LENGTH_LONG).show();
                    return;
                }

                //get input
                numA = Double.parseDouble(fieldA.getText().toString());
                numB = Double.parseDouble(fieldB.getText().toString());
                numC = Double.parseDouble(fieldC.getText().toString());

                //calculate discriminant
                discrim = ((numB * numB) - (4 * numA * numC));

                //if discriminant < 0, outputs are imaginary
                if(discrim < 0)
                {
                    answerTV1.setText("Imaginary");
                    answerTV2.setText("Imaginary");
                    return;
                }

                //if discriminant = 0, output 1 and 2 are the same
                else if(discrim == 0)
                {
                    result1 = ((-numB) / (2 * numA));
                    result2 = ((-numB) / (2 * numA));

                    answerTV1.setText(String.format("%.4f", result1));
                    answerTV2.setText(String.format("%.4f", result2));
                    return;
                }

                //else output 1 = ((-b + sqrt(discriminant)) / 2a)
                //     output 2 = ((-b - sqrt(discriminant)) / 2a)
                else
                {
                    result1 = (((-numB) + Math.sqrt(discrim)) / (2 * numA));
                    result2 = (((-numB) - Math.sqrt(discrim)) / (2 * numA));
                    answerTV1.setText(String.format("%.4f", result1));
                    answerTV2.setText(String.format("%.4f", result2));
                    return;
                }
            }
        }); //calc
    }
}
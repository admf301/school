
package edu.niu.cs.adam.assignment3;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Spinner;

public class MainActivity extends AppCompatActivity {

    public static int image_id[] = {R.drawable.lang1, R.drawable.lang2, R.drawable.lang3,
            R.drawable.lang4, R.drawable.lang5};
    private Spinner xmlSpin;
    private ImageView picture;
    private Button selectBtn;
    public int selection = -1;
    public String xmlSelection;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        xmlSpin = findViewById(R.id.xmlSpinner);
        picture = findViewById(R.id.pictureIV);
        selectBtn = findViewById(R.id.selectButton);

        ArrayAdapter<CharSequence> xmlAdapter = ArrayAdapter.createFromResource(this, R.array.selection,R.layout.spinner_view);
        xmlSpin.setAdapter(xmlAdapter);

        xmlSpin.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                selection = i;
                xmlSelection = adapterView.getItemAtPosition(i).toString();
                picture.setImageResource(image_id[i]);
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {
                String defaultSelection = adapterView.getItemAtPosition(0).toString();
                picture.setImageResource(image_id[0]);
            }
        });
    }

    public void goToSelection(View view) {
        Intent displayIntent = new Intent(this, displayActivity.class);
        displayIntent.putExtra("select", selection);
        startActivity(displayIntent);
    }
}
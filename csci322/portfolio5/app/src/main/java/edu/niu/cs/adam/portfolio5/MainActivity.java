package edu.niu.cs.adam.portfolio5;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private Spinner xmlSpin, arraySpin, listSpin;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        xmlSpin = findViewById(R.id.xmlSpinner);
        arraySpin = findViewById(R.id.xmlSpinner2);
        listSpin = findViewById(R.id.xmlSpinner3);
        ArrayAdapter<CharSequence> xmlAdapter = ArrayAdapter.createFromResource(this, R.array.pizza_toppings, R.layout.spinner_view);
        xmlSpin.setAdapter(xmlAdapter);

        xmlSpin.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                String xmlSelection;
                xmlSelection = adapterView.getItemAtPosition(i).toString();
                Toast.makeText(MainActivity.this, "The xml selection is " + xmlSelection, Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });

        ArrayAdapter<String> arrayAdapter = new ArrayAdapter<>(this, R.layout.spinner_view, Spinnerinfo.sauceArray);
        arraySpin.setAdapter(arrayAdapter);

        arraySpin.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                String arraySelection;
                arraySelection = adapterView.getItemAtPosition(i).toString();
                Toast.makeText(MainActivity.this, "The array selection is " + arraySelection, Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });

        List<String> listValues = new ArrayList<>();
        listValues.add("Bears");
        listValues.add("Bulls");
        listValues.add("Sox");

        ArrayAdapter<String> listAdapter = new ArrayAdapter<>(this, R.layout.spinner_view, listValues);


        listSpin.setAdapter(listAdapter);
        listSpin.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                String listSelection;
                listSelection = adapterView.getItemAtPosition(i).toString();
                Toast.makeText(MainActivity.this, "The list selection is " + listSelection, Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });
    }
}
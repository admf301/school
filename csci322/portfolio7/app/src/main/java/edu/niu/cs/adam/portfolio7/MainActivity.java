package edu.niu.cs.adam.portfolio7;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    static final String MA_TAG = "APPLE";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        String create_str = getString(R.string.create_msg);
        Log.d(MA_TAG, create_str);
        Toast.makeText(this, create_str, Toast.LENGTH_LONG).show();
    }

    @Override
    protected void onStart() {
        super.onStart();
        String start_str = getString(R.string.start_msg);
        Log.d(MA_TAG, start_str);
    }

    @Override
    protected void onResume() {
        super.onResume();
        String resume_str = getString(R.string.resume_msg);
        Log.d(MA_TAG, resume_str);
    }

    @Override
    protected void onPause() {
        super.onPause();
        String pause_str = getString(R.string.pause_msg);
        Log.d(MA_TAG, pause_str);
    }

    @Override
    protected void onStop() {
        super.onStop();
        String stop_str = getString(R.string.stop_msg);
        Log.d(MA_TAG, stop_str);
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        String restart_str = getString(R.string.restart_msg);
        Log.d(MA_TAG, restart_str);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        String destroy_str = getString(R.string.destroy_msg);
        Log.d(MA_TAG, destroy_str);
    }

    public void doSecond(View view) {
        Intent secondIntent = new Intent(MainActivity.this, SecondActivity.class);
        startActivity(secondIntent);
    }
}
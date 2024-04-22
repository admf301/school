package edu.niu.cs.adam.portfolio7;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

public class SecondActivity extends AppCompatActivity {
    static final String SA_TAG = "APPLE";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        String create_str = getString(R.string.create_msg2);
        Log.d(SA_TAG, create_str);
    }

    @Override
    protected void onStart() {
        super.onStart();
        String start_str = getString(R.string.start_msg2);
        Log.d(SA_TAG, start_str);
    }

    @Override
    protected void onResume() {
        super.onResume();
        String resume_str = getString(R.string.resume_msg2);
        Log.d(SA_TAG, resume_str);
    }

    @Override
    protected void onPause() {
        super.onPause();
        String pause_str = getString(R.string.pause_msg2);
        Log.d(SA_TAG, pause_str);
    }

    @Override
    protected void onStop() {
        super.onStop();
        String stop_str = getString(R.string.stop_msg2);
        Log.d(SA_TAG, stop_str);
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        String restart_str = getString(R.string.restart_msg2);
        Log.d(SA_TAG, restart_str);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        String destroy_str = getString(R.string.destroy_msg2);
        Log.d(SA_TAG, destroy_str);
    }

    public void goBack(View view) {
        finish();
    }


}
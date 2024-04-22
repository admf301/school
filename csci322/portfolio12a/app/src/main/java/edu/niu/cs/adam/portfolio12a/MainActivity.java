
package edu.niu.cs.adam.portfolio12a;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private TextView textView;
    private Integer number;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = findViewById(R.id.textView1);
        number = 0;

        Thread thread = new Thread(countNumbers);
        thread.start();
    }

    @Override
    protected void onStart() {
        super.onStart();
        number = 0;
    }

    private Handler threadHandler = new Handler(new Handler.Callback() {
        @Override
        public boolean handleMessage(@NonNull Message message) {
            textView.setText(number.toString());
            return true;
        }
    });

    private Runnable countNumbers = new Runnable() {
        @Override
        public void run() {
            while(true) {
                threadHandler.sendEmptyMessage(0);
                number++;

                //1 number per sec
                try {
                    Thread.sleep(1000);
                }

                catch (InterruptedException exception) {
                    exception.printStackTrace();
                }
            }
        }
    };
}
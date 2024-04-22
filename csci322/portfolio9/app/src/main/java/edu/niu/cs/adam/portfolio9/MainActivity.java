
package edu.niu.cs.adam.portfolio9;

import androidx.appcompat.app.AppCompatActivity;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    private MediaPlayer drumsMP, ukuleleMP;
    private Button drumsBtn, ukuleleBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        drumsBtn = findViewById(R.id.drumButton);
        ukuleleBtn = findViewById(R.id.ukuleleButton);

        drumsMP = new MediaPlayer();
        drumsMP.reset();
        drumsMP = MediaPlayer.create(this, R.raw.drums);

        ukuleleMP = new MediaPlayer();
        ukuleleMP.reset();
        ukuleleMP = MediaPlayer.create(this, R.raw.ukulele);
    }

    public void pressDrums(View view) {
        if(drumsMP.isPlaying() == true) {
            drumsMP.pause();
        }

        else {
            drumsMP.start();
        }
    }

    public void pressUkulele(View view) {
        if(ukuleleMP.isPlaying() == true) {
            ukuleleMP.pause();
        }

        else {
            ukuleleMP.start();
        }
    }
}
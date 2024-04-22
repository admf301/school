
package edu.niu.cs.adam.assignment4;

import androidx.appcompat.app.AppCompatActivity;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    private MediaPlayer mediaPlayer;
    private int currentSound = 0;          

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }

    public void onClick(View view) {
        int soundID = 0;                   

        switch(view.getId()) {              

            case R.id.fart1_button:        
                soundID = R.raw.drums;   
                break;

            case R.id.fart2_button:
                soundID = R.raw.flute;
                break;

            case R.id.fart3_button:
                soundID = R.raw.guitar;
                break;

            case R.id.fart4_button:
                soundID = R.raw.piano;
                break;
        }

        if(soundID != currentSound) {       

            if(mediaPlayer != null) {      

                mediaPlayer.stop();       
                mediaPlayer.release();     
            }

            mediaPlayer = MediaPlayer.create(this, soundID); 
            mediaPlayer.start();            
            currentSound = soundID;        
        }

        else {                              

            if(mediaPlayer.isPlaying()) {  

                mediaPlayer.pause();     
            }

            else {                       

                mediaPlayer.start();     
            }
        }
    }
}
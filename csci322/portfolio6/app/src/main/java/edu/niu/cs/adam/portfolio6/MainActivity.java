package edu.niu.cs.adam.portfolio6;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView nameTV, quoteTV;
    private ImageView characterIV;
    private boolean isVisible;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        nameTV = findViewById(R.id.nameTextView);
        quoteTV = findViewById(R.id.quoteTextView);
        characterIV = findViewById(R.id.characterImageView);
        isVisible = false;
    }

    public void revealCharacter(View view) {
        int characterSub = -10;

        switch(view.getId())
        {
            case R.id.character1button:
                characterSub = 0;
                break;
            case R.id.character2button:
                characterSub = 1;
                break;
            case R.id.character3button:
                characterSub = 2;
                break;
            case R.id.character4button:
                characterSub = 3;
                break;
            case R.id.character5button:
                characterSub = 4;
                break;
            case R.id.character6button:
                characterSub = 5;
                break;
            default:
                characterSub = -1;
                break;
        }

        nameTV.setText(CharacterInfo.character_name[characterSub]);
        quoteTV.setText(CharacterInfo.character_quote[characterSub]);
        characterIV.setImageResource(CharacterInfo.image_id[characterSub]);

        if(!isVisible)
        {
            nameTV.setVisibility(View.VISIBLE);
            quoteTV.setVisibility(View.VISIBLE);
            characterIV.setVisibility(View.VISIBLE);
            isVisible = true;
        }
    }

}
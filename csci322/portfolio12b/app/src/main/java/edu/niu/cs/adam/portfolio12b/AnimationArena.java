package edu.niu.cs.adam.portfolio12b;

import android.graphics.Canvas;

public class AnimationArena {
    private Ball myBall;

    public AnimationArena() {
        myBall = new Ball();
    }

    //update position of the ball
    public void update(int width, int height) {
        myBall.move(0,0,width, height);
    }

    //draw the ball on screen
    public void draw(Canvas canvas) {
        //change color - erase the screen to re-draw ball
        canvas.drawRGB(205, 205, 205);

        //re-draw the ball
        myBall.draw(canvas);
    }
}

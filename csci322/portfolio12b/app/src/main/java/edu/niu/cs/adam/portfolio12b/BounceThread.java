package edu.niu.cs.adam.portfolio12b;

import android.graphics.Canvas;
import android.view.SurfaceHolder;

public class BounceThread extends Thread {
    private SurfaceHolder surfaceHolder;
    private AnimationArena animationArena;
    private boolean isRunning;

    public BounceThread(SurfaceHolder holder) {
        surfaceHolder = holder;
        animationArena = new AnimationArena();
        isRunning = true;
    }

    @Override
    public void run() {
        try {
            while(isRunning) {
                //have to lock canvas to be able to draw
                Canvas canvas = surfaceHolder.lockCanvas();
                animationArena.update(canvas.getWidth(), canvas.getHeight());
                animationArena.draw(canvas);

                //unlock canvas and display
                surfaceHolder.unlockCanvasAndPost(canvas);
            }
        }

        catch (NullPointerException npe) {
            npe.printStackTrace();
        }
    }

    public void endBounce() {
        isRunning = false;
    }

}

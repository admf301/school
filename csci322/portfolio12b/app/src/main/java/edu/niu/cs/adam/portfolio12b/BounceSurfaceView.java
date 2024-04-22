package edu.niu.cs.adam.portfolio12b;

import android.content.Context;
import android.util.AttributeSet;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import androidx.annotation.NonNull;

public class BounceSurfaceView extends SurfaceView implements SurfaceHolder.Callback{
    private BounceThread bounceThread;

    public BounceSurfaceView(Context context, AttributeSet attrs) {
        super(context, attrs);
        SurfaceHolder holder = getHolder();

        holder.addCallback(this);
        bounceThread = new BounceThread(holder);
    }

    @Override
    public void surfaceCreated(@NonNull SurfaceHolder surfaceHolder) {
        bounceThread.start();
    }

    @Override
    public void surfaceDestroyed(@NonNull SurfaceHolder surfaceHolder) {
        bounceThread.endBounce();

        //old way of nullifying a thread (will work 100%)
        Thread dummyThread = bounceThread;
        bounceThread = null;
        dummyThread.interrupt();
    }

    @Override
    public void surfaceChanged(@NonNull SurfaceHolder surfaceHolder, int i, int i1, int i2) {

    }
}

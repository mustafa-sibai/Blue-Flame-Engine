package com.Sandbox;

import android.app.Activity;
import android.os.Bundle;

import android.view.Surface;
import android.view.SurfaceView;
import android.view.SurfaceHolder;
import android.util.Log;

public class Sandbox extends Activity implements SurfaceHolder.Callback
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

		setContentView(R.layout.main);
        SurfaceView surfaceView = (SurfaceView)findViewById(R.id.surfaceview);
        surfaceView.getHolder().addCallback(this);

		Log.i("JAVACODE", "onCreate()");
		NativeOnCreate();
    }

	@Override
	protected void onStart() 
	{
	    super.onStart();
	    Log.i("JAVACODE", "onStart()");
	    NativeOnStart();
	}
	
	@Override
	protected void onResume() 
	{
	    super.onResume();
	    Log.i("JAVACODE", "onResume()");
	    NativeOnResume();
	}
	
	@Override
	protected void onPause() 
	{
	    super.onPause();
	    Log.i("JAVACODE", "onPause()");
	    NativeOnPause();
	}
	
	@Override
	protected void onStop() 
	{
	    super.onStop();
	    Log.i("JAVACODE", "onStop()");
	    NativeOnStop();
	}

	public void surfaceCreated(SurfaceHolder holder) 
	{
		Log.i("JAVACODE", "surfaceCreated()");
		NativeSurfaceCreated(holder.getSurface());
    }

	public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) 
	{
		Log.i("JAVACODE", "surfaceChanged()");
		NativeSurfaceChanged(holder.getSurface());
    }

    public void surfaceDestroyed(SurfaceHolder holder) 
	{
		Log.i("JAVACODE", "surfaceDestroyed()");
		NativeSurfaceDestroyed(null);
    }

    static 
    {
    	System.loadLibrary("Sandbox_Android_Cpp");
    }

	public native void NativeOnCreate();
	public native void NativeOnStart();
	public native void NativeOnResume();
	public native void NativeOnPause();
	public native void NativeOnStop();
	public native void NativeSurfaceCreated(Surface surface);
	public native void NativeSurfaceChanged(Surface surface);
	public native void NativeSurfaceDestroyed(Surface surface);
}
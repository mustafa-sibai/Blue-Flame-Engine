package com.vault16software.sandbox;

import android.app.Activity;
import android.os.Bundle;
import android.view.Surface;
import android.view.SurfaceView;
import android.view.SurfaceHolder;
import android.util.Log;

public class Sandbox_Android extends Activity implements SurfaceHolder.Callback
{
	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);

		setContentView(R.layout.main);
        SurfaceView surfaceView = (SurfaceView)findViewById(R.id.surfaceview);
        surfaceView.getHolder().addCallback(this);

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
	    Log.i("..", "onResume()");
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

	public void surfaceChanged(SurfaceHolder holder, int format, int w, int h) 
	{
		Log.i("JAVACODE", "surfaceChanged()");
		NativeSetSurface(holder.getSurface());
    }
	
    public void surfaceCreated(SurfaceHolder holder) 
	{
		Log.i("JAVACODE", "surfaceCreated()");
    }
	
    public void surfaceDestroyed(SurfaceHolder holder) 
	{
		Log.i("JAVACODE", "surfaceDestroyed()");
		NativeSetSurface(null);
    }

	public native void NativeOnCreate();
	public native void NativeOnStart();
	public native void NativeOnResume();
	public native void NativeOnPause();
	public native void NativeOnStop();
	public native void NativeSetSurface(Surface surface);

	static 
	{
		System.loadLibrary("Sandbox_Android");
	}
}
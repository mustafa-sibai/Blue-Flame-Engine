#include <jni.h>
#include <errno.h>

#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#include <android/log.h>

#include <BF/System/Log.h>
#include <BF/Platform/Android/EJNI.h>
#include <android/native_window_jni.h>
#include "Main.cpp"

using namespace BF::Platform::Android;

extern "C"
{
	JNIEXPORT void JNICALL Java_com_Sandbox_Sandbox_NativeOnCreate(JNIEnv* env, jobject thiz)
	{
		BFE_LOG_INFO("NativeOnCreate");
		EJNI::NativeOnCreate(main);
	}

	JNIEXPORT void JNICALL Java_com_Sandbox_Sandbox_NativeOnStart(JNIEnv* env, jobject thiz)
	{
		BFE_LOG_INFO("NativeOnStart");
	}

	JNIEXPORT void JNICALL Java_com_Sandbox_Sandbox_NativeOnResume(JNIEnv* env, jobject thiz)
	{
		BFE_LOG_INFO("NativeOnResume");
	}

	JNIEXPORT void JNICALL Java_com_Sandbox_Sandbox_NativeOnPause(JNIEnv* env, jobject thiz)
	{
		BFE_LOG_INFO("NativeOnPause");
	}

	JNIEXPORT void JNICALL Java_com_Sandbox_Sandbox_NativeOnStop(JNIEnv* env, jobject thiz)
	{
		BFE_LOG_INFO("NativeOnStop");
	}

	JNIEXPORT void JNICALL Java_com_Sandbox_Sandbox_NativeSurfaceCreated(JNIEnv* env, jobject thiz, jobject surface)
	{
		BFE_LOG_INFO("NativeSurfaceCreated");
		EJNI::NativeSetSurface(ANativeWindow_fromSurface(env, surface));
	}

	JNIEXPORT void JNICALL Java_com_Sandbox_Sandbox_NativeSurfaceChanged(JNIEnv* env, jobject thiz, jobject surface)
	{
		BFE_LOG_INFO("NativeSurfaceChanged");
	}

	JNIEXPORT void JNICALL Java_com_Sandbox_Sandbox_NativeSurfaceDestroyed(JNIEnv* env, jobject thiz, jobject surface)
	{
		BFE_LOG_INFO("NativeSurfaceDestroyed");
	}
}
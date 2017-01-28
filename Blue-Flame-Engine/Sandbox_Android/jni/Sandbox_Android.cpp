#include "BF/Platform/Android/JNI.h"
#include <jni.h>
#include <android/native_window_jni.h>
#include "../Sandbox/Sandbox/Main.cpp"

using namespace BF::Platform::Android;

extern "C"
{

	JNIEXPORT void JNICALL Java_com_vault16software_sandbox_Sandbox_1Android_NativeOnCreate(JNIEnv* env, jobject thiz)
	{
		JNI::NativeOnCreate(main);
	}

	JNIEXPORT void JNICALL Java_com_vault16software_sandbox_Sandbox_1Android_NativeOnStart(JNIEnv* env, jobject thiz)
	{
		JNI::NativeOnStart();
	}

	JNIEXPORT void JNICALL Java_com_vault16software_sandbox_Sandbox_1Android_NativeOnResume(JNIEnv* env, jobject thiz)
	{
		JNI::NativeOnResume();
	}

	JNIEXPORT void JNICALL Java_com_vault16software_sandbox_Sandbox_1Android_NativeOnPause(JNIEnv* env, jobject thiz)
	{
		JNI::NativeOnPause();
	}

	JNIEXPORT void JNICALL Java_com_vault16software_sandbox_Sandbox_1Android_NativeOnStop(JNIEnv* env, jobject thiz)
	{
		JNI::NativeOnStop();
	}

	JNIEXPORT void JNICALL Java_com_vault16software_sandbox_Sandbox_1Android_NativeSetSurface(JNIEnv* env, jobject thiz, jobject surface)
	{
		JNI::NativeSetSurface(ANativeWindow_fromSurface(env, surface));
	}
}
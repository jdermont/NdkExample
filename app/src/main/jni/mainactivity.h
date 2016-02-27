#ifndef NDKEXAMPLE_MAINACTIVITY_H
#define NDKEXAMPLE_MAINACTIVITY_H

#include <jni.h>
#include <android/log.h>
#include <string>
#include <sstream>

#ifdef __cplusplus
extern "C" {
#endif

jstring Java_omg_jd_ndkexample_MainActivity_helloFromNative(JNIEnv *, jobject, jstring);
jdouble Java_omg_jd_ndkexample_MainActivity_quadraticSum(JNIEnv *, jobject, jdoubleArray);

#ifdef __cplusplus
}
#endif

#endif

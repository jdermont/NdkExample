#include "mainactivity.h"

using namespace std;

JNIEXPORT jstring Java_omg_jd_ndkexample_MainActivity_helloFromNative(JNIEnv *env, jobject instance, jstring name) {
    const char *nativeName = env->GetStringUTFChars( name, 0);

    ostringstream ostream;
    ostream << "Hello, " << nativeName << "!";

    env->ReleaseStringUTFChars(name, nativeName);

    return env->NewStringUTF(ostream.str().c_str());
}

JNIEXPORT jdouble JNICALL
Java_omg_jd_ndkexample_MainActivity_quadraticSum(JNIEnv *env, jobject instance, jdoubleArray toSum_) {
    __android_log_print(ANDROID_LOG_DEBUG, "NDK_EXAMPLE", "getting the array...");
    jdouble *toSum = env->GetDoubleArrayElements(toSum_, NULL);
    jsize toSumSize = env->GetArrayLength(toSum_);
    __android_log_print(ANDROID_LOG_DEBUG, "NDK_EXAMPLE", "array size is %d",toSumSize);

    double output = 0.0;

    for (int i=0;i<toSumSize;i++) {
        output += toSum[i]*toSum[i];
    }

    __android_log_print(ANDROID_LOG_DEBUG, "NDK_EXAMPLE", "releasing elements...");
    env->ReleaseDoubleArrayElements(toSum_, toSum, 0);
    __android_log_print(ANDROID_LOG_DEBUG, "NDK_EXAMPLE", "elements released");

    return output;
}

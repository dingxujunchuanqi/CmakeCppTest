#include <jni.h>
#include <string>
//引用安卓日志头文件
#include <android/log.h>

extern "C"
JNIEXPORT jstring //返回值 string 类型 再C里面就是jstring

JNICALL  //com_example_administrator_myfirstc_MainActivity 全类名，stringFromJNI 方法名，约定用“-”连接
Java_com_example_administrator_myfirstc_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
/**
 * 返回一个字符串
 */
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_administrator_myfirstc_MainActivity_myJni(JNIEnv *env, jobject instance) {

//    return (env*)->NewStringUTF(env,"myJNi");
    return env->NewStringUTF("myJNI");
}
/**
 * java层传入int 类型，返回一个int 类型；jint相当于java的int 类型，也可以直接用int
 */
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_administrator_myfirstc_MainActivity_getSum(JNIEnv *env, jobject instance, jint a,
                                                            jint b) {
    jsize sum;
    sum = a + b;
    return sum;
}
/**
 * 从java层 传入一个字符串然后返回 ，%s表示字符串
 */
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_administrator_myfirstc_MainActivity_getStr(JNIEnv *env, jobject instance,
                                                            jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);
    jint i = 5;
    __android_log_print(ANDROID_LOG_INFO, "DD", "str = %s与i = %d", str, i);
    __android_log_print(ANDROID_LOG_INFO, "DD", "str = AA");
    env->ReleaseStringUTFChars(str_, str);
    jstring jStr = env->NewStringUTF(str);
    return jStr;
}
/**
 * 从java层传入一个数组，再c语言层遍历打印 %d表示整形
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_example_administrator_myfirstc_MainActivity_showElemnet(JNIEnv *env, jobject instance,
                                                                 jintArray arr_) {
    jint *arr = env->GetIntArrayElements(arr_, NULL);
    jint len = env->GetArrayLength(arr_);
    jint i;
    for (int i = 0; i < len; ++i) {
        __android_log_print(ANDROID_LOG_INFO, "DD", "i = %d", arr[i]);
    }
    env->ReleaseIntArrayElements(arr_, arr, 0);
}
/**
 * 返回一个数组
 */
extern "C"
JNIEXPORT jintArray JNICALL
Java_com_example_administrator_myfirstc_MainActivity_getArr(JNIEnv *env, jobject instance) {

    jintArray arr = env->NewIntArray(3);//定义数组
    jint *arr_ = env->GetIntArrayElements(arr, NULL);//定义数组指针
    jint i;
//    jint buf[3];//定义数组长度
    for (int i = 0; i < 3; ++i) {
//        __android_log_print(ANDROID_LOG_INFO, "DD", "i = %d", buf[i]);
        arr_[i] = i;
//        __android_log_print(ANDROID_LOG_INFO, "DD", "ia = %d", buf[i]);
    }
//    env->SetIntArrayRegion(arr, 0, 3, buf);
    env->SetIntArrayRegion(arr,0,3,arr_);//把arr_ 赋值给arr 然后返回

    return arr;
}
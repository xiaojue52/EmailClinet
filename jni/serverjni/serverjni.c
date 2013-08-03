#include <string.h>
#include <stdio.h>
#include <jni.h>
#include "server.h"
#include <android/log.h>

jstring
Java_com_wu_serverjni_ServerJni_test( JNIEnv* env,
        jobject thiz )
{
	return (*env)->NewStringUTF(env, test1());
	//return 1;
}

jint
Java_com_wu_serverjni_ServerJni_login(JNIEnv* env,
        jobject thiz ,jobject juserInfo)
{
	jclass cls = (*env)->GetObjectClass(env,juserInfo);
	jfieldID userId,passId,addrId;
	userId = (*env)->GetFieldID(env, cls, "username", "Ljava/lang/String;");
	passId = (*env)->GetFieldID(env, cls, "password", "Ljava/lang/String;");
	addrId = (*env)->GetFieldID(env, cls, "serAddr", "Ljava/lang/String;");

	jstring username = (*env)->GetObjectField(env,juserInfo,userId);
	jstring password = (*env)->GetObjectField(env,juserInfo,passId);
	jstring serAddr = (*env)->GetObjectField(env,juserInfo,addrId);
    const char* u = (*env)->GetStringUTFChars(env,username,NULL);
    const char* p = (*env)->GetStringUTFChars(env,password,NULL);
    const char* s = (*env)->GetStringUTFChars(env,serAddr,NULL);
	int ret = 0;
	char buff[100];
	memset(buff,0x00,100);
	sprintf(buff,"q login %s %s",u,p);
	//char* logCom = strcat(strcat(strcat(strcat(strcat(temp,"q")," "),u)," "),p);
	//__android_log_write(ANDROID_LOG_ERROR, "Tag", buff);
    char* logCom = buff;
    ret = login(s,logCom);
	return ret;
}
jint
Java_com_wu_serverjni_ServerJni_logout(JNIEnv* env, jobject thiz)
{
	int ret = 0;
	ret = logout();
	return ret;
}

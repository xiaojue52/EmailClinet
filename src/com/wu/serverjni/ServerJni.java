package com.wu.serverjni;

import com.wu.data.UserInfo;


public class ServerJni {
	static {
        System.loadLibrary("serverjni");
    }  
	public static native String test();
	
    public static native int login(UserInfo userInfo);
    
    public static native int logout();
    
    public static native int getInboxMes();
}

#include "server.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <android/log.h>
#define MAXLINE 1024
#define SERV_PORT 143

char* test1(){
	return "ssss";
}
int sockfd;

int login(const char* addr, char* logCom){
	int ret=0;
	char* myStr;

	struct sockaddr_in servaddr;
	char sendline[MAXLINE],recvline[MAXLINE];

	if ((sockfd = socket(AF_INET,SOCK_STREAM,0))<0){
		myStr = "create socket error!";
		ret = -1;
		return ret;
	}
	memset(&servaddr,0x00,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	//servaddr.sin_addr.s_addr = inet_addr(addr);
	servaddr.sin_port = htons(SERV_PORT);
	//struct hostent * gethostbyname (const char *name)
	struct hostent *hostinfo = gethostbyname (addr);
	if (hostinfo == NULL)
	{
		__android_log_write(ANDROID_LOG_ERROR, "Test0", "no host!");
		return -4;
	}
	else{
		servaddr.sin_addr = *(struct in_addr *)hostinfo->h_addr;
		//struct in_addr aaa = *(struct in_addr *)test;
		//servaddr.sin_addr.s_addr = (int)*(hostinfo->h_addr);
		char buff[1024];
		memset(buff,0x00,1024);
		sprintf(buff,"%i....%s",servaddr.sin_addr.s_addr,addr);
		__android_log_write(ANDROID_LOG_ERROR, "Test0", buff);
	}
	if (connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0){
		myStr = "connect error!";
		ret = -2;
		return ret;
	}

	int re = recv(sockfd, recvline, MAXLINE,0);
	if (re == 0){
		myStr = "recv error!";
		ret = -3;
		return ret;
	}
	else
		recvline[re]='\0';
	__android_log_write(ANDROID_LOG_ERROR, "Test1", recvline);
	char buff[100];
	memset(buff,0x00,100);
	sprintf(buff,"%s\n",logCom);
	__android_log_write(ANDROID_LOG_ERROR, "Test3", buff);
	send(sockfd,buff,strlen(buff),0);

	memset(recvline,'\0',MAXLINE);
	re = recv(sockfd, recvline, MAXLINE,0);
	if (re == 0){
		__android_log_write(ANDROID_LOG_ERROR, "Test2", recvline);
		myStr = "recv error!";
		ret = -4;
		return ret;
	}
	recvline[re] = '\0';
	__android_log_write(ANDROID_LOG_ERROR, "Test3", recvline);
	recvline[4] = '\0';
	myStr = recvline;

	if (strcmp(myStr,"q OK")){
		__android_log_write(ANDROID_LOG_ERROR, "Test3", myStr);
		ret = -5;
		close(sockfd);
	}

	return ret;
}


int logout(){
	int ret = 0;
	char recvline[1024];
	memset(recvline,0x00,1024);
	send(sockfd,"q logout\n",strlen("q logout\n"),0);
	int re = recv(sockfd, recvline, MAXLINE,0);
	if (re == 0){
		__android_log_write(ANDROID_LOG_ERROR, "Test2 logout", recvline);
		ret = -4;
		return ret;
	}
	recvline[re] = '\0';
	__android_log_write(ANDROID_LOG_ERROR, "Test3 logout", recvline);
	close(sockfd);
	return ret;
}

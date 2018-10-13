#include<stdio.h>
#include<string.h>
#include<time.h>
#include<thread>

/* Linux下编写c++11多线程代码 */
/* 编译时需要加上-std=c++11 -pthread */

#define TIME_FILENAME "time.txt"

void FileThreadFunc(){
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char timeStr[32] = {0};
    sprintf(timeStr,"%04d %02d %02d %02d:%02d:%02d",t->tm_year + 1900,t->tm_mon + 1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
    FILE* fp = fopen(TIME_FILENAME,"w");
    if(fp == NULL){
        printf("Failed to create time.txt.\n");
        return;
    }

    size_t write_size = strlen(timeStr);
    size_t ret = fwrite(timeStr,1,write_size,fp);
    if(ret != write_size){
        printf("write file error.\n");
    }

    fclose(fp);
}


int main(){
    std::thread t(FileThreadFunc);
    if(t.joinable())
        t.join();

    FILE* fp = fopen(TIME_FILENAME,"r");
    if(fp == NULL){
        printf("open file error.\n");
        return -2;
    }

    char buf[32] = {0};
    int read_size = fread(buf,1,32,fp);
    if(read_size == 0){
        printf("read file error.\n");
        return -3;
    }

    printf("Current Time is : %s.\n",buf);

    return 0;
}

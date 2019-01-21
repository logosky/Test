#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<list>
#include <sstream>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include<boost/unordered_map.hpp>
#include<boost/bind.hpp>
#include<boost/function.hpp>
#include<json/json.h>

//g++ test.cpp -I /home/liukai/workspace/common_inc/boost/ -g -o test

using namespace std;

std::string get_time_str(int64_t timestamp, const char* fmt = "%F %T");

void test_json();

int main(int argc, char** argv)
{
    for(int i=0;i<argc;i++)
        cout<<"i:"<<i <<" -> "<<argv[i]<<endl;
    
    //srand(time(NULL));
    for(int i = 0;i<10;i++)
    {
        int a = rand() % 100000;
        int b = rand() % 100000;
        cout<<"a:"<<a <<",b:"<< b<<endl;
    }
    
    int len = 0;
    char log_buff[1024] = {0};

    snprintf(log_buff, 1024, "val:%d", 1024);
    len = strlen(log_buff);
    printf("buf:%s,len:%d\n", log_buff, len);
    
    time_t now = time(NULL);
    printf("now:%d,%s\n", now, get_time_str(now).c_str());
    
    test_json();

    return 0;
}

std::string get_time_str(int64_t timestamp, const char* fmt)
{
    time_t ttime = timestamp;

    struct tm st;

    localtime_r(&ttime, &st);

    char buf[20] = {0};

    strftime(buf, sizeof(buf), fmt, &st);

    return std::string(buf);
}

void test_json()
{
    Json::Value mq_gift_info;
    mq_gift_info["type"] = "ycjy";
    mq_gift_info["tag_id"] = 123;
    
    std::string gift_info_str = mq_gift_info.toStyledString();
    printf("str:%s\n", gift_info_str.c_str());
}

#include<iostream>

/*
 *
 * 1. 不想被拷贝的对象,应该将其拷贝构造和构造函数声明为private
 * 2. C++11中可采用delete关键字,指明其不能被拷贝,default关键字表示为缺省可拷贝
 *
 */

class NoCopy{
public:
    NoCopy();
    NoCopy(NoCopy& copy) = delete;
private:
    //NoCopy(NoCopy& copy);
    NoCopy& operator=(const NoCopy& copy);
    int val_;
};

int main(){
    NoCopy n;
    NoCopy c;
    n = c;
    return 0;
}

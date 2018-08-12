#include<iostream>

using namespace std;

class Base{
public:
    virtual void f(){
        cout<<"Base::f"<<endl;
    }

    virtual void g(){
        cout<<"Base::g"<<endl;
    }

    virtual void h(){
        cout<<"Base::h"<<endl;
    }
};

int main(){
    typedef void(*Fun)(void);
    Base b;

    Fun pFun = NULL;

#if  0
    cout<<"虚函数表地址:"<<(int*)(&b)<<endl;
    cout<<"第一个虚函数地址:"<<(int*)*(int*)(&b)<<endl;

    pFun = (Fun)*((int*)*(int*)(&b));
    pFun();
#endif

#if 1
    pFun = (Fun)*((long*)*(long*)(&b)+0);    //Base::f()
    pFun();
    pFun = (Fun)*((long*)*(long*)(&b)+1);    //Base::g()
    pFun();
    pFun = (Fun)*((long*)*(long*)(&b)+2);    //Base::h()
    pFun();
#endif
    return 0;
}

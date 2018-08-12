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


class Derive: public Base{
public:
    void f(){
        cout<<"Derive::f"<<endl;
    }

    void g1(){
        cout<<"Derive::g1"<<endl;
    }

    void h1(){
        cout<<"Derive::h1"<<endl;
    }
};


int main(){
    typedef void(*Fun)(void);
    Derive d;

    Fun pFun = NULL;

#if 0
    //Base类中被声明为virtual的函数才会被加入到虚函数表中
    //父类的成员函数在子类成员函数的前面,按照声明的顺序
    pFun = (Fun)*((long*)*(long*)(&d)+0);

    pFun(); //预期打印Derive的f()函数
#endif

#if 1
    /* Derive重载f()函数,观察虚表的结构 */
    /* 这里虚函数表中第一个位置Derive中的f函数覆盖的Base的f函数 */
    pFun = (Fun)*((long*)*(long*)(&d)+0);
    pFun();
    pFun = (Fun)*((long*)*(long*)(&d)+1);
    pFun();
    pFun = (Fun)*((long*)*(long*)(&d)+2);
    pFun();

    /* 父类的指针可以有多种选择 */
    Base* b = new Derive();
    b->f();
    /* 不是虚函数不会出现在虚表中 */
    /* pFun = (Fun)*((long*)*(long*)(&d)+3); */
    /* pFun(); */
    /* pFun = (Fun)*((long*)*(long*)(&d)+4); */
    /* pFun(); */
#endif
    return 0;
}


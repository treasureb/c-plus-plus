#include<iostream>

using namespace std;

class Base1{
    virtual void f(){
        cout<<"Base1::f"<<endl;
    }
    
    virtual void g(){
        cout<<"Base1::g"<<endl;
    }
    
    virtual void h(){
        cout<<"Base1::h"<<endl;
    }
};

class Base2{
    virtual void f(){
        cout<<"Base2::f"<<endl;
    }
    
    virtual void g(){
        cout<<"Base2::g"<<endl;
    }
    
    virtual void h(){
        cout<<"Base2::h"<<endl;
    }
};

class Base3{
    virtual void f(){
        cout<<"Base3::f"<<endl;
    }
    
    virtual void g(){
        cout<<"Base3::g"<<endl;
    }
    
    virtual void h(){
        cout<<"Base3::h"<<endl;
    }
};

class Derive: public Base1,public Base2,public Base3{
    void f(){
        cout<<"Derive f"<<endl;
    }

    void g1(){
        cout<<"Derive g1"<<endl;
    }

    void h1(){
        cout<<"Derive h1"<<endl;
    }
};

int main(){
    typedef void(*Fun)(void);
    Derive d;
    Fun pFun = NULL;
#if 1
    /* 继承的第一个基类 */
    pFun = (Fun)*((long*)*(long*)(&d)+0);
    pFun();
    pFun = (Fun)*((long*)*(long*)(&d)+1);
    pFun();
    pFun = (Fun)*((long*)*(long*)(&d)+2);
    pFun();
#endif
#if 0
    /* Derive中继承了三个虚表,按照基类的声明顺序 */
   pFun = (Fun)*(long*)*((long*)(&d)+0); 
   pFun();
   pFun = (Fun)*(long*)*((long*)(&d)+1); 
   pFun();
   pFun = (Fun)*(long*)*((long*)(&d)+2); 
   pFun();
#endif
    return 0;
}

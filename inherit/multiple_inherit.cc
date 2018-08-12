#include<iostream>

using namespace std;

class Base1{
public:
    int base1_;
    Base1():base1_(10){}

    virtual void f(){
        cout<<"Base1:: f()"<<endl;
    }
    virtual void g(){
        cout<<"Base1:: g()"<<endl;
    }
    virtual void h(){
        cout<<"Base1:: h()"<<endl;
    }
};
class Base2{
public:
    int base2_;
    Base2():base2_(20){}

    virtual void f(){
        cout<<"Base2:: f()"<<endl;
    }
    virtual void g(){
        cout<<"Base2:: g()"<<endl;
    }
    virtual void h(){
        cout<<"Base2:: h()"<<endl;
    }
};
class Base3{
public:
    int base3_;
    Base3():base3_(30){}

    virtual void f(){
        cout<<"Base3:: f()"<<endl;
    }
    virtual void g(){
        cout<<"Base3:: g()"<<endl;
    }
    virtual void h(){
        cout<<"Base3:: h()"<<endl;
    }
};

class Derive:public Base1,public Base2,public Base3{
public:
    int derive_;
    Derive():derive_(100){}
    virtual void f(){
        cout<<"Derive::f()"<<endl;
    }
    virtual void g1(){
        cout<<"Derive::g1()"<<endl;
    }
};


int main(){
    typedef void(*Fun)(void);
    Derive d;
    Fun pFun = NULL;
    long** pVtab = (long**)&d;
    cout<<"[0] Base1::pvtr_->"<<endl;
    pFun = (Fun)pVtab[0][0];
    cout<<" [0]";pFun();

    pFun = (Fun)pVtab[0][1];
    cout<<" [1]";pFun();

    pFun = (Fun)pVtab[0][2];
    cout<<" [2]";pFun();

    pFun = (Fun)pVtab[0][3];
    cout<<" [3]";pFun();

    pFun = (Fun)pVtab[0][4];
    cout<<" [4]";pFun();

    cout<<"[1] Base1.base1_ = "<<(long)pVtab[1]<<endl;
    
    int s = sizeof(Base1)/4;

    cout<<"["<<s<<"] Base2::vptr_->"<<endl;
    pFun = (Fun)pVtab[s][0];
    cout << "     [0] "; pFun();
     
    pFun = (Fun)pVtab[s][1];
    cout << "     [1] "; pFun();
     
    pFun = (Fun)pVtab[s][2];
    cout << "     [2] "; pFun();
     
    pFun = (Fun)pVtab[s][3];
    cout << "     [3] ";
    cout<<pFun<<endl;
     
    cout << "["<< s+1 <<"] Base2.ibase2 = " << (long)pVtab[s+1] << endl;
     
    s = s + sizeof(Base2)/4;
     
    cout << "[" << s << "] Base3::_vptr->"<<endl;
    pFun = (Fun)pVtab[s][0];
    cout << "     [0] "; pFun();
     
    pFun = (Fun)pVtab[s][1];
    cout << "     [1] "; pFun();
     
    pFun = (Fun)pVtab[s][2];
    cout << "     [2] "; pFun();
     
    pFun = (Fun)pVtab[s][3];
    cout << "     [3] ";
    cout<<pFun<<endl;
     
    s++;
    cout << "["<< s <<"] Base3.ibase3 = " << (long)pVtab[s] << endl;
    s++;
    cout << "["<< s <<"] Derive.iderive = " << (long)pVtab[s] << endl;
    return 0;
}

#include<iostream>

using namespace std;

class Parent{
public:
    Parent()
        :parent_(10)
    {}

    virtual void f(){
        cout<<"Parent::f()"<<endl;
    }

    virtual void g(){
        cout<<"Parent::g()"<<endl;
    }

    virtual void h(){
        cout<<"Parent::h()"<<endl;
    }
    int parent_;
};

class Child : public Parent{
public:
    Child()
        :child_(100)
    {}

    virtual void f(){
        cout<<"Child::f()"<<endl;
    }

    virtual void g_child(){
        cout<<"Child::g_child()"<<endl;
    }

    virtual void h_child(){
        cout<<"Child::h_child()"<<endl;
    }
    int child_;
};

class GrandChild : public Child{
public:
    GrandChild()
        :grandchild_(1000)
    {}

    virtual void f(){
        cout<<"GrandChild::f()"<<endl;
    }

    virtual void g_child(){
        cout<<"GrandChild::g_child()"<<endl;
    }

    virtual void h_grandchild(){
        cout<<"GrandChild::h_grandchild()"<<endl;
    }
    int grandchild_;
};


int main(){
    typedef void(*Fun)(void);
    GrandChild gc;
    Fun pFun = NULL;
    long** pVtab = (long**)&gc;
    cout<<"[0] GrandChil::vptr_->"<<endl;
    for(int i = 0;(Fun)pVtab[0][i] != NULL;i++){
        pFun = (Fun)pVtab[0][i];
        cout<<" ["<<i<<"]";
        pFun();
    }

    cout<<"[1] Parent.parent_ = "<<(long)pVtab[1]<<endl;
    cout<<"[2] Child.child_ = "<<(long)pVtab[1]<<endl;
    cout<<"[3] GrandChild.grandchild_ = "<<(long)pVtab[2]<<endl;

    return 0;
}

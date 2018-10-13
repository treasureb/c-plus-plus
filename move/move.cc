#include<iostream>

using namespace std;

class HasPtrMem{
public:
    HasPtrMem():d(new int(0)){
        cout<<"Construct:" <<++n_cstr<<endl;
    }

    HasPtrMem(const HasPtrMem& h):d(new int(*h.d)){
        cout<<"Copy Construct:"<<++n_cptr<<endl;
    }

    ~HasPtrMem(){
        cout<<"Destruct:"<<++n_dstr<<endl;
    }
    
    int *d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;

HasPtrMem GetTemp(){
    return HasPtrMem();
}

/* g++编译器默认优化拷贝构造次数 */
/* -fno-elide-constructors来关闭编译器的优化 */

int main(){
    HasPtrMem a = GetTemp();
    return 0;
}

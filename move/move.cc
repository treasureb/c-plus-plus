#include<iostream>

using namespace std;

class HasPtrMem{
public:
    HasPtrMem():d(new int(3)){
        cout<<"Construct:" <<++n_cstr<<endl;
    }

    HasPtrMem(const HasPtrMem& h):d(new int(*h.d)){
        cout<<"Copy Construct:"<<++n_cptr<<endl;
    }

    //移动构造函数
    HasPtrMem(HasPtrMem&& h):d(h.d){
        h.d = nullptr;
        cout<<"Move construct:"<<++n_mvtr<<endl;
    }

    ~HasPtrMem(){
        cout<<"Destruct:"<<++n_dstr<<endl;
    }
    
    int *d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
    static int n_mvtr;
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_mvtr = 0;

HasPtrMem GetTemp(){
    HasPtrMem h;
    
    /* __func__为c++11中的宏,可以打印当前函数 */
    /* std::hex为以16进制输出 */

    cout<<"Resour from:"<<__func__<<":"<<hex<<h.d<<endl;
    return h;
}

/* g++编译器默认优化拷贝构造次数 */
/* -fno-elide-constructors来关闭编译器的优化 */

int main(){
    HasPtrMem a = GetTemp();
    cout<<"Resour from:"<<__func__<<":"<<hex<<a.d<<endl;
    return 0;
}

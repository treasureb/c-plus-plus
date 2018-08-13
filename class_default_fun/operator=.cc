#include<iostream>
#include<string>

using namespace std;

template<class T>
class NamedObject{
public:
    NamedObject(string& name,const T& value)
    :nameValue(name)
     ,objectValue(value)
    {}

private:
    string& nameValue;
    const T objectValue;
};


int main(){
    string newDog("Persephone");
    string oldDog("Satch");

    NamedObject<int> p(newDog,2);
    NamedObject<int> s(oldDog,36);

    /* 这里编译器不会生成默认的赋值运算符 */
    /* 1. 类的成员变量是引用,而引用一旦绑定实体就不能再绑定其他对象 */
    /* 2. 类的成员变量为const,而改变一个const对象是违法的 */
    /* 综上,编译器不会生成默认的operator= */
    p = s;
    return 0;
}

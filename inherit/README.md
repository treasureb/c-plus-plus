# 继承体系

### 单一的一般继承
*   虚函数表在最前面的位置
*   成员变量根据其继承和声明顺序依次放在后面
*   在单一的继承中,被overwrite的虚函数在表中得到更新


### 多重继承
*   每个父类都有自己的虚表
*   子类的成员函数被放到了第一个父类的表中
*   内存布局中,其父类布局依次按照声明的顺序
*   每个父类的虚表中函数都被overweite成子类的函数,这样做就是为了解决不同的父类类型的指针指向同一个子类的实例

### 菱形继承
*   造成数据的二义性
*   通过指定作用域可以消除二义性,但是有数据的冗余,采用虚拟继承

### 虚拟继承
*   对于超类中的成员函数和成员变量公用一份,继承的两个父类虚表中不再记录超类的虚函数,该虚函数只出现在超类的虚表中

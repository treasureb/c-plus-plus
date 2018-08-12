# 虚函数安全性
### 一、通过父类型的指针访问子类自己的虚函数

```
Base *b1 = new Derive();
b1->f1();   //编译出错,因为子类没有重写父类的虚函数

```

### 二、访问non-public的虚函数

非public的虚函数也会出现在虚表中,可以通过访问虚函数表来访问这边虚函数
```
typedef void(*Fun)(void);

Derive d;
Fun pFun = (Fun)*((long*)*(long*)(&d)+0);
pFun();
```

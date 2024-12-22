#include<iostream>
#include<string>
using namespace std;
//遇到菱形继承，即例如继承了两个性别这样的问题时
//采用虚继承来解决
//class joker :virtual class public role{};
class role
{
public:
    role(int hp,int attack)
    {
        this->attack=attack;
        this->hp=hp;
    }
    int hp;//血量
    int attack;//攻击
    void func()
    {
        cout<<"function under role\n";
    }
};
class joker :public role
{
public:
    joker():name("小丑"),sexy(1),role(100,100){}
    string name;
    bool sexy;
    void func()
    {
        cout<<"function under joker\n";
    }
};
ostream& operator<<(ostream& cout,const joker& t)
{
    cout<<t.name<<" "<<t.sexy<<" "<<t.hp<<" "<<t.attack<<"\n";
    return cout;
}
class animal
{
public:
    animal()
    {
        cout<<"animal构造函数调用\n";
    }
    virtual void speak() //加上virtual 地址晚绑定
    {
        cout<<"helloworld\n";
    }
    // virtual ~animal()
    // {
    //     cout<<"animal析构函数调用\n";
    // }
    virtual ~animal()=0;
};
animal::~animal(){} //纯虚析构 需要纯析构函数的函数实现
class cat : public animal
{
public:
    cat(string name)
    {
        this->name=new string(name); 
    }
    void speak()
    {
        cout<<*name<<" miaomiao\n"; //多态显然扩展性很强，
    }
    ~cat()
    {
        cout<<"调用cat了析构函数"<<"\n";
        if(name!=nullptr)
        {
            delete name;
            name=nullptr;
        }
    }
private:
    string* name;
};
//抽象类 ：无法实例化对象，子类必须重写父类纯虚函数
//计算机组装
class cpu
{
public:
    virtual void cal()=0;
};
class gpu
{
public:
    virtual void dis()=0;
};
class dram
{
public:
    virtual void sto()=0;
};
class intelcpu:public cpu
{
public:
    void cal()
    {
        cout<<"intel cpu cal\n";
    }
};
class intelgpu:public gpu
{
public:
    void dis()
    {
        cout<<"intel gpu dis\n";
    }
};
class inteldram:public dram
{
public:
    void sto()
    {
        cout<<"intel dram sto\n";
    }
};
class computer
{
public:
    computer(cpu* c,gpu* g,dram* d)
    {
        this->c=c;
        this->g=g;
        this->d=d;
    }
    void work()
    {
        c->cal();
        d->sto();
        g->dis();
    }
    ~computer()
    {
        if(c!=nullptr)
        {
            delete c;
            c=nullptr;
        }
        if(g!=nullptr)
        {
            delete g;
            g=nullptr;
        }
        if(d!=nullptr)
        {
            delete d;
            d=nullptr;
        }
    }
private:
    cpu* c;
    gpu* g;
    dram* d;
};
void test1()
{
    cpu* c=new intelcpu;
    gpu* g=new intelgpu;
    dram* d=new inteldram;
    computer t(c,g,d);
    t.work(); 
}
int main()
{
    // joker j;
    // cout<<j;
    // j.func();
    // j.role::func();
    // animal* t=new cat("Tom"); //地址早绑定
    // t->speak(); //得到的就是原始动物aoao 叫
    // delete t;
    // base* b=new son;
    // b->func();
    test1();
    return 0;
}
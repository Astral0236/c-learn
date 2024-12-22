#include<iostream>
#include<string>
using namespace std;
template<class Name,class Attack> //类模板 中成员函数创建时机
class role
{
public:
    role(Name name,Attack attack)
    {
        this->name=name;
        this->attack=attack;
    }
    void print()
    {
        cout<<name<<" "<<attack<<"\n";
    }
    Name name;
    Attack attack;
};
void test(role<string,int>& t) { t.print();} //需要指定传入的参数
template<class Name,class Attack>
void test1(role<Name,Attack>&t) //参数模板化
{
    cout<<typeid(Name).name()<<"\n"; //查看模板类型
    cout<<typeid(Attack).name()<<"\n";
}
//整个类模板化
template<class T>
void test3(T& t)
{
    cout<<typeid(T).name()<<"\n";
    t.print();
}
//类模板与继承
class joker:public role<string,int> {};//继承类模板要指定模板类型

//zai抽象一点 类模板函数类外实现

template<class T1,class T2,class T3>
class butcher :public role<T1,T2>
{
public:
    T3 arm;
    butcher(T1 name,T2 attack,T3 arm);
    void print();
    friend void add1()
    {
        cout<<"类内函数做友元，变成全局函数，但又可以访问私有变量\n";
    }
    friend void add2();
};
void add2(){cout<<"hello world\n";} //友元函数实现不需要加上作用域
//类模板函数类外实现
template<class T1,class T2,class T3>
butcher<T1,T2,T3>::butcher(T1 name,T2 attack,T3 arm):role<T1,T2>(name,attack)
{
    this->arm=arm;
}
template<class T1,class T2,class T3>
void butcher<T1,T2,T3>::print()
{
    cout<<this->name<<" "<<this->attack<<" "<<this->arm<<"\n";
}
void test4()
{
    butcher<string,int,int> t("jiexi",10,5);
    t.print();
    add2();
}
int main()
{
    // role<string,int> role1("lihua",10);
    // test(role1);
    // test1(role1);
    // test3(role1);
    test4();
    return 0;
}
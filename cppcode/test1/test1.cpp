#include<iostream>
using namespace std;
class teacher
{
    friend class student;
    string name;
    int age;
public:
    teacher()
    {
        this->name="lihua";
        this->age=18;
    }
}; 
class student
{
    friend int main();
    int age;
    mutable int high;
    student(int age)
    {
        this->age=age;
    }
    student& add_age(student& t)
    {
        this->age+=t.age;
        return *this;
    }
    void visit()
    {
        teacher* t=new teacher;
        cout<<t->name<<" "<<t->age<<"\n";
        delete t;
    }
};
class matrix
{
public:
    int a;
    int b;
    matrix& operator +(matrix& t1)
    {
        this->a+=t1.a;
        this->b+=t1.b;
        return *this;
    }
    bool operator ==(matrix& t1)
    {
        return (a+b)==(t1.a+t1.b);
    }
    matrix()
    {
        a=10;
        b=5;
    }
};
ostream& operator <<(ostream& cout,matrix& p)
{
    cout<<p.a<<" "<<p.b<<"\n";
    return cout;
}
class integer
{
    friend ostream& operator <<(ostream& cout,const integer& p);
private:
    int t;
public:
    integer():t(0){}
    integer& operator++()
    {
        ++t;
        return *this;
    }
    integer operator++(int)
    {
        integer x=*this;
        ++t;
        return x;       
    }
};
ostream& operator <<(ostream& cout,const integer& p)
{
    cout<<p.t;
    return cout;
}
class person
{
public:
    int* age;
    person(int age):age(new int(age)) {}
    person(const person& p): age(new int(*p.age)){}
    person& operator=(const person& t)
    {
        cout<<"调用重载函数"<<"\n";
        if(this==&t) return *this;
        if(age!=nullptr)
        {
            delete age;
            age=nullptr;
        }
        age=new int(*t.age);
        return *this;
    }
    ~person()
    {
        cout<<"调用析构函数\n";
        if(age!=nullptr)
        {
            delete age;
            age=nullptr;
        }
    }

};
int main()
{
    // student p1(10),p2(2);
    // p1.add_age(p2).add_age(p2).add_age(p2);
    // cout<<p1.age<<"\n";
    // p1.visit();
    matrix a1,a2;
    cout<<(a1==a2)<<"\n";
    // matrix a3=a1+a2+a2;
    // cout<<a3<<" ";
    // integer t;   
    // cout<<t++;
    // cout<<t;
    // person p1(18);
    // person p2(10);
    // person p3=p1;//这是初始化，并不是赋值
    // cout<<*p2.age<<"\n";
    // p2=p1;
    // cout<<*p2.age<<"\n";
    //cout<<*p3.age<<"\n";
    return 0;
}

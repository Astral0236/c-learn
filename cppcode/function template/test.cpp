#include<iostream>
#include <string.h>
#include<string>
using namespace std;
//template<typename T>
// template<class type>
// void Swap(type a,type b)
// {
//     type temp=a;
//     a=b;
//     b=temp;
// }

// void test1()
// {
//     double a=1.5,b=13.4;
//     Swap(a,b); //自动推导参数类型
//     Swap<double>(a,b); //指定T的类型
//     cout<<a<<" "<<b<<"\n";
// }
template<class type>
void msort(type a[],int len)
{
    for(int i=0;i<len;i++)
    {
        int idx=i;
        for(int j=i+1;j<len;j++)   if(a[j]<a[idx])  idx=j;
        swap(a[i],a[idx]);
    }
}
void test()
{
    char str[]="hoiahcoiao";
    int a[10]={9,8,7,6,5,4,3,2,1,0};
    msort(a,10);
    msort(str,strlen(str));
    for(int i=0;i<strlen(str);i++)cout<<str[i]<<" ";
    cout<<"\n";
    for(int i=0;i<10;i++) cout<<a[i]<<" ";
}
class role
{
public:
    string name;
    int gender;
    role(string name,int gender)
    {
        this->name=name;
        this->gender=gender;
    }
    bool operator ==(role& Role)
    {
        if(name==Role.name&&gender==Role.gender) return true;
        return false;
    }
};
template<class type>
bool is_equal(type a,type b)
{
    if(a==b) return true;
    return false;
}
int main()
{
    role a1("lihua",0);
    role a2("xiaoming",1);
    cout<<(a1==a2)<<"\n";
    cout<<is_equal<role>(a1,a2);
    return 0;
}
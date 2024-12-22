#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
//内建函数对象
// 算数仿函数 negate plus
void test1()
{
    negate<int> t1;
    cout<<t1(50)<<"\n";
    plus<int> t2;
    cout<<t2(50,20)<<"\n"; 
}
//关系仿函数
class compare //谓词
{
public:
    bool operator()(int a,int b)
    {
        return a>b;
    }
};
void test2()
{
    vector<int> q;
    for(int i=0;i<10;i++) q.push_back(i);
    for(vector<int>::const_iterator it=q.begin();it<q.end();it++) cout<<*it<<" ";
    sort(q.begin(),q.end(),greater<int>()); //内建函数对象
    cout<<endl;
    for(vector<int>::const_iterator it=q.begin();it<q.end();it++) cout<<*it<<" ";
}
//逻辑仿函数 logical_and or not
void test3()
{
    vector<bool> q;
    q.push_back(0);
    q.push_back(1);
    q.push_back(0);
    q.push_back(0);
    q.push_back(1);
    q.push_back(0);
    q.push_back(1);
    q.push_back(0);
    for(vector<bool>::const_iterator it=q.begin();it<q.end();it++) cout<<*it<<" ";
    cout<<endl;
    vector<bool> q2(q.size());
    transform(q.begin(),q.end(),q2.begin(),logical_not<bool>());
    for(vector<bool>::const_iterator it=q2.begin();it<q2.end();it++) cout<<*it<<" ";

}
int main()
{
    cout<<"hello world\n";
    test3();
    return 0;
}
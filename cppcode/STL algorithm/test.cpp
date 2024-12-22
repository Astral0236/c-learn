#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
using namespace std;
//for_each transform 将一个容器搬运到另外一个容器中
class print
{
public:
    void operator()(int val) 
    {
        cout<<val<<" ";
    }
};
void test1()
{
    vector<int> q;
    for(int i=0;i<10;i++) q.push_back(i);
    for_each(q.begin(),q.end(),print());
    //for(vector<int>::const_iterator it=q.begin();it<q.end();it++) cout<<*it<<" ";
}
//查找算法 find 查找 自定义数据类型可能需要重载运算符
//find_if 按条件查找 
//adjacent_find 查找相邻重复元素
//binary_search 二分查找
//count 统计元素个数
//count_if 按条件统计元素个数
void test2()
{
    vector<int> q;
    for(int i=0;i<10;i++) q.push_back(i);
    auto t=find(q.begin(),q.end(),5); //返回迭代器 
    cout<<*t<<" ";
}
class select
{
public:
    bool operator()(int val)
    {
        if(val>5) return true;
        return false;
    }
};
void test3() //貌似只能查出来一个数，并不能返回一个集合
{
    vector<int> q;
    for(int i=0;i<10;i++) q.push_back(i);
    auto results=find_if(q.begin(),q.end(),select());
    cout<<*results;
}
//常用的排序算法 sort random_shuffle 随即洗牌已被弃用 merge 合并 reverse 反转
void test4()
{
    vector<int> q;
    for(int i=0;i<10;i++) q.push_back(i);
    reverse(q.begin(),q.end());
    for_each(q.begin(),q.end(),print());
}
//拷贝算法 copy replace replace_if swap 
void test5()
{
     vector<int> q,q1;
    for(int i=0;i<10;i++) q.push_back(i);//后者起码比前者大
    q1.resize(q.size());
    copy(q.begin(),q.end(),q1.begin()); //copy
    for_each(q1.begin(),q1.end(),print());
    // replace(q1.begin(),q1.end(),5,100); //replace
    // cout<<endl;
    // for_each(q1.begin(),q1.end(),print());
    replace_if(q1.begin(),q1.end(),select(),3000);
    cout<<endl;
    for_each(q1.begin(),q1.end(),print());


}
//算数生成算法 accumulate 累加 fill 填充
void test6()
{
    vector<int> q;
    for(int i=0;i<10;i++) q.push_back(i);
    cout<<accumulate(q.begin(),q.end(),0); //0是起始累加值
}
//常用集合算法
//set_intersection 交
//set_union 并
//set_difference 差
void test7()
{
    vector<int> q;
    for(int i=0;i<10;i++) q.push_back(i);
    vector<int> v;
    for(int i=5;i<15;i++) v.push_back(i);
    vector<int> result(20);
    set_intersection(q.begin(),q.end(),v.begin(),v.end(),result.begin());
    for(auto x:result) cout<<x<<" ";
    cout<<endl;
    auto t=set_union(q.begin(),q.end(),v.begin(),v.end(),result.begin()); //会返回迭代器 返回最后一迭代器
    for_each(result.begin(),t,print());
}
int main()
{
    test7();
    return 0;
}
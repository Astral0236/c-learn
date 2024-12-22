#include<iostream>
#include<vector>
#include"myvector.hpp"
using namespace std;
int main()
{
    myvector<string> a(5);
    for(int i=0;i<5;i++)
    {
        string t="abcd";
        a.append(t);
    }
    for(int i=1;i<5;i++) cout<<a[i]<<"\n";
    return 0;
}
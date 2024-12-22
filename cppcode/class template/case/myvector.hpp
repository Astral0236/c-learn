#include<iostream>
using namespace std;
template<class type>
class myvector
{
private:
    type* array;
    int len; //长度
    int cap; //容量
public:
    myvector(int cap);
    myvector(const myvector& t);
    ~myvector();
    void print();
    void append(const type& value);
    void pop_back();
    myvector& operator=(const myvector& t);
    type& operator[](const int& idx);
};
template<class type>
myvector<type>& myvector<type>::operator=(const myvector<type>& t)
{
    if(this->array!=nullptr) 
    {
        delete[] this->array;
        array=nullptr;
    }
    this->cap=t.cap;
    this->len=t.len;
    this->array=new type[cap];
    for(int i=0;i<len;i++)
    {
        this->array[i]=t.array[i];
    }
    return *this;

}
template<class type>
myvector<type>::myvector(int cap)
{
    this->cap=cap;
    this->len=0;
    this->array=new type[cap];
}
template<class type>
myvector<type>::~myvector()
{
    if(this->array!=nullptr) 
    {
        delete[] this->array;
        array=nullptr;
    }
}
template<class type>
void myvector<type>::print()
{
    cout<<this->cap<<" "<<this->len<<"\n";
}
template<class type>
myvector<type>::myvector(const myvector& t)
{
    this->cap=t.cap;
    this->len=t.len;
    this->array=new type[cap];
    for(int i=0;i<len;i++)
    {
        this->array[i]=t.array[i];
    }
}
template<class type>
void myvector<type>::append(const type& value)
{
    if(len<this->cap) array[len++]=value;
    else return;
}
template<class type>
void myvector<type>::pop_back()
{
    if(!len) return;
    len--;
}
template<class type>
type& myvector<type>::operator[](const int& idx)
{
    return array[idx];
}

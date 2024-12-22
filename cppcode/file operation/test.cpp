#include<iostream>
#include<fstream>
using namespace std;
//写文件
void test1()
{
    cout<<"hello world\n";
    ofstream ofs;
    ofs.open("test01.text",ios::out);
    ofs<<"lihua\nman\n18";
    ofs.close();
}
//读文件
void test2()
{
    ifstream ifs;
    ifs.open("test01.text",ios::in);
    //ifs.is_open() 判断是否打开成功
    //第一种
    //char buf[128]={0};
    // while(ifs>>buf) 
    // {
    //     cout<<buf<<"\n";
    // }
    // while(ifs.getline(buf,sizeof(buf)))
    // {
    //     cout<<buf<<"\n";
    // }
    //第三种
    // 
    string t;
    while(getline(ifs,t))
    {
        cout<<t<<"\n";
    }
    //第四种
    // char c;
    // while((c=ifs.get())!=EOF)
    // {
    //     cout<<c;
    // }
    ifs.close();

}
class role
{
public:
    char name[32];
    int age;
    void print()
    {
        cout<<name<<" "<<age<<"\n";
    }
};
//二进制写文件
void test3()
{
    ofstream ofs;
    ofs.open("test01.text",ios::out |ios::binary);
    role joker={"lihua",20};
    ofs.write((const char *)&joker,sizeof(role));
    ofs.close();
}
//读文件
void test4()
{
    ifstream ifs;
    ifs.open("test01.text",ios::in |ios::binary);
    role joker;
    ifs.read((char*)&joker,sizeof(role));
    joker.print();
    ifs.close();
}
int main()
{
    test4();
    return 0;
}
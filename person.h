#include<iostream>
#include<cstring>
using namespace std;
class person
{
public:
    person();//无参构造函数
    void setname(string q1);//设置姓名
    void setsex(string q2);//设置性别
    void setpbnumber(string q3);//设置电话号码
    void setaddress(string q4);//设置地址
    void setpostal_code(string q5);//设置邮政编码
    void setemail(string q6);//设置邮箱
    void setQQnumber(string q7);//设置QQ号
    void settype(string q8);//设置类别
    string getname();//获取姓名
    string getsex();//获取性别
    string getpbnumber();//获取电话号码
    string getaddress();//获取地址
    string getpostal_code();//获取邮政编码
    string getemail();//获取邮箱
    string getQQnumber();//获取QQ号码
    string gettype();//获取类别
    void searchname(string rname);//查找姓名
    void searchpbnumber(string rnumber);//查找电话号码
    void searchaddress(string raddress);//查找地址
    void searchtype(string rtype);//查找类别
    void sortname();//根据姓名排序
    void sortsex();//根据性别排序
    void sortpostal_code();//根据邮政编码排序
    void sorttype();//根据类别排序
    void loadperson(string q1,string q2,string q3,string q4,string q5,string q6,string q7,string q8);//重新设置人员信息
    person* searchxname(string xname);//根据姓名查找信息，后修改
    person* searchxpbnumber(string xpbnumber);//根据电话号码查找信息，后修改
    person* searchscname(string sname);//根据姓名查找信息，后删除
    person* searchscname1(string sname);//辅助根据姓名查找信息，后删除
    person* searchscpbnumber(string spbnumber);//根据电话号码查找信息，后删除
    person* searchscpbnumber1(string spbnumber);//辅助根据电话号码查找信息，后删除
    void pinout();//输出信息
    person *next;//定义next指针，用于建立链表
    ~person();//析构函数
private:
    //定义姓名、性别、电话号码、地址、邮政编码、邮箱、QQ号码、类别变量
    string name,sex,pbnumber,address,postal_code,email,QQnumber,type;
};


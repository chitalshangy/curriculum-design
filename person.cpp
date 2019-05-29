#include<cstring>
#include<iostream>
#include"person.h"
using namespace std;

//构造函数
person::person(){}

//设置信息
void person::setname(string q1)
{
    name=q1;//赋值
}

void person::setsex(string q2)
{
    sex=q2;
}

void person::setpbnumber(string q3)
{
    pbnumber=q3;
}

void person::setaddress(string q4)
{
    address=q4;
}

void person::setpostal_code(string q5)
{
    postal_code=q5;
}

void person::setemail(string q6)
{
    email=q6;
}

void person::setQQnumber(string q7)
{
    QQnumber=q7;
}

void person::settype(string q8)
{
    type=q8;
}

//获取信息
string person::getname()
{
    return name;//返回值
}

string person::getsex()
{
    return sex;
}

string person::getpbnumber()
{
    return pbnumber;
}

string person::getaddress()
{
    return address;
}

string person::getpostal_code()
{
    return postal_code;
}

string person::getemail()
{
    return email;
}

string person::getQQnumber()
{
    return QQnumber;
}

string person::gettype()
{
    return type;
}

//查找信息
void person::searchname(string rname)
{
    int pd=0;//判断是否存在此信息
    person *p=this;
    while(p)//链表遍历
    {
        if(p->name==rname)
        {
            p->pinout();
            pd=1;
        }
        p=p->next;
    }
    if(!pd)
    {
        cout<<"----------------------------------------"<<endl;
        cout<<"============该联系人不存在!============="<<endl;
    }
}

void person::searchpbnumber(string rnumber)
{
    int pd=0;
    person *p=this;
    while(p)
    {
        if(p->pbnumber==rnumber)
        {
            p->pinout();
            pd=1;
        }
        p=p->next;
    }
    if(!pd)
    {
        cout<<"----------------------------------------"<<endl;
        cout<<"===========该电话号码不存在!============"<<endl;
    }
}

void person::searchaddress(string raddress)
{
    int pd=0;
    person *p=this;
    while(p)
    {
        if(p->address==raddress)
        {
            p->pinout();
            pd=1;
        }
        p=p->next;
    }
    if(!pd)
    {
        cout<<"----------------------------------------"<<endl;
        cout<<"=============该地址不存在!============="<<endl;
    }
}

void person::searchtype(string rtype)
{
    int pd=0;
    person *p=this;
    while(p)
    {
        if(p->type==rtype)
        {
            p->pinout();
            pd=1;
        }
        p=p->next;
    }
    if(!pd)
    {
        cout<<"----------------------------------------"<<endl;
        cout<<"=============该类别不存在!============="<<endl;
    }
}

//输出所有信息
void person::pinout()
{
    cout<<this->getname()<<" "<<this->getsex()<<" "<<this->getpbnumber()<<" "<<this->getaddress()<<" "<<this->getpostal_code()<<" "<<this->getemail()<<" "<<this->getQQnumber()<<" "<<this->gettype()<<endl;
}

//选择排序函数
void person::sortname()
{
    person*sort1=this;//新建指向当前对象的指针
    while(sort1)//遍历链表排序
    {
        person *min1=sort1;
        person *minx=sort1->next;
        while(minx)//遍历链表，找出最小项
        {
            if(minx->name<min1->name)min1=minx;
            minx=minx->next;
        }
        if(min1!=sort1)//如果当前不是最大项，交换信息
        {
            string t;
            t=min1->name;
            min1->name=sort1->name;
            sort1->name=t;
            t=min1->sex;
            min1->sex=sort1->sex;
            sort1->sex=t;
            t=min1->pbnumber;
            min1->pbnumber=sort1->pbnumber;
            sort1->pbnumber=t;
            t=min1->address;
            min1->address=sort1->address;
            sort1->address=t;
            t=min1->postal_code;
            min1->postal_code=sort1->postal_code;
            sort1->postal_code=t;
            t=min1->email;
            min1->email=sort1->email;
            sort1->email=t;
            t=min1->QQnumber;
            min1->QQnumber=sort1->QQnumber;
            sort1->QQnumber=t;
            t=min1->type;
            min1->type=sort1->type;
            sort1->type=t;
        }
        sort1=sort1->next;//指向下一个节点
    }
}

void person::sortsex()
{
    person*sort1=this;
    while(sort1)
    {
        person *min1=sort1;
        person *minx=sort1->next;
        while(minx)
        {
            if(minx->sex<min1->sex)min1=minx;
            minx=minx->next;
        }
        if(min1!=sort1)
        {
            string t;
            t=min1->name;
            min1->name=sort1->name;
            sort1->name=t;
            t=min1->sex;
            min1->sex=sort1->sex;
            sort1->sex=t;
            t=min1->pbnumber;
            min1->pbnumber=sort1->pbnumber;
            sort1->pbnumber=t;
            t=min1->address;
            min1->address=sort1->address;
            sort1->address=t;
            t=min1->postal_code;
            min1->postal_code=sort1->postal_code;
            sort1->postal_code=t;
            t=min1->email;
            min1->email=sort1->email;
            sort1->email=t;
            t=min1->QQnumber;
            min1->QQnumber=sort1->QQnumber;
            sort1->QQnumber=t;
            t=min1->type;
            min1->type=sort1->type;
            sort1->type=t;
        }
        sort1=sort1->next;
    }
}

void person::sortpostal_code()
{
    person*sort1=this;
    while(sort1)
    {
        person *min1=sort1;
        person *minx=sort1->next;
        while(minx)
        {
            if(minx->postal_code<min1->postal_code)min1=minx;
            minx=minx->next;
        }
        if(min1!=sort1)
        {
            string t;
            t=min1->name;
            min1->name=sort1->name;
            sort1->name=t;
            t=min1->sex;
            min1->sex=sort1->sex;
            sort1->sex=t;
            t=min1->pbnumber;
            min1->pbnumber=sort1->pbnumber;
            sort1->pbnumber=t;
            t=min1->address;
            min1->address=sort1->address;
            sort1->address=t;
            t=min1->postal_code;
            min1->postal_code=sort1->postal_code;
            sort1->postal_code=t;
            t=min1->email;
            min1->email=sort1->email;
            sort1->email=t;
            t=min1->QQnumber;
            min1->QQnumber=sort1->QQnumber;
            sort1->QQnumber=t;
            t=min1->type;
            min1->type=sort1->type;
            sort1->type=t;
        }
        sort1=sort1->next;
    }
}

void person::sorttype()
{
    person*sort1=this;
    while(sort1)
    {
        person *min1=sort1;
        person *minx=sort1->next;
        while(minx)
        {
            if(minx->type<min1->type)min1=minx;
            minx=minx->next;
        }
        if(min1!=sort1)
        {
            string t;
            t=min1->name;
            min1->name=sort1->name;
            sort1->name=t;
            t=min1->sex;
            min1->sex=sort1->sex;
            sort1->sex=t;
            t=min1->pbnumber;
            min1->pbnumber=sort1->pbnumber;
            sort1->pbnumber=t;
            t=min1->address;
            min1->address=sort1->address;
            sort1->address=t;
            t=min1->postal_code;
            min1->postal_code=sort1->postal_code;
            sort1->postal_code=t;
            t=min1->email;
            min1->email=sort1->email;
            sort1->email=t;
            t=min1->QQnumber;
            min1->QQnumber=sort1->QQnumber;
            sort1->QQnumber=t;
            t=min1->type;
            min1->type=sort1->type;
            sort1->type=t;
        }
        sort1=sort1->next;
    }
}

//载入信息函数
void person::loadperson(string q1,string q2,string q3,string q4,string q5,string q6,string q7,string q8)
{    this->setname(q1);
    this->setsex(q2);
    this->setpbnumber(q3);
    this->setaddress(q4);
    this->setpostal_code(q5);
    this->setemail(q6);
    this->setQQnumber(q7);
    this->settype(q8);
}

//寻找信息函数，用于修改信息
person* person::searchxname(string xname)
{
    person*p1=this;//指向当前对象
    while(p1)
    {
        if(p1->name==xname)break;//找到了就退出循环
        p1=p1->next;
    }
    return p1;//找到了返回节点地址，没找到返回NULL
}

person* person::searchxpbnumber(string xpbnumber)
{
    person*p1=this;
    while(p1)
    {
        if(p1->pbnumber==xpbnumber)break;
        p1=p1->next;
    }
    return p1;
}

//寻找信息函数，用于删除信息
person* person::searchscname(string sname)
{
    person*p1=this;//记录节点地址
    person*p2=NULL;//记录节点的前一个节点地址
    while(p1)
    {
        if(p1->name==sname)
        {
            break;
        }
        else
        {
            p2=p1;
            p1=p1->next;
        }
    }
    return p2;//返回节点的前一个节点地址
}

//辅助寻找信息函数，用于删除信息
person* person::searchscname1(string sname)
{
    person*p1=this;
    person*p2=NULL;
    while(p1)
    {
        if(p1->name==sname)
        {
            break;
        }
        else
        {
            p2=p1;
            p1=p1->next;
        }
    }
    return p1;//返回节点地址
}

person* person::searchscpbnumber(string spbnumber)
{
    person*p1=this;
    person*p2=NULL;
    while(p1)
    {
        if(p1->pbnumber==spbnumber)
        {
            break;
        }
        else
        {
            p2=p1;
            p1=p1->next;
        }
    }
    return p2;
}

person* person::searchscpbnumber1(string spbnumber)
{
    person*p1=this;
    person*p2=NULL;
    while(p1)
    {
        if(p1->pbnumber==spbnumber)
        {
            break;
        }
        else
        {
            p2=p1;
            p1=p1->next;
        }
    }
    return p1;
}

//析构函数
person::~person(){}


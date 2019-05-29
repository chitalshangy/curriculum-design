#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include"person.h"
using namespace std;
int main()
{
    string n="0";
    while(n!="-1")//此循环控制是否退出程序
    {
        n="0";
        cout<<"----------------------------------------"<<endl;
        cout<<"       ^_^ 欢迎进入通信录系统 ^_^       "<<endl;
        cout<<"\\*                                     "<<endl;
        cout<<"\\*         输入人员信息,请按1;         "<<endl;
        cout<<"\\*         查询人员信息,请按2;         "<<endl;
        cout<<"\\*         输出人员信息,请按3;         "<<endl;
        cout<<"\\*         修改人员信息,请按4;         "<<endl;
        cout<<"\\*         删除人员信息,请按5;         "<<endl;
        cout<<"\\*                                     "<<endl;
        cout<<"\\***********************退出系统请按-1;"<<endl;
        cin>>n;
        system("cls");
        if(n=="1")
        {
            //打开文本文件
            ofstream outfile;
            outfile.open("personinf.txt",ios::app);//防止原文本文件内的数据被删除，所以用ios::app方式打开
            if(!outfile)
            {
                cerr<<"open error!"<<endl;
                exit(1);
            }
            string shu="0";
            cout<<"------------------------------------------------------------------------"<<endl;
            cout<<"请以姓名、性别、电话、地址、邮政编码、邮箱、QQ号、类别的格式输入人员信息:"<<endl<<endl;
            string name1,sex1,address1,email1,type1,phonenumber1,postal_code1,QQnumber1;
            while(shu!="-1")//此循环控制是否退出输入界面
            {
                //将数据输入文本文件
                cin>>name1>>sex1>>phonenumber1>>address1>>postal_code1>>email1>>QQnumber1>>type1;
                outfile<<name1<<" "<<sex1<<" "<<phonenumber1<<" "<<address1<<" "<<postal_code1<<" "<<email1<<" "<<QQnumber1<<" "<<type1<<endl;
                cout<<endl;
                cout<<"=======================是否要继续输入信息：是(输入0);否(输入-1,返回主界面)"<<endl;
                cin>>shu;
                system("cls");//清空当前屏幕
                if(shu!="-1")
                {
                    cout<<"------------------------------------------------------------------------"<<endl;
                    cout<<"请以姓名、性别、电话、地址、邮政编码、邮箱、QQ号、类别的格式输入人员信息:"<<endl<<endl;
                }
            }
            outfile.close();//关闭文本文件
            system("cls");
        }
        else if(n=="2")
        {
            string se="0";
            while(se!="-1")//此循环控制是否退出查询界面
            {
                cout<<"----------------------------------------"<<endl;
                cout<<"请选择查询方法:                         "<<endl;
                cout<<"      根据姓名精确查询,请按1;           "<<endl;
                cout<<"      根据电话精确查询,请按2;           "<<endl;
                cout<<"      根据地址模糊查询,请按3;           "<<endl;
                cout<<"      根据人员类别查询,请按4;           "<<endl;
                cout<<"---------------------返回上一界面请按-1;"<<endl;
                cin>>se;
                system("cls");
                ifstream infile;
                infile.open("personinf.txt",ios::in);//打开文件
                if(!infile)
                {
                    cerr<<"open error!"<<endl;
                    exit(1);
                }
                //建立链表
                person *head=NULL;
                string q1,q2,q3,q4,q5,q6,q7,q8;
                while(infile>>q1>>q2>>q3>>q4>>q5>>q6>>q7>>q8)//此循环控制文本内数据是否全被存储在链表中
                {
                    person*newperson=new person;
                    newperson->loadperson(q1,q2,q3,q4,q5,q6,q7,q8);
                    newperson->next=head;
                    head=newperson;
                }
                infile.close();//关闭文件
                if(se=="1")
                {
                    string see="0";
                    while(see!="-1")//此循环控制是否继续根据姓名查找
                    {
                         cout<<"----------------------------------------"<<endl;
                         cout<<"请输入所要查找的姓名:"<<endl;
                         string rname;
                         cin>>rname;
                         head->searchname(rname);//调用查找姓名函数
                         cout<<"------------------------------------------------"<<endl;
                         cout<<"==========请问是否继续根据姓名查找？是(0):否(-1)"<<endl;
                         cin>>see;
                         system("cls");
                    }
                }
                else if(se=="2")
                {
                    string see="0";
                    while(see!="-1")//此循环控制是否继续根据电话查找
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"请输入所要查找的电话:"<<endl;
                        string rpho;
                        cin>>rpho;
                        head->searchpbnumber(rpho);//调用查找电话函数
                        cout<<"------------------------------------------------"<<endl;
                        cout<<"==========请问是否继续根据电话查找？是(0):否(-1)"<<endl;
                        cin>>see;
                        system("cls");
                    }
                }
                else if(se=="3")
                {
                    string see="0";
                    while(see!="-1")//此循环控制是否继续根据地址查找
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"请输入所要查找的地址:"<<endl;
                        string raddr;
                        cin>>raddr;
                        head->searchaddress(raddr);//调用查找地址函数
                        cout<<"------------------------------------------------"<<endl;
                        cout<<"==========请问是否继续根据地址查找？是(0):否(-1)"<<endl;
                        cin>>see;
                        system("cls");
                    }

                }
                else if(se=="4")//此循环控制是否继续根据类别查找
                {
                    string see="0";
                    while(see!="-1")
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"请输入所要查找的类别:"<<endl;
                        string rtype;
                        cin>>rtype;
                        head->searchtype(rtype);//调用类别查找函数
                        cout<<"------------------------------------------------"<<endl;
                        cout<<"==========请问是否继续根据类别查找？是(0):否(-1)"<<endl;
                        cin>>see;
                        system("cls");
                    }
                }
                //链表删除操作
                person*p=head;
                while(head)
                {
                    head=head->next;
                    delete p;
                    p=head;
                }
                delete head;
            }
        }
        else if(n=="3")
        {
            string so="0";
            while(so!="-1")//此循环控制是否退出输出界面
            {
                cout<<"----------------------------------------"<<endl;
                cout<<"请选择排序输出依据:                     "<<endl;
                cout<<"      根据姓名排序输出,请按1;           "<<endl;
                cout<<"      根据性别排序输出,请按2;           "<<endl;
                cout<<"      根据邮政编码输出,请按3;           "<<endl;
                cout<<"      根据类别排序输出,请按4;           "<<endl;
                cout<<"---------------------返回上一界面请按-1;"<<endl;
                cin>>so;
                system("cls");
                ifstream infile;
                infile.open("personinf.txt",ios::in);//打开文件
                if(!infile)
                {
                    cerr<<"open error!"<<endl;
                    exit(1);
                }
                //建立链表
                person *head=NULL;
                string q1,q2,q3,q4,q5,q6,q7,q8;
                while(infile>>q1>>q2>>q3>>q4>>q5>>q6>>q7>>q8)
                {
                    person*newperson=new person;
                    newperson->loadperson(q1,q2,q3,q4,q5,q6,q7,q8);
                    newperson->next=head;
                    head=newperson;
                }
                infile.close();//关闭文件
                if(so=="1")
                {
                    string soo="0";
                    while(soo!="-1")//此循环控制是否继续根据姓名排序输出
                    {
                        cout<<"----------------------------------------"<<endl;
                        head->sortname();//调用姓名排序函数
                        person*p1=head;//新建p1指针，指向表头
                        while(p1)
                        {
                            p1->pinout();//调用输出函数，输出p1所指向空间内的所有数据
                            p1=p1->next;//p1指向下一个空间
                        }
                        cout<<"=============================================="<<endl;
                        cout<<"--------是否继续根据姓名排序输出？是(0):否(-1)"<<endl;
                        cin>>soo;
                        system("cls");
                    }
                }
                else if(so=="2")
                {
                    string soo="0";
                    while(soo!="-1")//此循环控制是否继续根据性别排序输出
                    {
                        cout<<"----------------------------------------"<<endl;
                        head->sortsex();//调用性别排序函数
                        person*p1=head;//新建p1指针，指向表头
                        while(p1)
                        {
                            p1->pinout();//调用输出函数，输出p1所指向空间内的所有数据
                            p1=p1->next;//p1指向下一个空间
                        }
                        cout<<"=============================================="<<endl;
                        cout<<"--------是否继续根据性别排序输出？是(0):否(-1)"<<endl;
                        cin>>soo;
                        system("cls");
                    }
                }
                else if(so=="3")
                {
                    string soo="0";
                    while(soo!="-1")//此循环控制是否继续根据邮政编码排序输出
                    {
                        cout<<"----------------------------------------"<<endl;
                        head->sortpostal_code();//调用邮政编码排序函数
                        person*p1=head;//新建p1指针，指向表头
                        while(p1)
                        {
                            p1->pinout();//调用输出函数，输出p1所指向空间内的所有数据
                            p1=p1->next;//p1指向下一个空间
                        }
                        cout<<"=============================================="<<endl;
                        cout<<"----是否继续根据邮政编码排序输出？是(0):否(-1)"<<endl;
                        cin>>soo;
                        system("cls");
                    }
                }
                else if(so=="4")
                {
                    string soo="0";
                    while(soo!="-1")//此循环控制是否继续根据类别排序输出
                    {
                        cout<<"----------------------------------------"<<endl;
                        head->sorttype();//调用类别排序函数
                        person*p1=head;//新建p1指针，指向表头
                        while(p1)
                        {
                            p1->pinout();//调用输出函数，输出p1所指向空间内的所有数据
                            p1=p1->next;//p1指向下一个空间
                        }
                        cout<<"=============================================="<<endl;
                        cout<<"--------是否继续根据类别排序输出？是(0):否(-1)"<<endl;
                        cin>>soo;
                        system("cls");
                    }
                }
                //链表删除操作
                person*p=head;
                while(head)
                {
                    head=head->next;
                    delete p;
                    p=head;
                }
                delete head;
            }
        }
        else if(n=="4")
        {
            string xg="0";
            while(xg!="-1")//此循环控制是否退出修改界面
            {
                cout<<"----------------------------------------"<<endl;
                cout<<"请选择修改根据:                         "<<endl;
                cout<<"      根据姓名修改,请按1;               "<<endl;
                cout<<"      根据电话修改,请按2;               "<<endl;
                cout<<"---------------------返回上一界面请按-1;"<<endl;
                cin>>xg;
                system("cls");
                ifstream infile;
                infile.open("personinf.txt",ios::in);
                if(!infile)
                {
                    cerr<<"open error!"<<endl;
                    exit(1);
                }
                person*head=NULL;
                string q1,q2,q3,q4,q5,q6,q7,q8;
                while(infile>>q1>>q2>>q3>>q4>>q5>>q6>>q7>>q8)
                {
                    person*newperson=new person;
                    newperson->loadperson(q1,q2,q3,q4,q5,q6,q7,q8);
                    newperson->next=head;
                    head=newperson;
                }
                infile.close();
                if(xg=="1")
                {
                    string xgg="0";
                    while(xgg!="-1")//此循环控制是否继续根据姓名修改
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"==========请输入需要修改信息的人员姓名："<<endl;
                        string xgname;
                        cin>>xgname;
                        person*ans=head->searchxname(xgname);//调用姓名查找函数，返回节点地址
                        if(ans==NULL)
                        {
                            cout<<"============不存在此人信息！============="<<endl;
                        }
                        else
                        {
                            cout<<"-------------------------------------------------------------------------"<<endl;
                            cout<<"请以姓名、性别、电话、地址、邮政编码、邮箱、QQ号、类别的格式输入人员信息:"<<endl;
                            string w1,w2,w3,w4,w5,w6,w7,w8;
                            cin>>w1>>w2>>w3>>w4>>w5>>w6>>w7>>w8;
                            ans->loadperson(w1,w2,w3,w4,w5,w6,w7,w8);//调用数据重置函数，重置数据
                        }
                        cout<<"====================================是否继续根据姓名修改信息?是(0):否(-1)"<<endl;
                        cin>>xgg;
                        system("cls");
                    }
                    ofstream outfile;
                    outfile.open("personinf.txt",ios::out);
                    if(!outfile)
                    {
                        cerr<<"open error!"<<endl;
                        exit(1);
                    }
                    //将数据写入文本
                    person*out=head;
                    while(out)
                    {
                        outfile<<out->getname()<<" "<<out->getsex()<<" "<<out->getpbnumber()<<" "<<out->getaddress()<<" "<<out->getpostal_code()<<" "<<out->getemail()<<" "<<out->getQQnumber()<<" "<<out->gettype()<<endl;
                        out=out->next;
                    }
                    outfile.close();
                }
                else if(xg=="2")
                {
                    string xgg="0";
                    while(xgg!="-1")//此循环控制是否继续根据电话修改
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"==========请输入需要修改信息的人员电话："<<endl;
                        string xgpbnumber;
                        cin>>xgpbnumber;
                        person*ans=head->searchxpbnumber(xgpbnumber);//调用电话查找函数，返回节点地址
                        if(ans==NULL)
                        {
                            cout<<"============不存在此人信息！============="<<endl;
                        }
                        else
                        {
                            cout<<"-------------------------------------------------------------------------"<<endl;
                            cout<<"请以姓名、性别、电话、地址、邮政编码、邮箱、QQ号、类别的格式输入人员信息:"<<endl;
                            string w1,w2,w3,w4,w5,w6,w7,w8;
                            cin>>w1>>w2>>w3>>w4>>w5>>w6>>w7>>w8;
                            ans->loadperson(w1,w2,w3,w4,w5,w6,w7,w8);//调用数据重置函数，重置数据
                        }
                        cout<<"====================================是否继续根据电话修改信息?是(0):否(-1)"<<endl;
                        cin>>xgg;
                        system("cls");
                    }
                    ofstream outfile;
                    outfile.open("personinf.txt",ios::out);
                    if(!outfile)
                    {
                        cerr<<"open error!"<<endl;
                        exit(1);
                    }
                    //将数据写入文本
                    person*out=head;
                    while(out)
                    {
                        outfile<<out->getname()<<" "<<out->getsex()<<" "<<out->getpbnumber()<<" "<<out->getaddress()<<" "<<out->getpostal_code()<<" "<<out->getemail()<<" "<<out->getQQnumber()<<" "<<out->gettype()<<endl;
                        out=out->next;
                    }
                    outfile.close();
                }
                //链表删除操作
                person*p1=head;
                while(head)
                {
                    head=head->next;
                    delete p1;
                    p1=head;
                }
                delete head;
            }
        }
        else if(n=="5")
        {
            string sc="0";
            while(sc!="-1")//此循环控制是否退出删除界面
            {
                cout<<"----------------------------------------"<<endl;
                cout<<"请选择删除依据:                         "<<endl;
                cout<<"      根据姓名删除,请按1;               "<<endl;
                cout<<"      根据电话删除,请按2;               "<<endl;
                cout<<"---------------------返回上一界面请按-1;"<<endl;
                cin>>sc;
                system("cls");
                ifstream infile;
                infile.open("personinf.txt",ios::in);
                if(!infile)
                {
                    cerr<<"open error!"<<endl;
                    exit(1);
                }
                string q1,q2,q3,q4,q5,q6,q7,q8;
                person*head=NULL;
                while(infile>>q1>>q2>>q3>>q4>>q5>>q6>>q7>>q8)
                {
                    person*newperson=new person;
                    newperson->loadperson(q1,q2,q3,q4,q5,q6,q7,q8);
                    newperson->next=head;
                    head=newperson;
                }
                infile.close();
                if(sc=="1")
                {
                    string scc="0";
                    while(scc!="-1")//此循环控制是否继续根据姓名删除信息
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"=========请输入需要删除的信息人员的姓名:"<<endl;
                        string scname;
                        cin>>scname;
                        person*ans=head->searchscname(scname);//调用姓名查找函数，返回节点前一个节点的地址
                        person*anst=head->searchscname1(scname);//调用辅助姓名查找函数，返回节点地址
                        if(anst==NULL)
                        {
                            cout<<"============不存在此人信息！============="<<endl;
                        }
                        else
                        {
                            //删除节点信息
                            if(ans)
                            {
                                ans->next=anst->next;
                            }
                            else
                            {
                                head=anst->next;
                            }
                            delete anst;
                        }
                        cout<<"====================================是否继续根据姓名删除信息?是(0):否(-1)"<<endl;
                        cin>>scc;
                        system("cls");
                    }
                     ofstream outfile;
                     outfile.open("personinf.txt",ios::out);
                     if(!outfile)
                     {
                         cerr<<"open error!"<<endl;
                         exit(1);
                     }
                     person*out=head;
                     while(out)
                     {
                         outfile<<out->getname()<<" "<<out->getsex()<<" "<<out->getpbnumber()<<" "<<out->getaddress()<<" "<<out->getpostal_code()<<" "<<out->getemail()<<" "<<out->getQQnumber()<<" "<<out->gettype()<<endl;
                         out=out->next;
                     }
                     outfile.close();
                }
                else if(sc=="2")
                {
                    string scc="0";
                    while(scc!="-1")//此循环控制是否继续根据电话删除信息
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"=====请输入需要删除的信息人员的电话号码:"<<endl;
                        string scpbnumber;
                        cin>>scpbnumber;
                        person*ans=head->searchscpbnumber(scpbnumber);//调用电话查找函数，返回节点前一个节点的地址
                        person*anst=head->searchscpbnumber1(scpbnumber);//调用辅助电话查找函数，返回节点地址
                        if(anst==NULL)
                        {
                            cout<<"==========不存在此号码信息！==========="<<endl;
                        }
                        else
                        {
                            //删除节点信息
                            if(ans)
                            {
                                ans->next=anst->next;
                            }
                            else
                            {
                                head=anst->next;
                            }
                            delete anst;
                        }
                        cout<<"============================是否继续根据电话号码删除信息?是(0):否(-1)"<<endl;
                        cin>>scc;
                        system("cls");
                    }
                    ofstream outfile;
                    outfile.open("personinf.txt",ios::out);
                    if(!outfile)
                    {
                        cerr<<"open error!"<<endl;
                        exit(1);
                    }
                    person*out=head;
                    while(out)
                    {
                        outfile<<out->getname()<<" "<<out->getsex()<<" "<<out->getpbnumber()<<" "<<out->getaddress()<<" "<<out->getpostal_code()<<" "<<out->getemail()<<" "<<out->getQQnumber()<<" "<<out->gettype()<<endl;
                        out=out->next;
                    }
                    outfile.close();
                }
                //链表删除操作
                person*p1=head;
                while(head)
                {
                    head=head->next;
                    delete p1;
                    p1=head;
                }
                delete head;
            }
        }
    }
    cout<<"========================================"<<endl;
    cout<<endl;
    cout<<"----------------谢谢使用----------------"<<endl;

    return 0;
}

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<stdlib>
#include"person.h"
using namespace std;
int main()
{
    string n="0";
    while(n!="-1")//��ѭ�������Ƿ��˳�����
    {
        n="0";
        cout<<"----------------------------------------"<<endl;
        cout<<"       ^_^ ��ӭ����ͨ��¼ϵͳ ^_^       "<<endl;
        cout<<"\\*                                     "<<endl;
        cout<<"\\*         ������Ա��Ϣ,�밴1;         "<<endl;
        cout<<"\\*         ��ѯ��Ա��Ϣ,�밴2;         "<<endl;
        cout<<"\\*         �����Ա��Ϣ,�밴3;         "<<endl;
        cout<<"\\*         �޸���Ա��Ϣ,�밴4;         "<<endl;
        cout<<"\\*         ɾ����Ա��Ϣ,�밴5;         "<<endl;
        cout<<"\\*                                     "<<endl;
        cout<<"\\***********************�˳�ϵͳ�밴-1;"<<endl;
        cin>>n;
        system("cls");
        if(n=="1")
        {
            //���ı��ļ�
            ofstream outfile;
            outfile.open("personinf.txt",ios::app);//��ֹԭ�ı��ļ��ڵ����ݱ�ɾ����������ios::app��ʽ��
            if(!outfile)
            {
                cerr<<"open error!"<<endl;
                exit(1);
            }
            string shu="0";
            cout<<"------------------------------------------------------------------------"<<endl;
            cout<<"�����������Ա𡢵绰����ַ���������롢���䡢QQ�š����ĸ�ʽ������Ա��Ϣ:"<<endl<<endl;
            string name1,sex1,address1,email1,type1,phonenumber1,postal_code1,QQnumber1;
            while(shu!="-1")//��ѭ�������Ƿ��˳��������
            {
                //�����������ı��ļ�
                cin>>name1>>sex1>>phonenumber1>>address1>>postal_code1>>email1>>QQnumber1>>type1;
                outfile<<name1<<" "<<sex1<<" "<<phonenumber1<<" "<<address1<<" "<<postal_code1<<" "<<email1<<" "<<QQnumber1<<" "<<type1<<endl;
                cout<<endl;
                cout<<"=======================�Ƿ�Ҫ����������Ϣ����(����0);��(����-1,����������)"<<endl;
                cin>>shu;
                system("cls");//��յ�ǰ��Ļ
                if(shu!="-1")
                {
                    cout<<"------------------------------------------------------------------------"<<endl;
                    cout<<"�����������Ա𡢵绰����ַ���������롢���䡢QQ�š����ĸ�ʽ������Ա��Ϣ:"<<endl<<endl;
                }
            }
            outfile.close();//�ر��ı��ļ�
            system("cls");
        }
        else if(n=="2")
        {
            string se="0";
            while(se!="-1")//��ѭ�������Ƿ��˳���ѯ����
            {
                cout<<"----------------------------------------"<<endl;
                cout<<"��ѡ���ѯ����:                         "<<endl;
                cout<<"      ����������ȷ��ѯ,�밴1;           "<<endl;
                cout<<"      ���ݵ绰��ȷ��ѯ,�밴2;           "<<endl;
                cout<<"      ���ݵ�ַģ����ѯ,�밴3;           "<<endl;
                cout<<"      ������Ա����ѯ,�밴4;           "<<endl;
                cout<<"---------------------������һ�����밴-1;"<<endl;
                cin>>se;
                system("cls");
                ifstream infile;
                infile.open("personinf.txt",ios::in);//���ļ�
                if(!infile)
                {
                    cerr<<"open error!"<<endl;
                    exit(1);
                }
                //��������
                person *head=NULL;
                string q1,q2,q3,q4,q5,q6,q7,q8;
                while(infile>>q1>>q2>>q3>>q4>>q5>>q6>>q7>>q8)//��ѭ�������ı��������Ƿ�ȫ���洢��������
                {
                    person*newperson=new person;
                    newperson->loadperson(q1,q2,q3,q4,q5,q6,q7,q8);
                    newperson->next=head;
                    head=newperson;
                }
                infile.close();//�ر��ļ�
                if(se=="1")
                {
                    string see="0";
                    while(see!="-1")//��ѭ�������Ƿ����������������
                    {
                         cout<<"----------------------------------------"<<endl;
                         cout<<"��������Ҫ���ҵ�����:"<<endl;
                         string rname;
                         cin>>rname;
                         head->searchname(rname);//���ò�����������
                         cout<<"------------------------------------------------"<<endl;
                         cout<<"==========�����Ƿ���������������ң���(0):��(-1)"<<endl;
                         cin>>see;
                         system("cls");
                    }
                }
                else if(se=="2")
                {
                    string see="0";
                    while(see!="-1")//��ѭ�������Ƿ�������ݵ绰����
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"��������Ҫ���ҵĵ绰:"<<endl;
                        string rpho;
                        cin>>rpho;
                        head->searchpbnumber(rpho);//���ò��ҵ绰����
                        cout<<"------------------------------------------------"<<endl;
                        cout<<"==========�����Ƿ�������ݵ绰���ң���(0):��(-1)"<<endl;
                        cin>>see;
                        system("cls");
                    }
                }
                else if(se=="3")
                {
                    string see="0";
                    while(see!="-1")//��ѭ�������Ƿ�������ݵ�ַ����
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"��������Ҫ���ҵĵ�ַ:"<<endl;
                        string raddr;
                        cin>>raddr;
                        head->searchaddress(raddr);//���ò��ҵ�ַ����
                        cout<<"------------------------------------------------"<<endl;
                        cout<<"==========�����Ƿ�������ݵ�ַ���ң���(0):��(-1)"<<endl;
                        cin>>see;
                        system("cls");
                    }

                }
                else if(se=="4")//��ѭ�������Ƿ��������������
                {
                    string see="0";
                    while(see!="-1")
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"��������Ҫ���ҵ����:"<<endl;
                        string rtype;
                        cin>>rtype;
                        head->searchtype(rtype);//���������Һ���
                        cout<<"------------------------------------------------"<<endl;
                        cout<<"==========�����Ƿ�������������ң���(0):��(-1)"<<endl;
                        cin>>see;
                        system("cls");
                    }
                }
                //����ɾ������
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
            while(so!="-1")//��ѭ�������Ƿ��˳��������
            {
                cout<<"----------------------------------------"<<endl;
                cout<<"��ѡ�������������:                     "<<endl;
                cout<<"      ���������������,�밴1;           "<<endl;
                cout<<"      �����Ա��������,�밴2;           "<<endl;
                cout<<"      ���������������,�밴3;           "<<endl;
                cout<<"      ��������������,�밴4;           "<<endl;
                cout<<"---------------------������һ�����밴-1;"<<endl;
                cin>>so;
                system("cls");
                ifstream infile;
                infile.open("personinf.txt",ios::in);//���ļ�
                if(!infile)
                {
                    cerr<<"open error!"<<endl;
                    exit(1);
                }
                //��������
                person *head=NULL;
                string q1,q2,q3,q4,q5,q6,q7,q8;
                while(infile>>q1>>q2>>q3>>q4>>q5>>q6>>q7>>q8)
                {
                    person*newperson=new person;
                    newperson->loadperson(q1,q2,q3,q4,q5,q6,q7,q8);
                    newperson->next=head;
                    head=newperson;
                }
                infile.close();//�ر��ļ�
                if(so=="1")
                {
                    string soo="0";
                    while(soo!="-1")//��ѭ�������Ƿ�������������������
                    {
                        cout<<"----------------------------------------"<<endl;
                        head->sortname();//��������������
                        person*p1=head;//�½�p1ָ�룬ָ���ͷ
                        while(p1)
                        {
                            p1->pinout();//����������������p1��ָ��ռ��ڵ���������
                            p1=p1->next;//p1ָ����һ���ռ�
                        }
                        cout<<"=============================================="<<endl;
                        cout<<"--------�Ƿ�����������������������(0):��(-1)"<<endl;
                        cin>>soo;
                        system("cls");
                    }
                }
                else if(so=="2")
                {
                    string soo="0";
                    while(soo!="-1")//��ѭ�������Ƿ���������Ա��������
                    {
                        cout<<"----------------------------------------"<<endl;
                        head->sortsex();//�����Ա�������
                        person*p1=head;//�½�p1ָ�룬ָ���ͷ
                        while(p1)
                        {
                            p1->pinout();//����������������p1��ָ��ռ��ڵ���������
                            p1=p1->next;//p1ָ����һ���ռ�
                        }
                        cout<<"=============================================="<<endl;
                        cout<<"--------�Ƿ���������Ա������������(0):��(-1)"<<endl;
                        cin>>soo;
                        system("cls");
                    }
                }
                else if(so=="3")
                {
                    string soo="0";
                    while(soo!="-1")//��ѭ�������Ƿ�����������������������
                    {
                        cout<<"----------------------------------------"<<endl;
                        head->sortpostal_code();//������������������
                        person*p1=head;//�½�p1ָ�룬ָ���ͷ
                        while(p1)
                        {
                            p1->pinout();//����������������p1��ָ��ռ��ڵ���������
                            p1=p1->next;//p1ָ����һ���ռ�
                        }
                        cout<<"=============================================="<<endl;
                        cout<<"----�Ƿ���������������������������(0):��(-1)"<<endl;
                        cin>>soo;
                        system("cls");
                    }
                }
                else if(so=="4")
                {
                    string soo="0";
                    while(soo!="-1")//��ѭ�������Ƿ������������������
                    {
                        cout<<"----------------------------------------"<<endl;
                        head->sorttype();//�������������
                        person*p1=head;//�½�p1ָ�룬ָ���ͷ
                        while(p1)
                        {
                            p1->pinout();//����������������p1��ָ��ռ��ڵ���������
                            p1=p1->next;//p1ָ����һ���ռ�
                        }
                        cout<<"=============================================="<<endl;
                        cout<<"--------�Ƿ����������������������(0):��(-1)"<<endl;
                        cin>>soo;
                        system("cls");
                    }
                }
                //����ɾ������
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
            while(xg!="-1")//��ѭ�������Ƿ��˳��޸Ľ���
            {
                cout<<"----------------------------------------"<<endl;
                cout<<"��ѡ���޸ĸ���:                         "<<endl;
                cout<<"      ���������޸�,�밴1;               "<<endl;
                cout<<"      ���ݵ绰�޸�,�밴2;               "<<endl;
                cout<<"---------------------������һ�����밴-1;"<<endl;
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
                    while(xgg!="-1")//��ѭ�������Ƿ�������������޸�
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"==========��������Ҫ�޸���Ϣ����Ա������"<<endl;
                        string xgname;
                        cin>>xgname;
                        person*ans=head->searchxname(xgname);//�����������Һ��������ؽڵ��ַ
                        if(ans==NULL)
                        {
                            cout<<"============�����ڴ�����Ϣ��============="<<endl;
                        }
                        else
                        {
                            cout<<"-------------------------------------------------------------------------"<<endl;
                            cout<<"�����������Ա𡢵绰����ַ���������롢���䡢QQ�š����ĸ�ʽ������Ա��Ϣ:"<<endl;
                            string w1,w2,w3,w4,w5,w6,w7,w8;
                            cin>>w1>>w2>>w3>>w4>>w5>>w6>>w7>>w8;
                            ans->loadperson(w1,w2,w3,w4,w5,w6,w7,w8);//�����������ú�������������
                        }
                        cout<<"====================================�Ƿ�������������޸���Ϣ?��(0):��(-1)"<<endl;
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
                    //������д���ı�
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
                    while(xgg!="-1")//��ѭ�������Ƿ�������ݵ绰�޸�
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"==========��������Ҫ�޸���Ϣ����Ա�绰��"<<endl;
                        string xgpbnumber;
                        cin>>xgpbnumber;
                        person*ans=head->searchxpbnumber(xgpbnumber);//���õ绰���Һ��������ؽڵ��ַ
                        if(ans==NULL)
                        {
                            cout<<"============�����ڴ�����Ϣ��============="<<endl;
                        }
                        else
                        {
                            cout<<"-------------------------------------------------------------------------"<<endl;
                            cout<<"�����������Ա𡢵绰����ַ���������롢���䡢QQ�š����ĸ�ʽ������Ա��Ϣ:"<<endl;
                            string w1,w2,w3,w4,w5,w6,w7,w8;
                            cin>>w1>>w2>>w3>>w4>>w5>>w6>>w7>>w8;
                            ans->loadperson(w1,w2,w3,w4,w5,w6,w7,w8);//�����������ú�������������
                        }
                        cout<<"====================================�Ƿ�������ݵ绰�޸���Ϣ?��(0):��(-1)"<<endl;
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
                    //������д���ı�
                    person*out=head;
                    while(out)
                    {
                        outfile<<out->getname()<<" "<<out->getsex()<<" "<<out->getpbnumber()<<" "<<out->getaddress()<<" "<<out->getpostal_code()<<" "<<out->getemail()<<" "<<out->getQQnumber()<<" "<<out->gettype()<<endl;
                        out=out->next;
                    }
                    outfile.close();
                }
                //����ɾ������
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
            while(sc!="-1")//��ѭ�������Ƿ��˳�ɾ������
            {
                cout<<"----------------------------------------"<<endl;
                cout<<"��ѡ��ɾ������:                         "<<endl;
                cout<<"      ��������ɾ��,�밴1;               "<<endl;
                cout<<"      ���ݵ绰ɾ��,�밴2;               "<<endl;
                cout<<"---------------------������һ�����밴-1;"<<endl;
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
                    while(scc!="-1")//��ѭ�������Ƿ������������ɾ����Ϣ
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"=========��������Ҫɾ������Ϣ��Ա������:"<<endl;
                        string scname;
                        cin>>scname;
                        person*ans=head->searchscname(scname);//�����������Һ��������ؽڵ�ǰһ���ڵ�ĵ�ַ
                        person*anst=head->searchscname1(scname);//���ø����������Һ��������ؽڵ��ַ
                        if(anst==NULL)
                        {
                            cout<<"============�����ڴ�����Ϣ��============="<<endl;
                        }
                        else
                        {
                            //ɾ���ڵ���Ϣ
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
                        cout<<"====================================�Ƿ������������ɾ����Ϣ?��(0):��(-1)"<<endl;
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
                    while(scc!="-1")//��ѭ�������Ƿ�������ݵ绰ɾ����Ϣ
                    {
                        cout<<"----------------------------------------"<<endl;
                        cout<<"=====��������Ҫɾ������Ϣ��Ա�ĵ绰����:"<<endl;
                        string scpbnumber;
                        cin>>scpbnumber;
                        person*ans=head->searchscpbnumber(scpbnumber);//���õ绰���Һ��������ؽڵ�ǰһ���ڵ�ĵ�ַ
                        person*anst=head->searchscpbnumber1(scpbnumber);//���ø����绰���Һ��������ؽڵ��ַ
                        if(anst==NULL)
                        {
                            cout<<"==========�����ڴ˺�����Ϣ��==========="<<endl;
                        }
                        else
                        {
                            //ɾ���ڵ���Ϣ
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
                        cout<<"============================�Ƿ�������ݵ绰����ɾ����Ϣ?��(0):��(-1)"<<endl;
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
                //����ɾ������
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
    cout<<"----------------ллʹ��----------------"<<endl;

    return 0;
}

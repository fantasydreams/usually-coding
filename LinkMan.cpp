// LinkMan.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<sstream>
#include<conio.h>
#include<fstream>

using namespace std;

//结构体：
struct LinkMan
{
	char name[10];
	char num[12];
	char position[16];
	char postadd[18];
	char brithday[15];
	struct LinkMan *next;
};

typedef struct LinkMan Link;

//函数定义区；
char Menu();
Link *AddLinkMan();
Link *Readfile(Link *head);
void PrintAllLinkan(Link *head);
void SaveToFile(Link *head);
Link *Sort(Link *head,Link *p);
void Search(Link *head,string s);
void PrintOneLink(Link *p);
void Free(Link *p);
Link *Delete(Link *head);




int _tmain(int argc, _TCHAR* argv[])
{
	char ch;
	int i=0;
	Link *head=NULL,*p1=NULL,*pp=NULL;
	head=Readfile(head);
	if(head==NULL)
	{
	char choose;
	cout<<'\a'<<"there isn't exist a linkman,would you link to add a new one(Y or N)";
	dian:
	cin>>choose;
	if(choose!='Y' && choose !='y' &&choose!='N' && choose!='n')
	{
		cout<<'\a'<<"please input a right key:";
		goto dian;
	}
	if(choose=='Y' || choose=='y')
	{
		i++;
		for(int j=1;j;)
	{
		pp=AddLinkMan();
		if(head==NULL)    head=pp;
			head=Sort(head,pp);
		cout<<"would you link to add a new one(Y or N)";
	Dian:
	cin>>choose;
	if(choose!='Y' && choose !='y' &&choose!='N' && choose!='n')
	{
		cout<<'\a'<<"please input a right key:";
		goto Dian;
	}
	if(choose =='N' || choose=='n')  j=0;
	}
	}
	}
	while(true)
	{
		DIan:
	ch=Menu();
	string s;
	switch(ch)
	{
	case '0':if(i!=0) SaveToFile(head);
		Free(head);
		cout<<"preaciate your use."<<"press any key to exit.";
		_getch();
		exit(1);
	case '1':cout<<endl;PrintAllLinkan(head);break;
	case '2':
		cout<<"please input linkman's name:";
		cin>>s;
		Search(head,s);
		break;
	case '3':
		pp=AddLinkMan();
		head=Sort(head,pp);
		i++;
		char choose;
		cout<<"would you link to add a new one(Y or N)";
		dian1:
		cin>>choose;
		if(choose!='Y' && choose !='y' &&choose!='N' && choose!='n')
		{
			cout<<'\a'<<"please input a right key:";
			goto dian1;
		}
		if(choose=='Y' || choose=='y')
		{
			for(int j=1;j;)
		{
			pp=AddLinkMan();
			if(head==NULL)  head=pp;
			head=Sort(head,pp);
			cout<<'\a'<<"would you link to add a new one(Y or N)";
		Dian1:
		cin>>choose;
		if(choose!='Y' && choose !='y' &&choose!='N' && choose!='n')
		{
			cout<<'\a'<<"please input a right key:";
			goto Dian1;
		}
		if(choose =='N' || choose=='n')  j=0;
		}
		}
		break;
	case '4':
		head=Delete(head);
		i++;
		break;
	default:
		cout<<'\a'<<"please input a right key:";
		goto DIan;
	}
	}
	return 0;
}
char Menu()    //菜单函数；
{
	char ch;
	cout<<"		***********************************************"<<endl
	    <<"		*           1、PrintAllLinkMan                *"<<endl
		<<"		*           2、Search  LinkMan                *"<<endl
	    <<"		*           3、Add     LinkMan                *"<<endl
		<<"		*           4、Delete  LinkMan                *"<<endl
		<<"		*           0、Exit                           *"<<endl
		<<"		***********************************************"<<endl
		<<"		please input your choose:";
	Dian:
	cin>>ch;
	fflush(stdin);
	if(ch>='0' && ch<='4')  return ch;
	else  goto Dian;
	
}


//创建LinkMan函数；
Link *AddLinkMan()
{
	Link *p;
	p=(Link *)malloc(sizeof(Link));
	cout<<"input 'x' to jump;"<<endl;
	cout<<"please input linkman's name:";
	cin>>p->name;
	cout<<"please input linkman's linknumber:";
	cin>>p->num;
	cout<<"please input linkman's postadd:";
	cin>>p->postadd;
	cout<<"please input linkman's position:";
	cin>>p->position;
	cout<<"please input linkman's brithday:";
	cin>>p->brithday;
	fflush(stdin);
	cout<<"seccess add a linkman!"<<endl;
	return p;
}


//从文件中读取内容到内存；

Link *Readfile(Link *head)
{
	Link *p=NULL,*pr=NULL;
	int i=0;
	ifstream in("LinkMan.txt");
	for(string s;getline(in,s);)
	{
		i++;
		p=(Link *)malloc(sizeof(Link));
		p->next=NULL;
		stringstream sin(s);
		sin>>p->name;
		sin>>p->num;
		sin>>p->postadd;
		sin>>p->position;
		sin>>p->brithday;
		if(head==NULL)    {head=p;pr=p;}
		else {pr->next=p;pr=p;}
	}
	return head;
}

//打印所有的联系人；
void PrintAllLinkan(Link *head)
{
	Link *p=head;
	if(head==NULL)
	{
		cout<<'\a'<<"there isn't exist any imformatiom!"
			<<"press any key to continue."<<endl;
		getch();
		goto end;
	}
	for(;p!=NULL;)
	{
		cout<<"name   :"<<p->name<<"	"<<"number:"<<p->num<<"	"<<"position:"<<p->position<<endl
			<<"postadd:"<<p->postadd<<"	"<<"brithday:"<<p->brithday<<endl<<endl;
		if(p->next==NULL)  p=NULL;
		else p=p->next;
	}
	end:;
}

//将LinkMan保存到文件；
void SaveToFile(Link *p)
{
	FILE *fp;
	fp=fopen("LinkMan.txt","w");
	for(;p!=NULL;)
	{
		fprintf(fp,"%s",p->name);
		fputs("  ",fp);
		fprintf(fp,"%s",p->num);
		fputs("  ",fp);
		fprintf(fp,"%s",p->postadd);
		fputs("  ",fp);
		fprintf(fp,"%s",p->position);
		fputs("  ",fp);
		fprintf(fp,"%s",p->brithday);
		fputc('\n',fp);
		if(p->next==NULL)  p=NULL;
		else p=p->next;
	}
	fclose(fp);
}

//排序函数：
Link *Sort(Link *head,Link *p)
{
	int i=0;
	Link *pr=head,*ip=NULL;
	if(head==p)  return head;
	for(;pr!=NULL;)
	{
		if((p->name)>=(pr->name))
		{
			ip=pr->next;
			pr->next=p;
			p->next=ip;
			i++;
			break;
		}
		if(pr->next==NULL)  pr=NULL;
		else  pr=pr->next;
	}
	if(i==0)
	{
		p->next=head;
		head=p;
	}
	return head;
}

//搜索LinkMan;

void Search(Link *head,string s)
{
	Link *pr=head;
	int i=0;
	for(;pr!=NULL;)
	{
		if(pr->name==s)
		{
			cout<<endl;
			PrintOneLink(pr);
			cout<<endl;
			i++;
		}
		if(pr->next==NULL)  pr=NULL;
		else pr=pr->next;
	}
	if(i==0)
	{
		cout<<'\a'<<"there isn't exist any imformatiom!"
			<<"press any key to continue."<<endl;
		getch();
	}
}

//打印一个LinkMan函数；
void PrintOneLink(Link *p)
{
	cout<<"name:"<<p->name<<"	"<<"number:"<<p->num<<"	"<<"postadd:"<<p->postadd<<endl
		<<"position"<<p->position<<"	"<<"brithday:"<<p->brithday<<endl;
}

//释放内存函数；
void Free(Link* p)
{
	Link *ip;
	for(;p!=NULL;)
	{
		if(p->next==NULL)
		{
		free(p);
		p=NULL;
		}
		else
		{
			ip=p->next;
			free(p);
			p=ip;
		}
	}
}

//删除LinkMan函数；
Link *Delete(Link *head)
{
	Link *p=head,*ip=NULL,*ip1=NULL;
	string s;
	cout<<"please input the linkman's name you want to delete:";
	cin>>s;
	if(p->name==s)
	{
		cout<<endl;
		PrintOneLink(p);
		cout<<endl;
		cout<<'\a'<<"are you sure to delete(Y or N):";
		char ch;
		dian:
		cin>>ch;
		if(ch!='Y' && ch!='y' && ch!='N' &&ch!='n')
		{
			cout<<'\a'<<"please input a right key:";
			goto dian;
		}
		if(ch=='Y' || ch=='y')
		{
			if(head->next==NULL)
			{
				cout<<"seccess to delete!"<<endl;
				return NULL;
			}
			else
			{
				head=p->next;
				free(p);
				cout<<"seccess to delete!"<<endl;
				return head;
			}
		}else
		{
			return head;
		}
	}
	for(;p->next!=NULL;)
	{
		if(((p->next)->name)==s)
		{
			cout<<endl;
			PrintOneLink(p->next);
			cout<<endl;
			cout<<'\a'<<"are you sure to delete(Y or N):";
			char ch;
			dian1:
			cin>>ch;
			if(ch!='Y' && ch!='y' && ch!='N' &&ch!='n')
			{
				cout<<'\a'<<"please input a right key:";
				goto dian1;
			}
			if(ch=='Y' || ch=='y')
			{	
				ip=p->next;
				ip1=ip->next;
				free(ip);
				p->next=ip1;
				cout<<"seccess to delete!"<<endl;
				return head;
			}else
			{
				return head;
			}
		}
		p=p->next;
	}
	cout<<'\a'<<"there isn't exist any imformatiom!"
			<<"press any key to continue."<<endl;
	getch();
	return head;
}
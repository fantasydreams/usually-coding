#pragma comment(lib,"user32")
#include<windows.h>          //window�ļ�
#include<conio.h>
#include<stdio.h>            //Ԥ����
#include<stdlib.h>           //�����ڴ����裻
#include<string.h>           //�����ַ���

//����������
int Menu();                                      //�˵���
int SearchBYName(struct link *head,char a[]);    //���������ң�ɾ���ڵ�ʱ�ã���
int SearchBYNum(struct link *head,int n);        //��ѧ�Ų��ң�ɾ���ڵ�ʱ�ã���
struct link *CreatNode();                        //�����½ڵ㣻
struct link *CreatLink(struct link *head);       //��������
struct link *Insert(struct link *head,int n);    //����ڵ㣻
struct link *Delete(struct link *head,int n);    //ɾ���ڵ㣻
struct link *SearchByNAME(struct link *head,char a[]); //���������ң��޸���Ϣ����     
struct link *SearchByNUM(struct link *head,int n);     //��ѧ�Ų��ң��޸���Ϣ����
struct link *SearchAndInsert(struct link *head); //������Ӧ��Ϣ������Ӧλ�ò���ڵ㣻
struct link *ReadFromFile(struct link *head);    //���ļ���ȡ���ݵ��ڴ棻
struct link * Delete1(struct link *head);        //ɾ��һ���ض��Ľڵ㣻
void SearchByName(struct link *head,char a[]);   //���������ң�
void Rvise(struct link *head);                   //�޸�ѧ����Ϣ��
void SearchByNum(struct link *head,int n);       //��ѧ��ѧ�Ų��ң�
void PrintOneNode(struct link *p);               //��������ڵ㣻
void SearchByClass(struct link *head,int n);     //���༶���ң�
void PrintAll(struct link *head);                //���ȫ������
void Input(struct link *p);                      //���룻
void Summatiom(struct link *p);                  //�����ƽ���֣��޸���Ϣ����
void Release(struct link *head);                 //�ͷ��ڴ棻
void SortByClass1(struct link *head);            //���հ༶����������
void SortByClass2(struct link *head);            //���հ༶�Ľ�������
void SortBySex1(struct link *head);              //�����Ա�����
void SortBySex2(struct link *head);
void SortByNum1(struct link *head);              //����ѧ�ŵ���������
void SortByNum2(struct link *head);              //����ѧ�ŵĽ�������
void SortBySum1(struct link *head);              //�����ܷ���������
void SortBySum2(struct link *head);              //�����ֽܷ�������
void SortByAver1(struct link *head);             //����ƽ������������
void SortByAver2(struct link *head);             //����ƽ���ֽ�������
void SwapSemster(struct link *p0,struct link *p1);//����semster���ݣ�
void SwapCla(struct link *p0,struct link *p1);   //����cla���ݣ�
void SwapName(struct link *p0,struct link *p1);  //����name���ݣ�
void SwapNum(struct link *p0,struct link *p1);   //����num���ݣ�
void SwapSex(struct link *p0,struct link *p1);   //����Sex���ݣ�
void SwapScore(struct link *p0,struct link *p1); //����score���ݣ�
void SwapSum(struct link *p0,struct link *p1);   //����sum���ݣ�
void SwapAver(struct link *p0,struct link *p1);  //����aver����;
void SaveFile(struct link *head);                //�����ݱ��浽�ļ���
void SearchByGrade(struct link *head);           //ͨ���ɼ����Ҳ������ѧ����
struct link *SearchByG1(struct link *p,float n); //���ݳɼ�һ���Ҳ������ѧ����
struct link *SearchByG2(struct link *p,float n); //���ݳɼ������Ҳ������ѧ����
struct link *SearchByG3(struct link *p,float n); //���ݳɼ������Ҳ������ѧ����
struct link *SearchByG4(struct link *p,float n); //���ݳɼ��Ĳ��Ҳ������ѧ����
struct link *SearchByG5(struct link *p,float n); //���ݳɼ�����Ҳ������ѧ����
void SearchBySemster(struct link *head,int n);         //����ѧ�ڲ��ң�

/*
void Swap(struct link *p0,struct link *p1);      //�������ݣ�
*/

//�Զ��庯�����ͣ�
struct link
{
	int semster;            //����ѧ�ڣ�
	int cla;                //����ѧ���༶��
	int num;                //����ѧ�ţ�
	char name[20];          //����ѧ��������
	char sex;               //����ѧ���Ա�
	float score[5];         //����ɼ���
	float sum;              //�����ܷ֣�
	float aver;             //����ƽ���֣�
	struct link * next;     //��������ָ����һ���ڵ㣻
};

//��������
void main()
{
	int n,i,c;                                            //ʵ�ζ��壻
	char *p1;
	struct link *head=NULL;                               //����ͷ������ֵΪ�գ�
    while(1)
	{
dian0:n=Menu();                                           //�������ã�
dian1:switch(n)                                           //ѡ��ṹ��
		{
		case 1:head=CreatLink(head);                      //�������������ã�
			break;
		case 2:printf("please input where you want to insert?");
			scanf("%d",&i);                               //���룻
		 	head=Insert(head,i);                          //���뺯�����ã�
			break;
		case 3:
			printf("please input which node you want to delete?");
			scanf("%d",&i);                               //���룻
			head=Delete(head,i);                          //ɾ���������ã�
			break;
		case 4:printf("please input which class you want to search?");
			scanf("%d",&i);                               //���룻
			SearchByClass(head,i);                        //���༶���Һ������ã�
			break;
		case 5:printf("please input the number you want to search:");
			scanf("%d",&i);                               //���룻
			SearchByNum(head,i);                          //��ѧ�Ų��Һ������ã�
			break;
		case 6:printf("please input the student's name:");
			p1=malloc(sizeof(char));
			scanf("%s",p1);                               //���룻
			SearchByName(head,p1);                        //���������Һ������ã�
			break;
		case 7:Rvise(head);                               //�޸���Ϣ�������ã�
			break;
		case 8:printf(" 1 stand for sequence, 2 stand for grade down:");
dian2:scanf("%d",&i);
			switch(i)
			{
			case 1:SortByClass1(head);                    //���༶�������������ã�
				break;
			case 2:SortByClass2(head);
				break;
			default:MessageBox(NULL,"your input form is not correct!please input again!","MessageBox",MB_OK|MB_SETFOREGROUND);
				goto dian2;
			}
			break;
		case 9:printf(" 1 stand for male front, 2 stand for female front:");
dian3:scanf("%d",&i);
			switch(i)
			{
			case 1:SortBySex1(head);                      //�����Ա���������
				break;
			case 2:SortBySex2(head);
				break;
			default:MessageBox(NULL,"your input form is not correct!please input again!","MessageBox",MB_OK|MB_SETFOREGROUND);
				goto dian3;
			}
			break;
		case 10:printf(" 1 stanf for sequence, 2 stand for grade down,please input your choose:");
dian4:scanf("%d",&i);
			switch(i)
			{
			case 1:SortByNum1(head);                      //ѧ�����������ã�
				break;
			case 2:SortByNum2(head);
				break;
			default:MessageBox(NULL,"your input form is not correct!please input again!","MessageBox",MB_OK|MB_SETFOREGROUND);
				goto dian4;
			}
			break;
		case 11: printf(" 1 stand for sequence, 2 stand for grade down,please input your choose:");
dian5:scanf("%d",&i);
	        switch(i)
			{
			case 1:SortByAver1(head);                     //����ƽ������������
				break;
			case 2:SortByAver2(head);
				break;
			default:MessageBox(NULL,"your input form is not correct!please input again!","MessageBox",MB_OK|MB_SETFOREGROUND);
				goto dian5;
			}
			break;
		case 12:printf(" 1 stand for sequence, 2 stand for grade down,please input your choose:");
dian6:scanf("%d",&i);
			switch(i)
			{
			case 1:SortBySum1(head);                      //�ܷ����������ã�
				break;
			case 2:SortBySum2(head);
				break;
			default:MessageBox(NULL,"your input form is not correct!please input again!","MessageBox",MB_OK|MB_SETFOREGROUND);
				goto dian6;
			}
			break;
		case 13:head=ReadFromFile(head);                  //���ô��ļ���ȡ���ݺ�����
			break;
		case 14:SaveFile(head);                           //���ý����ݱ��浽�ļ�������
			break;
		case 15:PrintAll(head);                           //������������ã�
			break;
		case 16:head=Delete1(head);                       //�������ã�
			break;
		case 17:head=SearchAndInsert(head);               //�������ã�
			break;
		case 18:SearchByGrade(head);                      //SearchByGrade�������ã�
			break;
		case 19:
			printf("please input the semster:");
			scanf("%d",&i);
			SearchBySemster(head,i);                      //SearchBySemster�������ã�
			break;
		case 0:c=MessageBox(NULL,"befor exit,be sure you are\nsave the file!\npress ok to exit\npress cancel to return\nthe execut!","MessageBox",MB_OKCANCEL|MB_SETFOREGROUND);//��ʾ�û������ļ���
			if(c==2)                                      //�û����ȡ������˵���
			{
				goto dian0;
			}
			else
			{
				Release(head);                             //�ͷ��ڴ溯�����ã�
				printf("end of program!\n");
			    exit(0);
			}
		default:MessageBox(NULL,"your input form is not correct!now please input again!\n1 stand for sequence, 2 stand for grade down!","MessageBox",MB_OKCANCEL|MB_SETFOREGROUND);
			scanf("%d",&n);                               //���롮
			goto dian1;                                   //goto��䣬�������ʱ����1���������룻
		}
	}
}/*�˺����Ĺ����Ǹ������˵�����ֵ���в�����switch������ѡ�񣬲�������صĹ��ܡ�*/


//�������ܣ���ʾ���˵���
//������int��
//����ֵ��choose��
int Menu()                                                //�������壻
{
	int choose;
	printf("         ************************************************************\n");
	printf("         *                        function                          *\n");
	printf("         *                      1:CreatLink                         *\n");
	printf("         *                      2:Insert one                        *\n");
	printf("         *                      3:Delete one                        *\n");
	printf("         *                      4:SearchByClass                     *\n");
	printf("         *                      5:SearchByNum                       *\n");
	printf("         *                      6:SearchByName                      *\n");
	printf("         *                      7:Rvise(�޸�)                       *\n");
	printf("         *                      8:SortByClass                       *\n");
	printf("         *                      9:SortBySex                         *\n");
	printf("         *                      10:SortByNum                        *\n");
	printf("         *                      11:SortByAver                       *\n");
	printf("         *                      12:SortBySum                        *\n");
	printf("         *                      13:ReadFromFile                     *\n");
	printf("         *                      14:SaveFile                         *\n");
	printf("         *                      15:PrintAll                         *\n");
	printf("         *                      16:SearchAndDelete(���Ҳ�ɾ��)      *\n");
	printf("         *                      17:SearchAndInsert                  *\n");
	printf("         *                      18:SearchByGrade(����ĳ�Ʋ�����ѧ��)*\n");
	printf("         *                      19:SearchBySemster(��ѧ�ڲ���)      *\n");
	printf("         *                      0:exit                              *\n");
	printf("         ************************************************************\n");
	printf("\n");
	printf("             *****please iput which function you want to use****:");
	scanf("%d",&choose);                                  //���룻
	return choose;                                        //����choose��
}

//�������ܣ�����һ������
//�������ͣ�struct link *;
//����ֵ��head;

struct link *CreatLink(struct link *head)                 //�������壻
{
	int n;
	char c;
	struct link *p;        //����һ��ָ�룻
	struct link *pr;
	if(head!=NULL)
	{
		n=MessageBox(NULL,"There have the old imformatiom!\nwhether to creat other node after\nit?","MessageBox",MB_OKCANCEL|MB_SETFOREGROUND);
		if(n==1)//���ݴ��ڷ���ֵ��
		{
			for(pr=head;pr->next!=NULL;)//�ߵ��������һ���ڵ㡣
			{
				pr=pr->next;
			}
			MessageBox(NULL,"now,creat a now node after the old link!","MssageBox",MB_OK|MB_SETFOREGROUND);
			p=(struct link *)malloc(sizeof(struct link));
			Input(p);//�������ã�
			pr->next=p;
			goto duandian;
		}
		else
		{
			goto end;//�û�ѡȡȡ����
		}
	}
	p=(struct link *)malloc(sizeof(struct link));         //��ϵͳ����һ���ڴ沢����ַ����ָ��p;
	if(head==NULL)         //����ַ��Ϊ�����ͷ����
	{
		head=p;
		pr=head;
	}
	do
	{
		Input(p);          //�����뺯�����е��ã�
duandian:printf("go on?(y or n)");                        //���õ�duandian�������ʱ�ã�
		scanf("%1s",&c);
		if(c!='n' && c!='N' && c!='y' && c!='Y')          //�ж��������ȷ�ԣ�
		{
			MessageBox(NULL,"you input a wrong char!","warning",MB_OK|MB_SETFOREGROUND);
			goto duandian;                                //����duandian;
		}
		if(c=='y' || c=='Y')
		{
			p=(struct link *)malloc(sizeof(struct link));//�����ڴ棻
			{
				if(p==NULL)                              //����ʧ��ʱ�˳���
				{
				    MessageBox(NULL,"can't apply for size succesful! exit!","error",MB_OK|MB_SETFOREGROUND);
					exit(1);
				}
			}
			pr->next=p; 
			pr=pr->next;
		}
	}
	while(c=='y' || c=='Y');                              //ѭ��������
end:return head;           //�����׵�ַ��
}

//�������ܣ�������Ϣ��
//�������ͣ�void;
//����ֵ���ޣ�

void Input(struct link *p)                                //�������壻
{
	int i;
	float sum=0,aver;
	printf("please input the semster:");
	scanf("%d",&p->semster);//����ѧ�ڣ�
	printf("please input the student's num:");
	scanf("%d",&p->num);  //����ѧ�ţ�
	printf("please input the student's class:");
	scanf("%d",&p->cla);  //����༶��
	printf("please input the student's name:");
	scanf("%s",p->name);  //����������
	printf("please input the student's sex:");
	scanf("%1s",&p->sex); //�����Ա�
	for(i=0;i<5;i++)
	{
		printf("please input the %dth score:",i+1);
		scanf("%f",&p->score[i]);                         //����ɼ���
		sum=sum+p->score[i];                              //���ܷ�;
	}
	p->sum=sum;           //���ܷ�д�룻
	aver=sum/5;           //��ƽ���ɼ���
	p->aver=aver;         //��ƽ���ɼ�д�룻
	p->next=NULL;         //��ָ��ָ��գ�
}

//�������ܣ������������
//�������ͣ�void��
//����ֵ���ޣ�

void PrintAll(struct link *head)                           //�������壻
{
	int i;
	struct link *p;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
    	p=head;
	    printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
	    do//���������Ϣ����Ļ��
		{
			printf("%-3d",p->semster);
	    	printf(" %-6s",p->name);
	    	printf("%-5d",p->cla);
	    	printf("%-5d",p->num);
	    	printf("%-5c",p->sex);
	    	for(i=0;i<5;i++)                                  //����forѭ�����룻
			{
	    		printf("%-8.2f",p->score[i]);
			}
	    	printf("%-8.2f",p->sum);
	    	printf("%-6.2f",p->aver);
	    	printf("\n");
	    	p=p->next;
		}
    	while(p!=NULL);                                       //��ָ�벻Ϊ��ʱ����ѭ����
	}
}

//�������ܣ��½�һ���ڵ㣻
//������struct link *;
//����ֵ��p��

struct link *CreatNode()                                  //�������壻
{
	struct link *p;                                       //ʵ�ζ��壻
	p=(struct link *)malloc(sizeof(struct link));         //�����ڴ棻
	if(p==NULL)
	{
		MessageBox(NULL,"can't ask for memoroy! exit!","error",MB_OK|MB_SETFOREGROUND);
		exit(0);
	}
	Input(p);            //���뺯�����ã�
	return p;            //����p���׵�ַ��
}

//�������ܣ�����ڵ㣻
//������struct link *��
//����ֵ��head;

struct link *Insert(struct link *head,int n)                  //�������壻
{
	int i;
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)
	{
		p=CreatNode();       //�����ڵ㺯�����ã�
		head=p;
		MessageBox(NULL,"succesful to insert a node!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
	    if(n==1)             //n=1ʱ������ͷ����ַ��
		{
			p=CreatNode();    //�����ڵ㺯�����ã�
		    pr=head;
		    head=p;
		    p->next=pr;
			MessageBox(NULL,"succesful to insert a node!","MessageBox",MB_OK|MB_SETFOREGROUND);
		}
    	else
		{
		    pr=head;
		    for(i=0;i<n-1;i++)                            //Ѱ��Ҫ����Ľڵ�λ�ã�����Ҳ�����ӡ������Ϣ��
			{
			    if(pr==NULL)
				{
				    MessageBox(NULL,"out of arrange!","error",MB_OK|MB_SETFOREGROUND);
					break;
				}
			    else
				{
					if(i==n-2)   //��λ��
					{
						p=CreatNode();       //�����ڵ㺯�����ã�
				        pr1=pr->next;
				        pr->next=p;
				        p->next=pr1;
						MessageBox(NULL,"succesful to insert a node!","MessageBox",MB_OK|MB_SETFOREGROUND);
					}
				}
				pr=pr->next;                              //�ڵ�ָ����һ���ڵ㣻
			}
		}
	}
	return head;                                          //��������ͷ�����׵�ַ��
}

//�������ܣ�ɾ��һ���ڵ㣻
//������struct link *��
//����ֵ��head��

struct link *Delete(struct link *head,int n)              //�������壻
{
	int i;
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)                                        //�ж��Ƿ���������ڣ�
	{
		MessageBox(NULL,"have nothing about link imformation!","error",MB_OK|MB_SETFOREGROUND);
		exit(0);
	}
	if(n==1)
	{
		p=head->next;
		free(head);                                       //�ͷű�ɾ���ڵ���ռ���ڴ棻
		head=p;//��head���һ���ڵ���Ϊhead;
		MessageBox(NULL,"succesful to delete the node!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		p=head;
    	for(i=0;i<n-1;i++)
		{
	    	if(p==NULL)
			{
				MessageBox(NULL,"out of arrange!can't delete!","error",MB_OK|MB_SETFOREGROUND);
				break;//������Χ���������ԭ�򣬲�ֹͣ�˺�����
			}
		    else
			{
				if(i==n-2)
				{
		        	pr=p->next;
		        	pr1=pr->next;
		        	p->next=pr1;
		        	free(pr);                             //�ͷű�ɾ���ڵ���ռ���ڴ棻
					MessageBox(NULL,"successfully to delete!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
			}
			p=p->next;
		}
	}
	return head;
}

//�������ܣ���������ڵ㣻
//������void��
//����ֵ���ޣ�

void PrintOneNode(struct link *p)                         //�������壻
{
	int i;
	printf("%-3d",p->semster);
	printf(" %-6s",p->name);
	printf("%-5d",p->cla);
	printf("%-5d",p->num);
	printf("%-5c",p->sex);
	for(i=0;i<5;i++)
	{
		printf("%-8.2f",p->score[i]);
	}
	printf("%-8.2f",p->sum);
	printf("%-6.2f",p->aver);
	printf("\n");        //���з���
}

//�������ܣ���ѧ���༶���ң�
//������void��
//����ֵ����;

void SearchByClass(struct link *head,int n)               //�������壻
{
	int i,count=0;
	struct link *p;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
	    p=head;
    	printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
    	for(i=0;p!=NULL;i++)
		{
	     	if(p->cla==n)                                 //�ж��Ƿ�������������ϱ�����й���Ϣ��
			{
	    		PrintOneNode(p);                          //�����ڵ�����������ã�
	    		count++;
			}
	    	p=p->next;
		}
    	if(count==0)                                      //û�ҵ��������
		{
			MessageBox(NULL,"unfortunately,can't find the information!","MessageBox",MB_OK|MB_SETFOREGROUND);
		}
	}
}

//�������ܣ�����ѧ����ѧ�Ų��ң�
//������void��
//����ֵ���ޣ�

void SearchByNum(struct link *head,int n)                 //�������壻
{
	int i,count=0;
	struct link *p;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
    	p=head;
    	printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
    	for(i=0;p!=NULL;i++)
		{
	    	if(p->num==n)
			{
	    		PrintOneNode(p);                              //�����ڵ�����������ã�
		    	count++;
			}
	    	p=p->next;
		}
    	if(count==0)
		{
			MessageBox(NULL,"unfortunately,can't find the information!","MessageBox",MB_OK|MB_SETFOREGROUND);
		}
	}
}

//�������ܣ�����ѧ�����������ң�
//������void
//����ֵ����

void SearchByName(struct link *head,char a[])             //�������壻
{
	int i,count=0;
	struct link *p;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
    	p=head;
    	printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
    	for(i=0;p!=NULL;i++)
		{
	    	if(strcmp(p->name,a)==0)                      //�ж�������ַ���p->name��������ַ��Ƿ���ͬ��
			{
		    	PrintOneNode(p);                          //���һ���ڵ㺯�����ã�
		    	count++;                                  //����������������Լӣ�
			}
	    	p=p->next;
		}
    	if(count==0)                                      //count=0��û�����������Ľڵ㣻���û���ҵ�����Ϣ��
		{
			MessageBox(NULL,"unfortunately,can't find the information!","error",MB_OK|MB_SETFOREGROUND);
		}
	}
}

//�������ܣ��޸�ѧ����Ϣ��
//������void��
//����ֵ���ޣ�

void Rvise(struct link *head)                             //�������壻
{
	int i,j,n;                                            //ʵ�ζ��壻
	char *p1;
	struct link *p;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
    	printf("please input n:( 1 stand for num, 2 stand for name)");
    	scanf("%d",&n);                                       //���룻
    	switch(n)                                             //switchѡ��ṹ��
		{
    	case 1:printf("please input the student's number:");
	    	scanf("%d",&i);                                   //���룻
	    	p=SearchByNUM(head,i);                            //�������ã�
	    	if(p!=NULL)
			{
		    	printf("1:s  2:name 3:cla 4:num 5:sex 6:score1 7:score2 8:score3 9:score4 10:score5 11:revise all\n");
	        	printf("please input which one you want to revise:");
	        	scanf("%d",&j);
	        	switch(j)                                     //switchѡ��ṹѡ����Ҫ���ĵ���Ŀ��
				{
				case 1:printf("please input the semster:");
					scanf("%d",&p->semster);
					break;
	        	case 2:printf("please input the student's name:");
		        	scanf("%s",p->name);
		        	break;
	        	case 3:printf("please input the student's class:");
		        	scanf("%d",&p->cla);
		        	break;
	        	case 4:printf("please input the student's number:");
		        	scanf("%d",&p->num);
		        	break;
    		    case 5:printf("please input the student's sex:");
	    	    	scanf("%1s",&p->sex);
  		        	break;
	    	    case 6:printf("please input the student's score1:");
	    	    	scanf("%f",&p->score[0]);
		        	break;
	        	case 7:printf("please input the student's score2:");
		            scanf("%f",&p->score[1]);
		        	break;
	        	case 8:printf("please input the student's score3:");
		            scanf("%f",&p->score[2]);
	    	    	break;
	    	    case 9:printf("please input the student's score4:");
		            scanf("%f",&p->score[3]);
	    	    	break;
	         	case 10:printf("please input the student's score5:");
		            scanf("%f",&p->score[4]);
		        	break;
    	    	case 11:printf("please input the semster:");
					scanf("%d",&p->semster);
					printf("please input the student's name:");
	  	        	scanf("%s",p->name);
		        	printf("please input the student's class:");
		        	scanf("%d",&p->cla);
	    	    	printf("please input the student's number:");
	    	    	scanf("%d",&p->num);
	    	    	printf("please input the student's sex:");
	    	    	scanf("%1s",&p->sex);
		        	printf("please input the student's score1:");
		        	scanf("%f",&p->score[0]);
		        	printf("please input the student's score2:");
		            scanf("%f",&p->score[1]);
		        	printf("please input the student's score3:");
	    	        scanf("%f",&p->score[2]);
		        	printf("please input the student's score4:");
		            scanf("%f",&p->score[3]);
		        	printf("please input the student's score5:");
		            scanf("%f",&p->score[4]);
	    	    	break;
				}
		     	if(p!=NULL)                               //p!=NULL�����޸ĳɹ����������һ���ڵ㺯������޸ĵ���Ϣ��
				{
			    	Summatiom(p);                         //�����ּܷ��㺯�����޸��ֺܷ�ƽ���֣�
					MessageBox(NULL,"succesful revise the imfoematoin !","MessageBox",MB_OK|MB_SETFOREGROUND);
			    	printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
			    	PrintOneNode(p);                      //���һ���ڵ㺯�����ã�
				}
			}
			break;
    	case 2:printf("please input the student's name:");
	    	p1=malloc(sizeof(char));
	    	scanf("%s",p1);
	    	p=SearchByNAME(head,p1);                      //�������ã�
    		if(p!=NULL)
			{
		    	printf("1:s  2:name 3:cla 4:num 5:sex 6:score1 7:score2 8:score3 9:score4 10:score5 11:revise all\n");
	        	printf("please input which one you want to revise:");
	        	scanf("%d",&j);
	        	switch(j)
				{
				case 1:printf("please input the semster:");
					scanf("%d",&p->semster);
					break;
	        	case 2:printf("please input the student's name:");
		        	scanf("%s",p->name);
		        	break;
	         	case 3:printf("please input the student's class:");
		        	scanf("%d",&p->cla);
		        	break;
	        	case 4:printf("please input the student's number:");
		        	scanf("%d",&p->num);
		        	break;
    	    	case 5:printf("please input the student's sex:");
	    	    	scanf("%1s",&p->sex);
  		        	break;
	        	case 6:printf("please input the student's score1:");
	    	    	scanf("%f",&p->score[0]);
		        	break;
	        	case 7:printf("please input the student's score2:");
		            scanf("%f",&p->score[1]);
		        	break;
	        	case 8:printf("please input the student's score3:");
		            scanf("%f",&p->score[2]);
	    	     	break;
	        	case 9:printf("please input the student's score4:");
		           scanf("%f",&p->score[3]);
	    	    	break;
	    	    case 10:printf("please input the student's score5:");
		           scanf("%f",&p->score[4]);
		        	break;
    	    	case 11:printf("please input the semster:");
					scanf("%d",&p->semster);
					printf("please input the student's name:");
	  	        	scanf("%s",p->name);
		        	printf("please input the student's class:");
		        	scanf("%d",&p->cla);
	    	    	printf("please input the student's number:");
	    	    	scanf("%d",&p->num);
	    	    	printf("please input the student's sex:");
	    	    	scanf("%1s",&p->sex);
		        	printf("please input the student's score1:");
		        	scanf("%f",&p->score[0]);
		        	printf("please input the student's score2:");
		            scanf("%f",&p->score[1]);
		        	printf("please input the student's score3:");
	    	        scanf("%f",&p->score[2]);
		        	printf("please input the student's score4:");
		            scanf("%f",&p->score[3]);
		        	printf("please input the student's score5:");
		            scanf("%f",&p->score[4]);
	    	    	break;
				}
		    	if(p!=NULL)
				{
			    	Summatiom(p);
					MessageBox(NULL,"succesful revise the imfoematoin !","MessageBox",MB_OK|MB_SETFOREGROUND);
			    	printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
			    	PrintOneNode(p);
				}
			}
			break;
		}
	}
}

//�������ܣ����������ң��޸���Ϣʱ�ã���
//����:struct link *;
//����ֵ��p;

struct link *SearchByNAME(struct link *head,char a[])     //�������壻
{
	int i;
	struct link *p;
	if(head==NULL)                                        //head=NULL����û��������Ϣ��
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND); //���������Ϣ��
	}
	else
	{
		p=head;
    	for(i=0;p!=NULL;i++)
		{
	    	if(strcmp(p->name,a)==0)                          //�ҵ�����������ص�ַp,�������ߵ���Ϣ��
			{
	    		printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
	    		PrintOneNode(p);
	      		break;
			}
			p=p->next;
		}
	}
	return p;
}

//�������ܣ���ѧ�Ų��ң��޸���Ϣʱ�ã���
//������struct link *;
//����ֵ��p;

struct link *SearchByNUM(struct link *head,int n)         //�������壻
{
	int i;
	struct link *p;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
    	p=head;
    	for(i=0;p!=NULL;i++)
		{
	    	if(p->num==n)
			{
	     		printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
		    	PrintOneNode(p);//PrintOneNode�������ã�
		    	break;
			}
			p=p->next;
		}
	}
	return p;
}

//�������ܣ���sum �� aver(���޸���Ϣʱ��)��
//������void;
//����ֵ���ޣ�

void Summatiom(struct link *p)                            //�������壻
{
	int i;                                                //ʵ�ζ��壻
	float sum=0,aver;
	for(i=0;i<5;i++)                                      //��forѭ����ͣ�
	{
		sum=sum+p->score[i];
	}
	aver=sum/5;                                           //��ƽ���֣�
	p->sum=sum;                                           //д�����ݣ�
	p->aver=aver;
}

//�������ܣ��ͷ�������ռ�õ��ڴ棻
//������void;
//����ֵ���ޣ�

void Release(struct link *head)                           //�������壻
{
	int i;
	struct link *p;
	struct link *pr;
	p=head;
	for(i=0;p!=NULL;i++)
	{
		pr=p->next;
		free(p);                                          //�ͷ��ڴ棻
		p=pr;
	}
}

//�������ܣ����հ༶����������
//������struct link*;
//����ֵ��head;

void SortByClass1(struct link *head)                      //�������壻
{
	int count,i;
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND); 
	}
	else
	{
		for(p=head,count=0;p!=NULL;)
		{
	    	count++;
	    	p=p->next;
		}
    	for(p=head;p!=NULL;)
		{
    		for(i=0,pr=head;i<count-1;i++)
			{
	    		if(pr->cla>(pr->next)->cla)
				{
	    			pr1=pr->next;
		    		SwapCla(pr,pr1);                          //����swap�����������ݣ�
					SwapSemster(pr,pr1);
		    		SwapName(pr,pr1);
		    		SwapNum(pr,pr1);
		    		SwapScore(pr,pr1);
		      		SwapSex(pr,pr1);
		    		SwapSum(pr,pr1);
		    		SwapAver(pr,pr1);
				}
		    	pr=pr->next;
			}
	    	count--;
	    	p=p->next;
		}
		MessageBox(NULL,"successfully to sort!","MessagBox",MB_OK|MB_SETFOREGROUND);
	}
}

//�������ܣ����༶��������
//������void;
//����ֵ���ޣ�

void SortByClass2(struct link *head)                      //�������壻
{
	int count=0,i;                                        //����ʵ�Σ�
	struct link *p;
	struct link *pr;
	struct link *pr1;
    if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		for(p=head,count=0;p!=NULL;)                      //��������Ľڵ�����
		{
	    	count++;
	    	p=p->next;
		}
    	for(p=head;p!=NULL;)                              //����ð�ݷ�����
		{
    		for(i=0,pr=head;i<count-1;i++)
			{
	    		if(pr->cla<(pr->next)->cla)               //�ж�������
				{
	    			pr1=pr->next;
					SwapSemster(pr,pr1);
		    		SwapCla(pr,pr1);                      //����swap�����������ݣ�
		    		SwapName(pr,pr1);
		    		SwapNum(pr,pr1);
		    		SwapScore(pr,pr1);
		      		SwapSex(pr,pr1);
		    		SwapSum(pr,pr1);
		    		SwapAver(pr,pr1);
				}
		    	pr=pr->next;
			}
	    	count--;
	    	p=p->next;
		}
		MessageBox(NULL,"successfully to sort!","MessagBox",MB_OK|MB_SETFOREGROUND);
	}
}

//�������ܣ�����semster���ݣ�
//������void;
//����ֵ����;

void SwapSemster(struct link *p0,struct link *p1)         //�������壻
{
	int temp;
	temp=p0->semster;
	p0->semster=p1->semster;
	p1->semster=temp;
}

//�������ܣ�����class���ݣ�
//������void;
//����ֵ���ޣ�

void SwapCla(struct link *p0,struct link *p1)             //�������壻
{
	int temp;
	temp=p0->cla;
	p0->cla=p1->cla;
	p1->cla=temp;
}

//�������ܣ�����NAME���ݣ�
//������void��
//����ֵ���ޣ�

void SwapName(struct link *p0,struct link *p1)            //�������壻
{
	char *temp;
	temp=malloc(sizeof(char));
	strcpy(temp,p0->name);                                //�������ݣ�
	strcpy(p0->name,p1->name);
	strcpy(p1->name,temp);
}

//�������ܣ�����num���ݣ�
//������void;
//����ֵ���ޣ�

void SwapNum(struct link *p0,struct link *p1)             //�������壻
{
	int temp;
	temp=p0->num;
	p0->num=p1->num;
	p1->num=temp;
}

//�������ܣ�����sex���ݣ�
//������void��
//����ֵ���ޣ�

void SwapSex(struct link *p0,struct link *p1)             //�������壻
{
	char c;
	c=p0->sex;
	p0->sex=p1->sex;
	p1->sex=c;
}

//�������ܣ�����score���ݣ�
//������void��
//����ֵ���ޣ�

void SwapScore(struct link *p0,struct link *p1)           //�������壻
{
	int i;
	float temp;
	for(i=0;i<5;i++)
	{
		temp=p0->score[i];
		p0->score[i]=p1->score[i];
		p1->score[i]=temp;
	}
}

//�������ܣ�����sum���ݣ�
//������void��
//����ֵ���ޣ�

void SwapSum(struct link *p0,struct link *p1)             //�������壻
{
	float temp;
	temp=p0->sum;
	p0->sum=p1->sum;
	p1->sum=temp;
}

//�������ܣ�����aver���ݣ�
//������void��
//����ֵ���ޣ�

void SwapAver(struct link *p0,struct link *p1)            //�������壻
{
	float temp;
	temp=p0->aver;
	p0->aver=p1->aver;
	p1->aver=temp;
}

//��������:������ǰŮ��˳������
//������void ;
//����ֵ���ޣ�

void SortBySex1(struct link *head)                        //�������壻
{
	int i,count=0;                                        //����ʵ�Σ�
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		p=head;
		for(;p!=NULL;)
		{
			count++;
			p=p->next;
		}
		for(p=head;p!=NULL;)
		{
			for(i=0,pr=head;i<count-1;i++)
			{
				if((pr->sex=='f' || pr->sex=='F') && ((pr->next)->sex=='m' || (pr->next)->sex=='M'))
				{
					pr1=pr->next;
					SwapCla(pr,pr1);                          //����swap�����������ݣ�
					SwapSemster(pr,pr1);
				    SwapName(pr,pr1);
				    SwapNum(pr,pr1);
			    	SwapScore(pr,pr1);
			    	SwapSex(pr,pr1);
			    	SwapSum(pr,pr1);
			    	SwapAver(pr,pr1);
				}
				pr=pr->next;
			}
			count--;
			p=p->next;
		}
		MessageBox(NULL,"successfully to sort!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}
}

//�������ܣ������Ա�����
//������void��
//����ֵ���ޣ�

void SortBySex2(struct link *head)                        //�������壻
{
	int i,count=0;                                        //����ʵ�Σ�
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		p=head;
		for(;p!=NULL;)
		{
			count++;
			p=p->next;
		}
		for(p=head;p!=NULL;)
		{
			for(i=0,pr=head;i<count-1;i++)
			{
				if((pr->sex=='m' || pr->sex=='M') && ((pr->next)->sex=='f' || (pr->next)->sex=='F'))  //�жϣ�
				{
					pr1=pr->next;
					SwapCla(pr,pr1);                          //����swap�����������ݣ�
					SwapSemster(pr,pr1);
				    SwapName(pr,pr1);
				    SwapNum(pr,pr1);
			    	SwapScore(pr,pr1);
			    	SwapSex(pr,pr1);
			    	SwapSum(pr,pr1);
			    	SwapAver(pr,pr1);
				}
				pr=pr->next;
			}
			count--;
			p=p->next;
		}
		MessageBox(NULL,"successfully to sort!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}
}

//�������ܣ�����ѧ�ŵ���������
//������void;
//����ֵ���ޣ�

void SortByNum1(struct link *head)                        //�������壻
{
	int i,count=0;
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		p=head;
		for(;p!=NULL;)
		{
			count++;
			p=p->next;
		}
		for(p=head;p!=NULL;)
		{
			for(pr=head,i=0;i<count-1;i++)
			{
				if(pr->num>(pr->next)->num)
				{
					pr1=pr->next;
					SwapCla(pr,pr1);                          //����swap�����������ݣ�
					SwapSemster(pr,pr1);
				    SwapName(pr,pr1);
				    SwapNum(pr,pr1);
			    	SwapScore(pr,pr1);
			    	SwapSex(pr,pr1);
			    	SwapSum(pr,pr1);
			    	SwapAver(pr,pr1);
				}
				pr=pr->next;
			}
			count--;
			p=p->next;
		}
		MessageBox(NULL,"successfully to sort!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}
}             

//�������ܣ�����ѧ�ŵĽ�������
//������void��
//����ֵ���ޣ�

void SortByNum2(struct link *head)                        //�������壻
{
	int i,count=0;
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		p=head;
		for(;p!=NULL;)
		{
			count++;
			p=p->next;
		}
		for(p=head;p!=NULL;)
		{
			for(pr=head,i=0;i<count-1;i++)
			{
				if(pr->num<(pr->next)->num)
				{
					pr1=pr->next;
					SwapCla(pr,pr1);                          //����swap�����������ݣ�
					SwapSemster(pr,pr1);
				    SwapName(pr,pr1);
				    SwapNum(pr,pr1);
			    	SwapScore(pr,pr1);
			    	SwapSex(pr,pr1);
			    	SwapSum(pr,pr1);
			    	SwapAver(pr,pr1);
				}
				pr=pr->next;
			}
			count--;
			p=p->next;
		}
		MessageBox(NULL,"successfully to sort!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}
}

//�������ܣ������ܷ���������
//������void;
//����ֵ���ޣ�

void SortBySum1(struct link *head)                        //�������壻
{
	int i,count=0;
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		p=head;
		for(;p!=NULL;)
		{
			count++;
			p=p->next;
		}
		for(p=head;p!=NULL;)
		{
			for(pr=head,i=0;i<count-1;i++)
			{
				if((pr->sum)>((pr->next)->sum))
				{
					pr1=pr->next;
					SwapCla(pr,pr1);                          //����swap�����������ݣ�
					SwapSemster(pr,pr1);
				    SwapName(pr,pr1);
				    SwapNum(pr,pr1);
			    	SwapScore(pr,pr1);
			    	SwapSex(pr,pr1);
			    	SwapSum(pr,pr1);
			    	SwapAver(pr,pr1);
				}
				pr=pr->next;
			}
			count--;
			p=p->next;
		}
		MessageBox(NULL,"successfully to sort!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}
}

//�������ܣ������ֽܷ�������
//������void;
//����ֵ���ޣ�

void SortBySum2(struct link *head)                        //�������壻
{
	int i,count=0;
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		p=head;
		for(;p!=NULL;)
		{
			count++;
			p=p->next;
		}
		for(p=head;p!=NULL;)
		{
			for(pr=head,i=0;i<count-1;i++)
			{
				if((pr->sum)<((pr->next)->sum))
				{
					pr1=pr->next;
					SwapCla(pr,pr1);                          //����swap�����������ݣ�
					SwapSemster(pr,pr1);
				    SwapName(pr,pr1);
				    SwapNum(pr,pr1);
			    	SwapScore(pr,pr1);
			    	SwapSex(pr,pr1);
			    	SwapSum(pr,pr1);
			    	SwapAver(pr,pr1);
				}
				pr=pr->next;
			}
			count--;
			p=p->next;
		}
		MessageBox(NULL,"successfully to sort!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}
}

//�������ܣ�����ƽ������������
//������void��
//����ֵ���ޣ�

void SortByAver1(struct link *head)                       //�������壻
{
		int i,count=0;
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		p=head;
		for(;p!=NULL;)
		{
			count++;
			p=p->next;
		}
		for(p=head;p!=NULL;)
		{
			for(pr=head,i=0;i<count-1;i++)
			{
				if((pr->aver)>(pr->next)->aver)
				{
					pr1=pr->next;
					SwapCla(pr,pr1);                          //����swap�����������ݣ�
					SwapSemster(pr,pr1);
				    SwapName(pr,pr1);
				    SwapNum(pr,pr1);
			    	SwapScore(pr,pr1);
			    	SwapSex(pr,pr1);
			    	SwapSum(pr,pr1);
			    	SwapAver(pr,pr1);
				}
				pr=pr->next;
			}
			count--;
			p=p->next;
		}
		MessageBox(NULL,"successfully to sort!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}
}

//�������ܣ�����ƽ���ֽ�������
//������void��
//����ֵ���ޣ�


void SortByAver2(struct link *head)                       //�������壻
{
		int i,count=0;
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		p=head;
		for(;p!=NULL;)
		{
			count++;
			p=p->next;
		}
		for(p=head;p!=NULL;)
		{
			for(pr=head,i=0;i<count-1;i++)
			{
				if(pr->aver<(pr->next)->aver)
				{
					pr1=pr->next;
					SwapCla(pr,pr1);                          //����swap�����������ݣ�
					SwapSemster(pr,pr1);
				    SwapName(pr,pr1);
				    SwapNum(pr,pr1);
			    	SwapScore(pr,pr1);
			    	SwapSex(pr,pr1);
			    	SwapSum(pr,pr1);
			    	SwapAver(pr,pr1);
				}
				pr=pr->next;
			}
			count--;
			p=p->next;
		}
		MessageBox(NULL,"successfully to sort!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}
}

//�������ܣ����ļ���ȡ���ݵ��ڴ棻
//����:struct link*��
//����ֵ���ޣ�

struct link *ReadFromFile(struct link *head)              //�������壻
{
	int i,n=0,j=1;                                        //ʵ�ζ��壻
	struct link *p;
	struct link *pr=NULL;
	struct link *pr1=head;
	FILE *fp;                                             //�����ļ�ָ�룻
	char filename[30];
	printf("please input the filename(inclede route):");
	scanf("%s",filename);
	printf("now, read sourse from file!\n");
	if((fp=fopen(filename,"r"))==NULL)                    //�����ܴ��ļ������������Ϣ���˳�����
	{
		MessageBox(NULL,"can't open the file!","error",MB_OK|MB_SETFOREGROUND);
		exit(0);
	}
	else
	{
		if(head!=NULL)                                    //��ĩβ���׵�ַ��ֵ��ָ��pr;
		{
			for(;pr1->next!=NULL;)
			{
		    	pr1=pr1->next;
			}
	    	pr=pr1;
		}
		for(;fgetc(fp)!=EOF;)
		{
			p=(struct link *)malloc(sizeof(struct link)); //�����ڴ棬���ļ���ȡ���ݵ��ڴ棻
			fscanf(fp,"%3d",&p->semster);
			while(fgetc(fp)==(int)NULL)
				getchar();
			fscanf(fp,"%2c",&p->sex);
			fscanf(fp,"%5d",&p->num);
			fscanf(fp,"%5d",&p->cla);
			fscanf(fp,"%6s",p->name);
			for(i=0;i<5;i++)
			{
				fscanf(fp,"%10f",&p->score[i]);
			}
			fscanf(fp,"%12f",&p->sum);
			fscanf(fp,"%10f",&p->aver);
			p->next=NULL;
			if(head==NULL)                                //�ڴ���û�����ݣ�ֱ�ӽ��ļ������ڴ棻
			{
				head=p;
				pr=p;
			}
			else                                          //���ڴ��������ݣ����ļ����ݶ����ڴ��������ݺ�
			{
				pr->next=p;
				pr=p;
			}
			n++;                                          //��¼��ȡ�˶������ݣ��ڵ㣩��
		}
		printf("%d node(s) have been readed!\n",n);
	}
	fclose(fp);                                           //�ر��ļ���
	return head;                                          //���������׵�ַ��
}

//�������ܣ������ݱ��浽�ļ���
//������void;
//����ֵ���ޣ�

void SaveFile(struct link *head)                          //�������壻
{
	int i,j;
	char filename[30];
	struct link*p;
	FILE *fp;                                             //�����ļ�ָ�룻
	if(head==NULL)                                        //��û��������Ϣ�����������Ϣ��
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		printf("please input the filename(include route):\n");//������Ҫ����Ϣ���浽�ļ����ļ����ƣ�

		scanf("%s",filename);


		if((fp=fopen(filename,"w+"))==NULL)               //�����ܴ򿪴��ļ������������Ϣ��
		{
			MessageBox(NULL,"can't open the file!","error",MB_OK|MB_SETFOREGROUND);
			exit(0);
		}
		else
		{
			for(j=0,p=head;p!=NULL;)                      //������д�뵽�ļ���
			{
				fprintf(fp,"%3d",p->semster);
				fprintf(fp,"%2c",p->sex);
			    fprintf(fp,"%5d",p->num);
		       	fprintf(fp,"%5d",p->cla);
		    	fprintf(fp,"%6s",p->name);
				fprintf(fp,"%c",' ');
	     		for(i=0;i<5;i++)
				{
	    			fprintf(fp,"%10f",p->score[i]);
				}
		    	fprintf(fp,"%12f",p->sum);
				fprintf(fp,"%10f",p->aver);
				j++;
				p=p->next;
			}
			printf("%d node have been saved to %s\n",j,filename);
			fclose(fp);
		}
	}
}

//�������ܣ�ɾ��һ���ض��Ľڵ�
//���� struct link *
//����ֵ ��head��

struct link *Delete1(struct link *head)                   //�������壻
{
	int i,n,c;                                            //ʵ�ζ��壻
	char a[20];
	struct link * p;
	struct link * pr;
	printf("now find a imformation and delete it!");
dian1:	printf("1 stand for search by name,2 stand for search by num,press 0 to exit delete!\n");
	printf("please input your choose:");
	scanf("%d",&i);                                       //������Ҫѡ��Ĺ��ܣ�
	switch(i)
	{
	case 0:break;
	case 1:printf("please input the student's name:");
		scanf("%s",a);
		n=SearchBYName(head,a);                           //�������ã�
		if(n==-1)
		{
	   	    c=MessageBox(NULL,"sure to delete?","MessageBox",MB_OKCANCEL|MB_SETFOREGROUND);
			if(c==1)                                      //ɾ������ͷ������head->next��Ϊͷ����
			{
				p=head;
				head=p->next;
				free(p);
				MessageBox(NULL,"successfully to delete the imformation!","Messagebox",MB_OK|MB_SETFOREGROUND);
			}
		}			
		else
		{
			p=head;
			for(i=0;i<n && p!=NULL;i++)                     //ָ��������Ѱ�ҵĽڵ��ǰһ���ڵ㣻
			{
			   	p=p->next;
			}
			if(p->next==NULL)                             //��û����һ���ڵ㣬�򲻴��ڸ���Ϣ�����������Ϣ��
			{
				MessageBox(NULL,"can't find the student's imformation!can't use this function!","Messagebox",MB_OK|MB_SETFOREGROUND);
			}
			if(p->next!=NULL)                             //���ڸ���Ϣ��
			{
				c=MessageBox(NULL,"sure to delete?","MessageBox",MB_OKCANCEL|MB_SETFOREGROUND);
		    	if(c==1)                                  //���˽ڵ�ɾ����
				{
			    	pr=p->next;
			       	p->next=pr->next;
		        	free(pr);
		        	MessageBox(NULL,"successfully to delete the imformation!","Messagebox",MB_OK|MB_SETFOREGROUND);
				}
			}
		}
		break;
	case 2:printf("please input the student's num:");
		scanf("%d",&i);
		n=SearchBYNum(head,i);                            //�������ã�
		if(n==-1)
		{
	   	    c=MessageBox(NULL,"sure to delete?","MessageBox",MB_OKCANCEL|MB_SETFOREGROUND);
		    if(c==1)
			{
				p=head;
				head=p->next;
				free(p);
				MessageBox(NULL,"successfully to delete the imformation!","Messagebox",MB_OK|MB_SETFOREGROUND);
			}
		}			
		else
		{
			p=head;
			for(i=0;i<n && p!=NULL;i++)
			{
			   	p=p->next;
			}
			if(p->next==NULL)
			{
				MessageBox(NULL,"can't find the student's imformation!can't use this function!","error",MB_OK|MB_SETFOREGROUND);
			}
			if(p->next!=NULL)
			{
				c=MessageBox(NULL,"sure to delete?","MessageBox",MB_OKCANCEL|MB_SETFOREGROUND);
		    	if(c==1)   
				{
			    	pr=p->next;
			       	p->next=pr->next;
		        	free(pr);
		        	MessageBox(NULL,"successfully to delete the imformation!","Messagebox",MB_OK|MB_SETFOREGROUND);	
				}
			}
		}
			break;
		default :MessageBox(NULL,"you input a wrong choose!please input again!","error",MB_OK|MB_SETFOREGROUND);         //�����������dina1�������루�������е�dian1����
		goto dian1;
	}
	return head;
}

//�������ܣ����������ң�
//����:int
//����ֵ��n-1

int SearchBYName(struct link *head,char a[])              //�������壻
{
	struct link *p=NULL;
	int n=0;
	if(head!=NULL)
	{
		for(p=head;p!=NULL;)
		{
    		if(strcmp(p->name,a)==0)
	    		break;
			n++;
	    	p=p->next;
		}
    }
	return n-1;
}

//�������ܣ���ѧ�Ų��ң�
//������int
//����ֵ��m-1

int SearchBYNum(struct link *head,int n)                  //�������壻
{
	struct link *p=NULL;
	int m=0;
	if(head!=NULL)
	{
		for(p=head;p!=NULL;)
		{
	    	if(p->num==n)
	     		break;
			m++;
	    	p=p->next;
		}
	}
	return m-1;
}

//�������ܣ����û������������Ӧλ�ò���ڵ㣻
//������struct link *��
//����ֵ��head;

struct link *SearchAndInsert(struct link *head)           //�������壻
{
	struct link*p;                                        //ʵ�ζ��壻
	struct link*pr;
	struct link*pr2;
	int n,i,m,j;
	char a[20];
	int k;
	printf("now,begin to find and insert!\n");
dian3:printf("1 stand for search by name,2 stand for search by num,press 0 to exit this function!\n");
	printf("please input your choose:");
	scanf("%d",&i);
	switch(i)
	{
	case 0:break;
	case 1:printf("please input the student's name:");
		scanf("%s",a);
		m=SearchBYName(head,a);                           //�������ã�
		for(j=0,p=head;j<m && p!=NULL;j++)                //����ָ���ڵ�ǰһ���ڵ㣨����ָ���ڵ���ͷ���⣩��
		{
			p=p->next;
		}
		if(m==-1)                                         //ָ���ڵ�Ϊͷ����������ýڵ���Ϣ��
		{
			printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
			PrintOneNode(head);                           //���һ���ڵ㺯�����ã�
		}
		else
		{
			if((p->next)!=NULL)                           //���ָ���ڵ���Ϣ��
			{
		    	printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
		    	PrintOneNode(p->next);                    //���һ���ڵ㺯�����ã�
			}
		}
		if((p->next)==NULL && m!=-1)                      //û�иýڵ���Ϣ�����������Ϣ��
		{
			MessageBox(NULL,"not find the student's imformation,can't use this function!","error",MB_OK|MB_SETFOREGROUND);
		}
		else
		{
dian1:printf("you want to insert this node in at the student's head or back(1 stand head,2 stand back)");
			scanf("%d",&n);
			if(n!=1 && n!=2)
			{
				MessageBox(NULL,"you input a wrong number!please input again!","error",MB_OK|MB_SETFOREGROUND);
				goto dian1;                               //������󣬺�������������dian1����
			}
			if(n==1)
			{
				if(m==-1)                                 //ѡ���һ��ܣ�����ָ���ڵ�Ϊͷ����
				{
					pr=CreatNode();                       //����ڵ��ڴ�ռ䣬������Ϣ���뵽ͷ��ǰ�������˽ڵ���Ϊͷ����
					pr->next=head;
					head=pr;
					MessageBox(NULL,"successfully to insert!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
				else                                      //ָ���ڵ㲻��ͷ����������ڵ���뵽ָ��ǰ��
				{
					pr2=CreatNode();                      //�����ڵ㺯�����ã�
			     	pr=p->next;
			    	p->next=pr2;
			    	pr2->next=pr;
					MessageBox(NULL,"successfully to insert!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
			}
			else
			{
				if(m==-1)                                 //���ڵ���뵽ָ���ڵ��
				{
					pr=CreatNode();                       //�����ڵ㺯�����ã�
					p=head->next;
					head->next=pr;
					pr->next=p;
					MessageBox(NULL,"successfully to insert!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
				else                                      //���ڵ���뵽ָ���ڵ��
				{
					pr2=CreatNode();                      //�����ڵ㺯�����ã�
			    	pr=p->next;
			    	p=pr->next;
		    		pr->next=pr2;
			    	pr2->next=p;
					MessageBox(NULL,"successfully to insert!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
			}
		}
		break;
	case 2:printf("please input the student's num:");
		scanf("%d",&k);
		m=SearchBYNum(head,k);
		for(j=0,p=head;j<m && p!=NULL;j++)
		{
			p=p->next;
		}
		if(m==-1)
		{
			printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
			PrintOneNode(head);
		}
		else
		{
			if((p->next)!=NULL)
			{
		    	printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
		    	PrintOneNode(p->next);
			}
		}
		if((p->next)==NULL && m!=-1)
		{
			MessageBox(NULL,"not find the student's imformation,can't use this function","MessageBox",MB_OK|MB_SETFOREGROUND);
		}
		else
		{
dian2:printf("you want to insert this node in at the student's head or back(1 stand head,2 stand back)");
			scanf("%d",&n);
			if(n!=1 && n!=2)
			{
				MessageBox(NULL,"you input a wrong number!please input again!","error",MB_OK|MB_SETFOREGROUND);
				goto dian2;
			}
			if(n==1)
			{
				if(m==-1)
				{
					pr=CreatNode();
					pr->next=head;
					head=pr;
					MessageBox(NULL,"successfully to insert!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
				else
				{
					pr2=CreatNode();
			     	pr=p->next;
			    	p->next=pr2;
			    	pr2->next=pr;
					MessageBox(NULL,"successfully to insert!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
			}
			else
			{
				if(m==-1)
				{
					pr=CreatNode();
					p=head->next;
					head->next=pr;
					pr->next=p;
					MessageBox(NULL,"successfully to insert!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
				else
				{
					pr2=CreatNode();
			    	pr=p->next;
			    	p=pr->next;
		    		pr->next=pr2;
			    	pr2->next=p;
					MessageBox(NULL,"successfully to insert!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
			}
		}
			break;
	default :MessageBox(NULL,"you input a wrong number!please input again!","error",MB_OK|MB_SETFOREGROUND);   //�������������������dian3����
		goto dian3;
	}
	return head;                                          //����ͷ����ַ��
}

/*
//�������ܣ�����ָ����ߵ����ݣ�
//�������ͣ�void;
//����ֵ���ޣ�

void Swap(struct link *p0,struct link *p1)                //����ָ��佻�����ݣ��������壻
{
    int a,i;                                              //ʵ�ζ��壻
    float b;
    char n[20],c;
    a=p0->num;                                            //����ѧ�����ݣ�
    p0->num=p1->num;
    p1->num=a;
    a=p0->cla;                                            //�����༶���ݣ�
    p0->cla=p1->cla;
    p1->cla=a;
	c=p0->sex;                                            //�����Ա���Ϣ��
    p0->sex=p1->sex;
    p1->sex=c;
    strcmp(n,p0->name);                                   //�����������ݣ�
    strcmp(p0->name,p1->name);
	strcmp(p1->name,n);
    for(i=0;i<5;i++)                                      //�����������ݣ�
	{
		b=p0->score[i];
		p0->score[i]=p1->score[i];
		p1->score[i]=b;
	}
	b=p0->sum;                                            //�����ܷ����ݣ�
	p0->sum=p1->sum;
	p1->sum=b;
	b=p0->aver;                                           //����ƽ�������ݣ�
	p0->aver=p1->aver;
	p1->aver=b;

}
*/

//�������ܣ����������Ŀ���в��Ҳ������ѧ��
//������void
//����ֵ���ޣ�

void SearchByGrade(struct link *head)                     //�������壻
{
	struct link *p=head;
	int i,n=0;
	float m;
dian0:printf("1:score1 2:score2 3:score3 4:score4 5:score5\n");
	printf("please input your choose:");
	scanf("%d",&i);
	if(i<1 || i>5)
	{
		MessageBox(NULL,"you input  a wrong number!please input again!","MessageBox",MB_OK|MB_SETFOREGROUND);  //��ʾ���ڣ�
		goto dian0;                                       //�����������dain0����
	}
	printf("please input low grades:");
	scanf("%f",&m);
	printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
	switch(i)
	{
	case 1:for(;p!=NULL;p=p->next)
		   {
			   p=SearchByG1(p,m);                         //SearchByG1�������ã�
			   if(p==NULL)
				   goto END;
			   PrintOneNode(p);                           //PrintOneNode�������ã�
			   n++;
		   }
		break;
	case 2:for(;p!=NULL;p=p->next)
		   {
			   p=SearchByG2(p,m);                         //SearchByG2�������ã�
			   if(p==NULL)
				   goto END;
			   PrintOneNode(p);                           //PrintOneNode�������ã�
			   n++;
		   }
		break;
	case 3:for(;p!=NULL;p=p->next)
		   {
			   p=SearchByG3(p,m);                         //SearchByG3�������ã�
			   if(p==NULL)
				   goto END;
			   PrintOneNode(p);                           //PrintOneNode�������ã�
			   n++;
		   }
		break;
	case 4:for(;p!=NULL;p=p->next)
		   {
			   p=SearchByG4(p,m);                         //SearchByG4�������ã�
			   if(p==NULL)
				   goto END;
			   PrintOneNode(p);                           //PrintOneNode�������ã�
			   n++;
		   }
		break;
	case 5:for(;p!=NULL;p=p->next)
		   {
			   p=SearchByG5(p,m);                         //SearchByG5�������ã�
			   if(p==NULL)
				   goto END;
			   PrintOneNode(p);                           //PrintOneNode�������ã�
			   n++;
		   }
END:printf("Search subject 5,low grade student(s) are %d person(s) in all!\n",n);
	break;
	default:
		break;
	}
}

//�������ܣ����Ҳ��������
//������struct link *
//����ֵ��p;
struct link *SearchByG1(struct link *p,float n)           //�������壻
{
	for(;p!=NULL;p=p->next)
	{
		if(p->score[0]<n)
			break;
	}
	return p;
}

//�������ܣ����Ҳ��������
//������struct link *
//����ֵ��p;
struct link *SearchByG2(struct link *p,float n)           //�������壻
{
	for(;p!=NULL;p=p->next)
	{
		if(p->score[1]<n)
			break;
	}
	return p;
}

//�������ܣ����Ҳ��������
//������struct link *
//����ֵ��p;
struct link *SearchByG3(struct link *p,float n)           //�������壻
{
	for(;p!=NULL;p=p->next)
	{
		if(p->score[2]<n)
			break;
	}
	return p;
}

//�������ܣ����Ҳ��������
//������struct link *
//����ֵ��p;
struct link *SearchByG4(struct link *p,float n)           //�������壻
{
	for(;p!=NULL;p=p->next)
	{
		if(p->score[3]<n)
			break;
	}
	return p;
}

//�������ܣ����Ҳ��������
//������struct link *
//����ֵ��p;
struct link *SearchByG5(struct link *p,float n)           //�������壻
{
	for(;p!=NULL;p=p->next)
	{
		if(p->score[4]<n)
			break;
	}
	return p;
}

//�������ܣ�����ѧ�ڲ��ң�
//������void;
//����ֵ���ޣ�

void SearchBySemster(struct link *head,int n)             //�������壻
{
	struct link *p=head;
	int i=0;
	for(;p!=NULL;p=p->next)
	{
		if((p->semster)==n)
		{
			if(i==0)
			{
			    printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
			}
			PrintOneNode(p);                              //PrintOneNode�������ã�
			i++;
		}
	}
	if(i==0)
	{
		MessageBox(NULL,"Unfortunately,can't find the imformation!please input again!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}

}
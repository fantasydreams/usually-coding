#pragma comment(lib,"user32")
#include<windows.h>          //window文件
#include<conio.h>
#include<stdio.h>            //预处理；
#include<stdlib.h>           //申请内存所需；
#include<string.h>           //处理字符；

//函数声明：
int Menu();                                      //菜单；
int SearchBYName(struct link *head,char a[]);    //按姓名查找（删除节点时用）；
int SearchBYNum(struct link *head,int n);        //按学号查找（删除节点时用）；
struct link *CreatNode();                        //创建新节点；
struct link *CreatLink(struct link *head);       //创建链表；
struct link *Insert(struct link *head,int n);    //插入节点；
struct link *Delete(struct link *head,int n);    //删除节点；
struct link *SearchByNAME(struct link *head,char a[]); //按姓名查找（修改信息）；     
struct link *SearchByNUM(struct link *head,int n);     //按学号查找（修改信息）；
struct link *SearchAndInsert(struct link *head); //查找相应信息并在相应位置插入节点；
struct link *ReadFromFile(struct link *head);    //从文件读取数据到内存；
struct link * Delete1(struct link *head);        //删除一个特定的节点；
void SearchByName(struct link *head,char a[]);   //按姓名查找；
void Rvise(struct link *head);                   //修改学生信息；
void SearchByNum(struct link *head,int n);       //按学生学号查找；
void PrintOneNode(struct link *p);               //输出单个节点；
void SearchByClass(struct link *head,int n);     //按班级查找；
void PrintAll(struct link *head);                //输出全部链表；
void Input(struct link *p);                      //输入；
void Summatiom(struct link *p);                  //求和求平均分（修改信息）；
void Release(struct link *head);                 //释放内存；
void SortByClass1(struct link *head);            //按照班级的升序排序；
void SortByClass2(struct link *head);            //按照班级的降序排序；
void SortBySex1(struct link *head);              //按照性别排序
void SortBySex2(struct link *head);
void SortByNum1(struct link *head);              //按照学号的升序排序；
void SortByNum2(struct link *head);              //按照学号的降序排序；
void SortBySum1(struct link *head);              //按照总分升序排序；
void SortBySum2(struct link *head);              //按照总分降序排序；
void SortByAver1(struct link *head);             //按照平均分升序排序；
void SortByAver2(struct link *head);             //按照平均分降序排序；
void SwapSemster(struct link *p0,struct link *p1);//交换semster数据；
void SwapCla(struct link *p0,struct link *p1);   //交换cla数据；
void SwapName(struct link *p0,struct link *p1);  //交换name数据；
void SwapNum(struct link *p0,struct link *p1);   //交换num数据；
void SwapSex(struct link *p0,struct link *p1);   //交换Sex数据；
void SwapScore(struct link *p0,struct link *p1); //交换score数据；
void SwapSum(struct link *p0,struct link *p1);   //交换sum数据；
void SwapAver(struct link *p0,struct link *p1);  //交换aver数据;
void SaveFile(struct link *head);                //将数据保存到文件；
void SearchByGrade(struct link *head);           //通过成绩查找不及格的学生；
struct link *SearchByG1(struct link *p,float n); //根据成绩一查找不及格的学生；
struct link *SearchByG2(struct link *p,float n); //根据成绩二查找不及格的学生；
struct link *SearchByG3(struct link *p,float n); //根据成绩三查找不及格的学生；
struct link *SearchByG4(struct link *p,float n); //根据成绩四查找不及格的学生；
struct link *SearchByG5(struct link *p,float n); //根据成绩五查找不及格的学生；
void SearchBySemster(struct link *head,int n);         //根据学期查找；

/*
void Swap(struct link *p0,struct link *p1);      //交换数据；
*/

//自定义函数类型：
struct link
{
	int semster;            //定义学期；
	int cla;                //定义学生班级；
	int num;                //定义学号；
	char name[20];          //定义学生姓名；
	char sex;               //定义学生性别；
	float score[5];         //定义成绩；
	float sum;              //定义总分；
	float aver;             //定义平均分；
	struct link * next;     //定义链表指向下一个节点；
};

//主函数：
void main()
{
	int n,i,c;                                            //实参定义；
	char *p1;
	struct link *head=NULL;                               //申请头部并赋值为空；
    while(1)
	{
dian0:n=Menu();                                           //函数调用；
dian1:switch(n)                                           //选择结构；
		{
		case 1:head=CreatLink(head);                      //创建链表函数调用；
			break;
		case 2:printf("please input where you want to insert?");
			scanf("%d",&i);                               //输入；
		 	head=Insert(head,i);                          //插入函数调用；
			break;
		case 3:
			printf("please input which node you want to delete?");
			scanf("%d",&i);                               //输入；
			head=Delete(head,i);                          //删除函数调用；
			break;
		case 4:printf("please input which class you want to search?");
			scanf("%d",&i);                               //输入；
			SearchByClass(head,i);                        //按班级查找函数调用；
			break;
		case 5:printf("please input the number you want to search:");
			scanf("%d",&i);                               //输入；
			SearchByNum(head,i);                          //按学号查找函数调用；
			break;
		case 6:printf("please input the student's name:");
			p1=malloc(sizeof(char));
			scanf("%s",p1);                               //输入；
			SearchByName(head,p1);                        //按姓名查找函数调用；
			break;
		case 7:Rvise(head);                               //修改信息函数调用；
			break;
		case 8:printf(" 1 stand for sequence, 2 stand for grade down:");
dian2:scanf("%d",&i);
			switch(i)
			{
			case 1:SortByClass1(head);                    //按班级排序升序函数调用；
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
			case 1:SortBySex1(head);                      //调用性别排序函数；
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
			case 1:SortByNum1(head);                      //学号排序函数调用；
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
			case 1:SortByAver1(head);                     //调用平均分排序函数；
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
			case 1:SortBySum1(head);                      //总分排序函数调用；
				break;
			case 2:SortBySum2(head);
				break;
			default:MessageBox(NULL,"your input form is not correct!please input again!","MessageBox",MB_OK|MB_SETFOREGROUND);
				goto dian6;
			}
			break;
		case 13:head=ReadFromFile(head);                  //调用从文件读取数据函数；
			break;
		case 14:SaveFile(head);                           //调用将数据保存到文件函数；
			break;
		case 15:PrintAll(head);                           //输出链表函数调用；
			break;
		case 16:head=Delete1(head);                       //函数调用；
			break;
		case 17:head=SearchAndInsert(head);               //函数调用；
			break;
		case 18:SearchByGrade(head);                      //SearchByGrade函数调用；
			break;
		case 19:
			printf("please input the semster:");
			scanf("%d",&i);
			SearchBySemster(head,i);                      //SearchBySemster函数调用；
			break;
		case 0:c=MessageBox(NULL,"befor exit,be sure you are\nsave the file!\npress ok to exit\npress cancel to return\nthe execut!","MessageBox",MB_OKCANCEL|MB_SETFOREGROUND);//提示用户保存文件；
			if(c==2)                                      //用户点击取消进入菜单；
			{
				goto dian0;
			}
			else
			{
				Release(head);                             //释放内存函数调用；
				printf("end of program!\n");
			    exit(0);
			}
		default:MessageBox(NULL,"your input form is not correct!now please input again!\n1 stand for sequence, 2 stand for grade down!","MessageBox",MB_OKCANCEL|MB_SETFOREGROUND);
			scanf("%d",&n);                               //输入‘
			goto dian1;                                   //goto语句，输入错误时调回1处重新输入；
		}
	}
}/*此函数的功能是根据主菜单返回值进行操作，switch语句进行选择，并进入相关的功能。*/


//函数功能：显示主菜单；
//参数：int；
//返回值：choose；
int Menu()                                                //函数定义；
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
	printf("         *                      7:Rvise(修改)                       *\n");
	printf("         *                      8:SortByClass                       *\n");
	printf("         *                      9:SortBySex                         *\n");
	printf("         *                      10:SortByNum                        *\n");
	printf("         *                      11:SortByAver                       *\n");
	printf("         *                      12:SortBySum                        *\n");
	printf("         *                      13:ReadFromFile                     *\n");
	printf("         *                      14:SaveFile                         *\n");
	printf("         *                      15:PrintAll                         *\n");
	printf("         *                      16:SearchAndDelete(查找并删除)      *\n");
	printf("         *                      17:SearchAndInsert                  *\n");
	printf("         *                      18:SearchByGrade(查找某科不及格学生)*\n");
	printf("         *                      19:SearchBySemster(按学期查找)      *\n");
	printf("         *                      0:exit                              *\n");
	printf("         ************************************************************\n");
	printf("\n");
	printf("             *****please iput which function you want to use****:");
	scanf("%d",&choose);                                  //输入；
	return choose;                                        //返回choose；
}

//函数功能：创建一个链表；
//参数类型：struct link *;
//返回值：head;

struct link *CreatLink(struct link *head)                 //函数定义；
{
	int n;
	char c;
	struct link *p;        //定义一个指针；
	struct link *pr;
	if(head!=NULL)
	{
		n=MessageBox(NULL,"There have the old imformatiom!\nwhether to creat other node after\nit?","MessageBox",MB_OKCANCEL|MB_SETFOREGROUND);
		if(n==1)//根据窗口返回值。
		{
			for(pr=head;pr->next!=NULL;)//走到链表的最一个节点。
			{
				pr=pr->next;
			}
			MessageBox(NULL,"now,creat a now node after the old link!","MssageBox",MB_OK|MB_SETFOREGROUND);
			p=(struct link *)malloc(sizeof(struct link));
			Input(p);//函数调用；
			pr->next=p;
			goto duandian;
		}
		else
		{
			goto end;//用户选取取消键
		}
	}
	p=(struct link *)malloc(sizeof(struct link));         //向系统申请一块内存并将地址赋给指针p;
	if(head==NULL)         //将地址作为链表的头部；
	{
		head=p;
		pr=head;
	}
	do
	{
		Input(p);          //对输入函数进行调用；
duandian:printf("go on?(y or n)");                        //设置的duandian方便错误时用；
		scanf("%1s",&c);
		if(c!='n' && c!='N' && c!='y' && c!='Y')          //判断输入的正确性；
		{
			MessageBox(NULL,"you input a wrong char!","warning",MB_OK|MB_SETFOREGROUND);
			goto duandian;                                //跳到duandian;
		}
		if(c=='y' || c=='Y')
		{
			p=(struct link *)malloc(sizeof(struct link));//申请内存；
			{
				if(p==NULL)                              //申请失败时退出；
				{
				    MessageBox(NULL,"can't apply for size succesful! exit!","error",MB_OK|MB_SETFOREGROUND);
					exit(1);
				}
			}
			pr->next=p; 
			pr=pr->next;
		}
	}
	while(c=='y' || c=='Y');                              //循环条件；
end:return head;           //返回首地址；
}

//函数功能：输入信息；
//参数类型：void;
//返回值：无；

void Input(struct link *p)                                //函数定义；
{
	int i;
	float sum=0,aver;
	printf("please input the semster:");
	scanf("%d",&p->semster);//输入学期；
	printf("please input the student's num:");
	scanf("%d",&p->num);  //输入学号；
	printf("please input the student's class:");
	scanf("%d",&p->cla);  //输入班级；
	printf("please input the student's name:");
	scanf("%s",p->name);  //输入姓名；
	printf("please input the student's sex:");
	scanf("%1s",&p->sex); //输入性别；
	for(i=0;i<5;i++)
	{
		printf("please input the %dth score:",i+1);
		scanf("%f",&p->score[i]);                         //输入成绩；
		sum=sum+p->score[i];                              //求总分;
	}
	p->sum=sum;           //将总分写入；
	aver=sum/5;           //求平均成绩；
	p->aver=aver;         //将平均成绩写入；
	p->next=NULL;         //将指针指向空；
}

//函数功能：输出整个链表；
//参数类型：void；
//返回值：无；

void PrintAll(struct link *head)                           //函数定义；
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
	    do//输出链表信息到屏幕；
		{
			printf("%-3d",p->semster);
	    	printf(" %-6s",p->name);
	    	printf("%-5d",p->cla);
	    	printf("%-5d",p->num);
	    	printf("%-5c",p->sex);
	    	for(i=0;i<5;i++)                                  //利用for循环输入；
			{
	    		printf("%-8.2f",p->score[i]);
			}
	    	printf("%-8.2f",p->sum);
	    	printf("%-6.2f",p->aver);
	    	printf("\n");
	    	p=p->next;
		}
    	while(p!=NULL);                                       //当指针不为空时继续循环；
	}
}

//函数功能：新建一个节点；
//参数：struct link *;
//返回值：p；

struct link *CreatNode()                                  //函数定义；
{
	struct link *p;                                       //实参定义；
	p=(struct link *)malloc(sizeof(struct link));         //申请内存；
	if(p==NULL)
	{
		MessageBox(NULL,"can't ask for memoroy! exit!","error",MB_OK|MB_SETFOREGROUND);
		exit(0);
	}
	Input(p);            //输入函数调用；
	return p;            //返回p的首地址；
}

//函数功能：插入节点；
//参数：struct link *；
//返回值：head;

struct link *Insert(struct link *head,int n)                  //函数定义；
{
	int i;
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)
	{
		p=CreatNode();       //创建节点函数调用；
		head=p;
		MessageBox(NULL,"succesful to insert a node!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
	    if(n==1)             //n=1时，更换头部地址；
		{
			p=CreatNode();    //创建节点函数调用；
		    pr=head;
		    head=p;
		    p->next=pr;
			MessageBox(NULL,"succesful to insert a node!","MessageBox",MB_OK|MB_SETFOREGROUND);
		}
    	else
		{
		    pr=head;
		    for(i=0;i<n-1;i++)                            //寻找要插入的节点位置，如果找不到打印错误信息；
			{
			    if(pr==NULL)
				{
				    MessageBox(NULL,"out of arrange!","error",MB_OK|MB_SETFOREGROUND);
					break;
				}
			    else
				{
					if(i==n-2)   //定位；
					{
						p=CreatNode();       //创建节点函数调用；
				        pr1=pr->next;
				        pr->next=p;
				        p->next=pr1;
						MessageBox(NULL,"succesful to insert a node!","MessageBox",MB_OK|MB_SETFOREGROUND);
					}
				}
				pr=pr->next;                              //节点指向下一个节点；
			}
		}
	}
	return head;                                          //返回链表头部的首地址；
}

//函数功能：删除一个节点；
//参数：struct link *；
//返回值：head；

struct link *Delete(struct link *head,int n)              //函数定义；
{
	int i;
	struct link *p;
	struct link *pr;
	struct link *pr1;
	if(head==NULL)                                        //判断是否有链表存在；
	{
		MessageBox(NULL,"have nothing about link imformation!","error",MB_OK|MB_SETFOREGROUND);
		exit(0);
	}
	if(n==1)
	{
		p=head->next;
		free(head);                                       //释放被删除节点所占的内存；
		head=p;//将head后的一个节点作为head;
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
				break;//超出范围，输出错误原因，并停止此函数；
			}
		    else
			{
				if(i==n-2)
				{
		        	pr=p->next;
		        	pr1=pr->next;
		        	p->next=pr1;
		        	free(pr);                             //释放被删除节点所占的内存；
					MessageBox(NULL,"successfully to delete!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
			}
			p=p->next;
		}
	}
	return head;
}

//函数功能：输出单个节点；
//参数：void；
//返回值：无；

void PrintOneNode(struct link *p)                         //函数定义；
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
	printf("\n");        //换行符；
}

//函数功能：按学生班级查找；
//参数：void；
//返回值：无;

void SearchByClass(struct link *head,int n)               //函数定义；
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
	     	if(p->cla==n)                                 //判断是否符合条件，符合便输出有关信息；
			{
	    		PrintOneNode(p);                          //单个节点输出函数调用；
	    		count++;
			}
	    	p=p->next;
		}
    	if(count==0)                                      //没找到，输出；
		{
			MessageBox(NULL,"unfortunately,can't find the information!","MessageBox",MB_OK|MB_SETFOREGROUND);
		}
	}
}

//函数功能：按照学生的学号查找；
//参数：void；
//返回值：无；

void SearchByNum(struct link *head,int n)                 //函数定义；
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
	    		PrintOneNode(p);                              //单个节点输出函数调用；
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

//函数功能：按照学生的姓名查找；
//参数：void
//返回值：无

void SearchByName(struct link *head,char a[])             //函数定义；
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
	    	if(strcmp(p->name,a)==0)                      //判断输入的字符与p->name中所存的字符是否相同；
			{
		    	PrintOneNode(p);                          //输出一个节点函数调用；
		    	count++;                                  //若符合条件则进行自加；
			}
	    	p=p->next;
		}
    	if(count==0)                                      //count=0，没有满足条件的节点；输出没有找到该信息；
		{
			MessageBox(NULL,"unfortunately,can't find the information!","error",MB_OK|MB_SETFOREGROUND);
		}
	}
}

//函数功能：修改学生信息；
//参数：void；
//返回值：无；

void Rvise(struct link *head)                             //函数定义；
{
	int i,j,n;                                            //实参定义；
	char *p1;
	struct link *p;
	if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
    	printf("please input n:( 1 stand for num, 2 stand for name)");
    	scanf("%d",&n);                                       //输入；
    	switch(n)                                             //switch选择结构；
		{
    	case 1:printf("please input the student's number:");
	    	scanf("%d",&i);                                   //输入；
	    	p=SearchByNUM(head,i);                            //函数调用；
	    	if(p!=NULL)
			{
		    	printf("1:s  2:name 3:cla 4:num 5:sex 6:score1 7:score2 8:score3 9:score4 10:score5 11:revise all\n");
	        	printf("please input which one you want to revise:");
	        	scanf("%d",&j);
	        	switch(j)                                     //switch选择结构选择需要更改的项目；
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
		     	if(p!=NULL)                               //p!=NULL表明修改成功并调用输出一个节点函数输出修改的信息；
				{
			    	Summatiom(p);                         //调用总分计算函数，修改总分和平均分；
					MessageBox(NULL,"succesful revise the imfoematoin !","MessageBox",MB_OK|MB_SETFOREGROUND);
			    	printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
			    	PrintOneNode(p);                      //输出一个节点函数调用；
				}
			}
			break;
    	case 2:printf("please input the student's name:");
	    	p1=malloc(sizeof(char));
	    	scanf("%s",p1);
	    	p=SearchByNAME(head,p1);                      //函数调用；
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

//函数功能：按姓名查找（修改信息时用）；
//参数:struct link *;
//返回值：p;

struct link *SearchByNAME(struct link *head,char a[])     //函数定义；
{
	int i;
	struct link *p;
	if(head==NULL)                                        //head=NULL表明没有链表信息；
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND); //输出错误信息；
	}
	else
	{
		p=head;
    	for(i=0;p!=NULL;i++)
		{
	    	if(strcmp(p->name,a)==0)                          //找到后输出并返回地址p,并输出里边的信息；
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

//函数功能：按学号查找（修改信息时用）；
//参数：struct link *;
//返回值：p;

struct link *SearchByNUM(struct link *head,int n)         //函数定义；
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
		    	PrintOneNode(p);//PrintOneNode函数调用；
		    	break;
			}
			p=p->next;
		}
	}
	return p;
}

//函数功能：求sum 与 aver(在修改信息时用)；
//参数：void;
//返回值：无；

void Summatiom(struct link *p)                            //函数定义；
{
	int i;                                                //实参定义；
	float sum=0,aver;
	for(i=0;i<5;i++)                                      //用for循环求和；
	{
		sum=sum+p->score[i];
	}
	aver=sum/5;                                           //求平均分；
	p->sum=sum;                                           //写入数据；
	p->aver=aver;
}

//函数功能：释放数据所占用的内存；
//参数：void;
//返回值：无；

void Release(struct link *head)                           //函数定义；
{
	int i;
	struct link *p;
	struct link *pr;
	p=head;
	for(i=0;p!=NULL;i++)
	{
		pr=p->next;
		free(p);                                          //释放内存；
		p=pr;
	}
}

//函数功能：按照班级的升序排序；
//参数：struct link*;
//返回值：head;

void SortByClass1(struct link *head)                      //函数定义；
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
		    		SwapCla(pr,pr1);                          //调用swap函数交换数据；
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

//函数功能：按班级降序排序；
//参数：void;
//返回值：无；

void SortByClass2(struct link *head)                      //函数定义；
{
	int count=0,i;                                        //定义实参；
	struct link *p;
	struct link *pr;
	struct link *pr1;
    if(head==NULL)
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		for(p=head,count=0;p!=NULL;)                      //计算链表的节点数；
		{
	    	count++;
	    	p=p->next;
		}
    	for(p=head;p!=NULL;)                              //类似冒泡法排序；
		{
    		for(i=0,pr=head;i<count-1;i++)
			{
	    		if(pr->cla<(pr->next)->cla)               //判断条件；
				{
	    			pr1=pr->next;
					SwapSemster(pr,pr1);
		    		SwapCla(pr,pr1);                      //调用swap函数交换数据；
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

//函数功能：交换semster数据；
//参数：void;
//返回值：无;

void SwapSemster(struct link *p0,struct link *p1)         //函数定义；
{
	int temp;
	temp=p0->semster;
	p0->semster=p1->semster;
	p1->semster=temp;
}

//函数功能：交换class数据；
//参数：void;
//返回值：无；

void SwapCla(struct link *p0,struct link *p1)             //函数定义；
{
	int temp;
	temp=p0->cla;
	p0->cla=p1->cla;
	p1->cla=temp;
}

//函数功能：交换NAME数据；
//参数：void；
//返回值：无；

void SwapName(struct link *p0,struct link *p1)            //函数定义；
{
	char *temp;
	temp=malloc(sizeof(char));
	strcpy(temp,p0->name);                                //交换数据；
	strcpy(p0->name,p1->name);
	strcpy(p1->name,temp);
}

//函数功能：交换num数据；
//参数：void;
//返回值：无；

void SwapNum(struct link *p0,struct link *p1)             //函数定义；
{
	int temp;
	temp=p0->num;
	p0->num=p1->num;
	p1->num=temp;
}

//函数功能：交换sex数据；
//参数：void；
//返回值：无；

void SwapSex(struct link *p0,struct link *p1)             //函数定义；
{
	char c;
	c=p0->sex;
	p0->sex=p1->sex;
	p1->sex=c;
}

//函数功能：交换score数据；
//参数：void；
//返回值：无；

void SwapScore(struct link *p0,struct link *p1)           //函数定义；
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

//函数功能：交换sum数据；
//参数：void；
//返回值：无；

void SwapSum(struct link *p0,struct link *p1)             //函数定义；
{
	float temp;
	temp=p0->sum;
	p0->sum=p1->sum;
	p1->sum=temp;
}

//函数功能：交换aver数据；
//参数：void；
//返回值：无；

void SwapAver(struct link *p0,struct link *p1)            //函数定义；
{
	float temp;
	temp=p0->aver;
	p0->aver=p1->aver;
	p1->aver=temp;
}

//函数功能:按照男前女后顺序排序；
//参数：void ;
//返回值：无；

void SortBySex1(struct link *head)                        //函数定义；
{
	int i,count=0;                                        //定义实参；
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
					SwapCla(pr,pr1);                          //调用swap函数交换数据；
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

//函数功能：按照性别排序；
//参数：void；
//返回值：无；

void SortBySex2(struct link *head)                        //函数定义；
{
	int i,count=0;                                        //定义实参；
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
				if((pr->sex=='m' || pr->sex=='M') && ((pr->next)->sex=='f' || (pr->next)->sex=='F'))  //判断；
				{
					pr1=pr->next;
					SwapCla(pr,pr1);                          //调用swap函数交换数据；
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

//函数功能：按照学号的升序排序；
//参数：void;
//返回值：无；

void SortByNum1(struct link *head)                        //函数定义；
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
					SwapCla(pr,pr1);                          //调用swap函数交换数据；
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

//函数功能：按照学号的降序排序；
//参数：void；
//返回值：无；

void SortByNum2(struct link *head)                        //函数定义；
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
					SwapCla(pr,pr1);                          //调用swap函数交换数据；
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

//函数功能：按照总分升序排序；
//参数：void;
//返回值：无；

void SortBySum1(struct link *head)                        //函数定义；
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
					SwapCla(pr,pr1);                          //调用swap函数交换数据；
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

//函数功能：按照总分降序排序；
//参数：void;
//返回值：无；

void SortBySum2(struct link *head)                        //函数定义；
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
					SwapCla(pr,pr1);                          //调用swap函数交换数据；
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

//函数功能：按照平均分升序排序；
//参数：void；
//返回值：无；

void SortByAver1(struct link *head)                       //函数定义；
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
					SwapCla(pr,pr1);                          //调用swap函数交换数据；
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

//函数功能：按照平均分降序排序；
//参数：void；
//返回值：无；


void SortByAver2(struct link *head)                       //函数定义；
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
					SwapCla(pr,pr1);                          //调用swap函数交换数据；
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

//函数功能：从文件读取数据到内存；
//参数:struct link*；
//返回值：无；

struct link *ReadFromFile(struct link *head)              //函数定义；
{
	int i,n=0,j=1;                                        //实参定义；
	struct link *p;
	struct link *pr=NULL;
	struct link *pr1=head;
	FILE *fp;                                             //定义文件指针；
	char filename[30];
	printf("please input the filename(inclede route):");
	scanf("%s",filename);
	printf("now, read sourse from file!\n");
	if((fp=fopen(filename,"r"))==NULL)                    //若不能打开文件，输出错误信息并退出；；
	{
		MessageBox(NULL,"can't open the file!","error",MB_OK|MB_SETFOREGROUND);
		exit(0);
	}
	else
	{
		if(head!=NULL)                                    //将末尾的首地址赋值给指针pr;
		{
			for(;pr1->next!=NULL;)
			{
		    	pr1=pr1->next;
			}
	    	pr=pr1;
		}
		for(;fgetc(fp)!=EOF;)
		{
			p=(struct link *)malloc(sizeof(struct link)); //申请内存，从文件读取数据到内存；
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
			if(head==NULL)                                //内存里没有数据，直接将文件读到内存；
			{
				head=p;
				pr=p;
			}
			else                                          //若内存里有数据，则将文件数据读到内存链表数据后；
			{
				pr->next=p;
				pr=p;
			}
			n++;                                          //记录读取了多少数据（节点）；
		}
		printf("%d node(s) have been readed!\n",n);
	}
	fclose(fp);                                           //关闭文件；
	return head;                                          //返回链表首地址；
}

//函数功能：将数据保存到文件；
//参数：void;
//返回值：无；

void SaveFile(struct link *head)                          //函数定义；
{
	int i,j;
	char filename[30];
	struct link*p;
	FILE *fp;                                             //定义文件指针；
	if(head==NULL)                                        //若没有链表信息，输出错误信息；
	{
		MessageBox(NULL,"there have nothing imformation,can't motion this function!","error",MB_OK|MB_SETFOREGROUND);
	}
	else
	{
		printf("please input the filename(include route):\n");//输入需要将信息保存到文件的文件名称；

		scanf("%s",filename);


		if((fp=fopen(filename,"w+"))==NULL)               //若不能打开此文件，输出错误信息；
		{
			MessageBox(NULL,"can't open the file!","error",MB_OK|MB_SETFOREGROUND);
			exit(0);
		}
		else
		{
			for(j=0,p=head;p!=NULL;)                      //将数据写入到文件；
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

//函数功能：删除一个特定的节点
//参数 struct link *
//返回值 ：head；

struct link *Delete1(struct link *head)                   //函数定义；
{
	int i,n,c;                                            //实参定义；
	char a[20];
	struct link * p;
	struct link * pr;
	printf("now find a imformation and delete it!");
dian1:	printf("1 stand for search by name,2 stand for search by num,press 0 to exit delete!\n");
	printf("please input your choose:");
	scanf("%d",&i);                                       //输入需要选择的功能；
	switch(i)
	{
	case 0:break;
	case 1:printf("please input the student's name:");
		scanf("%s",a);
		n=SearchBYName(head,a);                           //函数调用；
		if(n==-1)
		{
	   	    c=MessageBox(NULL,"sure to delete?","MessageBox",MB_OKCANCEL|MB_SETFOREGROUND);
			if(c==1)                                      //删除链表头部，将head->next作为头部；
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
			for(i=0;i<n && p!=NULL;i++)                     //指针跳到所寻找的节点的前一个节点；
			{
			   	p=p->next;
			}
			if(p->next==NULL)                             //若没有下一个节点，则不存在该信息，输出错误信息；
			{
				MessageBox(NULL,"can't find the student's imformation!can't use this function!","Messagebox",MB_OK|MB_SETFOREGROUND);
			}
			if(p->next!=NULL)                             //存在该信息；
			{
				c=MessageBox(NULL,"sure to delete?","MessageBox",MB_OKCANCEL|MB_SETFOREGROUND);
		    	if(c==1)                                  //将此节点删除；
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
		n=SearchBYNum(head,i);                            //函数调用；
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
		default :MessageBox(NULL,"you input a wrong choose!please input again!","error",MB_OK|MB_SETFOREGROUND);         //输入错误；跳到dina1重新输入（本函数中的dian1）；
		goto dian1;
	}
	return head;
}

//函数功能：按姓名查找；
//参数:int
//返回值：n-1

int SearchBYName(struct link *head,char a[])              //函数定义；
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

//函数功能：按学号查找；
//参数：int
//返回值：m-1

int SearchBYNum(struct link *head,int n)                  //函数定义；
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

//函数功能：按用户输入查找在相应位置插入节点；
//参数：struct link *；
//返回值：head;

struct link *SearchAndInsert(struct link *head)           //函数定义；
{
	struct link*p;                                        //实参定义；
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
		m=SearchBYName(head,a);                           //函数调用；
		for(j=0,p=head;j<m && p!=NULL;j++)                //跳到指定节点前一个节点（除了指定节点是头部外）；
		{
			p=p->next;
		}
		if(m==-1)                                         //指定节点为头部，并输出该节点信息；
		{
			printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
			PrintOneNode(head);                           //输出一个节点函数调用；
		}
		else
		{
			if((p->next)!=NULL)                           //输出指定节点信息；
			{
		    	printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
		    	PrintOneNode(p->next);                    //输出一个节点函数调用；
			}
		}
		if((p->next)==NULL && m!=-1)                      //没有该节点信息，输出错误信息；
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
				goto dian1;                               //输入错误，函数跳到本函数dian1处；
			}
			if(n==1)
			{
				if(m==-1)                                 //选择第一项功能，并且指定节点为头部；
				{
					pr=CreatNode();                       //申请节点内存空间，将此信息插入到头部前，并将此节点作为头部；
					pr->next=head;
					head=pr;
					MessageBox(NULL,"successfully to insert!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
				else                                      //指定节点不是头部，将申请节点插入到指点前；
				{
					pr2=CreatNode();                      //创建节点函数调用；
			     	pr=p->next;
			    	p->next=pr2;
			    	pr2->next=pr;
					MessageBox(NULL,"successfully to insert!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
			}
			else
			{
				if(m==-1)                                 //将节点插入到指定节点后；
				{
					pr=CreatNode();                       //创建节点函数调用；
					p=head->next;
					head->next=pr;
					pr->next=p;
					MessageBox(NULL,"successfully to insert!","MessageBox",MB_OK|MB_SETFOREGROUND);
				}
				else                                      //将节点插入到指定节点后；
				{
					pr2=CreatNode();                      //创建节点函数调用；
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
	default :MessageBox(NULL,"you input a wrong number!please input again!","error",MB_OK|MB_SETFOREGROUND);   //输入错误跳到本函数的dian3处；
		goto dian3;
	}
	return head;                                          //返回头部地址；
}

/*
//函数功能：交换指针里边的数据；
//函数类型：void;
//返回值：无；

void Swap(struct link *p0,struct link *p1)                //用于指针间交换数据；函数定义；
{
    int a,i;                                              //实参定义；
    float b;
    char n[20],c;
    a=p0->num;                                            //交换学号数据；
    p0->num=p1->num;
    p1->num=a;
    a=p0->cla;                                            //交换班级数据；
    p0->cla=p1->cla;
    p1->cla=a;
	c=p0->sex;                                            //交换性别信息；
    p0->sex=p1->sex;
    p1->sex=c;
    strcmp(n,p0->name);                                   //交换姓名数据；
    strcmp(p0->name,p1->name);
	strcmp(p1->name,n);
    for(i=0;i<5;i++)                                      //交换分数数据；
	{
		b=p0->score[i];
		p0->score[i]=p1->score[i];
		p1->score[i]=b;
	}
	b=p0->sum;                                            //交换总分数据；
	p0->sum=p1->sum;
	p1->sum=b;
	b=p0->aver;                                           //交换平均分数据；
	p0->aver=p1->aver;
	p1->aver=b;

}
*/

//函数功能：根据输入科目进行查找不及格的学生
//参数：void
//返回值：无；

void SearchByGrade(struct link *head)                     //函数定义；
{
	struct link *p=head;
	int i,n=0;
	float m;
dian0:printf("1:score1 2:score2 3:score3 4:score4 5:score5\n");
	printf("please input your choose:");
	scanf("%d",&i);
	if(i<1 || i>5)
	{
		MessageBox(NULL,"you input  a wrong number!please input again!","MessageBox",MB_OK|MB_SETFOREGROUND);  //提示窗口；
		goto dian0;                                       //输入错误，跳到dain0处；
	}
	printf("please input low grades:");
	scanf("%f",&m);
	printf("s  name  cla  num  sex  score1  score2  score3  score4  score5   sum     aver   \n");
	switch(i)
	{
	case 1:for(;p!=NULL;p=p->next)
		   {
			   p=SearchByG1(p,m);                         //SearchByG1函数调用；
			   if(p==NULL)
				   goto END;
			   PrintOneNode(p);                           //PrintOneNode函数调用；
			   n++;
		   }
		break;
	case 2:for(;p!=NULL;p=p->next)
		   {
			   p=SearchByG2(p,m);                         //SearchByG2函数调用；
			   if(p==NULL)
				   goto END;
			   PrintOneNode(p);                           //PrintOneNode函数调用；
			   n++;
		   }
		break;
	case 3:for(;p!=NULL;p=p->next)
		   {
			   p=SearchByG3(p,m);                         //SearchByG3函数调用；
			   if(p==NULL)
				   goto END;
			   PrintOneNode(p);                           //PrintOneNode函数调用；
			   n++;
		   }
		break;
	case 4:for(;p!=NULL;p=p->next)
		   {
			   p=SearchByG4(p,m);                         //SearchByG4函数调用；
			   if(p==NULL)
				   goto END;
			   PrintOneNode(p);                           //PrintOneNode函数调用；
			   n++;
		   }
		break;
	case 5:for(;p!=NULL;p=p->next)
		   {
			   p=SearchByG5(p,m);                         //SearchByG5函数调用；
			   if(p==NULL)
				   goto END;
			   PrintOneNode(p);                           //PrintOneNode函数调用；
			   n++;
		   }
END:printf("Search subject 5,low grade student(s) are %d person(s) in all!\n",n);
	break;
	default:
		break;
	}
}

//函数功能：查找不及格个数
//参数：struct link *
//返回值：p;
struct link *SearchByG1(struct link *p,float n)           //函数定义；
{
	for(;p!=NULL;p=p->next)
	{
		if(p->score[0]<n)
			break;
	}
	return p;
}

//函数功能：查找不及格个数
//参数：struct link *
//返回值：p;
struct link *SearchByG2(struct link *p,float n)           //函数定义；
{
	for(;p!=NULL;p=p->next)
	{
		if(p->score[1]<n)
			break;
	}
	return p;
}

//函数功能：查找不及格个数
//参数：struct link *
//返回值：p;
struct link *SearchByG3(struct link *p,float n)           //函数定义；
{
	for(;p!=NULL;p=p->next)
	{
		if(p->score[2]<n)
			break;
	}
	return p;
}

//函数功能：查找不及格个数
//参数：struct link *
//返回值：p;
struct link *SearchByG4(struct link *p,float n)           //函数定义；
{
	for(;p!=NULL;p=p->next)
	{
		if(p->score[3]<n)
			break;
	}
	return p;
}

//函数功能：查找不及格个数
//参数：struct link *
//返回值：p;
struct link *SearchByG5(struct link *p,float n)           //函数定义；
{
	for(;p!=NULL;p=p->next)
	{
		if(p->score[4]<n)
			break;
	}
	return p;
}

//函数功能：根据学期查找；
//参数：void;
//返回值：无；

void SearchBySemster(struct link *head,int n)             //函数定义；
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
			PrintOneNode(p);                              //PrintOneNode函数调用；
			i++;
		}
	}
	if(i==0)
	{
		MessageBox(NULL,"Unfortunately,can't find the imformation!please input again!","MessageBox",MB_OK|MB_SETFOREGROUND);
	}

}
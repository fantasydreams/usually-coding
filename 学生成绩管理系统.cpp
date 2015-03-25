#include<iostream>
#include<string>
#include<fstream>


using namespace std;


typedef struct student
{
	string StuID;    //定义学生学号；
	string Name;     //学生姓名；
	double MathScore;//学生数学成绩；
	double ProgramScore;//程序设计成绩；
	double TP;       //总分；
	struct student * primer;//存取上一节点的地址；
	struct student * next;  //存取下一节点的地址；
}Stu;



//函数声明区：
void PrintAll(Stu * head);
void PrintOne(Stu * p);
void Function(Stu * head);
void DeleteData(Stu * head);
void SaveDataToFileEnd(Stu * head);
void AddLink(Stu * head, Stu * p);
void SortByMath(Stu * head, char Ch);
void SortByProgram(Stu * head, char Ch);
void SwaP(Stu * Guard, Stu * Cur);
void SortByTP(Stu *head, char Ch);
void SaveMathDataToFile(Stu * head);
void SaveProgramDataToFile(Stu * head);
void SaveTPScoreToFile(Stu * head);
void FreeRam(Stu * head);
void PrintMenu();
char Menu();
char Menu1();
char Menu2();
char Menu3();
char Menu4();
char Menu5();
inline Stu *ApplyRam();
bool SaveDataToFile(Stu * head);
bool FindStuID(Stu * head, string ID);
bool FindByName(Stu * head, string name);
bool FindByMathScore(Stu * head, double MathScore);
bool FindByProgramScore(Stu * head, double MathScore);
bool FindByTP(Stu * head, double TP);
int DataInput(Stu * head, Stu * p);
Stu * BuildLink(Stu * Head);
Stu * ReadDataFromFile();
Stu * FindMin(Stu * p);
Stu * FindMax(Stu * p);
Stu * FindMin1(Stu * p);
Stu * FindMax1(Stu * p);
Stu * FindMax2(Stu * p);
Stu * FindMin2(Stu * p);
Stu * FindByNameAndDelete(Stu * head, string name);
Stu * FindByStuIDAndDelete(Stu * head, string StuID);
Stu * FindBySerial(Stu * head, int Num);
Stu * DeleteBySerial(Stu * head);

template <typename T>
void Swap(T & Data1, T & Data2)
{
	T Data = Data1;
	Data1 = Data2;
	Data2 = Data;
}
Stu * FindCommomStuID(Stu * head, Stu * p)   //函数传入参数为链表的首地址和一个节点的地址
{
	while (head)           //寻找链表中的数据
	{
		if (head->StuID == p->StuID)  //若找到相同的数据，则返回此节点的地址
			return head;
		head = head->next;       //走向链表的下一节点
	}
	return NULL;         //没有相同的数据，返回数据为空
}


void main()
{
	system("color F1");                                       //调用系统函数库，对窗口及字体的颜色进行修改
	cout << "欢迎使用成绩管理系统" << endl;
	cout << "正在从文件读取数据，请稍后..." << endl;
	Stu * head = NULL;                                        //定义链表头并赋值为空
	ifstream InFile("students.txt");						  //打开“student.txt”文件
	if (InFile)
	{
		head = ReadDataFromFile();                            //从“student.txt”文件读取数据
		cout << "成功从文件中读取数据！" << endl;
	}
	else
	{
		cout << "未发现文件存在，请先建立文件..." << endl;
	}
	Function(head);											 //功能选择函数调用
	FreeRam(head);											 //释放占用内存
	system("pause");
}

//退出程序将存中的数据进行释放
void FreeRam(Stu * head)
{
	Stu * Cur;         //定义一个指针，记录当前指针指向内存的地址
	while (head)      //若head不为空，便一直执行delete，释放占用内存空间，直到为空
	{
		Cur = head;
		head = head->next;  //顺着链表向下走
		delete Cur;    //释放当前节点占用的内存
	}
}

//通过学号查询删除
Stu * FindByStuIDAndDelete(Stu * head, string StuID)   //入口有两个值，一个是链表的头结点，一个是存储输入的信息（学号）
{
	while (head)        //循环查找
	{
		if (head->StuID == StuID)    //判断是否符合条件
			return head;         //若符合，便返回这个节点的地址
		head = head->next;        //否则顺着链表向下走，继续寻找
	}
	return head;             //没找着，返回head(NULL)
}

//选择功能函数
void Function(Stu * head)
{
	char Ch;            //定义一个char类型用于记录用户输入的数据
	Stu * p = NULL;     //定义一个指针
	string S;            //定义string类型S,用于存储用户输入的数据
	bool J; 
	double Num;          //double类型Num，用于存储用户输入的数据
	while (true)        //一直循环，直到语句执行break跳出
	{
		Ch = Menu();      //调用Menu函数，显示一级菜单，并返回用户输入的数据并赋给Ch;
		switch (Ch)       //根据用户输入的数据进行功能选择
		{
		case '1':if (head != NULL)     //输入w为‘1’，当程序中已经村在之前的数据
				{
					 cout << '\a' << "Caution：计算机中存在旧数据!"<<endl;
					 char ch;    //定义另一个char类型字符，用于存储用户输入的数据
					 while (true)  //一直循环，直到语句执行break跳出
					 {
						 ch = Menu1();  //调用Menu1函数，进行相应二级菜单显示，并记录用户输入的数据
						 switch (ch)   //根据用户输入的数据进行选择功能
						 {
						 case '1':DeleteData(head);   //输入为'1'时，调用数据删除函数，清空内存所有的数据并释放
							 head = NULL;    //将头指针赋值为空
							 cout << "已成功清除所有数据！开始创建新数据..." << endl;
							 head = BuildLink(head);  //调用BuildLink函数重新建立新的数据（链表）
							 cout << "成功创建新数据！" << endl;
							 break;
						 case '2':cout << "请输入你需要添加的信息：" << endl; //输入为'2'时，
							 p = BuildLink(head);   //另外新建一个链表
							 SaveDataToFileEnd(p);  //调用SaveDataToFileEnd函数将新链表中的数据保存至文件末尾
							 AddLink(head, p);      //将之前的链表与新建的链表进行连接
							 cout << "已成功添加信息" << endl;
							 break;
						 }
						 if (ch == '3')      //输出为'3'，退出循环
							 break;
					 }
				}
				 else          //若程序中没有旧数据
				 {
					 head = BuildLink(head);      //调用BuildLink函数重新建立新的数据（链表）
					 if (head != NULL)            //若有新建数据
					 {
						 cout << "已成功新建数据！"<<endl;
						 SaveDataToFile(head);    //将新建的数据保存至文件
					 }
				 }
				 break;
		case '2':cout << "请输入你需要添加的数据"<<endl;   //若输入的是'2'
			p = BuildLink(head);                    //调用BuildLink函数，构建新的链表
			SaveDataToFileEnd(p);                  //调用SaveDataToFileEnd函数将新链表中的数据保存至文件末尾
			AddLink(head, p);						//将之前的链表与新建的链表进行连接
			cout << "已成功添加数据！" << endl;
			break;
		case '3':						//若输入的是'3'
			while (true)              //一致循环
			{
				Ch = Menu5();         //调用Menu5函数，显示相应二级菜单并保存用户输入的数据
				switch (Ch)          //根据用户输入的数据进行选择功能
				{
				case '1':cout << "请输入需要查找的学号：";
					cin >> S;           //输入数据
					p = FindByStuIDAndDelete(head, S);       //调用FindByStuIDDelete函数进行查找
					if (p)            //若查到相应节点
					{
						PrintMenu(); //调用PrintMenu函数打印横菜单
						PrintOne(p); //调用PrintOne函数显示当前节点数据
						if (p == head)  //如果查找到的节点是头结点
						{
							cout << "确认删除?(Y or N)";
						Point:cin >> Ch;
							if (Ch != 'Y' && Ch != 'y' && Ch != 'N' && Ch != 'n')
							{
								cout << "输入有误，请重新输入：";
								goto Point;
							}
							if (Ch == 'Y' || Ch == 'y')       //输入删除
							{
								head = head->next;            //将链表的头往下移
								head->primer = head->primer->primer;
								delete p;                   //删除查找到的节点
								p = NULL;
								cout << "已成功删除！" << endl;
							}
						}
						else							//查找到的不是头结点
						{
							cout << "确认删除?(Y or N)";
						Point3:cin >> Ch;
							if (Ch != 'Y' && Ch != 'y' && Ch != 'N' && Ch != 'n')
							{
								cout << "输入有误，请重新输入：";
								goto Point3;
							}
							if (Ch == 'Y' || Ch == 'y')     //确定删除，删除查找到的节点，并将前后节点相连
							{
								Stu * Cur = p;
								Cur->primer->next = p->next;
								if (p->next!=NULL)
								{
									p->next->primer = Cur->primer;
								}
								else
								{
									head->primer = head->primer->primer;
								}
								delete Cur;
								Cur = p = NULL;
								cout << "已成功删除！" << endl;
							}
						}
					}
					else   //没有找到相应节点
					{
						cout << "未查找到相关信息！" << endl;
					}
					break;
				case '2':cout << "请输入需要查找的姓名：";      //若输入的树是'2',及通过查找姓名进行删除
					cin >> S;
					p = FindByNameAndDelete(head, S);            //通过调用FindByNameAndDelete函数查找满足的节点
					if (p)									//如果有满足条件的节点
					{
						if (p == head)						//如果查找到的节点是头结点
						{
							PrintMenu();					//调用PrintMenu函数打印横菜单
							PrintOne(p);					//调用PrintOne函数显示当前节点数据
							cout << "确认删除?(Y or N)";
							Point1:cin >> Ch;
							if (Ch != 'Y' && Ch != 'y' && Ch != 'N' && Ch != 'n')
							{
								cout << "输入有误，请重新输入：";
								goto Point1;
							}
							if (Ch == 'Y' || Ch == 'y')			//输入删除
							{
								head = head->next;				//将链表的头往下移
								head->primer = head->primer->primer;
								delete p;						//删除查找到的节点
								p = NULL;
							}
						}
						else									//查找到的不是头结点
						{
							PrintMenu();						//调用PrintMenu函数打印横菜单
							PrintOne(p);						//调用PrintOne函数显示当前节点数据
							cout << "确认删除?(Y or N)";
						Point2:cin >> Ch;
							if (Ch != 'Y' && Ch != 'y' && Ch != 'N' && Ch != 'n')
							{
								cout << "输入有误，请重新输入：";
								goto Point2;
							}
							if (Ch == 'Y' || Ch == 'y')				//输入删除
							{
								Stu * Cur = p;                     //连接两个节点
								Cur->primer->next = p->next;
								if (p->next != NULL)              //若删除的不是最后一个节点
								{
									p->next->primer = Cur->primer;
								}
								else								//若删除的是最后一个结点
								{
									head->primer = Cur->primer;    //将头结点与删除之后的末节点相连
								}
								delete Cur;                        //释放内存空间
								Cur = p = NULL;
								cout << "已成功删除！" << endl;
							}
						}
					}
					else							//若没找到，打印错误信息
					{
						cout << "未查找到相关信息！" << endl;
					}
					break;
				case '3':head = DeleteBySerial(head);   //输入的是'3'，即通过序号删除，调用DeleteBySerial函数进行操作
					break;
				}
				SaveDataToFile(head);       //将修改过的链表保存至文件
				if (Ch == '4')              //若输入'4'，则跳出循环
				{
					break;
				}
			}
			break;
		case '4':PrintAll(head);              //用户输入'4'，即查看所有数据函数，调用PrintAll函数进行操作
			system("pause");				//暂停
			break;
		case '5':char ch;					//当输入为'5'，即排序
			while (true)                   //一直循环，直至break跳出循环
		{
				ch = Menu2();              //调用Menu2函数显示相应二级菜单，并记录用户输入的数据
				switch (ch)               //根据用户输入的数据进行选择
				{
				case '1':Ch = Menu3();     //输入为'1'，数学成绩排序
					if (head != NULL)       //当链表不为空
					{
						SortByMath(head, Ch);  //调用SortByMath函数，进行排序操作
						cout << "已成功排序" << endl;
						SaveMathDataToFile(head); //将拍好序的数据保存至文件
						PrintAll(head);
					}
					else					//当不存在数据，打印错误信息
					{
						cout << "请新建数据在使用此功能..."<<endl;
					}
					break;
				case '2':Ch = Menu3();   //输入为'2'，调用Menu3函数显示相应的二级菜单，并记录用户输入的数据
					if (head != NULL)			 //当链表不为空
					{
						SortByProgram(head, Ch); //调用SortByPrigram函数进行排序操作
						cout << "已成功排序" << endl;
						SaveProgramDataToFile(head); //将排好序的数据保存至文件
						PrintAll(head);
					}
					else
					{
						cout << "请新建数据在使用此功能..." << endl;
					}
					break;
				case '3':Ch = Menu3();       //输入为'3'，即总分排序，调用Menu3函数显示相应二级菜单并记录数据输入的信息
					if (head != NULL)
					{
						SortByTP(head, Ch);  //调用SortByTP函数，进行排序操作
						SaveTPScoreToFile(head); //将排好序的数据保存至文件
						cout << "已成功排序" << endl;
						PrintAll(head);
						
					}
					else
					{
						cout << "请新建数据在使用此功能..." << endl;
					}
				}
				if (ch == '4')        //输入为'4'，返回上一级菜单
					break;
		}
			break;
		case '6':                     //输入为'6'，即查询
			while (true)				//一致循环，直至break
			{
				Ch = Menu4();         //调用Menu4函数，显示相应二级菜单，保存用户输入的数据
				switch (Ch)          //根据用户输入的数据进行功能选择
				{
				case '1':cout << "请输入需要查找的学号：";      //输入为'1',即进行学号查找
					cin >> S;
					J=FindStuID(head, S);     //调用FindStuID函数进行查找
					if (!J)					//如果没查找到相应节点
					{
						cout << "没有查找到相关信息！" << endl;
					}
					break;
				case '2':cout << "请输入需要查找的姓名：";      //输入为'2',即通过姓名查找
					cin >> S;
					J = FindByName(head, S);    //调用FindByName函数进行查找
					if (!J)						//若没有查找到相关函数
					{
						cout << "没有查找到相关信息！" << endl;
					}
					break;
				case '3':cout << "请输入数学成绩标准分:";   //输入为'3'，即查找符合条件的学生及满足的学生数量
					cin >> Num;
					J = FindByMathScore(head, Num);        //调用DindByMathScore函数进行查找
					if (!J)									//若没有查找到，打印错误信息
					{
						cout << "没有查找到相关信息！" << endl;
					}
					break;
				case '4':cout << "请输入程序设计成绩标准分:";  //输入为'4'，查找程序设计成绩符合条件的学生及其数量
					cin >> Num;
					J = FindByProgramScore(head, Num);        //调用FindByProgrameScore函数进行查找
					if (!J)
					{
						cout << "没有查找到相关信息！" << endl;
					}
					break;
				case '5':cout << "请输入总分标准分：";			//输入为'5'，查找程序总分成绩符合条件的学生及其数量
					cin >> Num;
					J = FindByTP(head, Num);					//调用FindByTP函数进行查找
					if (!J)
					{
						cout << "没有查找到相关信息！" << endl;
					}
				}
				if (Ch == '6')					//输入为'6'，break
				{
					break;
				}
			}
		case '7':
			break;
		default:cout << "请正确输入！" <<'\a'<< endl;
		}
		if (Ch == '7')
			break;
	}
}

//将总分排名保存至文件
void SaveTPScoreToFile(Stu * head)   //函数入口，为链表的头结点指针
{
	int Num = 1;				//记录名词整形变量Num;
	ofstream OutFile;				//定义输出文件流OutFile
	OutFile.open("TPScore.txt");		 //打开TPScore.txt文件
	OutFile << "排名	" << "学号		姓名		数学成绩	程序设计	总分" << endl;
	while (head)			//利用循环将已排好序的链表中的信息保存至文件
	{
		OutFile <<" "<< Num << "	" << head->StuID << "		" << head->Name << "		" << head->MathScore << "		" << head->ProgramScore << "		" << head->TP << endl;
		head = head->next;		//顺着链表向下走
		Num++;			//名次变量自加
	}
	OutFile.close();			//写入完毕，关闭文件
	cout << "已将排名保存至  TPScore.txt  文件" << endl;
}

//将程序设计程序排保存至文件
void SaveProgramDataToFile(Stu * head)		//函数入口，参数为链表首指针地址
{
	int Num = 1;			//记录名词整形变量Num;
	ofstream OutFile;			//定义输出文件流OutFile
	OutFile.open("cxsj.txt");	//打开cxsj.txt文件
	OutFile << "排名	" << "学号		姓名		数学成绩	程序设计	总分" << endl;
	while (head)			//利用循环将已排好序的链表中的信息保存至文件
	{
		OutFile <<" "<< Num << "	" << head->StuID << "		" << head->Name << "		" << head->MathScore << "		" << head->ProgramScore << "		" << head->TP << endl;
		head = head->next;		//顺着链表向下走
		Num++;			//名次变量自加
	}
	OutFile.close();		//写入完毕，关闭文件
	cout << "已将排名保存至  cxsj.txt  文件" << endl;
}

//将数学成绩排名保存至文件
void SaveMathDataToFile(Stu * head)  //函数入口，参数为链表首指针地址
{
	int Num = 1;			//记录名词整形变量Num;
	ofstream OutFile;	//定义输出文件流OutFile
	OutFile.open("sxcj.txt");		//打开sxsj.txt文件
	OutFile <<"排名	"<< "学号		姓名		数学成绩	程序设计	总分" << endl;
	while (head)		//利用循环将已排好序的链表中的信息保存至文件
	{
		OutFile <<" "<<Num<<"	"<< head->StuID << "		" << head->Name << "		" << head->MathScore << "		" << head->ProgramScore << "		" << head->TP << endl;
		head = head->next;		//顺着链表向下走
		Num++;		//名次变量自加
	}
	OutFile.close();		//写入完毕，关闭文件
	cout << "已将排名保存至  sxcj.txt  文件" << endl;
}

//通过序号删除
Stu * DeleteBySerial(Stu * head)		//函数入口，参数为链表首指针地址
{
	int Num = 0;
	Stu * Current = head;			//定义Stu类型Current指针变量，记录当前节点地址
	if (head != NULL)				 //判断链表是否为空（即判断是否有信息存在）
	{
		cout << "序号	";
		PrintMenu();			 //通过此语句，调用PrintMenu()函数，显示数据菜单
		while (Current)			//通过while语句控制
		{
			cout <<" "<< Num+1<<"	";		//输出序号
			PrintOne(Current);			//调用PrintOne函数，输出当前节点拥有的所有数据
			Num++;				//序号自加
			Current = Current->next;   //顺着链表向下走
		}
		cout << "请输入需要删除的序号：";
		int num;			//定义一个整形变量num存储用户输入数据
		cin >> num;			//用户输入数据
		Stu * p = FindBySerial(head, num);			//通过调用FindBySerial函数查找满足条件的指针
		if (p)				 //判断是否查找到相关数据
		{
			PrintMenu();
			PrintOne(p);
			cout << "确定删除？（Y or N）";
			char Ch;
		Point1:cin >> Ch;			//用户输入数据（Point1标记点，当用户输入有误时重新返回至此标记点重新输入）
			if (Ch != 'Y' && Ch != 'y' && Ch != 'N' && Ch != 'n')		//判断输入是否符合要求
			{
				cout << "输入有误，请重新输入：";
				goto Point1;			//不满足，重新输入
			}
			if (Ch == 'Y' || Ch == 'y')			//判断是否需要删除
			{
				if (p == head)			//当需要删除的数据位头结点
				{
					head = head->next;		//将头结点向下移动
					head->primer = head->primer->primer;	//将目前的头结点与链表的尾节点相连接
					delete p;				//删除查找到的节点
					p = NULL;
					cout << "已成功删除！" << endl;
				}
				else
				{
					Stu * Cur = p;			//记录下当前节点
					p->primer->next = p->next;//将当前节点的下一节点和当前节点的上一节点相连接
					if (p->next != NULL)		//当删除的不是末节点
					{
						p->next->primer = p->primer;
					}
					else   //当删除的是末节点
					{
						head->primer = p->primer;		//将头结点指向当前节点的前一节点
					}
					delete Cur;			 //释放当前节点占用的内存	
					Cur = NULL;
					cout << "已成功删除！" << endl;
				}
			}
		}
		else      
		{
			cout << "没找到满足要求的数据..." << endl;
		}
	}
	else    //当删除的是末节点
	{
		cout << "没有信息存在！" << endl;
	}
	return head;
}

//由序号查找并返回指针
Stu * FindBySerial(Stu * head, int Num)		//函数入口参数为链表首地址和用户输入的序号值
{
	int num = 1;			//定义一个整形变量，做哨兵
	while (head)			//while控制，直至head=NULL
	{
		if (num == Num)		 //判断是否应经到了需要寻找节点的位置
		{
			return head;	//返回查找到节点的地址
		}
		head = head->next;	 //顺着链表往下走
		num++;			//哨兵自加
	}
	return head;		  //返回head=NULL
}

//通过姓名查找删除数据
Stu * FindByNameAndDelete(Stu * head, string name)   //函数入口，链表首地址，用户输入的数据：学生姓名
{
	while (head)  //利用循环结构在链表上操作
	{
		if (head->Name == name)  //判断节点里存储的姓名是否与用户输入的数据相同
			return head;        //若相同，返回此节点的地址
		head = head->next;      //不满足，继续往下走
	}
	return head;         //没查找到，返回head=NULL
}

//二级菜单
char Menu5()
{
	cout << "******************************************" << endl           //利用C++标准库函数进行输出
		<< "*               二级菜单                 *" << endl
		<< "*          1、通过查找学号删除           *" << endl
		<< "*          2、通过查找姓名删除           *" << endl
		<< "*          3、查看所有数据序号删除       *" << endl
		<< "*          4、返回主菜单                 *" << endl
		<< "******************************************" << endl
		<< "请输入你的选择：" << endl;
	char Ch;				//定义一个字符类型，用于存储用户输入的数据
	Point:cin >> Ch;        //用户输入数据（Point用于用于当用户输入数据不合法时跳转到此点重新输入）
	if (Ch<'1' || Ch>'4')  //判断数据的合法性
	{
		cout << "输入有误，请重新输入：";
		goto Point;        //不合法，重新输入
	}
	return Ch;           //返回用户输入的数据
}

//总分查询
bool FindByTP(Stu * head, double TP)  //函数入口参数为链表的首地址和用户输入的标准成绩
{
	bool Judge = false;           //定义一个bool类型哨兵初始值为false
	int Num = 0;				//定义int类型数据，用于记录满足要求的学生个数
	while (head)				//利用while在链表上进行操作
	{
		if (head->TP > TP || head->TP == TP) //判断是否符合要求
		{
			Num++;                  //满足要求，Num自加
			if (Num == 1)       //当Num=1,调用显示横菜单函数，显示横菜单
			{
				PrintMenu();
			}
			PrintOne(head);  //打印当前节点信息
			Judge = true;   //将哨兵赋值为true
		}
		head = head->next;  //链表向下走
	}
	if (Judge == true)     //当哨兵为true,显示Num数据
	{
		cout << "共有【" << Num << "】名学生达到此要求！" << endl;
	}
	return Judge;       //将哨兵值返回，用于其他操作
}
//程序设计成绩查询
bool FindByProgramScore(Stu * head, double ProgramScore)		//函数入口参数为链表的首地址和用户输入的标准成绩
{
	bool Judge = false;				//定义一个bool类型哨兵初始值为false
	int Num = 0;				//定义int类型数据，用于记录满足要求的学生个数
	while (head)				//利用while在链表上进行操作
	{
		if (head->ProgramScore == ProgramScore || head->ProgramScore > ProgramScore)		//判断是否符合要求
		{
			Num++;		  //满足要求，Num自加
			if (Num == 1)			//当Num=1,调用显示横菜单函数，显示横菜单
			{
				PrintMenu();
			}
			PrintOne(head);			 //打印当前节点信息
			Judge = true;			//将哨兵赋值为true
		}
		head = head->next;				//链表向下走
	}
	if (Judge == true)				//当哨兵为true,显示Num数据
	{
		cout << "共有【" << Num << "】名学生达到此要求！" << endl;
	}
	return Judge;				 //将哨兵值返回，用于其他操作
}

//数学成绩查询
bool FindByMathScore(Stu * head, double MathScore)
{
	bool Judge = false;
	int Num = 0;
	while (head)
	{
		if (head->MathScore == MathScore || head->MathScore > MathScore)
		{
			Num++;
			if (Num == 1)
			{
				PrintMenu();
			}
			PrintOne(head);
			Judge = true;
		}
		head = head->next;
	}
	if (Judge == true)
	{
		cout << "共有【" << Num << "】名学生达到此要求！" << endl;
	}
	return Judge;
}

//姓名查找函数
bool FindByName(Stu * head, string name)   //函数入口参数为链表的首地址以及用户输入的学生姓名
{
	bool Judge = false;             //定义bool型数据，用于做哨兵
	int Num = 0;
	while (head)                  //用while语句在链表上操作
	{
		if (head->Name == name)  //判断节点数据是否满足用户要求
		{
			Num++;
			if (Num == 1)
			{
				PrintMenu();
			}
			PrintOne(head);       //调用PrintOne函数输出当前节点的数据
			Judge = true;
		}
		head = head->next;        //顺着节点向下走
	}
	return Judge;
}
//学号查找函数
bool FindStuID(Stu * head, string ID)
{
	int Num = 0;
	bool Judge = false;
	while (head)
	{
		if (head->StuID == ID)
		{
			Num++;
			if (Num == 1)
			{
				PrintMenu();
			}
			PrintOne(head);
			Judge = true;
		}
		head = head->next;
	}
	return Judge;
}

//二级菜单
char Menu4()
{
	char Ch;
	cout << "**************************************************" << endl
		<< "*                  二级菜单                      *" << endl
		<< "*                 1、学号查询                    *" << endl
		<< "*                 2、姓名查询                    *" << endl
		<< "*                 3、数学成绩查询                *" << endl
		<< "*                 4、程序设计成绩查询            *" << endl
		<< "*                 5、总分查询                    *" << endl
		<< "*                 6、返回主菜单                  *" << endl
		<< "**************************************************" << endl
		<< "请输入你的选择:";
	Point:cin >> Ch;
	if (Ch<'1' || Ch>'6')
	{
		cout << "输入有误，请重新输入：";
		goto Point;
	}
	return Ch;
}

//三级菜单
char Menu3()
{
	char Ch;
	cout << "**************************" << endl
		<< "*       三级菜单         *" << endl
		<< "*     1、降序排序        *" << endl
		<< "*     2、升序排序        *" << endl
		<< "**************************" << endl
		<< "请输入你的选择：" << endl;
	Point:cin >> Ch;
	if (Ch<'1' || Ch>'2')
	{
		cout << "输入数据有误，请重新输入：";
		goto Point;
	}
	return Ch;
}

//通过总分升降排序
void SortByTP(Stu *head, char Ch)        //函数入口为链表的首地址和字符类型（用于判断升序或降序）
{
	Stu * Cur = head, *Guard;            //定义Cur指针记录当前节点，Guard指针用于记录保存查找到的节点指针
	while (Cur)                         //Cur不为空，继续执行
	{
		if (Ch == '1')                 //若Ch=='1'，则执行降序排序
		{
			Guard = FindMax2(Cur);     //调用查找TP数据最大的节点
		}
		else                         //进行升序排序
		{
			Guard = FindMin2(Cur);   //调用查找TP数据最小的节点
		}
		if (Guard != Cur)             //若当前指针数据与寻找到满足要求的指针数据不同时，交换两指针中的数据
		{
			SwaP(Guard, Cur);        //数据交换函数调用
		}
		head = head->next;           //往链表下方走
		Cur = head;                   //记录下当前的节点地址
	}
}

//通过总分查找最小及其指针
Stu * FindMin2(Stu * p)        //入口参数为链表中的一个节点的地址
{
	Stu * Guard = p;        //定义一个指针Guard用于记录最小TP节点的地址
	while (p)                 //若链表微循环到链表尾，则继续往下
	{
		if (Guard->TP > p->TP)       //当满足条件的时候，将Guard赋值为当前节点的地址
		{
			Guard = p;
		}
		p = p->next;       //往链表下走
	}
	return Guard;         //返回查找到的节点的地址
}

//通过总分查找最大及其指针
Stu * FindMax2(Stu * p)
{
	Stu * Guard = p;
	while (p)
	{
		if (Guard->TP < p->TP)
		{
			Guard = p;
		}
		p = p->next;
	}
	return Guard;
}
//通过程序设计升级升降序排序
void SortByProgram(Stu * head, char Ch)
{
	Stu * Cur = head, *Guard;
	while (Cur)
	{
		if (Ch == '1')
		{
			Guard = FindMax1(Cur);
		}
		else
		{
			Guard = FindMin1(Cur);
		}
		if (Guard != Cur)
		{
			SwaP(Guard, Cur);
		}
		head = head->next;
		Cur = head;
	}
}

//数据交换函数
void SwaP(Stu * Guard, Stu * Cur)        //函数入口参数为两个指针
{
	Swap(Guard->MathScore, Cur->MathScore);  //调用Swap函数交换MathScore数据
	Swap(Guard->Name, Cur->Name);            //调用Swap函数交换Name数据
	Swap(Guard->ProgramScore, Cur->ProgramScore);  //调用Swap函数交换ProgramScore数据
	Swap(Guard->StuID, Cur->StuID);         //调用Swap函数交换StuID数据
	Swap(Guard->TP, Cur->TP);              //调用Swap函数交换总分TP数据
}

//通过程序设计成绩寻早最小及其指针
Stu * FindMin1(Stu * p)
{
	Stu * Guard = p;
	while (p)
	{
		if (Guard->ProgramScore > p->ProgramScore)
		{
			Guard = p;
		}
		p = p->next;
	}
	return Guard;
}


//通过程序设计成绩寻早最小及其指针
Stu * FindMax1(Stu * p)
{
	Stu * Guard = p;
	while (p)
	{
		if (Guard->ProgramScore < p->ProgramScore)
		{
			Guard = p;
		}
		p = p->next;
	}
	return Guard;
}

//通过数学成绩升序和降序排序
void SortByMath(Stu * head, char Ch)
{
	Stu * Cur = head, *Guard;
	while (Cur)
	{
		if (Ch == '1')
		{
			Guard = FindMax(Cur);
		}
		else
		{
			Guard = FindMin(Cur);
		}
		if (Guard != Cur)
		{
			SwaP(Guard, Cur);
		}
		head = head->next;
		Cur = head;
	}
}

//通过数学成绩寻找最小及其指针；
Stu * FindMin(Stu * p)
{
	Stu * Guard = p;
	while (p)
	{
		if (Guard->MathScore > p->MathScore)
		{
			Guard = p;
		}
		p = p->next;
	}
	return Guard;
}

//通过数学成绩寻早最大及其指针；
Stu * FindMax(Stu * p)
{
	Stu * Guard = p;
	while (p)
	{
		if (Guard->MathScore < p->MathScore)
		{
			Guard = p;
		}
		p = p->next;
	}
	return Guard;
}

//二级菜单二
char Menu2()
{
	char Ch;
	cout << "***********************************" << endl
		<< "*            二级菜单             *" << endl
		<< "*          1、数学成绩排序        *" << endl
		<< "*          2、程序设计排序        *" << endl
		<< "*          3、总分排序            *" << endl
		<< "*          4、返回主菜单          *" << endl
		<< "***********************************" << endl
		<< "请输入你的选择：";
	Point:cin >> Ch;
	if (Ch < '1' || Ch>'4')
	{
		cout << "输入数据有误，请重新输入:";
		goto Point;
	}
	return Ch;
}

//衔接两个链表
void AddLink(Stu * head, Stu * p)     //入口参数为一个链表的尾节点指针和另一个链表的首地址
{
	Stu * Cur = head->primer;         //定义一个指针记录一个链表的尾节点
	Cur->next = p;					  //将两个链表进行连接
	head->primer = p->primer;         //形成一个环
	p->primer = Cur;                  //前指针连接

}


//将数据保存到旧数据文件的末尾
void SaveDataToFileEnd(Stu * head)
{
	ofstream OutFile("students.txt", ofstream::out | ofstream::app);    //打开students.txt文件，并将文件流指向文件末
	while (head)        //利用循环将链表中的信息保存至文件
	{
		OutFile << head->StuID << "	" << head->Name << "	" << head->MathScore << "	" << head->ProgramScore << "	" << head->TP << endl;
		head = head->next;   //将链表往下调
	}
}

//清楚所有数据函数
void DeleteData(Stu * head)   //链表的首地址
{
	Stu * Cur;     //定义指针记录当前节点的地址
	while (head)   //利用循环操作
	{
		Cur = head;    //将目前的节点的地址进行记录
		head = head->next;  //往链表的下一节点
		delete Cur;    //删除目前节点
	}
}

//二级菜单一
char Menu1()
{
	cout << "********************************************"<<endl
	<< "*			" << "二级菜单" <<"           *"<< endl
		<< "*	  1、清除所有数据数据创建新数据    *" << endl
		<< "*	  2、在旧数据后添加新数据          *" << endl
		<< "*	  3、返回上一级                    *" << endl
		<< "********************************************" << endl
		<< "请输入你的选择：";
	char Ch;
	Point:cin >> Ch;
	if (Ch<'1' || Ch>'3')
	{
		cout << "输入数据有误，请重新输入！";
		goto Point;
	}
	return Ch;
}

//主菜单显示函数
char Menu()
{
	cout << "*************************************" << endl
		<< "*              主菜单               *" << endl
		<< "*           1、新建数据             *" << endl
		<< "*           2、添加数据             *" << endl
		<< "*           3、删除数据             *" << endl
		<< "*           4、查看数据             *" << endl
		<< "*           5、  排序               *" << endl
		<< "*           6、  查询               *" << endl
		<< "*           7、  退出               *" << endl
		<< "*************************************" << endl
		<< "请输入你的选择：";
	char ch;
	cin >> ch;
	return ch;
}

//内存申请函数；
inline Stu *ApplyRam()
{
	Stu * Current = new Stu;                //利用c++标准向系统申请内存
	Current->primer = Current->next = NULL;      //将指针赋值为空，防止乱指的现象出现；
	return Current;                       //返回申请好的内存地址
}


//建立链表函数；
Stu * BuildLink(Stu * Head)
{
	Stu * head = ApplyRam(), *Current = head, *CurrentNew = NULL;   //定义三个指针，并申请一个内存空间并赋值给head 和 Current，一个CurrentNew赋值为空
	int Judge = true;          //定义一个哨兵
	Judge = DataInput(Head, head);   //调用输入信息函数，若返回为false，则不建立链表
	if (!Judge)          //若果返回为false，则释放申请的内存
	{
		delete head;
		head = Current = NULL;
		return head;      //返回上一函数
	}
	CurrentNew = ApplyRam();  //调用内存申请函数
	Judge = DataInput(head, CurrentNew);  //输入数据函数调用
	if (!Judge)
	{
		delete CurrentNew;    //若返回空则释放申请的内存
		CurrentNew =NULL;
	}
	while (Judge)        //利用循环建立链表，直至Judge为false
	{
		Current->next = CurrentNew;    //连接两节点
		CurrentNew->primer = Current;
		Current = CurrentNew;
		CurrentNew = ApplyRam();
		Judge = DataInput(head, CurrentNew);
	}
	delete CurrentNew;    //删除最后申请的一个节点
	head->primer = Current;   //将头结点和末节点相连
	return head;  //返回首地址

}

//数据输入并计算总分函数；
int DataInput(Stu * head, Stu * p)    //函数入口为链表的首地址和一个节点的地址
{
	cout << "请输入此学生学号：";
	Stu * P = NULL;                  //申请一个指针类型，注意是大写P,用于用户输入的学号在数据里已经有的时候进行记录
	Point:cin >> p->StuID;           //向已经申请好的内存输入学号（定义了一个点，用于有相同信息的时候重新建立）
	if (p->StuID == "n" || p->StuID == "N")     //如果输入为‘n’ 或 'N'时，返回false，不在建立和输入信息。
	{
		return false;
	}
	else
	{
		P = FindCommomStuID(head, p);        //调用寻找相同学号函数，返回有相同学号的节点
		if (!P)                      //如果没有相同的学号的节点，则输入信息
		{
			cout << "请输入此学生姓名：";
			cin >> p->Name;
			cout << "请输入此学生数学成绩：";
			cin >> p->MathScore;
			cout << "请输入此学生程序设计成绩：";
			cin >> p->ProgramScore;
			p->TP = p->MathScore + p->ProgramScore;
			return true;
		}
		else                            //若存在相同的信息的节点，则打印错误信息，并输出相同信息节点的信息
		{
			cout << "已经存在此ID的学生：" << endl;
			PrintMenu();
			PrintOne(P);
			cout << "请确保数据输入正确，请重新建立此信息：";
			goto Point;                 //重新输入
		}
	}
}

//打印信息函数
void PrintAll(Stu * p)     //参数入口为一个链表的首地址
{
	if (p != NULL)    //当第一个节点不为空输出以下信息
	{
		cout << "学号		姓名		数学成绩	程序设计	总分" << endl;
	}
	else         //否则打印错误信息
	{
		cout << "没有信息存在！";
	}
	while (p)       //将链表中的数据进行输出
	{
		cout << " "<<p->StuID << "		" << p->Name << "		  " << p->MathScore << "		   " << p->ProgramScore << "		 " << p->TP << endl;
		p = p->next;  //走向链表下一个节点
	}
}

void PrintOne(Stu * p)
{
	if (p)         //当p不为空，输出次内存中的数据
	{
		cout << " " << p->StuID << "		" << p->Name << "		  " << p->MathScore << "		   " << p->ProgramScore << "		 " << p->TP << endl;
	}
}

//打印菜单栏
void PrintMenu()
{
	cout << "学号		姓名		数学成绩	程序设计	总分" << endl;
}

//将内存中的数据保存到文件students.txt
bool SaveDataToFile(Stu * head)
{
	ofstream OutFile;            //定义一个文件流
	OutFile.open("students.txt");   //打开students.txt文件
	while (head)                //只要链表不为空，则向文件里保存数据
	{
		OutFile << head->StuID << "	" << head->Name << "	" << head->MathScore << "	" << head->ProgramScore << "	" << head->TP << endl;
		head = head->next;   //走向链表下一节点
	}
	OutFile.close();      //关闭文件
	return true;
}

//从文件读入数据
Stu * ReadDataFromFile()
{
	Stu * head = NULL, *Cur = NULL, *Cur1 = NULL;      //定义三个指针，用于存储头结点，目前节点，新申请节点
	ifstream InFile;            //定义输入文件流
	InFile.open("students.txt");     //打开students.txt文件
	while (InFile)               //只要文件流未到文件末，继续申请内存将数据输入内存
	{
		if (head == NULL)           //当头结点为空时，申请一个内存作为头节点
		{
			head = ApplyRam();
			InFile >> head->StuID>>head->Name>> head->MathScore >> head->ProgramScore >> head->TP;
			Cur = head;           //将目前节点指向头结点
		}
		else                    //当头结点不为空
		{
			Cur1 = ApplyRam();   //记录申请的节点
			InFile >> Cur1->StuID>>Cur1->Name>>Cur1->MathScore >> Cur1->ProgramScore >> Cur1->TP;//将文件输入新申请的内存
			Cur->next = Cur1;    //节点的连接
			Cur1->primer = Cur;
			Cur = Cur1;
		}
	}
	head->primer = Cur->primer; //将新建立好的链表首位相连形成环
	Cur->primer->next = NULL;
	delete Cur;                 //由于文件中的回车，所以会多申请一个节点，需要删除
	InFile.close();            //关闭文件
	return head;                //返回头节点地址
}
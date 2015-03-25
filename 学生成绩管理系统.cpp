#include<iostream>
#include<string>
#include<fstream>


using namespace std;


typedef struct student
{
	string StuID;    //����ѧ��ѧ�ţ�
	string Name;     //ѧ��������
	double MathScore;//ѧ����ѧ�ɼ���
	double ProgramScore;//������Ƴɼ���
	double TP;       //�ܷ֣�
	struct student * primer;//��ȡ��һ�ڵ�ĵ�ַ��
	struct student * next;  //��ȡ��һ�ڵ�ĵ�ַ��
}Stu;



//������������
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
Stu * FindCommomStuID(Stu * head, Stu * p)   //�����������Ϊ������׵�ַ��һ���ڵ�ĵ�ַ
{
	while (head)           //Ѱ�������е�����
	{
		if (head->StuID == p->StuID)  //���ҵ���ͬ�����ݣ��򷵻ش˽ڵ�ĵ�ַ
			return head;
		head = head->next;       //�����������һ�ڵ�
	}
	return NULL;         //û����ͬ�����ݣ���������Ϊ��
}


void main()
{
	system("color F1");                                       //����ϵͳ�����⣬�Դ��ڼ��������ɫ�����޸�
	cout << "��ӭʹ�óɼ�����ϵͳ" << endl;
	cout << "���ڴ��ļ���ȡ���ݣ����Ժ�..." << endl;
	Stu * head = NULL;                                        //��������ͷ����ֵΪ��
	ifstream InFile("students.txt");						  //�򿪡�student.txt���ļ�
	if (InFile)
	{
		head = ReadDataFromFile();                            //�ӡ�student.txt���ļ���ȡ����
		cout << "�ɹ����ļ��ж�ȡ���ݣ�" << endl;
	}
	else
	{
		cout << "δ�����ļ����ڣ����Ƚ����ļ�..." << endl;
	}
	Function(head);											 //����ѡ��������
	FreeRam(head);											 //�ͷ�ռ���ڴ�
	system("pause");
}

//�˳����򽫴��е����ݽ����ͷ�
void FreeRam(Stu * head)
{
	Stu * Cur;         //����һ��ָ�룬��¼��ǰָ��ָ���ڴ�ĵ�ַ
	while (head)      //��head��Ϊ�գ���һֱִ��delete���ͷ�ռ���ڴ�ռ䣬ֱ��Ϊ��
	{
		Cur = head;
		head = head->next;  //˳������������
		delete Cur;    //�ͷŵ�ǰ�ڵ�ռ�õ��ڴ�
	}
}

//ͨ��ѧ�Ų�ѯɾ��
Stu * FindByStuIDAndDelete(Stu * head, string StuID)   //���������ֵ��һ���������ͷ��㣬һ���Ǵ洢�������Ϣ��ѧ�ţ�
{
	while (head)        //ѭ������
	{
		if (head->StuID == StuID)    //�ж��Ƿ��������
			return head;         //�����ϣ��㷵������ڵ�ĵ�ַ
		head = head->next;        //����˳�����������ߣ�����Ѱ��
	}
	return head;             //û���ţ�����head(NULL)
}

//ѡ���ܺ���
void Function(Stu * head)
{
	char Ch;            //����һ��char�������ڼ�¼�û����������
	Stu * p = NULL;     //����һ��ָ��
	string S;            //����string����S,���ڴ洢�û����������
	bool J; 
	double Num;          //double����Num�����ڴ洢�û����������
	while (true)        //һֱѭ����ֱ�����ִ��break����
	{
		Ch = Menu();      //����Menu��������ʾһ���˵����������û���������ݲ�����Ch;
		switch (Ch)       //�����û���������ݽ��й���ѡ��
		{
		case '1':if (head != NULL)     //����wΪ��1�������������Ѿ�����֮ǰ������
				{
					 cout << '\a' << "Caution��������д��ھ�����!"<<endl;
					 char ch;    //������һ��char�����ַ������ڴ洢�û����������
					 while (true)  //һֱѭ����ֱ�����ִ��break����
					 {
						 ch = Menu1();  //����Menu1������������Ӧ�����˵���ʾ������¼�û����������
						 switch (ch)   //�����û���������ݽ���ѡ����
						 {
						 case '1':DeleteData(head);   //����Ϊ'1'ʱ����������ɾ������������ڴ����е����ݲ��ͷ�
							 head = NULL;    //��ͷָ�븳ֵΪ��
							 cout << "�ѳɹ�����������ݣ���ʼ����������..." << endl;
							 head = BuildLink(head);  //����BuildLink�������½����µ����ݣ�����
							 cout << "�ɹ����������ݣ�" << endl;
							 break;
						 case '2':cout << "����������Ҫ��ӵ���Ϣ��" << endl; //����Ϊ'2'ʱ��
							 p = BuildLink(head);   //�����½�һ������
							 SaveDataToFileEnd(p);  //����SaveDataToFileEnd�������������е����ݱ������ļ�ĩβ
							 AddLink(head, p);      //��֮ǰ���������½��������������
							 cout << "�ѳɹ������Ϣ" << endl;
							 break;
						 }
						 if (ch == '3')      //���Ϊ'3'���˳�ѭ��
							 break;
					 }
				}
				 else          //��������û�о�����
				 {
					 head = BuildLink(head);      //����BuildLink�������½����µ����ݣ�����
					 if (head != NULL)            //�����½�����
					 {
						 cout << "�ѳɹ��½����ݣ�"<<endl;
						 SaveDataToFile(head);    //���½������ݱ������ļ�
					 }
				 }
				 break;
		case '2':cout << "����������Ҫ��ӵ�����"<<endl;   //���������'2'
			p = BuildLink(head);                    //����BuildLink�����������µ�����
			SaveDataToFileEnd(p);                  //����SaveDataToFileEnd�������������е����ݱ������ļ�ĩβ
			AddLink(head, p);						//��֮ǰ���������½��������������
			cout << "�ѳɹ�������ݣ�" << endl;
			break;
		case '3':						//���������'3'
			while (true)              //һ��ѭ��
			{
				Ch = Menu5();         //����Menu5��������ʾ��Ӧ�����˵��������û����������
				switch (Ch)          //�����û���������ݽ���ѡ����
				{
				case '1':cout << "��������Ҫ���ҵ�ѧ�ţ�";
					cin >> S;           //��������
					p = FindByStuIDAndDelete(head, S);       //����FindByStuIDDelete�������в���
					if (p)            //���鵽��Ӧ�ڵ�
					{
						PrintMenu(); //����PrintMenu������ӡ��˵�
						PrintOne(p); //����PrintOne������ʾ��ǰ�ڵ�����
						if (p == head)  //������ҵ��Ľڵ���ͷ���
						{
							cout << "ȷ��ɾ��?(Y or N)";
						Point:cin >> Ch;
							if (Ch != 'Y' && Ch != 'y' && Ch != 'N' && Ch != 'n')
							{
								cout << "�����������������룺";
								goto Point;
							}
							if (Ch == 'Y' || Ch == 'y')       //����ɾ��
							{
								head = head->next;            //�������ͷ������
								head->primer = head->primer->primer;
								delete p;                   //ɾ�����ҵ��Ľڵ�
								p = NULL;
								cout << "�ѳɹ�ɾ����" << endl;
							}
						}
						else							//���ҵ��Ĳ���ͷ���
						{
							cout << "ȷ��ɾ��?(Y or N)";
						Point3:cin >> Ch;
							if (Ch != 'Y' && Ch != 'y' && Ch != 'N' && Ch != 'n')
							{
								cout << "�����������������룺";
								goto Point3;
							}
							if (Ch == 'Y' || Ch == 'y')     //ȷ��ɾ����ɾ�����ҵ��Ľڵ㣬����ǰ��ڵ�����
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
								cout << "�ѳɹ�ɾ����" << endl;
							}
						}
					}
					else   //û���ҵ���Ӧ�ڵ�
					{
						cout << "δ���ҵ������Ϣ��" << endl;
					}
					break;
				case '2':cout << "��������Ҫ���ҵ�������";      //�����������'2',��ͨ��������������ɾ��
					cin >> S;
					p = FindByNameAndDelete(head, S);            //ͨ������FindByNameAndDelete������������Ľڵ�
					if (p)									//��������������Ľڵ�
					{
						if (p == head)						//������ҵ��Ľڵ���ͷ���
						{
							PrintMenu();					//����PrintMenu������ӡ��˵�
							PrintOne(p);					//����PrintOne������ʾ��ǰ�ڵ�����
							cout << "ȷ��ɾ��?(Y or N)";
							Point1:cin >> Ch;
							if (Ch != 'Y' && Ch != 'y' && Ch != 'N' && Ch != 'n')
							{
								cout << "�����������������룺";
								goto Point1;
							}
							if (Ch == 'Y' || Ch == 'y')			//����ɾ��
							{
								head = head->next;				//�������ͷ������
								head->primer = head->primer->primer;
								delete p;						//ɾ�����ҵ��Ľڵ�
								p = NULL;
							}
						}
						else									//���ҵ��Ĳ���ͷ���
						{
							PrintMenu();						//����PrintMenu������ӡ��˵�
							PrintOne(p);						//����PrintOne������ʾ��ǰ�ڵ�����
							cout << "ȷ��ɾ��?(Y or N)";
						Point2:cin >> Ch;
							if (Ch != 'Y' && Ch != 'y' && Ch != 'N' && Ch != 'n')
							{
								cout << "�����������������룺";
								goto Point2;
							}
							if (Ch == 'Y' || Ch == 'y')				//����ɾ��
							{
								Stu * Cur = p;                     //���������ڵ�
								Cur->primer->next = p->next;
								if (p->next != NULL)              //��ɾ���Ĳ������һ���ڵ�
								{
									p->next->primer = Cur->primer;
								}
								else								//��ɾ���������һ�����
								{
									head->primer = Cur->primer;    //��ͷ�����ɾ��֮���ĩ�ڵ�����
								}
								delete Cur;                        //�ͷ��ڴ�ռ�
								Cur = p = NULL;
								cout << "�ѳɹ�ɾ����" << endl;
							}
						}
					}
					else							//��û�ҵ�����ӡ������Ϣ
					{
						cout << "δ���ҵ������Ϣ��" << endl;
					}
					break;
				case '3':head = DeleteBySerial(head);   //�������'3'����ͨ�����ɾ��������DeleteBySerial�������в���
					break;
				}
				SaveDataToFile(head);       //���޸Ĺ������������ļ�
				if (Ch == '4')              //������'4'��������ѭ��
				{
					break;
				}
			}
			break;
		case '4':PrintAll(head);              //�û�����'4'�����鿴�������ݺ���������PrintAll�������в���
			system("pause");				//��ͣ
			break;
		case '5':char ch;					//������Ϊ'5'��������
			while (true)                   //һֱѭ����ֱ��break����ѭ��
		{
				ch = Menu2();              //����Menu2������ʾ��Ӧ�����˵�������¼�û����������
				switch (ch)               //�����û���������ݽ���ѡ��
				{
				case '1':Ch = Menu3();     //����Ϊ'1'����ѧ�ɼ�����
					if (head != NULL)       //������Ϊ��
					{
						SortByMath(head, Ch);  //����SortByMath�����������������
						cout << "�ѳɹ�����" << endl;
						SaveMathDataToFile(head); //���ĺ�������ݱ������ļ�
						PrintAll(head);
					}
					else					//�����������ݣ���ӡ������Ϣ
					{
						cout << "���½�������ʹ�ô˹���..."<<endl;
					}
					break;
				case '2':Ch = Menu3();   //����Ϊ'2'������Menu3������ʾ��Ӧ�Ķ����˵�������¼�û����������
					if (head != NULL)			 //������Ϊ��
					{
						SortByProgram(head, Ch); //����SortByPrigram���������������
						cout << "�ѳɹ�����" << endl;
						SaveProgramDataToFile(head); //���ź�������ݱ������ļ�
						PrintAll(head);
					}
					else
					{
						cout << "���½�������ʹ�ô˹���..." << endl;
					}
					break;
				case '3':Ch = Menu3();       //����Ϊ'3'�����ܷ����򣬵���Menu3������ʾ��Ӧ�����˵�����¼�����������Ϣ
					if (head != NULL)
					{
						SortByTP(head, Ch);  //����SortByTP�����������������
						SaveTPScoreToFile(head); //���ź�������ݱ������ļ�
						cout << "�ѳɹ�����" << endl;
						PrintAll(head);
						
					}
					else
					{
						cout << "���½�������ʹ�ô˹���..." << endl;
					}
				}
				if (ch == '4')        //����Ϊ'4'��������һ���˵�
					break;
		}
			break;
		case '6':                     //����Ϊ'6'������ѯ
			while (true)				//һ��ѭ����ֱ��break
			{
				Ch = Menu4();         //����Menu4��������ʾ��Ӧ�����˵��������û����������
				switch (Ch)          //�����û���������ݽ��й���ѡ��
				{
				case '1':cout << "��������Ҫ���ҵ�ѧ�ţ�";      //����Ϊ'1',������ѧ�Ų���
					cin >> S;
					J=FindStuID(head, S);     //����FindStuID�������в���
					if (!J)					//���û���ҵ���Ӧ�ڵ�
					{
						cout << "û�в��ҵ������Ϣ��" << endl;
					}
					break;
				case '2':cout << "��������Ҫ���ҵ�������";      //����Ϊ'2',��ͨ����������
					cin >> S;
					J = FindByName(head, S);    //����FindByName�������в���
					if (!J)						//��û�в��ҵ���غ���
					{
						cout << "û�в��ҵ������Ϣ��" << endl;
					}
					break;
				case '3':cout << "��������ѧ�ɼ���׼��:";   //����Ϊ'3'�������ҷ���������ѧ���������ѧ������
					cin >> Num;
					J = FindByMathScore(head, Num);        //����DindByMathScore�������в���
					if (!J)									//��û�в��ҵ�����ӡ������Ϣ
					{
						cout << "û�в��ҵ������Ϣ��" << endl;
					}
					break;
				case '4':cout << "�����������Ƴɼ���׼��:";  //����Ϊ'4'�����ҳ�����Ƴɼ�����������ѧ����������
					cin >> Num;
					J = FindByProgramScore(head, Num);        //����FindByProgrameScore�������в���
					if (!J)
					{
						cout << "û�в��ҵ������Ϣ��" << endl;
					}
					break;
				case '5':cout << "�������ֱܷ�׼�֣�";			//����Ϊ'5'�����ҳ����ֳܷɼ�����������ѧ����������
					cin >> Num;
					J = FindByTP(head, Num);					//����FindByTP�������в���
					if (!J)
					{
						cout << "û�в��ҵ������Ϣ��" << endl;
					}
				}
				if (Ch == '6')					//����Ϊ'6'��break
				{
					break;
				}
			}
		case '7':
			break;
		default:cout << "����ȷ���룡" <<'\a'<< endl;
		}
		if (Ch == '7')
			break;
	}
}

//���ܷ������������ļ�
void SaveTPScoreToFile(Stu * head)   //������ڣ�Ϊ�����ͷ���ָ��
{
	int Num = 1;				//��¼�������α���Num;
	ofstream OutFile;				//��������ļ���OutFile
	OutFile.open("TPScore.txt");		 //��TPScore.txt�ļ�
	OutFile << "����	" << "ѧ��		����		��ѧ�ɼ�	�������	�ܷ�" << endl;
	while (head)			//����ѭ�������ź���������е���Ϣ�������ļ�
	{
		OutFile <<" "<< Num << "	" << head->StuID << "		" << head->Name << "		" << head->MathScore << "		" << head->ProgramScore << "		" << head->TP << endl;
		head = head->next;		//˳������������
		Num++;			//���α����Լ�
	}
	OutFile.close();			//д����ϣ��ر��ļ�
	cout << "�ѽ�����������  TPScore.txt  �ļ�" << endl;
}

//��������Ƴ����ű������ļ�
void SaveProgramDataToFile(Stu * head)		//������ڣ�����Ϊ������ָ���ַ
{
	int Num = 1;			//��¼�������α���Num;
	ofstream OutFile;			//��������ļ���OutFile
	OutFile.open("cxsj.txt");	//��cxsj.txt�ļ�
	OutFile << "����	" << "ѧ��		����		��ѧ�ɼ�	�������	�ܷ�" << endl;
	while (head)			//����ѭ�������ź���������е���Ϣ�������ļ�
	{
		OutFile <<" "<< Num << "	" << head->StuID << "		" << head->Name << "		" << head->MathScore << "		" << head->ProgramScore << "		" << head->TP << endl;
		head = head->next;		//˳������������
		Num++;			//���α����Լ�
	}
	OutFile.close();		//д����ϣ��ر��ļ�
	cout << "�ѽ�����������  cxsj.txt  �ļ�" << endl;
}

//����ѧ�ɼ������������ļ�
void SaveMathDataToFile(Stu * head)  //������ڣ�����Ϊ������ָ���ַ
{
	int Num = 1;			//��¼�������α���Num;
	ofstream OutFile;	//��������ļ���OutFile
	OutFile.open("sxcj.txt");		//��sxsj.txt�ļ�
	OutFile <<"����	"<< "ѧ��		����		��ѧ�ɼ�	�������	�ܷ�" << endl;
	while (head)		//����ѭ�������ź���������е���Ϣ�������ļ�
	{
		OutFile <<" "<<Num<<"	"<< head->StuID << "		" << head->Name << "		" << head->MathScore << "		" << head->ProgramScore << "		" << head->TP << endl;
		head = head->next;		//˳������������
		Num++;		//���α����Լ�
	}
	OutFile.close();		//д����ϣ��ر��ļ�
	cout << "�ѽ�����������  sxcj.txt  �ļ�" << endl;
}

//ͨ�����ɾ��
Stu * DeleteBySerial(Stu * head)		//������ڣ�����Ϊ������ָ���ַ
{
	int Num = 0;
	Stu * Current = head;			//����Stu����Currentָ���������¼��ǰ�ڵ��ַ
	if (head != NULL)				 //�ж������Ƿ�Ϊ�գ����ж��Ƿ�����Ϣ���ڣ�
	{
		cout << "���	";
		PrintMenu();			 //ͨ������䣬����PrintMenu()��������ʾ���ݲ˵�
		while (Current)			//ͨ��while������
		{
			cout <<" "<< Num+1<<"	";		//������
			PrintOne(Current);			//����PrintOne�����������ǰ�ڵ�ӵ�е���������
			Num++;				//����Լ�
			Current = Current->next;   //˳������������
		}
		cout << "��������Ҫɾ������ţ�";
		int num;			//����һ�����α���num�洢�û���������
		cin >> num;			//�û���������
		Stu * p = FindBySerial(head, num);			//ͨ������FindBySerial������������������ָ��
		if (p)				 //�ж��Ƿ���ҵ��������
		{
			PrintMenu();
			PrintOne(p);
			cout << "ȷ��ɾ������Y or N��";
			char Ch;
		Point1:cin >> Ch;			//�û��������ݣ�Point1��ǵ㣬���û���������ʱ���·������˱�ǵ��������룩
			if (Ch != 'Y' && Ch != 'y' && Ch != 'N' && Ch != 'n')		//�ж������Ƿ����Ҫ��
			{
				cout << "�����������������룺";
				goto Point1;			//�����㣬��������
			}
			if (Ch == 'Y' || Ch == 'y')			//�ж��Ƿ���Ҫɾ��
			{
				if (p == head)			//����Ҫɾ��������λͷ���
				{
					head = head->next;		//��ͷ��������ƶ�
					head->primer = head->primer->primer;	//��Ŀǰ��ͷ����������β�ڵ�������
					delete p;				//ɾ�����ҵ��Ľڵ�
					p = NULL;
					cout << "�ѳɹ�ɾ����" << endl;
				}
				else
				{
					Stu * Cur = p;			//��¼�µ�ǰ�ڵ�
					p->primer->next = p->next;//����ǰ�ڵ����һ�ڵ�͵�ǰ�ڵ����һ�ڵ�������
					if (p->next != NULL)		//��ɾ���Ĳ���ĩ�ڵ�
					{
						p->next->primer = p->primer;
					}
					else   //��ɾ������ĩ�ڵ�
					{
						head->primer = p->primer;		//��ͷ���ָ��ǰ�ڵ��ǰһ�ڵ�
					}
					delete Cur;			 //�ͷŵ�ǰ�ڵ�ռ�õ��ڴ�	
					Cur = NULL;
					cout << "�ѳɹ�ɾ����" << endl;
				}
			}
		}
		else      
		{
			cout << "û�ҵ�����Ҫ�������..." << endl;
		}
	}
	else    //��ɾ������ĩ�ڵ�
	{
		cout << "û����Ϣ���ڣ�" << endl;
	}
	return head;
}

//����Ų��Ҳ�����ָ��
Stu * FindBySerial(Stu * head, int Num)		//������ڲ���Ϊ�����׵�ַ���û���������ֵ
{
	int num = 1;			//����һ�����α��������ڱ�
	while (head)			//while���ƣ�ֱ��head=NULL
	{
		if (num == Num)		 //�ж��Ƿ�Ӧ��������ҪѰ�ҽڵ��λ��
		{
			return head;	//���ز��ҵ��ڵ�ĵ�ַ
		}
		head = head->next;	 //˳������������
		num++;			//�ڱ��Լ�
	}
	return head;		  //����head=NULL
}

//ͨ����������ɾ������
Stu * FindByNameAndDelete(Stu * head, string name)   //������ڣ������׵�ַ���û���������ݣ�ѧ������
{
	while (head)  //����ѭ���ṹ�������ϲ���
	{
		if (head->Name == name)  //�жϽڵ���洢�������Ƿ����û������������ͬ
			return head;        //����ͬ�����ش˽ڵ�ĵ�ַ
		head = head->next;      //�����㣬����������
	}
	return head;         //û���ҵ�������head=NULL
}

//�����˵�
char Menu5()
{
	cout << "******************************************" << endl           //����C++��׼�⺯���������
		<< "*               �����˵�                 *" << endl
		<< "*          1��ͨ������ѧ��ɾ��           *" << endl
		<< "*          2��ͨ����������ɾ��           *" << endl
		<< "*          3���鿴�����������ɾ��       *" << endl
		<< "*          4���������˵�                 *" << endl
		<< "******************************************" << endl
		<< "���������ѡ��" << endl;
	char Ch;				//����һ���ַ����ͣ����ڴ洢�û����������
	Point:cin >> Ch;        //�û��������ݣ�Point�������ڵ��û��������ݲ��Ϸ�ʱ��ת���˵��������룩
	if (Ch<'1' || Ch>'4')  //�ж����ݵĺϷ���
	{
		cout << "�����������������룺";
		goto Point;        //���Ϸ�����������
	}
	return Ch;           //�����û����������
}

//�ֲܷ�ѯ
bool FindByTP(Stu * head, double TP)  //������ڲ���Ϊ������׵�ַ���û�����ı�׼�ɼ�
{
	bool Judge = false;           //����һ��bool�����ڱ���ʼֵΪfalse
	int Num = 0;				//����int�������ݣ����ڼ�¼����Ҫ���ѧ������
	while (head)				//����while�������Ͻ��в���
	{
		if (head->TP > TP || head->TP == TP) //�ж��Ƿ����Ҫ��
		{
			Num++;                  //����Ҫ��Num�Լ�
			if (Num == 1)       //��Num=1,������ʾ��˵���������ʾ��˵�
			{
				PrintMenu();
			}
			PrintOne(head);  //��ӡ��ǰ�ڵ���Ϣ
			Judge = true;   //���ڱ���ֵΪtrue
		}
		head = head->next;  //����������
	}
	if (Judge == true)     //���ڱ�Ϊtrue,��ʾNum����
	{
		cout << "���С�" << Num << "����ѧ���ﵽ��Ҫ��" << endl;
	}
	return Judge;       //���ڱ�ֵ���أ�������������
}
//������Ƴɼ���ѯ
bool FindByProgramScore(Stu * head, double ProgramScore)		//������ڲ���Ϊ������׵�ַ���û�����ı�׼�ɼ�
{
	bool Judge = false;				//����һ��bool�����ڱ���ʼֵΪfalse
	int Num = 0;				//����int�������ݣ����ڼ�¼����Ҫ���ѧ������
	while (head)				//����while�������Ͻ��в���
	{
		if (head->ProgramScore == ProgramScore || head->ProgramScore > ProgramScore)		//�ж��Ƿ����Ҫ��
		{
			Num++;		  //����Ҫ��Num�Լ�
			if (Num == 1)			//��Num=1,������ʾ��˵���������ʾ��˵�
			{
				PrintMenu();
			}
			PrintOne(head);			 //��ӡ��ǰ�ڵ���Ϣ
			Judge = true;			//���ڱ���ֵΪtrue
		}
		head = head->next;				//����������
	}
	if (Judge == true)				//���ڱ�Ϊtrue,��ʾNum����
	{
		cout << "���С�" << Num << "����ѧ���ﵽ��Ҫ��" << endl;
	}
	return Judge;				 //���ڱ�ֵ���أ�������������
}

//��ѧ�ɼ���ѯ
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
		cout << "���С�" << Num << "����ѧ���ﵽ��Ҫ��" << endl;
	}
	return Judge;
}

//�������Һ���
bool FindByName(Stu * head, string name)   //������ڲ���Ϊ������׵�ַ�Լ��û������ѧ������
{
	bool Judge = false;             //����bool�����ݣ��������ڱ�
	int Num = 0;
	while (head)                  //��while����������ϲ���
	{
		if (head->Name == name)  //�жϽڵ������Ƿ������û�Ҫ��
		{
			Num++;
			if (Num == 1)
			{
				PrintMenu();
			}
			PrintOne(head);       //����PrintOne���������ǰ�ڵ������
			Judge = true;
		}
		head = head->next;        //˳�Žڵ�������
	}
	return Judge;
}
//ѧ�Ų��Һ���
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

//�����˵�
char Menu4()
{
	char Ch;
	cout << "**************************************************" << endl
		<< "*                  �����˵�                      *" << endl
		<< "*                 1��ѧ�Ų�ѯ                    *" << endl
		<< "*                 2��������ѯ                    *" << endl
		<< "*                 3����ѧ�ɼ���ѯ                *" << endl
		<< "*                 4��������Ƴɼ���ѯ            *" << endl
		<< "*                 5���ֲܷ�ѯ                    *" << endl
		<< "*                 6���������˵�                  *" << endl
		<< "**************************************************" << endl
		<< "���������ѡ��:";
	Point:cin >> Ch;
	if (Ch<'1' || Ch>'6')
	{
		cout << "�����������������룺";
		goto Point;
	}
	return Ch;
}

//�����˵�
char Menu3()
{
	char Ch;
	cout << "**************************" << endl
		<< "*       �����˵�         *" << endl
		<< "*     1����������        *" << endl
		<< "*     2����������        *" << endl
		<< "**************************" << endl
		<< "���������ѡ��" << endl;
	Point:cin >> Ch;
	if (Ch<'1' || Ch>'2')
	{
		cout << "���������������������룺";
		goto Point;
	}
	return Ch;
}

//ͨ���ܷ���������
void SortByTP(Stu *head, char Ch)        //�������Ϊ������׵�ַ���ַ����ͣ������ж��������
{
	Stu * Cur = head, *Guard;            //����Curָ���¼��ǰ�ڵ㣬Guardָ�����ڼ�¼������ҵ��Ľڵ�ָ��
	while (Cur)                         //Cur��Ϊ�գ�����ִ��
	{
		if (Ch == '1')                 //��Ch=='1'����ִ�н�������
		{
			Guard = FindMax2(Cur);     //���ò���TP�������Ľڵ�
		}
		else                         //������������
		{
			Guard = FindMin2(Cur);   //���ò���TP������С�Ľڵ�
		}
		if (Guard != Cur)             //����ǰָ��������Ѱ�ҵ�����Ҫ���ָ�����ݲ�ͬʱ��������ָ���е�����
		{
			SwaP(Guard, Cur);        //���ݽ�����������
		}
		head = head->next;           //�������·���
		Cur = head;                   //��¼�µ�ǰ�Ľڵ��ַ
	}
}

//ͨ���ֲܷ�����С����ָ��
Stu * FindMin2(Stu * p)        //��ڲ���Ϊ�����е�һ���ڵ�ĵ�ַ
{
	Stu * Guard = p;        //����һ��ָ��Guard���ڼ�¼��СTP�ڵ�ĵ�ַ
	while (p)                 //������΢ѭ��������β�����������
	{
		if (Guard->TP > p->TP)       //������������ʱ�򣬽�Guard��ֵΪ��ǰ�ڵ�ĵ�ַ
		{
			Guard = p;
		}
		p = p->next;       //����������
	}
	return Guard;         //���ز��ҵ��Ľڵ�ĵ�ַ
}

//ͨ���ֲܷ��������ָ��
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
//ͨ�����������������������
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

//���ݽ�������
void SwaP(Stu * Guard, Stu * Cur)        //������ڲ���Ϊ����ָ��
{
	Swap(Guard->MathScore, Cur->MathScore);  //����Swap��������MathScore����
	Swap(Guard->Name, Cur->Name);            //����Swap��������Name����
	Swap(Guard->ProgramScore, Cur->ProgramScore);  //����Swap��������ProgramScore����
	Swap(Guard->StuID, Cur->StuID);         //����Swap��������StuID����
	Swap(Guard->TP, Cur->TP);              //����Swap���������ܷ�TP����
}

//ͨ��������Ƴɼ�Ѱ����С����ָ��
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


//ͨ��������Ƴɼ�Ѱ����С����ָ��
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

//ͨ����ѧ�ɼ�����ͽ�������
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

//ͨ����ѧ�ɼ�Ѱ����С����ָ�룻
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

//ͨ����ѧ�ɼ�Ѱ�������ָ�룻
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

//�����˵���
char Menu2()
{
	char Ch;
	cout << "***********************************" << endl
		<< "*            �����˵�             *" << endl
		<< "*          1����ѧ�ɼ�����        *" << endl
		<< "*          2�������������        *" << endl
		<< "*          3���ܷ�����            *" << endl
		<< "*          4���������˵�          *" << endl
		<< "***********************************" << endl
		<< "���������ѡ��";
	Point:cin >> Ch;
	if (Ch < '1' || Ch>'4')
	{
		cout << "����������������������:";
		goto Point;
	}
	return Ch;
}

//�ν���������
void AddLink(Stu * head, Stu * p)     //��ڲ���Ϊһ�������β�ڵ�ָ�����һ��������׵�ַ
{
	Stu * Cur = head->primer;         //����һ��ָ���¼һ�������β�ڵ�
	Cur->next = p;					  //�����������������
	head->primer = p->primer;         //�γ�һ����
	p->primer = Cur;                  //ǰָ������

}


//�����ݱ��浽�������ļ���ĩβ
void SaveDataToFileEnd(Stu * head)
{
	ofstream OutFile("students.txt", ofstream::out | ofstream::app);    //��students.txt�ļ��������ļ���ָ���ļ�ĩ
	while (head)        //����ѭ���������е���Ϣ�������ļ�
	{
		OutFile << head->StuID << "	" << head->Name << "	" << head->MathScore << "	" << head->ProgramScore << "	" << head->TP << endl;
		head = head->next;   //���������µ�
	}
}

//����������ݺ���
void DeleteData(Stu * head)   //������׵�ַ
{
	Stu * Cur;     //����ָ���¼��ǰ�ڵ�ĵ�ַ
	while (head)   //����ѭ������
	{
		Cur = head;    //��Ŀǰ�Ľڵ�ĵ�ַ���м�¼
		head = head->next;  //���������һ�ڵ�
		delete Cur;    //ɾ��Ŀǰ�ڵ�
	}
}

//�����˵�һ
char Menu1()
{
	cout << "********************************************"<<endl
	<< "*			" << "�����˵�" <<"           *"<< endl
		<< "*	  1����������������ݴ���������    *" << endl
		<< "*	  2���ھ����ݺ����������          *" << endl
		<< "*	  3��������һ��                    *" << endl
		<< "********************************************" << endl
		<< "���������ѡ��";
	char Ch;
	Point:cin >> Ch;
	if (Ch<'1' || Ch>'3')
	{
		cout << "���������������������룡";
		goto Point;
	}
	return Ch;
}

//���˵���ʾ����
char Menu()
{
	cout << "*************************************" << endl
		<< "*              ���˵�               *" << endl
		<< "*           1���½�����             *" << endl
		<< "*           2���������             *" << endl
		<< "*           3��ɾ������             *" << endl
		<< "*           4���鿴����             *" << endl
		<< "*           5��  ����               *" << endl
		<< "*           6��  ��ѯ               *" << endl
		<< "*           7��  �˳�               *" << endl
		<< "*************************************" << endl
		<< "���������ѡ��";
	char ch;
	cin >> ch;
	return ch;
}

//�ڴ����뺯����
inline Stu *ApplyRam()
{
	Stu * Current = new Stu;                //����c++��׼��ϵͳ�����ڴ�
	Current->primer = Current->next = NULL;      //��ָ�븳ֵΪ�գ���ֹ��ָ��������֣�
	return Current;                       //��������õ��ڴ��ַ
}


//������������
Stu * BuildLink(Stu * Head)
{
	Stu * head = ApplyRam(), *Current = head, *CurrentNew = NULL;   //��������ָ�룬������һ���ڴ�ռ䲢��ֵ��head �� Current��һ��CurrentNew��ֵΪ��
	int Judge = true;          //����һ���ڱ�
	Judge = DataInput(Head, head);   //����������Ϣ������������Ϊfalse���򲻽�������
	if (!Judge)          //��������Ϊfalse�����ͷ�������ڴ�
	{
		delete head;
		head = Current = NULL;
		return head;      //������һ����
	}
	CurrentNew = ApplyRam();  //�����ڴ����뺯��
	Judge = DataInput(head, CurrentNew);  //�������ݺ�������
	if (!Judge)
	{
		delete CurrentNew;    //�����ؿ����ͷ�������ڴ�
		CurrentNew =NULL;
	}
	while (Judge)        //����ѭ����������ֱ��JudgeΪfalse
	{
		Current->next = CurrentNew;    //�������ڵ�
		CurrentNew->primer = Current;
		Current = CurrentNew;
		CurrentNew = ApplyRam();
		Judge = DataInput(head, CurrentNew);
	}
	delete CurrentNew;    //ɾ����������һ���ڵ�
	head->primer = Current;   //��ͷ����ĩ�ڵ�����
	return head;  //�����׵�ַ

}

//�������벢�����ֺܷ�����
int DataInput(Stu * head, Stu * p)    //�������Ϊ������׵�ַ��һ���ڵ�ĵ�ַ
{
	cout << "�������ѧ��ѧ�ţ�";
	Stu * P = NULL;                  //����һ��ָ�����ͣ�ע���Ǵ�дP,�����û������ѧ�����������Ѿ��е�ʱ����м�¼
	Point:cin >> p->StuID;           //���Ѿ�����õ��ڴ�����ѧ�ţ�������һ���㣬��������ͬ��Ϣ��ʱ�����½�����
	if (p->StuID == "n" || p->StuID == "N")     //�������Ϊ��n�� �� 'N'ʱ������false�����ڽ�����������Ϣ��
	{
		return false;
	}
	else
	{
		P = FindCommomStuID(head, p);        //����Ѱ����ͬѧ�ź�������������ͬѧ�ŵĽڵ�
		if (!P)                      //���û����ͬ��ѧ�ŵĽڵ㣬��������Ϣ
		{
			cout << "�������ѧ��������";
			cin >> p->Name;
			cout << "�������ѧ����ѧ�ɼ���";
			cin >> p->MathScore;
			cout << "�������ѧ��������Ƴɼ���";
			cin >> p->ProgramScore;
			p->TP = p->MathScore + p->ProgramScore;
			return true;
		}
		else                            //��������ͬ����Ϣ�Ľڵ㣬���ӡ������Ϣ���������ͬ��Ϣ�ڵ����Ϣ
		{
			cout << "�Ѿ����ڴ�ID��ѧ����" << endl;
			PrintMenu();
			PrintOne(P);
			cout << "��ȷ������������ȷ�������½�������Ϣ��";
			goto Point;                 //��������
		}
	}
}

//��ӡ��Ϣ����
void PrintAll(Stu * p)     //�������Ϊһ��������׵�ַ
{
	if (p != NULL)    //����һ���ڵ㲻Ϊ�����������Ϣ
	{
		cout << "ѧ��		����		��ѧ�ɼ�	�������	�ܷ�" << endl;
	}
	else         //�����ӡ������Ϣ
	{
		cout << "û����Ϣ���ڣ�";
	}
	while (p)       //�������е����ݽ������
	{
		cout << " "<<p->StuID << "		" << p->Name << "		  " << p->MathScore << "		   " << p->ProgramScore << "		 " << p->TP << endl;
		p = p->next;  //����������һ���ڵ�
	}
}

void PrintOne(Stu * p)
{
	if (p)         //��p��Ϊ�գ�������ڴ��е�����
	{
		cout << " " << p->StuID << "		" << p->Name << "		  " << p->MathScore << "		   " << p->ProgramScore << "		 " << p->TP << endl;
	}
}

//��ӡ�˵���
void PrintMenu()
{
	cout << "ѧ��		����		��ѧ�ɼ�	�������	�ܷ�" << endl;
}

//���ڴ��е����ݱ��浽�ļ�students.txt
bool SaveDataToFile(Stu * head)
{
	ofstream OutFile;            //����һ���ļ���
	OutFile.open("students.txt");   //��students.txt�ļ�
	while (head)                //ֻҪ����Ϊ�գ������ļ��ﱣ������
	{
		OutFile << head->StuID << "	" << head->Name << "	" << head->MathScore << "	" << head->ProgramScore << "	" << head->TP << endl;
		head = head->next;   //����������һ�ڵ�
	}
	OutFile.close();      //�ر��ļ�
	return true;
}

//���ļ���������
Stu * ReadDataFromFile()
{
	Stu * head = NULL, *Cur = NULL, *Cur1 = NULL;      //��������ָ�룬���ڴ洢ͷ��㣬Ŀǰ�ڵ㣬������ڵ�
	ifstream InFile;            //���������ļ���
	InFile.open("students.txt");     //��students.txt�ļ�
	while (InFile)               //ֻҪ�ļ���δ���ļ�ĩ�����������ڴ潫���������ڴ�
	{
		if (head == NULL)           //��ͷ���Ϊ��ʱ������һ���ڴ���Ϊͷ�ڵ�
		{
			head = ApplyRam();
			InFile >> head->StuID>>head->Name>> head->MathScore >> head->ProgramScore >> head->TP;
			Cur = head;           //��Ŀǰ�ڵ�ָ��ͷ���
		}
		else                    //��ͷ��㲻Ϊ��
		{
			Cur1 = ApplyRam();   //��¼����Ľڵ�
			InFile >> Cur1->StuID>>Cur1->Name>>Cur1->MathScore >> Cur1->ProgramScore >> Cur1->TP;//���ļ�������������ڴ�
			Cur->next = Cur1;    //�ڵ������
			Cur1->primer = Cur;
			Cur = Cur1;
		}
	}
	head->primer = Cur->primer; //���½����õ�������λ�����γɻ�
	Cur->primer->next = NULL;
	delete Cur;                 //�����ļ��еĻس������Ի������һ���ڵ㣬��Ҫɾ��
	InFile.close();            //�ر��ļ�
	return head;                //����ͷ�ڵ��ַ
}
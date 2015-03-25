#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<io.h>

typedef struct
{
	char name[10];		//姓名
	char addr[255];		//地址
	char post[7];		//邮编
	char pNum[13];		//电话号码
}list;

#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define ERROR -1
#define ACCEPT 0

void CreateList();
void OpenList();
void DeleteList();
void AddContact(FILE *fp);
void SelContact(FILE *fp);
void DelContact(FILE *fp,char *filename);
void UpdContact(FILE *fp);
list readList(FILE *fp);
list readLine(FILE *fp,int key);
list readFile(char *fp,int *p);

int main()
{
	char a = NULL;
	
	while(1)
	{
		system("cls");
		do{
			printf("当前位置：主菜单\n\n");
			printf("输入相应数字回车进入相应操作：\n");
			printf("\t1.新建通讯录文件\n");
			printf("\t2.打开通讯录文件\n");
			printf("\t3.删除通讯录文件\n");
			printf("\t4.退出程序\n");
			printf("\n请输入：");
			fflush(stdin);
			a = getchar();

			if(a > '4' || a < '1')
			{
				printf("输入错误！按任意键继续");
				fflush(stdin);
				getchar();
				system("cls");
			}

		}while(a > '4' || a < '1');

		switch(a)
		{
		case '1':
			CreateList();break;
		case '2':
			OpenList();break;
		case '3':
			DeleteList();break;
		case '4':
			system("cls");
			printf("\n\n\n\t感谢你的使用！按任意键退出。");
			getch();
			exit(0);break;
		}

		a = NULL;
	}

	return 0;
}

void CreateList()
{
	FILE *fp;
	char filename[255] = "";
	int flag = 1;

	system("cls");

	while(flag)
	{
		if(strcmp(filename,"") != 0)
		{
			system("cls");
		}

		printf("当前位置：新建通信录文件\n\n");
		printf("输入文件名，需要带文件后缀\n直接输入exit，返回上一级菜单\n");

		printf("\n请输入文件名:");
		fflush(stdin);
		gets(filename);

		if(strcmp(filename,"exit") == 0)
		{
			return;
		}

		/*
		函数名：access
		功 能：	确定文件的访问权限，检查某个文件的存取方式，
				比如说是只读方式、只写方式等。如果指定的存取
				方式有效，则函数返回0，否则函数返回-1
		参数mode可为以下的其中之一：
				00 只存在
				02 写权限
				04 读权限
				06 读和写权限
		*/

		if(access(filename,0) == -1)
		{
			if((fp = fopen(filename,"w")) != NULL)
			{
				flag = 0;
			}else{
				printf("输入有误或者文件存在已经存在。按任意键继续");
				getch();
			}
		}else{
			printf("输入有误或者文件存在已经存在。按任意键继续");
			getch();
		}
	}

	if(fp)
	{
		printf("新建通讯录文件成功！按任意键开始添加数据。");
		getchar();
		fclose(fp);
		fp = fopen(filename,"a");
		AddContact(fp);
	}
	fclose(fp);
}

void OpenList()
{
	char filename[255] = "";
	char key;
	FILE *fp;
	int flag = 1;

	while(flag)
	{
		system("cls");
		printf("当前位置：打开通讯录文件\n\n");
		printf("请先输入你要查询的通讯录文件，输入exit返回上一级\n");
		printf("请输入：");
		fflush(stdin);
		gets(filename);

		if(!strcmp(filename,"exit"))
		{
			return;
		}

		if(access(filename,02) == -1)
		{
			printf("文件不存在或者文件只读。按任意键继续");
			getch();
			system("cls");
		}else{
			if(!(fp = fopen(filename,"a+")))
			{
				printf("文件打开失败！按任意键继续");
				getch();
			}else{
				flag = 0;
			}
		}
	}

	while(1)
	{
		do{
			system("cls");

			printf("当前位置：联系人操作选择\n当前操作文件：%s\n\n",filename);

			printf("输入下列操作的序号，进行相应操作：\n");
			printf("\t1.查询联系人\n");
			printf("\t2.新增联系人\n");
			printf("\t3.删除联系人\n");
			printf("\t4.返回上一级\n\n");

			printf("请输入：");
			fflush(stdin);
			key = getchar();
		}while(key > '4' || key < '1');

		switch(key)
		{
		case '1':
			SelContact(fp);break;
		case '2':
			AddContact(fp);break;
		case '3':
			DelContact(fp,filename);break;
		case '4':
			fclose(fp);
			return;break;
		}
	}

	fclose(fp);
}

void DeleteList()
{
	char filename[255] = "";

	while(1)
	{
		system("cls");

		printf("当前位置：删除通讯录文件\n\n");
		printf("请输入你要删除文件的文件名\n输入exit返回上一级\n");
		printf("\n请输入文件名:");
		fflush(stdin);
		gets(filename);

		if(!strcmp(filename,"exit"))
		{
			return;
		}

		/*
		函数名：remove函数
		功 能：	删除一个文件   
		用 法：	int remove( const char *filename);
		头文件：在Visual C++ 6.0中可以用stdio.h
		返回值：如果删除成功，remove返回0，否则返回EOF（-1）。
		*/

		if(!access(filename,0))
		{
			if(!remove(filename))
			{
				printf("删除成功！按任意键继续操作。");
				getch();
			}else{
				printf("不能成功删除！当前文件为只读文件或者正使用。\n按任意键继续操作。");
				getch();
			}
		}else{
			printf("文件不存在！按任意键继续操作。");
			getch();
		}
	}
}

void SelContact(FILE *fp)
{
	char key = NULL,keyword[255];
	list a;
	
	strcpy(a.name,"");
	strcpy(a.addr,"");
	strcpy(a.post,"");
	strcpy(a.pNum,"");

	do{
		system("cls");
		printf("当前位置：搜索联系人\n\n");
		printf("按1查询文件中所有信息，按2进行特征查询。\n");
		printf("请输入：");
		fflush(stdin);
		key = getchar();
		if(key > '2' || key < '1')
		{
			printf("输入错误！	按任意键继续。");
			getch();
		}
	}while(key > '2' || key < '1');

	int flag;
	switch(key)
	{
	case '1':
		system("cls");
		printf("当前位置：搜索联系人—结果\n\n");
		printf("查询结果如下：\n");

		fseek(fp,0,SEEK_SET);
		flag = 0;
		while(!feof(fp))
		{
			a = readList(fp);
			if(strcmp(a.name,""))
			{
				printf("姓名：%s\t",a.name);
				printf("地址：%s\t",a.addr);
				printf("邮编：%s\t",a.post);
				printf("电话号码：%s\n",a.pNum);
				flag = 1;
			}
		}

		fseek(fp, 0, SEEK_SET);

		if(flag)
		{
			printf("\n结果显示完毕。按任意键继续。");
		}else{
			printf("\n该文件中没有任何联系人信息。");
		}
		getch();
		break;
	case '2':
		do{
			system("cls");
			printf("当前位置：搜索联系人—关键字输入\n\n");
			printf("请输入你要查询的关键字类型：\n");
			printf("\t1.姓名\n");
			printf("\t2.地址\n");
			printf("\t3.邮政编码\n");
			printf("\t4.电话号码\n\n");
			
			printf("请输入：");
			fflush(stdin);
			key = getchar();
			
			if(key > '4' || key < '1')
			{
				printf("输入错误！按任意键继续。");
				getch();
			}
		}while(key > '4' || key < '1');

		printf("请输入关键字：");
		fflush(stdin);
		gets(keyword);

		int flag_a = 0;
		fseek(fp,0,SEEK_SET);
		system("cls");
		printf("当前位置：搜索联系人—结果\n\n");
		printf("你所要搜索的结果如下：\n");
		while(!feof(fp))
		{
			flag = 0;
			a = readList(fp);
			if(a.name != "")
			{
				switch(key)
				{
				case '1':
					flag = strcmp(keyword,a.name)?flag:1;
					break;
				case '2':
					flag = strcmp(keyword,a.addr)?flag:1;
					break;
				case '3':
					flag = strcmp(keyword,a.post)?flag:1;
					break;
				case '4':
					flag = strcmp(keyword,a.pNum)?flag:1;
					break;
				}
				if(flag)
				{
					printf("姓名：%s\t",a.name);
					printf("地址：%s\t",a.addr);
					printf("邮编：%s\t",a.post);
					printf("电话号码：%s\n",a.pNum);
					flag_a = 1;
				}
			}
		}

		if(flag_a)
		{
			printf("\n结果显示完毕！按任意键继续。");
			getch();
		}else{
			system("cls");
			printf("\n\n\n\t你所要查询的信息不存在。按任意键继续");
			getch();
		}

		fseek(fp, 0, SEEK_SET);
		break;
	}
}

void AddContact(FILE *fp)
{
	list a;
	fseek(fp, 0, SEEK_END);

	while(1)
	{
		system("cls");

		fflush(stdin);
		printf("当前位置：新增联系人\n输入exit退出输入\n\n");
		printf("请输入联系人的姓名：");
		if(!strcmp(gets(a.name),"exit"))
		{
			fclose(fp);
			return;
		}
		printf("请输入联系人的地址：");
		if(!strcmp(gets(a.addr),"exit"))
		{
			fclose(fp);
			return;
		}
		printf("请输入联系人的邮编：");
		if(!strcmp(gets(a.post),"exit"))
		{
			fclose(fp);
			return;
		}
		printf("请输入联系人的电话号码：");
		if(!strcmp(gets(a.pNum),"exit"))
		{
			fclose(fp);
			return;
		}

		if(fprintf(fp,";;%s;%s;%s;%s;\n",a.name,a.addr,a.post,a.pNum) != 0)
		{
			printf("输入成功！按任意键继续。");
			getch();
		}else{
			printf("写入失败！按任意键继续。");
			getch();
		}
	}
}

void DelContact(FILE *fp,char *filename)
{
	char key,keyword[255];

	do
	{
		system("cls");
		printf("当前位置：删除联系人\n输入exit退出输入\n\n");
		printf("请输入关键字类型相应的编号：\n");
		printf("\t1.姓名\n");
		printf("\t2.地址\n");
		printf("\t3.邮编\n");
		printf("\t4.电话号码\n");
		printf("\t5.返回上一级");
		printf("\n请输入：");
		fflush(stdin);
		key = getchar();
		if(key > '5' || key < '1')
		{
			fflush(stdin);
			printf("输入有误，按任意键继续。");
			getch();
		}else if(key == '5'){
			return;
		}
	}while(key > '5' || key < '1');

	printf("请输入关键字：");
	fflush(stdin);
	gets(keyword);

	if(!strcmp(keyword,"exit"))
	{
		return;
	}

	list a;
	int flag_a = 0,flag;

	char file[1024] = "";
	int  i = 0;
	while(!feof(fp))
	{
		file[i] = fgetc(fp);
		i++;
	}
	file[i-1] = '\0';
	i = 0;

	int *p = &i;
	while(file[i] != '\0')
	{
		flag = 0;
		a = readFile(file,p);
		if(strcmp(a.name, ""))
		{
			switch(key)
			{
			case '1':
				flag = strcmp(keyword,a.name)?flag:1;
				break;
			case '2':
				flag = strcmp(keyword,a.addr)?flag:1;
				break;
			case '3':
				flag = strcmp(keyword,a.post)?flag:1;
				break;
			case '4':
				flag = strcmp(keyword,a.pNum)?flag:1;
				break;
			}
			if(flag)
			{
				file[i-2] = '@';
				flag_a = 1;
			}
		}
	}
	fclose(fp);
	fp = fopen(filename,"w+");
	fputs(file,fp);
	fclose(fp);
	fp = fopen(filename,"a+");
	if(flag_a)
	{
		printf("结果已经删除，按任意键继续。");
		getch();
	}else{
		printf("没有找到此联系人，按任意键继续。");
		getch();
	}
}

list readList(FILE *fp)
{
	list a,n;
	int state = S1,i = 0,j = 0,flag = 1;
	char ch;

	strcpy(n.name,"");
	strcpy(n.addr,"");
	strcpy(n.post,"");
	strcpy(n.pNum,"");

	while(state != ERROR && state != ACCEPT && !feof(fp))
	{
		ch = fgetc(fp);

		switch(state)
		{
		case S1:
			if(ch == ';')
			{
				state = S2;
			}else{
				state = S4;
				flag = 0;
			}
			break;
		case S2:
			if(ch == ';')
			{
				state = S3;
			}else{
				state = S4;
				flag = 0;
			}
			break;
		case S3:
			if(ch == ';')
			{
				//state = S3;
				switch(j)
				{
				case 0:
					a.name[i] = '\0';break;
				case 1:
					a.addr[i] = '\0';break;
				case 2:
					a.post[i] = '\0';break;
				case 3:
					a.pNum[i] = '\0';
					state = S4;break;
				}
				i = 0;
				j++;
			}else if(ch == '@'){
				flag = 0;
				state = S4;
			}else{
				switch(j)
				{
				case 0:
					a.name[i] = ch;break;
				case 1:
					a.addr[i] = ch;break;
				case 2:
					a.post[i] = ch;break;
				case 3:
					a.pNum[i] = ch;break;
				}
				i++;
			}
			break;
		case S4:
			if(ch == '\n')
			{
				if(flag)
				{
					state = ACCEPT;
				}else{
					state = ERROR;
				}
			}else{
				state = ERROR;
			}
			if(feof(fp))
			{
				if(flag)
				{
					state = ACCEPT;
				}else{
					state = ERROR;
				}
			}
			break;
		}
	}

	if(state == ACCEPT)
	{
		return a;
	}else{
		return n;
	}
}

list readFile(char *file,int *p)
{
	list a,n;
	int state = S1,i = 0,j = 0,flag = 1;
	char ch;

	strcpy(n.name,"");
	strcpy(n.addr,"");
	strcpy(n.post,"");
	strcpy(n.pNum,"");

	while(state != ERROR && state != ACCEPT)
	{
		ch = file[*p];

		switch(state)
		{
		case S1:
			if(ch == ';')
			{
				state = S2;
			}else{
				state = S4;
				flag = 0;
			}
			break;
		case S2:
			if(ch == ';')
			{
				state = S3;
			}else{
				state = S4;
				flag = 0;
			}
			break;
		case S3:
			if(ch == ';')
			{
				state = S3;
				switch(j)
				{
				case 0:
					a.name[i] = '\0';break;
				case 1:
					a.addr[i] = '\0';break;
				case 2:
					a.post[i] = '\0';break;
				case 3:
					a.pNum[i] = '\0';
					state = S4;break;
				}
				i = 0;
				j++;
			}else if(ch == '@'){
				state = S4;
			}else{
				switch(j)
				{
				case 0:
					a.name[i] = ch;break;
				case 1:
					a.addr[i] = ch;break;
				case 2:
					a.post[i] = ch;break;
				case 3:
					a.pNum[i] = ch;break;
				}
				i++;
			}
			break;
		case S4:
			if(ch == '\n')
			{
				if(flag)
				{
					state = ACCEPT;
				}else{
					state = ERROR;
				}
			}else{
				state = ERROR;
			}
			if(ch == '\0')
			{
				state = ACCEPT;
			}
			break;
		}
		(*p)++;
	}

	if(state == ACCEPT)
	{
		return a;
	}else{
		return n;
	}
}

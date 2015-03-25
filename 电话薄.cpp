#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<io.h>

typedef struct
{
	char name[10];		//����
	char addr[255];		//��ַ
	char post[7];		//�ʱ�
	char pNum[13];		//�绰����
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
			printf("��ǰλ�ã����˵�\n\n");
			printf("������Ӧ���ֻس�������Ӧ������\n");
			printf("\t1.�½�ͨѶ¼�ļ�\n");
			printf("\t2.��ͨѶ¼�ļ�\n");
			printf("\t3.ɾ��ͨѶ¼�ļ�\n");
			printf("\t4.�˳�����\n");
			printf("\n�����룺");
			fflush(stdin);
			a = getchar();

			if(a > '4' || a < '1')
			{
				printf("������󣡰����������");
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
			printf("\n\n\n\t��л���ʹ�ã���������˳���");
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

		printf("��ǰλ�ã��½�ͨ��¼�ļ�\n\n");
		printf("�����ļ�������Ҫ���ļ���׺\nֱ������exit��������һ���˵�\n");

		printf("\n�������ļ���:");
		fflush(stdin);
		gets(filename);

		if(strcmp(filename,"exit") == 0)
		{
			return;
		}

		/*
		��������access
		�� �ܣ�	ȷ���ļ��ķ���Ȩ�ޣ����ĳ���ļ��Ĵ�ȡ��ʽ��
				����˵��ֻ����ʽ��ֻд��ʽ�ȡ����ָ���Ĵ�ȡ
				��ʽ��Ч����������0������������-1
		����mode��Ϊ���µ�����֮һ��
				00 ֻ����
				02 дȨ��
				04 ��Ȩ��
				06 ����дȨ��
		*/

		if(access(filename,0) == -1)
		{
			if((fp = fopen(filename,"w")) != NULL)
			{
				flag = 0;
			}else{
				printf("������������ļ������Ѿ����ڡ������������");
				getch();
			}
		}else{
			printf("������������ļ������Ѿ����ڡ������������");
			getch();
		}
	}

	if(fp)
	{
		printf("�½�ͨѶ¼�ļ��ɹ������������ʼ������ݡ�");
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
		printf("��ǰλ�ã���ͨѶ¼�ļ�\n\n");
		printf("����������Ҫ��ѯ��ͨѶ¼�ļ�������exit������һ��\n");
		printf("�����룺");
		fflush(stdin);
		gets(filename);

		if(!strcmp(filename,"exit"))
		{
			return;
		}

		if(access(filename,02) == -1)
		{
			printf("�ļ������ڻ����ļ�ֻ���������������");
			getch();
			system("cls");
		}else{
			if(!(fp = fopen(filename,"a+")))
			{
				printf("�ļ���ʧ�ܣ������������");
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

			printf("��ǰλ�ã���ϵ�˲���ѡ��\n��ǰ�����ļ���%s\n\n",filename);

			printf("�������в�������ţ�������Ӧ������\n");
			printf("\t1.��ѯ��ϵ��\n");
			printf("\t2.������ϵ��\n");
			printf("\t3.ɾ����ϵ��\n");
			printf("\t4.������һ��\n\n");

			printf("�����룺");
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

		printf("��ǰλ�ã�ɾ��ͨѶ¼�ļ�\n\n");
		printf("��������Ҫɾ���ļ����ļ���\n����exit������һ��\n");
		printf("\n�������ļ���:");
		fflush(stdin);
		gets(filename);

		if(!strcmp(filename,"exit"))
		{
			return;
		}

		/*
		��������remove����
		�� �ܣ�	ɾ��һ���ļ�   
		�� ����	int remove( const char *filename);
		ͷ�ļ�����Visual C++ 6.0�п�����stdio.h
		����ֵ�����ɾ���ɹ���remove����0�����򷵻�EOF��-1����
		*/

		if(!access(filename,0))
		{
			if(!remove(filename))
			{
				printf("ɾ���ɹ��������������������");
				getch();
			}else{
				printf("���ܳɹ�ɾ������ǰ�ļ�Ϊֻ���ļ�������ʹ�á�\n�����������������");
				getch();
			}
		}else{
			printf("�ļ������ڣ������������������");
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
		printf("��ǰλ�ã�������ϵ��\n\n");
		printf("��1��ѯ�ļ���������Ϣ����2����������ѯ��\n");
		printf("�����룺");
		fflush(stdin);
		key = getchar();
		if(key > '2' || key < '1')
		{
			printf("�������	�������������");
			getch();
		}
	}while(key > '2' || key < '1');

	int flag;
	switch(key)
	{
	case '1':
		system("cls");
		printf("��ǰλ�ã�������ϵ�ˡ����\n\n");
		printf("��ѯ������£�\n");

		fseek(fp,0,SEEK_SET);
		flag = 0;
		while(!feof(fp))
		{
			a = readList(fp);
			if(strcmp(a.name,""))
			{
				printf("������%s\t",a.name);
				printf("��ַ��%s\t",a.addr);
				printf("�ʱࣺ%s\t",a.post);
				printf("�绰���룺%s\n",a.pNum);
				flag = 1;
			}
		}

		fseek(fp, 0, SEEK_SET);

		if(flag)
		{
			printf("\n�����ʾ��ϡ��������������");
		}else{
			printf("\n���ļ���û���κ���ϵ����Ϣ��");
		}
		getch();
		break;
	case '2':
		do{
			system("cls");
			printf("��ǰλ�ã�������ϵ�ˡ��ؼ�������\n\n");
			printf("��������Ҫ��ѯ�Ĺؼ������ͣ�\n");
			printf("\t1.����\n");
			printf("\t2.��ַ\n");
			printf("\t3.��������\n");
			printf("\t4.�绰����\n\n");
			
			printf("�����룺");
			fflush(stdin);
			key = getchar();
			
			if(key > '4' || key < '1')
			{
				printf("������󣡰������������");
				getch();
			}
		}while(key > '4' || key < '1');

		printf("������ؼ��֣�");
		fflush(stdin);
		gets(keyword);

		int flag_a = 0;
		fseek(fp,0,SEEK_SET);
		system("cls");
		printf("��ǰλ�ã�������ϵ�ˡ����\n\n");
		printf("����Ҫ�����Ľ�����£�\n");
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
					printf("������%s\t",a.name);
					printf("��ַ��%s\t",a.addr);
					printf("�ʱࣺ%s\t",a.post);
					printf("�绰���룺%s\n",a.pNum);
					flag_a = 1;
				}
			}
		}

		if(flag_a)
		{
			printf("\n�����ʾ��ϣ��������������");
			getch();
		}else{
			system("cls");
			printf("\n\n\n\t����Ҫ��ѯ����Ϣ�����ڡ������������");
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
		printf("��ǰλ�ã�������ϵ��\n����exit�˳�����\n\n");
		printf("��������ϵ�˵�������");
		if(!strcmp(gets(a.name),"exit"))
		{
			fclose(fp);
			return;
		}
		printf("��������ϵ�˵ĵ�ַ��");
		if(!strcmp(gets(a.addr),"exit"))
		{
			fclose(fp);
			return;
		}
		printf("��������ϵ�˵��ʱࣺ");
		if(!strcmp(gets(a.post),"exit"))
		{
			fclose(fp);
			return;
		}
		printf("��������ϵ�˵ĵ绰���룺");
		if(!strcmp(gets(a.pNum),"exit"))
		{
			fclose(fp);
			return;
		}

		if(fprintf(fp,";;%s;%s;%s;%s;\n",a.name,a.addr,a.post,a.pNum) != 0)
		{
			printf("����ɹ����������������");
			getch();
		}else{
			printf("д��ʧ�ܣ��������������");
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
		printf("��ǰλ�ã�ɾ����ϵ��\n����exit�˳�����\n\n");
		printf("������ؼ���������Ӧ�ı�ţ�\n");
		printf("\t1.����\n");
		printf("\t2.��ַ\n");
		printf("\t3.�ʱ�\n");
		printf("\t4.�绰����\n");
		printf("\t5.������һ��");
		printf("\n�����룺");
		fflush(stdin);
		key = getchar();
		if(key > '5' || key < '1')
		{
			fflush(stdin);
			printf("�������󣬰������������");
			getch();
		}else if(key == '5'){
			return;
		}
	}while(key > '5' || key < '1');

	printf("������ؼ��֣�");
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
		printf("����Ѿ�ɾ�����������������");
		getch();
	}else{
		printf("û���ҵ�����ϵ�ˣ��������������");
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

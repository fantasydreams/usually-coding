#define MaxLen 100

class Data    //�������ڽ������洢���ݺͽ������Һ���
{
public:
	char data;
	Data * lchild;
	Data * rchild;
	Data(char ch) //���캯��
	{
		lchild = rchild = NULL;
		data = ch;
	}
};


//��������ʵ�ֶԶ������Ľ��������������������򡢺��������ʵ�ֵ�
class Tree
{
private:
	Data * TreeRoot; //�������
	void Post(const Data * Root); //�����������
	void In(const Data * Root);  //�����������
	void Pre(const Data * Root); //�����������
	void gradation(Data * Root); //��α���
	void deleteMemoroy(Data * Root)  //�ͷ��ڴ溯��
	{
		if (Root)
		{
			deleteMemoroy(Root->lchild);
			deleteMemoroy(Root->rchild);
			delete Root;
		}
	}
	void CreateTree(Data * &Root); //��������������
	int TreeDegree(const Data * Root); //�����������
public:
	Tree()  //���캯��
	{
		TreeRoot = NULL;
		CreateTree(TreeRoot); //���ô����������������ж������Ľ���
	}
	~Tree(){ deleteMemoroy(TreeRoot); }  //�������������ڴ��ռ�ý����ͷ�
	void PreOrderTraverse()
	{
		std::cout << "���������" << std::endl;
		Pre(TreeRoot);
		std::cout << std::endl;
	}
	
	void InorderTraverse()
	{
		std::cout << "���������" << std::endl;
		In(TreeRoot);
		std::cout << std::endl;
	}
	
	void PostOrderTraverse()
	{
		std::cout << "�������" << std::endl;
		Post(TreeRoot);
		std::cout << std::endl;
	}

	void Gradation()
	{
		std::cout << "��α���" << std::endl;
		gradation(TreeRoot); 
	}   // ��α����ӿ�

	void Treedegree()
	{
		std::cout << "������ȣ�"<<TreeDegree(TreeRoot);
	}
};

void Tree::CreateTree(Data * &Root)  //������������ķ�ʽ���ж���������
{
	char ele;
	std::cin >> ele;
	if (ele != '*')
	{
		Root = new Data(ele);

		if (!Root)
			exit(OVERFLOW);
		CreateTree(Root->lchild);  //�ݹ齨��������
		CreateTree(Root->rchild);  //�ݹ�ݹ齨��������
	}
	else
		Root = NULL;
}

void Tree::Pre(const Data * Root)
{
	if (Root)
	{
		std::cout << Root->data;
		Pre(Root->lchild);  //����������
		Pre(Root->rchild);  //����������
	}
}

void Tree::In(const Data * Root)
{
	if (Root)
	{
		In(Root->lchild);
		std::cout << Root->data;
		In(Root->rchild);
	}
}

void Tree::Post(const Data * Root)
{
	if (Root)
	{
		Post(Root->lchild);
		Post(Root->rchild);
		std::cout << Root->data;
	}
}

void Tree::gradation(Data * Root)
{
	Data * p;
	Data * q[MaxLen] = { NULL };  //����˳�����
	int head = 0, tail = 0;
	if (Root)    //��if������ڽ�����������ѭ�����
	{
		tail = (tail + 1) % MaxLen;
		q[tail] = Root;
	}
	while (head != tail)
	{
		head = (head + 1) % MaxLen;
		p = q[head];
		std::cout << p->data;     //����
		if (p->lchild)  //�����������ӽ���
		{
			tail = (tail + 1) % MaxLen;  
			q[tail] = p->lchild;
		}
		if (p->rchild)  //�����ӵ��Һ��ӽ���
		{
			tail = (tail + 1) % MaxLen;
			q[tail] = p->rchild;
		}
	}
}

int Tree::TreeDegree(const Data * Root)
{
	int LeftDefree, RightDegree;
	if (Root)
	{
		LeftDefree = TreeDegree(Root->lchild);  //�������������
		RightDegree = TreeDegree(Root->rchild);  //�������������
		if (LeftDefree > RightDegree)
			return LeftDefree + 1;
		else
			return RightDegree + 1;
	}
	else
		return 0;
}

class Data    //�������ڽ������洢���ݺͽ������Һ���
{
public:
	char data;

	Data * lchild;
	Data * rchild;
	Data * pre;  //ָ��ֱ��ǰ����������ʵĽ�㣩
	Data * Behind; //ָ��ֱ�Ӻ�̣��������ڷ��ʵĽ�㣩
	Data(char ch) //���캯��
	{
		pre = Behind = lchild = rchild = NULL;
		data = ch;
	}
};


//��������ʵ�ֶԶ������Ľ��������������������򡢺��������ʵ�ֵ�
class Tree
{
private:
	Data * TreeRoot; //�������
	Data * pre;
	Data * head;  //���ڱ���ʱ���ͷ�ڵ�
	void PreInThread(Data * p);//�������������������
	void InInThread(Data *p);//�������������������
	void PostInThread(Data *p);//�������������������
	void ergodic(const Data *p); //���������õĶ�����
public:
	Tree()  //���캯��
	{
		head = pre = TreeRoot = NULL; 
		CreateTree(TreeRoot); //���ô����������������ж������Ľ���
	}

	~Tree(){ deleteMemoroy(TreeRoot); }  //�������������ڴ��ռ�ý����ͷ�

	
	void deleteMemoroy(Data * Root)  //�ͷ��ڴ溯��
	{
		if (Root)
		{
			deleteMemoroy(Root->lchild);
			deleteMemoroy(Root->rchild);
			delete Root;
		}
	}

	void CreateTree(Data * &Root); //����������   ����

	//����ӿ�
	void Pre(){ PreInThread(TreeRoot); }  //���������������������������Ľӿ�
	void In(){ InInThread(TreeRoot); }  //����ӿ�
	void Post(){ PostInThread(TreeRoot); }  //����ӿ�
	void ergodicP(){ ergodic(head); }
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
		CreateTree(Root->lchild);
		CreateTree(Root->rchild);
	}
	else
		Root = NULL;
}


void Tree::PreInThread(Data * p)
{
	if (p)
	{
		p->pre = this->pre;  //�����pre�ǽ���ֱ��ǰ��
		if (pre) //�����pre�Ǵ˽ڵ��ǰһ����㣬��Ȼ��p��ֱ��ǰ������������pre����class��ͬ
			pre->Behind = p;
		if (!head)
			head = p;
		pre = p;
		PreInThread(p->lchild); //������������
		PreInThread(p->rchild); //������������
	}
}


void Tree::InInThread(Data * p)
{
	if (p)
	{
		PreInThread(p->lchild); //������������
		p->pre = this->pre;  //�����pre�ǽ���ֱ��ǰ��
		if (pre) //�����pre�Ǵ˽ڵ��ǰһ����㣬��Ȼ��p��ֱ��ǰ������������pre����class��ͬ
			pre->Behind = p;
		if (!head)
			head = p;
		pre = p;
		PreInThread(p->rchild); //������������
	}
}

void Tree::PostInThread(Data * p)
{
	if (p)
	{
		PreInThread(p->lchild); //������������
		PreInThread(p->rchild); //������������
		p->pre = this->pre;  //�����pre�ǽ���ֱ��ǰ��
		if (pre) //�����pre�Ǵ˽ڵ��ǰһ����㣬��Ȼ��p��ֱ��ǰ������������pre����class��ͬ
			pre->Behind = p;
		if (!head)
			head = p;
		pre = p;
	}
}

void Tree::ergodic(const Data *p)
{
	while (true)
	{
		std::cout << p->data;
		p = p->Behind;
		if (!p)
			break;
	}
}
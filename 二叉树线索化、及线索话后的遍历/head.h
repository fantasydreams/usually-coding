
class Data    //此类用于建立结点存储数据和结点的左右孩子
{
public:
	char data;

	Data * lchild;
	Data * rchild;
	Data * pre;  //指向直接前驱（最近访问的结点）
	Data * Behind; //指向直接后继（现在正在访问的结点）
	Data(char ch) //构造函数
	{
		pre = Behind = lchild = rchild = NULL;
		data = ch;
	}
};


//此类用于实现对二叉树的建立、二叉树的先序、中序、后序遍历的实现等
class Tree
{
private:
	Data * TreeRoot; //树根结点
	Data * pre;
	Data * head;  //用于遍历时候的头节点
	void PreInThread(Data * p);//先序遍历线索化二叉树
	void InInThread(Data *p);//中序遍历线索化二叉树
	void PostInThread(Data *p);//后序遍历线索化二叉树
	void ergodic(const Data *p); //遍历线索好的二叉树
public:
	Tree()  //构造函数
	{
		head = pre = TreeRoot = NULL; 
		CreateTree(TreeRoot); //调用创建二叉树函数进行二叉树的建立
	}

	~Tree(){ deleteMemoroy(TreeRoot); }  //析构函数，对内存的占用进行释放

	
	void deleteMemoroy(Data * Root)  //释放内存函数
	{
		if (Root)
		{
			deleteMemoroy(Root->lchild);
			deleteMemoroy(Root->rchild);
			delete Root;
		}
	}

	void CreateTree(Data * &Root); //创建二叉树   函数

	//对外接口
	void Pre(){ PreInThread(TreeRoot); }  //对外调用先序遍历线索化二叉树的接口
	void In(){ InInThread(TreeRoot); }  //对外接口
	void Post(){ PostInThread(TreeRoot); }  //对外接口
	void ergodicP(){ ergodic(head); }
};


void Tree::CreateTree(Data * &Root)  //利用先序遍历的方式进行二叉树建立
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
		p->pre = this->pre;  //这里的pre是结点的直接前驱
		if (pre) //这里的pre是此节点的前一个结点，仍然是p的直接前驱，但是两个pre所在class不同
			pre->Behind = p;
		if (!head)
			head = p;
		pre = p;
		PreInThread(p->lchild); //线索化左子树
		PreInThread(p->rchild); //线索化右子树
	}
}


void Tree::InInThread(Data * p)
{
	if (p)
	{
		PreInThread(p->lchild); //线索化左子树
		p->pre = this->pre;  //这里的pre是结点的直接前驱
		if (pre) //这里的pre是此节点的前一个结点，仍然是p的直接前驱，但是两个pre所在class不同
			pre->Behind = p;
		if (!head)
			head = p;
		pre = p;
		PreInThread(p->rchild); //线索化右子树
	}
}

void Tree::PostInThread(Data * p)
{
	if (p)
	{
		PreInThread(p->lchild); //线索化左子树
		PreInThread(p->rchild); //线索化右子树
		p->pre = this->pre;  //这里的pre是结点的直接前驱
		if (pre) //这里的pre是此节点的前一个结点，仍然是p的直接前驱，但是两个pre所在class不同
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
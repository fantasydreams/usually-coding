#define MaxLen 100

class Data    //此类用于建立结点存储数据和结点的左右孩子
{
public:
	char data;
	Data * lchild;
	Data * rchild;
	Data(char ch) //构造函数
	{
		lchild = rchild = NULL;
		data = ch;
	}
};


//此类用于实现对二叉树的建立、二叉树的先序、中序、后序遍历的实现等
class Tree
{
private:
	Data * TreeRoot; //树根结点
	void Post(const Data * Root); //后序遍历函数
	void In(const Data * Root);  //中序遍历函数
	void Pre(const Data * Root); //先序遍历函数
	void gradation(Data * Root); //层次遍历
	void deleteMemoroy(Data * Root)  //释放内存函数
	{
		if (Root)
		{
			deleteMemoroy(Root->lchild);
			deleteMemoroy(Root->rchild);
			delete Root;
		}
	}
	void CreateTree(Data * &Root); //创建二叉树函数
	int TreeDegree(const Data * Root); //计算树的深度
public:
	Tree()  //构造函数
	{
		TreeRoot = NULL;
		CreateTree(TreeRoot); //调用创建二叉树函数进行二叉树的建立
	}
	~Tree(){ deleteMemoroy(TreeRoot); }  //析构函数，对内存的占用进行释放
	void PreOrderTraverse()
	{
		std::cout << "先序遍历：" << std::endl;
		Pre(TreeRoot);
		std::cout << std::endl;
	}
	
	void InorderTraverse()
	{
		std::cout << "中序遍历：" << std::endl;
		In(TreeRoot);
		std::cout << std::endl;
	}
	
	void PostOrderTraverse()
	{
		std::cout << "后序遍历" << std::endl;
		Post(TreeRoot);
		std::cout << std::endl;
	}

	void Gradation()
	{
		std::cout << "层次遍历" << std::endl;
		gradation(TreeRoot); 
	}   // 层次遍历接口

	void Treedegree()
	{
		std::cout << "树的深度："<<TreeDegree(TreeRoot);
	}
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
		CreateTree(Root->lchild);  //递归建立左子树
		CreateTree(Root->rchild);  //递归递归建立右子树
	}
	else
		Root = NULL;
}

void Tree::Pre(const Data * Root)
{
	if (Root)
	{
		std::cout << Root->data;
		Pre(Root->lchild);  //遍历左子树
		Pre(Root->rchild);  //遍历右子树
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
	Data * q[MaxLen] = { NULL };  //定义顺序队列
	int head = 0, tail = 0;
	if (Root)    //此if语句用于将树根结点进入循序队列
	{
		tail = (tail + 1) % MaxLen;
		q[tail] = Root;
	}
	while (head != tail)
	{
		head = (head + 1) % MaxLen;
		p = q[head];
		std::cout << p->data;     //出队
		if (p->lchild)  //将本结点的左孩子进队
		{
			tail = (tail + 1) % MaxLen;  
			q[tail] = p->lchild;
		}
		if (p->rchild)  //将本接的右孩子进队
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
		LeftDefree = TreeDegree(Root->lchild);  //求左子树的深度
		RightDegree = TreeDegree(Root->rchild);  //求右子树的深度
		if (LeftDefree > RightDegree)
			return LeftDefree + 1;
		else
			return RightDegree + 1;
	}
	else
		return 0;
}
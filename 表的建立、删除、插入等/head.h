template <typename type> class Node
{
public:
	Node(type data = 0)
	{
		back = NULL;
		this->data = data;
	}
	~Node(){}
	type GetData(){ return data; }
	Node <type> * GetBack(){ return back; }
	void SetBack(Node<type> * p){ back = p; }
private:
	type data;
	Node<type> * back;
};


template <typename type>class List
{
public:
	List()
	{
		head = NULL;
		Node_Num = 0;
	}
	~List(){}
	void createList();
	bool deleteNode();
	bool insertNode();
	void Print();
	void free();
private:
	Node<type> *head;
	int Node_Num;
};

template <class type> void List<type>::createList()
{
	int i;
	cout << "请输入需要创建的表长：";
	while (!(cin >> i && i >= 1));
	cout << "请输入第一个结点值：";
	type data;
	cin >> data;
	head = new Node < type > (data);
	Node<type>* temp, *front = head;
	for (int j = 0; j < i - 1; j++)
	{
		cout << "请输入第"<<j+2<<"个结点的值：";
		cin >> data;
		temp = new Node<type>(data);
		front->SetBack(temp);
		front = temp;
	}
	Node_Num = i;
	cout << "建立链完毕!" << endl;
}

template <class type> bool  List<type>::deleteNode()
{
	int Num;
	cout << "请输入要删除节点的位置：";
	while(!(cin >> Num && Num>0 && Num<=Node_Num));
	if (Num> 0 && Num <= Node_Num)
	{
		Node<type> * temp = head;
		for (int i = 0; i < Num - 2; i++)
			temp = temp->GetBack();
		if (1 == Num)
		{
			temp = head;
			head = head->GetBack();
			delete temp;
			return true;
			Node_Num--;
		}
		else
		{
			Node<type> * t = temp->GetBack();
			temp->SetBack(t->GetBack());
			delete t;
			Node_Num--;
			return true;
		}
	}
	else return false;
}

template <class type> bool List<type>::insertNode()
{
	int num;
	type data;
	cout << "请输入插入的位置和值:";
	cin >> num >> data;
	while (!(num > 0 && num <= Node_Num))
		cin >> num;
	Node<type> * temp = head, *NewNode = new Node<type>(data);
	if (1 == num)
	{
		NewNode;
		NewNode->SetBack(head);
		head = NewNode;
		Node_Num++;
		return true;
	}
	else
	{
		int i = 0;
		for (; i < num - 2; i++)
			temp = temp->GetBack();
		NewNode->SetBack(temp->GetBack());
		temp->SetBack(NewNode);
		Node_Num++;
		return true;
	}
}


template<class type>void List<type>::Print()
{
	Node<type>* temp = head;
	while (temp)
	{
		cout << temp->GetData();
		temp = temp->GetBack();
	}
	cout << endl;
}

template <class type> void List<type>::free()
{
	Node<type>* temp;
	while (head)
	{
		temp = head;
		head = head->GetBack();
		delete temp;
	}
}
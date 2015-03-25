template <typename type> class ListNode     //�ڵ���
{
public:
	ListNode(type data = 0)  //���캯��
	{
		this->data = data;
		L_node = NULL;
		R_node = NULL;
	}
	~ListNode(){}
	void Set_L_Node(ListNode<type> * Node){ L_node = Node; }
	void Set_R_Node(ListNode<type> * Node){ R_node = Node; }
	ListNode<type> * Get_LN(){ return L_node; }
	ListNode<type> * Get_RN(){ return R_node; }
	type GetData(){ return data; }
private:
	type data;
	ListNode<type> * L_node;
	ListNode<type> * R_node;
};
//ջ��
template <typename type> class stack :protected ListNode <type>
{
public:
	stack()
	{
		top = boom = this;
		Node_num = 0;
	}
	~stack(){ freeMemory(); }
	bool InStack(type n);
	type OutStack();
private:
	ListNode<type> * top; //ջ��ָ�룻
	ListNode<type> * boom; //ջ��ָ�룻
	int Node_num;  //��¼�������
	void freeMemory();  //���û�г�ջ�꣬������������ʱ�Զ��ͷ��ڴ棻
};

template <class type> void stack<type>::freeMemory()
{
	ListNode<type> * temp = boom->Get_RN();
	ListNode<type> * tmp = NULL;
	while (temp)
	{
		tmp = temp;
		temp = temp->Get_RN();
		delete tmp;
	}
}

//��ջ��Ա����
template<class type> bool stack<type>::InStack(type data)
{
	ListNode<type> * Node = new ListNode<type>(data);
	if (!Node)return false;
	else
	{
		Node->Set_L_Node(top);
		top->Set_R_Node(Node);
		top = Node;
		++Node_num;
		return true;
	}
}
//��ջ��Ա����
template<class type> type stack<type>::OutStack()
{
	if (NULL == top->Get_LN())return 0;
	else
	{
		type m;
		ListNode<type> * temp = top;
		top = top->Get_LN();
		top->Set_R_Node(NULL);
		--Node_num;
		m = temp->GetData();
		temp->Set_R_Node(NULL);  //��Ϊ��ָ�����ӣ��������Ҫ����ΪNULL������ΪҰָ�룬���´���
		delete temp;
		return m;
	}
}

//������
template  <typename type>class Queue :protected ListNode < type >
{
public:
	Queue()
	{
		head = tail = new ListNode<type>;
		Node_num = 0;
	}
	~Queue(){ freeMemory(); }
	bool InQueue(type n);
	type OutQueue();
private:
	ListNode<type> * head; //��ͷָ�룻
	ListNode<type> * tail; //��βָ�룻
	int Node_num;  //��¼�������
	void freeMemory();
};

//��ӳ�Ա����
template <class type> bool Queue < type > ::InQueue(type data)
{
	ListNode<type> * Node = new ListNode<type>(data);
	if (!Node)return false;
	else
	{
		tail->Set_R_Node(Node);
		Node->Set_L_Node(tail);
		tail = Node;
		Node_num++;
		return true;
	}
}

//���ӳ�Ա����
template <class type> type Queue<type> ::OutQueue()
{
	if (!(head->Get_RN()))return 0;
	else
	{
		type m = head->Get_RN()->GetData();
		ListNode <type> * temp = head;
		head = head->Get_RN();
		head->Get_RN()->Set_L_Node(NULL);//���Ҳ�Ƿ�ֹҰָ�룬��������δ����в������Ӱ��
		delete temp;
		return m;
	}
}

template <class type> void Queue <type>::freeMemory()
{
	ListNode<type> * temp = head->Get_RN();
	ListNode<type> * tmp = NULL;
	while (temp)
	{
		tmp = temp;
		temp = temp->Get_LN();
		delete tmp;
	}
}
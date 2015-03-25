#ifndef Graphic
#define Graphic
#ifndef _VECTOR_
#undef _VECTOR_
#include <vector>
#define _VECTOR_
#else
#include <vector>
#define _VECTOR_
#endif
//
template <typename type> class Data
{
private:
	type data; //�洢����
	Data * Next;  //��һ������address
public:
	Data(){ Next = NULL; }
	Data(type d)   //���캯������
	{
		Next = NULL;
		data = d;
	}
	int GetData(){	return data; }
	void SetData(type d){ data = d; }
	Data * GetNext(){ return Next; }
	void SetNext(Data *N){ Next = N; };
};

template <typename type>class Graph
{
private:
	Data<type> * addr; //�洢������׵�ַ
	int numVertexs; //�洢����ĸ���
	int * visit; //ָ���Ǳ���������
	std::vector <int> Queue;  //������ȱ���ʹ�õĶ���
	void freeMemery();   //�����ͷŷ�����ڴ� �������ͷ��ڴ淽��������ѷ��������ȵ�������ͷ��ڴ棬��ʹ��һ������ʹ�ù����ڴ汻ռ��ȴ���ܱ���һ������ʹ�ã�
	bool applyMemery();
	void DFS(const Data<type> * G, int i);
	void BFS(const Data<type> * G, int i);
public:
	Graph()
	{
		addr = NULL; 
		visit = NULL;
	} //���캯������ʼ��ָ��Ϊ��
	~Graph(){ freeMemery(); }  //��������;
	bool CreateGraph();  //����ͼ
	void PrintGraph();  //��ӡͼ
	void  CalDegree(); //�����
	void DFSTraverse();  //��ȱ����ӿ�
	void BFSTraverse(); //������ȱ����ӿ�
};

template <class type>bool Graph<type>::CreateGraph()
{
	std::cout << "��������ĸ�����";
	std::cin >> numVertexs;
	if (!(addr = new Data<type>[numVertexs]))  //���������ݴ洢
		return false;
	type data;
	Data<type>*p,*temp;  //ָ��������ʱָ��������ڴ�
	int numV;  //������ֱ�������Ķ�����
	for (int i = 0; i < numVertexs; i++)
	{
		std::cout << "�������" << i + 1 << "����������ݣ�";
		std::cin >> data;
		addr[i].SetData(data);
		std::cout << "�����뱾�ڵ�ֱ�����ӵĶ��������";
		std::cin >> numV;
		temp = &addr[i];
		for (int j = 0; j < numV; j++)
		{
			std::cout << "�������" << j + 1 << "�������˳��ֵ��";
			std::cin >> data;
			if (p = new Data<type>(data-1))
			{
				temp->SetNext(p);
				temp = p;
			}
			else
				return false;

		}
	}


	return true;
}

template <class type>void Graph<type>::freeMemery()
{
	if (addr)
	{
		Data<type> * temp, *tmp;  //������ʱָ��
		for (int i = 0; i < numVertexs; i++)
		{
			temp = addr[i].GetNext();
			while (temp)
			{
				tmp = temp;
				temp = temp->GetNext();
				delete tmp;
			}
				
		}
		delete[]addr;
	}
	if (visit)
		delete[] visit;
}

template <class type>void Graph<type>::PrintGraph()
{
	Data<type> * temp;
	for (int i = 0; i < numVertexs; i++)
	{
		std::cout << addr[i].GetData() << "  ";
		temp = addr[i].GetNext();
		while (temp)
		{
			std::cout << addr[temp->GetData()].GetData() << "  ";
			temp = temp->GetNext();
		}
		cout << endl;
	}
}

template <class type> void Graph<type>::CalDegree()
{
	int D;
	Data <type> * temp;
	for (int i = 0; i < numVertexs; i++)
	{
		D = 0;
		temp = addr[i].GetNext();
		while (temp)
		{
			D++;
			temp = temp->GetNext();
		}
		std::cout << "��" << i + 1 << "������Ķ�Ϊ��" << D << std::endl;
	}
}

template <class type>bool Graph<type>::applyMemery()
{
	if (!(visit = new int[numVertexs]))
		return false;
	for (int i = 0; i < numVertexs; i++)
		visit[i] = 0;
	return true;
}


template <class type>void Graph<type>::DFSTraverse()
{
	if (visit)
		delete[]visit;
	if (applyMemery())  //��������ڴ�����
	{
		std::cout << "������ȱ���" << std::endl;
		for (int j = 0; j < numVertexs; j++) //����������飬����û�з��ʵģ�����������ȱ���  //����һ������û�б�ʱ�Ż�������
			if (!visit[j]) 
				BFS(addr, j);//������ȱ�������
	}
}

template <class type>void Graph<type>::DFS(const Data<type> * G,int i)
{
	visit[i] = 1;
	std::cout << addr[i].GetData();
	Data<type> * p = addr[i].GetNext();
	while (p)
	{
		if (!visit[p->GetData()])
			DFS(G, p->GetData());
		p = p->GetNext();
	}
}

template <class type> void Graph<type>::BFSTraverse()
{
	if (visit)
		delete[]visit;
	if (applyMemery())  //��������ڴ�����
	{
		std::cout << "������ȱ�����" << std::endl;
		for (int j = 0; j < numVertexs; j++) //����������飬����û�з��ʵģ�����������ȱ���  //����һ������û�б�ʱ�Ż�������
			if (!visit[j]) 
				BFS(addr, j);
	}
}

template <class type>void Graph<type>::BFS(const Data<type> * G,int i)
{
	//�㷨һ
	visit[i] = 1;
	int j; //������ӵ�����
	Data <type> *p;
	std::cout << addr[i].GetData();  //�������
	Queue.push_back(i);  //���
	while (!Queue.empty()) //ѭ������������Ϊ�ǿ�
	{
		j = Queue[0]; //�õ������еĵ�һ��Ԫ��
		Queue.erase(Queue.begin());  //��һ��Ԫ�س��ӣ�ɾ����
		p = addr[j].GetNext();
		while (p)
		{
			if (!visit[p->GetData()])
			{
				visit[p->GetData()] = 1;
				Queue.push_back(p->GetData());
				std::cout << addr[p->GetData()].GetData();
			}
			p = p->GetNext();
		}
	}

	//�㷨����
	/*
	visit[i] = 1;
	std::cout << addr[i].GetData();
	Data<type> * p = addr[i].GetNext();
	while (p)
	{
		if (!visit[p->GetData()])
		{
			visit[p->GetData()] = 1;
			std::cout << addr[p->GetData()].GetData();
		}
		p = p->GetNext();
	}
	for (int j = 0; j < numVertexs; j++) //����������飬����û�з��ʵģ�����������ȱ���
		if (!visit[j])
			DFS(G, j);
			*/

	//�㷨���ϸ���˵�㲻�����������ϵĹ������
}

#endif

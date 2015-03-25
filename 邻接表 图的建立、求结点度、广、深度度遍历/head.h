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
	type data; //存储数据
	Data * Next;  //下一个结点的address
public:
	Data(){ Next = NULL; }
	Data(type d)   //构造函数重载
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
	Data<type> * addr; //存储数组的首地址
	int numVertexs; //存储顶点的个数
	int * visit; //指向标记遍历的数组
	std::vector <int> Queue;  //广度优先遍历使用的队列
	void freeMemery();   //整体释放分配的内存 （集中释放内存方案不是最佳方案，都等到最后来释放内存，会使得一部分已使用过的内存被占用却不能被进一步回收使用）
	bool applyMemery();
	void DFS(const Data<type> * G, int i);
	void BFS(const Data<type> * G, int i);
public:
	Graph()
	{
		addr = NULL; 
		visit = NULL;
	} //构造函数，初始化指针为空
	~Graph(){ freeMemery(); }  //析构函数;
	bool CreateGraph();  //构建图
	void PrintGraph();  //打印图
	void  CalDegree(); //计算度
	void DFSTraverse();  //深度遍历接口
	void BFSTraverse(); //广度优先遍历接口
};

template <class type>bool Graph<type>::CreateGraph()
{
	std::cout << "请输入结点的个数：";
	std::cin >> numVertexs;
	if (!(addr = new Data<type>[numVertexs]))  //申请结点数据存储
		return false;
	type data;
	Data<type>*p,*temp;  //指针用来临时指向申请的内存
	int numV;  //各顶点直接相连的顶点数
	for (int i = 0; i < numVertexs; i++)
	{
		std::cout << "请输入第" << i + 1 << "个顶点的数据：";
		std::cin >> data;
		addr[i].SetData(data);
		std::cout << "请输入本节点直接连接的顶点个数：";
		std::cin >> numV;
		temp = &addr[i];
		for (int j = 0; j < numV; j++)
		{
			std::cout << "请输入第" << j + 1 << "个顶点的顺序值：";
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
		Data<type> * temp, *tmp;  //两个临时指针
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
		std::cout << "第" << i + 1 << "个顶点的度为：" << D << std::endl;
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
	if (applyMemery())  //如果申请内存正常
	{
		std::cout << "深度优先遍历" << std::endl;
		for (int j = 0; j < numVertexs; j++) //遍历标记数组，若有没有访问的，继续进行深度遍历  //仅当一个顶点没有边时才会起作用
			if (!visit[j]) 
				BFS(addr, j);//调用深度遍历函数
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
	if (applyMemery())  //如果申请内存正常
	{
		std::cout << "广度优先遍历：" << std::endl;
		for (int j = 0; j < numVertexs; j++) //遍历标记数组，若有没有访问的，继续进行深度遍历  //仅当一个顶点没有边时才会起作用
			if (!visit[j]) 
				BFS(addr, j);
	}
}

template <class type>void Graph<type>::BFS(const Data<type> * G,int i)
{
	//算法一
	visit[i] = 1;
	int j; //储存出队的数据
	Data <type> *p;
	std::cout << addr[i].GetData();  //输出数据
	Queue.push_back(i);  //入队
	while (!Queue.empty()) //循环条件：队列为非空
	{
		j = Queue[0]; //得到对列中的第一个元素
		Queue.erase(Queue.begin());  //第一个元素出队（删除）
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

	//算法二：
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
	for (int j = 0; j < numVertexs; j++) //遍历标记数组，若有没有访问的，继续进行深度遍历
		if (!visit[j])
			DFS(G, j);
			*/

	//算法二严格上说算不上真正意义上的广义遍历
}

#endif

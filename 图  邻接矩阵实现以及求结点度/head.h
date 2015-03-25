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


#define _INFINITY 65535  //���������

template <typename type> class Graph
{
private:
	type *  vexs; //�������ַ
	type * arcs;  //�ڽӾ�����׵�ַ
	int numVertexs, numEdges; //	ͼ�е�ͱ�
	bool * visit;  //���������Ǿ���
	bool applyVisit();
	void DFS(int i); //������ȱ�������
	void BFS(int i); //������ȱ�������
	std::vector<int> Queue;  //����
public:
	Graph(){}
	~Graph()
	{
		if (vexs)
			delete[] vexs;
		if (arcs)
			delete[] arcs;
	}
	bool CreateGraph();//����ͼ
	bool CreateVectorGraph()//��������ͼ
	{
		if (CreateGraph());
		else return false;
		for (int i = 0; i < numVertexs; i++)
			for (int j = i + 1; j < numVertexs; j++)
				arcs[j*numVertexs + i] = arcs[i*numVertexs + j];  //����ͼ��Ϊ�Գƾ���
		return true;
	}
	void print();//����
	void CalDegree();
	void DFSTraverse(); //������ȱ����ӿ�
	void BFSTraverse(); //������ȱ����ӿ�
};

template <class type>void Graph<type>::BFS(int i)
{
	visit[i] = true;
	std::cout << vexs[i];
	int j;
	Queue.push_back(i);  //������
	while (!Queue.empty()) //�����в�Ϊ��
	{
		j = Queue[0];  //��õ�һ��Ԫ��ֵ
		Queue.erase(Queue.begin()); //��һ��Ԫ�س���
		for (int k = 0; k < numVertexs; k++)
		{
			if (arcs[i*numVertexs + k] != _INFINITY && arcs[i*numVertexs + k] != 0)
				if (!visit[k])
				{
					visit[k] = true;
					std::cout << vexs[k];
					Queue.push_back(k);
				}
		}
	}
}

template <class type>void Graph<type>::BFSTraverse()
{
	if (applyVisit())
	{
		std::cout << "������ȱ�����" << std::endl;
		for (int i = 0; i < numVertexs; i++)
			if (!visit[i])
				BFS(i);
	}
}
template <class type>void Graph<type>::DFS(int i)
{
	visit[i] = true;
	std::cout << vexs[i];
	for (int j = 0; j < numVertexs; j++)
		if (arcs[i*numVertexs + j] != _INFINITY && arcs[i*numVertexs + j] != 0)
			if (!(visit[j]))
				DFS(j);
}


template <class type>inline void Graph<type>::DFSTraverse()
{
	if (applyVisit())
	{
		std::cout << "��ȱ���:" << std::endl;
		for (int i = 0; i < numVertexs; i++)
			if (!visit[i])
				DFS(i);
	}
}

template<class type>void Graph<type>::CalDegree()
{
	int D;
	for (int i = 0; i < numVertexs; i++)
	{
		D = 0;
		for (int j = 0; j < numVertexs; j++)
		{
			if (arcs[i*numVertexs + j] != _INFINITY)
				D++;
		}
		std::cout << "��" << i + 1 << "�����Ķ�Ϊ��" << D << std::endl;
	}

}

template<class type>bool Graph<type>::CreateGraph()
{
	std::cout << "��ֱ�����ͼ�еĽ�������ͱ�������";
	std::cin >> numVertexs >> numEdges;
	if (!(vexs = new type[numVertexs]))  //����������
		return false;
	if (!(arcs = new type[numVertexs*numVertexs])) //�����ڽӾ���
		return false;
	//memset(arcs, _INFINITY, numVertexs*numVertexs);  //��ʼ���ڽӾ���
	for (int i = 0; i < numVertexs*numVertexs; i++)
		arcs[i] = _INFINITY;
	for (int i = 0; i < numVertexs; i++)  //����ͼ��������
	{
		std::cout << "�������" << i + 1 << "�������ֵ��";
		std::cin >> vexs[i];
	}
	for (int i, j, w, k = 0; k < numEdges; k++)
	{
		std::cout << "������ߵ����������˳��ֵ��˱ߵ�Ȩֵ��";
		cin >> i >> j >> w;
		arcs[(i - 1)*numVertexs + j - 1] = w;
	}

	return true;
}

template <class type>void Graph<type>::print()
{
	for (int i = 0; i < numVertexs; i++)
	{
		for (int j = 0; j < numVertexs; j++)
			std::cout << arcs[i*numVertexs + j] << "  ";
		std::cout << std::endl;
	}
}

template <class type >bool Graph<type>::applyVisit()
{
	if (visit)
		delete[]visit;
	if (!(visit = new bool[numVertexs]))
		return false;
	for (int i = 0; i < numVertexs; i++)  //��ʼ������������Ϊ0
		visit[i] = false;
	return true;
}

#endif

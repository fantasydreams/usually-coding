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


#define _INFINITY 65535  //定义无穷大

template <typename type> class Graph
{
private:
	type *  vexs; //点数组地址
	type * arcs;  //邻接矩阵的首地址
	int numVertexs, numEdges; //	图中点和边
	bool * visit;  //定义遍历标记矩阵
	bool applyVisit();
	void DFS(int i); //深度优先遍历函数
	void BFS(int i); //广度优先遍历函数
	std::vector<int> Queue;  //队列
public:
	Graph(){}
	~Graph()
	{
		if (vexs)
			delete[] vexs;
		if (arcs)
			delete[] arcs;
	}
	bool CreateGraph();//创建图
	bool CreateVectorGraph()//创建有向图
	{
		if (CreateGraph());
		else return false;
		for (int i = 0; i < numVertexs; i++)
			for (int j = i + 1; j < numVertexs; j++)
				arcs[j*numVertexs + i] = arcs[i*numVertexs + j];  //无向图，为对称矩阵
		return true;
	}
	void print();//测试
	void CalDegree();
	void DFSTraverse(); //深度优先遍历接口
	void BFSTraverse(); //广度优先遍历接口
};

template <class type>void Graph<type>::BFS(int i)
{
	visit[i] = true;
	std::cout << vexs[i];
	int j;
	Queue.push_back(i);  //进队列
	while (!Queue.empty()) //当队列不为空
	{
		j = Queue[0];  //获得第一个元素值
		Queue.erase(Queue.begin()); //第一个元素出队
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
		std::cout << "广度优先遍历：" << std::endl;
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
		std::cout << "深度遍历:" << std::endl;
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
		std::cout << "第" << i + 1 << "个结点的度为：" << D << std::endl;
	}

}

template<class type>bool Graph<type>::CreateGraph()
{
	std::cout << "请分别输入图中的结点总数和边总数：";
	std::cin >> numVertexs >> numEdges;
	if (!(vexs = new type[numVertexs]))  //申请结点数组
		return false;
	if (!(arcs = new type[numVertexs*numVertexs])) //申请邻接矩阵
		return false;
	//memset(arcs, _INFINITY, numVertexs*numVertexs);  //初始化邻接矩阵
	for (int i = 0; i < numVertexs*numVertexs; i++)
		arcs[i] = _INFINITY;
	for (int i = 0; i < numVertexs; i++)  //导入图顶点数据
	{
		std::cout << "请输入第" << i + 1 << "个顶点的值：";
		std::cin >> vexs[i];
	}
	for (int i, j, w, k = 0; k < numEdges; k++)
	{
		std::cout << "请输入边的两个顶点的顺序值与此边的权值：";
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
	for (int i = 0; i < numVertexs; i++)  //初始化遍历矩阵标记为0
		visit[i] = false;
	return true;
}

#endif

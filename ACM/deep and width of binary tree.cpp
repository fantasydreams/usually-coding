#include <iostream>

using namespace std;

struct node
{
	int left, right;
};

int deep(struct node * p,int nnum)
{
	int left, right;
	if (nnum)
	{
		left = deep(p, p[nnum-1].left) + 1;
		right = deep(p, p[nnum-1].right) + 1;
		return (left > right) ? left : right;
	}
	else
		return 0;
}

void width(struct node * p, int nnum,int *n,int layer)
{
	if (nnum)
	{
		n[layer] += 1;
		width(p, p[nnum - 1].left,n,layer+1);
		width(p, p[nnum - 1].right,n,layer+1);
	}
}

int getmax(int *n,int num)
{
	int max = 0;
	for (int i = 0; i < num; i++)
		if (n[i]>max)
			max = n[i];
	return max;
}

int main()
{
	int num,leftdeep = 0,rightdeep = 0,*n;
	cin >> num;
	while (!num)
		cin >> num;
	struct node *p = new struct node[num];  //use merex save node info
	n = new int[num] ;  //save the number of per layer
	for (int i = 0; i < num; i++)
	{
		cin >> p[i].left;
		cin >> p[i].right;
		n[i] = 0;
	}
	
	width(p, 1, n, 0);
	cout << getmax(n, num) << ' ' << deep(p, 1) << endl;
	return 0;
}
#include <iostream>

using namespace std;

struct node
{
	int left, right;
};

//前序遍历
void pre(struct node * p,int nnum)
{
	cout << nnum;
	if (p[nnum-1].left)
		pre(p, p[nnum-1].left);
	if (p[nnum-1].right)
		pre(p, p[nnum-1].right);
}
 
//中序遍历
void in(struct node * p, int nnum)
{
	if (p[nnum - 1].left)
		in(p, p[nnum - 1].left);
	cout << nnum;
	if (p[nnum - 1].right)
		in(p, p[nnum - 1].right);
}

//后序遍历
void post(struct node * p, int nnum)
{
	if (p[nnum - 1].left)
		post(p, p[nnum - 1].left);
	if (p[nnum - 1].right)
		post(p, p[nnum - 1].right);
	cout << nnum;
}

int main()
{
	int num;
	cin >> num;
	while (!num)
		cin >> num;
	struct node *p = new struct node[num];  //use merex save node info
	for (int i = 0; i < num; i++)
	{
		cin >> p[i].left;
		cin >> p[i].right;
	}
	pre(p, 1);
	cout << endl;
	in(p, 1);
	cout << endl;
	post(p, 1);
	cout << endl;
	system("pause");
	return 0;
}
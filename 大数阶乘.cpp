//��׳˺ʹ�����
//��������Ľ׳˺ͣ����ǱȽ��˷�cpu��Դ
#include <iostream>

using namespace std;

void main()
{
	system("color F1");
	int sum[7000] = { 0 }, Temp[6000] = { 0 };
	Temp[0] = 1;
	int n,j,flag;
	cout << "�������������֣���������Ľ׳˵�ֵ�ó��ȳ���6000λ����������������ȷ��";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (j = 0; j < 6000; j++)
		{
			Temp[j] *= i;
		}
		for (int k = 0; k < 6000; k++)
		{
			if (Temp[k] >= 10)
			{
				Temp[k + 1] += Temp[k] / 10;
				Temp[k] = Temp[k] % 10;
			}
		}
		for (int m = 0; m < 6000; m++)
			sum[m] += Temp[m];
		for (int k = 0; k < 6000; k++)
		{
			if (sum[k] >= 10)
			{
				sum[k + 1] += sum[k] / 10;
				sum[k] = sum[k] % 10;
			}
		}
	}
	for (flag = 6999; sum[flag] == 0; flag--);
	cout << "��" << n << "���׳˺ͣ� " <<endl;
	for (; flag >= 0; flag--)
		cout<<sum[flag];
	cout << endl;
	system("pause");
}
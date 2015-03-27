#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<iomanip>
#include<utility>
#include<algorithm>


using namespace std;
vector<pair<string,int>> word;

void findsameword(string Word);
bool sortWord(pair<string, int> elem1, pair<string, int> elem2);

void main()
{
	system("color F1");
	string temp;
	ifstream TextFile;
	TextFile.open("test.txt");
	while (TextFile >> temp)
	{
		findsameword(temp);
	}
	sort(word.begin(), word.end(),sortWord);
	cout << "出现单词频率前十的是：" << endl;
	for (vector<pair<string, int>>::iterator itor = word.begin(); itor != word.begin()+10; itor++)
	{
		cout << "单词：" << setw(38) << setiosflags(ios::left) << itor->first << "数量：" << itor->second << endl;
	}
	system("pause");
}

void findsameword(string Word)
{
	bool flag = false;
	for (vector<pair<string,int>>::iterator itor = word.begin(); itor != word.end(); itor++)
	{
		if (Word == itor->first)
		{
			itor->second += 1;
			flag = true;
			break;
		}

	}
	if (!flag)
	{
		word.push_back(make_pair(Word, 1));
	}
}

bool sortWord(pair<string, int> elem1, pair<string, int> elem2)
{
	return elem1.second > elem2.second;
}
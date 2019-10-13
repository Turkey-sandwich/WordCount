// wordcount3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
//---------------------------------------------
int countwords(string s)
{
	int countword = 0;
	unsigned int count = 0;
	char c;
	bool wordjudge = false;
	int i = 0, j = 0;
	while (count < s.size())
	{
		c = s[count];
		count++;
		if (isalpha(c) || isdigit(c))
		{
			j++;
			if (isalpha(c))
			{
				i++;
			}
			else i = 0;
			if (i == 4 && j == 4)
			{
				wordjudge = true;
			}//判断是否为单词 

		}
		else
		{
			if (wordjudge == true)
			{
				countword++;
				wordjudge = false;
			}
			i = j = 0;
		}
	}
	c = s[count];
	if (wordjudge == true)
	{
		countword++;
		wordjudge = false;
		i = j = 0;
	}
	return countword;
}
//---------------------------------------------
int main()
{
	ifstream ifs("chengji.txt");
	ofstream fout;
	string s;
	char r[10][20];
	int br = 1;
	unsigned int count = 0;
	int number = 0;
	getline(ifs, s, '\0');
	while (count < s.length())
	{
		if (s[count] == '\n')br++;
		count++;
	}
	fout.open("result.txt", ios::app);
	fout << "characters:" << s.length() << endl;
	fout << "lines:" << br << endl;
	fout << "words:" << countwords(s) << endl;
	fout.close();
	//	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

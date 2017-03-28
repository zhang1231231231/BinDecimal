// ***********************************************************************
// Assembly         : 
// Author           : zhang
// Created          : 03-28-2017
//
// Last Modified By : zhang
// Last Modified On : 03-28-2017
// ***********************************************************************
// <copyright file="BinDecimal.cpp" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary>
//
// 有一个介于0和1之间的实数，类型为double，返回它的二进制表示。如果该数字无法精确地用32位以内的二进制表示，返回“Error”。
// 给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
// 测试样例：
// 0.625
// 返回：0.101
//
// </summary>
// ***********************************************************************

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class BinDecimal {
public:
	string printBin(double num) {
		// write code here
		double a = num;
		vector<int> vct;
		while (a > 0.000001f)
		{
			if (vct.size() >= 32)
			{
				return "Error";
			}
			a *= 2;
			if (a == 1)
			{
				vct.push_back(1);
				break;
			}
			else if (a > 1)
			{
				vct.push_back(1);
				a -= 1;
			}
			else {
				vct.push_back(0);
			}
		}
		//cout << vct.size() << endl;
		double result = 0;
		for (int i = 0; i < vct.size(); i++)
		{
			result += vct[i] * pow(10, -1 - i);
		}
		//cout << result << endl;
		string resString;
		char s[100] = { 0 };
		// 也可以使用标准库to_string()直接转换
		sprintf_s(s, (vct.size()+2)*sizeof(double),"%f", result);
		resString = s;
		string subStr = resString.substr(0, vct.size() + 2);
		//strcpy(resString, s);
		//= to_string(result);
		return subStr;
	}
};

int main()
{
	BinDecimal bin;
	cout << bin.printBin(0.46502) << endl;
	return 0;
}


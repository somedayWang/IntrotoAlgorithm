// lab4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

#define defl 10000000

void makepath(int i, int j, vector<vector<int >> p, vector<int>& path) 
{
	if (p[i][j] == i) return;
	else 
	{
		path.insert(path.begin() + 1, p[i][j]);
		makepath(i, p[i][j], p, path);
	}
}

int main() {
	vector<vector<int>>d;//记录所有点，以及其到其他点的最短路径的权重
	vector<vector<int>>p;//记录所有最短路径的连通关系，记录某一点是否为其路径上的中间结点
	int v, e, temp, d1, d2, w;
	cin >> v;
	cin >> e;
	for (int i = 0; i < v; i++) 
	{
		d.push_back(vector<int>(v, 0));
		p.push_back(vector<int>(v, 0));
		for (int j = 0; j < v; j++) 
		{
			if (i == j)	d[i][j] = 0;//初始化点到自己的距离为0
			else d[i][j] = defl;//初始化所有点距离为无限远
			p[i][j] = -1;//初始化所有点，不连通
		}
	}
	for (int i = 0; i < e; ++i) 
	{
		cin >> d1;
		cin >> d2;
		cin>> w;
		d[d1][d2] = w;
		p[d1][d2] = d1;
	}
	for (int k = 0; k < v; ++k) 
	{
		for (int i = 0; i < v; ++i) 
		{
			for (int j = 0; j < v; ++j) 
			{
				if (i != j) 
				{
					temp = d[i][k] + d[k][j];
					if (d[i][j] > temp) 
					{
						d[i][j] = temp;//更新最短路径权重，k为中间结点
						p[i][j] = p[k][j];//添加k为中间结点
					}
				}
			}
		}
	}
	for (int i = 0; i < v; ++i) 
	{
		for (int j = 0; j < v; ++j) 
		{
			if (i != j)
			{
				vector<int > path;//用以寻找最短路径
				cout << "Node." << i << " to Node." << j << " thw cloest way is ";
				path.push_back(i);
				path.push_back(j);
				makepath(i, j, p, path);
				for (vector<int>::iterator iter = path.begin(); iter != path.end(); iter++)
				{
					if(iter == path.end()-1)	cout << *iter;
					else cout << *iter << "→" ;

				}
				cout << "  the distance is " << d[i][j] << "\n";
			}
		}
	}
	getchar();
	getchar();
	return 0;
}


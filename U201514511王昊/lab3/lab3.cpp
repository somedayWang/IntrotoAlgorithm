// lab3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;
int root[100][100],d;
void right(int a, int b, int k);
void left(int a, int b, int k);
void left(int a,int b,int k)
{
	if (a <= b)
	{
		cout << "k" << root[a][b] << "为k" << k << "的左孩子\n";
		left(a, root[a][b]-1, root[a][b]);
		right(root[a][b]+1,b , root[a][b]);
		return;
	}
	else
	{
		cout << "d" << d << "为k" << k << "的左孩子\n";
		d++;
		return;
	}
}
void right(int a, int b, int k)
{
	if (a <= b)
	{
		cout << "k" << root[a][b] << "为k" << k << "的右孩子\n";
		left(a, root[a][b] - 1, root[a][b]);
		right(root[a][b]+1, b, root[a][b]);
		return;
	}
	else
	{
		cout << "d" << d << "为k" << k << "的右孩子\n";
		d++;
		return;
	}
}

int main()
{
	int n,*rootlist,s=0;
	cout << "enter the num of nodes\n";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "enter  " << n - i + 1 << " nums mean " << i << " to n nodes\n";
		for (int j = i; j <= n; j++)
		{
			cin >> root[i][j];
		}
	}
	cout << "k" << root[1][n] << "为根\n";
	left(1, root[1][n]-1, root[1][n]);
	right(root[1][n]+1,n, root[0][n]);
	getchar();
	getchar();
	return 0;
}


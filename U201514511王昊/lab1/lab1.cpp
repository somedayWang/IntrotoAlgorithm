// lab1.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

struct point//代表点的类
{
	double x;
	double y;
	point(double x, double y) : x(x), y(y) {};
};

struct point_pair//代表点对的类
{
	point p1, p2;
	point_pair(point d1, point d2) :p1(d1), p2(d2) {};
	double dist()
	{
		return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
	}
};

bool compx(const point &p1, const point &p2)//比较点的x坐标进行排序
{
	return p1.x < p2.x;
}

void addpair(vector<point_pair> &cloest_pairs,point p1, point p2)//添加点对到最小点对的表中
{
	point_pair pair(p1, p2);
	if (cloest_pairs.empty())
	{
		cloest_pairs.push_back(pair);
	}
	else
	{
		if (pair.dist() < cloest_pairs[0].dist())
		{
			cloest_pairs.clear();
			cloest_pairs.push_back(pair);
		}
		else
		{
			if (pair.dist() == cloest_pairs[0].dist())	cloest_pairs.push_back(pair);
		}
	}
}

void dcase(vector<point> &p, vector<point_pair> &cloest_pairs)//划分长度为2d的区域
{
	vector<point> left;
	vector<point> right;
	double mid;
	if (p.size() % 2)
	{
		mid = p[p.size() / 2].x;
		left.push_back(p[p.size() / 2]);
		int i = 1;
		while (1) {
			if (i <= p.size() / 2)  //向左边划分
			{
				if (mid - p[p.size() / 2 - i].x <= cloest_pairs[0].dist())
				{
					left.push_back(p[p.size() / 2 - i]);
					i++;
				}
				else break;
			}
			else break;
		}
		i = 1;
		while (1) 
		{
			if (i <p.size() - p.size() / 2) //向右边划分
			{
				if (mid - p[p.size() / 2 +i].x <= cloest_pairs[0].dist()) 
				{
					right.push_back(p[p.size() / 2 +i]);
					i++;
				}
				else break;
			}
			else break;
		}
	}
	else {
		mid = p[p.size() / 2 - 1].x;
		left.push_back(p[p.size() / 2 - 1]);
		int i = 1;
		while (1) 
		{
			if (i <= p.size() / 2 - 1)  //向左边划分
			{
				if (mid - p[p.size() / 2 - 1 - i].x <= cloest_pairs[0].dist()) 
				{
					left.push_back(p[p.size() / 2 - 1 - i]);
					i++;
				}
				else break;
			}
			else break;
		}
		i = 1;
		while (1) 
		{
			if (i < p.size() / 2  + 1) //向右边划分
			{
				if (mid - p[p.size() / 2 - 1 + i].x <= cloest_pairs[0].dist()) 
				{
					right.push_back(p[p.size() / 2 - 1 + i]);
					i++;
				}
				else break;
			}
			else break;
		}
	}
	for (int i = 0; i < left.size(); i++) 
	{
		for (int j = 0; j < right.size(); j++) 
		{
			addpair(cloest_pairs, left[i], right[j]);
		}
	}
}

void cloest_pair(vector<point> &p, vector<point_pair> &cloest_pairs)//分治递归过程
{
	if (p.empty() || p.size() == 1)		return;
	else	if (p.size() == 2)
		{
			addpair(cloest_pairs, p[0], p[1]);
			return;
		}
	else
	{
		if (p.size() % 2)
		{
			vector<point> p1(p.begin(), p.begin() + p.size() / 2 + 1);
			vector<point> p2(p.begin() + p.size() / 2 + 1, p.end());
			cloest_pair(p1, cloest_pairs);
			cloest_pair(p2, cloest_pairs);
		}
		else
		{
			vector<point> p1(p.begin(), p.begin() + p.size() / 2);
			vector<point> p2(p.begin() + p.size() / 2, p.end());
			cloest_pair(p1, cloest_pairs);
			cloest_pair(p2, cloest_pairs);
		}
		dcase(p, cloest_pairs);
	}
	return;
}

void main() {
	int n;
	double x, y;
	vector<point> p;
	p.reserve(1000 * sizeof(point));
	vector<point_pair> cloest_pairs;
	cout << "enter number of points\n" ;
	cin >> n;
	cout << "(x,y)?\n";
	for (int i = 0; i < n; i++) {//输入n个点
		cin >> x;
		cin >> y;
		p.push_back(point(x, y));
	}
	sort(p.begin(), p.end(), compx);
	cloest_pair(p, cloest_pairs);
	cout << "the cloest_pair points\n";
	cout << "distance :"<< cloest_pairs[0].dist()<<endl;
	for (int i = 0; i < cloest_pairs.size(); i++) {//输出所有最近点对
		cout << "(" << cloest_pairs[i].p1.x << "," << cloest_pairs[i].p1.y<< ") and (" << cloest_pairs[i].p2.x << "," << cloest_pairs[i].p2.y << ")\n";
	}
	getchar();
	getchar();
	return;
}



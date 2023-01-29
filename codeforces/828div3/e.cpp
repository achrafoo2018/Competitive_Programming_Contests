#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <map>
using namespace std;
vector <int> resh_ar(int n)
{
	vector <bool> u(n + 10 , false);
	vector <int> p;
	for (int i = 2; i <= n; i++)
	{
		if (u[i] == false)
		{
			p.push_back(i);
			int j = i+i;
			while (j <= n)
			{
				u[j] = true;
				j += i;
			}
		}
	}
	return p;
}
long long sqr(long long a, int n)
{
	long long r = 1;
	for (int i = 0; i < n; i++)
		r *= a;
	return r;
}
int main()
{
	int tt;
	cin >> tt;
	vector <int> prost = resh_ar(101000);
	int n = tt;
	while (tt--)
	{
		long long int a, b, c, d;
		cin >> a >> b >> c >> d;
		long long ab = a * b;
		map <int, int> p;
		for (int i = 0; i <= ab; i++)
		{
			if (prost[i] > ab)
				break;
			if (ab % prost[i] == 0)
			{
				int r = 0;
				while (ab % prost[i] == 0)
				{
					r++;
					ab /= prost[i];
				}
				if (r != 0)
				{
					p[prost[i]] = r;
				}
			}
		}
		if (ab != 0)
		{
			p[ab] = 1;
		}
		long long y = 1;
		bool f = false;
		for (int ij = a + 1; ij <= c; ij++)
		{ 
			y = 1;
			map <int, int> p2;
			int u = ij;
			for (int i = 0; i <= ij; i++)
			{
				if (prost[i] > u)
					break;
				int r = 0;
				if (u % prost[i] == 0)
				{
					while (u % prost[i] == 0)
					{
						r++;
						u /= prost[i];
					}
				}
				if (r != 0)
				{
					p2[prost[i]] = r;
				}
			}
			if (u != 0)
			{
				p2[u] = 1;
			}
			//if (tt == 2)
			//	cout << endl;
			for (auto& item : p)
			{
				if (item.second - p2[item.first] > 0)
				{
					//cout << item.second - p2[item.first] << endl;
					y *= sqr(item.first, item.second - p2[item.first]);
				}
			}
			if (d / y - b / y > 0)
			{
				f = true;
				cout << ij << " " << (d / y) * y << endl;
				break;
			}
		}
		if (f == false)
			cout << "-1 -1\n";
	}
}
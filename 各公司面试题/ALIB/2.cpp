//联盟问题：并查集
#include<iostream>
#include<vector>
#include<algorithm>
#include <cassert>
#include<sstream>
#include <stack>
#include<unordered_map>
using namespace std;
unordered_map<int, int> mp;
vector<int> vec;
int find(vector<int>& dp, int x)
{
	while (dp[x] != x)
	{
		x = dp[x];
	}
	return dp[x];
}
bool check(vector<int>& dp, int a, int b)
{
	int x = find(dp, a);
	int y = find(dp, b);
	if (x == y)
		return true;
	else
		return false;
}
int func(vector<int>& dp, int a, int b)
{
	int x = find(dp, a);
	int y = find(dp, b);
	if (x == y)
		return -1;
	else
	{
		int num = (x + y) ^ (abs(vec[x] - vec[y]));
		if (x < y)
		{
			dp[y] = x;
			vec[x] = vec[x] + vec[y];
		}
		else
		{
			dp[x] = y;
			vec[y] = vec[x] + vec[y];
		}
		return num;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int cnt = n;
	vec = vector<int>(n + 1);
	vector<int> dp(n + 1);
	for (int i = 0; i < n + 1; i++)
		dp[i] = i;
	int id = 1;
	int x;
	while (cnt--)
	{
		cin >> x;
		vec[id++] = x;
	}
	cnt = m;
	int a, b, t, q;
	while (cnt--)
	{
		cin >> t >> a >> b;
		if (t == 1)
		{
			q = func(dp, a, b);
			if (q != -1)
				cout << q << endl;
		}
		else
		{
			if (check(dp, a, b))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}

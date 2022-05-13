//编译器求大小问题

#include<iostream>
#include<vector>
#include<algorithm>
#include <cassert>
#include<sstream>
#include <stack>
using namespace std;
bool check(string& str)
{
	for (char c : str)
	{
		if (c == '[')
			return true;
	}
	return false;
}

int main()
{
	string s;
	getline(cin, s);
	stringstream ss(s);
	string temp;
	int cnt = 0;
	int mod = 1;
	int z = 0;
	while (getline(ss, temp, ' '))
	{
        cout<<"temp:"<<temp<<endl;
		if (mod)
		{
			if (temp == "int")
				z = 4;
			else if (temp == "char")
				z = 1;
			else if (temp == "long")
				z = 8;
			mod = 0;
			continue;
		}
		stringstream ss2(temp);
		string temp2;
		while (getline(ss2, temp2, ','))
		{
            cout<<"temp2:"<<temp2<<endl;
			if (check(temp2))
			{
				stack<char> st;
				vector<int> vec;
				int i, j;
				int num = 1, n = temp2.size();
				for (int k = 0; k < n; k++)
				{
					if (temp2[k] == '[')
					{
						i = k + 1;
					}
					else if (temp2[k] == ']')
					{
						j = k - 1;
						string str = temp2.substr(i, j - i + 1);
						vec.push_back(atoi(str.c_str()));
					}
				}
				for (int x : vec)
					num *= x;
				cnt += num * z;
			}
			else
			{
				cnt += z;
			}
		}
	}
	cout << cnt << endl;
}



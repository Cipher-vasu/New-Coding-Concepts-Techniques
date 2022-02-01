#include<bits/stdc++.h>
using namespace std;

int prec(char c)
{
	if (c == '^')
	{
		return 3;
	}
	else if (c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	return -1;
}

string convert_infix_to_prefix(string s)
{
	string ans;
	stack<char> st;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			ans.push_back(s[i]);
		}
		else if (s[i] == '(')
		{
			st.push('(');
		}
		else if (s[i] == ')')
		{
			while (st.top() != '(')
			{
				ans.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
		else
		{
			while (!st.empty() && prec(s[i]) <= prec(st.top()) )
			{
				ans.push_back(st.top());
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	string ans = convert_infix_to_prefix(s);
	cout << ans;
	return 0;

}
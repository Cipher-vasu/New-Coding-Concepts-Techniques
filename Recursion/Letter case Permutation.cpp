#include<bits/stdc++.h>
using namespace std;

void helper(string a, string temp, vector<string>& ans)
{
	if (a.size() == 0)
	{
		ans.push_back(temp);
		return;
	}
	if (a[0] >= '0' && a[0] <= '9')
	{
		temp.push_back(a[0]);
		a.erase(a.begin() + 0);
		helper(a, temp, ans);
	}
	else
	{
		string temp1 = temp;
		string temp2 = temp;
		if (a[0] >= 'A' && a[0] <= 'Z')
		{
			temp1.push_back(a[0]);
			temp2.push_back(a[0] + 32);
		}
		else
		{
			temp1.push_back(a[0]);
			temp2.push_back(a[0] - 32);
		}
		a.erase(a.begin() + 0);
		helper(a, temp1, ans);
		helper(a, temp2, ans);
	}

}

int main()
{
	string a;
	cin >> a;
	string temp = "";
	vector<string> ans;
	helper(a, temp, ans);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}
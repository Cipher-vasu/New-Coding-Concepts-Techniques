#include<bits/stdc++.h>
using namespace std;

void helper(string a, string temp, vector<string>& ans)
{
	if (a.size() == 0)
	{
		ans.push_back(temp);
		return;
	}
	string temp1 = temp;
	string temp2 = temp;
	temp2.push_back(' ');
	temp2.push_back(a[0]);
	temp1.push_back(a[0]);
	a.erase(a.begin() + 0);
	helper(a, temp1, ans);
	helper(a, temp2, ans);

}

int main()
{
	string a;
	cin >> a;
	string temp = "";
	temp.push_back(a[0]);
	a.erase(a.begin() + 0);
	vector<string> ans;
	helper(a, temp, ans);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}
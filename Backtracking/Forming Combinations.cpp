/*
*/
#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> temp, int start, int n, int k, vector<vector<int>>& ans)
{
	if (temp.size() == k)
	{
		ans.push_back(temp);
		return;
	}
	for (int i = start; i <= n; i++)
	{
		//if(st.find(i)==st.end())
		//{
		temp.push_back(i);
		//st.insert(i);
		helper(temp, i + 1, n, k, ans);
		temp.pop_back();
		//st.erase(i);
		//}
	}
}

vector<vector<int>> combine(vector<int>& nums, int n, int k) {
	vector<vector<int>> ans;
	vector<int> temp;
	//unordered_set<int> st;
	helper(temp, 1, n, k, ans);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	vector<vector<int>> ans = combine(nums, n, k);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool subsequences_with_sum_k(vector<int>& vec, int k, int index, int sum, vector<int> temp, vector<vector<int>>& ans)
{
	//cout<<sum<<endl;
	if (index >= vec.size())
	{
		if (sum == k)
		{
			ans.push_back(temp);
			return true;
		}
		return false;
	}
	if (subsequences_with_sum_k(vec, k, index + 1, sum, temp, ans) == true)
	{
		return true;
	}
	temp.push_back(vec[index]);
	sum += vec[index];
	if (subsequences_with_sum_k(vec, k, index + 1, sum, temp, ans) == true)
	{
		return true;
	}
	return false;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	vector<vector<int>> ans;
	vector<int> temp;
	bool flag = subsequences_with_sum_k(vec, k, 0, 0, temp, ans);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
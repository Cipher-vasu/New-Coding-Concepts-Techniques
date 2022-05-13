/*
Forming Permutations of the given array/string using backtracking
*/
#include<bits/stdc++.h>
using namespace std;

// Instead of using swap function we can use unordered_set but in case of set every time we will run our
//loop from 0th index and check whether the current element is present in the set or not, If it is not
//present then we will push it to the current permutation we are forming and call the function again

// how to solve the problem using set refer Permutations code in leetcode.
void helper(vector<int>& nums, int start, int end, vector<vector<int>>& ans)
{

	if (start == end)
	{
		ans.push_back(nums);
		return;
	}
	for (int i = start; i <= end; i++)
	{
		swap(nums[start], nums[i]);
		helper(nums, start + 1, end, ans);
		swap(nums[start], nums[i]);  // Backtrack
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> ans;
	/* Naive Approach
	sort(nums.begin(),nums.end());
	ans.push_back(nums);
	while(next_permutation(nums.begin(),nums.end()))
	{
	    ans.push_back(nums);
	}
	*/

	// Using Backtracking
	helper(nums, 0, nums.size() - 1, ans);
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	vector<vector<int>> ans = permute(nums);
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
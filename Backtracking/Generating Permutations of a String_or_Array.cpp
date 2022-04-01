/*
https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/
#include<bits/stdc++.h>
using namespace std;

// void permute1(string st, int start, int end, vector<string>& ans)
// {
// 	if (start == end) // Base Condition - When a
// 	{
// 		ans.push_back(st);
// 		return;
// 	}
// 	for (int i = start; i <= end; i++)
// 	{
// 		swap(st[start], st[i]);
// 		permute(st, start + 1, end, ans);
// 		swap(st[start], st[i]); // Backtrack
// 	}
// }

void permute2(string st, string temp, vector<string>& ans, unordered_set<char>& s)
{
	if (temp.size() == st.size())
	{
		ans.push_back(temp);
		return;
	}
	for (int i = 0; i < st.size(); i++)
	{
		if (s.find(st[i]) == s.end())
		{
			temp.push_back(st[i]);
			s.insert(st[i]);  // Insert current character in the set so in the next recursive call this character is not pushed to temp
			permute2(st, temp, ans, s);
			temp.pop_back();  // These two lines are our bactrack code
			s.erase(st[i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string st;
	cin >> st;
	vector<string> ans;
	//permute1(st, 0, st.size() - 1, ans);
	unordered_set<char> s;
	string temp;
	permute2(st, temp, ans, s);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
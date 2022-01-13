/*
Question - Two Sum
Naive Approach will be two for loops O(n*n)
Better Approach will to sort the array and find the target sum using Two Pointers Approach O(n * log(n))
Best Approach will be to use the unordered_set the approach will be to search if the (k-nums[i]) is
present in the set, if it is present then we will return true and if not present then we will insert the
element at ith index in nums in set
Suppose if we are asked to return the indexes of the element whose sum is equal to target then instead of
unordered_set we can use unordered_map with the element as key and its index as the value
*/

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& nums, int k) {
    /* Naive Approach
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0;j<nums.size();j++)
        {
            if((nums[i]+nums[j])==k)
            {
                return true;
            }
        }
    }
    return false;*/
    /* Better Approach
    sort(nums.begin(),nums.end());
    int low=0;
    int high=nums.size()-1;
    while(low<high)
    {
        if((nums[low]+nums[high])==k)
        {
            return true;
        }
        else if((nums[low]+nums[high])>k)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    return false;
    */
    // Best Approach
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        if (st.find(k - nums[i]) != st.end())
        {
            return true;
        }
        st.insert(nums[i]);
    }
    return false;
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
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << solve(nums) << endl;
    return 0;
}

/*
Question - Max Product of Two Numbers in binarysearch
In these type of questions where we have to find the largest or smallest ans of some arithmetic operation
the best approach could be just keep track of maximum/minimum till now and then perform operation of
maximum/minimum with the current value and update the answer according to the need.
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {
    /*Naive Approach O(n*n)
    int maxp=-100000000;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if((nums[i]*nums[j])>maxp)
            {
                maxp=nums[i]*nums[j];
            }
        }
    }
    return maxp;
    */
    /*Better Approach
    sort(nums.begin(),nums.end());
    int n=nums.size();
    return nums[0]*nums[1]>nums[n-1]*nums[n-2]?nums[0]*nums[1]:nums[n-1]*nums[n-2];*/
    /* Best Approach*/
    int maxi = nums[0];
    int mini = nums[0]; // We are taking min because product of two negatives is positive that's why we are tracking minimum value also
    int maxp = INT_MIN;
    for (int i = 1; i < nums.size(); i++)
    {
        // we are first finding the max among product of maximum and current value & product of minimum and
        // current value and then comparing it with maxp
        maxp = max(maxp, max(maxi * nums[i], mini * nums[i]));
        mini = min(mini, nums[i]);
        maxi = max(maxi, nums[i]);
    }
    return maxp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
#endif
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

/* Remove Duplicates
Given an integer array vec sorted in non-decreasing order,
remove some duplicates in-place such that each unique element appears at most k times.
The relative order of the elements should be kept the same.
Return len after placing the final result in the first len slots of vec.
*/
#include<bits/stdc++.h>
using namespace std;

int remove_duplicates(vector<int>& vec, int k)
{
    if (k == 0)
    {
        return 0;
    }
    if (vec.size() <= k)
    {
        return vec.size();
    }

    int insert_pos = k - 1; // insert_pos will be k-1 bcoz vectors are 0-indexed like suppose are k=2 then in the array=[0,0,1,1,1,1]
    // upto 1st index the value has repeated k times

    for (int i = k; i < vec.size(); i++)
    {
        if (vec[i] != vec[insert_pos - (k - 1)]) // we are subtracting (k-1) from insert position instead oof k because array is 0-indexed if it was 1-indexed then we would have subtracted k
        {
            vec[++insert_pos] = vec[i];
        }
    }
    return insert_pos + 1;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    int len = remove_duplicates(vec, k);
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}


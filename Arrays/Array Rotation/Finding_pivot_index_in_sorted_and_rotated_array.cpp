// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int findpivotindex(int A[], int l, int h, int n)
{
    if (A[l] < A[h]) // If this condition is true it means that our array is sorted
    {
        return l;
    }
    int mid = l + (h - l) / 2;
    int next = (mid + 1) % n;            // We are taking mod to avoid Segmentation Fault in
    int prev = (mid + n - 1) % n; // calculting next and prev
    if (A[mid] < A[next] && A[mid] < A[prev]) // In sorted & rotated array the element at pivot index
    {   // is always smaller than the previous and next element
        return mid;
    }
    if (A[mid] <= A[h]) // If the middle element is smaller than or equal to the end element then
    {   // array from mid to high is sorted that means our pivot index is not present
        return findpivotindex(A, l, mid - 1, n);  // between mid to high therefore we will now search between
    }                                          // low to mid-1 indexes

    return findpivotindex(A, mid + 1, h, n); // Otherwise the pivot index must be between mid & high
}
int search(int A[], int l, int h, int n) {
    //complete the function here
    /* Naive Approach
    for(int i=l;i<=h;i++)
    {
        if(A[i]==key)
        {
            return i;
        }
    }
    return -1;*/
    int pivot = findpivotindex(A, l, h, n); // if pivot==0 then are array is not rotated
    return pivot;
}


// { Driver Code Starts.
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];

        cout << search(A, 0, n - 1, n)  << endl;
    }
    return 0;
}  // } Driver Code Ends
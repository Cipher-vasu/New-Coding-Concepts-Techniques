/*
This approach/concept can be very useful when we have to move a certain number to th end of the array
or where we have to remove some elements from the array. The main intution is that we will maintain a
counter variable which will be initailsed to zero and as we encounter a valid number according to the given
conditions we will insert that element at count index and increment count. Therefore, in our array/vector
from 0 to count(not inclusive) we will have our valid numbers.
for eg like
Move all zeros to the end of the array(gfg)
Remove the given value from the array (Remove Element in leetcode)
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    /* Naive Approach using temp array in O(n) time and O(n) extra space
    int b[n];
    int start = 0;             // from 0th index we will insert non-zero element in as we encounter so their order is maintained
    int end = n - 1;           // and we will insert 0 from end and decrement end pointer
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            b[end] = a[i];
            end--;
        }
        else
        {
            b[start] = a[i];
            start++;
        }
    }          // After this for loop our desired array will contain all the non zero elements first in b then all zero
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];                // Now we have to just copy our temp array to original array
        cout << a[i] << " ";
    }*/
    // Efficient Approach:-
    int count = 0;        // An count variable to count the non-zero elements in the array
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)               // If a[i] is a non-zero element we will insert the element at
        {   // count index and increment count
            a[count] = a[i];        // since we are inserting the non-zero elements as we encounter them
            count++;                // therefore the order of non-zero elements will be maintained
        }
    }   //so after this for loop till count index we will have our all non-zero elements in the original order

    for (int i = count; i < n; i++)       // Since we have taken care of tha all the non-zero elements in the
    {   // array the only thing is left to insert zero's at the end
        a[i] = 0;                         // till count we have our non-zero elements therefore from count till
    }                                     // end of the array we have to insert zero's.
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}



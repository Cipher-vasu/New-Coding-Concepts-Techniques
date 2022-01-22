/*
Maximising the given number by changing 6 to 9 or 9 to 6 once
The main intuition of the efficient approach is we will keep track of the significant bit where changing the
digit from 6 to 9 will maximise our so for this we are keeping track of digit place and updating max_digit_place
where 6 is found;

Note: The efficient approach of this question can be used in the question where we have to maximise or
      minimise the number by changing digits for given time like in this question we have to change the digit only
      once.
*/

#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    /* Naive Approach  T.C - O(log(n)) 2 passes and S.C - O(log(n))
        vector<int> a;               // declaring an array to store the digits of the number given
        while(num>0)                //Extracting digits of the number given
        {
            a.push_back((num%10));
            num=num/10;
        }
        int flag=0;
        for(int i=a.size()-1;i>=0;i--)  // we are traversing from end because we have to maximise the number
        {                               // & we can maximise the number by changing the most significant bit
            //cout<<a[i]<<endl;         // in the lasr index of array MSB will be stored and in first LSB
            if(a[i]==6 && flag!=1)
            {
                a[i]=9;
                flag=1;
            }
            num=num*10+a[i];

        }
        return num; */

    // Efficient Approach  T.C - O(log(n)) with one pass and constant space


    int digit_place = 1;     // stores digit place like for lsb digit place is 1
    int max_digit_place = 0; // will store max digit place where 6 is present by which changing to 9 will maximise the number
    int n = num;
    while (n > 0)
    {
        if ((n % 10) == 6)
        {
            max_digit_place = digit_place;
        }
        digit_place = digit_place * 10; // updating the digit_place
        n = n / 10;
    }
    num = num + (max_digit_place * 3); // now in the original number we will add the product of (9-6)*max_digit_place

    return 0;
}

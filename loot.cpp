/*

A thief wants to loot houses. He knows the amount of money in each house.
He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin >> n;

     int *arr = new int[n];
     int *dp = new int[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];

     dp[0] = arr[0];
     dp[1] = max(arr[0],arr[1]);

     for(int i = 2; i < n; i++)
          dp[i] = max(arr[i] + dp[i-2], dp[i-1]);

     std::cout << dp[n-1] << '\n';
     delete[] arr;
     delete[] dp;
     return 0;
}

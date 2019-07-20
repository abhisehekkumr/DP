/*
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible
with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long count(int n, long long *dp){

     if(n < 0)
          return 0;

     if( n == 1 || n == 0)
          return 1;

     long long sum = 0;
     for(int i = 1; i <= n; i++){

          if(dp[i-1] == -1)
               dp[i-1] = count(i-1,dp);
          if(dp[n-i] == -1)
               dp[n-i] = count(n-1,dp);

          sum += (dp[n-i] * dp[i-1]);
     }
     return sum;
}

int totalCount(int n){
     long long *dp = new long long[n+1];
     dp[0] = 1;
     dp[1] = 1;
     dp[2] = 2;
     long long sum = 0;

          for(int i = 3; i <= n; i++){
               dp[i] = 0;
               for(int j = 0; j < i; j++)
                    dp[i] = (dp[i] + (dp[j]*dp[i-1-j]))%1000000007;
          }

          /*
          for(int i = 0; i <=n; i++)
               std::cout << dp[i] << ' ';
          std::cout << '\n';
          */
     sum = dp[n];
     delete[] dp;
     return sum;
}



int countBST( int n){
    int arr[10001];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2;i<=n;i++){

        for(int j=0;j<i;j++){

           int temp=(int)(arr[j] * 1l *arr[i-j-1])%mod;
            arr[i] = (arr[i]+temp)%mod;
        }
    }
    return arr[n]%mod;
}

int main(){
     int n;
     cin >> n;

     long long *dp = new long long[n];
     for(int i = 0; i <= n; i++)
          dp[i] = -1;

     //long long result = count(n,dp);
     //int result1 = (int)(result%MOD);
     //std::cout << result1 << '\n';

     std::cout << countBST(n) << '\n';
     delete[] dp;
     return 0;
}

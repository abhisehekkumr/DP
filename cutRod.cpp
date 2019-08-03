#include<iostream>
using namespace std;

int profit(int arr[], int n, int dp[]){
     if(n <= 0)
          return 0;

     if(dp[n] > -1)
          return dp[n];
     int result = 0;

     for(int i = 1; i <= n; i++){
          int ans = 0;
          if(n - i >= 0)
               ans = profit(arr,n-i,dp) + arr[i-1];
          result = result > ans ? result : ans;
     }
     dp[n] = result;
     return result;
}

int profit(int arr[], int n){
     int dp[n+1];
     for(int i = 0; i <= n; i++)
          dp[i] = -1;
     return profit(arr,n,dp);
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << profit(arr,n) << '\n';
}

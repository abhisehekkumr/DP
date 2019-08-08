#include<iostream>
#include<climits>
using namespace std;

int minCoins(int arr[], int n, int sum, int dp[]){
     if(n == 0)
          return INT_MAX;

     if(sum == 0)
          return 0;

     if(dp[n] > -1)
          return dp[n];

     int result = INT_MAX;

     for(int i = 0; i < n; i++){
          if(arr[i] <= sum){
               int sub = minCoins(arr,n,sum-arr[i],dp);
               if(sub != INT_MAX && sub + 1 < result)
                    result = sub + 1;
          }
     }
     dp[n] = result;
     return result;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     int sum;
     cin >> sum;

     int *dp = new int[n+1];
     for(int i = 0; i <= n; i++)
          dp[i] = -1;
     std::cout << minCoins(arr,n,sum,dp) << '\n';
}

/*
4
9 6 5 1
11
*/

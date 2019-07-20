#include<bits/stdc++.h>
using namespace std;

bool isSumPossible(int arr[], int n, int sum){

     bool dp[n+1][sum+1];
     for(int i = 0; i <= sum; i++)
          dp[0][i] = false;

     for(int i = 0; i <= n; i++)
          dp[i][0] = true;

     for(int i = 1; i<= n; i++){
          for(int j = 1; j <= sum; j++){

               dp[i][j] = dp[i-1][j];
               if(j >= arr[i-1])
                    dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
          }
     }
     return dp[n][sum];
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          std::cin >> arr[i];
     int sum;
     std::cin >> sum;

     if(isSumPossible(arr,n,sum))
          std::cout << "Yes" << '\n';
     else
          std::cout << "No" << '\n';
     return 0;
}

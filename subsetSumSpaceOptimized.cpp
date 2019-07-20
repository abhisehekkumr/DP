#include<bits/stdc++.h>
using namespace std;

bool isSumPossible(int arr[], int n, int sum){

     bool dp[2][sum+1];
     for(int i = 0; i <= sum; i++)
          dp[0][i] = false;

     dp[0][0] = true;

     int flag = 1;
     for(int i = 1; i <= n; i++){
          for(int j = 1; j <= sum; j++){
               dp[flag][j] = dp[flag^1][j];

               if(j >= arr[i-1])
                    dp[flag][j] = dp[flag][j] || dp[flag^1][j - arr[i-1]];
          }

          flag = flag^1;
     }

     return dp[flag^1][sum];
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];

     int sum;
     cin >> sum;

     if(isSumPossible(arr,n,sum))
          std::cout << "Yes" << '\n';
     else
          std::cout << "No" << '\n';
     return 0;
}

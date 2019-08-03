#include<iostream>
using namespace std;

int totalSubsets(int arr[], int n, int sum){

     int **dp = new int*[n+1];
     for(int i = 0; i <= n; i++)
          dp[i] = new int[sum+1];

     for(int i = 0; i <= n; i++)
          dp[i][0] = 1;

     for(int i = 1; i <= sum; i++)
          dp[0][i] = 0;

     for(int i = 1; i <= n; i++){
          for(int j = 1; j <= sum; j++){
               dp[i][j] = dp[i-1][j];
               if(j >= arr[i-1])
                    dp[i][j] = dp[i][j] + dp[i-1][j - arr[i-1]];
          }
     }

     return dp[n][sum];
}

int main(){
     int t = 1;
     //cin >> t;
     int arr[100001];
     while(t--){
          int n;
          cin >> n;

          for(int i = 0; i < n; i++)
               cin >> arr[i];

          int sum;
          cin >> sum;

          std::cout << totalSubsets(arr,n,sum) << '\n';
     }
}

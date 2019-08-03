#include<iostream>
using namespace std;
bool isPossible(int arr[], int n, int sum){

     bool **dp = new bool*[n+1];
     for(int i = 0; i <= n; i++){
          dp[i] = new bool[sum+1];
     }

     for(int i = 0; i <= n; i++)
          dp[i][0] = true;

     for(int i = 0; i <= sum; i++)
          dp[0][i] = false;


     for(int i = 1; i <= n; i++){
          for(int j = 1; j <= sum; j++){
               if(j < arr[i-1])
                    dp[i][j] = dp[i-1][j];
               else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
          }
     }

     for(int i = 1; i <= n; i++){
          std::cout << arr[i-1] << ' ';
          for(int j = 1; j <= sum; j++)
               std::cout << dp[i][j] << ' ';
          std::cout << '\n';
     }

     return dp[n][sum];
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int n;
          cin >> n;

          int arr[n];
          int sum = 0;
          for(int i = 0; i < n; i++){
               cin >> arr[i];
               sum += arr[i];
          }

          if(sum%2 == 0){
               if(isPossible(arr,n,sum/2))
                    std::cout << "YES" << '\n';
               else
                    std::cout << "NO" << '\n';
          }
          else
               std::cout << "NO" << '\n';
     }
}

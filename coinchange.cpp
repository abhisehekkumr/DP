#include<iostream>
using namespace std;

int ways(int arr[], int **dp, int n, int value){
     if(value == 0)
          return 1;
     if(n == 0 || value < 0)
          return 0;

     if(dp[n][value] > -1)
          return dp[n][value];

     int ans1 = ways(arr,dp,n,value-arr[0]);
     int ans2 = ways(arr+1,dp,n-1,value);

     dp[n][value] = ans1 + ans2;
     return dp[n][value];
}

int maxValue(int arr[], int n, int value){
     int **dp = new int*[n+1];
     for(int i = 0; i <= n; i++){
          dp[i] = new int[value+1];
          for(int j = 0; j <= value; j++)
               dp[i][j] = -1;
     }
     return ways(arr,dp,n,value);
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int n;
          cin >> n;
          int arr[n];
          for(int i = 0; i < n; i++)
               cin >> arr[i];
          int value;
          cin >> value;
          std::cout << maxValue(arr,n,value) << '\n';
     }
}

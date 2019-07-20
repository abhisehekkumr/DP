#include<iostream>
#include<climits>
using namespace std;

int matrixChain(int arr[], int i, int n, int **dp){
     //std::cout << i << " " << n << '\n';
     if(i == n)
          return 0;
     if(i > n)
          return 0;

     if(dp[i][n] > -1)
          return dp[i][n];

     int min = INT_MAX;
     int count;
     for(int k = i; k < n; k++){
          count = matrixChain(arr,i,k) + matrixChain(arr,k+1,n) + arr[i-1]*arr[k]*arr[n];
          if(min > count)
               min = count;
     }
     dp[i][n] = min;
     return min;
}

int main(){
     int n;
     cin >> n;

     int arr[n+1];
     for(int i = 0; i <= n; i++)
          cin >> arr[i];

     int **dp = new int*[n+1];
     for(int i = 0; i <= n; i++){
          dp[i] = new int[n+1];
          for(int j = 0; j <= n; j++)
               dp[i][j] = -1;
     }
     std::cout << matrixChain(arr,1,n,dp) << '\n';
}

#include<iostream>
using namespace std;

inline int max(int a, int b){
     return a > b ? a : b;
}

int min(int a, int b){
     return a < b ? a : b;
}
int zeroSquare(int **arr, int n, int m){

     int dp[n][m];
     int first = 0, largest = 0;

     for(int i = 0; i < n; i++){
          dp[i][0] = 0;
          if(arr[i][0] == 0){
               dp[i][0] = 1;
               first = 1;
          }
     }

     for(int i = 0; i < m; i++){
          dp[0][i] = 0;
          if(arr[0][i] == 0){
               dp[0][i] = 1;
               first = 1;
          }
     }

     for(int i = 1; i < n; i++){
          for(int j = 1; j < m; j++){

               dp[i][j] = 0;

               if(arr[i][j] == 0){
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
                    largest = max(largest,dp[i][j]);
               }

          }
     }
     return max(first, largest);
}

int main(){
     int n,m;
     cin >> n >> m;

     int **arr = new int*[n];
     for(int i = 0; i < n; i++){
          arr[i] = new int[m];
          for(int j = 0; j < m; j++)
               cin >> arr[i][j];
     }
     std::cout << zeroSquare(arr,n,m) << '\n';
}

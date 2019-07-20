/*
given 2D matrix of cost find minimum cost required to go to location
0,0 to m,n
*/

#include<bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int n, int m){

     int **dp = new int*[n];
     for(int i = 0; i < n; i++)
          dp[i] = new int[m];

     dp[n-1][m-1] = input[n-1][m-1];

     for(int i = n-2; i >= 0; i--)
          dp[i][m-1] = input[i][m-1] + dp[i + 1][m-1];

     for(int i = m-2; i >= 0; i--)
          dp[n-1][i] = input[n-1][i] + dp[n-1][i+1];

     for(int i = n-2; i >= 0; i--){
          for(int j = m-2; j >= 0; j--)
               dp[i][j] = input[i][j] + min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
     }

     int ans = dp[0][0];

     for(int i = 0; i < n; i++)
          delete [] dp;
     delete [] dp;
     return ans;
}


int main(){
     int n,m;
     cin >> n >> m;

     int **input = new int*[n];
     for(int i = 0; i < n; i++)
          input[i] = new int[m];

     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++)
               cin >> input[i][j];
     }

     std::cout << minCostPath(input,n,m) << '\n';

     for(int i = 0; i < n; i++)
          delete[] input[i];
     delete[] input;
     return 0;
}

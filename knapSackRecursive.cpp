#include<bits/stdc++.h>
using namespace std;

int knapSack(int *w, int *v, int n, int maxWeight, int **dp){

     if(n <= 0)
          return 0;

     if(maxWeight <= 0)
          return 0;

     if(dp[n][maxWeight] > -1)
          return dp[n][maxWeight];

     int ans1 = 0;

     if(maxWeight - w[0] >= 0)
          ans1 = knapSack(w+1, v + 1, n-1, maxWeight - w[0], dp) + v[0];
     int ans2 = knapSack(w + 1, v + 1, n - 1, maxWeight, dp);
     dp[n][maxWeight] = max(ans1, ans2);
     return dp[n][maxWeight];
}

int main(){

     int n;
     cin >> n;

     int w[n], v[n];
     for(int i = 0; i < n; i++)
          cin >> w[i];

     for(int j = 0; j < n; j++)
          cin >> v[j];

     int maxWeight;
     cin >> maxWeight;

     int **dp = new int*[n+1];
     for(int i = 0; i <= n; i++){
          dp[i] = new int[maxWeight+1];
          for(int j = 0; j <= maxWeight; j++)
               dp[i][j] = -1;
     }

     std::cout << knapSack(w,v,n,maxWeight,dp) << '\n';
     for(int i = 0; i <= n; i++)
          delete [] dp[i];
     delete [] dp;
}

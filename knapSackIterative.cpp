#include<bits/stdc++.h>
using namespace std;

void knapSack(int *val, int *wt, int n, int W){

     int **dp = new int*[n+1];
     for(int i = 0; i <= n; i++){
          dp[i] = new int[W+1];
     }

     for(int i = 0; i <= n; i++)
          dp[i][0] = 0;

     for(int i = 0; i <= W; i++)
          dp[0][i] = 0;

     for(int i = 1; i <= n; i++){
          for(int w = 0; w <= W; w++){
               dp[i][w] = dp[i-1][w];
               if(wt[i-1] <= w)
                    dp[i][w] = max(dp[i][w], val[i] + dp[i-1][w-wt[i-1]]);
          }
     }

     std::cout << dp[n][W] << '\n';
}

int main(){

     int n;
     cin >> n;

     int v[n],w[n];
     for(int i = 0; i < n; i++)
          cin >> w[i];

     for(int i = 0; i < n; i++)
          cin >> v[i];

     int maxWeight;
     cin >> maxWeight;
     knapSack(v,w,n,maxWeight);
     return 0;
}

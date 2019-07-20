#include<bits/stdc++.h>
using namespace std;

int knapSack(int wt[], int val[], int n, int W){

     int dp[2][W+1];
     memset(dp,0,sizeof(dp));

     int i = 0;
     while(i < n){
          int j = 0;

          if(i%2 == 1){
               while(++j <= W){
                    if(wt[i] <= j)
                         dp[1][j] = max(val[i] + dp[0][j-wt[i]],dp[0][j]);
                    else
                          dp[1][j] = dp[0][j];
               }
          }
          else
        {
            while(++j <= W)
            {
                if (wt[i] <= j)
                    dp[0][j] = max(val[i] + dp[1][j-wt[i]], dp[1][j]);
                else
                    dp[0][j] = dp[1][j];
            }
        }

          i++;
     }

     return (n%2 != 0)? dp[0][W] : dp[1][W];
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

     int **dp = new int*[2];
     for(int i = 0; i < 2; i++){
          dp[i] = new int[maxWeight+1];
          for(int j = 0; j <= maxWeight; j++)
               dp[i][j] = -1;
     }

     int result =  knapSack(w,v,n,maxWeight);

     if(n%2 == 0)
          std::cout << dp[1][maxWeight] << '\n';
     else
          std::cout << dp[0][maxWeight] << '\n';

     for(int i = 0; i <= 1; i++)
          delete [] dp[i];
     delete [] dp;
}

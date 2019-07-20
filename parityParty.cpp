#include<bits/stdc++.h>
using namespace std;

void knapsack(int fee[], int fun[], int party, int budget){

     int dp[party + 1][budget+1];
     for(int i = 0; i <= party; i++){
          for(int j = 0; j <= budget; j++){
               if(i == 0 || j == 0)
                    dp[i][j] = 0;
               else if(fee[i-1] <= j)
                    dp[i][j] = max(fun[i-1] + dp[i-1][j - fee[i-1]], dp[i-1][j]);
               else
                    dp[i][j] = dp[i-1][j];
          }
     }

     int maxFun = dp[party][budget];
     int maxCost = 0;
     int res = maxFun;
     int b = budget;

     for(int i = 0; i <= budget; i++){
          if(dp[party][i] == maxFun){
              maxCost = i;
              break;
          }
     }

     std::cout << maxCost << " " << maxFun << '\n';
}



int main(){

     int party, budget;
     while(true){
          cin >> budget >> party;
          if(budget == 0 && party == 0)
               break;
          int fee[party], fun[party];

          for(int i = 0; i < party; i++)
               cin >> fee[i] >> fun[i];
          knapsack(fee,fun,party,budget);
     }
}

#include<bits/stdc++.h>
using namespace std;

int minTravlingCost(int **arr, int cities, int buses){

     int **dp = new int*[cities];
     for(int i = 0; i < cities; i++)
          dp[i] = new int[buses];

     for(int i = 0; i < buses; i++)
          dp[cities-1][i] = arr[cities-1][i];

     for(int i = cities-2; i >= 0; i--){
          for(int j = 0; j < buses; j++){

               if(j == 0){
                    dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + arr[i][j];
               }
               else if(j + 1 == buses){
                    dp[i][j] = min(dp[i+1][j], dp[i+1][j-1]) + arr[i][j];
               }
               else{
                    dp[i][j] = min(min(dp[i+1][j], dp[i+1][j-1]), dp[i+1][j+1]) + arr[i][j];
               }
          }
          //cout << endl;
     }

     int minCost = INT_MAX;

     for(int i = 0; i < buses; i++){
          if(minCost > dp[0][i])
               minCost = dp[0][i];
     }

     for(int i = 0; i < cities; i++)
          delete [] dp[i];
     delete [] dp;

     return minCost;
}

int main(){
     int cities,buses;
     cin >> cities >> buses;

     int **arr = new int*[cities];

     for(int i = 0; i < cities; i++){
          arr[i] = new int[buses];
          for(int j = 0; j < buses; j++)
               cin >> arr[i][j];
     }
     std::cout << minTravlingCost(arr,cities,buses) << '\n';
}

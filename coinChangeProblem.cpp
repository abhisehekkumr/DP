/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}.
 You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = 15;
int coinChange(int denominations[], int size, int n, int output[][MAX]){

     if(n == 0)
          return 1;
     if(n  < 0)
          return 0;
     if(size == 0)
          return 0;

     if(output[n][size] > -1)
          return output[n][size];

     int first = coinChange(denominations, size, n - denominations[0], output);
     int second = coinChange(denominations + 1, size - 1,n, output);

     output[n][size] = first + second;
     return first + second;
}

int main(){
     int d;
     cin >> d;

     int denominations[d];
     for(int i = 0; i < d; i++)
          cin >> denominations[i];

     int n;
     cin >> n;

     int output[n + 1][MAX];

     for(int i = 0; i <= n; i++){
          for(int j = 0; j < MAX; j++)
               output[i][j] = -1;
     }

     std::cout << coinChange(denominations,d,n,output) << '\n';
}

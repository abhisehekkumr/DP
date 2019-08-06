#include<iostream>
#include<cmath>
using namespace std;
int dp[1000][1000];

int count(int n, int diff, int dp[1000][1000]){
     if(abs(diff) > n)
          return 0;
     if(n < 0)
          return 0;
     if(n == 1 && diff == 0)
          return 2;
     if(n == 1 && abs(diff) == 1)
          return 1;
     if(dp[n][n + diff] > -1)
          return dp[n][n + diff];

     dp[n][n+diff] = count(n-1,diff-1,dp) + 2*count(n-1,diff,dp) + count(n-1,diff+1,dp);
     return dp[n][n+diff];
}

int count(int n){
     for(int i = 0; i < 1000; i++){
          for(int j = 0; j < 1000; j++)
               dp[i][j] = -1;
     }
     return count(n,0,dp);
}

int better(int n){
     int nCr=1, res = 1;

	// Calculate SUM ((nCr)^2)
	for (int r = 1; r<=n ; r++)
	{
		// Compute nCr using nC(r-1)
		// nCr/nC(r-1) = (n+1-r)/r;
		nCr = (nCr * (n+1-r))/r;

		res += nCr*nCr;
	}

	return res; 
}

int main(){
     int n;
     cin >> n;

     //std::cout << count(n) << '\n';
     std::cout << better(n) << '\n';
}

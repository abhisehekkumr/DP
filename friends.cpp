#include<iostream>
#define mod 1000000007
typedef long long ll;
using namespace std;

ll ways(int n, ll *dp){
     if(n == 1)
          return 1;
     if(n == 0)
          return 1;
     if(n < 0)
          return 0;
     if(dp[n] > -1)
          return dp[n];

     dp[n] = (ways(n-1,dp) + ((n-1)*ways(n-2,dp))%mod)%mod;
     return dp[n];
}

int main(){
     int t = 1;
     //cin >> t;

     ll dp[101];
     for(int i = 0; i <= 100; i++)
          dp[i] = -1;
     dp[0] = dp[1] = 1;
     ways(100,dp);
     while(t--){
          int n;
          cin >> n;
          std::cout << dp[n] << '\n';
     }
}

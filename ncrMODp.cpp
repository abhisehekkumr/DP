#include<iostream>
#define P 1000000007
typedef long long ll;
using namespace std;

ll combination(int n, int r){
     if(r > n)
          return 0;

     ll dp[r+1];
     for(int i = 0; i <= r; i++)
        dp[i] = 0;
     dp[0] = 1;

     for(int i = 1; i <= n; i++){
          for(int j = min(i,r); j > 0; j--)
               dp[j] = (dp[j] + dp[j-1])%P;
     }

     return dp[r]%P;
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int n,r;
          cin >> n >> r;
          std::cout << combination(n,r) << '\n';
     }
}

#include<iostream>
#include<string>
using namespace std;

inline int max(int a, int b){
     return a > b ? a : b;
}

int subsequence(string s, string t, int **dp){
     if(s.size() == 0 || t.size() == 0)
          return 0;

     if(dp[s.size()][t.size()] > -1)
          return dp[s.size()][t.size()];

     if(s[0] == t[0]){
          dp[s.size()][t.size()] = subsequence(s.substr(1), t.substr(1),dp)+1;
          return dp[s.size()][t.size()];
     }

     int ans1 = subsequence(s.substr(1),t,dp);
     int ans2 = subsequence(s, t.substr(1),dp);
     dp[s.size()][t.size()] = max(ans1,ans2);
     return dp[s.size()][t.size()];
}

int longestCommonSubsequence(string s, string t){
     int **dp = new int*[s.size()+1];
     for(int i = 0; i <= s.size(); i++){
          dp[i] = new int[t.size()+1];
          for(int j = 0; j <= t.size(); j++)
               dp[i][j] = -1;
     }
     return subsequence(s,t,dp);
}

int main(){
     string s;
     string t;
     cin >> s;
     cin >> t;
     std::cout << longestCommonSubsequence(s,t) << '\n';
}

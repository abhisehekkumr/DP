#include<iostream>
#include<cstring>
using namespace std;

int distance(string s, string t, int **dp){

    if(s.size() == 0)
        return t.size();

    if(t.size() == 0)
        return s.size();

    if(s[0] == t[0]){
        dp[s.size()][t.size()] = distance(s.substr(1),t.substr(1), dp);
        return dp[s.size()][t.size()];
    }

    if(dp[s.size()][t.size()] > 1)
        return dp[s.size()][t.size()];

    int ans1 = distance(s.substr(1),t.substr(1),dp);
    int ans2 = distance(s.substr(1),t,dp);
    int ans3 = distance(s,t.substr(1),dp);
    dp[s.size()][t.size()] = min(ans1, min(ans2,ans3))+1;
    return dp[s.size()][t.size()];
}

int editDistance(string s1, string s2){

    int **dp = new int*[s1.size()+1];
    for(int i = 0; i <= s1.size(); i++){
        dp[i] = new int[s2.size()+1];
        for(int j = 0; j <= s2.size(); j++)
            dp[i][j] = -1;
    }
    return distance(s1,s2,dp);
}

int main(){

     string s;
     string t;
     cin >> s;
     cin >> t;
     std::cout << editDistance(s,t) << '\n';
}

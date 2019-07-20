#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

void totalSubsequences(string str, unordered_map<string, int> &m, string ans = ""){
     //std::cout << "ans : " << ans << '\n';
     if(str.size() == 0)
          return;

     if(m.count(ans))
          return;

     totalSubsequences(str.substr(1), m, ans + str[0]);
     totalSubsequences(str.substr(1), m,ans);

     m[ans + str[0]] = 1;
     m[ans] = 1;
}

int main(){
     int t;
     cin >> t;

     while(t--){
          string str;
          cin >> str;
          unordered_map<string,int> m;
          totalSubsequences(str, m);
          std::cout << m.size() << '\n';
          /*
          unordered_map<string,int> :: iterator it;
          for(it = m.begin(); it != m.end(); it++)
               std::cout << it->first << '\n';
               */
     }
}

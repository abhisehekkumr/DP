#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007

long long countDecodingDP(string digits, int n)
{
     int count[n+1];
     count[0] = 1;
     count[1] = 1;
     for (int i = 2; i <= n; i++) {
          count[i] = 0;

          if (digits[i-1] > '0')
               count[i] = count[i-1];
          if (digits[i-2] == '1' || (digits[i-2] == '2' && digits[i-1] < '7') )
               count[i]=(count[i]%MAX + count[i-2]%MAX)%MAX;
     }

     return count[n]%MAX;
}



     int main() {
     string str; cin>>str;
     while(str!="0"){
     int l=str.size();
     cout<<countDecodingDP(str,l)<<endl;
     cin>>str;}
     }

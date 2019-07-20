#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long alphaCodes(string arr){

     long long *output = new long long[arr.size()+1];
     output[0] = 1;
     output[1] = 1;

     for(int i = 2; i <= arr.size(); i++){
          output[i] = 0;

          if(arr[i-1] > '0')
               output[i] = output[i-1]%mod;

          if(arr[i-2] == '1' || (arr[i-2] == '2' && arr[i-1] <= '6'))
               output[i] = (output[i]%mod + output[i-2]%mod)%mod;
     }

     //for(int i = 0; i <= arr.size(); i++)
     //     std::cout << output[i] << ' ';
     //std::cout << '\n';
     long long ans = output[arr.size()];
     delete [] output;
     return ans%mod;
}

int main(){
     string str;
     cin >> str;
     std::cout << alphaCodes(str) << '\n';
}

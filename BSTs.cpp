#include<iostream>
#define mod 1000000007
using namespace std;

int BSTs(int n, long long arr[]){

     if(n == 1 || n == 0){
          arr[n] = 1;
          return 1;
     }

     if(arr[n] > 0)
          return arr[n];

     for(int i = 1; i <= n; i++){
          long long temp = ((BSTs(i-1,arr))%mod * (BSTs(n-i,arr))%mod)%mod;
          arr[n] = (temp + arr[n])%mod;
     }

     return (int)(arr[n]%mod);
}

int main(){
     int n;
     cin >> n;

     long long output[n+1];
     for(int i = 0; i <= n; i++)
          output[i] = 0;

     std::cout << BSTs(n,output) << '\n';

     //for(int i = 0; i <= n; i++)
     //     std::cout << output[i] << ' ';
     //std::cout << '\n';
}

#include<iostream>
#define mod 1000000007
using namespace std;

long long balancedTrees(long long h, long long arr[]){

     if(h == 0 || h == 1){
          arr[h] = 1;
          return 1;
     }

     if(arr[h] > 0)
          return arr[h];

     long long x = balancedTrees(h-1,arr);
     long long y = balancedTrees(h-2,arr);

     long long ans1 = (x*x)%mod;
     long long ans2 = (((2*x)%mod)*y)%mod;
     //std::cout << "ans1 " << ans1 << " " << "ans2 " << ans2 << '\n';
     arr[h] = (ans1 + ans2)%mod;
     return arr[h];
}

int main(){

     long long h;
     cin >> h;

     long long output[h+1];
     for(int i = 0; i <= h; i++)
          output[i] = 0;
     std::cout << balancedTrees(h,output) << '\n';
}

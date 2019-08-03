#include<iostream>
#define P 1000000007
typedef long long ll;
using namespace std;

ll ways(int n, int k){

     if(n == 1)
          return k;

     ll arr[n+1];
     arr[1] = k;

     ll same = 0, diff = k;
     for(int i = 2; i <= n; i++){
          same = diff;
          diff = arr[i-1]*(k-1);
          diff = diff%P;
          arr[i] = (same + diff)%P;
     }
     return arr[n];
}

int main(){
     int t;
     cin >> t;
     while(t--){
          int n,k;
          cin >> n >> k;
          std::cout << ways(n,k) << '\n';
     }
}

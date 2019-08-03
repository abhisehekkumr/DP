#include<iostream>
typedef long long ll;
using namespace std;

ll ways(ll w, ll arr[]){
     if(w == 0 || w == 1)
          return 1;
     if(w < 0)
          return 0;
     if(arr[w] > -1)
          return arr[w];

     ll ans1 = ways(w-1,arr);
     ll ans2 = 0;
     if(w - 2 >= 0)
          ans2 = ways(w-2,arr);
     arr[w] = ans1 + ans2;
     return arr[w];
}

ll *dp(){

     ll *arr = new ll[70+1];
     for(ll i = 0; i <= 70; i++)
          arr[i] = -1;
     arr[0] = 1;
     arr[1] = 1;
     ways(70,arr);
     return arr;
}

int main(){
     ll t = 1;
     ll *arr = dp();
     cin >> t;

     while(t--){
          ll w;
          cin >> w;
          std::cout << arr[w] << '\n';
     }
}

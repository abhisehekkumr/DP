#include<iostream>
#include<queue>
typedef long long ll;
using namespace std;

void uglyNumber(ll arr[]){
     int n = 10000;
     queue<ll> q2;
     queue<ll> q3;
     queue<ll> q5;

     ll count = 1;
     ll max = 1;
     arr[0] = 1;
     q2.push(2);
     q3.push(3);
     q5.push(5);

     while(count < n){
          ll k = min(q2.front(), min(q3.front(), q5.front()));
          if(max < k){
               arr[count] = k;
               count += 1;
               max = k;
          }

          if(k == q2.front()){
               q2.pop();
               q2.push(k*2);
               q3.push(k*3);
               q5.push(k*5);
          }
          else if(k == q3.front()){
               q3.pop();
               q3.push(k*3);
               q5.push(k*5);
          }
          else{
               q5.pop();
               q5.push(k*5);
          }
     }
}

int main(){
     int t;
     cin >> t;

     ll arr[10000+1];
     uglyNumber(arr);
     while(t--){
          ll n;
          cin >> n;
          std::cout << arr[n-1] << '\n';
     }
}

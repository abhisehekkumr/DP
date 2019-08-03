#include<iostream>
typedef long long ll;
using namespace std;

int main(){
     ll n, m;
     cin >> n >> m;

     ll count  = 0;
     ll i = 0;

     while(n - i && m - i){
          count += (n-i)*(m-i);
          i++;
     }
     std::cout << count << '\n';
}

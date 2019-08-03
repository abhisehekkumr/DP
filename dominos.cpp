#include<iostream>
using namespace std;

int ways(int n){

     int an[n+1], bn[n+1];
     an[0] = bn[0] = an[1] = bn[1] = 1;

     for(int i = 2; i <= n; i++){
          an[i] = an[i-2] + 2*bn[i-1];
          bn[i] = an[i-1] + bn[i-2];
     }
     return an[n];
}

int main(){
     int n;
     cin >> n;
     std::cout << ways(n) << '\n';
}

#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>
using boost :: multiprecision :: cpp_int;
using namespace std;

cpp_int Factorial(int n){
     if(n == 0 || n == 1)
          return 1;
     cpp_int fact = 1;
     for(int i = 1; i <= n; i++)
          fact *= i;
     return fact;
}

int main(){
     int t;
     cin >> t;
     while(t--){
          int n,r;
          cin >> n >> r;
          std::cout << ((Factorial(n))/(Factorial(r)*(Factorial(n-r))))%1000000007 << '\n';
     }
}

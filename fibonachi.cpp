// wap for finding the fibonachi sequence for particular n using dp

#include<iostream>
using namespace std;

int fib(int arr[], int n){
     arr[0] = 0;
     arr[1] = 1;

     for(int i = 2; i <= n; i++)
          arr[i] = arr[i - 1] + arr[i - 2];
     return arr[n];
}


/* recusive dp solution for fibonachi sequence
   things need to consider is

   1. what happens at the base case
   2. what if number we are looking for is not found yet
   3.what if number looking for is already found
   4. no need for checking for n < 0 contraint
*/

int fibonachi(int table[], int n){

     if(table[n] > 0)
          return table[n];

     if(n == 1 || n == 0){
          table[n] = 1;
          return table[n];
     }

     return fibonachi(table,n-1) + fibonachi(table,n-2);
}
int main(){
     int n;
     cin >> n;

     int arr[n + 1] = {0};
     fib(arr,n);

     std::cout << fibonachi(arr,n) << '\n';
}

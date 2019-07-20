/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count how many possible ways the child can run up to the stairs.
 You need to return all possible number of ways.
Time complexity of your code should be O(n).
*/

#include<iostream>
using namespace std;


long long staircase(int n, long long arr[]){

     if(n < 0)
          return 0;

     if(n == 1 || n == 0){
          arr[n] = 1;
          return arr[n];
     }

     if(arr[n] > 0)
          return arr[n];

     arr[n] = staircase(n-1,arr) + staircase(n-2,arr) + staircase(n-3,arr);
     return arr[n];
}
int main(){
     int n;
     cin >> n;

     long long arr[n + 1] = {0};
     std::cout << staircase(n,arr) << '\n';
}

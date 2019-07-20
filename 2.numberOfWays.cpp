/*
Given 3 numbers {1, 3, 5}, we need to tell
the total number of ways we can form a number 'N'
using the sum of the given three numbers.
*/

#include<iostream>
using namespace std;

long long table[1000000];

long long ways(int n){

     if(n < 0)
          return 0;

     if(n == 0)
          return 1;

     if(table[n] != -1)
          return table[n];

     return table[n] = ways(n - 1) + ways(n - 3) + ways(n - 5);
}

int solve(int n)
{
  // base case
  if (n < 0)
      return 0;
  if (n == 0)
      return 1;

  // checking if already calculated
  if (table[n]!=-1)
      return table[n];

  // storing the result and returning
  return table[n] = solve(n-1) + solve(n-3) + solve(n-5);
}

int main(){
     int n;
     cin >> n;

     for(int i = 0; i < 1000000; i++)
          table[i] = -1;
     std::cout << ways(n) << '\n';
}

/*

You are given an array of positive integers as input. Write a code to return the length of the largest such
sub-array in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a sub-array is known as bitonic sub-array. A purely increasing or purely decreasing subsequence will also be
considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic sub-array need not be consecutive in the given array but the order should remain same.
Input Format:

*/

#include<bits/stdc++.h>
using namespace std;

int largestBiotonicSubarray(int arr[], int n){
     int output[n],smallest[n];

     output[0] = 1;
     smallest[n-1] = 1;


          for(int i = 1; i < n; i++){
               output[i] = 1;
               for(int j = i - 1; j >= 0; j--){

                    if(arr[i] <= arr[j])
                         continue;

                    int bestAnswer = output[j] + 1;

                    if(bestAnswer > output[i])
                         output[i] = bestAnswer;
               }
          }

     for(int i = n-2; i >= 0; i--){
          smallest[i] = 1;
          for(int j = i +1; j < n; j++){

               if(arr[i] <= arr[j])
                    continue;

               int bestAnswer = smallest[j] + 1;

               if(bestAnswer > smallest[i])
                    smallest[i] = bestAnswer;
          }
     }

     int max = 0;
     /*
     for(int i = 0; i < n; i++)
          std::cout << output[i] << ' ';
     std::cout  << '\n';

     for(int i = 0; i < n; i++)
          std::cout << smallest[i] << ' ';
     cout << endl;
     */
     for(int i = 0; i < n; i++){

          if(max < (output[i] + smallest[i]))
               max = output[i] + smallest[i];
     }

     return max - 1;

}

int main(){

     int n;
     cin >> n;

     int arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];

     std::cout << largestBiotonicSubarray(arr,n) << '\n';
}

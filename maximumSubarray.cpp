#include<iostream>
using namespace std;

int maximumSubarray(int arr[], int n){

     int max = arr[0];
     int current = 0;
     for(int i = 0; i < n; i++){

          current += arr[i];
          if(max < current)
               max = current;

          if(current < 0)
               current = 0;
     }
     return max;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << maximumSubarray(arr,n) << '\n';
}

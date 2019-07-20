#include<iostream>
using namespace std;

int maximumLoot(int arr[], int n){

     int *output = new int[n];
     output[0] = arr[0];
     output[1] = max(arr[0],arr[1]);

     for(int i = 2; i < n; i++){
          output[i] = max(output[i-1], output[i-2] + arr[i]);
     }

     return output[n-1];
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << maximumLoot(arr,n) << '\n';
}

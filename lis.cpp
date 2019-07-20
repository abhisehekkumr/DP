#include<iostream>
using namespace std;

int lis(int arr[], int n){

     int *output = new int[n];
     output[0] = 1;

     for(int i = 1; i < n; i++){
          output[i] = 0;
          for(int j = i-1; j >= 0; j--){
               if(arr[i] <= arr[j])
                    continue;

               if(output[i] < output[j])
                    output[i] = output[j];
          }

          output[i] += 1;
     }

     int max = 0;
     for(int i = 0; i < n; i++){
          if(max < output[i])
               max = output[i];
     }

     delete [] output;
     return max;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << lis(arr,n) << '\n';
}

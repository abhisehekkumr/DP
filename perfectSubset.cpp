#include<iostream>
using namespace std;

void printSubsets(int arr[],int output[], int n, int total, int sum, int index){
     
     if(sum == total){
          for(int i = 0; i < index; i++)
               std::cout << output[i] << ' ';
          std::cout << '\n';
          return;
     }

     if(n == 0)
          return;

     if(sum > total)
          return;

     printSubsets(arr+1,output,n-1,total,sum,index);
     output[index] = arr[0];
     printSubsets(arr+1,output,n-1,total,sum + arr[0], index + 1);

}

int main(){
     int t = 1;
     //cin >> t;
     int arr[100001];
     int output[100001];
     while(t--){
          int n;
          cin >> n;
          for(int i = 0; i < n; i++)
               cin >> arr[i];
          int sum;
          cin >> sum;
          printSubsets(arr,output,n,sum,0,0);
     }
}

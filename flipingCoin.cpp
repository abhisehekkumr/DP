#include<iostream>
#include<climits>
using namespace std;

int maxInterval(int arr[], int n){
     int i,l,r,sum[n+1],maxHeadCount = INT_MIN, modifiedHeadCount;
     sum[0] = 0;
     for(int i = 1; i <= n; i++)
          sum[i] = sum[i-1] + arr[i];

     for(int l = 1; l <= n; l++){
          for(int r = l; r <= n; r++){
               int modifiedHeadCount = sum[l-1]+((r-l+1) - (sum[r] - sum[l-1])) + (sum[n]-sum[r-1]);
               if(maxHeadCount < modifiedHeadCount)
                    maxHeadCount = modifiedHeadCount;
          }
     }
     return maxHeadCount;
}

int main(){
     int n;
     cin >> n;

     int arr[n+1];
     for(int i = 1; i <= n; i++)
          cin >> arr[i];
     std::cout << maxInterval(arr,n) << '\n';
}

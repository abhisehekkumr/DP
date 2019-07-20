#include<bits/stdc++.h>
using namespace std;

int LonestCommonSubsequence(int arr[], int n){
     int output[n];
     output[0] = 1;

     for(int i = 1; i < n; i++){
          output[i] = 1;
          for(int j = i - 1; j >= 0; j--){

               if(arr[i] < arr[j])
                    continue;

               int bestAnswer = output[j] + 1;

               if(bestAnswer > output[i])
                    output[i] = bestAnswer;
          }
     }

     int ans = 0;
     for(int i = 0; i < n; i++){
          if(output[i] > ans)
               ans = output[i];
     }
     return ans;
}

int main(){
     int n;
     cin >> n;

     int arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];
     int ans = LonestCommonSubsequence(arr,n);
     std::cout << ans << '\n';
}

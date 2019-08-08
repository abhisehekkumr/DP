#include<iostream>
#include<climits>
using namespace std;

void print(int **arr, int n, int k){

     int **dp =  new int*[n - k];
     for(int i = 0; i < k; i++){
          dp[i] = new int[n];
     }

     for(int j = 0; j < n; j++){
          int sum = 0;
          for(int i = 0; i < k; i++)
               sum += arr[i][j];
          dp[0][j] = sum;

          for(int i = 1; i < n - k + 1; i++){
               sum += arr[i+k-1][j] - arr[i-1][j];
               dp[i][j] = sum;
          }
     }

     int total = INT_MIN;
     int start = 0, end = 0;

     //std::cout << "/* message */" << '\n';
     //for(int i = 0; i <= n - k; i++){
     //     for(int j = 0; j < n; j++)
     //          std::cout << dp[i][j] << ' ';
     //     std::cout << '\n';
     //}
     //std::cout << "/* message */" << '\n';
     for(int i = 0; i <= n - k; i++){
          int sum = 0;

          for(int j = 0; j < k; j++)
               sum += dp[i][j];

          if(sum > total){
               //std::cout << sum <<  " " << i << " " << 0 << '\n';
               total = sum;
               start = i;
               end = 0;
          }

          for(int j = 1; j < n - k + 1; j++){
               sum += dp[i][j + k - 1] - dp[i][j-1];
               if(sum > total){
                    //std::cout << sum <<  " " << i << " " << j << '\n';
                    total = sum;
                    start = i;
                    end = j;
               }
          }
     }

     std::cout << "output" << '\n';
     for(int i = 0; i < k; i++){
          for(int j = 0; j < k; j++)
               std::cout << arr[i+start][j + end] << ' ';
          std::cout << '\n';
     }
}

int main(){
     int n, k;
     cin >> n >> k;

     int **arr = new int*[n];
     for(int i = 0; i < n; i++){
          arr[i] = new int[n];
          for(int j = 0; j < n; j++)
               cin >> arr[i][j];
     }

     print(arr,n,k);
}

/*
4 3
1 2 -1 4
-8 -3 4 2
3 8 10 -8
-4 -1 1 7
*/

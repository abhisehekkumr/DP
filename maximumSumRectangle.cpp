#include<iostream>
#include<climits>
using namespace std;

int kadnes(int arr[], int n){

    int max = INT_MIN;
    int ending = 0;

    for(int i = 0; i < n; i++){
        ending += arr[i];

        if(max < ending)
            max = ending;

        if(ending < 0)
            ending = 0;
    }
    return max;
}

int maximumSumRectangle(int **arr, int n, int m){

     int dp[n];
     int sum = INT_MIN;
     for(int i = 0; i < m; i++){

          for(int k = 0; k < n; k++)
               dp[k] = 0;

          for(int j = i; j < m; j++){

               for(int k = 0; k < n; k++)
                    dp[k] += arr[k][j];
               int largest = kadnes(dp,n);

               sum = sum > largest ? sum : largest;
          }
     }
     return sum;
}

int main(){
     int n,m;
     cin >> n >> m;

     int **arr = new int*[n];
     for(int i = 0; i < n; i++){
          arr[i] = new int[m];
          for(int j = 0; j < m; j++)
               cin >> arr[i][j];
     }

     std::cout << maximumSumRectangle(arr,n,m) << '\n';
}

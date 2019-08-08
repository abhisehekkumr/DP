#include<iostream>
#include<algorithm>
using namespace std;

struct job{
     int start;
     int end;
     int profit;
};

bool compare(job j1, job j2){
     return j1.end <= j2.end;
}

int findNonConflicting(job arr[], int i){

     for(int j = i-1; j >= 0; j--){
          if(arr[j].end <= arr[i-1].start)
               return j;
     }
     return -1;
}

int maxProfit(job arr[], int n, int dp[]){
     if(n == 0)
          return 0;

     if(n == 1)
          return arr[n-1].profit;

     if(dp[n] > -1)
          return dp[n];

     // including current jobs
     int including = 0;
     int non_confliting = findNonConflicting(arr,n);
     if(non_confliting != -1)
          including = maxProfit(arr, non_confliting+1,dp) + arr[n-1].profit;

     int excluing = maxProfit(arr,n-1,dp);
     dp[n] = max(including,excluing);
     return dp[n];
}

int main(){
     int n;
     cin >> n;

     job arr[n];
     for(int i = 0; i < n; i++){
          cin >> arr[i].start >> arr[i].end >> arr[i].profit;
     }

     sort(arr,arr+n,compare);
     int *dp = new int[n+1];
     for(int i = 0; i <= n; i++)
          dp[i] = -1;
     std::cout << maxProfit(arr,n,dp) << '\n';
}

#include<iostream>
#include<vector>
using namespace std;

int solve(int n, vector<int> arr){

     int *dp = new int[1000+1];
     int *count = new int[1000+1];
     for(int i = 0; i <= 1000; i++){
          dp[i] = 0;
          count[i] = 0;
     }

     for(int i = 0; i < arr.size(); i++)
          count[arr[i]]++;

     dp[1] = count[1];
     for(int i = 2; i <= 1000; i++)
          dp[i] = max(dp[i-2]+ i*count[i], dp[i-1]);
     int ans = dp[1000];
     delete [] count;
     delete [] dp;
     return ans;
}

int main(){
     int n;
     cin >> n;

     vector<int> arr;
     for(int i = 0; i < n; i++){
          int element;
          cin >> element;
          arr.push_back(element);
     }

     std::cout << solve(n,arr) << '\n';
}

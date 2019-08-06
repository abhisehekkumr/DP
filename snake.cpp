#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int find(int **arr, int n, int i, int j, int *path, int index, int path_max, int previous){
     if(i < 0 || j < 0 || i >= n || j >= n)
          return INT_MIN+1;

     if(abs(arr[i][j]-previous) != 1)
          return INT_MIN+1;

     //std::cout << previous << " " << i <<  " " << j << '\n';

     int ans1 = find(arr,n,i,j+1,path,index+1,path_max,arr[i][j]);
     int ans2 = find(arr,n,i+1,j,path,index+1,path_max,arr[i][j]);

     int ans3 = max(ans1, ans2);

     if(ans3 > path_max)
          path[index] = arr[i][j];
     return ans3 + arr[i][j];
}

void print(int **arr, int n){
     int *path = new int[2*n];

     int path_max = INT_MIN;
     for(int i = 0; i < n; i++){
          int ans = find(arr,n,0,i,path,0,path_max,arr[0][i]-1);
          path_max = path_max > ans ? path_max : ans;
     }

     for(int i = 0; i < n; i++){
          int ans = find(arr,n,i,0,path,0,path_max,arr[i][0]-1);
          path_max = path_max > ans ? path_max : ans;
     }

     std::cout << "path : " << '\n';
     for(int i = 0; i < 2*n-1; i++)
          std::cout << path[i] << ' ';
     std::cout << '\n';
}

int main(){
     int n;
     cin >> n;

     int **arr = new int*[n];
     for(int i = 0; i < n; i++){
          arr[i] = new int[n];
          for(int j = 0; j < n; j++)
               cin >> arr[i][j];
     }

     print(arr,n);
}

/*
4
9 6 5 2
8 7 6 5
7 3 1 6
1 1 1 7
*/

#include<iostream>
#define MAX 101
using namespace std;

inline int max(int a, int b){
     return a > b ? a : b;
}

int found(int mine[MAX][MAX], int **arr, int n, int m, int i, int j){

     if(i < 0 || j < 0 || i >= n || j >= m)
          return 0;

     if(arr[i][j] == 1)
          return 0;

     if(arr[i][j] > -1)
          return arr[i][j];

     int ans1 = found(mine,arr,n,m,i,j+1);
     int ans2 = found(mine,arr,n,m,i-1,j+1);
     int ans3 = found(mine,arr,n,m,i+1,j+1);

     arr[i][j] = max(ans1, max(ans2, ans3)) + mine[i][j];
     return arr[i][j];
}

int maxGold(int mine[MAX][MAX], int n, int m){

     int **arr = new int*[n+1];
     for(int i = 0; i <= n; i++){
          arr[i] = new int[m+1];
          for(int j = 0; j <=m; j++)
               arr[i][j] = -1;
     }

     int gold = 0;
     for(int i = 0; i < n; i++){
          int ans = found(mine,arr,n,m,i,0);
          gold = max(gold, ans);
     }
     return gold;
}

int main(){
     int t = 1;
     //cin >> t;

     int mine[MAX][MAX];
     while(t--){
          int n,m;
          cin >> n >> m;

          for(int i = 0; i < n; i++){
               for(int j = 0; j < m; j++)
                    cin >> mine[i][j];
          }

          std::cout << maxGold(mine,n,m) << '\n';
     }
}

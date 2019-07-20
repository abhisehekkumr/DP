/*

Given a n*m matrix which contains only 0s and 1s, find out the size of largestimum square sub-matrix with all 0s.
You need to return the size of square with all 0s.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
     int n,m;
     cin >> n >> m;

     int **arr = new int*[m];
     for(int i = 0; i < n; i++)
          arr[i] = new int[m];

     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++)
               cin >> arr[i][j];
     }


     int **counts = new int*[m];
     for(int i = 0; i < n; i++)
          counts[i] = new int[m];

     int first = 0;
     // rows making 0 or 1
     for(int i = 0; i < m; i++){
          counts[0][i] = 0;
          if(!arr[0][i]){
               counts[0][i] = 1;
               first = 1;
          }
     }

     // making base case for rows
     for(int i = 0; i < n; i++){
          counts[i][0] = 0;
          if(!arr[i][0]){
               counts[i][0] = 1;
               first = 1;
          }
     }



     int largest = 0;
     for(int i = 1; i < n; i++){
          for(int j = 1; j < m; j++){

               counts[i][j] = 0;
               if(!arr[i][j]){
                    counts[i][j] = min(min(counts[i-1][j-1], counts[i][j-1]), counts[i-1][j]) + 1;
                    largest = largest > counts[i][j] ? largest : counts[i][j];

               }

          }
     }

     /*
     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++)
               std::cout << counts[i][j] << ' ';
          std::cout << '\n';
     }*/

     largest = max(largest,first);



     std::cout << largest << '\n';
     for(int i = 0; i < n; i++){
          delete[] arr[i];
          delete[] counts[i];
     }

     delete[] arr;
     delete[] counts;
     return 0;
}

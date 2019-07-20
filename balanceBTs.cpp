#include<bits/stdc++.h>
using namespace std;


int balancedBTs(int h, int arr[]){

     if(h == 1 || h == 0){
          arr[h] = 1;
          return arr[h];
     }

     if(arr[h] > 0)
          return arr[h];

     int x = balancedBTs(h - 1, arr);
     int y = balancedBTs(h - 2, arr);

     int m = pow(10,9) + 7;

     long x1 = (long)x*x;
     long y1 = (long)x*y*2;

     long ans1 = (x1%m);
     long ans2 = (y1%m);

     arr[h] = (ans1 + ans2)%m;
     return arr[h];
}

int main(){

     int h;
     cin >> h;

     int arr[h + 1];

     for(int i = 0; i <= h; i++)
          arr[i] = 0;

     std::cout << balancedBTs(h,arr) << '\n';

     for(int i = 0; i < h + 1; i++)
          std::cout << i  << " " << arr[i] << '\n';
}

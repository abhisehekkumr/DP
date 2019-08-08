#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void nextNumber(char *number, int n){

     int i,j;
     for(int i = n-1; i > 0; i--){
          if(number[i] > number[i-1])
               break;
     }

     if(i == 0){
          std::cout << "not possible" << '\n';
          return;
     }

     char c = number[i+1];
     for(int j = i+1; j < n; j++){
          if(c < number[j])
               c = number[j];
     }

     sort(number+i,number+n);
     std::cout << number << '\n';
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          char number[100];
          cin >> number;
          nextNumber(number,strlen(number));
          //std::cout << number << '\n';
     }
}

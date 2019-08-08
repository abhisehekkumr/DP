#include<iostream>
#include<sstream>
using namespace std;

int main(){
     string number;
     cin >> number;

     int n = 0;
     for(int i  = 0; i < number.size(); i++)
          n = n*10 + (number[i] - '0');
     std::cout << n << '\n';
}

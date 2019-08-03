#include<iostream>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;

cpp_int Factorial(int number)
{
	cpp_int num = 1;
	for (int i = 1; i <= number; i++)
		num = num * i;
	return num;
}

cpp_int build(int n, cpp_int arr[]){
     if(n <= 1)
          return 1;
     if(arr[n] > -1)
          return arr[n];
     cpp_int res = 0;
     for(int i = 0; i < n; i++){
          res += build(i,arr) * build(n-i-1,arr);
     }

     arr[n] = res;
     return res;
}

int main(){
     int n = 1000;
     int t;
     cin >> t;
     cpp_int arr[n+1];
     for(int i = 0; i <= n; i++)
          arr[i] = -1;
     arr[0] = 1;
     arr[1] = 1;
     build(n,arr);

     while(t--){
        int k;
        cin >> k;
        //cout << arr[k] << endl;
        std::cout << Factorial(k) << '\n';
     }
}

/*
Gary is given a string containing only ‘R’s and ‘O’s (uppercase).
 Gary wants to count the total number of subsequences forming “ROR”
in the given string. You need to return the count of subsequences possible.
*/

/*
          approach
     if we count total number of R's on right and total number of O's on right
     so we cannot solve this problem because if we get test case like RRROOO
     then our algo give number greater than 0 because to right of first R there
     are R's as well as there are O's, but their order isn't confimed. for that
     we need to traverse and check which will result in O(n*n) solution

     thus we will count total number of R's on left of O and total number of R's
     on right of that O. thus for that particular O total possible pair will
     be left[i]*right[i]. and it will also handle test case like RRRROOO
     as their will be 0's on right of every O. 
*/

#include<iostream>
#include<string>
#define ll long long int
using namespace std;

ll countROR(string arr){
     if(arr.size() == 0 || arr.size() == 1 || arr.size() == 2)
          return 0;

     ll left[arr.size()];
     ll right[arr.size()];

     for(int i = 0; i < arr.size(); i++)
          if(i == 0)
               if(arr[i] == 'R')
                    left[i] = 1;
               else
                    left[i] = 0;
          else if(arr[i] == 'R')
               left[i] = left[i-1]+1;
          else
               left[i] = left[i-1];

     for(int i = arr.size()-1; i >= 0; i--)
          if(i == arr.size()-1)
               if(arr[i] == 'R')
                    right[i] = 1;
               else
                    right[i] = 0;
          else if(arr[i] == 'R')
               right[i] = right[i+1]+1;
          else
               right[i] = right[i+1];

     ll ans = 0;
     for(int i = 0; i < arr.size(); i++){
          if(arr[i] == 'O')
               ans += left[i]*right[i];
     }
     return ans;
}

int main(){
     string str;
     cin >> str;
     std::cout << countROR(str) << '\n';
}

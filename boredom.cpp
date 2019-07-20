/*
Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called
"destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x
from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to
learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points
he receive grab from the game ?
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin >> n;

     int arr[n];
     int freq[10001];
     int dp[10001];
     for(int i = 0; i <= 10000; i++){
          freq[i] = 0;
     }

     for(int i = 0; i < n; i++){
          cin >> arr[i];
          freq[arr[i]]++;
     }

     int sum = 0;
     dp[0] = 0;
     dp[1] = 1;
     for(int i=2; i <= 1000; i++){
          dp[i] = max(dp[i-2] + i*freq[i], dp[i-1]);
     }
     std::cout << dp[1000] << '\n';
}

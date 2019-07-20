/*
Gary has a sequence A, consisting of n integers.
We'll call a sequence ai, ai + 1, ..., aj (1 ≤ i ≤ j ≤ n) a subsegment of the sequence a.
The value (j - i + 1) denotes the length of the subsegment.

Your task is to find the longest subsegment of a, such that it is possible to change
at most one number (change one number to any integer you want) from the subsegment
to make the subsegment strictly increasing. You need to return the length of the maximum
subsegment that you can find by changing only one integer in the given sequence.
*/

/*
approach
     this problem cannot be solved with single array storing length because if
     we reach at a point that is breaking the order than we need to know the length
     of left of the array which is in length array but wheather to include current
     element to legnth or start new length will depend upone the length of right
     side array, thus we have no way to know legth of right side of array unless
     we traverse it

     then it will become O(n*n) solution , but we can  also store elements length
     of right side at new array

     thus now we have two arrays that tells that for ith element length at left and
     length at right, then all we have to make decision that either to include This
     element or not, thus we have three condiotions

     1) max length lies at left including current element
     2) max length lies at right including current element
     3) max length contains length from left and right along with current element
*/

#include<iostream>
using namespace std;

inline int max(int a, int b){
     return a > b ? a : b;
}

int increasingSubsequent(int arr[], int n){
     int left[n];
     int right[n];
     int len = 1;

     left[0] = 1;
     right[n-1] = 1;

     for(int i = 1; i < n; i++)
          if(arr[i-1] < arr[i])
               left[i] = left[i-1]+1;
          else
               left[i] = 1;

     for(int i = n-2; i >= 0; i--)
          if(arr[i+1] > arr[i])
               right[i] = right[i+1]+1;
          else
               right[i] = 1;

     for(int i = 0; i < n; i++){
          if(i > 0)
               len = max(left[i-1]+1,len);
          if(i < n-1)
               len = max(right[i+1]+1,len);
           if(i != 0 && i != n-1 && arr[i-1]+1 < arr[i+1])
               len= max(right[i+1]+left[i-1]+1,len);
     }
     return len;
}

int main(){
     int n;
     cin >> n;
     int arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];

     std::cout << increasingSubsequent(arr,n) << '\n';
}

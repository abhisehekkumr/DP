class Solution {
public:

    int result(int n, int *arr){

        if(n < 0)
            return 0;

        if(n == 0 | n == 1)
            return 1;

        if(arr[n] > -1)
            return arr[n];

        arr[n] = result(n-1,arr) + result(n-2,arr);
        return arr[n];
    }
    int climbStairs(int n) {

        if(n == 1)
            return 1;

        int *arr = new int[n+1];
        for(int i = 0; i <= n; i++)
            arr[i] = -1;
        result(n,arr);
        return arr[n];
    }
};

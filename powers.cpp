#include<iostream>
#include<map>
using namespace std;

struct Area{
     int a;
     int b;

     Area(int a, int b){
          this->a = a;
          this->b = b;
     }
};

inline int max(int a, int b){
     return a > b ? a : b;
}

int result(int A, int B, Area X, Area Y, Area Z, int last = 1){
     if(A <= 0 || B <= 0)
          return 0;

     int ans = 0;
     if(last == 1)
          ans = 1 + max(result(A + Y.a,B + Y.b,X,Y,Z,2), result(A + Z.a,B + Z.b,X,Y,Z,3));
     if(last == 2)
          ans = 1 + max(result(A + X.a,B + X.b,X,Y,Z,1), result(A + Z.a,B + Z.b,X,Y,Z,3));
     if(last == 3)
          ans = 1 + max(result(A + X.a,B + X.b,X,Y,Z,1), result(A + Y.a,B + Y.b,X,Y,Z,2));

     return ans;
}

int maxSurvival(int A, int B, Area X, Area Y, Area Z, int last){
     if(A <= 0 || B <= 0)
          return 0;
     int ans = 0;

     switch(last){
          case 1:
               ans = 1 + max(maxSurvival(A + Y.a, B + Y.b, X,Y,Z,2),
                             maxSurvival(A + Z.a, B + Z.b, X,Y,Z,3));
               break;
          case 2:
               ans = 1 + max(maxSurvival(A + X.a, B + X.b, X,Y,Z,1),
                        maxSurvival(A + Z.a, B + Z.b, X,Y,Z,3));
               break;
          case 3:
               ans = 1 + max(maxSurvival(A + X.a, B + X.b, X,Y,Z,1),
                        maxSurvival(A + Y.a, B + Y.b, X,Y,Z,2));
               break;
     }

     return ans;
}

int getMaxSurvivalTime(int A, int B, Area X, Area Y, Area Z){
     if(A <= 0 || B <= 0)
          return 0;
     return max(maxSurvival(A+X.a,B+X.b,X,Y,Z,1),
                max(maxSurvival(A+Y.a,B+Y.b,X,Y,Z,2),
                maxSurvival(A+Z.a,B+Z.b,X,Y,Z,3)));
}

int main(){
     int A,B;
     A = 20;
     B = 8;

     Area X(3,2);
     Area Y(-5,-10);
     Area Z(-20,5);

     std::cout << result(A + X.a,B + X.b,X,Y,Z) << '\n';
}

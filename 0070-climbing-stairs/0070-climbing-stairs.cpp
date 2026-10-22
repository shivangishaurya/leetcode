class Solution {
public:
    int climbStairs(int n) {
       long long int a=1,b=1;
       while(n--){
        b=a+b;
        a=b-a;
       } 
       return a;
    }
};
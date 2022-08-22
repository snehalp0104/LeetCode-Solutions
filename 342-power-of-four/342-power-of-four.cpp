class Solution {
public:
    bool isPowerOfFour(int n) {
        int rem=n%4;
        if((rem!=0 and n!=1) or n==0)
            return false;
        if(n==1)
            return true;
        return isPowerOfFour(n/4);
        
    }
};
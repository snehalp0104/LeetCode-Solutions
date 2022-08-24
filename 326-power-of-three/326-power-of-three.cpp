class Solution {
public:
    bool isPowerOfThree(int n) {
        int rem=n%3;
        if((rem!=0 and n!=1) or n==0)
            return false;
        if(n==1)
            return true;
        return isPowerOfThree(n/3);
        
    }
};
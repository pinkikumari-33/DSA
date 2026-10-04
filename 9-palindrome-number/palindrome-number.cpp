class Solution {
public:
    long reverse(int n){
        long ans = 0;
        while(n > 0){
            int d = n % 10;
            ans = ans * 10 + d;
            n /= 10;
        }
        return ans;
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x >= INT_MAX) return false;

        long y = reverse(x);
  
        if(x == y) return true;

        return false;
        
    }
};
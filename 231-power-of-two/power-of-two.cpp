class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;

        while(n > 0 ) {
            int res = n & 1;
            if(res == 1) count++;
            n = n >> 1;
        }

        return count == 1 ? true : false;
    }
};
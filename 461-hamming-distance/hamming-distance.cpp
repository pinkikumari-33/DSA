class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y;
        int count = 0;

        while(res > 0 ) {
            int ans = res & 1;
            if(ans == 1) count++;
            res = res >> 1;
        }

        return count;
    }
};
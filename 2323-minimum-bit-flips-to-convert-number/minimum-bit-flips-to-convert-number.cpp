class Solution {
public:
    int bitDifference(int &start,int &goal) {
        int res = start ^ goal;
        int count = 0;

        while(res > 0) {
            int ans = res & 1;
            if(ans == 1) count++;
            res = res >> 1;
        }

        return count;
    }

    int minBitFlips(int start, int goal) {
        int res = bitDifference(start,goal);
        return res;
    }
};
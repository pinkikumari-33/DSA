class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        int i = 0;
        long long res = 0;
        int count = 1;

        while(i < n){
            int digit = s[i] - '0';

            if(digit > k){
                return -1;
            }
            
            if(res * 10 + digit > k){
                count++;
                res = digit;
            }

            else {
                res = res * 10 + digit;
            }

            i++;
        } 

        return count;  
    }
};
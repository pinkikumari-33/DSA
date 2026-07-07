class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> digits;
        int sum = 0;

        while(n > 0){
            int digit = n % 10;
            if(digit != 0){
                digits.push_back(digit);
                sum += digit;
            } 
            n /= 10;
        }

        long long ans = 0;
        
        for(int i = digits.size()-1; i >= 0; i--){
            ans = ans * 10 + digits[i];
        }

        return ans * sum;
    }
};
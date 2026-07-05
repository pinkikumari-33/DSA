class Solution {
public:
    bool isInteger(char ch){
        if(ch >= '0' && ch <= '9') return true;
        return false;
    }

    long long stringToint(string s,char sign){
        int n = s.size();
        if(n == 0) return 0;
        long long res = 0;

        for(char ch : s){
            res = res * 10 + (ch - '0');
            if(res > INT_MAX) return res;
        }

        return res;
    }

    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        
        while(i < n && s[i] == ' ') i++;

        char sign = '+';
        if(i < n  && (s[i] == '-' || s[i] == '+')){
            sign = s[i];
            i++;
        }

        if(s[i] == '0'){
            while(i < n && s[i] == '0') i++;
        }

        string res = "";
        while(i < n && isInteger(s[i]) == true){
            res += s[i];
            i++;
        }

        long long num = stringToint(res,sign);

        if(num > INT_MAX && sign == '+') return INT_MAX;
        if(num > INT_MAX && sign == '-') return INT_MIN;

        if(sign == '-'){
            num = -1 * num;
        }

        return num;
    }
};
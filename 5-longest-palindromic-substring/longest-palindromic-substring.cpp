class Solution {
public:
    bool isSame(char a, char b){
        return a == b;
    }

    bool isPalindrome(string &s,int i,int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxL = 0;
        int start = 0, end = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(s,i,j)){
                    int length = j - i + 1;
                    if(length > maxL){
                        maxL = length;
                        start = i;
                        end = j;
                    }
                }
            }
        }


        return s.substr(start,end - start + 1);
    }
};
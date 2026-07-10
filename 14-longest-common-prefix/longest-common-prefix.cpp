class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLength = INT_MAX;
        int n= strs.size();

        string res = "";

        for(int i = 0; i < strs.size(); i++){
            minLength = min(minLength,(int)strs[i].length());
        }

        int i = 0;

        for(int j = 0; j < minLength; j++){
            while(i <= n-2 && strs[i][j] == strs[i+1][j]) i++;

            if(i == n-1){
                res += strs[i][j];
                i = 0;
            }
            else{
                return res;
            }
        }

        return res;
        
    }
};
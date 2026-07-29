class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char,int> ch;
        int left = 0;
        int right = 0;

        int maxLen = 0;

        while(right < n){
            char chr = s[right];

            while(ch.find(chr) != ch.end()){
                ch.erase(s[left]);
                left++;
            }

            maxLen = max(maxLen,right-left+1);
            ch[chr] = 1;
            right++;
        }

        return maxLen;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        if(n == 1) return n;

        unordered_set<char> seen;
        int ans = 0;

        int left = 0;
        int right = 0;

        while(right < n) {
            char c = s[right];

            while(seen.find(c) != seen.end()) {
                seen.erase(s[left]);
                left++;
            }
            
            ans = max(ans, right - left + 1);
            seen.insert(c);
            right++;
        }

        return ans;
    }
};
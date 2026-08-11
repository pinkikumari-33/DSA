class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'e'){
            return true;
        }

        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.size();

        int ans = 0;

        int left = 0;
        int right = 0;
        int count = 0;

        while(right < n){

            char ch = s[right];

            if((right - left) + 1 > k){
                if(isVowel(s[left])){
                    count--;
                }

                //count = 0;
                left++;
            }

            if((right - left) + 1 <= k){
                if(isVowel(ch)){
                    count++;
                }
            }

            ans = max(ans,count);

            
            right++;
        }

        return ans;
    }
};
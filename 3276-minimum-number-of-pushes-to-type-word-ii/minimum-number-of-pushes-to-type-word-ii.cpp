class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);

        for(int i = 0; i < word.size(); i++){
            freq[word[i] - 'a']++;
        }

        sort(freq.begin(),freq.end(),greater<int>());
        int count = 0;
        int push = 1;

        for(int i = 0; i < 26; i++){
            if(freq[i] == 0) break;

            count += freq[i] * push;
            if((i+1) % 8 == 0) push++;
        }

        return count;
    }
};
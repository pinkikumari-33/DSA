class Solution {
public:
    bool isomorphic(string s,string t){
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;

        for(int i =0; i < s.length(); i++){
            char c1 = s[i];
            char c2 = t[i];

            if(mp1.find(c1) != mp1.end() && mp1[c1] != c2) return false;

            if(mp2.find(c2) != mp2.end() && mp2[c2] != c1) return false;

            mp1[c1] = c2;
            mp2[c2] = c1;
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;

        for(int i = 0; i < words.size(); i++){
            if(isomorphic(pattern,words[i])){
                res.push_back(words[i]);
            }
        }

        return res;
    }
};
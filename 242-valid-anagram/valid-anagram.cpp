class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();

        if(s_length != t_length) return false;

        map<char,int> map_s;
        map<char,int> map_t;

        for(int i = 0; i < s.length(); i++){
            map_s[s[i]]++;
            map_t[t[i]]++;
        }

        for(auto it : map_s){
            if(map_t[it.first] != it.second) return false;
        }

        return true;
    }
};
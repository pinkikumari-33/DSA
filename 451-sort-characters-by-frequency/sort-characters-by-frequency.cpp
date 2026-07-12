class Solution {
public:

    string frequencySort(string s){
        int n = s.size();
        unordered_map<char,int> freq;

        for(int i = 0 ; i < n; i++){
            freq[s[i]]++;
        }

        vector<pair<int,char>> freqArr;

        for(auto it : freq){
            freqArr.push_back({it.second,it.first});
        }

        sort(freqArr.begin(),freqArr.end(),greater<pair<int,char>>());
        string res = "";
        
        for(auto it : freqArr){
            while(it.first > 0){
                res += it.second;
                it.first--;
            }
        }

        return res;
    }
};
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        unordered_map<int,int> mp2;

        for(auto i : mp) {
            mp2[i.second]++;
        }

        for(auto i : mp2) {
            if(i.second > 1) {
                return false;
            }
        }

        return true;
    }
};
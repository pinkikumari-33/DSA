class Solution {
public:
    int partitionString(string s) {
        int n = s.size();

        vector<int> seen(26,0);

        int i = 0;
        int count = 1;
        
        while(i < n){
            char ch = s[i];

            if(seen[ch - 'a'] == 0){
                seen[ch - 'a'] = 1;
            }
            else{
                count++;
                seen.assign(26, 0);
                seen[ch - 'a'] = 1;
            }

            i++;
        }

        return count;
    }
};
class Solution {
public:
    void noAjacentZeroes(int n,int i,string ans,vector<string> &res){
        if(i == n){
            res.push_back({ans});
            return;
        }

        // Always add one
        noAjacentZeroes(n,i+1,ans + "1",res);

        if(ans.empty() || ans.back() != '0'){
            noAjacentZeroes(n,i+1,ans + "0",res);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> res;
        string ans = "";

        noAjacentZeroes(n,0,ans,res);
        return res;
    }
};
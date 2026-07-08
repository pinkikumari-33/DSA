class Solution {
public:
    void generateString(int n,int i,string ans,vector<string> &result){
        if(i == n){
            result.push_back(ans);
            return;
        }

        generateString(n,i+1,ans+"1",result);

        if(ans.empty() || ans.back() != '0'){
            generateString(n,i+1,ans+"0",result);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> res;
        string ans = "";

        generateString(n,0,ans,res);

        return res;
    }
};
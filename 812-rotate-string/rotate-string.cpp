class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();

        if(n != m) return false;
        
        string doubleS = s + s;

        auto val = doubleS.find(goal);

        if(val != string :: npos) return true;

        return false;
        
        
    }
};
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        for(int i = 0; i < n; i++){
            string rotated = s.substr(i) + s.substr(0,i);
            if(rotated.compare(goal) == 0) return true;
        }

        return false;
        
        
    }
};
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int n = s.length();
        int value = 0;

        for(int i = 0;i < n; i++){
            if(i > 0 && s[i] == 'V' && s[i-1] == 'I'){
                value += 3;
            }

            else if(i > 0 && s[i] == 'X' && s[i-1] == 'I'){
                value += 8;
                i++;
            }

            else if(i > 0 && s[i] == 'C' && s[i-1] == 'X'){
                value += 80;
            }

            else if(i > 0 && s[i] == 'L' && s[i-1] == 'X'){
                value += 30;
            }

            else if(i > 0 && s[i] == 'D' && s[i-1] == 'C'){
                value += 300;
            }

            else if(i > 0 && s[i] == 'M' && s[i-1] == 'C'){
                value += 800;
            }

            else{
                value += roman[s[i]];
            }
        }

        return value;
    }
};
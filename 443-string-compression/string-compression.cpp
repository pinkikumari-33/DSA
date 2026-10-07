class Solution {
public:

    int compress(vector<char>& chars) {
        int count = 0;
        int index = 0;
        int i = 0;

        int n = chars.size();

        while(i < n) {
            char c = chars[i];

            while(i < n && chars[i] == c) {
                count++;
                i++;
            }

            if(count == 1) {
                chars[index] = c;
                index++;
                count = 0;
            }
            
            else {
                chars[index] = c;
                string num = to_string(count);

                for(int j = 0; j < num.size(); j++) {
                    index++;
                    chars[index] = num[j];
                }
                
                index++;
                count = 0;
            }

        }

        return index;
    }
};
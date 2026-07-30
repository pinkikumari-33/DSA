class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3,0);

        int n = s.size();
        // int ans = 0;
        // // a - 0
        // // b - 1
        // // c - 2

        // for(int i = 0; i < n; i++){
        //     count[0] = 0;
        //     count[1] = 0;
        //     count[2] = 0;

        //     for(int j = i; j < n; j++){

        //         count[s[j]-'a']++;

        //         if(count[0] > 0 && count[1] > 0 && count[2] > 0){
        //             ans += (n-j);
        //             break;
        //         }
        //     }
        // }

        int left =0;
        int right = 0;
        int ans = 0;

        while(right < n){
            count[s[right]-'a']++;

            while(left < n && count[0] > 0 && count[1] > 0 && count[2] > 0){
                ans += n- right;
                
                count[s[left] - 'a']--;
                left++;
            }

            right++;
        }

        return ans;
        
    }
};
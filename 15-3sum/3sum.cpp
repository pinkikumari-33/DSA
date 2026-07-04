class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //-------------------- Brute Force Solution ----------------

        // vector<vector<int>> ans;
        // int n = nums.size();

        // set<vector<int>> s;

        // for(int i = 0; i < n; i++){  // ---------------- O(N)
        //     for(int j = i+1; j < n; j++){ // ------------ O(N)
        //         for(int k = j+1; k < n; k++){ // ------------- O(N)

        //             if(nums[i] + nums[j] + nums[k] == 0){
        //                 vector<int> trip = {nums[i] , nums[j] , nums[k] };
        //                 sort(trip.begin(),trip.end()); // nly three number so constant time

        //                 if(s.find(trip) == s.end()){ // --- O(log(UniqueTriplets))
        //                     s.insert(trip);
        //                     ans.push_back(trip);
        //                 }
        //             }
        //         }
        //     }
        // }

        // return ans;

        // TC : O(N^3 * Log(uniq trip))
        // SC : O(Uniq Trip)

        //------------------------ Better Solution -------------------
        // Use of hash map and two sum approach

        // set<vector<int>> trip;

        // int n = nums.size();

        // for(int i = 0; i < n; i++){

        //     int target = - nums[i];  // Fix a
        //     set<int> s;

        //     for(int j = i + 1; j < n; j++){

        //         int rem = target - nums[j]; // find remaing value

        //         if(s.find(rem) != s.end()){
        //             vector<int> ans = {nums[i],nums[j],rem}; 
        //             sort(ans.begin(),ans.end());
        //             trip.insert(ans);
        //         }

        //         s.insert(nums[j]); // insert the nums[j] in set if not found
        //     }
        // }

        // vector<vector<int>> output(trip.begin(),trip.end());
        // return output;

        // TC : O(N * N * Log(UniqueTriplets));
        // SC : O(N + UniqueTriplets);


        // ------------ Optimal Solution -------------------(Two Pointers Approach)
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;

                    while(j < k && nums[j] == nums[j-1]) j++;
                }
            }

        }

        return ans;
    }
};
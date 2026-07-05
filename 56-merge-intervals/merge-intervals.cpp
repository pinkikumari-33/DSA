class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if(n == 1) return intervals;

        sort(intervals.begin(),intervals.end());

        for(vector<int> i : intervals){
            cout<<i[0]<<" "<<i[1]<<endl;
        }

        int i = 0;
        int j = i + 1;

        vector<vector<int>> ans;

        while(j < n){
            if(intervals[i][1] >= intervals[j][0]){
                while(j < n && intervals[i][1] >= intervals[j][0]){
                    intervals[i][1] = max(intervals[i][1],intervals[j][1]);
                    j++;
                }
                ans.push_back({intervals[i][0],intervals[i][1]});
            }else{
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
            i = j;
            j = i + 1;   
        }

        if(i < n) ans.push_back(intervals[i]);

        return ans;        
    }
};
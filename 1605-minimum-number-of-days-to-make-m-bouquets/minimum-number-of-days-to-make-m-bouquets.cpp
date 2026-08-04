class Solution {
public:
    int canMakeBouquets(vector<int> bloomDay,int m,int k,int mid){
        int n = bloomDay.size();
        int count = 0;
        int m2 = 0;

        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= mid){
                count++;
                if(count == k){
                    m2++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }

        return m2;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if((long long)m*k > n) return -1;

        int max = *max_element(bloomDay.begin(),bloomDay.end());

        int low = 1;
        int high = max;

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int res = canMakeBouquets(bloomDay,m,k,mid);

            if(m <= res){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
        
    }
};
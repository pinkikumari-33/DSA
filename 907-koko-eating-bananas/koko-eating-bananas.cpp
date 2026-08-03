class Solution {
public:
    long long requiredTime(vector<int> &piles,int k){
        long long sum = 0;

        for(int i = 0; i < piles.size(); i++){
            sum += ceil((piles[i] + k -1)/k);
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxElem = *max_element(piles.begin(),piles.end());

        int low = 1;
        int high = maxElem;
  
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            long long reqTime = requiredTime(piles,mid);

            if(reqTime <= h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int left = 0;
        int right = n-1;

        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += cardPoints[i];
        }

        int ans = sum;

        for(int i = k-1; i >= 0; i--){
            sum = sum - cardPoints[i];
            sum = sum + cardPoints[right];
            right--;

            ans = max(ans,sum);
        }
        return ans;
    }
};
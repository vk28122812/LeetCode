class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax=nums[0], globalMin=nums[0];
        int currMax=0, currMin = 0;
        int total = 0;
        for(int i:nums){
            currMax = max(i,currMax+i);
            currMin = min(i, currMin+i);
            globalMax = max(globalMax, currMax);
            globalMin = min(globalMin, currMin);
            total += i;
        }
        if(globalMax < 0)return globalMax;
        return max(globalMax, total - globalMin);
    }
};
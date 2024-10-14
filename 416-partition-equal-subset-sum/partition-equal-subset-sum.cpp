class Solution {
public:
    bool targetSum(vector<int>&nums,vector<vector<int>>&dp,int target,int idx,int sum){
        if(idx==nums.size())return sum==target;
        else if(sum==target)return 1;
        else if(sum>target)return 0;
        else if(dp[idx][sum] != -1)return dp[idx][sum];
        int op1 = targetSum(nums,dp,target,idx+1,sum);
        int op2 = targetSum(nums,dp,target,idx+1,sum+nums[idx]);
        return dp[idx][sum]=op1||op2;
    }
    bool canPartition(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int s = accumulate(nums.begin(), nums.end(), 0);
        if(s%2)return 0;
        s/=2;
        vector<vector<int>>dp(nums.size(), vector<int>(2*s+1,-1));
        return targetSum(nums,dp,s,0,0);
    }
};
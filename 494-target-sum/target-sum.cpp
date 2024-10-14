class Solution {
public:
    int solve(vector<int>&nums,vector<vector<int>>&dp,int target,int idx,int s,int offset){
        if(idx==nums.size()){return s==target;}
        if(dp[idx][s+offset] != -1)return dp[idx][s+offset];
        return dp[idx][s+offset] = solve(nums,dp,target,idx+1,s-nums[idx],offset) + solve(nums,dp,target,idx+1,s+nums[idx],offset);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int s = accumulate(nums.begin(), nums.end(), 0);
        int offset = s;
        vector<vector<int>> dp(nums.size(), vector<int>(2*s+1,-1));
        return solve(nums,dp,target,0,0,offset);
    }
};
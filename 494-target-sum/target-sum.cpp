class Solution {
public:
    int solve(vector<int>&nums,unordered_map<int,unordered_map<int,int>>&dp,int&target,int idx,int s){
        if(idx==nums.size()){
            return s==target;
        }
        if(dp.find(idx)!= dp.end() && dp[idx].find(s) != dp[idx].end())return dp[idx][s];
        int add=solve(nums,dp,target,idx+1,s+nums[idx]);
        int minus=solve(nums,dp,target,idx+1,s-nums[idx]);
        return dp[idx][s]=add+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        unordered_map<int, unordered_map<int,int>> dp;
        return solve(nums,dp,target,0,0);
    }
};
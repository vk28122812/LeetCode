class Solution {
public:
    int solve(vector<int>&nums,map<pair<int,int>,int>&dp,int&target,int idx,int s){
        if(idx==nums.size()){
            return s==target;
        }
        if(dp.find({s,idx})!= dp.end())return dp[{s,idx}];
        int add=solve(nums,dp,target,idx+1,s+nums[idx]);
        int minus=solve(nums,dp,target,idx+1,s-nums[idx]);
        return dp[{s,idx}]=add+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        map<pair<int,int>,int> dp;
        return solve(nums,dp,target,0,0);
    }
};
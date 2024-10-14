class Solution {
public:
    int solve(vector<int>&nums,vector<vector<int>>&dp,int s,int i,int off){
        if(i==nums.size()){
            if(s>=0)return s;
            return INT_MAX;
        }
        if(dp[i][s+off]!=-1)return dp[i][s+off];
        return dp[i][s+off]=min(solve(nums,dp,s+nums[i],i+1,off),solve(nums,dp,s-nums[i],i+1,off));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int s = accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>>dp(stones.size(),vector<int>(2*s+1,-1));
        return solve(stones,dp,0,0,s);
    }
};
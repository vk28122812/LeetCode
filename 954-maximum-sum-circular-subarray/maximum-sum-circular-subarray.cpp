class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int gmx=nums[0], gmn=nums[0];
        int cmg=0, cmn = 0;
        int total = 0;
        for(int i:nums){
            cmg = max(i,cmg+i);
            cmn = min(i, cmn+i);
            gmx = max(gmx, cmg);
            gmn = min(gmn, cmn);
            total += i;
        }
        if(gmx < 0)return gmx;
        return max(gmx, total - gmn);
    }
};
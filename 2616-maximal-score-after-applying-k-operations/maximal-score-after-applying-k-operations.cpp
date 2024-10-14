class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        priority_queue<int>pq(nums.begin(),nums.end());
        long long ans=0;
        while(k--){
            int tp = pq.top(); pq.pop();
            ans += tp;
            pq.push(ceil(tp/3.0));
        }
        return ans;
    }
};
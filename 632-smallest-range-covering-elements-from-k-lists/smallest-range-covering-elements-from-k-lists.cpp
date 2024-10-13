class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {  
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        int maxVal = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }       
        int start = 0, end = INT_MAX;
        while(pq.size()==n){
            auto [minVal,idx]=pq.top(); pq.pop();
            if(maxVal-minVal < end-start ){
                start=minVal;
                end=maxVal;
            }
            if( idx.second + 1 < nums[idx.first].size()){
                pq.push({nums[idx.first][idx.second+1], {idx.first,idx.second+1}});
                maxVal = max(maxVal, nums[idx.first][idx.second+1]);
            }
        }
        return {start,end};
    }
};
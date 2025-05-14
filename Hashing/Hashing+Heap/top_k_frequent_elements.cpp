class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>f;
        for(int num:nums)f[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(pair<int,int>it:f){
            minHeap.push(make_pair(it.second,it.first));
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        while (!minHeap.empty()) {
            pair<int, int> top = minHeap.top();
            ans.push_back(top.second);
            minHeap.pop();
        }
        return ans;
    }
};

 bool twoSum(vector<int>& arr, int target) {
        unordered_map<int,pair<bool,int>>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]={true,i};
        }
        for(int i=0;i<arr.size();i++){
            if(m[target-arr[i]].first && m[target-arr[i]].second!=i )return true;
        }
        return false;
    }

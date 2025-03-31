/*You are given an array of integer arr[] where each number represents a vote to a candidate.
Return the candidates that have votes greater than one-third of the total votes, 
If there's not a majority vote, return an empty array. */
vector<int> findMajority(vector<int>& arr) {
        map<int,int>count;
        for(int i=0;i<arr.size();i++){
            count[arr[i]]++;
        }
        vector<int>ans;
        for(auto& it:count){
            if(it.second>arr.size()/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }

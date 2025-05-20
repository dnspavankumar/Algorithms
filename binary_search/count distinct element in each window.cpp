
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int i=0;
        int j=0;
         vector<int> result;
        unordered_map<int, int> freq;
        while(j<k){
            freq[arr[j]]++;
            j++;
        }
        result.push_back(freq.size());
        while(j<arr.size()){
            freq[arr[i]]--;
            if(freq[arr[i]]==0)freq.erase(arr[i]);
            i++;
            freq[arr[j++]]++;
            result.push_back(freq.size());
        }
        return result;
    }
};

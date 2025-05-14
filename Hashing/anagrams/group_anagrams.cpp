class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      //store the words with their sorted form as key
      //reason two angrams will for sure have same soreted key
      //as on sorting two anagrams would give same sorted strings
      //due to this all angrams would reach the same key
        unordered_map<string,vector<string>>m;
        vector<vector<string>>ans;
        for(string str:strs){
            string key=str;
            sort(key.begin(),key.end());
            m[key].push_back(str);
        }
        for(pair<string,vector<string>>it:m){
            ans.push_back(it.second);
        }
        return ans;   
    }
};

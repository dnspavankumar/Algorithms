 int missingNumber(vector<int> &arr) {
        set<int>s(arr.begin(),arr.end());
        for(int i=1;i<=arr.size();i++){
            if(s.find(i)==s.end())return i;
        }
        return arr.size()+1;
    }

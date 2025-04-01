int countPairs(vector<int> &arr, int target) {
  //a map that stores elements and their frequencies
        unordered_map<int,int>m;
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
//if u find the element target-arr[i] increase the count by frequency of it
/*coz if target is 6 and u have picked the element arr[i] as 1 and u have two 5's u can for two pairs (1,5)(1,5)*/          
             if(m.find(target-arr[i])!=m.end()){
                count+=m[target-arr[i]];
            }
//if not found then increase the frequency of the current element u r holding i.e arr[i]          
             m[arr[i]]++;
        }
        return count;
    }

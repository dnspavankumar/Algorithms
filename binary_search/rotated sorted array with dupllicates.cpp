class Solution {
  public:
    bool Search(vector<int>& arr, int target) {
        // Code here
      int i=0;
      int j=arr.size()-1;
      while(i<=j){
        int mid=i+(j-i)/2;
        ///////////////////////////////////////////
        //////////duplicates condition/////////////
        if(arr[i]==arr[mid] && arr[mid]==arr[j]){
            i++;j--;
        }
        ///////////////////////////////////////////
        ///////////////////////////////////////////
        if(arr[mid]==target) return true;
        if(arr[i]<=arr[mid]){
            if(arr[i]<=target && target<arr[mid]){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        else{
            if(arr[mid]<target && target<=arr[j]){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
      }
      return false;  
    }
};

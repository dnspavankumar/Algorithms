class Solution {
  public:
    bool feasible(vector<int>arr,int given_number_of_students,int mid){
        int number_of_students_required=1;
        int number_of_pages_allocated_to_current_student=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid)return false;
            if(number_of_pages_allocated_to_current_student+arr[i]>mid){
                number_of_students_required++;
                number_of_pages_allocated_to_current_student=arr[i];
                if(number_of_students_required>given_number_of_students){
                    return false;
                }
            }
            else{
                number_of_pages_allocated_to_current_student+=arr[i];
            }
        }
        return true;
    }
    int findPages(vector<int> &arr, int m) {
          int n = arr.size();
        if (m > n) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (feasible(arr,m, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};

 int majorityElement(vector<int>& nums) {
       int participant=nums[0];
       int votes=0;
       for(int i=1;i<nums.size();i++){
            if(nums[i]==participant){
                votes++;
            }
            else{
                votes--;
            }
            if(votes<0){
                participant=nums[i];
                votes=0;
            }
       }
       return participant; 
    }

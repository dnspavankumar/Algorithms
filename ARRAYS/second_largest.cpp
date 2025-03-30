 int getSecondLargest(vector<int> &arr) {
        int first_largest=arr[0];
        int second_largest=INT_MIN;
   
        for(int i=0;i<arr.size();i++){
            if(arr[i]>first_largest){
                second_largest=first_largest;
                first_largest=arr[i];
            }
            /*take example[10,10,2]
              first largest is 10 (arr[0])
              ***first iteration***
              10>10 is false
              first_largest=10
              second_largest=INT_MIN
              *** second iteration ***
              10>10 is false
              first_largest=10
              second_largest=INT_MIN
               *** third iteration ***
              2>10 is false
              first_largest=10
              second_largest=INT_MIN
            */ 


            //to overcome this this condition is being checked
            //2 is grater than int min and less than first largest (10) 
            else if(arr[i]>second_largest && arr[i]< first_largest){
                second_largest=arr[i];
            }
        }
        if(second_largest==INT_MIN){
            return -1;
        }
        return second_largest;
    }

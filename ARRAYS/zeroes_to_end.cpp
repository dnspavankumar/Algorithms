 void pushZerosToEnd(vector<int>& arr) {
        int insertion_index=0;
        int insertion_element=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                insertion_element=arr[i];
                arr[insertion_index]=insertion_element;
                insertion_index++;
            }
        }
        for(int i = insertion_index;i<arr.size();i++){
            arr[i]=0;
        }
    }

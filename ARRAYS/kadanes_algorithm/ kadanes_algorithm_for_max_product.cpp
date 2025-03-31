int maxProduct(vector<int> &arr) {
        int n=arr.size();
  /*
  we may encounter negative numbers so maintain a variable min_product too 
  because if min product is multiplied to another negative number it results in a positive number
  */
        int max_product=arr[0];
        int min_product=arr[0];
        int result=arr[0];
//traverse the array
        for(int i=1;i<n;i++){
        // if a negative number is encountered the min product is maximum and max product is minimum
        //because multiplying min product with a negative number would result in a positive number
            if(arr[i]<0)swap(max_product,min_product);
         // coz of swapping everytime the max product will have the maximum value 
            max_product=max(arr[i],max_product*arr[i]);
            min_product=min(arr[i],min_product*arr[i]);
            result=max(result,max_product);
        }
        return result;
    }

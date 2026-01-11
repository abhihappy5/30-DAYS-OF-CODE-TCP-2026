class Solution {
  private :
    void merge(vector<int>& arr, int l, int r ){
        int m = l+(r-l)/2;
        int len1 = m-l+1;
        int len2 = r-m;
        
        int *first = new int[len1];
        int *second = new int[len2];
        
        int k=l;
        for(int i=0 ; i<len1 ; i++){
            first[i] = arr[k++];
        }
        
        k=m+1;
        for(int i=0 ; i<len2 ; i++){
            second[i] = arr[k++];
        }
        
        int i=0,j=0;
        k=l;
        
        while(i<len1 && j<len2){
        if (first[i] <= second[j]) {
            arr[k] = first[i];
            i++;
        }
        else{
            arr[k] = second[j];
            j++;
        }
        k++;
        }
        
        while(i<len1){
            arr[k++]=first[i++];
        }
        
        while(j<len2){
            arr[k++]=second[j++];
        }
        
        delete[] first;
        delete[] second;
        
    }
    
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l<r){
        int m = l+(r-l)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr, l, r);
        }
    }
};

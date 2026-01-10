class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int s=0 , mid=0 , e=arr.size()-1;
        while(mid<=e){
            if(arr[mid]==0){
                swap(arr[s++],arr[mid++]);
            }
            else if(arr[mid]==1){
                mid++ ;
            }
            else{
                swap(arr[mid],arr[e--]);
            }
        }
    }
};

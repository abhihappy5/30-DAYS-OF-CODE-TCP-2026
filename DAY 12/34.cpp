class Solution {
private :
    int lastOcc(vector<int>& nums, int n, int target){
        int s = 0, e = n-1, last = -1;
        while(s<=e){
            int m = s+(e-s)/2 ;
            if(nums[m]==target){
                last = m;
                s = m+1;
            }
            else if(nums[m]>target){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
    return last;
    } 

    int firstOcc(vector<int>& nums, int n, int target){
        int s = 0, e = n-1, first = -1;
        while(s<=e){
            int m = s+(e-s)/2 ;
            if(nums[m]==target){
                first = m;
                e = m-1;
            }
            else if(nums[m]>target){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
    return first;
    }    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOcc(nums,n,target);
        if (first == -1) 
            return {-1,-1};
        int second = lastOcc(nums,n,target);

    return{first,second};    
    }
};

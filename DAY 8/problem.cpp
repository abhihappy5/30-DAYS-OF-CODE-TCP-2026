class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 1, maxcnt = 1;
        
        if (nums.empty()) return 0;
        
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i] == nums[i+1]) {
                continue; 
            }
            else if (nums[i]+1 == nums[i+1]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            maxcnt = max(maxcnt, cnt);
        }
        return maxcnt;
    }
};

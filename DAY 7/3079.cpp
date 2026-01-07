class Solution {    
public:
    int encrypt(int x) {
        int maxi = 0, digits = 0;

        if(x == 0) return 0;
        while (x > 0) {
            maxi = max(maxi, x % 10);
            x /= 10;
            digits++;
        }
        int ans = 0;
        for (int i = 0; i < digits; i++) {
            ans = ans * 10 + maxi;
        }
    return ans;
    }

    int sumOfEncryptedInt(vector<int>& nums) {
        
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
           int x = nums[i];
           cnt += encrypt(x); 
        }
    return cnt;    
    }
};

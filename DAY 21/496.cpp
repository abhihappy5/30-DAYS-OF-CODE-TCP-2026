// NEXT GREATER ELEMENT I
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> s; vector<int> ans;
        for (int x : nums2) {
            while (!s.empty() && s.top()<x) {
                m[s.top()] = x;
                s.pop();
            }
            s.push(x);
        }
        
        for (int x : nums1) {
            if (m.count(x)) ans.push_back(m[x]);
            else ans.push_back(-1);            
        }
    return ans;
    }
};


/*
// BRUTE FORCE SOLN.
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            int nextNum = -1;
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    for(int k=j+1; k<nums2.size(); k++){
                        if(nums2[k]>nums2[j]){
                            nextNum = nums2[k];
                            break;
                        }      
                    }
                break;
                }
            }
            ans.push_back(nextNum);
        }
    return ans;
    }
};
*/

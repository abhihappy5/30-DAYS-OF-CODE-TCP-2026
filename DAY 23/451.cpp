//Sort Characters by Frequency
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> frq;
        vector<pair<char, int>> v;
        for (int i = 0; i < s.length(); i++) {
            frq[s[i]]++;
        }
        for(auto x : frq){
            v.push_back(x);
        }

        sort(v.begin(),v.end(),[](auto y, auto z){return y.second > z.second;});

        string ans = "";
        for (int i = 0; i < v.size(); i++) {
            ans += string(v[i].second, v[i].first);
        }
    return ans;
    }
};

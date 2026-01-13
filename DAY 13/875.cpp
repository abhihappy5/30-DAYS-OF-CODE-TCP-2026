using ll = long long;
class Solution {
public:
    ll calculateTime(vector<int>& piles , int mid){
        ll totalHour = 0;
        for(int i=0; i<piles.size(); i++){
            totalHour += (piles[i] + mid - 1) / mid;
        }
    return totalHour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
       int s = 1, e = *max_element(piles.begin(), piles.end());
       while(s<=e){
            int mid = s + (e-s)/2;
            ll totalHour = calculateTime(piles, mid);

            if(totalHour <= h) e = mid-1;

            else s = mid+1;                
        }
    return s;
    }
};

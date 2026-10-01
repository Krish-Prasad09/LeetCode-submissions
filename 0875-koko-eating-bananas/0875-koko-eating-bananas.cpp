class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int s=1, e=piles.back();
        while(s<=e){
            int mid=s+(e-s)/2;
            long long hr=0;
            for(int i=0; i<n;i++){
                hr+=ceil((double)piles[i]/(double) mid);
            }
            if(hr>h){
                s=mid+1;
            }
            else e=mid-1;
        }
        return s;
    }
};
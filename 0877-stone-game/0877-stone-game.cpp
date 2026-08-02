class Solution {
public:
    bool stoneGame(vector<int>& arr) {
        int n=arr.size();
        int l=0, r=n-1;
        int cntA=0, cntB=0,t=0;
        while(l<r){
            if(t%2 ==0){
                if(arr[l]>=arr[r]){
                    cntA+=arr[l];
                    l++;
                }
                else cntA+=arr[r];
                r--;
            }
            else{
                if(arr[l]>=arr[r]){
                    cntB+=arr[l];
                    l++;
                }
                else cntB+=arr[r];
                r--;
            }
        }
        return cntA>cntB ? true:false;
    }
};
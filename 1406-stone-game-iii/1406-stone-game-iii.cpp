class Solution {
    int dp[50005][2]; // Added DP array to prevent Time Limit Exceeded (TLE)
    
public:
    pair<int,string> f(int ind, int c, int diff, vector<int>&arr){
        int n=arr.size();
        if(ind>=n) return {0,"Tie"};
        
        // DP Check: If we already calculated this exact state, return it immediately
        if(dp[ind][c] != -1) return {dp[ind][c], ""}; 
        
        int cntA=-1e9, cntB=-1e9;
        
        if(c==0){
            if(ind+2<n){
                cntA=max({arr[ind]-f(ind+1,1,diff,arr).first,
                          arr[ind]+arr[ind+1]-f(ind+2,1,diff,arr).first, 
                          arr[ind]+arr[ind+1]+arr[ind+2]- f(ind+3,1,diff,arr).first });
            } 
            else if(ind+1<n) cntA=max({arr[ind]-f(ind+1,1,diff,arr).first,
                                       arr[ind]+arr[ind+1]-f(ind+2,1,diff,arr).first});
            else if(ind<n) cntA=arr[ind]-f(ind+1,1,diff,arr).first;

            dp[ind][c] = cntA; // Save to DP array
            
            // FIX: Check cntA against 0, exactly like you did for Bob!
            if(cntA>0) return {cntA,"Alice"};
            else if(cntA<0) return {cntA,"Bob"};
            else return {cntA,"Tie"};
        }
        else if(c==1){
            if(ind+2<n) cntB=max({arr[ind]-f(ind+1,0,diff,arr).first,
                                  arr[ind]+arr[ind+1]-f(ind+2,0,diff,arr).first, 
                                  arr[ind]+arr[ind+1]+arr[ind+2]- f(ind+3,0,diff,arr).first });
            else if(ind+1<n) cntB=max({arr[ind]-f(ind+1,0,diff,arr).first,
                                       arr[ind]+arr[ind+1]-f(ind+2,0,diff,arr).first});
            else if(ind<n) cntB=arr[ind]-f(ind+1,0,diff,arr).first;

            dp[ind][c] = cntB; // Save to DP array
            
            if(cntB>0) return {cntB,"Bob"};
            else if(cntB<0) return {cntB,"Alice"};
            else return {cntB,"Tie"};
        }
        
        return {0,"Tie"};
    }
    
    string stoneGameIII(vector<int>& arr) {
        memset(dp, -1, sizeof(dp)); // Initialize DP array with -1
        int n=arr.size();
        int diff=0;
        return f(0,0,diff,arr).second;
    }
};

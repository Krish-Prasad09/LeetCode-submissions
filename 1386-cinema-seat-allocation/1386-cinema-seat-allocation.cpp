class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int len=reservedSeats.size();
        sort(reservedSeats.begin(),reservedSeats.end());
        int prev=1;
        int prevr=0;
        vector<int> vec(10,0);
        int cnt=0;
        for(int j=0; j<len; j++){
            int u=reservedSeats[j][0];
            int v=reservedSeats[j][1];
            if(prev==u){
                vec[v-1]=1;
            }
            else{
                if(u!=prevr+1)
                    cnt+=(u-prevr-1)*2;
                bool haikya=true;
                int haikya2=-1;
                for(int i=1; i<=4; i++){
                    if(vec[i]==1) haikya=false;
                }
                if(haikya) cnt++;
                else{
                    for(int i=3; i<=6; i++){
                        if(vec[i]==1) {
                            haikya2=0;
                            break;
                        }
                    }
                    if(haikya2==-1){
                        cnt++;
                        haikya2=1;
                    }
                }
                if(haikya2==-1 || haikya2==0){
                    haikya=true;
                    for(int i=5; i<=8; i++){
                        if(vec[i]==1) haikya=false;
                    }
                    if(haikya) cnt++;
                    haikya=false;
                }
                prev=u;
                fill(vec.begin(), vec.end(), 0);
                vec[v-1]=1;
                prevr=u;
            }
        }
        // Process the last row
         bool haikya=true;
                int haikya2=-1;
                for(int i=1; i<=4; i++){
                    if(vec[i]==1) haikya=false;
                }
                if(haikya) cnt++;
                else{
                    for(int i=3; i<=6; i++){
                        if(vec[i]==1) {
                            haikya2=0;
                            break;
                        }
                    }
                    if(haikya2==-1){
                        cnt++;
                        haikya2=1;
                    }
                }
                if(haikya2==-1 || haikya2==0){
                    haikya=true;
                    for(int i=5; i<=8; i++){
                        if(vec[i]==1) haikya=false;
                    }
                    if(haikya) cnt++;
                    haikya=false;
                }
                cnt+=(n-prevr-1)*2;

        return cnt;
    }
};
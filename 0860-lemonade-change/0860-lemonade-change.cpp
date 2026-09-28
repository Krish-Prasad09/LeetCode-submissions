class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int cnt5=0, cnt10=0;
        for(int i=0; i<n; i++){
            if(bills[i]==10){
                if(cnt5==0) return false;
                cnt5--;
                cnt10++;

            }
            else if(bills[i]==20){
                if((cnt10>=1 && cnt5>=1) || cnt5>=3){
                    if(cnt10>=1){
                        cnt10--;
                        cnt5--;
                    }
                    else{
                        cnt5-=3;
                    }
                }
                else return false;
            }
            else cnt5++;
            if(cnt5<0 || cnt10<0){
                cnt5=0;
                cnt10=0;
            }
        }
        return true;
    }
};
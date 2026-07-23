class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int dy=day-1;
        bool leap=false;
        if(year%4 ==0 && year!=2100){
                leap=true;
        }
        month--;
        while(month>=1){
            if(month==2 && leap) dy+=29;
            else if(month==2 && !leap) dy+=28;
            else if(month==1|| month==3 || month==5 || month==7 || month==8 || month==10 || month==12) dy+=31;
            else dy+= 30;
            month--;
        }
        year--;
        while(year!=1971){
            if(year%4 ==0 && year!=2100){
                dy+=366;
            }
            else{
                dy+=365;
            }
            
            year--;
        }
        dy++;
        vector<string> days = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        return days[dy % 7];
    }
};
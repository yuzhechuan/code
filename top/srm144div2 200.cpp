#include <bits/stdc++.h>
using namespace std;
class Time{
    public:
    string whatTime(int n){
        int h=0,m=0,s=0;
        while(n--){
            s++;
            if(s>=60) s=0,m++;
            if(m>=60) m=0,h++;
        }
        ostringstream ans;
        ans<<h<<":"<<m<<":"<<s;
        return ans.str();
    }
};

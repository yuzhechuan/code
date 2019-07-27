#include <bits/stdc++.h>
//#include <tr1/unordered_map>
//using namespace std::tr1;
using namespace std;
unordered_map<int,int> X,Y;
map<pair<int,int>,int> p;
long long ans;
int n;
signed main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<=n;i++){
        scanf("%d%d",&x,&y);
        ans+=X[x]+Y[y]-p[make_pair(x,y)];
        X[x]++;
        Y[y]++;
        p[make_pair(x,y)]++;
    }
    printf("%I64d",ans);
}

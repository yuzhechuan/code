#include <bits/stdc++.h>
using namespace std;
int n,a[50005],c[50005],x,y,Q;
string s;
inline int fyc(const int &x){return x&-x;}
inline void up(int i,int x){
    while(i<=n){
        c[i]+=x;
        i+=fyc(i);
    }
}
inline int que(int i){
    int tot=0;
    while(i>0){
        tot+=c[i];
        i-=fyc(i);
    }
    return tot;
}
signed main(){
    scanf("%d",&Q);
    for(int t=1;t<=Q;t++){
        printf("Case %d:\n",t);
        memset(a,0,sizeof a);
        memset(c,0,sizeof c);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),up(i,a[i]);
        cin>>s;
        while(s!="End"){
            scanf("%d%d",&x,&y);
            if(s=="Query") printf("%d\n",que(y)-que(x-1));
            else if(s=="Add") up(x,y);
            else up(x,-y);
            cin>>s;
        }
    }
    return 0;
}

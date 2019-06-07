#include <bits/stdc++.h>
using namespace std;
bool v[100004];
long long ans;
int t,qn[100005],q[100005][30],b,d,k;
inline int f(int x,int num){
    int res=0;
    for(int i=1;i<=(1<<qn[x])-1;i++){
        int tot=0,tp=1;
        for(int j=0;j<=qn[x]-1;j++)if((i>>j)&1) tot++,tp*=q[x][j+1];
        if(tot&1) res+=num/tp;
        else res-=num/tp;
    }
    return num-res;
}
signed main(){
    for(int i=2;i<=100000;i++) if(!v[i]){
        q[i][++qn[i]]=i;
        for(int j=i+i;j<=100000;j+=i) v[j]=1,q[j][++qn[j]]=i;
    }
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        scanf("%d%d%d%d%d",&b,&b,&d,&d,&k);
        if(!k){printf("Case %d: 0\n",T);continue;}
        b/=k,d/=k;
        if(b>d) swap(b,d);
        ans=0;
        for(int i=1;i<=d;i++)
            ans+=f(i,min(i,b));
        printf("Case %d: %lld\n",T,ans);
    }
}

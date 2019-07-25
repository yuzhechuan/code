#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],b[N],nm;
struct ball{
    int i,n;
    inline bool operator < (const ball &nt) const{
        if(n==nt.n) return i<nt.i;
        return n<nt.n;
    }
};
struct ANS{
    int x,y,z;
    inline void change(){
        int tx=x,ty=y,tz=z;
        x=max(max(tx,ty),tz);
        z=min(min(tx,ty),tz);
        y=tx+ty+tz-x-z;
    }
}ans[N/3];
priority_queue<ball> q;
signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+1+n);
    sort(a+1,a+1+n);
    int un=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;){
        int j=i;
        while(j+1<=n&&a[j+1]==a[i]) j++;
        int hn=j-i+1,id=lower_bound(b+1,b+1+un,a[i])-b;
        // printf("%d %d\n",b[id],hn);
        q.push((ball){id,hn});
        i=j+1;
    }
    while(q.size()>=3){
        ball alpha=q.top();q.pop();
        ball beta=q.top();q.pop();
        ball gamma=q.top();q.pop();
        alpha.n--;if(alpha.n) q.push(alpha);
        beta.n--;if(beta.n) q.push(beta);
        gamma.n--;if(gamma.n) q.push(gamma);
        ans[++nm]=((ANS){b[alpha.i],b[beta.i],b[gamma.i]});
    }
    printf("%d\n",nm);
    for(int i=1;i<=nm;i++){
        ANS now=ans[i];
        now.change();
        printf("%d %d %d\n",now.x,now.y,now.z);
    }
}

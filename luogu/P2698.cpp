#include <bits/stdc++.h>
using namespace std;
int ans=0x3f3f3f3f,n,d,l,r,h1,h2,t1,t2,q1[100005],q2[100005];
struct node{int x,y;}a[100005];
inline bool cmp(const node &x,const node &y){return x.x<y.x;}
signed main(){
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);
    while(++l<=n){
        while(h1<=t1&&q1[h1]<l) h1++;
        while(h2<=t2&&q2[h2]<l) h2++;
        while(a[q1[h1]].y-a[q2[h2]].y<d&&r<n){
            r++;
            while(a[q1[t1]].y<a[r].y&&h1<=t1) t1--;
            q1[++t1]=r;
            while(a[q2[t2]].y>a[r].y&&h2<=t2) t2--;
            q2[++t2]=r;
        }
        if(a[q1[h1]].y-a[q2[h2]].y>=d) ans=min(ans,a[r].x-a[l].x);
    }
    printf("%d",ans==0x3f3f3f3f?-1:ans);
}

#include <bits/stdc++.h>
using namespace std;
int n,k;
struct node{int x,id;}a[1000005];
deque<node> q;
signed main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].id=i;
    for(int i=1;i<=n;i++){
        while(!q.empty()&&q.back().x>=a[i].x) q.pop_back();
        q.push_back(a[i]);
        while(!q.empty()&&q.front().id+k<=i) q.pop_front();
        if(i>=k) printf("%d ",q.front().x);
    }
    q.clear();
    puts("");
    for(int i=1;i<=n;i++){
        while(!q.empty()&&q.back().x<=a[i].x) q.pop_back();
        q.push_back(a[i]);
        while(!q.empty()&&q.front().id+k<=i) q.pop_front();
        if(i>=k) printf("%d ",q.front().x);
    }
}

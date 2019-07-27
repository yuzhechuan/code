#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e5+5;
struct trie{
    int x,nt[26];
}a[M*10];
char s1[N],s2[M][1005];
int n,m,cnt,ans[N],pre[N];
inline void ins(char *s,int id){
    int x=0;
    for(int i=0;s[i];i++){
        int k=tolower(s[i])-'a';
        if(!a[x].nt[k]) a[x].nt[k]=++cnt;
        x=a[x].nt[k];
    }
    a[x].x=id;
}
inline void que(char *s,int id){
    int x=0;
    for(int i=id;i>=0;i--){
        int k=tolower(s[i])-'a';
        if(!a[x].nt[k]) return ;
        x=a[x].nt[k];
        // printf("%d %d %d %d %d\n",x,k,a[x].x,ans[i-1],i);
        if(a[x].x&&(ans[i-1]||i==0)){
            pre[id]=i-1;
            ans[id]=a[x].x;
            return ;
        }
    }
}
void print(const int &x){
    // printf("%d %d\n",x,pre[x]);
    if(pre[x]!=-1) print(pre[x]);
    printf("%s ",s2[ans[x]]);
}
signed main(){
    scanf("%d",&n);
    scanf("%s",s1);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%s",s2[i]);
        ins(s2[i],i);
    }
    // printf("%d|||\n",cnt);
    // memset(ans,0,sizeof ans);
    for(int i=1;i<=n;i++)
        que(s1,i-1);
    print(n-1);
}

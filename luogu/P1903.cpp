#include <bits/stdc++.h>
using namespace std;
#define getchar gc
char getchar(){
	static char buf[1<<16],*p1=buf,*p2=buf;
	if(p1==p2){
		p2=(p1=buf)+fread(buf,1,1<<16,stdin);
		if(p2==p1) return EOF;
	}
	return *p1++;
}
#define rint register int
template<class t> void read(t &x){
    x=0;char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
template<class t> void write(t x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
template<class t> void Write(t x,char c){write(x);putchar(c);}
inline int rd(){int temp;read(temp);return temp;}
inline void swap(int &x,int &y){x^=y^=x^=y;}
const int N=5e4+233,C=1e6+233;
int now,a[N],cnt[C],ans[N],block[N],qn,bn,len,cn,n,m,ql,qr,qt;
struct query{int l,r,t,i;}q[N];
struct modify{int p,col,lt;}c[N];
inline bool cmp(const query &x,const query &y){return block[x.l]^block[y.l]?block[x.l]<block[y.l]:block[x.r]^block[y.r]?block[x.r]<block[y.r]:x.t<y.t;}
inline void add(const int &x){now+=(++cnt[a[x]]==1);}
inline void del(const int &x){now-=(--cnt[a[x]]==0);}
inline void time(const int &x){
    if(ql<=c[x].p&&c[x].p<=qr){
        now-=(--cnt[a[c[x].p]]==0);
        now+=(++cnt[c[x].col]==1);
    }
    swap(c[x].col,a[c[x].p]);
}
signed main(){
    read(n),read(m);
    len=pow(n,2.0/3);
    bn=(n+(len>>1))/len;
    for(rint i=1;i<=bn;++i)
        for(rint j=(i-1)*len+1;j<=i*len;++j)
            block[j]=i;
    for(rint i=1;i<=n;++i)
        read(a[i]);
    while(m--){
        char cc=getchar();while(cc!='Q'&&cc!='R') cc=getchar();
        if(cc=='Q') q[++qn]=(query){rd(),rd(),cn,qn};
        if(cc=='R') c[++cn]=(modify){rd(),rd(),0};
    }
    sort(q+1,q+1+qn,cmp);
    int l=1,r=0,t=0;
    for(rint i=1;i<=qn;++i){
        ql=q[i].l,qr=q[i].r,qt=q[i].t;
        while(l<ql) del(l++);
        while(l>ql) add(--l);
        while(r>qr) del(r--);
        while(r<qr) add(++r);
        while(t<qt) time(++t);
        while(t>qt) time(t--);
        ans[q[i].i]=now;
    }
    for(rint i=1;i<=qn;++i)
        Write(ans[i],'\n');
}

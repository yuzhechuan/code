#include <bits/stdc++.h>
#define rint register int
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
template<class t> void read(t &x){
    x=0;char c=getchar();
    bool f=0;
    while(c<'0'||c>'9') f|=c=='-',c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;
}
template<class t> void write(t x){
    if(x<0) putchar('-'),write(-x);
    else{
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
}
template<class t> void Write(t x,char c){
	write(x);putchar(c);
}
const int N=1e5+30,B=333,oo=0x3f3f3f3f;
int a[N],block[N],L[B],R[B],same[B],n,bn,len;
inline void push(const int &x){
    if(same[x]!=-oo){
        for(rint i=L[x];i<=R[x];i++)
            a[i]=same[x];
        same[x]=-oo;
    }
}
inline int work(int l,int r,int v){
    int p=block[l],q=block[r],res=0;
    push(p);
    if(p==q){
        if(same[p]==v) return r-l+1;
        for(rint i=l;i<=r;i++)
            if(a[i]==v) res++;
            else a[i]=v;
        return res;
    }
    push(q);
    for(rint i=p+1;i<=q-1;i++){
        if(same[i]==v) res+=R[i]-L[i]+1;
        else{
            if(same[i]==-oo)
                for(rint j=L[i];j<=R[i];j++)
                    if(a[j]==v) res++;
                    else a[j]=v;
        }
        same[i]=v;
    }
    if(same[p]==v) res+=R[p]-l+1;
    else
    for(rint i=l;i<=R[p];i++)
        if(a[i]==v) res++;
        else a[i]=v;
    if(same[q]==v) res+=r-L[q]+1;
    else
    for(rint i=L[q];i<=r;i++)
        if(a[i]==v) res++;
        else a[i]=v;
    return res;
}
signed main(){
    read(n);
    for(rint i=1;i<=n;i++)
        read(a[i]);
    bn=len=sqrt(n);
    for(rint i=1;i<=bn;i++){
        L[i]=(i-1)*len+1;
        R[i]=i*len;
    }
    if(R[bn]<n){
        L[++bn]=R[bn-1]+1;
        R[bn]=n;
    }
    for(rint i=1;i<=bn;i++){
        same[i]=-oo;
        for(rint j=L[i];j<=R[i];j++)
            block[j]=i;
    }
    while(n--){
        int l,r,c;
        read(l),read(r),read(c);
        Write(work(l,r,c),'\n');
    }
}

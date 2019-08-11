#include <bits/stdc++.h>
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
using namespace std;
template<class t> void read(t &x){
    x=0;char c=getchar();
    bool f=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
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
const int N=50005,B=225;
int n,len,bn,L[B],R[B],tag[B],a[N],block[N];
inline void add(int l,int r,int c){
	int p=block[l],q=block[r];
	if(p==q){
		for(int i=l;i<=r;++i)
			a[i]+=c;
		return ;
	}
	for(rint i=p+1;i<=q-1;++i)
		tag[i]+=c;
	for(rint i=l;i<=R[p];++i)
		a[i]+=c;
	for(rint i=L[q];i<=r;++i)
		a[i]+=c;
}
signed main(){
	read(n);
	for(rint i=1;i<=n;++i)
		read(a[i]);
	bn=len=sqrt(n);
	for(rint i=1;i<=bn;++i){
		L[i]=(i-1)*len+1;
		R[i]=i*len;
		for(rint j=L[i];j<=R[i];++j)
			block[j]=i;
	}
	if(R[bn]<n){
		L[++bn]=R[bn-1]+1;
		R[bn]=n;
		for(rint i=L[bn];i<=n;++i)
			block[i]=bn;
	}
	for(rint i=1;i<=n;++i){
		int opt,l,r,c;
		read(opt);
		read(l);
		read(r);
		read(c);
		if(!opt) add(l,r,c);
		else Write(a[r]+tag[block[r]],'\n');
	}
}

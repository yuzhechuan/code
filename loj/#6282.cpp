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
const int N=200050,B=460;
int a[N],n,len,lim,bn;
vector<int> vec[B];
struct res{int block,pos;};
inline res get(int x){
    int p=1;
    while(x>vec[p].size()) x-=vec[p].size(),p++;
    return (res){p,x-1};
}
inline void rebuild(){
    int n=0;
    for(rint i=1;i<=bn;i++){
        int kkk=vec[i].size();
        for(int j=0;j<kkk;j++)
            a[++n]=vec[i][j];
        vec[i].clear();
    }
    len=sqrt(n);
    for(rint i=1;i<=n;i++)
        vec[(i-1)/len+1].push_back(a[i]);
    bn=(n-1)/len+1;
    lim=len*sqrt(len);
}
inline void edi(int x,int v){
    res now=get(x);
    vec[now.block].insert(vec[now.block].begin()+now.pos,v);
    if(vec[now.block].size()>lim) rebuild();
}
inline int que(int x){
    res now=get(x);
    return vec[now.block][now.pos];
}
signed main(){
    read(n);
    for(rint i=1;i<=n;i++)
        read(a[i]);
    len=sqrt(n);
    for(rint i=1;i<=n;i++)
        vec[(i-1)/len+1].push_back(a[i]);
    bn=(n-1)/len+1;
    lim=len*sqrt(len);
    while(n--){
        int opt,l,r,c;
        read(opt),read(l),read(r),read(c);
        if(!opt){
            edi(l,r);
        }
        else{
            Write(que(r),'\n');
        }
    }
}

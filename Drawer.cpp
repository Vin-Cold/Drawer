#include<map>
#include<set>
#include<list>
#include<queue>
#include<vector>
#include<string>
#include<time.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxn 5000000
#define reg register
#define ll long long
#define inf 2147483647
#define lowbit(x) ((x)&-(x))
#define abs(x) ((x)<0?-(x):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define isd(c) ('0'<=(c)&&(c)<='9')
#define isa(c) ('a'<=(c)&&(c)<='z')
#define isA(c) ('A'<=(c)&&(c)<='Z')
#define ckmax(a,b) ((a)=max((a),(b)))
#define ckmin(a,b) ((a)=min((a),(b)))
#define swap(a,b) ((a)==(b)?(a)=(b):((a)^=(b)^=(a)^=(b)))
using namespace std;
template<typename T> inline void read(T&x){T f=1;x=0;char c;
    for (c=getchar(); !isd(c); c=getchar()) f=(c=='-')?-1:f;
    for (; isd(c); c=getchar()) x=(x<<3)+(x<<1)+(c^48);x*=f;
}
template<typename T> inline void wt(T x,char c=0){char ch[(sizeof(T)+1)<<1];if (x<0) x=-x,putchar('-');
    int t=-1; do ch[++t]=x%10+'0',x/=10; while(x); do putchar(ch[t]); while(t--); if (c!=0) putchar(c);
}
FILE*out;int n,opt;
char name[1024],fl[2048];
inline int show(){int res=0;
    puts("1:无向图\n2:有向图(a->b)\n3:有向图(a<-b)\n哪种图？\n");
    while (res<1||res>3) read(res);puts("几条边？"); return res;
}
inline void output(int x,int y){
    switch (opt) {
        case 1:
            fprintf(out,"%d--%d;\n",x,y);
            printf("%d--%d\n",x,y);
            break;
        case 2:
            fprintf(out,"%d->%d;\n",x,y);
            printf("%d<-%d\n",x,y);
            break;
        case 3:
            fprintf(out,"%d->%d;\n",y,x);
            printf("%d->%d\n",x,y);
            break;
    }
}
int nxt[maxn<<1],fir[maxn],to[maxn<<1],cnt,bo[maxn];
inline void ins(int x,int y){
    if (opt!=3) nxt[++cnt]=fir[x],fir[x]=cnt,to[cnt]=y;
    if (opt==1||opt==3) nxt[++cnt]=fir[y],fir[y]=cnt,to[cnt]=x;
}
inline void dfs(int now,int fa){
    bo[now]=1;
    for (int i=fir[now]; i; i=nxt[i]){
        if (to[i]!=fa) {
            output(now,to[i]);
            if (!bo[to[i]]) dfs(to[i],now);
        }
        //if (!bo[to[i]]) dfs(to[i],now),output(now,to[i]);
    }
}
int main(){
    puts("文件名？");
    gets(name);strcat(name,".dot");
    opt=show();read(n);out=fopen(name,"wt+");
    fprintf(out,opt==1?"graph example{\n":"digraph example{\nnode[shape=circle]\n");
    for (int x,y,i=1; i<=n; ++i) read(x),read(y),output(x,y);//,ins(x,y);
    //for (int i=1; i<=n; ++i) if (bo[i]==0) dfs(i,i);
    fprintf(out,"}");fclose(out);
    for (int i=strlen(name)-4,g=strlen(name); i<g; ++i)name[i]=0;
    //dot test.dot -T png -o test.png
    sprintf(fl,"dot %s.dot -T png -o %s.png\n",name,name);
    system(fl);sprintf(fl,"start %s.png\n",name);system(fl);
    return 0;
}

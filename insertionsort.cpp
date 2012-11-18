#include<iostream>
#include<stdio.h>
#include<string.h> 

#define REP(i,n) for(int i = 0; i < n ; i++) 
#define take(a) scanf("%d",&a) 
#define take2(a,b) scanf("%d",&a,&b) 
#define write(s,a,b) if (b) printf("%s  %d\n",s,a) 
#define write2(s,a,b,c) if (c) printf("%s  %d %d\n",s,a,b) 
#define NOTJUDGE 0
#define MAXN 1000002
#define MAX  100002
int a[MAX],c[MAXN];
using namespace std;

int main() {
    int testcases,elements;
    take(testcases);
    write("No of Testcases :",testcases,NOTJUDGE);
    REP(m,testcases) {
        take(elements);
        write2("No of element for testcases",elements,m,NOTJUDGE);
        memset(a,0,sizeof a) ;
        long long ret = 1LL* elements * (elements-1) / 2;
        memset(c,0,sizeof c) ;
        REP(k,elements) take(a[k]);
        REP(n,elements) {
            write2("Nth element is ",a[n],n,NOTJUDGE);
            for ( int i = a[n];i > 0; i -= i & -i) ret -= c[i];
            for ( int j = a[n] ;j<MAXN;j += j & -j) c[j]++;
        }
        write("Number of Inversions :",ret,NOTJUDGE);
        cout<<ret<<endl;
    } 

    return 0;   
}

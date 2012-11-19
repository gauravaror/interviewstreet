#include<stdio.h>
#include<string.h>
#define MAX 102
#define REP(i,n) for (int i = 0; i < n; i++)

using namespace std;

char * reduce(int,char *);

int main() {
    int testcases;
    scanf("%d",testcases);
    while(testcases--) {
        char * str = char[MAX];
        scanf("%s",str);
        int len = strlen(str);
        char* ch =  reduce(str,len);
        printf("%s",ch);
    }

}

char * reduce(int,char *) {
    
}

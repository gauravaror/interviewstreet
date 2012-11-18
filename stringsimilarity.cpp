#include<iostream>
#include<stdio.h>

#define REP(i,n) for(int i = 0; i < n ; i++) 
#define take(a) scanf("%d",&a) 
#define take2(a,b) scanf("%d",&a,&b) 
#define write(s,a,b) if (b) printf("%s %d\n",s,a) 
#define write2(s,a,b,c) if (c) printf("%s  %d %d\n",s,a,b) 
//#define NOTJUDGE 0
#define NOTJUDGE1 0

using namespace std;

int similarity_score(string,string);
int main() {
    int testcases,elements;
    take(testcases);
    write("No of Testcases :",testcases,NOTJUDGE1);
    REP(m,testcases) {
        string str;
        cin>>str;
        long long similarity_final = 0;
        REP(j,str.length()) {
            similarity_final += similarity_score(str,str.substr(j,str.length()));
            #ifdef NOTJUDGE
            cout<<"Intial similarity score :"<<similarity_final<<endl;
            #endif
        }
    cout<<similarity_final<<endl;
    } 

    return 0;   
}

int similarity_score1(string org,string simi) {

int count = 0;
string org_f1 = org.substr(0,org.length()/2);
string org_s1;
string simi_s1;
    org_s1 = org.substr(((org.length()/2)),org.length());
string simi_f1 = simi.substr(0,org.length()/2);
     simi_s1 = simi.substr(((org.length()/2)),org.length());

    #ifdef NOTJUDGE
    cout<<"org_f1  :"<<org_f1<<"  org_s1   :"<<org_s1<<endl;
   cout<<"simi_f1 :"<<simi_f1<<" simi_s1   :"<<simi_s1<<endl;
    #endif
    if ( org_f1.compare(simi_f1) == 0 ) {
        count += org_f1.length();
        if (org_s1.compare(simi_s1) == 0) {
            count += org_s1.length();
            return count;
        }
        else {
            if(simi_s1.length() == 1 || org_s1.length() == 1)
                return count;
            return count + similarity_score(org_s1,simi_s1);
        }
    }
    if(simi_f1.length() == 1 || org_f1.length() == 1)
          return count;
    return count + similarity_score(org_f1,simi_f1);
}

int similarity_score(string org,string simi) {
    #ifdef NOTJUDGE
    cout<<" string org  "<<org<<"  simi "<<simi<<endl;
    #endif
    if ( org.compare(simi) == 0 ) {
        return org.length();
    }
    const char * o1 = org.c_str();
    const char * s1 = simi.c_str();
    int similarity = 0; 
    int i = 0;
    while (s1[i] == o1[i] && s1[i] != '\0') {
    #ifdef NOTJUDGE
        cout<<"o1 "<<o1[i] <<" s1 "<<s1[i]<<endl;
    #endif
        i++;
    }
    return i;
}

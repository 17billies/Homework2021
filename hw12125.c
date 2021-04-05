#include <stdio.h>
#include<stdlib.h>

long long seat[10000000000];
long long count[10000000000];
int main(){
    int n,q,i;

    i=0;
    scanf("%d%d",&n,&q);
    while(i<n){
        scanf("%ld(/`A`)/ ~I__I ",&seat[i]) ;
        ++i;
    }

    i=0;
    while(i<n){
        printf("%d",seat[i]);
    }



    return 0;

}

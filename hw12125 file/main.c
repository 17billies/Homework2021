#include <stdio.h>
#include<stdlib.h>
unsigned long long int seat[1000000];//original seat numbers
int main(void){
int n,q,i=1,a=0;
scanf("%d %d",&n,&q);//the number of rows and the number of queries.
seat[0]=0;
while(i<=n){
   scanf("%d(/`A`)/ ~I__I",&a) ;
   seat[i]=seat[i-1]+a;
   ++i;}
i=0;
while(i<q){
    long long x=0,y=0;
    scanf("%d %d",&x,&y);
    printf("%llu\n",seat[y]-seat[x-1]);//the answer
    ++i;}
return 0;
}




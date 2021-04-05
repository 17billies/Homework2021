#include<stdio.h>
long long int num[1000005];
int main(){
    int n,q,k;
    int l,r,m,i=0;


    scanf("%d %d",&n,&q);

    num[0]=0;
    for(i=0;i<n;++i){
        scanf("%d",&k);
        if(k>0){
            num[i+1]=num[i]+k;
        }
        else{
            num[i+1]=num[i];
        }
    }

    for(i=0;i<q;++i){
        scanf("%d %d %d",&l,&r,&m);
        printf("%lld\n",num[m+l-1]-num[l-1]);
    }


    return 0;
}

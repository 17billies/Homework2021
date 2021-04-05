#include<stdio.h>
#define max 2000000
unsigned long long int test[max];
unsigned long long int ans[max];
int main(){

int c=0,t,z,a,b,i=0,k;

scanf("%d",&z);
for(c=0;c<z;++c){
    scanf("%llu %llu",&test[0],&test[1]);
    k=test[0];
    ans[2]=0;
    for(i=0;i<2;++i){
        a=test[i];//record the number for the last bit checking
        t=0;
        ans[i]=0;

        while(test[i]/10!=0){
            if(test[i]>=1){
                ans[2]+=1*(i==0)*(test[i]%10==1);
                ans[i]+=((test[i]/10)+1)*pow(10,t);
                ++t;
            }
            else{
                ans[i]+=(test[i]/10)*pow(10,t);
                ++t;
            }
            test[i]=test[i]/10;
        }

        if(test[i]%10==1){
            ans[2]+=1*(i==0);
            ans[i]+=a-pow(10,t)+1;
        }
        else{
            ans[i]+=pow(10,t);
        }
    }


    printf("%llu\n",ans[1]-ans[0]+ans[2]);
}

return 0;
}


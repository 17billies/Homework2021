#include<stdio.h>
int main(){
    int t,i=0;
    int temp, num[3];

    scanf("%d",&t);
    for(i=0;i<t;++i){
    scanf("%d %d %d",&num[0],&num[1],&num[2]);

    for(int i=0;i<2;++i){
        if(num[i]>num[i+1]){
            temp=num[i];
            num[i]=num[i+1];
            num[i+1]=temp;
        }

    }


    if(num[2]-(num[0]+num[1])>=0){
        printf("%d\n",num[1]+num[0]);
    }
    else{
        printf("%d\n",(num[0]+num[1]+num[2])/2);
    }
    }




return 0;
}

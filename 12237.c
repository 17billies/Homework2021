#include<stdio.h>
int main(){
    int bi[100];
    float x;
    int i=0,j,flag=0;
    while((scanf("%f",&x))!=EOF){//the value of the float:28.759
        flag=0;
        //since EOF,clean the record
        if(x<0){
            x=x*(-1);
            flag=1;
        }
        //record if x<0

        void* ptr=(void*)&x;      //the address of the float:61fe10
        int out=*((int*)ptr);     //the value of the int which converted from the float:1105597039

        if(flag==1){
            bi[31]=1;
            j=31;
        }
        else{
            j=32;
        }
        //if x<0 the first bit would be:1
        for(i=0;i!=j;++i){
            bi[i]=out%2;
            out=out/2;
        }

        for(i=31;i>=0;--i){
            printf("%d",bi[i]);
        }
        //switch the order up side down
        printf("\n");


    }
    return 0;
}

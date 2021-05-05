#include <stdio.h>
#include <stdlib.h>
#define MAX 32



int main(void){ 
    int t1, b1, two1[MAX], i1=0, c=0; //十進位數
    int t2, b2, two2[MAX], i2=0;
    int carry=0 ,count=0;
    scanf("%d %d",&t1,&t2);


    while(t1>0){
        b1=t1%2;
        t1=t1/2;
        two1[i1]=b1;
        i1++;//i+1是二進位的位數
    }//十進位轉換成二進位(倒的)
    while(t2>0){
        b2=t2%2;
        t2=t2/2;
        two2[i2]=b2;
        i2++;
    }//十進位轉換成二進位(倒的)
    if (i1>=i2){
        int sum[i1+1];
        for(int n=0;n<=i1;n++){
            sum[n]=((two1[n]^two2[n])^carry); //^=XOR(1^1=0)
            carry=(two1[n]&two2[n])|(two1[n]&carry)|(two2[n]&carry);
            if(carry==1){
                count+=1;}
            else{
                count+=0;
            }
        }
        for(int c=i1;c>0;c--){
        printf("%d", sum[c]);
        }
    printf("\n%d",count);   
    }
    else{
        int sum[i2+1];//宣告加法的位數
        for(int n=0;n<=i2;n++){
            sum[n]=((two1[n]^two2[n])^carry);
            carry=(two1[n]&two2[n])|(two1[n]&carry)|(two2[n]&carry);
            if(carry==1){
                count+=1;
            }
            else{
                count+=0;
            }
        }
    for(int c=i2;c>0;c--){
        printf("%d", sum[c]);}
    }
    return 0;
}



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int a,n=0,l=0,r=0;
    char str[100000];
    scanf("%d",&a);
    scanf("%s",str);

    while(n<strlen(str)){//to know how many left and how many right
        if(str[n]=='L'){
            l++;
            n++;
        }
        else{
            r++;
            n++;
        }
    }

    if((l!=0)&&(r!=0)){
        printf("%d\n",r+l+1);
    }
    else{
        printf("%d\n",l+r);
    }


    return 0;
}

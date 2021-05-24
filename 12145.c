#include<stdio.h>
int main(){
    int n,i=0,temp;
    char b;
    char str[27]={0};

    scanf("%d",&n);
    scanf("%c",&b);
    if(n==1|n>26){
        printf("I'm the god of Knuckles!\n");
    }
    else{
        for(i=0;i<n;++i){
            scanf("%c",&str[i]);
            temp=i-1;
            while(temp>0){
                if(str[i]==str[temp]){
                    printf("I'm the god of Knuckles!\n");
                    temp=27;
                    break;
                }
                --temp;
            }
            if(temp==27){
                break;
            }

    }
    }
    if(i==n){
        printf("Different makes perfect\n");
    }

    return 0;
}

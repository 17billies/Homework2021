#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n%2==0){
        printf("%d 4\n",n+4);//a-b=n a and b should be composite number
    }
    else{
        printf("%d 9\n",n+9);//a-b=n a and b should be composite number
    }
    return 0;
}

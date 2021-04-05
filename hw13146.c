#include <stdio.h>
#include<stdlib.h>

int main(){
    double x,y;
    long long z,i=0,count=0;
    long long b,t=1;

    scanf("%lf %lf %d",&x,&y,&z);


    while(i<z){
        t*=10;  //to confirm how many decimals and save it in variable t
        ++i;
    }

    i=0;
    b=x*y*t/1;//to move the confirm decimals in front of the decimal point and delete other numbers behind

    while(b!=0){
        b=b%t/10;
        count++;//to know how many digits are there in the decimal part
    }

    b=x*y*t/1;//switch back the number

    if(b%t<0){//for delete the minus symbol in the decimal part
        printf("%ld.",b/t);
    while(z>count){//add '0' when the count is smaller than t
    printf("0");
    --z;
    }
    printf("%d",(b%t)*(-1));

    }
    else{
        printf("%ld.",b/t);
        while(z>count){
            printf("0");
            --z;
        }

    printf("%d",(b%t));


    }


    return 0;
}

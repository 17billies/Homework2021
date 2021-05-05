#include "function.h"
int t=0;
int BS(int input[200],int a, int n);
int BS(int input[200],int a, int n){

    int mid =(t+n)/2;     //0 1 2 3 4 5 6 7 8 9
    if(input[mid]<a){
        t=mid+1;
        BS(input,a,n);
    }
    else if(input[mid]>a){
        t=0;
        BS(input,a,mid-1);
    }
    else if(input[mid]==a){
        t=0;
        return mid;
    }
}

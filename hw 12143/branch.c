#include "12143.h"

int BS(int *input,int a, int n);
int BS(int *input,int a, int n){
    int R,L,answer,mid;
    L=0;
    R=n;

    while(L<R){
        int mid =(R+L)/2;
        if(input[mid]>a){
            R=mid;
        }
        else if(input[mid]<a){
            L=mid;
        }
        else{
            answer=mid;
            break;
        }
    }
    return answer;
}

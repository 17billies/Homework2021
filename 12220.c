#include<stdio.h>
long long int binary_search(long long int f,long long int* num, int n);//* represent a pointer to a variable whose datatype is integer,we cannot pass an array by value to a function in C
long long int front[1000006],back[1000006];
int main(){
    int n,k,q;//n integers(10^6),left shift k slots,q testcase for f(10^6)
    int i=0;
    int t,w;
    long long int f;//10^15
    scanf("%d %d %d",&n,&k,&q);
    for(i=0;i<k;++i){//k => directly separate the part that should be shifted
        scanf("%lld",&front[i]);
    }
    for(i=0;i<n-k;++i){
        scanf("%lld",&back[i]);
        //printf("back[%d]=%d\n",i,back[i]);
    }
    for(i=0;i<q;++i){
        scanf("%lld",&f);
        t=binary_search(f,back,n-k-1);
        w=binary_search(f,front,k-1);
        if(t==-1&&w==-1){//the f is too big for two parts
            printf("gan ni nya sai bau\n");
        }
        else if(w==-1 && t!=-1){//the f is too big for the front part
            printf("%d\n",t+1);//*1 the array start from 0,add it back when printing answer
        }
        else{
             if(back[t]-k<=front[w]-k){
                printf("%d\n",t+1);//*1
             }
             else{
                printf("%d\n",(n-k)+w+1);//*1 after shifting the index of the back part stats from n-k+1
             }
        }
    }
    return 0;
}

long long int binary_search(long long int f,long long int* num, int n){
    long long int mid=-1,L,R;//the initial value is set to avoid being same as the average(line 47)
    L=0;
    R=n;
    if(f>num[n]){//because a should >=f
        // printf("%d\n",num[n]);
        return -1;
    }
    while(mid!=(L+R)/2){//when the average is same as the value from the last round in mid, the loop should end
        mid=(L+R)/2;
        if(num[mid]>f){
            R=mid;
        }
        else if(num[mid]<f){
            L=mid;
        }
        else{
            return mid;
        }
    }
    if(mid==(L+R)/2){
        if(f<num[mid]){
            return mid;
        }
        if(f>=num[mid]){//because a should >=f
            return mid+1;
        }
    }
}

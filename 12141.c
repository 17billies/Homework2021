#include <stdio.h>
int cmp(char *a,char *b);

int cmp(char *a,char *b){
    return strlen(a)-strlen(b);
}
int main(){
    char a[1005][1005];
    int n,flag=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s",a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n-1;++i){
       if(strstr(a[i+1],a[i])==NULL){//strstr() is to find if a[i] is a substring of a[i+1];
        printf("NO\n");
        break;
       }
       if(i==n-2)flag=1;
    }
    if(flag==1){
        printf("YES\n");
        for(int i=0;i<n;++i){
            printf("%s\n",a[i]);
        }
    }
    return 0;
}

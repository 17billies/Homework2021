#include <stdio.h>
#include<math.h>
double distance[1005][1005];
int visited[1005];
int one=0,count=0;
int dfs(int now,int pa,int n,int r);
int main(){
    int n,r,i=0,j=0;
    int x[1005],y[1005];
    scanf("%d %d",&n,&r);
    for(i=0;i<n;++i){
        scanf("%d %d",&x[i],&y[i]);
    }
    //calculate the distance of each point and point
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            distance[i][j]=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
        }
    }
    for(i=0;i<n;++i){
        if(visited[i]==0){
            if(dfs(i,-1,n,r)==1) count++;
            else one++;
        }
    }
    printf("%d %d\n",one,count);
    return 0;
}

int dfs(int now,int pa,int n,int r){
    int i=0;
    int cnt=0;
    visited[now]=1;
    for(i=0;i<n;++i){
        if(i==now)continue;
        if(i==pa)continue;
        if(visited[i]==1)continue;
        if(distance[i][now]<=r){
            dfs(i,now,n,r);
            cnt++;
        }
    }
    if(cnt==0)return 0;//no other coordinate to connect
    else return 1;

}








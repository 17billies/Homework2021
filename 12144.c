#include <stdio.h>
int k;//the amount of monster
typedef struct{
    int hp;
    int attack;
    int x;
    int y;
}Obj;

typedef struct{
    Obj m[500];
}Mon;

int dfs(int x,int y,Obj hero,Mon mon);
int encounter(Obj hero,Mon monster);
int can_go(int x,int y);
int battle(Obj* hero,Mon* monster);//pointer for recording the hp return back to dfs
int cox[]={1,0};//the step
int coy[]={0,1};
int visited[1000][1000]={0};

int dfs(int x,int y,Obj hero,Mon mon){
    hero.x=x;//first save the current coordinate of ash
    hero.y=y;
    if(encounter(hero,mon)){//if ash approach mons,then battle
        if(!battle(&hero,&mon)){
            return 0;
        }
    }
    if(x==5 && y==5)return 1;//has to be after battle to determine 5*5mons is dead too
    for(int i=0;i<2;i++){
        if(can_go(x+cox[i],y+coy[i])){//test if it is over 5*5
            visited[x+cox[i]][y+coy[i]]=1;
            if(dfs(x+cox[i],y+coy[i],hero,mon)){
                return 1;
            }
            visited[x+cox[i]][y+coy[i]]=0;
        }
    }
    return 0;
}
int encounter(Obj hero,Mon monster){
    int flag=0;
    for(int i=0;i<k;++i){
        if(hero.x==monster.m[i].x && hero.y==monster.m[i].y){
            return 1;
            flag=1;
            break;
        }
    }
    if(flag==0)return 0;
}


int can_go(int x,int y){
    if(x>5 | y>5)return 0;
    else return 1;
}


int battle(Obj* hero,Mon* mon){
    Obj h=*(Obj*)hero;
    Mon m=*(Mon*)mon;
    for(int i=0;i<k;++i){
        if(m.m[i].x==h.x &&m.m[i].y==h.y){
            int j=0;
            while(h.hp>0 && m.m[i].hp>0){
                if(j%2==0){//start from ash
                    m.m[i].hp-=h.attack;
                    if(m.m[i].hp<=0){
                        return 1;
                        break;
                    }
                }
                else{
                    h.hp-=m.m[i].attack;
                    if(h.hp<=0){
                        return 0;
                        break;
                    }
                }
                ++j;
            }
        }
    }
}

int main(){
    Obj ash;
    Mon monster;
    scanf("%d %d %d",&ash.hp,&ash.attack,&k);
    for(int i=0;i<k;++i){
        scanf("%d %d %d %d",&monster.m[i].hp,&monster.m[i].attack,&monster.m[i].x,&monster.m[i].y);
    }
    if(dfs(1,1,ash,monster))printf("HEIR OF FIRE DESTROYED\n");
    else printf("YOU DIED\n");
    return 0;
}

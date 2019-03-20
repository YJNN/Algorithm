#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <math.h>

using namespace std;

struct sharkInf{
    int x;
    int y;
    int size;
    int eatFish;
    int time;
};

int n;
int map[21][21];
bool visited[21][21];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
queue<sharkInf> q;
vector<sharkInf> v;

bool cmp(sharkInf a, sharkInf b){
    if(a.time<=b.time){
        if(a.time==b.time){
            if(a.x<=b.x){
                if(a.x==b.x){
                    if(a.y<b.y){
                        return true;
                    }
                    return false;
                }
                
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int main(){
    scanf("%d", &n);
    sharkInf shark;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j]==9){
                map[i][j]=0;
                shark = {i,j,2,0,0};
            }
        }
    }
    
    int ans=0;
    while(1){
        v.clear();
        memset(visited, false, sizeof(visited));
        visited[shark.x][shark.y]=true;
        q.push(shark);
        
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int sz = q.front().size;
            int eatFishh = q.front().eatFish;
            int time = q.front().time;
            
            q.pop();
            
            for(int i=0; i<4; i++){
                int cx = x+dx[i];
                int cy = y+dy[i];
                
                if(cx<0 || cy<0 || cx>=n || cy>=n)
                    continue;
                if(visited[cx][cy])
                    continue;
                if(map[cx][cy]==0 || map[cx][cy]==sz){
                    visited[cx][cy]=true;
                    q.push({cx,cy,sz,eatFishh,time+1});
                }
                else if(map[cx][cy]<sz){
                    visited[cx][cy]=true;
                    v.push_back({cx,cy,sz,eatFishh+1,time+1});
                }
            }
        }
        
        if(v.size()==0)
            break;
        
        sort(v.begin(), v.end(), cmp);
        
        if(v[0].size==v[0].eatFish){
            v[0].size++;
            v[0].eatFish=0;
        }
        
        map[v[0].x][v[0].y]=0;
        ans += v[0].time;
        
        shark = {v[0].x, v[0].y, v[0].size, v[0].eatFish, 0};
    }
    printf("%d\n",ans);
    
    return 0;
}

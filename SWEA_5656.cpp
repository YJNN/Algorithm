#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n,w,h,t;
int map[16][13];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int minNum=987654321;

void setMap(){
    
    for(int i=0; i<w; i++){
        for(int j=h-2; j>=0; j--){
            int x = j;
            int y = i;
            
            if(map[x][y]==0)
                continue;
            while(1){
                if(x+1 > h-1)
                    break;
                if(map[x+1][y]==0){
                    map[x+1][y]=map[x][y];
                    map[x][y]=0;
                    x++;
                }else{
                    break;
                }
            }
            
            
        }
    }
    
    
    
}



void bomb(int x, int y){
   // if(map[x][y]==0)
     //   return;
    
    int wallNum = map[x][y];
    map[x][y]=0;
    
    for(int j=1; j<wallNum; j++){
        for(int i=0; i<4; i++){
            int cx = x+dx[i]*j;
            int cy = y+dy[i]*j;
            
            if(cx>=0 && cy>=0 && cx<h && cy<w && map[cx][cy]!=0)
                bomb(cx, cy);
        }
    }
}

void dfs(int cnt){
    if(cnt==n){
        int ret=0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j]!=0)
                    ret++;
            }
        }
        if(minNum>ret)
            minNum=ret;
        return;
    }
    int tmpMap[16][13];
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            tmpMap[i][j]=map[i][j];
        }
    }
    
    for(int i=0; i<w; i++){
        int x=0;
        int y=i;
        
        while(x>=0 && y>=0 && x<h && y<w && map[x][y]==0){
            ++x;
        }
        bomb(x,y);
        setMap();
        dfs(cnt+1);
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                map[i][j]=tmpMap[i][j];
            }
        }
        
    }
    
}

int main(){
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        minNum=987654321;
        scanf("%d %d %d", &n, &w, &h);
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                scanf("%d",&map[i][j]);
            }
        }
        dfs(0);
        printf("#%d %d\n",i+1,minNum);
    }
    return 0;
}

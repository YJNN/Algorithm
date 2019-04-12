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

struct Cell{
    int state=-1;
    int originLife;
    int activeTime;
    int inActiveTime;
};

int n,m,k,t;
int map[351][351];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
Cell cellInf[351][351];

int main(){
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        Cell cell;
        cell.state=-1;
        cell.originLife=0;
        cell.activeTime=0;
        cell.inActiveTime=0;
        for(int i=0; i<350; i++){
            for(int j=0; j<350; j++){
                cellInf[i][j]=cell;
            }
        }
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                scanf("%d", &map[i][j]);
                if(map[i][j]>0){
                    Cell newCell;
                    newCell.state=0;
                    newCell.originLife=map[i][j];
                    newCell.activeTime=map[i][j];
                    newCell.inActiveTime=map[i][j];
                    cellInf[i+150][j+150]=newCell;
                }
            }
        }
        
        int time=0;
        while(k>time){
            queue<pair<int, int>> q;
            
            for(int i=0; i<350; i++){
                for(int j=0; j<350; j++){
                    if(cellInf[i][j].state==0){
                        if(cellInf[i][j].inActiveTime>0){
                            cellInf[i][j].inActiveTime--;
                        }
                        if(cellInf[i][j].inActiveTime==0){
                            cellInf[i][j].state=1;
                        }
                    }else if(cellInf[i][j].state==1){
                        if(cellInf[i][j].activeTime>0){
                            cellInf[i][j].activeTime--;
                            q.push({i,j});
                        }
                        if(cellInf[i][j].activeTime==0)
                            cellInf[i][j].state=2;
                        
                    }
                }
            }
            
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int cx = x+dx[i];
                    int cy = y+dy[i];
                    
                    if(cx<0 || cy<0 || cx>=350 || cy>=350)
                        continue;
                    if(cellInf[cx][cy].state==-1){
                        cellInf[cx][cy].state=0;
                        cellInf[cx][cy].originLife=cellInf[x][y].originLife;
                        cellInf[cx][cy].activeTime=cellInf[x][y].originLife;
                        cellInf[cx][cy].inActiveTime=cellInf[x][y].originLife;
                    }
                    else if(cellInf[cx][cy].state==0 && cellInf[cx][cy].inActiveTime==cellInf[cx][cy].originLife && cellInf[cx][cy].activeTime==cellInf[cx][cy].originLife){
                        if(cellInf[cx][cy].originLife < cellInf[x][y].originLife){
                            cellInf[cx][cy].originLife = cellInf[x][y].originLife;
                            cellInf[cx][cy].activeTime = cellInf[x][y].originLife;
                            cellInf[cx][cy].inActiveTime=cellInf[x][y].originLife;
                        }
                    }
                }
            }
            ++time;
        }
        int ans=0;
        for(int i=0; i<350; i++){
            for(int j=0; j<350; j++){
                if(cellInf[i][j].state==0 || cellInf[i][j].state==1)
                    ++ans;
            }
        }
        printf("#%d %d\n",i+1,ans);
    }
    return 0;
}

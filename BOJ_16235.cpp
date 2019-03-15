#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,k;
int nutrition[11][11];
int land[11][11];
vector<int> treeMap[11][11];
int dx[] = {-1,-1,-1,1,1,1,0,0};
int dy[] = {-1,0,1,-1,0,1,-1,1};

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &nutrition[i][j]);
        }
    }
    for(int i=0; i<m; i++){
        int x,y,z;
        scanf("%d %d %d", &x, &y, &z);
        treeMap[x][y].push_back(z);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            land[i][j]=5;
        }
    }
    int year=0;
    
    while(1){
        if(year==k){
            break;
        }
        
        //봄여름
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(treeMap[i][j].size()!=0){
                    int dieTree=0;
                    vector<int> tmp;
                    sort(treeMap[i][j].begin(), treeMap[i][j].end());
                    for(int l=0; l<treeMap[i][j].size(); l++){
                        if(land[i][j]<treeMap[i][j][l]){
                            dieTree = dieTree + (treeMap[i][j][l]/2);
                        }else{
                            land[i][j] = land[i][j]-treeMap[i][j][l];
                            tmp.push_back(treeMap[i][j][l]+1);
                        }
                    }
                    treeMap[i][j].clear();
                    for(int l=0; l<tmp.size(); l++){
                        treeMap[i][j].push_back(tmp[l]);
                    }
                    
                    land[i][j] = land[i][j]+dieTree;
                    
                }
            }
        }
        
        //가을
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(treeMap[i][j].size()!=0){
                        for(int v : treeMap[i][j]){
                            if(v%5==0){
                                for(int l=0; l<8; l++){
                                    int cx = i+dx[l];
                                    int cy = j+dy[l];
                                    
                                    if(cx<0 || cy<0 || cx>n || cy>n)
                                        continue;
                                    treeMap[cx][cy].push_back(1);
                                }
                            }
                            
                        }
                }
            }
        }
        
        //겨울
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                land[i][j] += nutrition[i][j];
            }
        }
        ++year;
    }
    
    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ans += treeMap[i][j].size();
        }
    }
    
    printf("%d\n", ans);

    return 0;
}

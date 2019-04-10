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

int n,k,t;
string s;
int cutNum;

bool desc(int a, int b){
    return a>b;
}

int toDecimal(char c,int idx){
    int index = (cutNum-idx);
    int ret=1;
    if(c=='A'){
        ret = 10;
    }else if(c=='B'){
        ret = 11;
    }else if(c=='C'){
        ret = 12;
    }else if(c=='D'){
        ret = 13;
    }else if(c=='E'){
        ret = 14;
    }else if(c=='F'){
        ret = 15;
    }else{
        ret = (c-'0');
    }
    
    if(index==1)
        return ret;
    else{
        for(int i=0; i<index-1; i++){
            ret = ret*16;
        }
    }
    return ret;
}

int main() {
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        scanf("%d %d", &n, &k);
        cin >> s;
        
        cutNum = n/4;
        int groupNum = n/cutNum;
        vector<int> retNum;
        for(int i=0; i<cutNum; i++){
            vector<int> cuttenNum(groupNum);
            for(int j=0; j<groupNum; j++){
                for(int k=0; k<cutNum; k++){
                    cuttenNum[j] += toDecimal(s[cutNum*j+k],k);
                }
            }
            for(int j=0; j<groupNum; j++){
                retNum.push_back(cuttenNum[j]);
            }
            string tmp = s;
            s = tmp.substr(1)+tmp[0];
        }
        sort(retNum.begin(), retNum.end(), desc);
        retNum.erase(unique(retNum.begin(), retNum.end()),retNum.end());
        printf("#%d %d\n", i+1,retNum[k-1]);
    }
    return 0;
}

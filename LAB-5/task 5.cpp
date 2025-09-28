#include<iostream>
using namespace std;
const int N=9;

bool valid(int g[N][N],int r,int c,int num){
    for(int i=0;i<N;i++){
        if(g[r][i]==num)
            return false;
        if(g[i][c]==num)
            return false;
    }
    int sr=r-r%3;
    int sc=c-c%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(g[sr+i][sc+j]==num)
                return false;
        }
    }
    return true;
}

bool solve(int g[N][N]){
    for(int r=0;r<N;r++){
        for(int c=0;c<N;c++){
            if(g[r][c]==0){
                for(int num=1;num<=9;num++){
                    if(valid(g,r,c,num)){
                        g[r][c]=num;
                        if(solve(g))
                            return true;
                        g[r][c]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void print(int g[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int g[N][N]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    if(solve(g))
        print(g);
    else
        cout<<"No solution";
}

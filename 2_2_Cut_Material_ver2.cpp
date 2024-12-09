#include<bits/stdc++.h>
using namespace std;

int n, H, W;
int h[15], w[15];
int x[15], y[15], z[15];
bool mark[15][15];
int flag = 0;

void domark(int vx, int vy, int vz, int k, bool value){
    int wide = w[k], hight = h[k];
    if(vz==1){
        wide = h[k];
        hight = w[k];
    }
    for(int i=vx;i<=vx+wide-1;i++)
        for(int j=vy;j<=vy+hight-1;j++)
            mark[i][j]=value;
}
bool check(int vx, int vy, int vz, int k){
    int wide = w[k], hight = h[k];
    if(vz==1){
        wide = h[k];
        hight = w[k];
    }
    for(int i=vx;i<=vx+wide-1;i++)
        for(int j=vy;j<=vy+hight-1;j++)
            if(mark[i][j]) return false;
    return true;
}
void backtrack(int k){
    int wide = w[k], hight = h[k];
    for(int vz=0;vz<=1;vz++){
        if(vz==1){
            wide = h[k];
            hight = w[k];
        }
        for(int vx=0; vx<=W-wide; vx++)
            for(int vy=0; vy<=H-hight; vy++)
                if(check(vx, vy, vz, k)){
                    x[k] = vx;
                    y[k] = vy;
                    z[k] = vz;
                    domark(vx, vy, vz, k, true);
                    if(k==n) flag=1;
                        else if(flag!=1) backtrack(k+1);
                    }
                    domark(vx, vy, vz, k, false);
                }
    }
}
int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> H >> W; cin.ignore();
    cin >> n; cin.ignore();

    for(int i=1;i<=n;i++){
        cin >> h[i] >> w[i]; cin.ignore();
    }

    for(int i=0;i<=W-1;i++)
        for(int j=0;j<=H-1;j++)
            mark[i][j]=false;
    backtrack(1);
    cout << flag;
}

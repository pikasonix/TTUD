/* Cut Material: kiểm tra từ hcn H x W có cắt thành n hcn hi x wi */

#include<bits/stdc++.h>
using namespace std;

int n, H, W;            // n: số hcn nhỏ; H, W: kích thước hcn to
int h[15], w[15];       // kích thước hcn nhỏ
int x[15], y[15], z[15];// x[], y[]: toạ độ góc trái trên hcn nhỏ; z[]: trạng thái xoay
bool visited[15][15];   // đánh dấu các ô đã dùng trong hcn lớn
int flag = 0;           // kết quả
// vx,xy,vz,k: toạ độ, xoay (0-không xoay, 1-xoay 90 độ), chỉ số của hcn nhỏ 

/* mark: mark or un-mark các ô theo value */
void mark(int vx, int vy, int vz, int k, bool value){
    if(vz==0)   int width = w[k], height = h[k];
        else    int width = h[k], height = w[k];

    for(int i=vx; i<=vx+width-1; i++)
        for(int j=vy; j<=vy+height-1; j++)
            visited[i][j]=value;
}

/* check: check hcn nhỏ có để vừa vào vx,vy không*/
bool check(int vx, int vy, int vz, int k){
    if(vz==0)   int width = w[k], height = h[k];
        else    int width = h[k], height = w[k];

    for(int i=vx;i<=vx+width-1;i++)
        for(int j=vy;j<=vy+height-1;j++)
            if(visited[i][j]) return false;

    return true;
}

void TRY(int k){
    for(int vz=0; vz<=1; vz++){
        if(vz==0)   int width = w[k], height = h[k];
            else    int width = h[k], height = w[k];

        for(int vx=0; vx<=W-width; vx++)
            for(int vy=0; vy<=H-height; vy++)
                if(check(vx, vy, vz, k)){
                    x[k] = vx;                      // gán thử
                    y[k] = vy;
                    z[k] = vz;
                    mark(vx, vy, vz, k, true);      // update
                    if(k==n) flag=1;                // hoàn thành
                        else if(flag!=1) TRY(k+1);
                    mark(vx, vy, vz, k, false);     // remove update
                }
    }
}

void input(){
	ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> H >> W; 
    cin >> n; 
    for(int i=1; i<=n; i++) cin >> h[i] >> w[i]; 
}

int main(){
	input();
    TRY(1);
    cout << flag;
}

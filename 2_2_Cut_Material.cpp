#include <iostream>

using namespace std;

int H, W, N;
int x[15], y[15], o[15];
int mark[15][15] = {0};
int result = 0;

void doMark(int vx, int vy, int vo, int i, int m){
    int wi = x[i], hi = y[i];
    if (vo == 1){
        wi = y[i];
        hi = x[i];
    }
    for (int j = vx; j < vx + hi; j++)
        for (int k = vy; k < vy + wi; k++)
            mark[j][k] = m;
}

bool Check(int vx, int vy, int vo, int i){
    int wi = x[i], hi = y[i];
    if (vo == 1){
        wi = y[i];
        hi = x[i];
    }
    if (vx + hi > H || vy + wi > W) return false;
    for (int j = vx; j < vx + hi; j++)
        for (int k = vy; k < vy + wi; k++)
            if (mark[j][k]) return false;
    return true;
}

void Try(int i){
    for (int vo = 0; vo <= 1; vo++){
        for (int vx = 0; vx <= H; vx++)
            for (int vy = 0; vy <= W; vy++)
                if (Check(vx, vy, vo, i)){
                    doMark(vx, vy, vo, i, 1);
                    if (i == N){
                        result = 1;
                        return;
                    }
                    Try(i + 1);
                    doMark(vx, vy, vo, i, 0);
                }
    }
}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> H >> W >> N;
    for (int i = 1; i <= N; i++)cin >> x[i] >> y[i];
    Try(1);
    cout << result;
    return 0;
}

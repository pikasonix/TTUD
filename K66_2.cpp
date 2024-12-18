//là bài nhị phân
#include<bits/stdc++.h>
using namespace std;
int n;
int a[30];
int S;
int res;
int load;
int visited[30];

void TRY(int k){
	for (int i=0;i<2;i++){
		visited[k]=i;
		load += a[k]*visited[k];
		if (k==n-1) {
            if(load >= S) {res++;}
		} else TRY(k+1);
        load -= a[k]*visited[k];
	}
}
int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> S;
    TRY(0);
    cout << res;
}

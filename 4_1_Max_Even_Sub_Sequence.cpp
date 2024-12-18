/* Max Even SubSequence: Cho dãy a. 
Tính tổng lớn nhất của dãy con liên tiếp sao cho tổng là số chẵn (lẻ) */

#include<bits/stdc++.h>
using namespace std;

int n;
long long a[1000007];
long long S0[1000007]; 	// Tổng chẵn lớn nhất dãy con kết thúc tại a[i] 
long long S1[1000007]; 	// Tổng lẻ lớn nhất dãy con kết thúc tại a[i]
bool B0[1000007];		// B0[i] = True -> S0[i] tồn tại
bool B1[1000007];       // B1[i] = True -> S1[i] tồn tại

void solve(){
	// Xét tại a[1]
    if(a[1]%2==0){
        S0[1] = a[1]; B0[1] = true; B1[1] = false;
    } else { 
		S1[1] = a[1]; B1[1] = true; B0[1] = false;
    }
    
    
    for(int i = 2; i <= n; i++){
        if(a[i]%2==0){ 
        // Xét TH a[i] là số chẵn
            if(B0[i-1]){ 
			// S[i-1] là chẵn -> S[i] là chẵn
                if(S0[i-1]>0) S0[i] = S0[i-1]+a[i]; else S0[i] = a[i]; 
                B0[i] = true;
            }else{	
                S0[i] = a[i]; B0[i] = true;
            }
            if(B1[i-1]){
			// S[i-1] là lẻ -> S[i] là lẻ
                S1[i] = S1[i-1]+a[i];
                B1[i] = true;
            }else{
                B1[i] = false;
            }
        }else{ 
        // Xét TH a[i] là số lẻ
            if(B1[i-1]){
            // S[i-1] là lẻ -> S[i] là chẵn
                S0[i] = S1[i-1] + a[i]; 
				B0[i] = true;
            }else{
               B0[i] = false;
            }
            if(B0[i-1]){
            // S[i-1] là chẵn -> S[i] là lẻ
                if(S0[i-1] > 0) S1[i] = S0[i-1] + a[i]; else S1[i] = a[i]; 
                B1[i]= true;
            }else{
                S1[i] = a[i]; 
                B1[i] = true;
            }
        }
    }
    long long result = -1e18;
    // Tổng chẵn lớn nhất
    for(int i=1; i<=n; i++)
        if(B0[i] && result < S0[i]) result = S0[i];
    
    // Tổng lẻ lớn nhất
//    for(int i=1; i<=n; i++)
//        if(B1[i] && result < S1[i]) result = S1[i];
    if(result == -1e18) cout << "NOT_FOUND"; else cout << result;
    
}

void input(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
}

int main(){
        input();
        solve();
    }

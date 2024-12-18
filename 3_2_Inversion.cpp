/* Inversion: Cho dãy a. 
Đưa ra số cặp (i,j) thoả mãn (i<j) mà (a[i] > a[j]) */

#include<bits/stdc++.h>
using namespace std;

int const MOD = 1e9+7;
int n, a[1000007];
int temp[1000007];

// merge: hợp nhất 2 nửa mảng con + đếm inversion giữa các phần tử của 2 nửa
int merge(int l, int m, int r){
    int i = l, j = m+1, k = l, count=0;
    
    while((i <= m) && (j <= r)){
    	// so sánh các phần tử i:[l,m] và j:[m+1,r]
    		// a[i],a[j] đưa thằng nhỏ hơn vào temp[]
    		// a[i] > a[j]  -> tính count = m-i+1 (a[i->m] đều lớn hơn a[j])
        if(a[i] <= a[j]) temp[k++]=a[i++];
        else{
            temp[k++]=a[j++];
            count = (count + (m-i+1)) % MOD;
        }
    }

    // Đưa những thằng còn lại ở [l,m], [m+1,r] vào temp
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    
    // Hợp nhất xong thì trả lại mảng a[]
    for (i=l; i<=r; i++) a[i] = temp[i];
    return count;
}

//mergeSort: Chia mảng thành 2 nửa + đếm inversion của mỗi nửa rồi cộng thêm inversion của merge
int mergeSort(int l, int r){
    int m, count = 0;
    if(r > l){
        m = (r+l)/2;
        count = (count + mergeSort(l,m)) % MOD;
        count = (count + mergeSort(m+1,r)) % MOD;
        count = (count + merge(l,m,r)) % MOD;
    }
    return count;
}

void input(){
	ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
int main(){
    input();
    cout << mergeSort(1,n);
}

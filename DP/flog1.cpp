// flog 問題で理解する動的計画法の実装
#include<iostream>

using namespace std;

// 最大化→chmax, 最小化→chmin
// 入れ替え関数 a:配列の要素, b:比較する値
template<class T> inline void chmax(T& a,T b){if(a < b){ a=b;} return 0;}
template<class T> inline void chmin(T& a, T b){if(a > b){ a=b;} return 0;}

// 
const long long INF = 1LL << 60;
// 入力
int N;
long long h[100010];

// DP テーブル
long long dp[100010];

int main()
{
    int N;
    cin >> N;
    for(int i=0;i<N;i++) cin >> h[N];
    for(int i=0;i<100010;i++) dp[i] = INF;

    // 初期条件
    dp[0] = 0;
    for(int i=0;i<N;i++){
        chmin(dp[i],dp[i-1]+abs(h[i]-h[i-1]));
        if(i>1){ chmin(dp[i],dp[i-2] + abs(h[i]-h[i-2])); }
    }
    cout << dp[N-1] << endl;
}
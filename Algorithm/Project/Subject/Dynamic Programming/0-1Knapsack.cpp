/**********
*DP
*Sofice
*2020/7/10
*************/
#include<bits/stdc++.h>
using namespace std;
#define MAX_N 101
int n, W;
int w[MAX_N], v[MAX_N];//[1...n]
int dp[MAX_N][MAX_N];//������vֵ

int solve(){
    memset(dp, 0, sizeof(dp));
    //�ӵ�1������i����Ʒѡ�����ŵĲ�����j�Ľ�
    for (int i = 1; i<= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i])  dp[i][j] = dp[i - 1][j];//�Ѿ���������
            else           dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);//�ֱ�Ϊ��ѡ��ѡ
        }
    }
    return dp[n][W];
}

int main() {
    memset(w, 0, sizeof(w));
    memset(v, 0, sizeof(v));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
        scanf("%d %d", &w[i], &v[i]);
    scanf("%d", &W);
    printf("%d", solve());
    


    system("pause");
    return 0;
}
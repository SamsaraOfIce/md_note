//���ݷ�
#include<bits/stdc++.h>
using namespace std;

bool isp[40] = {};
int res[20] = { 1 };
int n;
bool vis[20] = {};
int tot = 0;

bool is_prime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)    return false;
    }
    return true;
}

void dfs(int cur) {
    if (cur == n && isp[res[cur - 1] + 1]) {
        //���ÿһ�����
        for (int i = 0; i < n; i++)  printf("%d ", res[i]);
        printf("\n");
        tot++;
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (isp[res[cur - 1] + i] && !vis[i]) {
            res[cur] = i;
            vis[i] = true;
            dfs(cur + 1);
            vis[i] = false;
        }
    }
}


int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n * 2; i++) isp[i] = is_prime(i);
    dfs(1);
    //�������
    //printf("%d\n", tot);
    system("pause");
    return 0;
}
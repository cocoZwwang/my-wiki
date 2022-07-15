#include <algorithm>
using namespace std;
const int MAX_N = 10010;
int n, k;
int w[MAX_N], v[MAX_N];
double y[MAX_N], INF;

//判断是否满足条件
bool C(double x){
    for (int i = 0; i < n; ++i){
        y[i] = v[i] - w[i] * x;
    }
    sort(y, y + n);

    //计算最大的 K 个 yi 的和
    double sum = 0;
    for (int i = 0; i < k; ++i){
        sum += y[n - 1 - i];
    }
    return sum >= 0;
}

void solve(){
    double l = 0, r = INF;
    for (int i = 0; i < 100; ++i){
        double md = (l + r) / 2;
        if (C(md))
            l = md;
        else
            r = md;
    }
    printf("%.2f\n", l);
}
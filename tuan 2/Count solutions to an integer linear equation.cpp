#include <iostream>
using namespace std;

int m, n;
int coef[50];
int dem = 0;
int coef_sum = 0;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> coef[i];
        coef_sum += coef[i];
    }
}

void Try(int k, int RHS) {
    for (int i = 1; i <= RHS/coef[k]; i++) {
        RHS -= coef[k] * i;
        if (k == n) {
            if (RHS == 0) dem++;
            if (RHS < 0) return;
        } else {
            Try(k + 1, RHS);
        }
        RHS += coef[k] * i;
    }
}

int main() {
    input();
    Try(1, m);
    cout << dem;
    return 0;
}

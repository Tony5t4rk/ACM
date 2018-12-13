#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

long long T;
long long N;
long long Left, Right;
long long Cur;
long long Ans;
long long Pos[maxn];
vector<long long> Dis;

int main(int argc, char *argv[]) {
    scanf("%lld", &T);
    for (long long Case = 1; Case <= T; ++Case) {
        if (Case != 1) {
            printf("\n");
        }
        Dis.clear();
        scanf("%lld", &N);
        Pos[1] = 0;
        for (long long i = 2, X; i <= N; ++i) {
            scanf("%lld", &X);
            Pos[i] = Pos[i - 1] + X;
        }
        Left = 0; Right = N + 1;
        Ans = 0; Cur = 0;
        for (int i = 1; i <= N; ++i) {
            if (i & 1) {
                Left++;
                Ans += Cur;
            }
            else {
                Right--;
                long long New = Pos[Right] - Pos[Left];
                Dis.push_back(New);
                Cur += New;
                Ans += Cur;
            }
            if (i != 1) {
                printf(" ");
            }
            printf("%lld", Ans);
        }
    }
    return 0;
}


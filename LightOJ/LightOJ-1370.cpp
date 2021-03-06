#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x) {
	Finish_read = 0;
	x = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -1;
		}
		if (ch == EOF) {
			return;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	x *= f;
	Finish_read = 1;
};

bool IsPrime[maxn];

void Prime() {
	mem(IsPrime, 1);
	IsPrime[1] = 0;
	for (ll i = 2; i < maxn; ++i) {
		if (IsPrime[i]) {
			for (ll j = i * i; j < maxn; j += i) {
				IsPrime[j] = 0;
			}
		}
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	Prime();
	int T;
	read(T);
	for (int Case = 1, n; Case <= T; ++Case) {
		read(n);
		ll ans = 0;
		for (int i = 0, x; i < n; ++i) {
			read(x);
			for (int j = x + 1; j < maxn; ++j) {
				if (IsPrime[j]) {
					ans += j;
					break;
				}
			}
		}
		printf("Case %d: %lld Xukha\n", Case, ans);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
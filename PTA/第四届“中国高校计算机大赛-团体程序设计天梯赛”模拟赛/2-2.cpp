#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  std::cout << std::fixed << std::setprecision(2);

  int n, d; std::cin >> n >> d;
  std::vector<std::pair<double, double>> p(n);
  for (int i = 0; i < n; ++i) std::cin >> p[i].first;
  for (int i = 0; i < n; ++i) std::cin >> p[i].second;
  sort(p.begin(), p.end(), [&](std::pair<int, double> k1, std::pair<int, double> k2) {
    return (k1.second / (double)k1.first) > (k2.second / (double)k2.first);
  });

  double ans = 0;
  for (int i = 0; i < n; ++i) {
    if (p[i].first >= d) {
      ans += p[i].second * (double)((double)d / p[i].first);
      break;
    }
    ans += p[i].second;
    d -= p[i].first;
  }

  std::cout << ans;
  return 0;
}

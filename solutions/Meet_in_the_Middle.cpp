#include <bits/stdc++.h>
#include <unordered_map>
#include <cstdio>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long x;
  scanf("%d %lld", &n, &x);
  vector<long long> v(n/2);
  vector<long long> u(n - n/2);
  for(auto& val : v) scanf("%lld", &val);
  for(auto& val : u) scanf("%lld", &val);
  unordered_map<long long, int, custom_hash> counts;
  long long mask_max_v = 1LL << (n/2);
  long long mask_max_u = 1LL << (n - n/2);
  for(long long mask = 0; mask < mask_max_v; mask++) {
    long long sum = 0;
    for(int i = 0; i < n/2; i++) {
      if(mask & (1LL << i)) sum += v[i];
    }
    counts[sum]++;
  }
  long long ans = 0;
  for(long long mask = 0; mask < mask_max_u; mask++) {
    long long sum = 0;
    for(int i = 0; i < n-(n/2); i++) {
      if(mask & (1LL << i)) sum += u[i];
    }
    if(counts.count(x-sum)) ans += counts[x-sum];
  }
  printf("%lld\n", ans);
}

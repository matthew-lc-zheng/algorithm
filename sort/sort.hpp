#include <bits/stdc++.h>

template<class T>
void merge_sort(std::vector<T> &v) {
  auto s = v.size();
  if (s == 2 && v[0] > v[1])
    std::swap(v[0], v[1]);
  else if (s > 2) {
    auto v1 = std::vector(v.begin(), v.begin() + (s >> 1));
    auto v2 = std::vector(v.begin() + (s >> 1), v.end());
    merge_sort(v1);
    merge_sort(v2);
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
  }
}

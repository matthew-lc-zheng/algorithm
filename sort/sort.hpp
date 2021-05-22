#include <bits/stdc++.h>




void quick_sort(std::vector<int>::iterator l, std::vector<int>::iterator r) {
  if (l < r) {
    srand(time(nullptr));
    std::swap(*(l + rand() % (r - l)), *(r - 1));
    auto p = std::stable_partition(l, r, [r](int i) { return i <= *(r - 1); });
    quick_sort(l, p - 1);
    quick_sort(p, r);
  }
}

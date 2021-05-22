#ifndef SORT_HPP
#define SORT_HPP
#include <bits/stdc++.h>

///
/// \brief merge_sort
/// \param l
/// \param r
/// \caption
///
void merge_sort(std::vector<int>::iterator l, std::vector<int>::iterator r) {
  auto s = r - l;
  if (s == 2 && *l > *(l + 1))
    std::swap(*l, *(l + 1));
  else if (s > 2) {
    auto v1 = std::vector(l, l + (s >> 1));
    auto v2 = std::vector(l + (s >> 1), r);
    merge_sort(v1.begin(), v1.end());
    merge_sort(v2.begin(), v2.end());
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), l);
  }
}

///
/// \brief quick_sort
/// \param l
/// \param r
/// \caption
///
void quick_sort(std::vector<int>::iterator l, std::vector<int>::iterator r) {
  if (l < r) {
    srand(time(nullptr));
    std::swap(*(l + rand() % (r - l)), *(r - 1));
    auto p = std::stable_partition(l, r, [r](int i) { return i <= *(r - 1); });
    quick_sort(l, p - 1);
    quick_sort(p, r);
  }
}

#endif

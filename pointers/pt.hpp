#ifndef PT_HPP
#define PT_HPP

int MSA(std::vector<int>::iterator l, std::vector<int>::iterator r) {
  auto maxv = *max_element(l, r);
  if (maxv < 0)
    return maxv;
  int sum, maxs;
  sum = maxs = 0;
  auto p = l;
  while (p < r) {
    if (*p > 0)
      sum += *p;
    else if (sum + *p > 0)
      sum += *p;
    else
      sum = 0;
    maxs = std::max(maxs, sum);
    ++p;
  }
  return maxs;
}



#endif

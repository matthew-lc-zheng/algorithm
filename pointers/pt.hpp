#ifndef PT_HPP
#define PT_HPP

///
/// \brief MSA: Maximum sum of subarray
/// \param l
/// \param r
/// \return
/// \caption 
///
int MSA(std::vector<int>::iterator l, std::vector<int>::iterator r) {
  auto maxv = *max_element(l, r);
  if (maxv < 0)
    return maxv;
  int sum=0, maxs=0;  
  auto p = l;
  while (p < r) {
    sum = *p > 0 || sum + *p > 0 ? *p + sum : 0;
    maxs = std::max(maxs, sum);
    ++p;
  }
  return maxs;
}
//----------------------------------------------------------------------------------


#endif

#ifndef NT_HPP
#define NT_HPP

#include <bits/stdc++.h>

///
/// \brief GCD: the greatest common divisor of two numbers
/// \param a number one
/// \param b number two
/// \caption GCD(a, b) = GCD(b, a mod b)
///
auto GCD(auto a, auto b) {
  if (a < b)
    swap(a, b);
  while (b) {
    swap(a, b);
    b %= a;
  }
  return a;
}

///
/// \brief LCM: the least common multiple of two numbers
/// \param a number one
/// \param b number two
/// \caption a*b/GCD9(a, b)
///
inline auto LCM(auto a, auto b) { return a * b / GCD(a, b); };

///
/// \brief CRT: Chinese Remainder Theorem
/// \param M List of modulus
/// \param R List of remainders
/// \caption to complete...
///
auto CRT(const std::vector<int> &M, const std::vector<int> &R) {
  auto A =
      accumulate(M.begin(), M.end(), 1, [](auto a, auto b) { return a * b; });
  std::vector<int> P(M.size());
  transform(M.begin(), M.end(), P.begin(), [A](auto i) { return A / i; });
  for (auto i = 0; i < P.size(); ++i) {
    auto j = 0;
    while ((P[i] * ++j) % M[i] != R[i]);
    P[i] *= j;
  }
  return accumulate(P.begin(), P.end(), 0) % A;
}


#endif

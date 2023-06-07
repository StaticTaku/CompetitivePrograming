#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> t(N);
  std::vector<int> x(N);
  std::vector<int> y(N);

  
  for(int i = 0;i<N;++i) {
    std::cin >> t[i] >> x[i] >> y[i];
  }

  int current_x = 0;
  int current_y = 0;
  int current_time = 0;

  for(int i = 0;i<N;++i) {
    int len = std::abs(x[i] - current_x) + std::abs(y[i] - current_y);
    if(t[i] - current_time < len) {
      std::cout << "No";
      return 0;
    }

    if((t[i] - current_time - len)%2 == 0) {
      current_x = x[i];
      current_y = y[i];
      current_time = t[i];
      continue;
    }else{
      std::cout << "No";
      return 0;
    }
  }

  std::cout << "Yes";
}
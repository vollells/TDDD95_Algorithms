#include <iostream>
#include <cmath>
#include <numeric>

int main(void){
  std::ios::sync_with_stdio(false);
  std::cout.tie(NULL);

  while(true){

    long long x = 0;
    std::cin >> x;
    if (x == 0){
      break;
    }

    long long absX = std::abs(x);
    long long rootExponent = 1;

    /*
     * The cummulative gcd for all exponents of the factors which
     * divide the number x is the same as the exponent of the largest
     * pth power.
     */

    for (long long factor = 2; factor < absX; factor++){
      long long divisions = 0;

      if (std::pow(factor, 2) > absX) {
        break;
      }

      while (!(absX % factor)) {
        absX = absX / factor;
        divisions++;
      }

      if (divisions){
        if (rootExponent != 1){
          divisions = std::gcd(rootExponent, divisions);
        }
        rootExponent = divisions;
      }
    }

    if (x < 0) {
      while ( !(rootExponent % 2))
        rootExponent /= 2;
    }
    std::cout << rootExponent << '\n';
  }
}

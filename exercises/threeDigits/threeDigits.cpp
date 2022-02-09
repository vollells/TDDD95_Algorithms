#include <iostream>

// Helper Function to return the three rightmost non-zero digit
int callMeFactorialLastDigit(long n){
  int sumOf5 = 0;
  int result = 1;

  for (long i=n; i>=1; i--){
    long number = i;
    while (number % 5 == 0) {
      number /= 5;
      sumOf5++;
    }
  }

  for (long i=n; i>=1; i--){
    long number = i;
    while (number % 5 == 0) {
      number /= 5;
    }

    while (sumOf5 != 0 && number % 2 == 0) {
      number /= 2;
      sumOf5--;
    }

    /*
     * After removing factors of 5 and 2 we multiply and only retrive
     * the last three didgets of the result.
    */
    result = (result * (number % 1000)) % 1000;
  }

  return result;
}

int main()
{
  long n;
  std::cin >> n;
  int result;

  result = callMeFactorialLastDigit(n);

  if (result < 10 && n>7) {
    std::cout << "00" << result << '\n';
  } else if (result < 100 && n>7) {
    std::cout << '0' << result << '\n';
  } else {
    std::cout << result << '\n';
  }

  return 0;
}

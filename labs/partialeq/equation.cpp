#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}


void toRowEchelon(std::vector<std::vector<long double>>& lhs, std::vector<long double>& rhs,
                  std::vector<unsigned long>& varRowIndex, unsigned long& offset, unsigned long N) {

  // k: pivot col, h: pivot row.
  unsigned long pCol = 0, pRow = 0;

  while (pCol < N && pRow < N){
    unsigned long maxIndex = 0;
    long double maxValue = 0;
    for (unsigned long i = pRow; i < N; i++){
      if (std::abs(lhs[i][pCol]) > std::abs(maxValue)){
        maxIndex = i;
        maxValue = std::abs(lhs[maxIndex][pCol]);
      }
    }
    

    if (maxValue == 0){
      //No pivot in this column, pass to next column
      offset++;
      std::swap(varRowIndex[pRow], varRowIndex[N-offset]);
      pCol++;
    } else {

      std::swap(lhs[pRow], lhs[maxIndex]);
      std::swap(rhs[pRow], rhs[maxIndex]);

      for (unsigned long i = pRow+1; i < N; i++){
        // Ratio between pivot row&col and current row& pivot col
        long double f = lhs[i][pCol] / lhs[pRow][pCol];
        lhs[i][pCol] = 0;
        for (unsigned long j = pCol+1; j < N; j++){
          lhs[i][j] -= (lhs[pRow][j] * f);
        }
        rhs[i] -= (rhs[pRow] * f);
      }

      pCol++;
      pRow++;
    }
  }
}


template<typename T>
T sumVector(std::vector<T> input){
  T answer = 0;
  for (T elem : input){
    answer += elem;
  }
  return answer;
}


bool checkNoneError(std::vector<long double>& rhs, unsigned long offset, unsigned long N){

  for(unsigned long pRow = N-1; pRow >= N-offset; pRow--){
    if (rhs[pRow] != 0){
      return true;
    }
    if (pRow == 0){break;}
  }
  return false;

}

bool checkMultipleError(std::vector<std::vector<long double>>& lhs, std::vector<long double>& rhs,
                        std::vector<unsigned long>& varRowIndex , std::vector<bool>& known,
                        unsigned long offset, unsigned long N){

  bool result = false;
  for (unsigned long pRow = 0; pRow < N-offset; pRow++) {
    for (unsigned long var = pRow; var < N; var++) {
      if (lhs[pRow][var] != 0 && rhs[varRowIndex[var]] == 0){
        result = true;
        known[var] = false;
      }
    }
  }
  return result;
}

void backSubstitution(std::vector<std::vector<long double>>& lhs, std::vector<long double>& rhs,
                      std::vector<unsigned long>& varRowIndex, std::vector<long double>& result,
                      std::vector<bool>& known, unsigned long offset, unsigned long N){

  for (long variable = N-1; (variable-(signed long)offset) >= 0; variable--) {

    if (lhs[varRowIndex[variable]][variable] == 0){
      offset--;
      continue;
    }

    long double ratio = 1 / lhs[varRowIndex[variable]][variable];

    
    result[variable] = (rhs[varRowIndex[variable]] * ratio);

    for (long pCol = N-1; pCol > variable; pCol--) {
      result[variable] -= (lhs[varRowIndex[variable]][pCol] * ratio * result[pCol]);
    }


  }
}

int main(void){
  // std::ios::sync_with_stdio(false);
  // std::cin.tie(NULL);

  while (true){
    unsigned long N = 0;
    std::cin >> N;
    if (N == 0) {
      break;
    }

    std::vector<std::vector<long double>> lhs(N,std::vector<long double>(N));
    std::vector<long double> rhs(N);
    std::vector<unsigned long> varRowIndex(N);

    for (unsigned long i = 0; i < N; i++){
      for (unsigned long j = 0; j < N; j++){
        std::cin >> lhs[i][j];
      }
    }
    for (unsigned long i = 0; i < N; i++){
      std::cin >> rhs[i];
      varRowIndex[i] = i;
    }

    unsigned long offset = 0;
    std::vector<bool> known(N, true);

    toRowEchelon(lhs, rhs, varRowIndex, offset, N);

    if (offset != 0 && checkNoneError(rhs, offset, N)){
      std::cout << "inconsistent\n";
    } else if (checkMultipleError(lhs, rhs, varRowIndex, known, offset, N)) {
      std::cout << "multiple\n";
    } else {
      std::vector<long double> result(N);
      backSubstitution(lhs, rhs, varRowIndex, result, known, offset, N);
      for (unsigned long i = 0; i < N; i++){
        std::cout << result[i] << ' ';
      }
      std::cout <<'\n';
    }

  }
}

    // std::cout <<  "New LHS: \n";
    // for (unsigned long i = 0; i < N; i++){
    //   for (unsigned long j = 0; j < N; j++){
    //     std::cout << lhs[i][j] << ' ';
    //   }
    //   std::cout <<'\n';
    // }
    // std::cout <<  "New RHS: \n";
    // for (unsigned long i = 0; i < N; i++){
    //   std::cout << rhs[i] << ' ';
    // }
    // std::cout <<'\n';
    // std::cout <<  "Result: \n";
    // for (unsigned long i = 0; i < N; i++){
    //   std::cout << result[i] << ' ';
    // }
    // std::cout <<'\n';

#include <iostream>
#include <string>
#include <vector>

struct SuffixPart{
  long index, length;
  std::string suffix;

  SuffixPart(long iIn, long lIn, std::string sIn) : index{iIn}, length{lIn}, suffix{sIn} {};
};

std::string suffixRecon(std::vector<SuffixPart> inputSuffixes, long sLen){
  std::string sentence(sLen, ' ');
  std::vector<SuffixPart> starSuffixes;

  for(SuffixPart suffixPart : inputSuffixes){
    for(long pIndex = 0; pIndex < suffixPart.length; pIndex++){
      long sIndex = suffixPart.index + pIndex;

      if(suffixPart.suffix[pIndex] == '*'){
        starSuffixes.push_back(suffixPart);
        break;
      }

      if (sentence[sIndex] == ' '){
        sentence[sIndex] = suffixPart.suffix[pIndex];
      } else if(sentence[sIndex] != suffixPart.suffix[pIndex]){
        return {};
      }
    }
  }

  for(SuffixPart suffixPart : starSuffixes){
    for(long i = 0; i < suffixPart.length; i++){
      long sIndex = sLen - 1 - i;
      long pIndex = suffixPart.length - 1 - i;

      if(suffixPart.suffix[pIndex] == '*'){break;}

      if (sentence[sIndex] == ' '){
        sentence[sIndex] = suffixPart.suffix[pIndex];
      } else if(sentence[sIndex] != suffixPart.suffix[pIndex]){
        return {};
      }
    }
  }

  for (char c : sentence){
    if(c == ' '){
      return {};
    }
  }

  return sentence;
}

int main(void){
  long n;
  std::cin >> n;
  for (int i = 0; i < n; i++){
    long sLen, nSuffix;
    std::cin >> sLen >> nSuffix;

    std::vector<SuffixPart> inputSuffixes;
    for (long j = 0; j  < nSuffix; j++){
      long index;
      std::string inputString;
      std::cin >> index >> inputString;
      inputSuffixes.emplace_back(index-1, inputString.size(), inputString);
    }

    std::string result = suffixRecon(inputSuffixes, sLen);

    if (result.empty()){
      std::cout << "IMPOSSIBLE" << '\n';
    } else {
      std::cout << result << '\n';
    }
  }
}

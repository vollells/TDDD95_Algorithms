#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct Literal{
  int i;
  bool negated;

  Literal(int iIn, bool nIn) : i(iIn), negated(nIn){}
  Literal() : i(-1), negated(false){}

  int isTrue(int value){
    if (value == 0) {
      return value;
    }

    //If value == -1 => tVal == false;
    bool tVal = negated ? !(value==1) : value==1;
    return tVal ? 1 : -1;
  }
};

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
      // Just 4 this problem
      if (item != "v"){
        result.push_back (item);
      }
    }

    return result;
}

bool DPLL(std::vector<std::vector<Literal>> const &PHI, std::vector<int> varAssign){

  bool holdsForAll = true;
  for (std::vector<Literal> clause : PHI){
    // oLT : oneLiteralTrue, oNTL : onlyNotTrueLiterals
    bool oLT = false, oNTL = true;

    for(Literal l : clause){
      // Does the literal exist in this caluse?
      if (l.i == -1){ continue; }
      // Is the current assignment true?
      int value = l.isTrue(varAssign[l.i]);
      if (value == 1){
        oLT = true;
        oNTL = false;
      } else if (value == 0) {
        oNTL = false;
      }
    }

    if (oNTL){ return false; }
    holdsForAll = holdsForAll && oLT;
  }

  if (holdsForAll) { return holdsForAll; }

  int nextVar = -1;
  for(unsigned i = 1; i < varAssign.size(); i++){
    if (!varAssign[i]){
      nextVar = i;
      break;
    }
  }

  std::vector<int> trueAssign = varAssign;
  trueAssign[nextVar] = 1;
  std::vector<int> falseAssign = varAssign;
  falseAssign[nextVar] = -1;

  return DPLL(PHI, trueAssign) || DPLL(PHI, falseAssign);
}

int main(){
  int C;
  std::cin >> C;
  while(C--){
    int N, M;
    std::cin >> N >> M;
    std::cin.ignore(256, '\n');

    // True: 1, False: -1, Unassigned: 0
    std::vector<int> variables(N+1, 0);
    // Vector with clauses, caluse vector -1/1 contains, 0 not contains
    std::vector<std::vector<Literal>> clauses(M, std::vector<Literal>());

    for(int i = 0; i<M; i++){
      std::string input;
      std::vector<std::string> input_vector;
      std::getline(std::cin, input);
      input_vector = split(input, ' ');
      for(std::string s : input_vector){
        bool value = true;
        if(s[0] == '~'){
          value = false;
          s.erase(s.begin(), s.begin()+1);
        }
        s.erase(s.begin(), s.begin()+1);
        clauses[i].emplace_back(std::stoi(s), !value);
      }
    }

    bool result = DPLL(clauses, variables);

    std::cout << (result ? "satisfiable\n" : "unsatisfiable\n");
  }
}

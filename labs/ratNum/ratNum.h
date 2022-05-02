/*
 * Author: Victor Lells (vicle728)
 * Problem: Rational Arithmetic with fractions.
 * Time Complexity: All member functions go in O(log(min(numerator,
 * denominator))) as they rely on GCD to normalize the values.
 */

#include <iostream>

template<typename T>
class ratNum {
private:
  // Uppper and Lower parts.
  T numerator, denominator;

  // TC:  O(log(min(num1, num2)))
  T gcd(T num1, T num2) const{
    if (num2 == 0){
      return num1;
    }
    return gcd(num2, num1 % num2);
  }

  void normalize(){
    T div = gcd(std::abs(numerator), std::abs(denominator));
    T num = numerator / div;
    T den = denominator / div;

    if(den < 0){
      num = -num;
      den = -den;
    }

    numerator = num;
    denominator = den;
  }

public:

  ratNum() : numerator(0), denominator(0){}
  ratNum(T nIn, T dIn) : numerator(nIn), denominator(dIn){
    normalize();
  }
  ratNum(ratNum<T>& rIn) : numerator(rIn.numerator), denominator(rIn.denominator){
    normalize();
  }

  ratNum<T>& operator = (const ratNum<T>& input) {
    numerator = input.numerator;
    denominator = input.denominator;

    return *this;
  }

  friend std::ostream& operator<<(std::ostream& out, const ratNum& obj)
  {
    out << obj.numerator << ' ' << '/' << ' ' << obj.denominator;
    return out;
  }

  friend std::istream& operator>>(std::istream& input, ratNum& obj)
  {
    input >> obj.numerator >> obj.denominator;
    return input;
  }

  /*
   * Addition, Subtraction, Multiplication, and Division done in a
   * rational arithmetic way. All in TC limit by GCD
   */
  ratNum<T> operator + (const ratNum &other) const {
    ratNum<T> output;
    output.numerator = (numerator * other.denominator) +  (other.numerator * denominator);
    output.denominator = other.denominator * denominator;
    output.normalize();
    return output;
  }
  ratNum<T> operator - (const ratNum &other) const {
    ratNum<T> output;
    output.numerator = (numerator * other.denominator) - (other.numerator * denominator);
    output.denominator = other.denominator * denominator;
    output.normalize();
    return output;
  }
  ratNum<T> operator * (const ratNum &other) const {
    ratNum<T> output;
    output.numerator = numerator * other.numerator;
    output.denominator = other.denominator * denominator;
    output.normalize();
    return output;
  }
  ratNum<T> operator / (const ratNum &other) const {
    ratNum<T> output;
    output.numerator = numerator * other.denominator;
    output.denominator = denominator * other.numerator;
    output.normalize();
    return output;
  }

  bool operator < (const ratNum &other) const {
    return (numerator * other.denominator) < (other.numerator * denominator);
  }
  bool operator > (const ratNum &other) const {
    return (numerator * other.denominator) > (other.numerator * denominator);
  }
  bool operator <= (const ratNum &other) const {
    return !(*this > other);
  }
  bool operator >= (const ratNum &other) const {
    return !(*this < other);
  }
  bool operator == (const ratNum &other) const {
    return numerator == other.numerator && denominator == other.denominator;
  }
  bool operator != (const ratNum &other) const {
    return numerator != other.numerator && denominator != other.denominator;
  }
};


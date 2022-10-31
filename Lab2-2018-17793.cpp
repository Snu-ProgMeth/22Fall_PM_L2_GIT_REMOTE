#include <iostream>
using namespace std;
class divide_by_zero_error {};

void emptyCinBuffer() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getInputDouble() {
  double num=0.;
  if (cin >> num) {
    return num;
  }
  else {
    emptyCinBuffer();
    throw exception("input value is not an integer");
  }
}

double simpleDivide(double numerator, double denominator) {
  if (denominator == 0.)
    throw divide_by_zero_error();
  return numerator / denominator;
}

double DoMyProcess();

int main() {
  while (true) {
    try {
      cout<< "result: " << DoMyProcess() <<endl;
    }
    catch (const exception& e) {
      cerr << e.what() << '\n';
    }
    catch (const divide_by_zero_error&) {
      cerr << " divide_by_zero_error occured" << endl;
    }
  }
  return 0;
}


double DoMyProcess() {
    double a = getInputDouble();
    double b = getInputDouble();
    double res = simpleDivide(a, b);

    if (res < 0)
        throw exception("negative result");
    else if (res > 1000000)
        throw exception("large result");

    return res;
}
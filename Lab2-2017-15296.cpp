#include <iostream>

namespace myNamespace {
	int a;
	int cout = 1;
}

using namespace std;
using namespace myNamespace;

int main() {
	a = 1;
	std::cout << a << endl;

	return 0;
}
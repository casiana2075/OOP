#include <iostream>
#include "Math.h"

using namespace std;

int main() {

	int a=3, b=4, c=2;
    double x=1.5, y=2.0, z=3.5;

    Math::Add(a, c);
    Math::Add(a, b, c);
    Math::Add(y, z);
    Math::Add(x, y, z);

    Math::Mul(b, c);
    Math::Mul(a, b, c);
    Math::Mul(x, z);
    Math::Mul(x, y, z);

    Math::Add(6, 5, 3, 8, 4, 1, 2);

    Math::Add("l1", "l2");
    Math::Add("l1", nullptr);
    Math::Add(nullptr, nullptr);

	return 0;
}
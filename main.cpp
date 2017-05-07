#include <iostream>
#include "functions.hpp"

using std::cout;
using std::endl;

int main()
{
    cout << "identity(3) == " << identity(3) << endl;
    cout << "add(3,4) == " << add(3,4) << endl;
    cout << "sub(4,3) == " << sub(4,3) << endl;
    cout << "mul(4,5) == " << mul(4,5) << endl;
    cout << "identityf(5)() == " << identityf(5)() << endl;
    cout << "addf(5)(4) == " << addf(5)(4) << endl;
    cout << "swap(sub)(3, 2) == " << swap(sub)(3, 2) << endl;
    cout << "twice(add)(11) == " << twice(add)(11) << endl;
    cout << "applyf(mul)(3)(4) == " << applyf(mul)(3)(4) << endl;
    cout << "curry(mul, 3)(4) == " << curry(mul, 3)(4) << endl;
    cout << "increment(19) == " << increment(19) << endl;
}

#include "helpers.hpp"
#include "functions.hpp"

int main() {
    cout << "identity(3) == " << identity(3) << endl;
    cout << "identity(Porto)" << identity("Porto"s) << endl;
    cout << "add(3,4) == " << add(3, 4) << endl;
    cout << "add(3.5,4.5) == " << add(3.5, 4.5) << endl;
    cout << "add(Porto ,Codes) == " << add("Porto "s,"Codes"s) << endl;
    cout << "sub(4,3) == " << sub(4, 3) << endl;
    cout << "mul(4,5) == " << mul(4, 5) << endl;
    cout << "identityf(5)() == " << identityf(5)() << endl;
    cout << "addf(5)(4) == " << addf(5)(4) << endl;
    cout << "swap(sub)(3, 2) == " << swap(sub)(3, 2) << endl;
    cout << "twice(add)(11) == " << twice(add)(11) << endl;
    cout << "applyf(mul)(3)(4) == " << applyf(mul)(3)(4) << endl;
    cout << "curry(mul, 3)(4) == " << curry(mul, 3)(4) << endl;
    cout << "increment(19) == " << increment(19) << endl;
    cout << "binaryCallback(mul)(5, 6, inc) ==" << binaryCallback(mul)(5, 6, increment) << endl;

    auto addTwice = twice(add);
    auto add20 = addf(20);

    auto add20ThenTwice = compose(addTwice, add20); //
    cout << "add20ThenTwice(20) == " << add20ThenTwice(20) << endl; // === addTwice(add20(20))

    vector<int> numbers = {1, 2, 3, 4, 5};
    vector<int> numbers2;
    vector<int> numbers3;

    //  MAP : apply lambda to each element
    std::transform(begin(numbers), end(numbers), back_inserter(numbers2), increment);

    printVector(numbers);
    printVector(numbers2);

    // FILTER : remove elements based on condition
    std::remove_copy_if(begin(numbers2), end(numbers2), back_inserter(numbers3),
        [](auto x)
        {
            return x % 2 == 0;
        }

    );
    printVector(numbers2);
    printVector(numbers3);

    // REDUCE : apply a function to reduce a list to a single element
    cout << std::accumulate(begin(numbers3), end(numbers3), 0,
                       [](auto x, auto y) {
                           return x + y;
                       }
    );
}
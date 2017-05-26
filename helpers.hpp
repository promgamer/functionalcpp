#ifndef DEMO_HELPERS_H
#define DEMO_HELPERS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::cout;
using std::endl;
using std::vector;
using std::transform;
using std::begin;
using std::end;
using std::back_inserter;
using std::remove_copy_if;
using std::accumulate;
using std::literals::string_literals::operator""s;

void printVector(const vector<int> vec)
{
    std::for_each(begin(vec), end(vec), [](auto x){cout << x << " ";});
    cout << endl;
}

#endif //DEMO_HELPERS_H

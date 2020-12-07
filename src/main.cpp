
#include <iostream>

#include "swap/swap.h"

using namespace std;

int main(int argc, char **argv) {
    int val1 = 10;
    int val2 = 20;
    cout << "before swap: val1=" << val1 << ", val2=" << val2 << endl;
    swap(val1, val2);
    cout << "after swap: val1=" << val1 << ", val2=" << val2 << endl;
    return 0;
}
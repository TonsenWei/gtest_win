#include "swap/swap.h"

/**
 * @description: 两个数交换
 * @param : 传入两个值
 * @return {*}
 */
void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
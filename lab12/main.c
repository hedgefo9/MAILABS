#include <stdio.h>
#include <assert.h>

#define INT_MIN (-2147483648)
#define INT_MAX 2147483647

// возвращает модуль числа
int abs(int a) {
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}

// возвращает знак числа
int sign(int a) {
    if (a > 0) {
        return 1;
    } else if (a == 0) {
        return 0;
    } else if (a < 0) {
        return -1;
    }
}

// возвращает количество разрядов у числа
int digits_quantity(int x) {
    int x_abs = abs(x);
    if (x_abs == 0) {
        return 1;
    }
    int num_len = 0;
    while (x_abs > 0) {
        num_len++;
        x_abs = x_abs / 10;
    }
    return num_len;
}

// возвращает число, равное x возведённому в положительную или нулевую степень power
int pow_int(int x, int power) {
    int res = 1;
    for (int i = 0; i < power; i++) {
        res *= x;
    }
    return res;
}

// возвращает число, равное сдвинутому числу x на shift_val влево
int shift_left(int x, int shift_val) {
    int new_num = x;
    int x_len = digits_quantity(x);
    shift_val = shift_val % x_len;
    int y = pow_int(10, x_len - 1);
    for (int k = 0; k < shift_val; k++) {
        int x_tmp = new_num;
        new_num = (x_tmp % y) * 10 + (x_tmp / y);
    }
    return new_num;
}

void test_abs() {
    assert(abs(5) == 5);
    assert(abs(-3) == 3);
    assert(abs(0) == 0);
}

void test_sign() {
    assert(sign(7) == 1);
    assert(sign(-10) == -1);
    assert(sign(0) == 0);
}

void test_digits_quantity() {
    assert(digits_quantity(0) == 1);
    assert(digits_quantity(1234) == 4);
    assert(digits_quantity(348584739) == 9);
    assert(digits_quantity(-10000) == 5);
}

void test_pow_int() {
    assert(pow_int(10, 4) == 10000);
    assert(pow_int(2, 20) == 1048576);
    assert(pow_int(100, 0) == 1);
    assert(pow_int(-5, 2) == 25);
    assert(pow_int(-7, 5) == -16807);
}

void test_shift_left() {
    assert(shift_left(1234, 1) == 2341);
    assert(shift_left(230503604, 2) == 50360423);
    assert(shift_left(9284158, 5764801) == 9284158);
}

void test_all() {
    test_abs();
    test_sign();
    test_digits_quantity();
    test_pow_int();
    test_shift_left();
}

int main() {
    test_all();

    int num;
    int shift_value;
    scanf("%d\n", &num);
    scanf("%d", &shift_value);


    if (num == 0) {
        printf("%d", 0);
        return 0;
    }

    // сохранение знака
    int sign_original = sign(num);
    int num_abs = abs(num);

    int shifted_num = shift_left(num_abs, shift_value) * sign_original;
    printf("%d\n", shifted_num);

    return 0;
}
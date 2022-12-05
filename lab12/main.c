#include <stdio.h>
#include <assert.h>

#define INT_MIN -2147483648
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

int digits_quantity(int x) {
    int num_len = 0;
    while (x > 0) {
        num_len++;
        x = x / 10;
    }
    return num_len;
}

int pow_int(int x, int power) {
    int res = 1;
    for (int i = 0; i < power; i++) {
        res *= x;
    }
    return res;
}

int shift_left(int x, int x_len, int shift_val) {
    int new_num = x;
    for (int k = 0; k < shift_val; k++) {
        int x_tmp = new_num;
        new_num = 0;
        for (int i = 0; i < x_len - 1; i++) {
            new_num = new_num + (x_tmp % 10) * pow_int(10, digits_quantity(new_num));
            x_tmp /= 10;
        }
        int first_digit = x_tmp;
        new_num = new_num * 10 + first_digit;
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

void test_all() {
    test_abs();
    test_sign();
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

    int sign_original = sign(num);
    int num_abs = abs(num);

    // подсчет количества разрядов
    int num_len = digits_quantity(num_abs);

    int shifted_num = shift_left(num_abs, num_len, shift_value % num_len) * sign_original;
    printf("%d\n", shifted_num);

    return 0;
}
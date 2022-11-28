#include <stdio.h>

// нахождение остатка при делении первого числа на второе
int mod(int a, int b) {
    return (b + a % b) % b;
}

// возвращает максимальное из двух чисел
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// возвращает минимальное из двух чисел
int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

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

int main() {
    int i0 = 10, j0 = 20, l0 = -1;
    int i = i0, j = j0, l = l0, i_prev = i, j_prev = j, l_prev = l;

    for (int k = 0; k <= 50; k++) {
        i_prev = i;
        j_prev = j;
        l_prev = l;
        i = mod(abs(max(i_prev * (k + 5), j_prev * (k + 6))) - abs(min(j_prev * (k + 7), l_prev * (k + 8))),20);
        j = mod((3 - sign(i_prev - j_prev)) * abs(min(i_prev * l_prev + 5,min(j_prev * l_prev - 3, i_prev * j_prev + 6))), 25) - 7;
        l = mod(i_prev, 10) + mod(j_prev, 10) + mod(l_prev, 10);
        if ((abs(i - 10) < 5) && (abs(j + 10) < 5)) {
            printf("Попал на шаге %d, i = %d, j = %d, l = %d\n", k, i, j, l);
            return 0;
        }
    }

    printf("Не попал, i = %d, j = %d, l = %d", i, j, l);
    return 0;
}

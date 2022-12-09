#include <stdio.h>

int main() {
    const int max_size = 8;
    int n;
    int m[max_size][max_size];

    // считывание данных и поиск минимального/максимального элемента
    int min_elem_val = 100000000;
    int min_elem_i = -1;
    int min_elem_j = -1;
    int max_elem_val = -100000000;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
            if (m[i][j] < min_elem_val) {
                min_elem_val = m[i][j];
                min_elem_i = i;
                min_elem_j = j;
            }
            if (m[i][j] > max_elem_val) {
                max_elem_val = m[i][j];
            }
        }
    }
    // замена строк с максимальным элементом на строку с
    // минимальным элементом (при этом номер строки минимальный)
    for (int i = 0; i < n; i++) {
        int flag_row_contains_max_elem = 0;
        for (int j = 0; j < n; j++) {
            if (m[i][j] == max_elem_val) {
                flag_row_contains_max_elem = 1;
                break;
            }
        }
        if (!flag_row_contains_max_elem) continue;
        for (int j = 0; j < n; j++) {
            m[i][j] = m[min_elem_i][j];
        }
    }
    // вывод матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}


#include <stdio.h>
#include <stdarg.h>

// возвращает максимальное из всех чисел
int max(int n, ...) {
    va_list ptr;
    va_start(ptr, n);

    int max_num = va_arg(ptr, int);
    for (int i = 0; i < n - 1; i++) {
        int current_num = va_arg(ptr, int);
        max_num = current_num > max_num ? current_num : max_num;
    }

    va_end(ptr);
    return max_num;
}

// возвращает минимальное из всех чисел
int min(int n, ...) {
    va_list ptr;
    va_start(ptr, n);

    int min_num = va_arg(ptr, int);
    for (int i = 0; i < n - 1; i++) {
        int current_num = va_arg(ptr, int);
        min_num = current_num < min_num ? current_num : min_num;
    }

    va_end(ptr);
    return min_num;
}

int main() {

    FILE *myfile;
    myfile = fopen("27.txt", "r");
    int N = 0;
    fscanf(myfile, "%d", &N);

    int summary = 0;
    int not_devisible_109 = 1000000000;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        fscanf(myfile, "%d %d %d", &a, &b, &c);
        summary += max(3, a, b, c);
        int diff1 = max(3, a, b, c) - min(3, a, b, c);
        int mid_num = a + b + c - max(3, a, b, c) - min(3, a, b, c);
        int diff2 = max(3, a, b, c) - mid_num;
        if (diff1 % 109 != 0) {
            not_devisible_109 = min(2, not_devisible_109, diff1);
        }
        if (diff2 % 109 != 0) {
            not_devisible_109 = min(2, not_devisible_109, diff2);
        }
    }

    if (summary % 109 != 0) {
        printf("%d\n", summary);
    } else {
        printf("%d\n", summary - not_devisible_109);
    }
    fclose(myfile);
}

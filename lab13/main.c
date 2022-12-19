#include <stdio.h>
#include <ctype.h>
#include <assert.h>

#define ALL_LETTERS 67108863u
#define VOWELS (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))
#define CONSONANTS ((~VOWELS) & ALL_LETTERS)

typedef enum {
  SEPARATOR,
  WORD1,
  WORD2
} state;

unsigned int char_to_set(char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0u;
    } else {
        return 1u << (c - 'a');
    }
}
int is_separator(char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == ',' || c == EOF;
}

int is_letter(char c) {
    return (char_to_set(c) & ALL_LETTERS) > 0;
}

void test_char_to_set() {
    assert(char_to_set('a') == 1u);
    assert(char_to_set('y') == 16777216u);
    assert(char_to_set('M') == 4096u);
    assert(char_to_set('+') == 0u);
}

void test_is_separator() {
    assert(is_separator(' ') == 1);
    assert(is_separator('\t') == 1);
    assert(is_separator(EOF) == 1);
    assert(is_separator('f') == 0);
}

void test_is_letter() {
    assert(is_letter('a') == 1);
    assert(is_letter('y') == 1);
    assert(is_letter('M') == 1);
    assert(is_letter('+') == 0);
}

void test_all() {
    test_char_to_set();
    test_is_separator();
    test_is_letter();
}

int main() {
    test_all();
    int result = 0;
    char c = ' ';
    state current_state = SEPARATOR;
    unsigned int word1_set = 0u, word2_set = 0u;

    while (1) {
        c = getchar();
        switch (current_state) {
            case SEPARATOR:
                if (is_letter(c)) {
                    word1_set = char_to_set(c);
                    current_state = WORD1;
                }
                break;
            case WORD1:
                if (is_letter(c)) {
                    word1_set = word1_set | char_to_set(c);
                } else if (is_separator(c)) {
                    current_state = WORD2;
                }
                break;
            case WORD2:
                if (is_letter(c)) {
                    word2_set = word2_set | char_to_set(c);
                } else if (is_separator(c)) {
                    if ((word1_set > 0) && (word2_set > 0)) {
                        if (((word1_set & word2_set) & CONSONANTS) == 0u) {
                            result = 1;
                        }
                        word1_set = word2_set;
                        word2_set = 0;
                    }
                }
                break;
        }
        if (c == EOF) break;
    }

    if (result == 1) {
        printf("Input contains at least two adjacent words with disjoint set of consonants\n");
    } else {
        printf("Input does not contain at least two adjacent words with disjoint set of consonants\n");
    }

    getchar();
    return 0;
}

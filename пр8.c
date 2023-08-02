#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int Duplicate(char *word, int start, int end) { /* Перевіряє, чи є дублікат символу у слові */
    for (int i = start; i < end; i++) {
        if (word[i] == word[end]) {
            return 1; /* Є дублікат */
        }
    }
    return 0; /* Немає дублікату */
}

void generateAnagrams(char *word, int start, int end, int *count) {  /* Генерує всі можливі анаграми слова */
    if (start == end) {
        (*count)++;
    } else {
        for (int i = start; i <= end; i++) {
            if (!Duplicate(word, start, i)) {
                swap((word + start), (word + i));
                generateAnagrams(word, start + 1, end, count);
                swap((word + start), (word + i)); /* Відмінити обмін backtrack */
            }
        }
    }
}

int main() {
    char word[15];
    int count = 0;

    printf("Введіть слово: ");
    scanf("%s", word);

    int length = strlen(word);

    generateAnagrams(word, 0, length - 1, &count);

    printf("Кількість анаграм: %d\n", count);

    return 0;
}
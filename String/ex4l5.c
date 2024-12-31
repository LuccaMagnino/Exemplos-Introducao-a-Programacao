#include <stdio.h>
#include <string.h>


int count_matching_letters(const char *word1, const char *word2) {
    int count = 0, i;
    for (i = 0; word1[i] != '\0'; i++) {
        if (word1[i] == word2[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, i;
    scanf("%d", &n);  

    for (i = 0; i < n; i++) {
        char word[6];
        scanf("%s", word);

        if (strlen(word) == 3) {
            if (count_matching_letters(word, "one") >= 2) {
                printf("1\n");
            } else if (count_matching_letters(word, "two") >= 2) {
                printf("2\n");
            }
        } else if (strlen(word) == 5) {
            if (count_matching_letters(word, "three") >= 4) {
                printf("3\n");
            }
        }
    }

    return 0;
}

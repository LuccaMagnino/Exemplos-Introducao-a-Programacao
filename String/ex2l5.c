#include <stdio.h>
#include <string.h>

int main() {
    int N, j, i;
    scanf("%d", &N);


    int led_count[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    for (i = 0; i < N; i++) {
        char number[101]; 
        scanf("%s", number);

        int total_leds = 0;
        int len = strlen(number);

        for (j = 0; j < len; j++) {
            total_leds += led_count[number[j] - '0'];
        }

        printf("%d leds\n", total_leds);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int cirolar[12];
    int max = 0;

    srand(time(NULL));

    // 12 aylık ciro verisi (1–10)
    for (int i = 0; i < 12; i++) {
        cirolar[i] = rand() % 10 + 1;
        if (cirolar[i] > max)
            max = cirolar[i];
    }

    printf("Aylik Cirolar:\n");
    for (int i = 0; i < 12; i++) {
        printf("%2d. Ay: %dK\n", i + 1, cirolar[i]);
    }

    printf("\nDikey Bar Grafigi:\n\n");

    // Dikey bar grafiği
    for (int seviye = max; seviye > 0; seviye--) {
        for (int i = 0; i < 12; i++) {
            if (cirolar[i] >= seviye)
                printf(" * ");
            else
                printf("   ");
        }
        printf("\n");
    }

    // Ay numaraları
    for (int i = 1; i <= 12; i++) {
        printf("%2d ", i);
    }

    return 0;
}
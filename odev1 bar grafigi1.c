#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int cirolar[12];

    // Rastgele sayı üretimi için
    srand(time(NULL));

    // 12 aylık ciro verisi oluşturma
    for (int i = 0; i < 12; i++) {
        cirolar[i] = rand() % 10 + 1;  // 1-10 arası
    }

    printf("Aylik Cirolar:\n");
    for (int i = 0; i < 12; i++) {
        printf("%d. Ay: %dK\n", i + 1, cirolar[i]);
    }

    printf("\nYatay Bar Grafigi:\n");

    // En yüksek ciroyu bul
    int max = cirolar[0];
    for (int i = 1; i < 12; i++) {
        if (cirolar[i] > max)
            max = cirolar[i];
    }

    // Örnek 1.2 - Yatay bar grafiği
    for (int i = 0; i < 12; i++) {
        printf("%2d.: ", i + 1);
        for (int j = 0; j < cirolar[i]; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
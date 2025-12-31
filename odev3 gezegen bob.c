#include <stdio.h>

int isVowel(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    char c1, c2, c3;
    int count = 0;

    printf("Gecerli Isimler:\n");

    for (c1 = 'a'; c1 <= 'z'; c1++) {
        for (c2 = 'a'; c2 <= 'z'; c2++) {
            c3 = c1;  // 1. ve 3. harf aynı

            // ünsüz-ünlü-ünsüz
            if (!isVowel(c1) && isVowel(c2) && !isVowel(c3)) {
                int toplam = c1 + c2 + c3;
                if (isPrime(toplam)) {
                    printf("%2d. %c%c%c\n", ++count, c1, c2, c3);
                }
            }

            // ünlü-ünsüz-ünlü
            if (isVowel(c1) && !isVowel(c2) && isVowel(c3)) {
                int toplam = c1 + c2 + c3;
                if (isPrime(toplam)) {
                    printf("%2d. %c%c%c\n", ++count, c1, c2, c3);
                }
            }
        }
    }

    printf("\nToplam Gecerli Isim Sayisi: %d\n", count);
    return 0;
}
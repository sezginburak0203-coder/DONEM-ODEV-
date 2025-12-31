#include <stdio.h>
#include <string.h>

int main() {
    char mesaj[200];
    int anahtar;

    printf("Sifrelemek istediginiz mesaji girin: ");
    fgets(mesaj, sizeof(mesaj), stdin);

    printf("Anahtar degeri girin: ");
    scanf("%d", &anahtar);

    anahtar = anahtar % 26;

    for (int i = 0; mesaj[i] != '\0'; i++) {
        if (mesaj[i] >= 'A' && mesaj[i] <= 'Z') {
            mesaj[i] = ((mesaj[i] - 'A' + anahtar) % 26) + 'A';
        } 
        else if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {
            mesaj[i] = ((mesaj[i] - 'a' + anahtar) % 26) + 'a';
        }
    }

    printf("Sifrelenmis Mesaj: %s", mesaj);
    return 0;
}
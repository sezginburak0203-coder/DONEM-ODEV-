#include <stdio.h>

#define BOYUT 5

int labirent[BOYUT][BOYUT] = {
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1}
};

int yol[BOYUT][BOYUT] = {0};

// Geçerli hamle mi? 
int gecerliMi(int x, int y) {
    return (x >= 0 && x < BOYUT &&
            y >= 0 && y < BOYUT &&
            labirent[x][y] == 1 &&
            yol[x][y] == 0);
}

// DFS ile yol bulma 
int yoluBul(int x, int y) {

    // Çıkış noktası
    if (x == BOYUT - 1 && y == BOYUT - 1) {
        yol[x][y] = 1;
        return 1;
    }

    if (gecerliMi(x, y)) {
        yol[x][y] = 1;

        // aşağı
        if (yoluBul(x + 1, y)) return 1;
        // sağ 
        if (yoluBul(x, y + 1)) return 1;
        // yukarı 
        if (yoluBul(x - 1, y)) return 1;
        // sol
        if (yoluBul(x, y - 1)) return 1;

        //geri al
        yol[x][y] = 0;
    }
    return 0;
}

// Matrisi yazdır
void yazdir(int dizi[BOYUT][BOYUT]) {
    for (int i = 0; i < BOYUT; i++) {
        for (int j = 0; j < BOYUT; j++) {
            printf("%d ", dizi[i][j]);
        }
        printf("\n");
    }
}

int main() {

    // Başlangıç ve çıkış kontrolü
    if (labirent[0][0] == 0 || labirent[BOYUT-1][BOYUT-1] == 0) {
        printf("Baslangic veya cikis noktasi gecersiz!\n");
        return 0;
    }

    if (yoluBul(0, 0)) {
        printf("Cikis yolu bulundu:\n");
        yazdir(yol);
    } else {
        printf("Cikis yolu bulunamadi!\n");
    }

    return 0;
}
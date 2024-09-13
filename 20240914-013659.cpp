#include <cstdio>   // Untuk printf dan scanf (pustaka C)
#include <cstring>  // Untuk strcpy
#include <cmath>    // Untuk operasi matematika (kalau dibutuhkan)

// Struktur untuk menyimpan catatan hutang
struct NotaHutang {
    char deskripsi[100];
    double jumlah;
};

// Fungsi untuk menampilkan saldo
void tampilkanSaldo(double saldo) {
    printf("Saldo saat ini: Rp %.2f\n", saldo);
}

// Fungsi untuk menambahkan uang ke saldo
double tambahUang(double saldo, double jumlah) {
    return saldo + jumlah;
}

// Fungsi untuk membayar hutang dan mengurangi saldo
double bayarHutang(double saldo, double jumlah) {
    if (saldo < jumlah) {
        printf("Saldo tidak cukup untuk membayar hutang!\n");
        return saldo;
    }
    return saldo - jumlah;
}

// Fungsi untuk menampilkan catatan hutang
void tampilkanNotaHutang(const NotaHutang hutangList[], int size) {
    printf("\nRiwayat Hutang:\n");
    if (size == 0) {
        printf("Tidak ada catatan hutang.\n");
    } else {
        for (int i = 0; i < size; ++i) {
            printf("%s: Rp %.2f\n", hutangList[i].deskripsi, hutangList[i].jumlah);
        }
    }
}

int main() {
    double saldo = 0.0;
    NotaHutang hutangList[100];  // Menyimpan daftar hutang
    int jumlahHutang = 0;        // Jumlah hutang yang dicatat

    int pilihan;
    double jumlah;
    char deskripsi[100];

    while (true) {
        // Menu interaktif
        printf("\nPilih operasi:\n");
        printf("1. Tambah Uang\n");
        printf("2. Bayar Hutang\n");
        printf("3. Tampilkan Saldo\n");
        printf("4. Tampilkan Riwayat Hutang\n");
        printf("5. Keluar\n");
        printf("Masukkan pilihan (1-5): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                // Tambah uang ke saldo
                printf("Masukkan jumlah uang yang akan ditambahkan: Rp ");
                scanf("%lf", &jumlah);
                saldo = tambahUang(saldo, jumlah);
                printf("Rp %.2f berhasil ditambahkan ke saldo!\n", jumlah);
                break;
            
            case 2:
                // Bayar hutang
                printf("Masukkan deskripsi hutang: ");
                scanf(" %[^\n]s", deskripsi);  // Mengambil input string deskripsi hutang
                printf("Masukkan jumlah hutang yang akan dibayar: Rp ");
                scanf("%lf", &jumlah);

                if (saldo >= jumlah) {
                    saldo = bayarHutang(saldo, jumlah);
                    strcpy(hutangList[jumlahHutang].deskripsi, deskripsi);  // Menyimpan deskripsi hutang
                    hutangList[jumlahHutang].jumlah = jumlah;  // Menyimpan jumlah hutang
                    jumlahHutang++;
                    printf("Rp %.2f berhasil dibayarkan!\n", jumlah);
                } else {
                    printf("Saldo tidak cukup untuk membayar hutang ini.\n");
                }
                break;
            
            case 3:
                // Tampilkan saldo saat ini
                tampilkanSaldo(saldo);
                break;
            
            case 4:
                // Tampilkan riwayat hutang
                tampilkanNotaHutang(hutangList, jumlahHutang);
                break;
            
            case 5:
                // Keluar dari program
                printf("Terima kasih telah menggunakan aplikasi ini!\n");
                return 0;
            
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    }
}
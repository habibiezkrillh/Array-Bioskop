# Program Pembelian Tiket Bioskop

## Deskripsi Proyek
Ini adalah program C++ sederhana yang saya buat ketika saya kuliah di Kalla Institute sebelum pindah ke UC Surabaya. Program ini mensimulasikan pembelian tiket bioskop menggunakan array satu dimensi yang dianalogikan sebagai nomor kursi. Program ini memungkinkan pengguna untuk membeli beberapa tiket dan memilih nomor kursi yang diinginkan. Pada akhir program, semua nama pembeli beserta nomor kursi yang dibeli akan ditampilkan.

## Fitur Program
1. Menggunakan array satu dimensi untuk menyimpan status kursi.
2. Input nama pembeli dan jumlah tiket yang ingin dibeli.
3. Validasi nomor kursi dan pengecekan ketersediaan kursi.
4. Menampilkan daftar pembeli dan nomor kursi yang dibeli di akhir program.

## Cara Kerja Program

1. **Inisialisasi Variabel**:
   - `totalSeats`: Jumlah total kursi (100 kursi).
   - `seats`: Vector dari string dengan ukuran `totalSeats` yang diinisialisasi dengan "Kosong" untuk menunjukkan kursi yang belum terisi.
   - `name`: String untuk menyimpan nama pembeli.
   - `numTickets`: Integer untuk menyimpan jumlah tiket yang ingin dibeli.
   - `seatNumber`: Integer untuk menyimpan nomor kursi yang diinginkan.

2. **Proses Input**:
   - Program meminta nama pembeli. Jika nama adalah "selesai", program akan berhenti meminta input.
   - Program meminta jumlah tiket yang ingin dibeli oleh pembeli.
   - Untuk setiap tiket, program meminta nomor kursi yang diinginkan dan mengecek validitas serta ketersediaannya. Jika kursi sudah terisi atau nomor kursi tidak valid, program meminta input ulang.

3. **Output**:
   - Setelah semua input selesai, program menampilkan daftar pembeli dan nomor kursi yang dibeli.

## Kode Program

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    const int totalSeats = 100; // Jumlah total kursi
    vector<string> seats(totalSeats, "Kosong"); // Inisialisasi semua kursi sebagai "Kosong"
    string name;
    int numTickets, seatNumber;

    while (true) {
        cout << "Masukkan nama pembeli (atau ketik 'selesai' untuk mengakhiri): ";
        getline(cin, name);

        if (name == "selesai") {
            break;
        }

        cout << "Berapa tiket yang ingin dibeli, " << name << "? ";
        cin >> numTickets;
        cin.ignore(); // Membersihkan newline dari input sebelumnya

        for (int i = 0; i < numTickets; ++i) {
            cout << "Masukkan nomor kursi yang diinginkan (1-" << totalSeats << "): ";
            cin >> seatNumber;
            cin.ignore(); // Membersihkan newline dari input sebelumnya

            if (seatNumber < 1 || seatNumber > totalSeats) {
                cout << "Nomor kursi tidak valid. Silahkan masukkan nomor kursi antara 1 dan " << totalSeats << ".\n";
                --i; // Mengulang iterasi ini
                continue;
            }

            if (seats[seatNumber - 1] != "Kosong") {
                cout << "Kursi sudah terisi. Silahkan pilih kursi lain.\n";
                --i; // Mengulang iterasi ini
                continue;
            }

            seats[seatNumber - 1] = name;
        }
    }

    // Tampilkan hasil pembelian tiket
    cout << "\nDaftar pembeli dan nomor kursi:\n";
    for (int i = 0; i < totalSeats; ++i) {
        if (seats[i] != "Kosong") {
            cout << "Kursi nomor " << i + 1 << " dibeli oleh " << seats[i] << endl;
        }
    }

    return 0;
}
```

## Output
```
Masukkan nama pembeli (atau ketik 'selesai' untuk mengakhiri): Andi
Berapa tiket yang ingin dibeli, Andi? 2
Masukkan nomor kursi yang diinginkan (1-100): 5
Masukkan nomor kursi yang diinginkan (1-100): 10

Masukkan nama pembeli (atau ketik 'selesai' untuk mengakhiri): Budi
Berapa tiket yang ingin dibeli, Budi? 1
Masukkan nomor kursi yang diinginkan (1-100): 5
Kursi sudah terisi. Silahkan pilih kursi lain.
Masukkan nomor kursi yang diinginkan (1-100): 15

Masukkan nama pembeli (atau ketik 'selesai' untuk mengakhiri): Siti
Berapa tiket yang ingin dibeli, Siti? 3
Masukkan nomor kursi yang diinginkan (1-100): 20
Masukkan nomor kursi yang diinginkan (1-100): 25
Masukkan nomor kursi yang diinginkan (1-100): 30

Masukkan nama pembeli (atau ketik 'selesai' untuk mengakhiri): selesai

Daftar pembeli dan nomor kursi:
Kursi nomor 5 Dibeli oleh Andi
Kursi nomor 10 Dibeli oleh Andi
Kursi nomor 15 Dibeli oleh Budi
Kursi nomor 20 Dibeli oleh Siti
Kursi nomor 25 Dibeli oleh Siti
Kursi nomor 30 Dibeli oleh Siti
```

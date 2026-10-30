#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std;

// Function menghitung rata-rata
float hitungRataRata(float data[]) {
    float total = 0;

    for (int i = 0; i < 7; i++) {
        total += data[i];
    }

    return total / 7;
}

// Function menghitung total air
float hitungTotalAir(float air[]) {
    float total = 0;

    for (int i = 0; i < 7; i++) {
        total += air[i];
    }

    return total;
}

// Function menghitung skor kesehatan
float hitungSkor(float tidur[], float air[],
                 float olahraga[]) {
    int skor = 0;

    for (int i = 0; i < 7; i++) {
        if (tidur[i] >= 7)
            skor++;

        if (air[i] >= 8)
            skor++;

        if (olahraga[i] >= 30)
            skor++;
    }

    return (skor / 21.0) * 100;
}

// Function pengingat minum air setiap jam
void pengingatMinum() {
    char pilihan;

    cout << "\n=== PENGINGAT MINUM AIR ===\n";
    cout << "Aktifkan pengingat setiap 1 jam? (y/n): ";
    cin >> pilihan;

    if (pilihan == 'y' || pilihan == 'Y') {
        cout << "\nPengingat aktif!\n";

        while (true) {
            this_thread::sleep_for(chrono::hours(1));

            cout << "\n[NOTIFIKASI]\n";
            cout << "Jangan lupa minum air putih!\n";

            cout << "Lanjutkan pengingat? (y/n): ";
            cin >> pilihan;

            if (pilihan == 'n' || pilihan == 'N') {
                cout << "Pengingat dihentikan.\n";
                break;
            }
        }
    }
}

// Program utama
int main() {
    string hari[7] = {
        "Senin", "Selasa", "Rabu", "Kamis",
        "Jumat", "Sabtu", "Minggu"
    };

    float tidur[7], air[7], olahraga[7];
    int pilihan;

    cout << "====================================\n";
    cout << " PELACAK KEBIASAAN SEHAT MAHASISWA\n";
    cout << "====================================\n";

    cout << "1. Input Data Harian\n";
    cout << "2. Pengingat Minum Air\n";
    cout << "Pilih menu: ";
    cin >> pilihan;

    if (pilihan == 2) {
        pengingatMinum();
        return 0;
    }

    if (pilihan != 1) {
        cout << "Pilihan tidak tersedia.\n";
        return 0;
    }

    // Input data selama 7 hari
    cout << "\n=== INPUT DATA MINGGUAN ===\n";

    for (int i = 0; i < 7; i++) {
        cout << "\nHari " << hari[i] << endl;

        cout << "Jam tidur: ";
        cin >> tidur[i];

        cout << "Jumlah gelas air: ";
        cin >> air[i];

        cout << "Olahraga (menit): ";
        cin >> olahraga[i];
    }

    // Menampilkan rekap mingguan
    cout << "\n========== REKAP MINGGUAN ==========\n";

    cout << left << setw(12) << "Hari"
         << setw(12) << "Tidur"
         << setw(12) << "Air"
         << setw(12) << "Olahraga" << endl;

    for (int i = 0; i < 7; i++) {
        cout << left << setw(12) << hari[i]
             << setw(12) << tidur[i]
             << setw(12) << air[i]
             << setw(12) << olahraga[i] << endl;
    }

    // Proses kalkulasi
    float rataTidur = hitungRataRata(tidur);
    float rataAir = hitungRataRata(air);
    float rataOlahraga = hitungRataRata(olahraga);
    float totalAir = hitungTotalAir(air);

    float skor = hitungSkor(tidur, air, olahraga);

    cout << "\n========== HASIL KALKULASI ==========\n";

    cout << "Rata-rata tidur: " << rataTidur << " jam\n";
    cout << "Rata-rata air: " << rataAir << " gelas\n";
    cout << "Total konsumsi air: " << totalAir << " gelas\n";
    cout << "Rata-rata olahraga: " << rataOlahraga << " menit\n";

    cout << "Skor kesehatan: " << skor << "%\n";

    // Analisis dan saran otomatis
    cout << "\n========== ANALISIS KESEHATAN ==========\n";

    if (rataTidur < 6) {
        cout << "Peringatan: Rata-rata tidur kurang dari 6 jam.\n";
        cout << "Saran: Perbaiki jadwal tidur dan istirahat cukup.\n";
    } else {
        cout << "Kebiasaan tidur cukup baik.\n";
    }

    if (rataAir < 8) {
        cout << "Peringatan: Konsumsi air masih kurang.\n";
        cout << "Saran: Tingkatkan konsumsi air putih.\n";
    } else {
        cout << "Konsumsi air sudah mencapai target.\n";
    }

    if (rataOlahraga < 30) {
        cout << "Peringatan: Aktivitas fisik masih minim.\n";
        cout << "Saran: Luangkan waktu untuk berolahraga.\n";
    } else {
        cout << "Aktivitas olahraga cukup baik.\n";
    }

    cout << "\nTerima kasih telah menggunakan program!\n";

    return 0;
}

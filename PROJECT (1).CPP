#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std;

float hitungRataRata(float data[]) {
    float total = 0;

    for (int i = 0; i < 7; i++) {
        total += data[i];
    }

    return total / 7;
}
float hitungTotalAir(float air[], int jumlah) {
    float total = 0;

    for (int i = 0; i < jumlah; i++) {
        total += air[i];
    }

    return total;
}

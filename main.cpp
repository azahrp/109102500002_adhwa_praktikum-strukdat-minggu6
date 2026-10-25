#include "Doublylist.h"

int main() {
    List L;
    infotype x;
    address P;
    CreateList(L);

    /* ===== Soal 1: input data kendaraan (4 kali input, seperti contoh output) ===== */
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi : ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan : ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan : ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            insertLast(L, alokasi(x));
        }
        cout << endl;
    }
    printInfo(L);

    /* ===== Soal 2: mencari elemen berdasarkan nomor polisi ===== */
    cout << endl << "Masukkan Nomor Polisi yang dicari : ";
    cin >> x.nopol;
    P = findElm(L, x);
    if (P != Nil) {
        cout << endl;
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    /* ===== Soal 3: menghapus elemen berdasarkan nomor polisi ===== */
    cout << endl << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> x.nopol;
    P = findElm(L, x);
    if (P == Nil) {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan." << endl;
    } else {
        address Q;
        if (P == L.First) {
            deleteFirst(L, Q);
        } else if (P == L.Last) {
            deleteLast(L, Q);
        } else {
            deleteAfter(P->prev, Q);
        }
        cout << "Data dengan nomor polisi " << Q->info.nopol << " berhasil dihapus." << endl;
        dealokasi(Q);
    }
    printInfo(L);

    return 0;
}
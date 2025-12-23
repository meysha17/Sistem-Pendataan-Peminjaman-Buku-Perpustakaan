#include "library.h"
#include <cctype>

static string toLowerStr(string s) {
    for (char &c : s) {
            c = (char)tolower((unsigned char)c);
    }
    return s;
}

void printInfoBuku(addrBuku P) {
    if (P != nullptr) {
        cout << "[ISBN: " << P->isbn << "] || " << P->judulBuku << " (" << P->tahunTerbit << ") || " << P->penulis << " || Stok: " << P->stock;
    }
}

void createListGenre(ListGenre &L) {
    L.first = nullptr;
}

void createListBuku(ListBuku &L)   {
    L.first = nullptr;
}

void createListRelasi(ListRelasi &L){
    L.first = nullptr;
}

addrGenre alokasiGenre(string nama) {
    addrGenre P = new ElmGenre;
    P->namaGenre = toLowerStr(nama);
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

addrBuku alokasiBuku(string judul, string isbn, string penulis, int tahun, int stock) {
    addrBuku P = new ElmBuku;
    P->judulBuku = judul;
    P->isbn = isbn;
    P->penulis = penulis;
    P->tahunTerbit = tahun;
    P->stock = stock;
    P->next = nullptr;
    return P;
}

addrRelasi alokasiRelasi(addrGenre P, addrBuku C) {
    addrRelasi R = new ElmRelasi;
    R->parent = P;
    R->child = C;
    R->next = nullptr;
    return R;
}

void insertGenre(ListGenre &L, addrGenre P) {
    if (!L.first) {
        L.first = P;
    }else {
        addrGenre Q = L.first;
        while (Q->next) Q = Q->next;
        Q->next = P; P->prev = Q;
    }
}

void deleteGenre(ListGenre &L, ListRelasi &LR, string nama) {
    addrGenre P = findGenre(L, nama);
    if (P) {
        addrRelasi R = LR.first;
        while (R) {
            addrRelasi nextR = R->next;
            if (R->parent == P) {
                deleteRelasi(LR, P, R->child);
            }
            R = nextR;
        }
        if (P == L.first) {
            L.first = P->next;
            if (L.first) {
                L.first->prev = nullptr;
            }
        } else {
            P->prev->next = P->next;
            if (P->next) {
                P->next->prev = P->prev;
            }
        }
        P->next = P->prev = nullptr;
        cout << "Genre '" << nama << "' dihapus." << endl;
    } else {
        cout << "Genre tidak ditemukan." << endl;
    }
}

addrGenre findGenre(ListGenre L, string nama) {
    string key = toLowerStr(nama);
    for (addrGenre P = L.first; P; P = P->next) {
        if (P->namaGenre == key) {
            return P;
        }
    }
    return nullptr;
}


void showAllGenre(ListGenre L) {
    if (L.first) {
        cout << "Daftar Genre:" << endl;
        for (addrGenre P = L.first; P; P = P->next) {
            cout << "- " << P->namaGenre << endl;
        }
    } else {
        cout << "Tidak ada Genre yang Terdaftar." << endl;
    }
}


int countGenreNoBuku(ListGenre LG, ListRelasi LR) {
    int count = 0;
    for (addrGenre P = LG.first; P; P = P->next) {
        bool ada = false;
        for (addrRelasi R = LR.first; R && !ada; R = R->next) {
            if (R->parent == P) {
                ada = true;
            }
        }
        if (!ada) {
            count++;
        }
    }
    return count;
}

void insertBuku(ListBuku &L, addrBuku P) {
    if (!L.first) {
        L.first = P;
    }else {
        addrBuku Q = L.first;
        while (Q->next) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

addrBuku findBuku(ListBuku L, string judul) {
    for (addrBuku P = L.first; P; P = P->next) {
        if (P->judulBuku == judul) {
            return P;
        }
    }
    return nullptr;
}


addrBuku findBukuByISBN(ListBuku L, string isbn) {
    for (addrBuku P = L.first; P; P = P->next) {
        if (P->isbn == isbn) {
            return P;
        }
    }
    return nullptr;
}


void deleteBuku(ListBuku &L, ListRelasi &LR, string judul) {
    addrBuku P = findBuku(L, judul);
    if (P == nullptr) {
        cout << "Buku tidak ditemukan." << endl;
    } else {
        // Hapus semua relasi yang mengacu ke buku P
        addrRelasi R = LR.first;
        addrRelasi prevR = nullptr;

        while (R != nullptr) {
            addrRelasi nextR = R->next;

            if (R->child == P) {
                if (prevR == nullptr) {
                    LR.first = nextR;
                } else {
                    prevR->next = nextR;
                }
                R->next = nullptr; // lepas relasi
            } else {
                prevR = R;
            }

            R = nextR;
        }
        // Lepaskan buku dari list
        if (L.first == P) {
            L.first = P->next;
        } else {
            addrBuku Q = L.first;
            while (Q != nullptr && Q->next != P) {
                Q = Q->next;
            }
            if (Q != nullptr) {
                Q->next = P->next;
            }
        }
        P->next = nullptr;
        cout << "Buku '" << judul << "' dihapus dari list." << endl;
    }
}

void showAllBuku(ListBuku L) {
    if (L.first) {
        cout << "Daftar Buku:" << endl;
        for (addrBuku P = L.first; P; P = P->next) {
            cout << "- ";
            printInfoBuku(P);
            cout << endl;
        }
    } else {
        cout << "List Buku Kosong." << endl;
    }
}

int countBukuNoGenre(ListBuku LB, ListRelasi LR) {
    int count = 0;
    for (addrBuku P = LB.first; P; P = P->next) {
        bool ada = false;
        for (addrRelasi R = LR.first; R && !ada; R = R->next) {
            if (R->child == P) {
                ada = true;
            }
        }
        if (!ada) {
            count++;
        }
    }
    return count;
}


void ubahStockBuku(ListBuku &L, string judul, int jumlah) {
    addrBuku P = findBuku(L, judul);
    if (P) {
        int hasil = P->stock + jumlah;
        if (hasil < 0) {
            cout << "Gagal: Stok tidak boleh negatif." << endl;
        } else {
            P->stock = hasil;
            cout << "Stok berhasil diperbaharui. Stok saat ini: " << P->stock << endl;
        }
    } else {
        cout << "Buku tidak ditemukan." << endl;
    }
}


void insertRelasi(ListRelasi &L, addrRelasi P) {
    P->next = nullptr;
    if (!L.first) {
        L.first = P;
    } else {
        addrRelasi Q = L.first;
        while (Q->next) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteRelasi(ListRelasi &L, addrGenre P, addrBuku C) {
    addrRelasi R = L.first;
    addrRelasi prev = nullptr;
    bool ditemukan = false;

    while (R && !ditemukan) {
        if (R->parent == P && R->child == C) {
            if (prev == nullptr) {
                L.first = R->next;
            } else {
                prev->next = R->next;
            }
            R->next = nullptr;
            ditemukan = true;
        } else {
            prev = R;
            R = R->next;
        }
    }
}


addrRelasi findRelasi(ListRelasi L, string namaGenre, string judulBuku) {
    string g = toLowerStr(namaGenre);
    for (addrRelasi R = L.first; R; R = R->next) {
        if (R->parent && R->child) {
            if (R->parent->namaGenre == g && R->child->judulBuku == judulBuku) {
                return R;
            }
        }
    }
    return nullptr;
}



void editRelasi(ListRelasi &L, string judulBuku, string genreLama, addrGenre genreBaru) {
    if (!genreBaru) {
        cout << "Gagal: Genre baru tidak valid." << endl;
        return;
    }
    addrRelasi R = findRelasi(L, genreLama, judulBuku);
    if (R) {
        R->parent = genreBaru;
        cout << "Buku '" << judulBuku << "' berubah genre dari '"
             << genreLama << "' ke '" << genreBaru->namaGenre << "'." << endl;
    } else {
        cout << "Gagal: Buku '" << judulBuku<< "' tidak ditemukan di genre '" << genreLama << "'." << endl;
    }
}

void showBukuByGenre(ListRelasi LR, string namaGenre) {
    string key = toLowerStr(namaGenre);
    cout << "Buku dengan Genre " << namaGenre << ":" << endl;
    bool ada = false;
    for (addrRelasi R = LR.first; R; R = R->next) {
        if (R->parent && R->child) {
            if (R->parent->namaGenre == key) {
                cout << "  -> ";
                printInfoBuku(R->child);
                cout << endl;
                ada = true;
            }
        }
    }
    if (!ada) {
        cout << "  (Tidak ada)" << endl;
    }
}

void showGenreByBuku(ListRelasi LR, string judulBuku) {
    cout << "Genre dari Buku " << judulBuku << ": ";
    bool ada = false;
    bool first = true;
    for (addrRelasi R = LR.first; R; R = R->next) {
        if (R->child && R->parent) {
            if (R->child->judulBuku == judulBuku) {
                if (!first) {
                    cout << ", ";
                }
                cout << R->parent->namaGenre;
                ada = true;
                first = false;
            }
        }
    }
    if (!ada) {
        cout << "Tidak ada";
    }
    cout << endl;
}


void showAllGenreWithBuku(ListGenre LG, ListRelasi LR) {
    cout << "\n=== DAFTAR GENRE BESERTA BUKUNYA ===" << endl;
    if (LG.first) {
        for (addrGenre P = LG.first; P; P = P->next) {
            cout << "Genre: " << P->namaGenre << endl;
            bool adaBuku = false;
            for (addrRelasi R = LR.first; R; R = R->next) {
                if (R->parent && R->child) {
                    if (R->parent == P) {
                        cout << "  - ";
                        printInfoBuku(R->child);
                        cout << endl;
                        adaBuku = true;
                    }
                }
            }
            if (!adaBuku) {
                cout << "  Tidak ada buku." << endl;
            }
            cout << "-------------------------" << endl;
        }
    } else {
        cout << "Belum ada data Genre." << endl;
    }
}

void showAllBukuWithGenre(ListBuku LB, ListRelasi LR) {
    cout << "\n=== DAFTAR BUKU BESERTA GENRENYA ===" << endl;
    if (LB.first) {
        for (addrBuku P = LB.first; P; P = P->next) {
            cout << "Buku: ";
            printInfoBuku(P);
            cout << endl;
            bool adaGenre = false;
            for (addrRelasi R = LR.first; R; R = R->next) {
                if (R->child && R->parent) {
                    if (R->child == P) {
                        cout << "  - Genre: " << R->parent->namaGenre << endl;
                        adaGenre = true;
                    }
                }
            }
            if (!adaGenre) {
                cout << "  (Tidak ada genre)" << endl;
            }
            cout << "-------------------------" << endl;
        }
    } else {
        cout << "Belum ada data Buku." << endl;
    }
}


int countBukuFromGenre(ListRelasi LR, string namaGenre) {
    int count = 0;
    string key = toLowerStr(namaGenre);
    for (addrRelasi R = LR.first; R; R = R->next) {
        if (R->parent) {
            if (toLowerStr(R->parent->namaGenre) == key) {
                count++;
            }
        }
    }
    return count;
}


int countGenreFromBuku(ListRelasi LR, string judulBuku) {
    int count = 0;
    for (addrRelasi R = LR.first; R; R = R->next) {
        if (R->child) {
            if (R->child->judulBuku == judulBuku) {
                count++;
            }
        }
    }
    return count;
}


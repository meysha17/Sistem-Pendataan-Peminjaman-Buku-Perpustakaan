#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

typedef struct ElmGenre *addrGenre;
struct ElmGenre {
    string namaGenre;
    addrGenre next;
    addrGenre prev;
};

struct ListGenre {
    addrGenre first;
};

typedef struct ElmBuku *addrBuku;
struct ElmBuku {
    string judulBuku;
    string isbn;
    string penulis;
    int tahunTerbit;
    int stock;
    addrBuku next;
};

struct ListBuku {
    addrBuku first;
};

typedef struct ElmRelasi *addrRelasi;
struct ElmRelasi {
    addrGenre parent;
    addrBuku child;
    addrRelasi next;
};

struct ListRelasi {
    addrRelasi first;
};

void createListGenre(ListGenre &L);
void createListBuku(ListBuku &L);
void createListRelasi(ListRelasi &L);

addrGenre alokasiGenre(string nama);
addrBuku alokasiBuku(string judul, string isbn, string penulis, int tahun, int stock);
addrRelasi alokasiRelasi(addrGenre P, addrBuku C);

//list parent
void insertGenre(ListGenre &L, addrGenre P);
void deleteGenre(ListGenre &L, ListRelasi &LR, string nama);
addrGenre findGenre(ListGenre L, string nama);
void showAllGenre(ListGenre L);
int countGenreNoBuku(ListGenre LG, ListRelasi LR);

//list child
void insertBuku(ListBuku &L, addrBuku P);
void deleteBuku(ListBuku &L, ListRelasi &LR, string judul);
addrBuku findBuku(ListBuku L, string judul);
addrBuku findBukuByISBN(ListBuku L, string isbn);
void showAllBuku(ListBuku L);
int countBukuNoGenre(ListBuku LB, ListRelasi LR);
void ubahStockBuku(ListBuku &L, string judul, int jumlah);

//list relasi
void insertRelasi(ListRelasi &L, addrRelasi P);
void deleteRelasi(ListRelasi &L, addrGenre P, addrBuku C);
addrRelasi findRelasi(ListRelasi L, string namaGenre, string judulBuku);
void editRelasi(ListRelasi &L, string judulBuku, string genreLama, addrGenre genreBaru);

void showBukuByGenre(ListRelasi LR, string namaGenre);
void showGenreByBuku(ListRelasi LR, string judulBuku);
void showAllGenreWithBuku(ListGenre LG, ListRelasi LR);
void showAllBukuWithGenre(ListBuku LB, ListRelasi LR);
int countBukuFromGenre(ListRelasi LR, string namaGenre);
int countGenreFromBuku(ListRelasi LR, string judulBuku);

void printInfoBuku(addrBuku P);

#endif


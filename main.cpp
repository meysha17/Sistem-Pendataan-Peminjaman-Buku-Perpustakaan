
#include <iostream>
#include <string>
#include "library.h"
using namespace std;

int main() {
    ListGenre LG;
    ListBuku LB;
    ListRelasi LR;

    createListGenre(LG);
    createListBuku(LB);
    createListRelasi(LR);

    int defaultStock = 5;

    // ===== INSERT GENRE =====
    insertGenre(LG, alokasiGenre("Fantasy"));
    insertGenre(LG, alokasiGenre("Romance"));
    insertGenre(LG, alokasiGenre("Sci-Fi"));
    insertGenre(LG, alokasiGenre("History"));
    insertGenre(LG, alokasiGenre("Horror"));
    insertGenre(LG, alokasiGenre("Drama"));
    insertGenre(LG, alokasiGenre("Sosial"));
    insertGenre(LG, alokasiGenre("Psychological Thriller"));

    // ===== POINTER GENRE =====
    addrGenre gFantasy = findGenre(LG, "fantasy");
    addrGenre gRomance = findGenre(LG, "romance");
    addrGenre gSciFi   = findGenre(LG, "sci-fi");
    addrGenre gHistory = findGenre(LG, "history");
    addrGenre gHorror  = findGenre(LG, "horror");
    addrGenre gDrama   = findGenre(LG, "drama");
    addrGenre gSosial  = findGenre(LG, "sosial");
    addrGenre gPsyThr  = findGenre(LG, "psychological thriller");

    // ===== INSERT 15 BUKU =====
    insertBuku(LB, alokasiBuku("The Lord of the Rings", "B001", "JRR Tolkien", 1954, defaultStock));
    insertBuku(LB, alokasiBuku("A Game Of Thrones", "B002", "George RR Martin", 1996, defaultStock));
    insertBuku(LB, alokasiBuku("The Colour Of Magic", "B003", "Terry Pratchett", 1983, defaultStock));
    insertBuku(LB, alokasiBuku("American Gods", "B004", "Neil Gaiman", 2001, defaultStock));
    insertBuku(LB, alokasiBuku("The Name of the Wind", "B005", "Patrick Rothfuss", 2007, defaultStock));
    insertBuku(LB, alokasiBuku("The Devil All the Time", "B006", "Donald Ray Pollock", 2011, defaultStock));
    insertBuku(LB, alokasiBuku("Arwah", "B007", "Jounatan & Guntur Alam", 2017, defaultStock));
    insertBuku(LB, alokasiBuku("Hendrick: Konnings", "B008", "Risa Saraswati", 2016, defaultStock));
    insertBuku(LB, alokasiBuku("Dracula", "B009", "Bram Stoker", 1897, defaultStock));
    insertBuku(LB, alokasiBuku("Annihilation", "B010", "Jeff VanderMeer", 2014, defaultStock));
    insertBuku(LB, alokasiBuku("Dune", "B011", "Frank Herbert", 1965, defaultStock));
    insertBuku(LB, alokasiBuku("Foundation", "B012", "Isaac Asimov", 1951, defaultStock));
    insertBuku(LB, alokasiBuku("War and Peace", "B014", "Leo Tolstoy", 1869, defaultStock));
    insertBuku(LB, alokasiBuku("Gone with the Wind", "B016", "Margaret Mitchell", 1936, defaultStock));
    insertBuku(LB, alokasiBuku("To Kill a Mockingbird", "B019", "Harper Lee", 1960, defaultStock));

    // ===== INSERT RELASI =====
    insertRelasi(LR, alokasiRelasi(gFantasy, findBukuByISBN(LB, "B001")));
    insertRelasi(LR, alokasiRelasi(gHistory, findBukuByISBN(LB, "B001")));

    insertRelasi(LR, alokasiRelasi(gFantasy, findBukuByISBN(LB, "B002")));
    insertRelasi(LR, alokasiRelasi(gHistory, findBukuByISBN(LB, "B002")));

    insertRelasi(LR, alokasiRelasi(gFantasy, findBukuByISBN(LB, "B003")));

    insertRelasi(LR, alokasiRelasi(gFantasy, findBukuByISBN(LB, "B004")));
    insertRelasi(LR, alokasiRelasi(gHorror,  findBukuByISBN(LB, "B004")));

    insertRelasi(LR, alokasiRelasi(gFantasy, findBukuByISBN(LB, "B005")));
    insertRelasi(LR, alokasiRelasi(gRomance, findBukuByISBN(LB, "B005")));

    insertRelasi(LR, alokasiRelasi(gHorror,  findBukuByISBN(LB, "B006")));
    insertRelasi(LR, alokasiRelasi(gPsyThr,  findBukuByISBN(LB, "B006")));

    insertRelasi(LR, alokasiRelasi(gHorror, findBukuByISBN(LB, "B007")));
    insertRelasi(LR, alokasiRelasi(gHorror, findBukuByISBN(LB, "B008")));

    insertRelasi(LR, alokasiRelasi(gHorror,  findBukuByISBN(LB, "B009")));
    insertRelasi(LR, alokasiRelasi(gRomance, findBukuByISBN(LB, "B009")));

    insertRelasi(LR, alokasiRelasi(gHorror, findBukuByISBN(LB, "B010")));
    insertRelasi(LR, alokasiRelasi(gSciFi,  findBukuByISBN(LB, "B010")));
    insertRelasi(LR, alokasiRelasi(gPsyThr, findBukuByISBN(LB, "B010")));

    insertRelasi(LR, alokasiRelasi(gSciFi, findBukuByISBN(LB, "B011")));
    insertRelasi(LR, alokasiRelasi(gSciFi, findBukuByISBN(LB, "B012")));

    insertRelasi(LR, alokasiRelasi(gHistory, findBukuByISBN(LB, "B014")));

    insertRelasi(LR, alokasiRelasi(gHistory, findBukuByISBN(LB, "B016")));
    insertRelasi(LR, alokasiRelasi(gDrama,   findBukuByISBN(LB, "B016")));
    insertRelasi(LR, alokasiRelasi(gRomance, findBukuByISBN(LB, "B016")));

    insertRelasi(LR, alokasiRelasi(gDrama,  findBukuByISBN(LB, "B019")));
    insertRelasi(LR, alokasiRelasi(gSosial, findBukuByISBN(LB, "B019")));




    int pilihan = -1;
    string inGenre, inBuku, inISBN, inPenulis, inGenreBaru, inBukuBaru;
    int inTahun, inStock, inJmlUpdate;

    addrGenre P_Genre = nullptr;
    addrBuku P_Buku = nullptr;

    bool isRunning = true;

    while (isRunning) {
        cout << "\n==============================================" << endl;
        cout << "           DATA BUKU PERPUSTAKAAN                 " << endl;
        cout << "==============================================" << endl;
        cout << "1.  Insert Genre" << endl;
        cout << "2.  Insert Buku" << endl;
        cout << "3.  Insert Relasi" << endl;
        cout << "4.  Hapus Genre" << endl;
        cout << "5.  Hapus Buku" << endl;
        cout << "6.  Hapus Relasi" << endl;
        cout << "7.  Cari Genre" << endl;
        cout << "8.  Cari Buku" << endl;
        cout << "9.  Cari Relasi" << endl;
        cout << "10. Tampilkan semua Genre" << endl;
        cout << "11. Tampilkan semua Buku" << endl;
        cout << "12. Tampilkan Buku dari Genre Tertentu" << endl;
        cout << "13. Tampilkan Genre dari Buku Tertentu" << endl;
        cout << "14. Tampilkan Genre beserta bukunya" << endl;
        cout << "15. Tampilkan Buku beserta genrenya" << endl;
        cout << "16. Jumlah Buku di Genre Tertentu" << endl;
        cout << "17. Jumlah Genre di Buku Tertentu" << endl;
        cout << "18. Jumlah Buku Tanpa Genre" << endl;
        cout << "19. Jumlah Genre Tanpa Buku" << endl;
        cout << "20. Edit Relasi" << endl;
        cout << "21. Update Stock Buku (Tambah/Kurang)" << endl;
        cout << "0.  Selesai" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << "----------------------------------------------" << endl;

        if (pilihan == 0) {
            isRunning = false;
            cout << "Selesai" << endl;
        }
        else if (pilihan == 1) {
            cout << "Masukkan Nama Genre: ";
            cin >> inGenre;
            if (findGenre(LG, inGenre) == nullptr) {
                insertGenre(LG, alokasiGenre(inGenre));
                cout << "Genre berhasil ditambahkan." << endl;
            } else {
                cout << "Genre sudah ada!" << endl;
            }
        }
        else if (pilihan == 2) {
            cout << "Masukkan Judul Buku: ";
            cin >> inBuku;
            if (findBuku(LB, inBuku) == nullptr) {
                cout << "Masukkan ISBN: ";
                cin >> inISBN;
                while (findBukuByISBN(LB, inISBN) != nullptr) {
                    cout << "GAGAL: ISBN '" << inISBN << "' sudah dipakai buku lain!" << endl;
                    cout << "Masukkan ISBN yang berbeda: ";
                    cin >> inISBN;
                }
                cout << "Nama Penulis: ";
                cin >> inPenulis;
                cout << "Tahun Terbit: ";
                cin >> inTahun;
                cout << "Stock: ";
                cin >> inStock;

                insertBuku(LB, alokasiBuku(inBuku, inISBN, inPenulis, inTahun, inStock));
                cout << "Buku berhasil ditambahkan." << endl;
            } else {
                cout << "Judul Buku sudah ada!" << endl;
            }
        }
        else if (pilihan == 3) {
            cout << "Masukkan Genre: ";
            cin >> inGenre;
            cout << "Masukkan Buku: ";
            cin >> inBuku;
            P_Genre = findGenre(LG, inGenre);
            P_Buku = findBuku(LB, inBuku);
            if (P_Genre != nullptr && P_Buku != nullptr) {
                if (findRelasi(LR, inGenre, inBuku) == nullptr) {
                    insertRelasi(LR, alokasiRelasi(P_Genre, P_Buku));
                    cout << "Relasi buku dan genre selesai ditambahkan." << endl;
                } else {
                    cout << "Relasi sudah ada sebelumnya." << endl;
                }
            } else {
                cout << "Genre atau Buku tidak ditemukan." << endl;
            }
        }
        else if (pilihan == 4) {
            cout << "Masukkan Genre yang ingin dihapus: ";
            cin >> inGenre;
            deleteGenre(LG, LR, inGenre);
        }
        else if (pilihan == 5) {
            cout << "Masukkan Buku yang ingin dihapus: ";
            cin >> inBuku;
            deleteBuku(LB, LR, inBuku);
        }
        else if (pilihan == 6) {
            cout << "Hapus Relasi Genre: ";
            cin >> inGenre;
            cout << "Hapus Relasi Buku: ";
            cin >> inBuku;
            P_Genre = findGenre(LG, inGenre);
            P_Buku = findBuku(LB, inBuku);
            if (P_Genre && P_Buku) {
                deleteRelasi(LR, P_Genre, P_Buku);
                cout << "Relasi dihapus." << endl;
            } else {
                cout << "Data tidak valid." << endl;
            }
        }
        else if (pilihan == 7) {
            cout << "Cari Genre: ";
            cin >> inGenre;
            if(findGenre(LG, inGenre)) {
                cout << "Genre Ditemukan.\n";
            } else {
                cout << "Genre Tidak Ditemukan.\n";
            }
        }
        else if (pilihan == 8) {
            cout << "Cari Buku: ";
            cin >> inBuku;
            P_Buku = findBuku(LB, inBuku);
            if(P_Buku != nullptr) {
                cout << "Ditemukan: ";
                printInfoBuku(P_Buku);
                cout << endl;
            } else {
                cout << "Buku Tidak Ditemukan.\n";
            }
        }else if (pilihan == 9) {
            cout << "Cari Relasi Genre: ";
            cin >> inGenre;
            cout << "Cari Relasi Buku: ";
            cin >> inBuku;
            if(findRelasi(LR, inGenre, inBuku)) {
                cout << "Relasi ada.\n";
                }else {
                    cout << "Relasi tidak ada.\n";
            }
        }else if (pilihan == 10) {
            showAllGenre(LG);

        }else if (pilihan == 11) {
            showAllBuku(LB);
        }else if (pilihan == 12) {
            cout << "Masukkan Genre: ";
            cin >> inGenre;
            showBukuByGenre(LR, inGenre);
        }else if (pilihan == 13) {
            cout << "Masukkan Buku: ";
            cin >> inBuku;
            showGenreByBuku(LR, inBuku);
        }else if (pilihan == 14) {
            showAllGenreWithBuku(LG, LR);
        }else if (pilihan == 15) {
            showAllBukuWithGenre(LB, LR);
        }else if (pilihan == 16) {
            cout << "Genre: "; cin >> inGenre;
            if (findGenre(LG, inGenre) != nullptr) {
                cout << "Jumlah Buku: " << countBukuFromGenre(LR, inGenre) << endl;
            }else {
                cout << "Genre tidak ditemukan/belum terdaftar." << endl;
            }
        }else if (pilihan == 17) {
            cout << "Buku: ";
            cin >> inBuku;
            if (findBuku(LB, inBuku) != nullptr) {
                cout << "Jumlah Genre: " << countGenreFromBuku(LR, inBuku) << endl;
            } else {
                cout << "Buku tidak ditemukan/belum terdaftar." << endl;
            }
        }else if (pilihan == 18) {
            cout << "Jumlah Buku Tanpa Genre: " << countBukuNoGenre(LB, LR) << endl;
        }else if (pilihan == 19) {
            cout << "Jumlah Genre Tanpa Buku: " << countGenreNoBuku(LG, LR) << endl;
        }else if (pilihan == 20) {
            cout << "--- EDIT GENRE BUKU ---" << endl;
            cout << "Judul Buku: ";
            cin >> inBuku;
            cout << "Genre yang mau diganti: ";
            cin >> inGenre;
            cout << "Genre Baru: ";
            cin >> inGenreBaru;
            addrGenre P_GenreBaru = findGenre(LG, inGenreBaru);

            if (P_GenreBaru != nullptr) {
                editRelasi(LR, inBuku, inGenre, P_GenreBaru);
            } else {
                cout << "Gagal: Genre baru '" << inGenreBaru << "' belum terdaftar. Insert dulu!" << endl;
            }
        }else if (pilihan == 21) {
            cout << "Masukkan Judul Buku: ";
            cin >> inBuku;
            cout << "Masukkan Jumlah (Positif bertambah, Negatif berkurang): ";
            cin >> inJmlUpdate;
            ubahStockBuku(LB, inBuku, inJmlUpdate);
        }else {
            cout << "Pilihan tidak valid." << endl;
        }
    }
    return 0;
}

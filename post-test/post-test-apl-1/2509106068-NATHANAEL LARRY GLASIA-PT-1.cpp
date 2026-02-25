#include <iostream>
using namespace std;

int main(){
    string nama, nama_benar;
    string password, password_benar;
    float jam, menit, detik;
    int percobaan_login, pilihan;
    nama_benar = "Larry";
    password_benar = "068";
    percobaan_login = 0;
    while (percobaan_login < 3){
    cout << "==========================================\n";
    cout << "      LOGIN PROGRAM KONVERSI WAKTU        \n"; 
    cout << "==========================================\n"; 
    cout << "Masukkan nama (Panggilan saja): "; cin >> nama;
    cout << "Masukkan password (3 digit terakhir NIM): "; cin >> password;

    if (nama == nama_benar && password == password_benar){
        cout << "Login berhasil! Selamat datang " << nama << endl; 
        break;
    }else{
        cout << "Login gagal! ";
        percobaan_login++;
        cout << "Percobaan login: " << (3 - percobaan_login) << endl;
    }
}
if (percobaan_login == 3){
    cout << "Gagal login 3 kali. Program berhenti!" << endl;
    return 0;
}

do{ 
    cout << "\n====================================" << endl;
    cout << "          MENU KONVERSI WAKTU       " << endl;
    cout << "====================================" << endl;
    cout << "1. Konversi Jam -> Menit & Detik" << endl;
    cout << "2. Konversi Menit -> Jam & Detik" << endl;
    cout << "3. Konversi Detik -> Jam & Menit" << endl;
    cout << "4. Keluar dari Program" << endl;
    cout << "====================================" << endl;

    cout << "Masukkan pilihan (1-4): ";
    cin >> pilihan;

    if (pilihan == 1){
        cout << "\n===========================" << endl;
        cout << "   JAM -> MENIT & DETIK   " << endl;
        cout << "===========================" << endl;
        cout << "Masukkan jumlah jam: "; cin >> jam;
        menit = jam*60;
        detik = jam*3600;
        cout << jam << " Jam = " << menit << " menit dan " << detik << " detik " << endl;
    }else if (pilihan == 2){
        cout << "\n==========================" << endl;
        cout << "   MENIT -> JAM & DETIK   " << endl;
        cout << "==========================" << endl;
        cout << "Masukkan jumlah menit: "; cin >> menit;
        jam = menit/60;
        detik = menit*60;
        cout << menit << " Menit = " << jam << " jam dan " << detik << " detik " << endl;
    }else if (pilihan == 3){
        cout << "\n==========================" << endl;
        cout << "   DETIK -> JAM & MENIT   " << endl;
        cout << "==========================" << endl;
        cout << "Masukkan jumlah detik: "; cin >> detik;
        jam = detik/3600;
        menit = detik/60;
        cout << detik << " Detik = " << jam << " jam dan " << menit << " menit " << endl; 
    }else if(pilihan == 4){
        cout << "\n================" << endl;
        cout << "PROGRAM SELESAI." << endl;
        cout << "================" << endl;
        break;
    }else{
        cout << "Pilihan tidak valid" << endl;
    }
    }while (pilihan != 4);
return 0;
}
#include <iostream>
#include <string>
using namespace std;

struct User
{
    string username;
    string password;
    string role;
};

struct StatusKamera
{
    string kondisi;
};

struct Kamera
{
    string ID_Kamera;
    string NamaKamera;
    int HargaSewa;
    int LamaSewa;
    string NamaPenyewa;
    StatusKamera status;
};

int main()
{
    Kamera data[5];
    User user[2];
    int JumlahUser = 0;
    int JumlahData = 0;
    user[JumlahUser].username = "TWISTERSIAN";
    user[JumlahUser].password = "123Action";
    user[JumlahUser].role = "admin";
    JumlahUser++;
    bool menu_awal = true;

    while (menu_awal)
    {
        bool login_sukses = false;
        int percobaan_login = 0;
        string InputNama, InputPassword, role_login;
        int MenuAwal;

        while (!login_sukses)
        {
            cout << "\n======================" << endl;
            cout << "HOME PAGE TWISTERS CAM" << endl;
            cout << "======================" << endl;
            cout << "1. Register" << endl;
            cout << "2. Login" << endl;
            cout << "3. Keluar Twisters Cam" << endl;
            cout << "======================" << endl;
            cout << "Pilih (1-3): ";
            cin >> MenuAwal;
            cin.ignore();

            if (MenuAwal == 1)
            {
                if (JumlahUser == 2)
                {
                    cout << "User penuh!\n";
                }
                else
                {
                    cout << "\n===REGISTER===" << endl;
                    cout << "Masukkan nama baru: ";
                    getline(cin, user[JumlahUser].username);
                    cout << "Masukkan password baru: ";
                    getline(cin, user[JumlahUser].password);
                    user[JumlahUser].role = "user";
                    JumlahUser++;
                    cout << "Berhasil daftar, silakan login ke Twisters Cam.\n";
                }
            }
            else if (MenuAwal == 2)
            {
                while (percobaan_login < 3 && !login_sukses)
                {
                    cout << "\n===LOGIN===" << endl;
                    cout << "Masukkan nama: ";
                    getline(cin, InputNama);
                    cout << "Masukkan password: ";
                    getline(cin, InputPassword);

                    for (int i = 0; i < JumlahUser; i++)
                    {
                        if (InputNama == user[i].username && InputPassword == user[i].password)
                        {
                            cout << "Login berhasil! Selamat datang " << InputNama << endl;
                            login_sukses = true;
                            role_login = user[i].role;
                            break;
                        }
                    }
                    if (!login_sukses)
                    {
                        percobaan_login++;
                        cout << "Login gagal! Kesempatan login: " << (3 - percobaan_login) << endl;
                    }
                }
                if (percobaan_login == 3 && !login_sukses)
                {
                    cout << "Akses ditolak!" << endl;
                    return 0;
                }
            }
            else if (MenuAwal == 3)
            {
                cout << "\n==================" << endl;
                cout << "  PROGRAM SELESAI " << endl;
                cout << "==================" << endl;
                return 0;
            }
            else
            {
                cout << "Pilihan tidak valid" << endl;
            }
        }
    
        int pilihan;
        do
        {
            if (role_login == "admin")
            {
                cout << "\n========================" << endl;
                cout << "      TWISTERS CAM      " << endl;
                cout << "========================" << endl;
                cout << "1. Tambahkan data kamera" << endl;
                cout << "2. Tampilkan data kamera" << endl;
                cout << "3. Ubah data kamera" << endl;
                cout << "4. Hapus data kamera" << endl;
                cout << "5. Keluar ke menu utama" << endl;
            }
            else
            {   cout << "\n===========================" << endl;
                cout << "         TWISTERS CAM      " << endl;
                cout << "===========================" << endl;
                cout << "1. Lihat data kamera" << endl;
                cout << "2. Sewa kamera" << endl;
                cout << "3. Kembalikan kamera" << endl;
                cout << "4. Keluar ke menu utama" << endl;
            }
            cout << "=========================" << endl;
            cout << "Masukkan pilihan: ";
            cin >> pilihan;
            cin.ignore();

            if (role_login == "admin")
            {

                switch (pilihan)
                {
                case 1:
                    if (JumlahData == 5)
                    {
                        cout << "Data Penuh!\n";
                        break;
                    }
                    cout << "\n========================================================================================" << endl;
                    cout << "                               TAMBAH DATA KAMERA                                       " << endl;
                    cout << "========================================================================================" << endl;
                    cout << "ID Kamera: ";
                    getline(cin, data[JumlahData].ID_Kamera);
                    cout << "Nama Kamera: ";
                    getline(cin, data[JumlahData].NamaKamera);
                    cout << "Harga sewa/hari: Rp";
                    cin >> data[JumlahData].HargaSewa;
                    cin.ignore();
                    cout << "Status (Tersedia/Disewa): ";
                    getline(cin, data[JumlahData].status.kondisi);
                    JumlahData++;
                    cout << "Data berhasil ditambahkan";
                    cout << endl;
                    break;

                case 2:
                    cout << "\n========================================================================================" << endl;
                    cout << "|                               DATA KAMERA TWISTERS CAM                               |" << endl;
                    cout << "========================================================================================" << endl;
                    if (JumlahData == 0)
                    {
                        cout << "Data kamera tidak tersedia";
                        break;
                    }
                    cout << "No\tID Kamera\tNama Kamera\t\tHarga Sewa/hari\t\t\tStatus\n";
                    cout << "----------------------------------------------------------------------------------------\n";
                    for (int i = 0; i < JumlahData; i++)
                    {
                        cout << i + 1 << "\t";
                        cout << data[i].ID_Kamera << "\t\t";
                        cout << data[i].NamaKamera << " \t\t";
                        cout << "Rp" << data[i].HargaSewa << "\t\t\t";
                        cout << data[i].status.kondisi << endl;
                        cout << endl;
                    }
                    break;

                case 3:
                {
                    cout << "\n========================================================================================" << endl;
                    cout << "|                               UBAH DATA KAMERA                                       |" << endl;
                    cout << "========================================================================================" << endl;
                    if (JumlahData == 0)
                    {
                        cout << "Data kamera belum tersedia!";
                        break;
                    }
                    cout << "No\tID Kamera\tNama Kamera\t\tHarga Sewa/hari\t\t\tStatus\n";
                    cout << "----------------------------------------------------------------------------------------\n";
                    for (int i = 0; i < JumlahData; i++)
                    {
                        cout << i + 1 << "\t";
                        cout << data[i].ID_Kamera << "\t\t";
                        cout << data[i].NamaKamera << " \t\t";
                        cout << "Rp" << data[i].HargaSewa << "\t\t\t";
                        cout << data[i].status.kondisi << endl;
                        cout << endl;
                    }
                    int index;
                    cout << "Masukkan nomor data yang ingin diubah: ";
                    cin >> index;
                    cin.ignore();
                    index--;

                    if (index >= 0 && index < JumlahData)
                    {
                        cout << "ID Kamera baru: ";
                        getline(cin, data[index].ID_Kamera);
                        cout << "Nama Kamera baru: ";
                        getline(cin, data[index].NamaKamera);
                        cout << "Harga sewa/hari: Rp";
                        cin >> data[index].HargaSewa;
                        cin.ignore();
                        cout << "Status (Tersedia/Disewa): ";
                        getline(cin, data[index].status.kondisi);
                        cout << "Data kamera berhasil diubah!\n";
                    }
                    else
                    {
                        cout << "Nomor tidak valid!";
                    }
                    break;
                }
                case 4:
                {
                    cout << "\n========================================================================================" << endl;
                    cout << "|                                 HAPUS DATA KAMERA                                     |" << endl;
                    cout << "========================================================================================" << endl;
                    if (JumlahData == 0)
                    {
                        cout << "Data kamera belum tersedia!";
                        break;
                    }
                    cout << "No\tID Kamera\tNama Kamera\t\tHarga Sewa/hari\t\t\tStatus\n";
                    cout << "----------------------------------------------------------------------------------------\n";
                    for (int i = 0; i < JumlahData; i++)
                    {
                        cout << i + 1 << "\t";
                        cout << data[i].ID_Kamera << "\t\t";
                        cout << data[i].NamaKamera << " \t\t";
                        cout << "Rp" << data[i].HargaSewa << "\t\t\t";
                        cout << data[i].status.kondisi << endl;
                    }
                    int index;
                    char konfirmasi_hapus;
                    cout << "Masukkan nomor data kamera yang ingin dihapus: ";
                    cin >> index;
                    index--;

                    if (index >= 0 && index < JumlahData)
                    {
                        cout << "Yakin ingin hapus data kamera ini? (Y/N): ";
                        cin >> konfirmasi_hapus;

                        if (konfirmasi_hapus == 'Y' || konfirmasi_hapus == 'y')
                        {
                            for (int i = index; i < JumlahData - 1; i++)
                            {
                                data[i] = data[i + 1];
                            }
                            JumlahData--;
                            cout << "Data kamera berhasil dihapus!\n";
                        }
                        else
                        {
                            cout << "Penghapusan dibatalkan!\n";
                        }
                    }
                    else
                    {
                        cout << "Nomor tidak valid!\n";
                    }
                    break;
                }
                case 5:
                    cout << "==========================================" << endl;
                    cout << "           KEMBALI KE MENU AWAL...        " << endl;
                    cout << "==========================================" << endl;
                    login_sukses = false;
                    break;

                default:
                    cout << "Pilihan tidak tersedia!";
                    break;
                }
            }
            else
            {
                switch (pilihan)
                {
                case 1:
                    if (JumlahData == 0)
                    {
                        cout << "Data kamera belum tersedia!";
                        break;
                    }
                    cout << "\n========================================================================================" << endl;
                    cout << "|                               DATA KAMERA TWISTERS CAM                               |" << endl;
                    cout << "========================================================================================" << endl;
                    cout << "No\tID Kamera\tNama Kamera\t\tHarga Sewa/hari\t\t\tStatus\n";
                    cout << "----------------------------------------------------------------------------------------\n";
                    for (int i = 0; i < JumlahData; i++)
                    {
                        cout << i + 1 << "\t";
                        cout << data[i].ID_Kamera << "\t\t";
                        cout << data[i].NamaKamera << " \t\t";
                        cout << "Rp" << data[i].HargaSewa << "\t\t\t";
                        cout << data[i].status.kondisi << endl;
                        cout << endl;
                    }
                    break;

                case 2:
                {
                    if (JumlahData == 0)
                    {
                        cout << "Data kamera tidak tersedia!";
                        break;
                    }
                    cout << "\n========================================================================================" << endl;
                    cout << "|                               DATA KAMERA TWISTERS CAM                               |" << endl;
                    cout << "========================================================================================" << endl;
                    cout << "No\tID Kamera\tNama Kamera\t\tHarga Sewa/hari\t\t\tStatus\n";
                    cout << "----------------------------------------------------------------------------------------\n";
                    for (int i = 0; i < JumlahData; i++)
                    {
                        cout << i + 1 << "\t";
                        cout << data[i].ID_Kamera << "\t\t";
                        cout << data[i].NamaKamera << " \t\t";
                        cout << "Rp" << data[i].HargaSewa << "\t\t\t";
                        cout << data[i].status.kondisi << endl;
                        cout << endl;
                    }
                    int pilih;
                    cout << "Masukkan nomor kamera yang ingin disewa: ";
                    cin >> pilih;
                    pilih--;

                    if (pilih >= 0 && pilih < JumlahData)
                    {
                        if (data[pilih].status.kondisi == "Tersedia")
                        {
                            cout << "Sewa berapa hari: ";
                            cin >> data[pilih].LamaSewa;
                            data[pilih].status.kondisi = "Disewa";
                            data[pilih].NamaPenyewa = InputNama;
                            cout << "Kamera berhasil disewa!\n";
                        }
                        else
                        {
                            cout << "Kamera sedang disewa!\n";
                        }
                    }
                    else
                    {
                        cout << "Nomor tidak valid\n";
                    }
                    break;
                }
                case 3:
                {
                    if (JumlahData == 0)
                    {
                        cout << "Data kamera tidak tersedia!";
                        break;
                    }
                    cout << "\n========================================================================================" << endl;
                    cout << "|                               DATA KAMERA YANG DISEWA                               |" << endl;
                    cout << "========================================================================================" << endl;
                    cout << "No\tID Kamera\tNama Kamera\t\tHarga Sewa/hari\t\t\tStatus\n";
                    cout << "----------------------------------------------------------------------------------------\n";
                    for (int i = 0; i < JumlahData; i++)
                    {
                        if (data[i].status.kondisi == "Disewa")
                        {
                            cout << i + 1 << "\t";
                            cout << data[i].ID_Kamera << "\t\t";
                            cout << data[i].NamaKamera << " \t\t";
                            cout << "Rp" << data[i].HargaSewa << "\t\t\t";
                            cout << data[i].status.kondisi << endl;
                            cout << endl;
                        }
                    }
                    int pilih;
                    cout << "Masukkan nomor kamera yang Anda sewa: ";
                    cin >> pilih;
                    pilih--;

                    if (pilih >= 0 && pilih < JumlahData)
                    {
                        if (data[pilih].status.kondisi == "Disewa" && data[pilih].NamaPenyewa == InputNama)
                        {
                            int totalharga = data[pilih].HargaSewa * data[pilih].LamaSewa;
                            cout << "\n===STRUK SEWA KAMERA===" << endl;
                            cout << "ID Kamera: " << data[pilih].ID_Kamera << endl;
                            cout << "Nama Kamera: " << data[pilih].NamaKamera << endl;
                            cout << "Harga sewa/hari: Rp" << data[pilih].HargaSewa << endl;
                            cout << "Lama sewa: " << data[pilih].LamaSewa << " hari" << endl;
                            cout << "Total harga sewa: Rp" << totalharga << endl;
                            data[pilih].status.kondisi = "Tersedia";
                            data[pilih].LamaSewa = 0;
                            data[pilih].NamaPenyewa = "";
                            cout << "Kamera berhasil dikembalikan!\n";
                        }
                        else
                        {
                            cout << "Ini bukan kamera yang Anda sewa!\n";
                        }
                    }
                    else
                    {
                        cout << "Nomor tidak valid!\n";
                    }
                    break;
                }
                case 4:
                    cout << "Kembali ke menu awal...\n";
                    login_sukses = false;
                    break;

                default:
                    cout << "Pilihan tidak tersedia\n";
                }
            }
        } while (login_sukses);
    }
    return 0;
}
#include <iostream>
#include <string>
#include <iomanip>
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

void RegisterUser(User *user, int *JumlahUser){
    string username, Password;
    if (*JumlahUser >= 2){
        cout << "User penuh";
        return;
    }
    cout << "\n========================\n";
    cout << "      REGISTER USER\n";
    cout << "========================\n";
    cout << "Masukkan nama baru: ";
    getline(cin, (user + *JumlahUser)->username);
    cout << "Masukkan password baru: ";
    getline(cin, (user + *JumlahUser)->password);
    (user + *JumlahUser)->role = "user";
    (*JumlahUser)++;
    cout << "Registrasi berhasil! Silakan login\n";
}

bool LoginUser(User *user, int *JumlahUser, string *InputNama, string *role_login){
    string InputPassword;
    int percobaan_login = 0;

    while (percobaan_login < 3){
        cout << "\n===================\n";
        cout << "       LOGIN\n";
        cout << "===================\n";
        cout << "Masukkan username: ";
        getline(cin, *InputNama);
        cout << "Masukkan password: ";
        getline(cin, InputPassword);

        for (int i = 0; i < *JumlahUser; i++){
            if (*InputNama == (user + i)->username && InputPassword == (user + i)->password){
                cout << "Berhasil login! Selamat datang " << *InputNama << endl;
                *role_login = (user + i)->role;
                return true;
            }
        }
        percobaan_login++;
        cout << "Gagal login! Sisa percobaan: " << (3 - percobaan_login) << endl;
    }
    cout << "Gagal 3x! Akses ditolak!\n";
    return false;
}

void TambahDataKamera(Kamera *data, int *JumlahData){
    if (*JumlahData == 10){
        cout << "Data kamera penuh!";
        return;
    }
    cout << "\n========================================================================================" << endl;
    cout << "                          TAMBAH DATA KAMERA TWISTERS CAM                                 " << endl;
    cout << "========================================================================================" << endl;
    cout << "ID Kamera: ";
    getline(cin, (data + *JumlahData)->ID_Kamera);
    cout << "Nama Kamera: ";
    getline(cin, (data + *JumlahData)->NamaKamera);
    cout << "Harga sewa/hari: Rp";
    cin >> (data + *JumlahData)->HargaSewa;
    cin.ignore();
    (data + *JumlahData)->status.kondisi = "Tersedia";
    (*JumlahData)++;
    cout << "Data berhasil ditambahkan";
    cout << endl;
}

void TampilkanDataKamera(Kamera *data, int *JumlahData){
    if (*JumlahData == 0){
        cout << "Data kamera belum tersedia";
        return;
    }
    Kamera *ptr = data;
    cout << "\n========================================================================================\n";
    cout << "                           DATA KAMERA TWISTERS CAM\n";
    cout << "========================================================================================\n";
    cout << left << setw(5) << "No";
    cout << setw(10) << "ID";
    cout << setw(20) << "Nama Kamera";
    cout << setw(20) << "Harga Sewa/hari";
    cout << setw(12) << "Status";
    cout << endl;
    cout << "---------------------------------------------------------------------------------------\n";

    for (int i = 0; i < *JumlahData; i++){
        cout << left << setw(5) << i + 1;
        cout << setw(10) << (ptr + i) -> ID_Kamera;
        cout << setw(20) << (ptr + i) -> NamaKamera;
        cout << "Rp" << setw(17) << (ptr + i) -> HargaSewa;
        cout << setw(12) << (ptr + i) -> status.kondisi << endl;
    }
    cout << "========================================================================================\n";
}
void UbahDataKamera(Kamera *data, int *JumlahData){
    int index;
    if (*JumlahData == 0){
        cout << "Data kamera belum tersedia";
        return;
    }
    Kamera *ptr = data;
    TampilkanDataKamera(data, JumlahData);
    cout << "Pilih nomor kamera yang ingin diubah: ";
    cin >> index;
    cin.ignore();
    index--; 
    
    if (index >= 0 && index < *JumlahData)
    {
        cout << "ID Kamera baru: ";
        getline(cin, (ptr + index) -> ID_Kamera);
        cout << "Nama Kamera baru: ";
        getline(cin, (ptr + index) -> NamaKamera);
        cout << "Harga sewa/hari: Rp";
        cin >> (ptr + index) -> HargaSewa;
        cin.ignore();
        cout << "Status (Tersedia/Disewa): ";
        getline(cin, (ptr + index) -> status.kondisi);
        cout << "Data kamera berhasil diubah!\n";
        TampilkanDataKamera(data, JumlahData);
    }
    else
    {
        cout << "Nomor tidak valid!";
    }

}

void HapusDataKamera(Kamera *data, int *JumlahData){
    if (*JumlahData == 0){
        cout << "Data kamera tidak tersedia!";
        return;
    }
    Kamera *ptr = data;
    int index;
    char konfir_hapus;
    TampilkanDataKamera(data, JumlahData);
    cout << "Pilih nomor kamera yang ingin dihapus: ";
    cin >> index;
    cin.ignore();
    index--;

    if (index >= 0 && index < *JumlahData ){
        cout << "Yakin ingin hapus data kamera ini? (Y/N): ";
        cin >> konfir_hapus;

        if (konfir_hapus == 'Y' || konfir_hapus == 'y')
        {
            for (int i = index; i < *JumlahData - 1; i++)
            {
                *(ptr + i) = *(ptr + i + 1);
            }
            (*JumlahData)--;
                cout << "Data kamera berhasil dihapus!\n";
                TampilkanDataKamera(data, JumlahData);
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
}

int KembalikanKamera(int harga, int hari){
    if (hari == 0){
        return 0;
    }else{
        return harga + KembalikanKamera(harga, hari - 1);
    }
}

int KembalikanKamera(int harga, int lamaHari, float diskonSewa){
    float total = harga * lamaHari;
    float potongan = total * diskonSewa;
    cout << "Diskon: Rp" << potongan << endl;
    return total - potongan;
}

int main(){
    Kamera data[10];
    User user[2];
    int JumlahUser = 0, JumlahData = 0;
    user[JumlahUser].username = "LARRY";
    user[JumlahUser].password = "068";
    user[JumlahUser].role = "admin";
    JumlahUser++;
    bool MenuAwal = true;

    while(MenuAwal)
    {
        int PilihMenu;
        string InputNama, role_login;

        cout << "\n==========================\n";
        cout << "  HOME PAGE TWISTERS CAM\n";
        cout << "==========================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih (1-3): ";
        cin >> PilihMenu;
        cin.ignore();

        switch(PilihMenu)
        {
            case 1:
            RegisterUser(user, &JumlahUser);
            break;

            case 2:
            if(!LoginUser(user, &JumlahUser, &InputNama, &role_login)){
                return 0;
            }
            if (role_login == "admin")
            {
                int pilihan;
                do
                { 
                    cout << "\n======================\n";
                    cout << "       MENU ADMIN\n";
                    cout << "======================\n";
                    cout << "1. Tambah Data Kamera\n";
                    cout << "2. Tampilkan Data Kamera\n";
                    cout << "3. Ubah Data Kamera\n";
                    cout << "4. Hapus Data Kamera\n";
                    cout << "5. Logout\n";
                    cout << "Pilih (1-5): ";
                    cin >> pilihan;
                    cin.ignore();

                    switch(pilihan)
                    {
                        case 1:
                        TambahDataKamera(data, &JumlahData);
                        break;
                        
                        case 2:
                        TampilkanDataKamera(data, &JumlahData);
                        break;

                        case 3:
                        UbahDataKamera(data, &JumlahData);
                        break;

                        case 4:
                        HapusDataKamera(data, &JumlahData);
                        break;
                    }

                } while (pilihan != 5);
            }
            else
            {
                int pilihan;
                do
                {
                    cout << "\n======================\n";
                    cout << "       MENU USER\n";
                    cout << "======================\n";
                    cout << "1. Lihat Data Kamera\n";
                    cout << "2. Sewa Kamera\n";
                    cout << "3. Kembalikan Kamera\n";
                    cout << "4. Logout\n";
                    cout << "Pilih (1-4): ";
                    cin >> pilihan;

                    switch (pilihan)
                    {
                        case 1:
                        TampilkanDataKamera(data, &JumlahData);
                        break;

                        case 2:
                        {
                        if (JumlahData == 0){
                            cout << "Data kamera belum ada";
                            break;
                        }
                        }

                        {
                            TampilkanDataKamera(data, &JumlahData);
                            int pilih;
                            cout << "Pilih nomor kamera yang ingin disewa: ";
                            cin >> pilih;
                            pilih--;

                            if ((data + pilih)->status.kondisi == "Tersedia")
                            {
                                cout << "Sewa berapa hari: ";
                                cin >> (data + pilih)->LamaSewa;
                                (data + pilih)->status.kondisi = "Disewa";
                                (data + pilih)->NamaPenyewa = InputNama;

                                cout << "Kamera berhasil disewa!\n";
                            }
                            else
                            {
                                cout << "Kamera sedang disewa!\n";
                            }
                            break;
                        }

                        case 3:
                        {
                            if (JumlahData == 0){
                                cout << "Data kamera belum ada";
                                break;
                            }
                        }
                        
                        {
                            TampilkanDataKamera(data, &JumlahData);
                            int pilih;
                            cout << "Pilih nomor kamera yang Anda sewa untuk dikembalikan: ";
                            cin >> pilih;
                            pilih--;
                            int total = KembalikanKamera((data + pilih)->HargaSewa, (data + pilih)->LamaSewa);
                            float pembayaran;

                            if (total >= 750000)
                            {
                                pembayaran = KembalikanKamera((data + pilih)->HargaSewa, (data + pilih)->LamaSewa, 0.15);
                                cout << "Harga sewa sebelum diskon: Rp" << total << endl;
                            }
                            else
                            {
                                pembayaran = total;
                            }
                            cout << "Total harga sewa yang harus dibayar: Rp" << pembayaran << endl;
                            (data + pilih)->status.kondisi = "Tersedia";
                            (data + pilih)->NamaPenyewa = "";
                            (data + pilih)->LamaSewa = 0;
                            cout << "Kamera berhasil dikembalikan\n";
                            break;
                        }
                    }
                } while (pilihan != 4);
            }
            break;
        
        case 3:
        cout << "Program selesai\n";
        return 0;

        default:
        cout << "Pilihan tidak valid\n";
        }
    }
    return 0;
}
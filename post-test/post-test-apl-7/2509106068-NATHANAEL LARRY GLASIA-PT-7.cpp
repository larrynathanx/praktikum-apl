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
    int ID_Kamera;
    string NamaKamera;
    int HargaSewa;
    int LamaSewa;
    string NamaPenyewa;
    StatusKamera status;
};

void RegisterUser(User *user, int &JumlahUser)
{
    try
    {
        if (JumlahUser >= 2)
            throw string("User penuh");

        cout << "\n========================\n";
        cout << "      REGISTER USER\n";
        cout << "========================\n";

        cout << "Masukkan nama baru: ";
        getline(cin, (user + JumlahUser)->username);
        if((user + JumlahUser)->username == "")
        throw string("Username tidak boleh kosongan");

        cout << "Masukkan password baru: ";
        getline(cin, (user + JumlahUser)->password);
        if((user + JumlahUser)->password == "")
        throw string("Password tidak boleh kosongan");

        (user + JumlahUser)->role = "user";
        JumlahUser++;

        cout << "Registrasi berhasil! Silakan login\n";
    }
    catch (string &e)
    {
        cout << "Error: " << e << endl;
    }
}

bool LoginUser(User *user, int &JumlahUser, string &InputNama, string &role_login)
{
    string InputPassword;
    int percobaan_login = 0;

    while (percobaan_login < 3)
    {
        try
        {
            cout << "\n===================\n";
            cout << "       LOGIN\n";
            cout << "===================\n";

            cout << "Masukkan username: ";
            getline(cin, InputNama);
            if (InputNama == "")
            throw string("Username tidak boleh kosong");

            cout << "Masukkan password: ";
            getline(cin, InputPassword);
            if (InputPassword == "")
            throw string("Password tidak boleh kosong");

            for (int i = 0; i < JumlahUser; i++)
            {
                if (InputNama == (user + i)->username && InputPassword == (user + i)->password)
                {
                    cout << "Berhasil login! Selamat datang " << InputNama << endl;
                    role_login = (user + i)->role;
                    return true;
                }
            }

            throw string("Username atau password salah");
        }
        catch (string &e)
        {
            percobaan_login++;
            cout << "Error: " << e << endl;
            cout << "Sisa percobaan: " << (3 - percobaan_login) << endl;
        }
    }

    cout << "Gagal 3x! Akses ditolak!\n";
    return false;
}

void TambahDataKamera(Kamera *data, int &JumlahData)
{
    try
    {
        if (JumlahData == 10)
            throw string("Data kamera penuh!");

        cout << "\n========================================================================================" << endl;
        cout << "                          TAMBAH DATA KAMERA TWISTERS CAM                                 " << endl;
        cout << "========================================================================================" << endl;

        cout << "ID Kamera: ";
        cin >> (data + JumlahData)->ID_Kamera;

        if ((data + JumlahData)->ID_Kamera <= 0)
            throw string("ID tidak valid");

        cin.ignore();

        cout << "Nama Kamera: ";
        getline(cin, (data + JumlahData)->NamaKamera);

        cout << "Harga sewa/hari: Rp";
        cin >> (data + JumlahData)->HargaSewa;

        if ((data + JumlahData)->HargaSewa < 0)
            throw string("Harga tidak valid");

        cin.ignore();

        (data + JumlahData)->status.kondisi = "Tersedia";
        JumlahData++;

        cout << "Data berhasil ditambahkan\n";
    }
    catch (string &e)
    {
        cout << "Error: " << e << endl;
    }
}

void TampilkanDataKamera(Kamera *data, int &JumlahData)
{
    if (JumlahData == 0)
    {
        cout << "Data kamera belum tersedia";
        return;
    }
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

    for (int i = 0; i < JumlahData; i++)
    {
        cout << left << setw(5) << i + 1;
        cout << setw(10) << (data + i)->ID_Kamera;
        cout << setw(20) << (data + i)->NamaKamera;
        cout << "Rp" << setw(17) << (data + i)->HargaSewa;
        cout << setw(12) << (data + i)->status.kondisi << endl;
    }
    cout << "========================================================================================\n";
}

void UbahDataKamera(Kamera *data, int &JumlahData)
{
    try
    {
        if (JumlahData == 0)
            throw string("Data kosong");

        TampilkanDataKamera(data, JumlahData);

        int index;
        cout << "Pilih nomor kamera: ";
        cin >> index;
        index--;

        if (index < 0 || index >= JumlahData)
            throw string("Index tidak valid");

        cout << "ID baru: ";
        cin >> (data + index)->ID_Kamera;

        cin.ignore();

        cout << "Nama baru: ";
        getline(cin, (data + index)->NamaKamera);

        cout << "Harga baru: ";
        cin >> (data + index)->HargaSewa;

        cin.ignore();

        cout << "Status: ";
        getline(cin, (data + index)->status.kondisi);

        cout << "Berhasil diubah\n";
    }
    catch (string &e)
    {
        cout << "Error: " << e << endl;
    }
}

void HapusDataKamera(Kamera *data, int &JumlahData)
{
    try
    {
        if (JumlahData == 0)
            throw string("Data kosong");

        TampilkanDataKamera(data, JumlahData);

        int index;
        char konfir;

        cout << "Pilih nomor: ";
        cin >> index;
        index--;

        if (index < 0 || index >= JumlahData)
            throw string("Index tidak valid");

        cout << "Yakin? (Y/N): ";
        cin >> konfir;

        if (konfir != 'Y' && konfir != 'y')
            throw string("Dibatalkan");

        for (int i = index; i < JumlahData - 1; i++)
        {
            *(data + i) = *(data + i + 1);
        }

        JumlahData--;

        cout << "Data dihapus\n";
    }
    catch (string &e)
    {
        cout << "Error: " << e << endl;
    }
}

int KembalikanKamera(int harga, int hari)
{
    try
    {
        if (hari < 0)
            throw string("Hari tidak valid");

        if (hari == 0)
            return 0;

        return harga + KembalikanKamera(harga, hari - 1);
    }
    catch (string &e)
    {
        cout << "Error: " << e << endl;
        return 0;
    }
}

int KembalikanKamera(int harga, int lamaHari, float diskonSewa)
{
    return (harga * lamaHari) - ((harga * lamaHari) * diskonSewa);
}

void BubbleSortKameraDescending(Kamera *data, int &JumlahData)
{
    for (int i = 0; i < JumlahData - 1; i++)
    {
        for (int j = 0; j < JumlahData - i - 1; j++)
        {
            if ((data + j)->NamaKamera < (data + j + 1)->NamaKamera)
            {
                Kamera temp = *(data + j);
                *(data + j) = *(data + j + 1);
                *(data + j + 1) = temp;
            }
        }
    }
}

void SelectionSortHargaAscending(Kamera *data, int &JumlahData)
{
    for (int i = 0; i < JumlahData - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < JumlahData; j++)
        {
            if ((data + j)->HargaSewa < (data + min)->HargaSewa)
                min = j;
        }
        Kamera temp = *(data + i);
        *(data + i) = *(data + min);
        *(data + min) = temp;
    }
}

int PartitionID(Kamera *data, int low, int high)
{
    int pivot = (data + high)->ID_Kamera;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if ((data + j)->ID_Kamera < pivot)
        {
            i++;
            Kamera temp = *(data + i);
            *(data + i) = *(data + j);
            *(data + j) = temp;
        }
    }

    Kamera temp = *(data + i + 1);
    *(data + i + 1) = *(data + high);
    *(data + high) = temp;

    return i + 1;
}

void QuickSortID(Kamera *data, int low, int high)
{
    if (low < high)
    {
        int p = PartitionID(data, low, high);
        QuickSortID(data, low, p - 1);
        QuickSortID(data, p + 1, high);
    }
}

int LinearSearchKamera(Kamera *data, int JumlahData, string key)
{
    for (int i = 0; i < JumlahData; i++)
    {
        if ((data + i)->NamaKamera == key)
            return i;
    }
    return -1;
}

int BinarySearchID(Kamera *data, int JumlahData, int key)
{
    int kiri = 0, kanan = JumlahData - 1;

    while (kiri <= kanan)
    {
        int tengah = (kiri + kanan) / 2;

        if ((data + tengah)->ID_Kamera == key)
            return tengah;
        else if ((data + tengah)->ID_Kamera < key)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    return -1;
}

int main()
{
    Kamera data[10];
    User user[2];
    int JumlahUser = 0, JumlahData = 0;

    user[JumlahUser++] = {"LARRY", "068", "admin"};

    bool MenuAwal = true;

    while (MenuAwal)
    {
        int PilihMenu;
        string InputNama, role_login;

        cout << "\n==========================\n";
        cout << "  HOME PAGE TWISTERS CAM\n";
        cout << "==========================\n";
        cout << "1. Register\n2. Login\n3. Keluar\n";
        cout << "Pilih (1-3): ";

        try
        {
            if (!(cin >> PilihMenu))
                throw string("Input harus angka!");

            cin.ignore(10000, '\n');

            switch (PilihMenu)
            {
            case 1:
                RegisterUser(user, JumlahUser);
                break;

            case 2:
            {
                if (!LoginUser(user, JumlahUser, InputNama, role_login))
                    throw string("Login gagal 3x");

                if (role_login == "admin")
                {
                    int pilihanAdmin;

                    do
                    {
                        cout << "\n======================\n";
                        cout << "       MENU ADMIN\n";
                        cout << "======================\n";
                        cout << "1. Tambah Data Kamera\n";
                        cout << "2. Tampilkan Data Kamera\n";
                        cout << "3. Ubah Data Kamera\n";
                        cout << "4. Hapus Data Kamera\n";
                        cout << "5. Sort Nama Kamera\n";
                        cout << "6. Sort Harga Kamera\n";
                        cout << "7. Sort ID Kamera\n";
                        cout << "8. Search Nama Kamera\n";
                        cout << "9. Search ID Kamera\n";
                        cout << "10. Logout\n";
                        cout << "Pilih (1-10): ";

                        if (!(cin >> pilihanAdmin))
                            throw string("Input admin harus angka!");

                        cin.ignore(10000, '\n');

                        switch (pilihanAdmin)
                        {
                        case 1:
                            TambahDataKamera(data, JumlahData);
                            break;

                        case 2:
                            TampilkanDataKamera(data, JumlahData);
                            break;

                        case 3:
                            UbahDataKamera(data, JumlahData);
                            break;

                        case 4:
                            HapusDataKamera(data, JumlahData);
                            break;

                        case 5:
                            BubbleSortKameraDescending(data, JumlahData);
                            TampilkanDataKamera(data, JumlahData);
                            break;

                        case 6:
                            SelectionSortHargaAscending(data, JumlahData);
                            TampilkanDataKamera(data, JumlahData);
                            break;

                        case 7:
                            QuickSortID(data, 0, JumlahData - 1);
                            TampilkanDataKamera(data, JumlahData);
                            break;

                        case 8:
                        {
                            string cari;
                            cout << "Masukkan nama kamera: ";
                            getline(cin, cari);

                            int hasil = LinearSearchKamera(data, JumlahData, cari);

                            if (hasil == -1)
                                throw string("Data tidak ditemukan");

                            cout << "ID: " << (data + hasil)->ID_Kamera << endl;
                            cout << "Nama: " << (data + hasil)->NamaKamera << endl;
                            cout << "Harga: Rp" << (data + hasil)->HargaSewa << endl;
                            break;
                        }

                        case 9:
                        {
                            if (JumlahData == 0)
                                throw string("Data kosong");

                            QuickSortID(data, 0, JumlahData - 1);

                            int cariID;
                            cout << "Masukkan ID kamera: ";

                            if (!(cin >> cariID))
                                throw string("ID harus angka!");

                            int hasil = BinarySearchID(data, JumlahData, cariID);

                            if (hasil == -1)
                                throw string("Data tidak ditemukan");

                            cout << "ID: " << (data + hasil)->ID_Kamera << endl;
                            cout << "Nama: " << (data + hasil)->NamaKamera << endl;
                            cout << "Harga: Rp" << (data + hasil)->HargaSewa << endl;
                            break;
                        }

                        case 10:
                            cout << "Logout admin...\n";
                            break;

                        default:
                            cout << "Menu tidak valid\n";
                        }

                    } while (pilihanAdmin != 10);
                }
                else
                {
                    int pilihanUser;

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

                        if (!(cin >> pilihanUser))
                            throw string("Input harus angka!");

                        cin.ignore(10000, '\n');

                        switch (pilihanUser)
                        {
                        case 1:
                            TampilkanDataKamera(data, JumlahData);
                            break;

                        case 2:
                        {
                            if (JumlahData == 0)
                                throw string("Data kosong");

                            TampilkanDataKamera(data, JumlahData);

                            int nomor;
                            cout << "Pilih kamera: ";

                            if (!(cin >> nomor))
                                throw string("Input harus angka");

                            nomor--;

                            if (nomor < 0 || nomor >= JumlahData)
                                throw string("Index tidak valid");

                            if ((data + nomor)->status.kondisi != "Tersedia")
                            {
                                cout << "Kamera sudah disewa\n";
                                break;
                            }

                            cout << "Lama sewa: ";
                            cin >> (data + nomor)->LamaSewa;

                            (data + nomor)->status.kondisi = "Disewa";
                            (data + nomor)->NamaPenyewa = InputNama;

                            cout << "Berhasil disewa\n";
                            break;
                        }

                        case 3:
                        {
                            if (JumlahData == 0)
                                throw string("Data kosong");

                            TampilkanDataKamera(data, JumlahData);

                            int nomor;
                            cout << "Pilih kamera: ";

                            if (!(cin >> nomor))
                                throw string("Input harus angka");

                            nomor--;

                            if (nomor < 0 || nomor >= JumlahData)
                                throw string("Index tidak valid");

                            if ((data + nomor)->NamaPenyewa != InputNama)
                                throw string("Bukan kamera milik anda");

                            int total = KembalikanKamera((data + nomor)->HargaSewa, (data + nomor)->LamaSewa);

                            if (total >= 750000)
                            {
                                total = KembalikanKamera((data + nomor)->HargaSewa, (data + nomor)->LamaSewa, 0.15);
                            }

                            cout << "Total bayar: Rp" << total << endl;

                            (data + nomor)->status.kondisi = "Tersedia";
                            (data + nomor)->NamaPenyewa = "";
                            (data + nomor)->LamaSewa = 0;

                            cout << "Berhasil dikembalikan\n";
                            break;
                        }

                        case 4:
                            cout << "Logout user...\n";
                            break;

                        default:
                            cout << "Menu tidak valid\n";
                        }

                    } while (pilihanUser != 4);
                }
                break;
            }

            case 3:
                cout << "Program selesai\n";
                MenuAwal = false;
                break;

            default:
                cout << "Menu utama tidak valid\n";
            }
        }
        catch (string &e)
        {
            cout << "\n[ERROR] " << e << "\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    return 0;
}
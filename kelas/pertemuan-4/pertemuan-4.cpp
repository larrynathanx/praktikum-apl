//pointer adalah variabel untuk menyimpan alamat memori dari suatu variabel atau objek lainnya

//pass by value
// # include <iostream>
// using namespace std;
// struct Address{
// string kota;
// string provinsi;
// string negara;
// };
// int main(){
// // deklarasi variabel dengan struct
// Address address1, address2;
// // mengisi value address1
// address1.kota = "Samarinda";
// address1.provinsi = "Kalimantan Timur";
// address1.negara = "Indonesia";
// // mengcopy value address1 ke address2
// address2 = address1;
// // mengganti property kota dari samarinda ke ikn
// address2.kota = "ikn";
// // value address1
// cout << address1.kota <<endl;
// // value address2
// cout << address2.kota;
// return 0;
// }

// #include <iostream>
// using namespace std;
// int main () {
// string nama = "Rangga Aryawinata";
// int umur = 37;
// cout << &nama << " adalah alamatnya " << nama <<endl;
// cout <<&umur << " adalah alamatnya " << umur << endl;
// return 0;
// }

// #include <iostream>
// using namespace std;
// int main () {
// string var = "Aku Variabel";
// string *varPtr = &var;
// cout << "Hasil dari varPtr: " << varPtr << endl;
// cout << "Hasil dari *varPtr: " << *varPtr <<endl;
// cout << endl << "Kesimpulannya varPtr isi nya alamatnya var" << endl;
// cout << "*varPtr hasilnya value dari var" <<endl;
// cout << "Jika masih bingung bisa amati output berikut" <<endl;
// cout << endl;
// cout << "Hasil/value dari var " << var <<endl;
// cout << "Hasil/value dari alamat var (&var) " << &var <<endl;
// cout << "Hasil/value dari varPtr " << varPtr <<endl;
// cout << "Hasil/value dari *varPtr " << var <<endl;
// return 0;
// }

// #include <iostream>
// using namespace std;
// int main () {
// cout << "pointer yang menunjuk ke suatu array" << endl;
// int a[5] = {1,2,3,4,5};
// int (*aPtr)[5] = &a;
// for (int i =0; i <5; i++){
// cout << *aPtr <<endl;
// }
// cout << "Pointer yang menunjuk ke arah elemen array" <<endl;
// int b[5] = {1,2,3,4,5,};
// int *bPtr = b;
// for (int i = 0; i < 5; i++){
// cout << bPtr <<endl;
// // cout << *bPtr <<endl;
// bPtr ++;
// }
// return 0;
// }

// #include <iostream>
// using namespace std;
// void tukar(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main(){
//     int angka1, angka2;
//     angka1 = 177;
//     angka2 = 267;

//     cout << "Sebelum ditukar, nilai a adalah " << angka1 << " dan nilai b adalah " << angka2 << endl;
//     tukar(&angka1, &angka2);
//     cout << "Setelah ditukar, nilai a: " << angka1 << ", nilai b: " << angka2;
// }
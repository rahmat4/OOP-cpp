#include <iostream>
#include <string>
using namespace std;

class Mahasiswa{
    public:
        string nama;
        string jurusan;
        string NIM;
        double ipk;

        Mahasiswa(string nama , string jurusan , string NIM , double ipk){
            Mahasiswa::nama = nama;
            Mahasiswa::jurusan = jurusan;
            Mahasiswa::NIM = NIM;
            Mahasiswa::ipk = ipk;
        }

        // method tanpa parameter dan tanpa return
        void display(){
            cout << nama << endl;
            cout << jurusan << endl;
            cout << NIM << endl;
            cout << ipk << endl;
        }

        // method dengan parameter dan tanpa return
        void ubahNama(string nama){
            this->nama = nama;
        }

        // method tanpa parameter dan dengan return
        string Nama(){
            return this->nama;
        }

        // method dengan parameter dan dengan return
        double tambahNilai(const double &nilai){
            return this->ipk + nilai;
        }
};

int main(){
    Mahasiswa mahasiswa1("otong","Teknik informatika","23324143",3.4);
    mahasiswa1.display();
    mahasiswa1.ubahNama("ucup");
    mahasiswa1.display();

    mahasiswa1.Nama();
    mahasiswa1.display();

    double tambah = mahasiswa1.tambahNilai(1);
    cout << tambah << endl;
    return 0;
}

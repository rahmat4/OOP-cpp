#include <iostream>
#include <string>
using namespace std;

class Mahasiswa{
    public:
        string nama;
        string jurusan;
        double ipk;
        int NIM;

        // constructor
        Mahasiswa(string nama,string jurusan,double ipk,int NIM){
            Mahasiswa::nama = nama; // menggunakan namespace
            this->jurusan = jurusan; // menggukana this && arrow
            Mahasiswa::ipk = ipk;
            Mahasiswa::NIM = NIM;

            cout <<"nama    : " << nama << endl;
            cout <<"jurusan : " << jurusan << endl;
            cout <<"ipk     : " << ipk << endl;
            cout <<"NIM     : " << NIM << endl;

        }
};

int main(){

    Mahasiswa mahasiswa("otong","Teknik informatika",3.6,4243455);
    cout << endl;
    Mahasiswa* mahasiswa1 = new Mahasiswa("ucup","Teknik pemakaman",4.0,42465455);
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Mahasiswa{
    public:
        string nama;
        string jurusan;
        double ipk;
        int NIM;
};

class buah{
    public :
        string nama;  // 32 byte
        string warna; // 32 byte
        string rasa;  // 32 byte
        double berat; // 8  byte
        int jumlah;   // 4  byte

        buah(const char* nama, const char* warna, const char* rasa, double berat, int jumlah){
            this->nama = nama;
            this->warna = warna;
            this->rasa = rasa;
            this->berat = berat;
            this->jumlah = jumlah;
        }

        void show(){
            cout <<"\nnama\t: " << nama << endl;
            cout <<"warna\t: " << warna << endl;
            cout <<"rasa\t: " << rasa << endl;
            cout <<"berat\t: " << berat << " kg"<< endl;
            cout <<"jumlah\t: " << jumlah << " biji" << endl;
        }

};

int main(){

    Mahasiswa Mahasiswa1, Mahasiswa2;
    Mahasiswa1.nama = "daus";
    Mahasiswa1.NIM = 643794;
    Mahasiswa1.jurusan = "Multimedia";
    Mahasiswa1.ipk = 3.6;

    Mahasiswa2.nama = "ilas";
    Mahasiswa2.NIM = 643734;
    Mahasiswa2.jurusan = "Cheater";
    Mahasiswa2.ipk = 4.0;

    cout <<"nama : " << Mahasiswa1.nama << endl;
    cout <<"jurusan : " << Mahasiswa1.jurusan << endl;
    cout <<"NIM : " << Mahasiswa1.NIM << endl;
    cout <<"ipk : " << Mahasiswa1.ipk << endl << endl;

    cout <<"nama : " << Mahasiswa2.nama << endl;
    cout <<"jurusan : " << Mahasiswa2.jurusan << endl;
    cout <<"NIM : " << Mahasiswa2.NIM << endl;
    cout <<"ipk : " << Mahasiswa2.ipk << endl;

    cout << "\n-------------------------------------------" << endl;
    buah buah1 = buah("apel","merah","manis", 3.5,9);
    buah1.show();

    cout << "\n\nHeap Memory" << endl;
    cout << "------------------------" << endl;
    buah* buah2 = new buah("menggis","merah + coklat","kecut + manis",4.6,10);
    buah2->show();
    
    return 0;
}

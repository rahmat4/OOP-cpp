#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Mahasiswa{
    public:
        string nama;
        string NIM;
        string jurusan;

        Mahasiswa(string nama, string NIM, string jurusan){
            this->nama=nama;
            this->NIM=NIM;
            this->jurusan=jurusan;
        }

        string sringify(){
            return "\n" + nama + " " + NIM + " " + jurusan;
        }
};

class DBase{
    public:
        fstream in,out;
        string namaFile;

    DBase(const char* namaFile){
        this->namaFile=namaFile;
    }

    void save(Mahasiswa data){
        cout << endl;
        cout << data.nama << endl;
        cout << data.NIM << endl;
        cout << data.jurusan << endl;

        DBase::out.open(DBase::namaFile,ios::app);
        DBase::out << data.sringify();
        DBase::out.close();
    }

    void show(){
        DBase::in.open(DBase::namaFile,ios::in);
        string nama,NIM,jurusan;
        int index=1;

        while (!DBase::in.eof()){
            DBase::in >> nama;
            DBase::in >> NIM;
            DBase::in >> jurusan;

            cout << index++ << "\t";
            cout << nama + "\t";
            cout << NIM + "\t";
            cout << jurusan << endl;
        }
        DBase::in.close();
    }

};

int main(){
    string nama,NIM,jurusan;
    DBase dataBase("data.txt");
    dataBase.show();

    cout <<"\n\nMASUKAN NAMA MAHASISWA" << endl;
    cout <<"nama : ";
    cin >> nama;
    cout <<"NIM : ";
    cin >> NIM;
    cout <<"jurusan : ";
    cin >> jurusan;

    Mahasiswa mahasiswa(nama,NIM,jurusan);
    dataBase.save(mahasiswa);

    return 0;
}
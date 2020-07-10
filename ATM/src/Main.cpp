#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class bank{
    public:
        string norek;
        string nama;
        string saldo;

        bank(string norek, string nama, string saldo){
            this->norek=norek;
            this->nama=nama;
            this->saldo=saldo;
        }
        
        string stringify(){
            return norek + " " + nama + " " + saldo;
        }
};

class DBase{
    public:
        fstream in,out;
        string namaFile;

        DBase(const char* namaFile){
            this->namaFile=namaFile;
        }

        void save(bank data){
            DBase::out.open(DBase::namaFile,ios::app);
            DBase::out << data.norek << " ";
            DBase::out << data.nama << " ";
            DBase::out << data.saldo << endl;
            DBase::out.close();
        }

        void show(){
            DBase::in.open(DBase::namaFile,ios::in);
            string norek,nama,saldo;
            int indek=1;
            while(!DBase::in.eof()){
                DBase::in >> norek;
                DBase::in >> nama;
                DBase::in >> saldo;

                cout << indek++ <<"\t";
                cout << norek + "\t\t";
                cout << nama + "\t\t";
                cout << saldo << endl;
            }
            DBase::in.close();
        }

        void daftar(){
            string norek,nama,saldo,no_rekening,nama1,saldo1;
	        again:
            cout <<"masukan no rekening : ";
            cin >> no_rekening;
	        DBase::in.open(DBase::namaFile,ios::in);
	        while(!DBase::in.eof()){
		        DBase::in >> norek;
		        DBase::in >> nama;
		        DBase::in >> saldo;  
	        }
	        if(no_rekening == norek){
		        cout <<"No rekening ini sudah di gunakan"<< endl;
		        system("pause");
		    goto again; 
	        }else{
                cout <<"masukan nama : ";
                cin >> nama;
                cout <<"masukan saldo awal : ";
                cin >> saldo;
            }
            bank data(norek,nama,saldo);
            this->save(data);
            DBase::in.close();
        }

        void nabung(){
            double nominal;
            lagi:
            cout <<"masukna no rekening : ";
            DBase::in.open(DBase::namaFile,ios::in);
            string no_rekening,norek,saldo,nama;
            while(!DBase::in.eof()){
                DBase::in >> norek;
                DBase::in >> nama;
                DBase::in >> saldo;
            }
            cin >> no_rekening;
            if(no_rekening == norek){
                cout <<"masukan nominal Rp.";
                cin >> nominal;
                saldo+=nominal;
                system("pause");
                cout <<"saldo anda menjadi Rp." << saldo << endl;
            }else{
                cout <<"no rekening tidak di temukan!!!" << endl;
                system("pause");
                goto lagi;
            }

            DBase::in.close();
        }

        void tarik(){
            double nominal;
            lagi:
            cout <<"masukna no rekening : ";
            DBase::in.open(DBase::namaFile,ios::in);
            string no_rekening,norek,saldo,nama;
            while(!DBase::in.eof()){
                DBase::in >> norek;
                DBase::in >> nama;
                DBase::in >> saldo;
            }
            cin >> no_rekening;
            if(no_rekening == norek){
                cout <<"masukan nominal Rp.";
                cin >> nominal;
                //saldo-=nominal;
                system("pause");
                cout <<"saldo anda menjadi Rp." << saldo << endl;
            }else{
                cout <<"no rekening tidak di temukan!!!" << endl;
                system("pause");
                goto lagi;
            }

            DBase::in.close();
        }
};

int main(){
    int pilih;
    DBase data("data.txt");

    while (true){
        menu:
        system("cls");
        cout <<"========= ATM CRUD =========" << endl;
        cout <<"  1.Daftar nasabah" << endl;
        cout <<"  2.Nabung" << endl;
        cout <<"  3.Tarik tunai" << endl;
        cout <<"  4.Cek nasabah" << endl;
        cout <<"  5.Hapus nasabah" << endl;
        cout <<"  6.Keluar" << endl;
        cout <<"============================" << endl;
        cout <<"Pilih [1-6]? : ";
        cin >> pilih;

        switch (pilih){
            case 1:
                data.daftar();
                cout << endl;
            break;
            case 2:
                data.nabung();
                cout << endl;
            break;
            case 3:
                data.tarik();
                cout << endl;
            break;
            case 4:
                data.show();
                cout << endl;
            break;
            case 5:
                cout <<"fitur ini masih dalam tahap pengembangan...." << endl;
            break;
            case 6:
                system("pause");
                goto keluar;
            break;
            default:
                cout <<"pilihan anda tidak ada..." << endl;
            break;
        }
        system("pause");
        goto menu;
    }

    keluar:
    

    return 0;
}

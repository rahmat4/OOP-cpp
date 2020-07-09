#include <iostream>
#include <string>
using namespace std;

// class dengan constructor
class denganConstructor{
    public:
        string data;

        denganConstructor(const char* data){
            this->data = data;
        }

        void show(){
            cout << data << endl;
            //cout << denganConstructor::data << endl; // menggunakan namespace
            //cout << this->data << endl; // menggunakan this
        }
};

// class tanpa constuctor
class tanpaConstructor{
    public:
        string data;

        void show(){
            cout << data << endl;
        }
};

int main(){
    // cara membuat object dengan constructor
    denganConstructor mahasiswa1 = denganConstructor("data 1");
    mahasiswa1.show();

    // cara membuat object tanpa constructor
    tanpaConstructor mahasiswa2;
    mahasiswa2.data = "data 2";
    mahasiswa2.show();

    // cara membuat object dengan constructor
    denganConstructor mahasiswa3("data 3");
    mahasiswa3.show();

    // membuat object dengan heap memory
    denganConstructor* mahasiswa4 = new denganConstructor("data 4");
    (*mahasiswa4).show();
    mahasiswa4->show();
    string data = mahasiswa4->data;
    cout << data << endl;

    denganConstructor* mahasiswa5;
    mahasiswa5 = new denganConstructor("data 5");
    mahasiswa5->show();

    // tanpa constructor
    tanpaConstructor* mahasiswa6 = new tanpaConstructor;
    mahasiswa6->data = "data 6";
    mahasiswa6->show();

    tanpaConstructor* mahasiswa7;
    mahasiswa7 = new tanpaConstructor;
    mahasiswa7->data = "data 7";
    mahasiswa7->show();

    return 0;
}
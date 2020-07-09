#include <iostream>
#include <string>
using namespace std;

// data member
class classType{
    public:
        string dataStr;
        double dataDouble;
        double m_dataDouble;

        classType(const char* dataStr, double dataDouble){
            // menggunakan namespace
            classType::dataStr = dataStr;

            // mengunakan "this"
            this->dataDouble = dataDouble;

            // menggunakan konvensip penamaan
            m_dataDouble = dataDouble;
        }
};


namespace mahasiswa{
    // member function
    class player{
        public:
            string nama;
            double power;
            int health;

            player(const char* nama,double power,int health){
                this->setName(nama);
                this->setPower(power);
                this->setHealth(health);
            }

            void setName(const char* nama){
                this->nama = nama;
            }

            void setPower(double power){
                this->power = power;
            }

            // prototype
            void setHealth(int);
    };    
}

int main(){
    classType* data = new classType("otong",3.4);
    cout << data->dataStr << endl;
    cout << data->dataDouble << endl;
    cout << data->m_dataDouble << endl;

    mahasiswa::player* player1 = new mahasiswa::player("ucup",200, 50);
    cout << player1->nama << endl;
    cout << player1->power << endl;
    cout << player1->health << endl; 
    return 0;
}

void mahasiswa::player::setHealth(int health){
    this->health = health;
}
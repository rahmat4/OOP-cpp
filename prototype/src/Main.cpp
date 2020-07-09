#include <iostream>
#include <string>
using namespace std;

// deklarasi class
class player{
    public:
       string name;

        // constructor
        player(const char*);

        // method
        void display();
        string getName();
        string ubahName(const char*);
};

int main(){
    player* player1 = new player("otong");
    player1->display();
    cout <<"get name : " << player1->getName() << endl;
    player1->ubahName("isabella");
    player1->display();

    return 0;
}

// penjabaran constructor
player::player(const char* name){
    this->name = name;
}

// penjabaran method
void player::display(){
    cout <<"nama player : " << this->name << endl;
}

string player::getName(){
    return this->name;
}

string player::ubahName(const char* name){
    return this->name = name;
}
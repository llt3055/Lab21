// COMSC-210 | Lab  21| Tianyi Cao 
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Goat {
public:
// Data members
    int age;
    string name;
    string color;
//genrate random goat data by replit ai
    string names[15] = {
        "Billy", "Nanny", "Goaty", "Cloud", "Snow", 
        "Shadow", "Giddy", "Butter", "Pepper", "Salt", 
        "Brownie", "Cookie", "Dancer", "Prancer", "Vixen"
    };

    string colors[15] = {
        "White", "Black", "Red", "Gold", "Mauve", 
        "Yellow", "Gray", "Silver", "Pink", "Blue", 
        "Green", "Orange", "Purple", "Cyan", "Tan"
    };
}
int main() {
   srand(time(0));
    int size = rand() % 16 + 5;

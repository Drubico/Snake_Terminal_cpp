#include <iostream>
#include "./views/windows_start.cpp"
#include "./views/usermain.cpp"
using namespace std;

/* 
Para ejecutar:
g++ -pthread main.cpp -o main
./main
*/

int main(void) {
    string user;
    int P,C;
    usermain(P,C,user);
    welcomemain(P,C,user);

    return 0;
};
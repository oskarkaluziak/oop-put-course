#include <stdio.h>
#include <iostream>
using namespace std;
class KB
{
public:
    static int PoleKBaz;
};
int KB::PoleKBaz = 0;
class KP: public KB
{
public:
    int a;
};
int main()
{
    KP Obiekt;
    KP::KB::PoleKBaz = 3;
    Obiekt.PoleKBaz = 2;
    KB::PoleKBaz = 1;
    KB::PoleKBaz = 4;
    cout << Obiekt.PoleKBaz << endl;
}

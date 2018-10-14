/*
Nustatykite didžiausią ir mažiausią iš trijų skaičių a, b ir c. Naudokite funkcijos prototipą
void DidMaz (int a, int b, int c, int &, int &mx);
Pradiniai duomenys – n sveikųjų skaičių trejetų. Naudodami sukurtą funkciją, iš kiekvieno trejeto
atrinkite po du skaičius ir išveskite juos į kitą failą
*/

#include <iostream>
#include <iomanip>
#include <fstream>
//#include
#include <cmath>

using namespace std;
void DidMaz (int a, int b, int c, int &mn, int &mx);
int main()
{
	setlocale(LC_ALL, "Lithuanian");
	int a, b, c, i, n, mn, mx;
    ifstream duom("duom_1-is-IT.txt");
    ofstream rez("rez_1-is-IT.txt");

	duom >> n; // į kintamąjį perkeliam skaičių porų skaičių

    for (i = 0; i < n; i++) { // skaičių porų perkėlimas į kint. ir funkcijos atlikimas, n kartų
        duom >> a >> b >> c;
        DidMaz(a, b, c, mn, mx);
        rez << mn << " "<< mx << endl;
    }

	rez.close(); duom.close(); // uždarom failus
	return 0;
}
void DidMaz (int a, int b, int c, int &mn, int &mx) {
    if(a > b && a > c) {
    // "--||--" - kartojasi
        mx = a;
        mn = b; // mn yra b
        if(b > c) { // perrašo kint.: jei c mažiau už b, mn bus c
            mn = c;
        }
    }
    if(c > a && c > b) {
        mx = c;
        mn = b; // --||--  mn bus b
        if(a < b) { // --||-- mn bus a
            mn = a;
        }
    }
    if(b > a && b > c) {
        mx = b;
        mn = a; // --||-- mn bus a
        if(a > c) { // --||-- mn bus c
            mn = c;
        }
    }


    }



/*      -- Paruoštukai --
// ifstream fr("uzdx_duom.txt");
// fr.close();
// fixed //(sk. kiekis bus nurodytas *po* kabl.)
// set.precision() // (skč. po kablelio, naud. su fixed)
// setw() //(laukelio ilgis, simb)
*/

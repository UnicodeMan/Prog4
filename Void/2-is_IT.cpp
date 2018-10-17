#include <iostream>
#include <iomanip>
#include <fstream>
//#include
#include <cmath>

using namespace std;

void S_ir_p(int a, int b, int &S, int &p) {
    S = a * b;
    p = 2 * (a + b);
}
int main()
{
	setlocale(LC_ALL, "Lithuanian");
	int a, b, n, S, p;
	ifstream fduom("duom_2-is-IT.txt");
    ofstream frez("rez_2-is-IT.txt");
	fduom >> n;

	for(int i=0; n > i; i++) {
        fduom >> a >> b;
        S_ir_p(a, b, S, p);
        frez << a << setw(6) << b; // Kraštinių matmenys, pirmo nereikia išvesti į failą nuo krašto
        frez << setw(6) << S << setw(6) << p; // plotai ir perimetrai
        frez << endl; // parašius reikšmes, pridedam naują eilutę
	}

	//uždaromi failai
    fduom.close();
    frez.close();
	return 0;
}


// -- Paruoštukai -- //
// ifstream fr("uzdx_duom.txt");
// fr.close();
// fixed //(sk. kiekis bus nurodytas *po* kabl.) -- set.precision() // (reikšminiai skč, galima naud. su fixed)
// setw() //(laukelio ilgis, simb)

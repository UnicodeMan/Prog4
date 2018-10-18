#include <iostream>
#include <iomanip>
#include <fstream>
//#include
#include <cmath>

using namespace std;

void GrazaPirkejui(int lt, int ct, int ns, int &ltg, int &ctg);

int main()
{
	setlocale(LC_ALL, "Lithuanian");
	int n, lt, ct, ns, ltg, ctg;
    ifstream fduom("duom_3-is-IT.txt");
    ofstream frez("rez_3-is-IT.txt");
    fduom >> n;

    /*  Apskaičiuoti grąžą, jei kainavo:
        'lt' ir 'ct', o įduota 'ns' litų;
        grąža 'ltg' litų ir 'ctg' centų.                   */

    for(int i=0; n > i; i++) {
        fduom >> lt >> ct >> ns;
        GrazaPirkejui(lt, ct, ns, ltg, ctg);
        frez << ltg << " Lt " << ctg << " ct" <<endl;
    }


	return 0;
	fduom.close();
	frez.close();
}
void GrazaPirkejui(int lt, int ct, int ns, int &ltg, int &ctg) {
    ltg = ns - (lt + 1); // atimti dar vieną litą, nes sekančioj eilutėj perverčiam 1lt į 100ct.
    ctg = 100 - ct;

    if(ctg == 100) { // su duotais duomenim nebūtina
        ctg = 0; // paverčiam 100 ct į 1Lt
        ltg = ltg++;
    }
}


// -- Paruoštukai -- //
// ifstream fduom("uzdx_duom.txt");
// fduom >> kintamasis;
// fr.close();
// fixed //(sk. kiekis bus nurodytas *po* kabl.) -- setprecision() // (reikšminiai skč, galima naud. su fixed)
// setw() //(laukelio ilgis, simb)

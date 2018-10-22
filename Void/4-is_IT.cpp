/*
 1.1:
 + padaryta atskira funkcija prastinimui
 + ištrintas nereikalingas kodas
 + dabar failai programos pabaigoje uždaromi "duom.close(); rez.close();"

 1.0:
 NOTICE: nors programa suskaičiuoja teisingai, dar reiktų prastinime padaryti ciklą cikle, gali būti bugų
 teksto bereikalingai daug (reikia ciklo cikle), liko sakinių pasitikrinimui (dar taisysiu kodą, todėl palikau),
 atsakyme rezultatai išvedami nevisai tvarkingai (dėl tarpų, reikia:  'setw(2) << skaitiklis'  ir  'setw(4-7) << vardiklis' ).
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;
void prastinimas(int &ats1, int &ats2);
void trupm_veiksmai(int skaitl1, int vardl1, int skaitl2, int vardl2, int &suma1, int &suma2, int &skirt1, int &skirt2, int &sand1, int &sand2, int &dalm1, int &dalm2);
int main()
{
	setlocale(LC_ALL, "Lithuanian");
	int n, skaitl1, vardl1, skaitl2, vardl2, suma1, suma2, skirt1, skirt2, sand1, sand2, dalm1, dalm2; //suma, skirt, sand, dalm;
	// Užduočių skaičius (n), skaitikliai ir vardikliai 1-2, ,,,
	// (suma, skirtumas, sandauga, dalmuo) - skaitiklio ir vardiklio
    ifstream duom("duom_4-is-IT.txt");
    ofstream  rez( "rez_4-is-it.txt");

	cout << "Sveikas, Pasauli!";

	duom >> n;

	rez << " T1      T2      Suma   Skirtumas   Sandauga   Dalmuo" << endl;
    rez << "----------------------------------------------------------" << endl;

	for(int i=0; i < n; i++) {
        duom >> skaitl1 >> vardl1 >> skaitl2 >> vardl2;
        trupm_veiksmai(skaitl1, vardl1, skaitl2, vardl2, suma1, suma2, skirt1, skirt2, sand1, sand2, dalm1, dalm2);
        rez  << skaitl1 << "/" << vardl1 << setw(7) << skaitl2 << "/" << vardl2 << setw(7) << suma1 <<  "/" << suma2 << setw(7) << skirt1 << "/" << skirt2 << setw(8) << sand1 << "/" << sand2 << setw(7) << dalm1 << "/" << dalm2 <<endl;
	}
    duom.close();
    rez.close();
	return 0;
}
void trupm_veiksmai(int skaitl1, int vardl1, int skaitl2, int vardl2, int &suma1, int &suma2, int &skirt1, int &skirt2, int &sand1, int &sand2, int &dalm1, int &dalm2){
    int ats1, ats2, vardl_common;
    vardl_common = vardl1 * vardl2; // bendras vardiklis daugybai, sudėčiai, atimčiai
    suma1 = skaitl1 * vardl2 + skaitl2 * vardl1; // sudedami skaitikliai, kartu ir bendravardiklinant
    skirt1= skaitl1 * vardl2 - skaitl2 * vardl1; // atimami skaitikliai, kartu ir bendravardiklinant
    sand1 = skaitl1 * skaitl2;
    sand2 = vardl1 * vardl2; // sandaugos bendras vardiklis
    dalm1 = skaitl1 * vardl2;
    dalm2 = skaitl2 * vardl1;
    suma2 = vardl_common; // baigiamas bendravardiklinimas
    skirt2= vardl_common; // baigiamas bendravardiklinimas
    // ats yra
    // skaičiai --> ats1, ats2
    prastinimas(suma1, suma2);
    prastinimas(skirt1, skirt2);
    prastinimas(sand1, sand2);
    prastinimas(dalm1, dalm2);
}

void prastinimas(int &ats1, int &ats2) {
    int i=0;
    for (i; i < 2; i++) {
        if((ats1 % 2) == 0 && (ats2 % 2) == 0) {
            ats1 = ats1 / 2; ats2 = ats2 / 2;
            i = 0;
        }
        if((ats1 % 3) == 0 && (ats2 % 3) == 0) {
            ats1 = ats1 / 3; ats2 = ats2 / 3;
            i = 0;
        }
        if((ats1 % 5) == 0 && (ats2 % 5) == 0) {
            ats1 = ats1 / 5; ats2 = ats2 / 5;
            i = 0;
        }
        if((ats1 % 7) == 0 && (ats2 % 7) == 0) {
            ats1 = ats1 / 7; ats2 = ats2 / 7;
            i = 0;
        }
    }
}


// -- Paruoštukai -- //
// ifstream fduom("uzdx_duom.txt");
// fduom >> kintamasis;
// fr.close();
// fixed //(sk. kiekis bus nurodytas *po* kabl.) -- setprecision() // (reikšminiai skč, galima naud. su fixed)
// setw() //(laukelio ilgis, simb)

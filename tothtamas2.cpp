// tothtamas2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>

using namespace std;

struct inf {
    int mevj;
    string nev;
    int hevj;
};

int main()
{
    setlocale(LC_ALL, "");
    const int maxd = 12;
    int i = 0;
    inf adatok[maxd];
    ifstream in("jegyek.txt");
    if (in.fail()) {
        cerr << "Hibas fajl";
        system("pause");
        exit(1);
    }
    int sor = 0;
    for (i = 0; i < maxd && !in.eof(); i++) {
        in >> adatok[i].mevj;
        in >> adatok[i].nev;
        in >> adatok[i].hevj;
        sor++;
    }
    in.close();
   //adatok kiirasa
    cout << "Adatok:\n";
    for (i = 0; i < sor; i++) {
        cout << "Második év végi jegy: " << adatok[i].mevj << "\tTanuló neve: " << adatok[i].nev << "\tHarmadik év végi jegy: " << adatok[i].hevj << endl;

    }

    //Hány olyan tanuló van, akinek mindkét év végi jegye legalább 3?
    int legharmas=0;
    for (i = 0; i < sor; i++) {
        if (adatok[i].mevj >= 3 && adatok[i].hevj >= 3) {
            legharmas++;
        }
    }
    cout <<endl<< legharmas << " embernek lett legalább hármas mindkét év végi jegye\n";

    //Mely tanulók teljesítették legjobban a második év végén, és hányan voltak?
    int legjobb = 0;
    for (i = 0; i < sor; i++) {
        if (adatok[i].mevj > legjobb) {
            legjobb = adatok[i].mevj;
        }
    }
    //cout << "Legjobb jegy:" << legjobb;
    cout << "\n";
    int legjobbak = 0;
    for (i = 0; i < sor; i++) {
        if (adatok[i].mevj == legjobb) {
            cout << "Legjobban teljesített: " << adatok[i].nev << endl;
            legjobbak++;
        }
    }
    cout << "Második évben legjobban teljesítõk száma: " << legjobbak << endl;

    //Mennyi az érdemjegyek közötti különbség az egyes diákok esetében?
    cout << "\n";
    for (i = 0; i < sor; i++) {
        if (adatok[i].mevj > adatok[i].hevj) {
            cout <<adatok[i].nev<<"  évvégi jegyek közti különbség: " << "" << adatok[i].mevj - adatok[i].hevj << endl;
        }
        else {
            cout << adatok[i].nev << "  évvégi jegyek közti különbség: " << "" << adatok[i].hevj - adatok[i].mevj << endl;
        }
    }

    //Volt-e olyan tanuló, aki mindkét év végén megbukott?
    bool megbukott = false;
    for (i = 0; i < sor; i++) {
        if (adatok[i].mevj < 2 && adatok[i].hevj < 2) {
            megbukott = true;
        }
    }
    cout << "\n";
    if (megbukott) {
        cout << "Volt olyan ";
    }else{
        cout << "Nem volt olyan ";
    }
    cout << "diák aki megbukott mindkét év végén\n";

    //Mely tanulók teljesítették legrosszabbul a harmadik év végén, és hányan voltak?
    int legroszabb=legjobb;
    int legroszabbak = 0;
    cout << "\n";
    for (i = 0; i < sor; i++) {
        if (adatok[i].hevj < legroszabb) {
            legroszabb = adatok[i].hevj;
        }
    }
    for (i = 0; i < sor; i++) {
        if (adatok[i].hevj == legroszabb) {
            cout << "Legrosszabbúl teljesített: " << adatok[i].nev << endl;
            legroszabbak++;
        }
    }
    cout << "A harmadik évben legrosszabbúl teljesített diákok száma: "<< legroszabbak << endl;

    //Mely tanulók kaptak mindkét év végén azonos jegyet?
    cout << "\n";
    for (i = 0; i < sor; i++) {
        if (adatok[i].mevj == adatok[i].hevj) {
            cout << "Mindkét év végén azonos jegyet kapott: " << adatok[i].nev << endl;
        }
    }
    //Mely tanulók jegyei nõttek meg legalább 2 egységgel a második év vége és a harmadik év vége között?
    cout << "\n";
    for (i = 0; i < sor; i++) {
        if (adatok[i].hevj - adatok[i].mevj >= 2) {
            cout << adatok[i].nev << " jegye legalább 2 egységgel nõtt\n";
        }
    }

    //Hozzon létre egy új állományt tankor.txt néven, majd írja ki az adatokat úgy, hogy elöl a név utána a második
    //év végi majd a harmadik év végi jegy szerepeljen!

    ofstream out("tankor.txt");
    if (out.fail()) {
        cerr << "Hibas fajl";
        system("pause");
        exit(1);
    }
    for (i = 0; i < sor; i++) {
        out << adatok[i].nev<<" ";
        out << adatok[i].mevj << " ";
        out << adatok[i].hevj << " \n";
    }
    out.close();
    return 1;
}


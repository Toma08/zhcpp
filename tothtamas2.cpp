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
        cout << "M�sodik �v v�gi jegy: " << adatok[i].mevj << "\tTanul� neve: " << adatok[i].nev << "\tHarmadik �v v�gi jegy: " << adatok[i].hevj << endl;

    }

    //H�ny olyan tanul� van, akinek mindk�t �v v�gi jegye legal�bb 3?
    int legharmas=0;
    for (i = 0; i < sor; i++) {
        if (adatok[i].mevj >= 3 && adatok[i].hevj >= 3) {
            legharmas++;
        }
    }
    cout <<endl<< legharmas << " embernek lett legal�bb h�rmas mindk�t �v v�gi jegye\n";

    //Mely tanul�k teljes�tett�k legjobban a m�sodik �v v�g�n, �s h�nyan voltak?
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
            cout << "Legjobban teljes�tett: " << adatok[i].nev << endl;
            legjobbak++;
        }
    }
    cout << "M�sodik �vben legjobban teljes�t�k sz�ma: " << legjobbak << endl;

    //Mennyi az �rdemjegyek k�z�tti k�l�nbs�g az egyes di�kok eset�ben?
    cout << "\n";
    for (i = 0; i < sor; i++) {
        if (adatok[i].mevj > adatok[i].hevj) {
            cout <<adatok[i].nev<<"  �vv�gi jegyek k�zti k�l�nbs�g: " << "" << adatok[i].mevj - adatok[i].hevj << endl;
        }
        else {
            cout << adatok[i].nev << "  �vv�gi jegyek k�zti k�l�nbs�g: " << "" << adatok[i].hevj - adatok[i].mevj << endl;
        }
    }

    //Volt-e olyan tanul�, aki mindk�t �v v�g�n megbukott?
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
    cout << "di�k aki megbukott mindk�t �v v�g�n\n";

    //Mely tanul�k teljes�tett�k legrosszabbul a harmadik �v v�g�n, �s h�nyan voltak?
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
            cout << "Legrosszabb�l teljes�tett: " << adatok[i].nev << endl;
            legroszabbak++;
        }
    }
    cout << "A harmadik �vben legrosszabb�l teljes�tett di�kok sz�ma: "<< legroszabbak << endl;

    //Mely tanul�k kaptak mindk�t �v v�g�n azonos jegyet?
    cout << "\n";
    for (i = 0; i < sor; i++) {
        if (adatok[i].mevj == adatok[i].hevj) {
            cout << "Mindk�t �v v�g�n azonos jegyet kapott: " << adatok[i].nev << endl;
        }
    }
    //Mely tanul�k jegyei n�ttek meg legal�bb 2 egys�ggel a m�sodik �v v�ge �s a harmadik �v v�ge k�z�tt?
    cout << "\n";
    for (i = 0; i < sor; i++) {
        if (adatok[i].hevj - adatok[i].mevj >= 2) {
            cout << adatok[i].nev << " jegye legal�bb 2 egys�ggel n�tt\n";
        }
    }

    //Hozzon l�tre egy �j �llom�nyt tankor.txt n�ven, majd �rja ki az adatokat �gy, hogy el�l a n�v ut�na a m�sodik
    //�v v�gi majd a harmadik �v v�gi jegy szerepeljen!

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


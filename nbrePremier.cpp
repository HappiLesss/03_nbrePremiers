/*
  ------------------------------------------------------------------------------
  Fichier     : nbre_1er.cpp
  Auteur(s)   :Maxime Schmidhauser
  Date        :

  But         : identifier tous les nombres premiers compris
                et une valeur choisie par l'utilisateur

  Remarque(s) : les erreurs de saisie ne sont pas vérifiées

  Compilateur : gcc
  ------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
using namespace std;

int main () {
    char validation_user;
    do {
        const int n_col = 5;
        int saisie_user;
        do {
            saisie_user= 0;
            std::cout<<"entrer une valeur [2-1000] "<<std::endl;
            std::cin>>saisie_user;
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (cin && (saisie_user < 2 ||saisie_user > 1000));
        int compteurligne =0;
        std::cout<<"Voici la liste des nombres premiers"<<std::endl;
        for (int i =2; i <= saisie_user; i++)
        {
            bool est_premier = false;
            if (i!=2) {
                for (int t = 2; t <i; t++)
                {
                    if (i%t==0)
                    {
                        break;
                    }
                    if (t== i-1)
                    {
                        est_premier = true;
                    }
                }
            }
            else if (i==2)
            {
                est_premier = true;
            }
            if (est_premier)
            {
                if (compteurligne != n_col)
                {
                    cout<<setw(10)<<i<<" ";
                    compteurligne++;
                }
                else
                {
                    cout<<endl;
                    compteurligne=0;
                }
            }
        }
        do
        {
            cout<<endl<<"Voulez-vous recommencer [O/N]"<<endl;
            cin>>validation_user;
        }
        while (validation_user != 'O' && validation_user != 'N');
    }
    while (validation_user =='O');
    return EXIT_SUCCESS;
}
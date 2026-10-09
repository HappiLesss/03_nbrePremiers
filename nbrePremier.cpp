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
        //nombre de colonne de notre tableau
        const int n_col = 5;
        //Chiffre qui sera demander d'être saisie par le user
        int saisie_user;
        do {
            saisie_user= 0;
            std::cout<<"entrer une valeur [2-1000] "<<std::endl;
            std::cin>>saisie_user;
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (cin && (saisie_user < 2 ||saisie_user > 1000));
        //Compteur qui nous premettera de définir lorsque nous devons faire un retour à la ligne
        //Pour respecter les dimmensions de notre tableau
        int compteurligne =0;
        std::cout<<"Voici la liste des nombres premiers"<<std::endl;
        //Boucle qui va vérifier si le nombre en cours à plus de deux diviseurs (lui-même et 1)
        for (int i =2; i <= saisie_user; i++)
        {
            //Inititalisation d'un booleen est premier en false, il sera en true seulement s'il respect les conditions de la boucle ci-dessous
            bool est_premier = false;
            //Si notre chiffre en cours est différent de 2
            if (i!=2) {
                //Nous divisons notre chiffre par tous les chiffres en dessous
                for (int t = 2; t <i; t++)
                {
                    //Si le modulo est 0, c'est qu'il a trouver un diviseur et donc que le chiffre n'est pas premier
                    if (i%t==0)
                    {
                        //Sortie de la boucle en cours car pas besoin de tester plus loin, on sait qu'il n'est pas premier
                        break;
                    }
                    //Si le chiffre n'est divisible par aucun des chiffres jusqu'à la moitier, il s'agit d'un nombre premier
                    if (t== i/2)
                    {
                        est_premier = true;
                    }
                }
            }
            //Au début de notre boucle, nous affichons deux dans la liste des nombre premier
            else if (i==2)
            {
                est_premier = true;
            }
            if (est_premier)
            {
                //Si le compteur n'est pas encore égal au dimmensions de notre tableau, nous affichons les résultats linéairement
                if (compteurligne != n_col)
                {
                    cout<<setw(10)<<i<<" ";
                    compteurligne++;
                }
                //dés que notre compteur atteint le nombre de colonne, nous insérons un retour à la ligne
                else
                {
                    cout<<endl;
                    compteurligne=0;
                }
            }
        }
        //Affichage du menu pour recommencer
        do
        {
            cout<<endl<<"Voulez-vous recommencer [O/N]"<<endl;
            cin>>validation_user;
        }
        while (validation_user != 'O' && validation_user != 'N');
    }
    //Si l'utilisateur tape O, le programme recommence
    while (validation_user =='O');
    return EXIT_SUCCESS;
}
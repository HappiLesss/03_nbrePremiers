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
        const int n_col = 2;
        //Chiffre qui sera demander d'être saisie par le user
        int saisie_user;
        do {
            saisie_user= 0;
            std::cout<<"entrer une valeur [2-1000] : ";
            std::cin>>saisie_user;
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
        while (saisie_user < 2 ||saisie_user > 1000);
        //Compteur qui nous premettera de définir lorsque nous devons faire un retour à la ligne
        //Pour respecter les dimmensions de notre tableau
        int compteurligne =0;
        std::cout<<"Voici la liste des nombres premiers"<<std::endl;
        //Boucle qui va vérifier si le nombre en cours à plus de deux diviseurs (lui-même et 1)
        for (int i =2; i <= saisie_user; i++)
        {
                //Nous divisons notre chiffre par tous les chiffres en dessous
                for (int t = 2; t <= i; t++)
                {
                    //Si le chiffre n'est divisible par aucun des chiffres jusqu'à la moitier, il s'agit d'un nombre premier
                    if (i/2 == 1 || t > (i/2)+1)
                    {
                        if (compteurligne != n_col)
                        {
                            std::cout<<std::setw(10)<<i<<" ";
                            compteurligne++;
                        }
                        else
                        {
                            //Si notre nombre de sortie atteint notre nombre de colonnes
                            //insertion d'un retour à la ligne et réintialisation du compteur
                            std::cout<<std::endl;
                            compteurligne=0;
                        }
                        break;
                    }
                    //Si le modulo est 0, c'est qu'il a trouver un diviseur et donc que le chiffre n'est pas premier
                    if (i%t==0)
                    {
                        //Sortie de la boucle en cours car pas besoin de tester plus loin, on sait qu'il n'est pas premier
                        break;
                    }
                }
        }
        //Affichage du menu pour recommencer
        do
        {
            std::cout<<std::endl<<"Voulez-vous recommencer [O/N] : ";
            std::cin>>validation_user;
        }
        while (validation_user != 'O' && validation_user != 'N');
    }
    //Si l'utilisateur tape O, le programme recommence
    while (validation_user =='O');
    return EXIT_SUCCESS;
}
PseudoCode Nombre premier:


1. Demande de saisie par l'utilisateur
2. Vérifier si la saisie est correct
	1. si saisie < 2 OU saisie > 1000
	2. alors on redemande la saisie 
3. Calcul de tous les nombres premiers
	1. Pour i allant de 2 à <= saisie utilisateur
		1. pour t allant de 2 à i
			1. Controle si i est un nombre premier
					1. Si i/2 == 1 OU t> (i/2)+1
					2. Alors c'est un nombre premier
							1. Affichage du nombre premier
							2. Incrémentation du compteur de colonne
							3. Si le compteur de colonne == n_col
							4. Alors on insère un retour à la ligne et on remet le compteur à 0
							5. Sort de la boucle 
					3. Si i%t==0
					4. Alors ce n'est pas un nombre premier
						1. Sort de la boucle
3. Affichage du menu pour recommencer
4. Vérifier si la saisie est correcte
	1 Si la saisie != 'O' AND saisie != 'N'
	2 Alors la saisie est redemandée
5. Fin de programme ou recommencer
	1. Si la saisie == 'O'
	2. Alors on recommence le programme
	3. Sinon le programme s'arrête
#include "PartieAvecResume.hh"


PartieAvecResume::PartieAvecResume(Parametres param):PartieADeux(param){
	for(int i=0;i<2;i++){
		nb3Pions[i]=0;
		tpsJoueur[i]=0;
	}
}

int PartieAvecResume::finPartie(int issue){


 	cout<<"----------------------------------"<<endl;
 	// on affiche le resume
 	afficheResume();
 	switch (issue){
 		case 0:
 			cout<<"Felicitations ! Tu as gagne "<<tabJoueurs[0]<<endl;
 			break;
 		case 1:
 			cout<<"Felicitations ! Tu as gagne "<<tabJoueurs[1]<<endl;

 			break;
 		case 2:
 			cout<<"Match nul. Un coude à coude VREUMENT"<<endl; 
 			break;
 	}
 	

 	return choixSuite();
}


void PartieAvecResume::afficheResume(){
	 //on maj nb3Pions au cas où on 
 	//ne serait pas rentré dans departagePions	
	comptage3Pions(0);
	comptage3Pions(1);

	cout<<"----------------------------------"<<endl;
	cout<<"RESUME DE LA PARTIE:"<<endl;
	cout<<endl;
	cout<<"Nombre de tours de la partie: "<<compteurTour<<endl;
	cout<<"Joueur 1: "<<tabJoueurs[0]<<endl;
	if (par.getAffichageSymboles())
		cout<<"Symbole pions: 1"<<endl;
	else
		cout<<"Symbole pions: X"<<endl;
	cout<<"Nombre de 3 pions alignes: "<<nb3Pions[0]<<endl;
	cout<<"Temps des décisions: "<<tpsJoueur[0]<<" secondes"<<endl;
	cout<<endl;
	cout<<"Joueur 2: "<<tabJoueurs[1]<<endl;
	if (par.getAffichageSymboles())
		cout<<"Symbole pions: 2"<<endl;
	else
		cout<<"Symbole pions: O"<<endl;
	cout<<"Nombre de 3 pions alignes: "<<nb3Pions[1]<<endl;
	cout<<"Temps des décisions: "<<tpsJoueur[1]<<" secondes"<<endl;
	cout<<"----------------------------------"<<endl;
}

//appelée dans remplitGrille()
void PartieAvecResume::affichageTour(){
	cout<<"A ton tour "<<tabJoueurs[JoueurCourant]<<". Tes jetons sont les:";
	if (!(par.getAffichageSymboles())){
		if (!JoueurCourant){
			cout<<"X"<<endl;
		}
		else{
			cout<<"O"<<endl;
		}
	}
	else{
		if (!JoueurCourant){
			cout<<"1"<<endl;
		}
		else{
			cout<<"2"<<endl;
		}

	}
}
//pour les tests
//on se met dans le cas d'une fin de partie
//où le nombre d'alignements de 3 pions est le même
void PartieAvecResume::grilleMemePions(){
	tpsJoueur[0]=24.7;
	tpsJoueur[1]=42.4;
	compteurTour=42;
	for(int i=0;i<6;i++){
		if(i%2==0){
			for(int j=0;j<=6;j++){
				if(j<=2 || j==6){
					(*this)(i,j)=0;
				}
				else{
					(*this)(i,j)=1;
				}
			}
		}
		else{
			for(int j=0;j<=6;j++){
				if(j<=2 || j==6){
					(*this)(i,j)=1;
				}
				else{
					(*this)(i,j)=0;
				}
			}
		}
	}
}

void PartieAvecResume::remplitGrille(){
	int colonne;
	time_t debutTour;
	time_t finTour;
	double tpsTour;

	affichageTour();

	time(&debutTour);
	cout<<"Remplis la colonne de ton choix"<<endl;
	cin>>colonne;
	time(&finTour);
	tpsTour=difftime(finTour,debutTour);
	cout<<endl;
	
	//tant que la colonne choisie est remplie/pas valide, on redemande au joueur de jouer
	while(nbParColonne[colonne]==6 || colonne > 6){
			
		//majAffichage();
		time(&debutTour);
		cout<<"choisis une colonne non remplie et valide"<<endl;
		cin>>colonne;
		time(&finTour);
		tpsTour=difftime(finTour,debutTour);
	} 
	tpsJoueur[JoueurCourant]+=tpsTour; //on rajoute le temps du tour au temps global de jeu du joueur

	grille[nbParColonne[colonne]][colonne]=JoueurCourant;
	nbParColonne[colonne]++; //maj ligneRemplieMax
	
}

void PartieAvecResume::reinitialisePartie(){
 	//on remet tous les attributs a leur état de base
	ligneRemplieMax=-1;
	compteurTour=0;
	srand(time(NULL));
	JoueurCourant=rand()%2;
	for(int i=0;i<=1;i++){
		tpsJoueur[i]=0;
		nb3Pions[i]=0;
	}
	map<int,int>::iterator it;
	//on remet le nombre de jetons par colonne à 0 partout
	for (it = nbParColonne.begin(); it  !=  nbParColonne.end(); ++it){
		it->second=0;

	}

 	for (int i=0; i<6; i++)  
	{
		for (int j=0; j<7; j++)
		{
			grille[i][j]=-1;
		}
	}

	//cas où le joueur a choisi de renommer les participants
	if (demandeNom){
		debutPartie();
	}

}

int PartieAvecResume::departageTemps(){

		if(tpsJoueur[0]>tpsJoueur[1]){
			return 1;
		}
		else {
			return 0;
		}
}

int PartieAvecResume::departagePions(){

	//cas où le critere est le nombre d'alignements de 3 pions
	comptage3Pions(0);
	comptage3Pions(1);

	if(nb3Pions[0]>nb3Pions[1]){
		return 0;
	}
	else if(nb3Pions[1]>nb3Pions[0]){
		return 1;
	}
	else{
		return departageTemps();
	}

}
void PartieAvecResume::comptage3Pions(int joueur){
	//c'est dans cette fonction qu'on change nb3Pions
	int somme=0;
	//cout<<"comptage3Pions joueur "<<joueur<<":somme0:"<<somme<<endl;
	int i;
	//nombre de 3 pions dans les lignes
	//on rajoute ce nombre a somme
	for(i=0;i<=5;i++)
		somme+=comptageUnitaire(i,0,i,6,joueur);
	//cout<<"comptage3Pions joueur "<<joueur<<" : somme1:"<<somme<<endl;
	//nombre de 3 pions dans les colonnes
	for(i=0;i<=6;i++)
		somme+=comptageUnitaire(0,i,5,i,joueur);
	//cout<<"comptage3Pions joueur "<<joueur<<" :somme2:"<<somme<<endl;
	//nombre de 3 pions dans les diagonales
	//diagonales coin bas gauche vers coin haut droit
	for(i=0;i<=3;i++)
		somme+=comptageUnitaire(3-i,0,5,2+i,joueur);

	for(i=0;i<=3;i++)
		somme+=comptageUnitaire(0,1+i,5-i,6,joueur);
	//cout<<"comptage3Pions joueur "<<joueur<<" :somme3:"<<somme<<endl;

	//diagonales coin haut gauche vers coin bas droit
	for(i=0;i<=3;i++)
		somme+=comptageUnitaire(2+i,0,0,2+i,joueur);

	for(i=0;i<=3;i++)
		somme+=comptageUnitaire(5,1+i,0+i,6,joueur);
	//cout<<"comptage3Pions joueur "<<joueur<<" :somme4:"<<somme<<endl;
	nb3Pions[joueur]=somme;
}

int PartieAvecResume::comptageUnitaire(int l1,int c1,int l2,int c2,int joueur){
	PionsAlignes pions;
	int i;
	//on compte pour une ligne
	if(l1==l2){
		for (i=c1;i<=c2;i++){
			pions.ajouterPion(grille[l1][i]);
		}
	}
	//on compte pour une colonne
	else if(c1==c2){
		for (i=l1;i<=l2;i++){
			pions.ajouterPion(grille[i][c1]);
		}
		
	}
	//on compte pour une diagonale
	else{
		if(l2>l1){
			for(i=0;i<=l2-l1;i++){
				pions.ajouterPion(grille[l1+i][c1+i]);
			}
		}
		else{
			for(i=0;i<=l1-l2;i++){
				pions.ajouterPion(grille[l1-i][c1+i]);
			}		
		}

	}
	return pions.compte3Pions(joueur);
}

int PartieAvecResume::VerifieFin(){


	int retour=-1;
	//on verifie les lignes
	retour=VerifieLignes();
	if(retour!=-1)
		return retour;
	
	//on verifie les colonnes
	retour=VerifieColonnes();
	if(retour!=-1)
		return retour;

	//on verifie les diagonales
	if (!(ligneRemplieMax<4)){
		if (VerifieDiagoBH()!=-1)
			return VerifieDiagoBH();
		if (VerifieDiagoHB()!=-1)
			return VerifieDiagoHB();
	}

	//on verifie si les joueurs n'ont pas déposé tous leurs pions
	//remplacer lignes suivantes par 1 seule fct
	if (compteurTour==42 && par.getSansEgalite()){
		if(par.getCritereEgalite()){
			return departagePions();
		}
		else{
			return departageTemps();

		}
	}
	else if (compteurTour==42){
		return 2;
	}

	return -1;	
}


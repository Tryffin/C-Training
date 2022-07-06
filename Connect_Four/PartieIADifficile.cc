#include "PartieIADifficile.hh"

PartieIADifficile::PartieIADifficile(Parametres param):Partie(param){


}
void PartieIADifficile::debutPartie(){
 	if (demandeNom){
 		cout	<< "Quel est le nom du joueur ?" << endl;
		cin>>nomjoueur;
 	}
 	if(!JoueurCourant==0){
 		cout<<endl;
 		cout<<"C'est " << nomjoueur << " qui commence"<<endl;
 	}
 	else{
 		cout<<"C'est l'IA qui commence"<<endl;
 	}
 }
 
int PartieIADifficile::finPartie(int issue){
    int choixFin;
    cout<<"----------------------------------"<<endl;
    switch (issue){
 		case 0:
 			cout<<"Felicitations ! Tu as gagne"<<endl;
 			break;

 		case 1:
 			cout<<"C'est dommage, Tu as perdu(e)"<<endl;
 			break;

 		case 2:
 			cout<<"Match nul. Un coude à coude VREUMENT"<<endl; 
 			break;
 	}
    cout<<"Tu veux faire quoi maintenant?"<<endl;
 	cout<<"1:Recommencer		2:Recommencer en changeant les noms			3:Menu"<<endl;
 	cin>>choixFin;
     

    //on met a jour demandeNom pour savoir si on demande les noms a la prochaine partie
 	if (choixFin==1){
 		demandeNom=0;
 	}
 	else{
 		demandeNom=1;
 	}
 	//si le choix n'est pas le menu, on recommence une partie
 	if (choixFin!=3){
         reinitialisePartie();

     }
 	return choixFin;
}

 void PartieIADifficile::reinitialisePartie() {
 	//on remet tous les attributs a leur état de base
	ligneRemplieMax=-1;
	compteurTour=0;
	srand(time(NULL));
	JoueurCourant=1;
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
void PartieIADifficile::remplitGrille(){
	int colonne;
	cout<<"A ton tour. Tes jetons sont les:";
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
	cout<<"Remplis la colonne de ton choix"<<endl;
	cin>>colonne;
	cout<<endl;
	
	//tant que la colonne choisie est remplie, on redemande au joueur de jouer
	while(nbParColonne[colonne]==6){
			
		majAffichage();
		cout<<"choisis une colonne non remplie"<<endl;
		cin>>colonne;
	} 
	

	grille[nbParColonne[colonne]][colonne]=JoueurCourant;
	nbParColonne[colonne]++; //maj ligneRemplieMax

}
 	
int PartieIADifficile::VerifieFin(){
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
	if (compteurTour==42){
		return 2;
	}

	return -1;

}
int PartieIADifficile::verifi(int colonne,int sym){
	PionsAlignes pions;
	int i,j;
	//verifie 3pions alignes horizontalemnt
	for(i=0;i<ligneRemplieMax;i++){
					
			for(j=0;j<=6;j++){
				pions.ajouterPion(grille[i][j]);
			}
			
			}
			if(pions.est3pions(sym)!=-1){
					colonne=j+1;
			}

			//verifie 3pions alignes verticalement
			for(j=0;j<=6;j++){
				if(!(nbParColonne[j]<4)){
					for(i=0;i<nbParColonne[j];i++){
						pions.ajouterPion(grille[i][j]);
					}	
				}
			}

			if(pions.est3pions(sym)!=-1){
					colonne=j;
			}
	return colonne;
}
void PartieIADifficile::tourOrdi(){
	int colonne=rand()%6;

    if (!(par.getAffichageSymboles())){
		if (!JoueurCourant){
			cout<<"Les jetons de l'IA sont X"<<endl;
			colonne=verifi(colonne,'O');
			
		}
		else{
			cout<<"Les jetons de l'IA sont est O"<<endl;
			colonne=verifi(colonne,'X');
		}
	}else{
		if (!JoueurCourant){
			cout<<"Les jetons de l'IA sont 1"<<endl;
			colonne=verifi(colonne,'2');
		}else{
			cout<<"Les jetons de l'IA sont 2"<<endl;
			colonne=verifi(colonne,'1');
			}
	}
	cout<<"En attente de l'IA..."<<endl;
	
	
	while(nbParColonne[colonne]==6){
		colonne=rand()%6;
	} 
	if(colonne<0){colonne=0;}
	if(colonne>6){colonne=6;}
    grille[nbParColonne[colonne]][colonne]=JoueurCourant;
	nbParColonne[colonne]++;

}


 int PartieIADifficile::jeu(){

 	while(VerifieFin()==-1){
		if(JoueurCourant){
			tourOrdi();	
		}else{
			remplitGrille();
		}
 		majAttributs();
 		majAffichage();

 	}
 	return finPartie(VerifieFin());
 	
 }


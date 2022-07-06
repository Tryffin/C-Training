#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Partie.hh"
#include "PartieADeux.hh"
#include "PartieAvecResume.hh"
#include "PartieIAMoyen.hh"
#include "PartieIADifficile.hh"
#include "Parametres.hh"
#include "Jeu.hh"

using namespace std;



// TEST_CASE("1:Partie: detection diagonale"){
// 	//on teste diagonales dans les 2 sens
// 	//et pour les 2 joueurs
// 	Parametres param;
// 	PartieADeux p(param);
// 	p(0,0)=0;
// 	p(1,1)=0;
// 	p(2,2)=0;
// 	p(3,3)=0;
// 	p.majAffichage();
// 	cout<<endl;
// 	cout<<"VerifieDiago:"<<p.VerifieDiago(0,0,5,5)<<endl;
// 	REQUIRE(p.VerifieDiagoBH()==0);
// 	REQUIRE(p.VerifieDiagoHB()==-1);
// 	p(2,6)=1;
// 	p(3,5)=1;
// 	p(4,4)=1;
// 	p(5,3)=1;
// 	p.majAffichage();
// 	cout<<endl;
// 	cout<<"VerifieDiago:"<<p.VerifieDiago(5,3,2,6)<<endl;
// 	REQUIRE(p.VerifieDiagoHB()==1);
// 	cout<<"------------------"<<endl;
// }

// TEST_CASE("2:maj ligneRemplieMax"){
// 	Parametres param;
// 	PartieADeux p(param);
// 	for(int i=0;i<=20;i++){
		
// 		p.remplitGrille();
// 		p.majAttributs();
// 		p.majAffichage();
// 		cout<<"ligne remplie max: "<<p.getLigneRemplieMax()<<endl;	
// 	}
// 	cout<<"------------------"<<endl;
// }



// TEST_CASE("3: PionsAlignes compte3Pions"){
// 	PionsAlignes p;
// 	p.ajouterPion(0);
// 	p.ajouterPion(0);
// 	p.ajouterPion(0);
// 	p.ajouterPion(1);
// 	p.ajouterPion(1);
// 	p.ajouterPion(0);
// 	p.ajouterPion(0);
// 	p.ajouterPion(0);
// 	p.afficheVecteur();
// 	cout<<"Joueur0: "<<p.compte3Pions(0)<<endl;
// 	cout<<"Joueur1: "<<p.compte3Pions(1)<<endl;
// 	REQUIRE(p.compte3Pions(0)==2);
// 	REQUIRE(p.compte3Pions(1)==0);
// 	cout<<"------------------"<<endl;
// }

TEST_CASE("4: PartieAvecResume comptageUnitaire"){
	Parametres param;
	PartieAvecResume p(param);
	p.grilleTest();
	p.majAffichage();
	cout<<"ligne 0 pour j1:"<<p.comptageUnitaire(0,0,0,6,0)<<endl;
	cout<<"colonne 5 pour j2:"<<p.comptageUnitaire(0,5,2,5,1)<<endl;
	cout<<"j2 diago 2,1-0,3:"<<p.comptageUnitaire(2,1,0,3,1)<<endl;
	cout<<"j2 diago 0,3-2,5:"<<p.comptageUnitaire(0,3,2,5,1)<<endl;
	cout<<"------------------"<<endl;

}
TEST_CASE("5: comptage 3 pions alignes"){
	Parametres param;
	PartieAvecResume p(param);
	p.grilleTest();
	p.majAffichage();
	p.comptage3Pions(0);
	p.comptage3Pions(1);
	cout<<"J1 3 pions :"<<p.getnb3Pions(0)<<endl;
	cout<<"J2 3 pions :"<<p.getnb3Pions(1)<<endl;
	REQUIRE(p.getnb3Pions(0)==8);
	REQUIRE(p.getnb3Pions(1)==4);
	cout<<"------------------"<<endl;
}

TEST_CASE("6: departage egalite sur pions"){

	Parametres param;
	PartieAvecResume p(param);
	p.grilleEgalite();
	p.majAffichage();
	REQUIRE(p.VerifieFin()==1);
	cout<<"------------------"<<endl;

}
TEST_CASE("7 :calcul temps joueurs"){
	//on pense dans ce testcase
	//a verifier si le temps du joueur se remet a jour lorsqu'il
	//choisit une mauvaise colonne
	Parametres param;
	PartieAvecResume p(param);
	p.debutPartie();
	for(int i=0;i<=3;i++){
		p.remplitGrille();
		cout<<"joueur1 temps:"<< p.getTpsJoueur(0)<<" secondes"<<endl;
		cout<<"joueur2 temps:"<< p.getTpsJoueur(1)<<" secondes"<<endl;
		p.majAttributs();
	}
}

TEST_CASE("8: egalite:meme nombre d'alignement de 3 pions+critereEgalite=pions"){
	Parametres param;
	PartieAvecResume p(param);
	p.grilleMemePions();
	p.majAffichage();
	cout<<"joueur1 temps:"<< p.getTpsJoueur(0)<<" secondes"<<endl;
	cout<<"joueur2 temps:"<< p.getTpsJoueur(1)<<" secondes"<<endl;
	REQUIRE(p.VerifieFin()==0);
}

TEST_CASE("9: changement des parametres"){

	Parametres param;
	
    switch(param.consulteParam()) {
    case 1 : 
		cout<<"valeur du paramètre 1 : affichage symboles"<<endl; 
		cout<<param.getAffichageSymboles()<<endl;
        break;    
    case 2 :
		cout<<"valeur du paramètre 2 : affichage index"<<endl;
		cout<<param.getAffichageIndex()<<endl;
        break;
	case 3 :
		cout<<"valeur du paramètre 3: critere d'egalite"<<endl; 
		cout<<param.getCritereEgalite()<<endl;
        break;
	case 4 : 
		cout<<"valeur du paramètre 4: niveau de difficulte"<<endl; 
		cout<<param.getNivDifficulte()<<endl;
        break;
	case 5 :
		cout<<"valeur du paramètre 5: sans egalite"<<endl; 
		cout<<param.getSansEgalite()<<endl;
        break;
	case 6 : 
		cout<<"valeur du paramètre 4: Avec resume"<<endl; 
		cout<<param.getAvecResume()<<endl;
        break;
	}	

}



TEST_CASE("10: IA moyen"){

	Parametres param;
	PartieIAMoyen p(param);
	p.setJoueurCourant(1);
	p.remplitGrille();
	p.remplitGrille();
	p.remplitGrille();
	p.setJoueurCourant(0);
	p.tourOrdi();

}

TEST_CASE("11: IA Difficile"){

	Parametres param;
	PartieIADifficile p(param);
	p.setJoueurCourant(1);
	p.remplitGrille();
	p.remplitGrille();
	p.remplitGrille();
	p.setJoueurCourant(0);
	p.tourOrdi();

	p.setJoueurCourant(1);
	p.remplitGrille();
	p.remplitGrille();
	p.remplitGrille();
	p.setJoueurCourant(0);
	p.tourOrdi();

}

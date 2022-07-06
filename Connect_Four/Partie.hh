#pragma once

#include <iostream>
#include <string>
#include <map>
#include <time.h>
#include "Parametres.hh"
#include "PionsAlignes.hh"

using namespace std;

//classe abstraite Partie
class Partie{
public:
	Partie(Parametres p);
	int getLigneRemplieMax(){return ligneRemplieMax;};
	virtual int jeu() = 0;
	virtual int VerifieFin() = 0;
	int VerifieDiago(int l1,int c1,int l2,int c2);
	int VerifieDiagoHB();
	int VerifieDiagoBH();
	int VerifieLignes();
	int VerifieColonnes();
	void grilleTest();
	void grilleEgalite();
	void majAffichage();
	void majAffichageMorpion();
	void majAffichageChiffres();
	void majAffichageChiffresIndex();
	void majAffichageMorpionIndex();
	void majAttributs();
	virtual void remplitGrille()=0;
	virtual void reinitialisePartie()=0;
	virtual void debutPartie()=0;
	virtual int finPartie(int issue)=0;
	int setJoueurCourant(int JoueurCour){return JoueurCourant=JoueurCour;};
	int& operator()(int L, int C){return grille[L][C];};

protected:
	int ligneRemplieMax;
	int grille[6][7];
	int JoueurCourant;
	int compteurTour;
	int demandeNom;
	map<int,int> nbParColonne;
	Parametres par;

};
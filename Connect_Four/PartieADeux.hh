#pragma once

#include "Parametres.hh"
#include "Partie.hh"


class PartieADeux: public Partie{
public:
	PartieADeux(Parametres param);
	int jeu();
	virtual void reinitialisePartie();
	virtual void remplitGrille();
	void debutPartie();
	int choixSuite();
	virtual int VerifieFin();
	virtual int finPartie(int issue);


protected:

	string tabJoueurs[2];

};
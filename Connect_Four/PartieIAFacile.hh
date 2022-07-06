#pragma once
#include "Parametres.hh"
#include "Partie.hh"

class PartieIAFacile: public Partie{
public:
	PartieIAFacile(Parametres param);
    void debutPartie();
    int finPartie(int issue);
    void reinitialisePartie();
    void remplitGrille();
    int  VerifieFin();
    void tourOrdi();
    int jeu();

protected:
   string nomjoueur;
};
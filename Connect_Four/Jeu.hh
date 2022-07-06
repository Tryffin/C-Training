//Fait par Mohamed-Ali YAZID et Yining BAO le 30/12/2020
#pragma once


#include <iostream>
#include <string>
#include "Parametres.hh"
#include "Partie.hh"
#include "PartieADeux.hh"
#include "PartieAvecResume.hh"
#include "PartieIAFacile.hh"
#include "PartieIAMoyen.hh"
#include "PartieIADifficile.hh"

class Jeu{
public:

	Jeu();
	void menu();
	void decisionMenu(int entree);
	void lancerParam();
	void lancerPartie();

private:
	Parametres param;
	Partie* partie;

};
#include "Parametres.hh"

using namespace std;

Parametres::Parametres(){
	affichageSymboles=1;
	affichageIndex=1;
	critereEgalite=1;
	nivDifficulte=1;
	sansEgalite=1;
	avecResume=1;

}
void Parametres::affsymbole(){
	
	if(getAffichageSymboles()){
		cout<<"1: Affichage des symboles :1/2"<<endl;
	}else{
		cout<<"1: Affichage des symboles :O/X"<<endl;
	}
}

void Parametres::affindex(){

	if(getAffichageIndex()){
		cout<<"2: Affichage des indexs :Oui"<<endl;
	}else{
		cout<<"2: Affichage des indexs :Non"<<endl;
	}

}

void Parametres::affcritere(){

	if(getCritereEgalite()){
		cout<<"3: Critere egalite : pions"<<endl;
	}else{
		cout<<"3: Critere egalite : rapidite"<<endl;
	}

}

void Parametres::affdiff(){

	switch (getNivDifficulte())
	{
	case 1:
		cout<<"4: Niveau :facile"<<endl;
		break;

	case 2:
		cout<<"4: Niveau :moyen"<<endl;
		break;

	case 3:
		cout<<"4: Niveau :Difficile"<<endl;
		break;
	default:
		break;
	}

}

void Parametres::affsansegal(){

	if(getSansEgalite()){
		cout<<"5: Sans egalite :oui"<<endl;
	}else{
		cout<<"5: Sans egalite :non"<<endl;
	}

}


void Parametres::affresume(){

	if(getAvecResume()){
		cout<<"6: Avec resume :Oui"<<endl;
	}else{
		cout<<"6: Avec resume :Non"<<endl;
	}
}


int Parametres::consulteParam(){
	int numero;
	cout<<"----------------------------------"<<endl;
	cout<<"Parametres:"<<endl;
	affsymbole();
	affindex();
	affcritere();
	affdiff();
	affsansegal();
	affresume();
	cout<<"7: Menu"<<endl;
	cout<<"Tapez le numero que vous voulez"<<endl;
	cin>>numero;
	//gérer les bugs
	while(numero<=0 || numero>7){
		cout<<"Tapez un numero entre 1 et 7"<<endl;
		cin>>numero;
	}
	cout<<endl;
	if(numero!=7){Changer(numero);}
	return numero;
}

void Parametres::changeaffsym(){
		int x1;
		cout<<"0: Affichage des symboles :O/X "<<endl;
		cout<<"1: Affichage des symboles :1/2 "<<endl;
		cin>>x1;
		if(cin){
			setAffichageSymboles(x1);
		}else{
			setAffichageSymboles(x1);
		}
}

void Parametres::changeaffind(){
		int x2;
		cout<<"0: Ne pas afficher les indexs"<<endl;
		cout<<"1: Afficher les indexs"<<endl;
		cin>>x2;
		if(cin){
			setAffichageIndex(x2);
		}else{
			setAffichageIndex(x2);
		}
}

void Parametres::changeaffrap(){
		int x3;
		cout<<"0: rapidite"<<endl;
		cout<<"1: Rangées de 3 pions"<<endl;
		cin>>x3;
		if(cin){
			setCritereEgalite(x3);
		}else{
			setCritereEgalite(x3);
		}
}

void Parametres::changediff(){
		int x4;
		cout<<"1: Le niveau facile"<<endl;
		cout<<"2: Le niveau moyen"<<endl;
		cout<<"3: Le niveau difficile"<<endl;
		cin>>x4;
		if(cin){
			setNivDifficulte(x4);
		}else{
			setNivDifficulte(x4);
		}
}

void Parametres::changeegal(){
		int x5;
		cout<<"0: Avec Egalite"<<endl;
		cout<<"1: Sans Egalite"<<endl;
		cin>>x5;
		if(cin){
			setSansEgalite(x5);
		}else{
			setSansEgalite(x5);
		}
}

void Parametres::changeresum(){
		int x6;
		cout<<"0: Sans resume"<<endl;
		cout<<"1: Avec resume"<<endl;
		cin>>x6;
		if(cin){
			setAvecResume(x6);
		}else{
			setAvecResume(x6);
		}
}


void Parametres::Changer(int num){
	
	cout<<"Comment vous voulez changer ce parametre?"<<endl;
	cout<<"Tapez ce que vous voulez"<<endl;
	switch (num)
	{
	case 1:
		changeaffsym();
		break;

	case 2:
		changeaffind();
		break;

	case 3:
		changeaffrap();
		break;

	case 4:
		changediff();
		break;

	case 5:
		changeegal();
		break;

	case 6:
		changeresum();
		break;

	default:
		break;
	}
}
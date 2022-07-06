#include "PionsAlignes.hh"

using namespace std;

PionsAlignes::PionsAlignes(){

}

int PionsAlignes::est3pions(int i){
	//taille du vecteur doit être supérieure a 2
	int compteur=0;
	int cpt2=0;
	vector<int>::iterator iter;
	for (iter=pions.begin();iter!=pions.end();iter++){
		if (*iter!=i){
			cpt2=0;
		}
		else{
			cpt2++;
		}
		//on a atteint 3 pions identiques successifs
		if (cpt2==3){
			compteur++;
			cpt2=0;
			return 1;
		}
	}
	return -1;
}

int PionsAlignes::estGagnant(){
	//taille du vecteur doit être supérieure a 2
	int nb=1;
	vector<int>::iterator iter;
	int prec=*(pions.begin());
	for (iter=pions.begin()+1;iter!=pions.end();iter++){
		if(*iter!=-1){
			if(*iter!=prec){
				nb=1;
			}
			else{
				nb++;
			}
		}
		//si on a un enchainement de 4 pions identiques
		//on retourne le chiffre lié au pion
		if(nb==4)
			return *iter;
		
		prec=*iter;
	}
	return -1;

}

//compte combien on trouve de fois 
//3 pions alignes identiques dans le vector de pions
// pour un type de pion donné par i
int PionsAlignes::compte3Pions(int i){
	int compteur=0;
	int cpt2=0;
	vector<int>::iterator iter;
	for (iter=pions.begin();iter!=pions.end();iter++){
		if (*iter!=i){
			cpt2=0;
		}
		else{
			cpt2++;
		}
		//on a atteint 3 pions identiques successifs
		if (cpt2==3){
			compteur++;
			cpt2=0;
		}
	}
	return compteur;
}

void PionsAlignes::afficheVecteur(){
	cout<<"vecteur:"<<endl;
	vector<int>::iterator iter;
	for (iter=pions.begin();iter!=pions.end();iter++){
		
		cout<<*iter<<", ";
	}
	cout<<endl;
}
void PionsAlignes::ajouterPion(int pion){
	pions.push_back(pion);

}
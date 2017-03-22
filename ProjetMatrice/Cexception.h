#pragma once
#include <iostream>

using namespace std;

#define EXCEPTION_NBLIGNECOLONNE 0
#define EXCEPTION_FICHIERINEXISTANT 1
#define EXCEPTION_MATRICENONDOUBLE 2
#define EXCEPTION_DIVISIONPARZERO 3
#define EXCEPTION_ERREURFICHIER 4

class Cexception
{
private:
	int EXCValeur;
	char * EXCMessage;
public:
	/* Constructeur */
	Cexception();
	Cexception(Cexception &EXCCopie);
	Cexception(int iValeur, char * sMessage);
	/* Getter */
	int EXCLecture_Valeur();
	void EXCAffiche_Message();
	/* Destructeur */
	~Cexception();

	/* Flux */
	friend ostream& operator<<(ostream& os, const Cexception& EXC);
};


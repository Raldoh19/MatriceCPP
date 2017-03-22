#include "Cexception.h"

/* CONSTRUCTEUR */

// Par défaut
Cexception::Cexception()
{
	EXCMessage = NULL;
	EXCValeur = -1;
}
// De recopie
Cexception::Cexception(Cexception &EXCCopie)
{
	EXCValeur = EXCCopie.EXCValeur;
	EXCMessage = (char*)malloc(sizeof(char)*(strlen(EXCCopie.EXCMessage) + 1));
	strcpy(EXCMessage, EXCCopie.EXCMessage);
}

Cexception::Cexception(int iValeur, char * sMessage)
{
	EXCValeur = iValeur;
	EXCMessage = (char*)malloc(sizeof(char)*(strlen(sMessage) + 1));
	strcpy(EXCMessage, sMessage);
}

/* DESTRUCTEUR */
Cexception::~Cexception()
{
	free(EXCMessage);
}

/* GETTER */
// Valeur 
int Cexception::EXCLecture_Valeur()
{
	return EXCValeur;
}
// Affichage du message
void Cexception::EXCAffiche_Message()
{
	if (this->EXCMessage != NULL)
	{
		std::cout << EXCMessage << endl;
	}
}

ostream& operator<<(ostream& os, const Cexception& EXC)
{
	os << "(Erreur n" << EXC.EXCValeur << ") :" << EXC.EXCMessage;
	return os;
}
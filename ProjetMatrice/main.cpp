// Matrice.cpp : Defines the entry point for the console application.
//

#include "FichierMatrice.h"
#include "Matrice.h"
#include "Cexception.h"
#include "TestUnitaire.h"

int main()
{
	// Initialisation des test unitaires
	CTestUnitaire *test = new CTestUnitaire();
	cout << "Tout les tests unitaires sont pass�s avec succ�s !" << endl;
	system("pause");
    return 0;
}


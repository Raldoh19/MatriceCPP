#include "TestUnitaire.h"
#include "FichierMatrice.h"
#include "Cexception.h"
#include "Matrice.h"

CTestUnitaire::CTestUnitaire()
{
	try
	{
		TU_TestLectureFichier();
		TU_TestLectureDonnee();
		TU_TestCreationFichierErr();
	}
	catch (Cexception *E)
	{
		cout << *E << endl;
	}
}

CTestUnitaire::~CTestUnitaire(void)
{

}

void CTestUnitaire::TU_TestCreationFichierErr()
{
	try
	{
		/* Test avec le type de la matrice en implementant trois erreurs */
		TU_TestCreationFichierErrType("TypeMatrice=<int>","testUnitaire_ErrType.txt");	// Le seul type autorisé doit être un double
		TU_TestCreationFichierErrType("TypeMatrice=<double","testUnitaire_ErrType2.txt"); // Oublie du chevron après le type
		TU_TestCreationFichierErrType("Type=<double>","testUnitaire_ErrType3.txt");	// TypeMatrice est mal écrit
	}
	catch(Cexception *e)
	{
		throw new Cexception(*e);
	}
}

void CTestUnitaire::TU_TestCreationFichierErrType(char * sErr, char * sNameFichier)
{
	ofstream fichier(sNameFichier, ios::out | ios::trunc);
    if(fichier)
	{
		fichier << sErr << endl;
		fichier << "NBLignes=<3>" << endl;
		fichier << "NBColonnes=<3>" << endl;
		fichier << "Matrice=[" << endl;
		fichier << "1 0 0" << endl;
		fichier << "0 1 0" << endl;
		fichier << "0 0 1" << endl;
		fichier << "]";
		fichier.close();
	}
	else
	{
		throw new Cexception(10,"[TEST UNITAIRE KO] La création du fichier a echouée.");
	}
			cout << "test" << endl;
	try
	{
		CMatrice<double> MAT_FakeTestUnitaire = *(CFichierMatrice(sNameFichier).FM_Contenu());
		throw new Cexception(10,"[TEST UNITAIRE KO] Erreur dans la lecture de la premiere ligne du fichier");
	}
	catch(Cexception*)
	{

	}	
}

void CTestUnitaire::TU_TestLectureFichier()
{
	ofstream fichier("testUnitaire.txt", ios::out | ios::trunc);
    if(fichier)
	{
		fichier << "TypeMatrice=<double>" << endl;
		fichier << "NBLignes=<3>" << endl;
		fichier << "NBColonnes=<3>" << endl;
		fichier << "Matrice=[" << endl;
		fichier << "1 0 0" << endl;
		fichier << "0 1 0" << endl;
		fichier << "0 0 1" << endl;
		fichier << "]";
		fichier.close();
	}
	else
	{
		throw new Cexception(10,"[TEST UNITAIRE KO] La création du fichier a echouée.");
	}
}

void CTestUnitaire::TU_TestLectureDonnee()
{
	try
	{
		try
		{
			CFichierMatrice FM_FakeTestUnitaire("abcdefgh.txt");
			CMatrice<double> MAT_FakeTestUnitaire = *(FM_FakeTestUnitaire.FM_Contenu());
			throw new Cexception(10,"[TEST UNITAIRE KO] La lecture du fichier a echouée.");
		}
		catch(Cexception*)
		{
			/* Test */
			try
			{
				TU_TestCreationFichierErr();
			}
			catch(Cexception * e)
			{
				throw new Cexception(*e);
			}

			/* Si tout les tests de syntaxes sont passées, on test les matrices */
			CFichierMatrice FM_TestUnitaire("testUnitaire.txt");
			CMatrice<double> MAT_TestUnitaire = *(FM_TestUnitaire.FM_Contenu());
		}
	}
	catch(Cexception* e)
	{
		throw new Cexception(*e);
	}
}
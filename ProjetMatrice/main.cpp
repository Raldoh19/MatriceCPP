// Matrice.cpp : Defines the entry point for the console application.
//

#include "FichierMatrice.h"
#include "Matrice.h"
#include "Cexception.h"

int main()
{
	try
	{ 
		CMatrice<double> m1 = *(CFichierMatrice("m1.txt").FM_Contenu());
		CMatrice<double> m2 = *(CFichierMatrice("m2.txt").FM_Contenu());
		CMatrice<double> m3 = *(CFichierMatrice("m3.txt").FM_Contenu());

		cout << "Matrice présente dans le fichier: " << endl;
		m1.MAT_afficher();
		cout << endl;
		m2.MAT_afficher();
		cout << endl;
		m3.MAT_afficher();
		cout << endl;


		cout << "Veuillez saisir une valeur C: ";
		double c;
		cin >> c;

		cout << "Resultat multiplication: " << endl;
		(m1*c).MAT_afficher();
		cout << endl;
		(m2*c).MAT_afficher();
		cout << endl;
		(m3*c).MAT_afficher();
		cout << endl;
		cout << "Resultat division: " << endl;
		(m1/c).MAT_afficher();
		cout << endl;
		(m2/c).MAT_afficher();
		cout << endl;
		(m3/c).MAT_afficher();
		cout << endl;

		(m1*m2*m3).MAT_afficher();
		cout << endl;

		m1.MAT_afficher();
		cout << endl;
	}
	catch (Cexception *E)
	{
		cout << *E << endl;
	}
	
	system("pause");
    return 0;
}


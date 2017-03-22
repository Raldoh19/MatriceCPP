#pragma once

class CTestUnitaire
{
	public:
		CTestUnitaire(void);
		~CTestUnitaire(void);
		/* Creation de fichier errone */
		void TU_TestCreationFichierErr();
		void TU_TestCreationFichierErrType(char * sErr, char * sNameFichier);
		void TU_TestCreationFichierErrNbLigne();
		void TU_TestCreationFichierErrNbColonne();
		void TU_TestCreationFichierErrMatrice();

		/* Test du fichier */
		void TU_TestLectureFichier();
		void TU_TestLectureDonnee();
		/* Test de la matrice */
};
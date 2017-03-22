#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Matrice.h"
#include "Cexception.h"

class CFichierMatrice
{
	private:
		char * sFichier;
	public:
		CFichierMatrice();
		CFichierMatrice(char * fichier);
		CMatrice<double>* FM_Contenu();
		~CFichierMatrice();
};


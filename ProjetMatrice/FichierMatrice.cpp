#include "FichierMatrice.h"

#define DELIM_TYPEMATRICE "TypeMatrice=<"
#define DELIM_NBLIGNE "NBLignes=<"
#define DELIM_NBCOLONNE "NBColonnes=<"
#define DELIM_MATRICE "Matrice=["

using namespace std;

CFichierMatrice::CFichierMatrice()
{
	sFichier = nullptr;
}

CFichierMatrice::CFichierMatrice(char * fichier)
{
	sFichier = (char*)malloc(sizeof(char)*(strlen(fichier) + 1));
	strcpy(sFichier, fichier);
}

CMatrice<double>* CFichierMatrice::FM_Contenu()
{
	ifstream fPath(sFichier);
	if (fPath)
	{
		// Une variable pour stocker les lignes lues
		string sLigne; 
		// Le type de notre matrice
		string sType;
		// Variable de stockage pour le nombre de ligne et colonnes de notre matrice
		unsigned int eNbLigne, eNbColonnes;
		// Matrice recuperé par le fichier
		double ** dMatrice = nullptr;
		// Compteur du nombre de ligne parcouru dans le fichier
		unsigned int uiNbLigne = 0;

		//Tant qu'on n'est pas à la fin, on lit
		while (getline(fPath, sLigne))
		{
			// La premiere ligne contient le type de la matrice
			if (uiNbLigne == 0)
			{
				if (sLigne.length() == strlen(DELIM_TYPEMATRICE))
				{
					throw new Cexception(EXCEPTION_ERREURFICHIER, "Fichier non conforme au modèle.(TypeMatrice incomplet)");
				}
				// On verifie si le delimiteur est bien noté
				string sTitre(sLigne.begin(), sLigne.begin() + strlen(DELIM_TYPEMATRICE));
				if (sTitre != DELIM_TYPEMATRICE)
				{
					throw new Cexception(EXCEPTION_ERREURFICHIER, "Fichier non conforme au modèle.(TypeMatrice non présent)");
				}
				if (sLigne[sLigne.length() - 1] != '>')
				{
					throw new Cexception(EXCEPTION_ERREURFICHIER, "Fichier non conforme au modèle.(Chevron final absent)");
				}
				string sDivision(sLigne.begin() + strlen(DELIM_TYPEMATRICE), sLigne.end()-1);
				sType = sDivision;
				if (sType != "double")
				{
					throw new Cexception(EXCEPTION_MATRICENONDOUBLE, "La matrice présente dans le fichier n'est pas du type double !");
				}
			}
			// La deuxieme ligne contient le nombre de lignes
			else if (uiNbLigne == 1)
			{
				if (sLigne.length() == strlen(DELIM_NBLIGNE))
				{
					throw new Cexception(EXCEPTION_ERREURFICHIER, "Fichier non conforme au modèle.(NbLigne incomplet)");
				}
				// On verifie si le delimiteur est bien noté
				string sTitre(sLigne.begin(), sLigne.begin() + strlen(DELIM_NBLIGNE));
				if (sTitre != DELIM_NBLIGNE)
				{
					throw new Cexception(EXCEPTION_ERREURFICHIER, "Fichier non conforme au modèle.(NbLigne non présent)");
				}
				if (sLigne[sLigne.length() - 1] != '>')
				{
					throw new Cexception(EXCEPTION_ERREURFICHIER, "Fichier non conforme au modèle.(Chevron final absent)");
				}
				string sDivision(sLigne.begin() + strlen(DELIM_NBLIGNE), sLigne.end() - 1);

				// Conversion du string en integer
				try
				{
					eNbLigne = stoi(sDivision);
				}
				catch(invalid_argument)
				{
					throw new Cexception(EXCEPTION_NBLIGNECOLONNE, "Fichier non conforme au modèle. (Nombre de lignes erronées)");
				}
			}
			// La troisieme contient le nombre de colonnes
			else if (uiNbLigne == 2)
			{
				if (sLigne.length() == strlen(DELIM_NBCOLONNE))
				{
					throw new Cexception(EXCEPTION_ERREURFICHIER, "Fichier non conforme au modèle.(NbColonnes incomplet)");
				}
				// On verifie si le delimiteur est bien noté
				string sTitre(sLigne.begin(), sLigne.begin() + strlen(DELIM_NBCOLONNE));
				if (sTitre != DELIM_NBCOLONNE)
				{
					throw new Cexception(EXCEPTION_ERREURFICHIER, "Fichier non conforme au modèle.(NbColonnes non présent)");
				}
				if (sLigne[sLigne.length() - 1] != '>')
				{
					throw new Cexception(EXCEPTION_ERREURFICHIER, "Fichier non conforme au modèle.(Chevron final absent)");
				}
				string sDivision(sLigne.begin() + strlen(DELIM_NBCOLONNE), sLigne.end() - 1);
				// Conversion du string en integer
				try
				{
					eNbColonnes = stoi(sDivision);
				}
				catch (invalid_argument)
				{
					throw new Cexception(EXCEPTION_NBLIGNECOLONNE, "Fichier non conforme au modèle. (Nombre de colonnes erronées)");
				}
			}
			else if (uiNbLigne == 3)
			{
				// On verifie si la longueur est conforme au delimiteur pour éviter une exception
				if (sLigne.length() < strlen(DELIM_MATRICE))
				{
					throw new Cexception(EXCEPTION_ERREURFICHIER, "Fichier non conforme au modèle.(Matrice incomplete)");
				}
				// On verifie si le delimiteur est bien noté
				string sTitre(sLigne.begin(), sLigne.begin() + strlen(DELIM_MATRICE));
				if (sTitre != DELIM_MATRICE)
				{
					throw new Cexception(EXCEPTION_ERREURFICHIER, "Fichier non conforme au modèle.(Matrice non présente)");
				}
			}
			// On saute la 4 lignes et on applique l'algorithme qui suit a toutes les lignes a partir de la ligne 4 jusqu'a 4 + NbLigne de la matrice
			else if (uiNbLigne < 4 + eNbLigne)
			{
				// Detection erreur ligne 
				if (sLigne[0] == ']' || sLigne[0] == ' ' || sLigne.empty())
				{
					throw new Cexception(EXCEPTION_ERREURFICHIER, "Nombre de lignes non conforme");
				}
				// Variable pour stocker chaque variable de la matrice (ce dernier est construit après découpage de la ligne)
				string sMot = "";
				// On initialise la matrice lors du premier passage
				if (dMatrice == nullptr)
				{
					dMatrice = (double **)malloc(sizeof(double*)*eNbLigne);
					// Initilisation de cette matrice
					for (unsigned int uiCpt = 0; uiCpt < eNbLigne; uiCpt++)
					{
						dMatrice[uiCpt] = (double*)malloc(sizeof(double)*eNbColonnes);
					}
				}
				// Boucle tant qu'on a pas recuperer tout les elements de la colonnes
				for (unsigned int uiCpt = 0; uiCpt < eNbColonnes; uiCpt++)
				{
					if (sLigne.length() < sMot.length())
					{
						throw new Cexception(EXCEPTION_ERREURFICHIER, "Nombre de colonnes non conforme");
					}
					// On prends une chaine 'sDivision' qui comporte une copie de notre ligne sans les variables déja traités (sMot)
					string sDivision(sLigne.begin() + sMot.length(), sLigne.end());	
					// On cree un flux a partir de notre chaine 'sDivision'
					istringstream issLigne(sDivision);
					// On recupere notre variable avec comme delimiteur ' ' et on la stock dans sMot
					getline(issLigne, sMot, ' ');

					// Conversion en double 
					try
					{
						dMatrice[uiNbLigne - 4][uiCpt] = stod(sMot);
					}
					catch (invalid_argument)
					{
						throw new Cexception(EXCEPTION_NBLIGNECOLONNE, "Fichier non conforme au modèle. (Un element dans la matrice n'est pas un reel)");
					}

					// On trouve l'indice de ce mot trouvé
					unsigned int uiIndexBegin = sLigne.find(sMot);
					// On retire ce mot la de notre ligne
					sLigne = sLigne.substr(uiIndexBegin + 1);
				}
			}
			uiNbLigne++;
		}
		// On retourne notre matrice cree avec le nombre de ligne, colonne et element qu'on a obtenu en analysant le fichier
		return new CMatrice<double>(eNbLigne, eNbColonnes, dMatrice);
		fPath.close();
	}
	else
	{

		throw new Cexception(EXCEPTION_FICHIERINEXISTANT, "Le fichier est inexistant !");
	}
}

CFichierMatrice::~CFichierMatrice()
{
	if (sFichier)
	{
		free(sFichier);
	}
}

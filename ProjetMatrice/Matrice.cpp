#ifndef C_Matrice_Header
#define C_Matrice_Header

#include "Cexception.h"
#include "Matrice.h"

using namespace std;


template <typename T>
CMatrice<T>::CMatrice()
{
	pptElement = NULL;
	uiNbColonne = 0;
	uiNbLigne = 0;
}
template <typename T>
CMatrice<T>::CMatrice(CMatrice &MATPar)
{
	
	uiNbColonne = MATPar.uiNbColonne;
	uiNbLigne = MATPar.uiNbLigne;
	pptElement =(T**)malloc(sizeof(T*)*uiNbLigne);
	
	for (unsigned int uiCompteur = 0; uiCompteur < uiNbLigne; uiCompteur++)
	{
		pptElement[uiCompteur]=(T*)malloc(sizeof(T)*uiNbColonne);
	}
	for (unsigned int uiCompteur = 0; uiCompteur < uiNbLigne; uiCompteur++)
	{
		for (unsigned int uiCompteur2 = 0; uiCompteur2 < uiNbColonne; uiCompteur2++)
		{
			pptElement[uiCompteur][uiCompteur2] = MATPar.pptElement[uiCompteur][uiCompteur2];
		}
	}
}

template <typename T>
CMatrice<T>::CMatrice(unsigned int uiNbLigneParam, unsigned int uiNbColonneParam)
{
	uiNbColonne = uiNbColonneParam;
	uiNbLigne = uiNbLigneParam;
	pptElement = (T**)malloc(sizeof(T*)*uiNbLigne);
	for (unsigned int uiCompteur = 0; uiCompteur < uiNbLigne; uiCompteur++)
	{
		pptElement[uiCompteur] = (T*)malloc(sizeof(T)*uiNbColonne);
	}
}

template<typename T>
CMatrice<T>::CMatrice(unsigned int uiNbLigneParam, unsigned int uiNbColonneParam, T ** TMATParam)
{
	uiNbColonne = uiNbColonneParam;
	uiNbLigne = uiNbLigneParam;
	pptElement = (T**)malloc(sizeof(T*)*uiNbLigne);
	for (unsigned int uiCompteur = 0; uiCompteur < uiNbLigne; uiCompteur++)
	{
		pptElement[uiCompteur] = (T*)malloc(sizeof(T)*uiNbColonne);
	}

	for (unsigned int uiCompteur = 0; uiCompteur < uiNbLigne; uiCompteur++)
	{
		for (unsigned int uiCompteur2 = 0; uiCompteur2 < uiNbColonne; uiCompteur2++)
		{
			pptElement[uiCompteur][uiCompteur2] = TMATParam[uiCompteur][uiCompteur2];
		}
	}
}

template <typename T>
CMatrice<T>::~CMatrice()
{
	for (unsigned int uiCompteur = 0; uiCompteur < uiNbLigne; uiCompteur++)
	{
		free(pptElement[uiCompteur]);
	}
	free(pptElement);

}

template<typename T>
CMatrice<T> CMatrice<T>::operator*(const T c)
{
	// On cree une copie de notre matrice actuelle
	CMatrice<T> MATParam(*this);

	for (unsigned int uiCompteur = 0; uiCompteur < MATParam.uiNbLigne; uiCompteur++)
	{
		for (unsigned int uiCompteur2 = 0; uiCompteur2 < MATParam.uiNbColonne; uiCompteur2++)
		{
			MATParam.pptElement[uiCompteur][uiCompteur2] = MATParam.pptElement[uiCompteur][uiCompteur2] * c;
		}
	}
	return MATParam;
}

template<typename T>
CMatrice<T> CMatrice<T>::operator/(const T c)
{
	if (c == 0)
	{
		throw new Cexception(EXCEPTION_DIVISIONPARZERO, "Division par zero impossible !");
	}
	// On cree une copie de notre matrice actuelle
	CMatrice<T> MATParam(*this);

	for (unsigned int uiCompteur = 0; uiCompteur < MATParam.uiNbLigne; uiCompteur++)
	{
		for (unsigned int uiCompteur2 = 0; uiCompteur2 < MATParam.uiNbColonne; uiCompteur2++)
		{
			MATParam.pptElement[uiCompteur][uiCompteur2] = MATParam.pptElement[uiCompteur][uiCompteur2] / c;
		}
	}
	return MATParam;
}

template<typename T>
void CMatrice<T>::MAT_afficher()
{
	for (unsigned int uiCompteur = 0; uiCompteur < uiNbLigne; uiCompteur++)
	{
		for (unsigned int uiCompteur2 = 0; uiCompteur2 < uiNbColonne; uiCompteur2++)
		{
			cout << pptElement[uiCompteur][uiCompteur2] << "\t";
			
		}
		cout << endl;
	}
}

template<typename T>
CMatrice<T> CMatrice<T>::operator+(const CMatrice & MATPar)
{
	if (MATPar.uiNbColonne != uiNbColonne || MATPar.uiNbLigne != uiNbLigne)
	{
		throw new Cexception(EXCEPTION_NBLIGNECOLONNE "Nombre de lignes/colonnes incorrect. Addition impossible !");
	}
	// On cree une copie de notre matrice actuelle
	CMatrice<T> MATParam(*this);

	for (unsigned int uiCompteur = 0; uiCompteur < MATParam.uiNbLigne; uiCompteur++)
	{
		for (unsigned int uiCompteur2 = 0; uiCompteur2 < MATParam.uiNbColonne; uiCompteur2++)
		{
			MATParam.pptElement[uiCompteur][uiCompteur2] = MATPar.pptElement[uiCompteur][uiCompteur2] + pptElement[uiCompteur][uiCompteur2];
		}
	}
	return MATParam;
	
}
template<typename T>
CMatrice<T> CMatrice<T>::operator-(const CMatrice & MATPar)
{
	if (MATPar.uiNbColonne != uiNbColonne || MATPar.uiNbLigne != uiNbLigne)
	{
		throw new Cexception(EXCEPTION_NBLIGNECOLONNE, "Nombre de lignes/colonnes incorrect. Soustraction impossible !");
	}
	// On cree une copie de notre matrice actuelle
	CMatrice<T> MATParam(*this);

	for (unsigned int uiCompteur = 0; uiCompteur < MATParam.uiNbLigne; uiCompteur++)
	{
		for (unsigned int uiCompteur2 = 0; uiCompteur2 < MATParam.uiNbColonne; uiCompteur2++)
		{
			MATParam.pptElement[uiCompteur][uiCompteur2] = pptElement[uiCompteur][uiCompteur2] - MATPar.pptElement[uiCompteur][uiCompteur2] ;
		}
	}
	return MATParam;
}

template<typename T>
CMatrice<T> CMatrice<T>::operator*(const CMatrice & MATPar)
{
	T calcul=0;
	unsigned int colonnecontrol=0;
	if (uiNbLigne != MATPar.uiNbColonne)
	{
		throw new Cexception(EXCEPTION_NBLIGNECOLONNE, "Nombre de lignes/colonnes incorrect. Multiplication impossible !");
	}
	// Soit n,m * m,k
	// On cree une matrice avec (n,k)
	CMatrice<T> MATRetour(uiNbLigne, MATPar.uiNbColonne);

	for (unsigned int uiCompteur = 0; uiCompteur < MATRetour.uiNbLigne; uiCompteur++)
	{
		colonnecontrol=0;
		while(colonnecontrol < MATRetour.uiNbColonne)
		{
			calcul=0;
			for (unsigned int uiCompteur2 = 0; uiCompteur2 < MATRetour.uiNbColonne; uiCompteur2++)
			{
				calcul =calcul + pptElement[uiCompteur][uiCompteur2]*MATPar.pptElement[uiCompteur2][colonnecontrol];
			}
		
			MATRetour.pptElement[uiCompteur][colonnecontrol]=calcul;
			colonnecontrol++;
		}
		

	}
	return MATRetour;

}

template<typename T>
CMatrice<T> CMatrice<T>::operator=(const CMatrice &MATPar)
{
	if(pptElement!=NULL)
	{
		for (unsigned int uiCompteur = 0; uiCompteur < uiNbLigne; uiCompteur++)
		{
			free(pptElement[uiCompteur]);
		}
	    free(pptElement);
	}

	uiNbColonne = MATPar.uiNbColonne;
	uiNbLigne = MATPar.uiNbLigne;
	pptElement =(T**)malloc(sizeof(T*)*uiNbLigne);
	
	for (unsigned int uiCompteur = 0; uiCompteur < uiNbLigne; uiCompteur++)
	{
		pptElement[uiCompteur]=(T*)malloc(sizeof(T)*uiNbColonne);
	}
	for (unsigned int uiCompteur = 0; uiCompteur < uiNbLigne; uiCompteur++)
	{
		for (unsigned int uiCompteur2 = 0; uiCompteur2 < uiNbColonne; uiCompteur2++)
		{
			pptElement[uiCompteur][uiCompteur2] = MATPar.pptElement[uiCompteur][uiCompteur2];
		}
	}
	return *this;
}

template<typename T>
CMatrice<T> CMatrice<T>::MAT_Transposee()
{
	CMatrice<T> MATRetour(uiNbColonne,uiNbLigne);
	for (unsigned int uiCompteur = 0; uiCompteur < MATRetour.uiNbLigne; uiCompteur++)
	{
		for (unsigned int uiCompteur2 = 0; uiCompteur2 < MATRetour.uiNbColonne; uiCompteur2++)
		{
			MATRetour.pptElement[uiCompteur][uiCompteur2] =pptElement[uiCompteur2][uiCompteur];
		}
	}
	return MATRetour;

}

template<typename T>
void CMatrice<T>::MAT_creation2_2(T a,T b, T c,T d)
{
	pptElement[0][0]=a;
	pptElement[0][1]=b;
	pptElement[1][0]=c;
	pptElement[1][1]=d;
}

#endif
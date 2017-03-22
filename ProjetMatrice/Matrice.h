#pragma once
#ifndef H_Matrice_Header
#define H_Matrice_Header
#include <iostream>
template <typename T>
class CMatrice
{
private:
	T ** pptElement;
	unsigned int uiNbLigne;
	unsigned int uiNbColonne;
public:
	CMatrice();
	CMatrice(unsigned int uiNbLigneParam, unsigned int uiNbColonneParam);
	CMatrice(unsigned int uiNbLigneParam, unsigned int uiNbColonneParam, T ** TMATParam);
	CMatrice(CMatrice &MATPar);
	~CMatrice();
	CMatrice operator*(const T c);
	CMatrice operator/(const T c);
	void MAT_afficher();
	CMatrice operator+(const CMatrice &MATPar);
	CMatrice operator-(const CMatrice &MATPar);
	CMatrice operator*(const CMatrice &MATPar);
	CMatrice operator=(const CMatrice &MATPar);
	CMatrice MAT_Transposee();
	void MAT_creation2_2(T a,T b,T c,T d);
};

#include "Matrice.cpp"

#endif
#ifndef _MATRIX__H
#define _MATRIX__H

#include <iostream>
using namespace std;


class Matrix
{
private:
	int n;
	double** a;
	double* b;
	double* x;
	
public:
	Matrix(int size, double** coeff, double* results);
	double solve();
	friend ostream& operator<<(ostream& stream, const Matrix& m);
	
	
};

Matrix::Matrix(int size, double** coeff, double* r) : n(size),a(coeff),b(results)
{
	this->x = new double[this->n];
	for(int i = 0; i < this->n; i ++)
	{
		this->x[i] = 0;
	}
		
}


double Matrix::solve()
{
	double f;	
	
	//Dreiecksmatrix bestimmen
	for(int i = 0; i < this->n; i++)
	{
		for(int j = i+1; j < this->n; j++)
		{
			f = this->a[j][i]/this->a[i][i];
			
			for(int k = 0; k < this->n; k++)
			{
				this->a[j][k] = this->a[j][k] - f*this->a[i][k];
			}
		
			this->b[j] = this->b[j] - f*this->b[i];
		}
	}
	
	//Rueckwaertseinsetzen
	for(int i = this->n-1; i >= 0; i--)
	{
		double z = this->b[i]; //z=letztes Spaltenskalar
		
		for(int j = i+1; j < this->n; j++)
		{
			z = z - (this->x[j]*this->a[i][j]); //Subtrahieren von vorhanden x-Werten * sein Koeffizient
		}
		
		if(this->a[i][i] == 0)
		{
			cout << "DEERP";
			exit(0);
		}
		this->x[i] = z/this->a[i][i];
	}
	
	return x;
}


ostream& operator<<(ostream& stream, const Matrix& m)
{
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			if(j+1 == m.n)
				stream << m.a[i][j] << (char)(j+97) <<" = ";
			else
				stream << m.a[i][j] << (char)(j+97) << " + ";
		}
		
		stream << m.b[i] << endl;
	}
	
	return stream;
}

#endif
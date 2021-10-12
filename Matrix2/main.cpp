#include "Matrix.h"
#include <iostream>
#include <windows.h>
#include <complex>
using namespace std;
int CheckTypeInt()
{
	char per[100]{ 0 };
	gets_s(per);
	while (strlen(per) == 0)
	{
		cout << "An incorrect value was entered. Please try again: ";
		gets_s(per);
	}
	for (int i = 0; i < (int)strlen(per); i++)
	{
		if (per[i] == '-' && i == 0) i++;
		if (per[i] < '0' || per[i] > '9')
		{
			cout << "An incorrect value was entered. Please try again: ";
			gets_s(per);
			while (strlen(per) == 0)
			{
				cout << "An incorrect value was entered. Please try again: ";
				gets_s(per);
			}
			i = -1;
		}
	}
	int result = atoi(per);
	return result;
}

double CheckTypeDouble()
{
	char per[100]{ 0 };
	gets_s(per);
	int kol_t = 0;
	while (strlen(per) == 0)
	{
		cout << "An incorrect value was entered. Please try again: ";
		gets_s(per);
	}
	for (int i = 0; i < (int)strlen(per); i++)
	{
		if (per[i] == '-' && i == 0) i++;
		if (per[i] == '.')
		{
			kol_t++;
			i++;
		}
		if (per[i] < '0' || per[i] > '9' || kol_t > 1)
		{
			cout << "An incorrect value was entered. Please try again: ";
			gets_s(per);
			kol_t = 0;
			while (strlen(per) == 0)
			{
				cout << "An incorrect value was entered. Please try again: ";
				gets_s(per);
			}
			i = -1;
		}
	}
	double result = atof(per);
	return result;
}

float CheckTypeFloat()
{
	char per[100]{ 0 };
	gets_s(per);
	int kol_t = 0;
	while (strlen(per) == 0)
	{
		cout << "An incorrect value was entered. Please try again: ";
		gets_s(per);
	}
	for (int i = 0; i < (int)strlen(per); i++)
	{
		if (per[i] == '-' && i == 0) i++;
		if (per[i] == '.')
		{
			kol_t++;
			i++;
		}
		if (per[i] < '0' || per[i] > '9' || kol_t > 1)
		{
			cout << "An incorrect value was entered. Please try again: ";
			gets_s(per);
			kol_t = 0;
			while (strlen(per) == 0)
			{
				cout << "An incorrect value was entered. Please try again: ";
				gets_s(per);
			}
			i = -1;
		}
	}
	float result = (float)atof(per);
	return result;
}

void CreatingComplexValue(complex<float>& number)
{
	float a, b;
	cout << "Complex<float>: z = a + b*i" << endl;
	cout << "a,b - numbers, (i)^2 = -1" << endl;
	cout << "Enter the value of a: ";
	a = CheckTypeFloat();
	cout << "Enter the value of b: ";
	b = CheckTypeFloat();
	complex<float> TempComplexFloat(a, b);
	number += TempComplexFloat;
}

void CreatingComplexValue(complex<double>& number)
{
	double a, b;
	cout << "Complex<float>: z = a + b*i" << endl;
	cout << "a,b - numbers, (i)^2 = -1" << endl;
	cout << "Enter the value of a: ";
	a = CheckTypeFloat();
	cout << "Enter the value of b: ";
	b = CheckTypeFloat();
	complex<double> TempComplexDouble(a, b);
	number += TempComplexDouble;
}


template <typename T>
void CreatingProcess(Matrix<T>& matrix, int& MatrixType)
{
	int row = 0, col = 0, PointInt = 0;
	double PointDouble = 0;
	float PointFloat = 0, k = 0, z = 0;
	complex<float> PointComplexFloat(k, z);
	complex<double> PointComplexDouble(k, z);
	int CreatingOption = 1;
	cout << "Do you want to fill the matrix with a single value or manually?" << endl;
	cout << "1 - Manually" << endl;
	cout << "0 - With a single value" << endl;
	cout << "Enter your choice : ";
	CreatingOption = CheckTypeInt();
	while (CreatingOption < 0 || CreatingOption > 1)
	{
		cout << "There is no such item in the menu. Repeat the input: ";
		CreatingOption = CheckTypeInt();
	}
	cout << "Enter the number of rows of the matrix: ";
	row = CheckTypeInt();
	while (row <= 0)
	{
		cout << "The number of rows must be a positive number. Repeat the input: ";
		row = CheckTypeInt();
	}
	cout << "Enter the number of columns of the matrix: ";
	col = CheckTypeInt();
	while (col <= 0)
	{
		cout << "The number of columns must be a positive number. Repeat the input: ";
		col = CheckTypeInt();
	}
	if (CreatingOption == 0)
	{
		cout << "Enter the value that you would like to fill in the matrix with: ";
		if (MatrixType == 1) PointInt = CheckTypeInt();
		else if (MatrixType == 2) PointFloat = CheckTypeFloat();
		else if (MatrixType == 3) PointDouble = CheckTypeDouble();
		else if (MatrixType == 4) CreatingComplexValue(PointComplexFloat); 
		else if (MatrixType == 5) CreatingComplexValue(PointComplexDouble);  
	}
	if (MatrixType == 1)
	{
		Matrix<int> matrix2(row, col, PointInt);
		matrix = matrix2;
	}
	if (MatrixType == 2)
	{
		Matrix<float> matrix2(row, col, PointFloat);
		matrix = matrix2;
	}
	else if (MatrixType == 3)
	{
		Matrix<double> matrix2(row, col, PointDouble);
		matrix = matrix2;
	}
	else if (MatrixType == 4)
	{
		Matrix<complex<float>> matrix2(row, col, PointComplexFloat);
		matrix = matrix2;
	}
	else if (MatrixType == 5)
	{
		Matrix <complex<double>> matrix2(row, col, PointComplexDouble);
		matrix = matrix2;
	}

	if (CreatingOption == 1) 
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << "Matrix[" << i << "][" << j << "] = ";
				ReadValueInMatrix(matrix, i, j);		
			}
		}
	}
}

void ReadValueInMatrix(Matrix<int>& matrix, int row, int col)
{
	matrix(row, col) = CheckTypeInt();  
}

void ReadValueInMatrix(Matrix<float>& matrix, int row, int col)
{
	matrix(row, col) = CheckTypeFloat();
}

void ReadValueInMatrix(Matrix<double>& matrix, int row, int col)
{
	matrix(row, col) = CheckTypeDouble(); 
}

void ReadValueInMatrix(Matrix<complex<float>>& matrix, int row, int col)
{
	float a, b;
	cout << "Complex<float>: z = a + b*i" << endl;
	cout << "a,b - numbers, (i)^2 = -1" << endl;
	cout << "Enter the value of a: ";
	a = CheckTypeFloat();
	cout << "Enter the value of b: ";
	b = CheckTypeFloat();
	complex<float>ComplexFloatNumber(a, b);
	matrix(row, col) = ComplexFloatNumber;
}

void ReadValueInMatrix(Matrix<complex<double>>& matrix, int row, int col)
{
	double a, b;
	cout << "Complex<double>: z = a + b*i" << endl;
	cout << "a,b - numbers, (i)^2 = -1" << endl;
	cout << "Enter the value of a: ";
	a = CheckTypeDouble();
	cout << "Enter the value of b: ";
	b = CheckTypeDouble();
	complex<double>ComplexDoubleNumber(a, b);
	matrix(row, col) = ComplexDoubleNumber;
}

template <typename T>
void ReadingOrWritingElements(Matrix<T>& matrix)
{
	int menu = 1;
	do
	{
		system("cls");
		cout << "Enter the row number of the element: ";
		int RowIndex = CheckTypeInt();
		while (RowIndex < 0 || RowIndex >= matrix.GetN())
		{
			cout << "The row number of the element mustn't be out of range of the matrix. Repeat the input: ";
			RowIndex = CheckTypeInt();
		}
		cout << "Enter the column number of the element: ";
		int ColIndex = CheckTypeInt();
		while (ColIndex < 0 || ColIndex >= matrix.GetM())
		{
			cout << "The column number of the element mustn't be out of range of the matrix. Repeat the input: ";
			ColIndex = CheckTypeInt();
		}
		cout << "Matrix[" << RowIndex << "][" << ColIndex << "] = " << matrix(RowIndex, ColIndex) << endl;
		cout << "Do you want to change value of Matrix[" << RowIndex << "][" << ColIndex << "]?" << endl;
		cout << "1 - Yes" << endl;
		cout << "0 - No" << endl;
		cout << "Enter your choice : ";
		menu = CheckTypeInt();
		while (menu < 0 || menu > 1)
		{
			cout << "There is no such item in the menu. Repeat the input: ";
			menu = CheckTypeInt();
		}
		if (menu == 1)
		{
			cout << "Enter a new value for the element: ";
			ReadValueInMatrix(matrix, RowIndex, ColIndex);
		}
		cout << "1 - Repeat" << endl;
		cout << "0 - Back" << endl;
		cout << "Enter your choice : ";
		menu = CheckTypeInt();
		while (menu < 0 || menu > 1)
		{
			cout << "There is no such item in the menu. Repeat the input: ";
			menu = CheckTypeInt();
		}
	} while (menu != 0);
}

template <typename T1, typename T2>
void DoingArithmeticOperations(Matrix<T1>& matrix1, Matrix<T2>& matrix2, int MatrixType1, int MatrixType2)
{
	int menu = 1;
	do
	{
		int NumberInt = 0;
		float NumberFloat = 0;
		double NumberDouble = 0;
		complex<float> NumberComplexFloat(NumberFloat, NumberFloat);
		complex<double> NumberComplexDouble(0, 0);
		system("cls");
		cout << "1 - Matrices addition" << endl;
		cout << "2 - Matrices subtraction" << endl;
		cout << "3 - Matrices multiplication" << endl;
		cout << "4 - Matrix multiplication by a scalar" << endl;
		cout << "5 - Matrix division by a scalar" << endl;
		cout << "0 - Back" << endl;
		cout << "Enter your choice : ";
		menu = CheckTypeInt();
		while (menu < 0 || menu > 5)
		{
			cout << "There is no such item in the menu. Repeat the input: ";
			menu = CheckTypeInt();
		}
		if (menu == 0) break;
		if (menu >= 1 && menu <= 3 && MatrixType1 != MatrixType2) cout << "The matrices must be of the same type!" << endl;
		else if ((menu == 1 || menu == 2) && (matrix1.GetM() != matrix2.GetM() || matrix1.GetN() != matrix2.GetN()))
		{
			cout << "The matrices must be of the same dimension!";
		}
		else if (menu == 1 && (matrix1.GetM() == matrix2.GetM() && matrix1.GetN() == matrix2.GetN()))
		{
			cout << matrix1 + matrix2;
		}
		else if (menu == 2 && (matrix1.GetM() == matrix2.GetM() && matrix1.GetN() == matrix2.GetN()))
		{
			cout << "1 - Subtract the second matrix from the first one" << endl;
			cout << "2 - Subtract the first matrix from the second one" << endl;
			cout << "Enter your choice : ";
			menu = CheckTypeInt();
			while (menu < 1 || menu > 2)
			{
				cout << "There is no such item in the menu. Repeat the input: ";
				menu = CheckTypeInt();
			}
			if (menu == 1) cout << matrix1 - matrix2;
			else cout << matrix2 - matrix1;
		}
		else if (menu == 3)
		{
			cout << "1 - Multiplying the first matrix by the second" << endl;
			cout << "2 - Multiplying the second matrix by the first" << endl;
			cout << "Enter your choice : ";
			menu = CheckTypeInt();
			while (menu < 1 || menu > 2)
			{
				cout << "There is no such item in the menu. Repeat the input: ";
				menu = CheckTypeInt();
			}
			if ((menu == 1 && (matrix1.GetM() != matrix2.GetN())) || (menu == 2 && (matrix2.GetM() != matrix1.GetN())))
			{
				cout << "The number of columns of the first matrix must be equal to the number of rows of the second matrix!" << endl;
			}
			if (MatrixType1 != MatrixType2) cout << "The matrices must be the same type!" << endl;
			else if (menu == 1) cout << matrix1 * matrix2;
			else if (menu == 2) cout << matrix2 * matrix1;
		}
		else if (menu == 4 || menu == 5)
		{
			cout << "Select the matrix that you would like to work with: (1 or 2) " << endl;
			cout << "Enter your choice : ";
			int MatrixNumber = CheckTypeInt();
			while (MatrixNumber < 1 || MatrixNumber > 2)
			{
				cout << "There is no such item in the menu. Repeat the input: ";
				MatrixNumber = CheckTypeInt();
			}


			cout << "Write a number: ";
			if (MatrixNumber == 1)
			{
				if (MatrixType1 == 1) NumberInt = CheckTypeInt();
				else if (MatrixType1 == 2) NumberFloat = CheckTypeFloat();
				else if (MatrixType1 == 3) NumberDouble = CheckTypeDouble();
				else if (MatrixType1 == 4) CreatingComplexValue(NumberComplexFloat);
				else if (MatrixType1 == 5) CreatingComplexValue(NumberComplexDouble);
			}
			else if (MatrixNumber == 2)
			{
				if (MatrixType2 == 1) NumberInt = CheckTypeInt();
				else if (MatrixType2 == 2) NumberFloat = CheckTypeFloat();
				else if (MatrixType2 == 3) NumberDouble = CheckTypeDouble();
				else if (MatrixType1 == 4) CreatingComplexValue(NumberComplexFloat);
				else if (MatrixType1 == 5) CreatingComplexValue(NumberComplexDouble);
			}
			if (menu == 4 && MatrixNumber == 1)
			{
				if (MatrixType1 == 1) cout << matrix1 * NumberInt;
				else if (MatrixType1 == 2) cout << matrix1 * NumberFloat;
				else if (MatrixType1 == 3) cout << matrix1 * NumberDouble;
				else if (MatrixType1 == 4) cout << matrix1 * NumberComplexFloat;
				else if (MatrixType1 == 5) cout << matrix1 * NumberComplexDouble;  
			}
			else if (menu == 4 && MatrixNumber == 2)
			{
				if (MatrixType2 == 1) cout << matrix2 * NumberInt;
				else if (MatrixType2 == 2) cout << matrix2 * NumberFloat;
				else if (MatrixType2 == 3) cout << matrix2 * NumberDouble;
				else if (MatrixType2 == 4) cout << matrix2 * NumberComplexFloat;
				else if (MatrixType2 == 5) cout << matrix2 * NumberComplexDouble;
			}
			if (NumberInt == 0 && NumberFloat == 0 && NumberDouble == 0 && NumberComplexFloat == (NumberFloat, NumberFloat) && NumberComplexDouble == (NumberDouble , NumberDouble) && menu == 5) cout << "Division by zero!" << endl; 
			else if (menu == 5 && MatrixNumber == 1)
			{
				if (MatrixType1 == 1) cout << matrix1 / NumberInt;
				else if (MatrixType1 == 2) cout << matrix1 / NumberFloat;
				else if (MatrixType1 == 3) cout << matrix1 / NumberDouble;
				else if (MatrixType1 == 4) cout << matrix1 / NumberComplexFloat;
				else if (MatrixType1 == 5) cout << matrix1 / NumberComplexDouble;  
			}
			else if (menu == 5 && MatrixNumber == 2)
			{
				if (MatrixType2 == 1) cout << matrix2 / NumberInt;
				else if (MatrixType2 == 2) cout << matrix2 / NumberFloat;
				else if (MatrixType2 == 3) cout << matrix2 / NumberDouble;
				else if (MatrixType2 == 4) cout << matrix2 / NumberComplexFloat;
				else if (MatrixType2 == 5) cout << matrix2 / NumberComplexDouble;
			}
		}
		cout << "1 - Repeat" << endl;
		cout << "0 - Back" << endl;
		cout << "Enter your choice : ";
		menu = CheckTypeInt();
		while (menu < 0 || menu > 1)
		{
			cout << "There is no such item in the menu. Repeat the input: ";
			menu = CheckTypeInt();
		}
	} while (menu != 0);
}

void ChooseTypeOfMatrix(int& MatrixType)
{
	cout << "Choose a type of Matrix: " << endl;
	cout << "1 - Int" << endl;
	cout << "2 - Float" << endl;
	cout << "3 - Double" << endl;
	cout << "4 - Complex<float>" << endl;
	cout << "5 - Complex<double>" << endl;
	cout << "Enter your choice : ";
	MatrixType = CheckTypeInt();
	while (MatrixType < 1 || MatrixType > 5)
	{
		cout << "There is no such item in the menu. Repeat the input: ";
		MatrixType = CheckTypeInt();
	}
}

template <typename T1, typename T2>
void Program(Matrix<T1>& matrix1, Matrix<T2>& matrix2, int MatrixType1, int MatrixType2)
{
	int menu = 1;
	do
	{
		system("cls");
		cout << "Laboratory work #1. Option #2" << endl;
		cout << "1 - Reads/writes of the matrix element by the indexes" << endl;
		cout << "2 - Performing arithmetic operations" << endl;
		cout << "3 - Calculating the trace of the matrix" << endl;
		cout << "4 - Matrix comparison" << endl;
		cout << "0 - Exit" << endl;
		cout << "Enter your choice : ";
		menu = CheckTypeInt();
		while (menu < 0 || menu > 4)
		{
			cout << "There is no such item in the menu. Repeat the input: ";
			menu = CheckTypeInt();
		}
		if (menu == 1 || menu == 3)
		{
			int MatrixNumber;
			system("cls");
			cout << "Reads/writes of the matrix element by the indexes (1 or 2)" << endl;
			cout << "Enter your choice : ";
			MatrixNumber = CheckTypeInt();
			while (MatrixNumber < 1 || MatrixNumber > 2)
			{
				cout << "Only 2 matrices are available. Repeat the input: ";
				MatrixNumber = CheckTypeInt();
			}
			if (MatrixNumber == 1 && menu == 1) ReadingOrWritingElements(matrix1);
			else if (MatrixNumber == 2 && menu == 1) ReadingOrWritingElements(matrix2);
			else if (MatrixNumber == 1 && menu == 3)
			{
				cout << "Matrix trace = " << matrix1.MatrixTrace();
				Sleep(2000);
			}
			else
			{
				cout << "Matrix trace = " << matrix2.MatrixTrace();
				Sleep(2000);
			}
		}
		else if (menu == 2) DoingArithmeticOperations(matrix1, matrix2, MatrixType1, MatrixType2); 
		else if (menu == 4 && matrix1 == matrix2)
		{
			cout << "The matrices are equal";
			Sleep(2000);
		}
		else if (menu == 4 && matrix1 != matrix2) 
		{
			cout << "The matrices are not equal";
			Sleep(2000);
		}
	} while (menu != 0);
}

int main()
{
	try
	{
		SetConsoleOutputCP(1251);
		float a = 0;
		complex<float> PointComplexFloat = (a, a);
		complex<double> PointComplexDouble = (a, a);
		Matrix<int> MatrixInt1(3, 3, 0), MatrixInt2(3, 3, 0);
		Matrix<float> MatrixFloat1(3, 3, a), MatrixFloat2(3, 3, a);
		Matrix<double> MatrixDouble1(3, 3, 0), MatrixDouble2(3, 3, 0);
		Matrix<complex<float>> MatrixComplexFloat1(3, 3, (a, a)), MatrixComplexFloat2(3, 3, (a, a));
		Matrix<complex<double>> MatrixComplexDouble1(3, 3, (1.2, 1.2)), MatrixComplexDouble2(3, 3, (1.2, 1.2));
		int MatrixType1 = 1, MatrixType2 = 1;
		cout << "Laboratory work ¹1. Option ¹2" << endl;
		cout << "Creating the first matrix:" << endl;
		ChooseTypeOfMatrix(MatrixType1); 
		if (MatrixType1 == 1) CreatingProcess(MatrixInt1, MatrixType1);
		else if (MatrixType1 == 2) CreatingProcess(MatrixFloat1, MatrixType1);
		else if (MatrixType1 == 3) CreatingProcess(MatrixDouble1, MatrixType1);
		else if (MatrixType1 == 4) CreatingProcess(MatrixComplexFloat1, MatrixType1);
		else if (MatrixType1 == 5) CreatingProcess(MatrixComplexDouble1, MatrixType1);
		cout << "Creating the second matrix:" << endl;
		ChooseTypeOfMatrix(MatrixType2);
		if (MatrixType2 == 1)
		{
			CreatingProcess(MatrixInt2, MatrixType2);
			if (MatrixType1 == 1) Program(MatrixInt1, MatrixInt2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 2) Program(MatrixFloat1, MatrixInt2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 3) Program(MatrixDouble1, MatrixInt2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 4) Program(MatrixComplexFloat1, MatrixInt2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 5) Program(MatrixComplexDouble1, MatrixInt2, MatrixType1, MatrixType2);
		}
		else if (MatrixType2 == 2)
		{
			CreatingProcess(MatrixFloat2, MatrixType2);
			if (MatrixType1 == 1) Program(MatrixInt1, MatrixFloat2, MatrixType1, MatrixType2);
			if (MatrixType1 == 2) Program(MatrixFloat1, MatrixFloat2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 3) Program(MatrixDouble1, MatrixFloat2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 4) Program(MatrixComplexFloat1, MatrixFloat2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 5) Program(MatrixComplexDouble1, MatrixFloat2, MatrixType1, MatrixType2);
		}
		else if (MatrixType2 == 3)
		{
			CreatingProcess(MatrixDouble2, MatrixType2);
			if (MatrixType1 == 1) Program(MatrixInt1, MatrixDouble2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 2) Program(MatrixFloat1, MatrixDouble2, MatrixType1, MatrixType2);
			if (MatrixType1 == 3) Program(MatrixDouble1, MatrixDouble2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 4) Program(MatrixComplexFloat1, MatrixDouble2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 5) Program(MatrixComplexDouble1, MatrixDouble2, MatrixType1, MatrixType2);
		}
		else if (MatrixType2 == 4)
		{
			CreatingProcess(MatrixComplexFloat2, MatrixType2);
			if (MatrixType1 == 1) Program(MatrixInt1, MatrixComplexFloat2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 2) Program(MatrixFloat1, MatrixComplexFloat2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 3) Program(MatrixDouble1, MatrixComplexFloat2, MatrixType1, MatrixType2);
			if (MatrixType1 == 4) Program(MatrixComplexFloat1, MatrixComplexFloat2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 5) Program(MatrixComplexDouble1, MatrixComplexFloat2, MatrixType1, MatrixType2);
		}
		else if (MatrixType2 == 5)
		{
			CreatingProcess(MatrixComplexDouble2, MatrixType2);
			if (MatrixType1 == 1) Program(MatrixInt1, MatrixComplexDouble2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 2) Program(MatrixFloat1, MatrixComplexDouble2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 3) Program(MatrixDouble1, MatrixComplexDouble2, MatrixType1, MatrixType2);
			else if (MatrixType1 == 4) Program(MatrixComplexFloat1, MatrixComplexDouble2, MatrixType1, MatrixType2);
			if (MatrixType1 == 5) Program(MatrixComplexDouble1, MatrixComplexDouble2, MatrixType1, MatrixType2);
		}
	}
	catch (const char* exception)
	{
		cout << exception;
	}
	return 0;
}
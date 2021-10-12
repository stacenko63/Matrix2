#include "pch.h"
#include "CppUnitTest.h"
#include "..\Matrix2\Matrix.h"
#include <complex>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(ConstructorTest)
		{
			Matrix<int> matrix(2, 2, 5);
			Assert::IsTrue((matrix.GetN() == 2 && matrix.GetM() == 2 && matrix(0, 0) == 5 && matrix(0, 1) == 5 && matrix(1, 0) == 5 && matrix(1, 1) == 5), L"Fail in constructor: Matrix matrix(2, 3, 5)");
			Matrix<int> matrix7(3,3,0);
			Assert::IsTrue((matrix7.GetN() == 3 && matrix7.GetM() == 3 && matrix7(0, 0) == 0 && matrix7(0, 1) == 0 && matrix7(0, 2) == 0 && matrix7(1, 0) == 0 && matrix7(1, 1) == 0 && matrix7(1, 2) == 0 && matrix7(2, 0) == 0 && matrix7(2, 1) == 0 && matrix7(2, 2) == 0), L"Fail in constructor: Matrix matrix()");
			float number = 2.5; 
			Matrix<float> MatrixFloat(2, 2, number);
			Assert::IsTrue((MatrixFloat.GetN() == 2 && MatrixFloat.GetM() == 2 && MatrixFloat(0, 0) == 2.5 && MatrixFloat(0, 1) == 2.5 && MatrixFloat(1, 0) == 2.5 && MatrixFloat(1, 1) == 2.5), L"Fail in constructor: Matrix matrix(2, 3, 5)");
			Matrix<double> MatrixDouble(2, 2, 2.5);
			Assert::IsTrue((MatrixDouble.GetN() == 2 && MatrixDouble.GetM() == 2 && MatrixDouble(0, 0) == 2.5 && MatrixDouble(0, 1) == 2.5 && MatrixDouble(1, 0) == 2.5 && MatrixDouble(1, 1) == 2.5), L"Fail in constructor: Matrix matrix(2, 3, 5)");
			float a = 1, b = 1;
			Matrix<complex<float>> MatrixComplexFloat(2, 2, (a, b));
			Assert::IsTrue((MatrixComplexFloat.GetN() == 2 && MatrixComplexFloat.GetM() == 2 && MatrixComplexFloat(0, 0) == (a,b) && MatrixComplexFloat(0, 1) == (a,b) && MatrixComplexFloat(1, 0) == (a,b) && MatrixComplexFloat(1, 1) == (a,b)), L"Fail in constructor: Matrix matrix(2, 3, 5)");
			double c = 1, d = 1;
			Matrix<complex<double>> MatrixComplexDouble(2, 2, (c, d)); 
			Assert::IsTrue((MatrixComplexDouble.GetN() == 2 && MatrixComplexDouble.GetM() == 2 && MatrixComplexDouble(0, 0) == (c, d) && MatrixComplexDouble(0, 1) == (c, d) && MatrixComplexDouble(1, 0) == (c, d) && MatrixComplexDouble(1, 1) == (c, d)), L"Fail in constructor: Matrix matrix(2, 3, 5)");
			bool check = false;
			try
			{
				Matrix<int> matrix1(-1, 9, 8);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail in constructor (Unhandled exception: row and col must be greater than 0): Matrix matrix(-1,9,8)";
			check = false;
			try
			{
				Matrix<int> matrix2(4, -1, 8);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail in constructor (Unhandled exception: row and col must be greater than 0): Matrix matrix(-1,9,8)";
			check = false;
			try
			{
				Matrix<int> matrix3(-1, -1, 8);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail in constructor (Unhandled exception: row and col must be greater than 0): Matrix matrix(-1,9,8)";
			check = false;
			try
			{
				Matrix<int> matrix4(0, 7, 8);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail in constructor (Unhandled exception: row and col must be greater than 0): Matrix matrix(-1,9,8)";
			check = false;
			try
			{
				Matrix<int> matrix5(4, 0, 8);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail in constructor (Unhandled exception: row and col must be greater than 0): Matrix matrix(-1,9,8)";
			check = false;
			try
			{
				Matrix<int> matrix6(0, 0, 8);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail in constructor (Unhandled exception: row and col must be greater than 0): Matrix matrix(-1,9,8)";
		}

		TEST_METHOD(CopyConstructorTest)
		{
			Matrix<int> matrix1(2, 2, 4);
			Matrix<int> matrix2(matrix1); 
			Assert::IsTrue(matrix1.GetM() == matrix2.GetM() && matrix1.GetN() == matrix2.GetM()), L"Fail: The matrices must be of the same dimension!";
			Assert::IsTrue(matrix1(0, 0) == matrix2(0, 0) && matrix1(0, 1) == matrix2(0, 1) && matrix1(1, 0) == matrix2(1, 0) && matrix1(1, 1) == matrix2(1, 1)), L"Fail: The matrices must have the same values";
			matrix2(0, 0) = 1;
			Assert::IsTrue(matrix1(0, 0) != matrix2(0, 0)), L"Fail: The matrices must have different references";
		}

		TEST_METHOD(MatrixTraceTest)
		{
			Matrix<int> matrix1(3, 3, 4);
			Assert::IsTrue(matrix1.MatrixTrace() == 12), L"Fail: Incorrent Answer: matrix(3,3,4)";
			Matrix<int> matrix2(5, 5, 7);
			Assert::IsTrue(matrix2.MatrixTrace() == 35), L"Fail: Incorrent Answer: matrix(5,5,7)";
			Matrix<int> matrix3(2, 3, 5);
			Assert::IsTrue(matrix3.MatrixTrace() == 10), L"Fail: Incorrent Answer: matrix(2,3,5)";
			Matrix<int> matrix4(3, 2, 7);
			Assert::IsTrue(matrix4.MatrixTrace() == 14), L"Fail: Incorrent Answer: matrix(3,2,7)";
			Matrix<float> MatrixFloat(2, 2, 3);
			Assert::IsTrue(MatrixFloat.MatrixTrace() == 6), L"Fail: Incorrent Answer: matrix(3,2,7)";
			Matrix<double> MatrixDouble(3, 3, 6);
			Assert::IsTrue(MatrixDouble.MatrixTrace() == 18), L"Fail: Incorrent Answer: matrix(3,2,7)"; 
			float a = 2, b = 3;
			double c = 2, d = 3; 
			Matrix<complex<float>>MatrixComplexFloat(3, 3, (a, b));
			Assert::IsTrue(MatrixComplexFloat.MatrixTrace() == (2*a,3*b)), L"Fail: Incorrent Answer: matrix(3,2,7)";
			Matrix<complex<double>>MatrixComplexDouble(3, 3, (c, d));
			Assert::IsTrue(MatrixComplexDouble.MatrixTrace() == (2*c, 3*d)), L"Fail: Incorrent Answer: matrix(3,2,7)";
		}

		TEST_METHOD(MatricesMultiplicationTest)
		{
			Matrix<int> matrix1(3, 3, 3), matrix2(3, 3, 9);
			Matrix<int> matrix3 = matrix1 * matrix2;
			Assert::IsTrue(matrix3.GetN() == 3 && matrix3.GetM() == 3 && matrix3(0, 0) == 81 && matrix3(0, 1) == 81 && matrix3(0, 2) == 81 && matrix3(1, 0) == 81 && matrix3(1, 1) == 81 && matrix3(1, 2) == 81 && matrix3(2, 0) == 81 && matrix3(2, 1) == 81 && matrix3(2, 2) == 81), L"Fail: Incorrect Answer: matrix(3,3,3) * matrix(3,3,9)";
			Matrix<int> matrix4(2, 2, 2), matrix5(2, 2, 3);
			Matrix<int> matrix6 = matrix4 * matrix5;
			Assert::IsTrue(matrix6.GetN() == 2 && matrix6.GetM() == 2 && matrix6(0, 0) == 12 && matrix6(0, 1) == 12 && matrix6(1, 0) == 12 && matrix6(1, 1) == 12), L"Fail: Incorrect Answer : matrix(2, 2, 2) * matrix(2, 2, 3)";
			Matrix<int> matrix11(3, 3, 9), matrix12(3, 3, 3);
			matrix11(1, 1) = 5;
			matrix11(2, 2) = 6;
			matrix12(1, 0) = 1;
			matrix12(2, 2) = 2;
			Matrix<int> matrix13 = matrix11 * matrix12;
			Assert::IsTrue(matrix13.GetN() == 3 && matrix13.GetM() == 3 && matrix13(0, 0) == 63 && matrix13(0, 1) == 81 && matrix13(0, 2) == 72 && matrix13(1, 0) == 59 && matrix13(1, 1) == 69 && matrix13(1, 2) == 60 && matrix13(2, 0) == 54 && matrix13(2, 1) == 72 && matrix13(2, 2) == 66), L"Fail: Incorrect Answer: matrix(3,3,3) * matrix(3,3,9)";
			Matrix<int> matrix14(2, 2, 3), matrix15(2, 2, 2);
			matrix14(0, 0) = 4;
			matrix14(0, 1) = 7;
			matrix14(1, 0) = 9;
			matrix15(0, 0) = 1;
			matrix15(0, 1) = 3;
			matrix15(1, 0) = 9;
			Matrix<int> matrix16 = matrix14 * matrix15;
			Assert::IsTrue(matrix16.GetN() == 2 && matrix16.GetM() == 2 && matrix16(0, 0) == 67 && matrix16(0, 1) == 26 && matrix16(1, 0) == 36 && matrix16(1, 1) == 33), L"Fail: Incorrect Answer : matrix(2, 2, 2) * matrix(2, 2, 3)";
			bool check = false;
			try
			{
				Matrix<int> matrix19(5, 5, 8), matrix20(4, 5, 2);
				Matrix<int> matrix21 = matrix19 * matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail Matrices Multiplication (Unhandled exception: The number of columns of the first matrix must be equal to the number of rows of the second matrix!): matrix1(5,5,8)*matrix(4,5,2)";
			check = false;
			try
			{
				Matrix<int> MatrixInt(3, 3, 2);
				Matrix<double> MatrixDouble(3, 3, 2);
				MatrixInt* MatrixDouble; 
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true), L"Fail Matrices Multiplication (Unhandled exception: The number of columns of the first matrix must be equal to the number of rows of the second matrix!): matrix1(5,5,8)*matrix(4,5,2)";
			check = false; 
		}

		TEST_METHOD(EqualityOperatorTest)
		{
			Matrix<int> matrix1(2, 2, 2), matrix2(2, 2, 2);
			Matrix<double> MatrixDouble(2, 2, 2);
			Assert::IsTrue((MatrixDouble == matrix1) == false);
			Assert::IsTrue((matrix1 == matrix2) == true); 
			Assert::IsTrue((matrix2 == matrix1) == true);
			Matrix<int> matrix3(2, 3, 2), matrix4(2, 2, 2);
			Assert::IsTrue((matrix3 == matrix4) == false);
			Assert::IsTrue((matrix4 == matrix3) == false);
			Matrix<int> matrix5(3, 2, 2);
			Assert::IsTrue((matrix3 == matrix5) == false);
			Assert::IsTrue((matrix5 == matrix3) == false);
			Matrix<int> matrix6(4, 4, 2); 
			Assert::IsTrue((matrix6 == matrix4) == false);
			Assert::IsTrue((matrix4 == matrix6) == false);
			Matrix<int> matrix7(2, 2, 3); 
			Assert::IsTrue((matrix1 == matrix7) == false);
			Assert::IsTrue((matrix7 == matrix1) == false);
		}

		TEST_METHOD(NotEqualityOperatorTest)
		{
			Matrix<int> matrix1(2, 2, 2), matrix2(2, 2, 2);
			Matrix<double> MatrixDouble(2, 2, 2);
			Assert::IsTrue((MatrixDouble != matrix1) == true);
			Assert::IsTrue((matrix1 != matrix2) == false);
			Assert::IsTrue((matrix2 != matrix1) == false);
			Matrix<int> matrix3(2, 3, 2), matrix4(2, 2, 2);
			Assert::IsTrue((matrix3 != matrix4) == true);
			Assert::IsTrue((matrix4 != matrix3) == true);
			Matrix<int> matrix5(3, 2, 2);
			Assert::IsTrue((matrix3 != matrix5) == true);
			Assert::IsTrue((matrix5 != matrix3) == true);
			Matrix<int> matrix6(4, 4, 2);
			Assert::IsTrue((matrix6 != matrix4) == true);
			Assert::IsTrue((matrix4 != matrix6) == true);
			Matrix<int> matrix7(2, 2, 3);
			Assert::IsTrue((matrix1 != matrix7) == true);
			Assert::IsTrue((matrix7 != matrix1) == true);
		}

		TEST_METHOD(AdditionOperatorTest)
		{
			Matrix<int> matrix1(3, 3, 4), matrix2(3, 3, 2);
			Matrix<int> matrix3 = matrix1 + matrix2;
			Assert::IsTrue(matrix3.GetM() == 3 && matrix3.GetN() == 3 && matrix3(0, 0) == 6 && matrix3(0, 1) == 6 && matrix3(0, 2) == 6 && matrix3(1, 0) == 6 && matrix3(1, 1) == 6 && matrix3(1, 2) == 6 && matrix3(2, 0) == 6 && matrix3(2, 1) == 6 && matrix3(2, 2) == 6);
			Matrix<int> matrix4(2, 2, 3), matrix5(2, 2, 4);
			Matrix<int> matrix6 = matrix4 + matrix5;
			Assert::IsTrue(matrix6.GetM() == 2 && matrix6.GetN() == 2 && matrix6(0, 0) == 7 && matrix6(0, 1) == 7 && matrix6(1, 0) == 7 && matrix6(1, 1) == 7);
			bool check = false;
			try
			{
				Matrix<int> matrix19(5, 5, 8), matrix20(4, 5, 2);
				Matrix<int> matrix21 = matrix19 + matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				Matrix<int> matrix19(4, 5, 8), matrix20(5, 4, 2);
				Matrix<int> matrix21 = matrix19 + matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				Matrix<int> matrix19(4, 4, 8), matrix20(5, 5, 2);
				Matrix<int> matrix21 = matrix19 + matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				Matrix<int> MatrixInt(3, 3, 2);
				Matrix<double> MatrixDouble(3, 3, 2);
				MatrixInt + MatrixDouble;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
		}

		TEST_METHOD(SubtractionOperatorTest)
		{
			Matrix<int> matrix1(3, 3, 4), matrix2(3, 3, 2);
			Matrix<int> matrix3 = matrix1 - matrix2;
			Assert::IsTrue(matrix3.GetM() == 3 && matrix3.GetN() == 3 && matrix3(0, 0) == 2 && matrix3(0, 1) == 2 && matrix3(0, 2) == 2 && matrix3(1, 0) == 2 && matrix3(1, 1) == 2 && matrix3(1, 2) == 2 && matrix3(2, 0) == 2 && matrix3(2, 1) == 2 && matrix3(2, 2) == 2);
			Matrix<int> matrix4(2, 2, 3), matrix5(2, 2, 4);
			Matrix<int> matrix6 = matrix4 - matrix5;
			Assert::IsTrue(matrix6.GetM() == 2 && matrix6.GetN() == 2 && matrix6(0, 0) == -1 && matrix6(0, 1) == -1 && matrix6(1, 0) == -1 && matrix6(1, 1) == -1);
			bool check = false;
			try
			{
				Matrix<int> matrix19(5, 5, 8), matrix20(4, 5, 2);
				Matrix<int> matrix21 = matrix19 - matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				Matrix<int> matrix19(4, 5, 8), matrix20(5, 4, 2);
				Matrix<int> matrix21 = matrix19 - matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				Matrix<int> matrix19(4, 4, 8), matrix20(5, 5, 2);
				Matrix<int> matrix21 = matrix19 - matrix20;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				Matrix<int> MatrixInt(3, 3, 2);
				Matrix<double> MatrixDouble(3, 3, 2);
				MatrixInt + MatrixDouble;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
		}

		TEST_METHOD(MultiplicationByAScalarTest)
		{
			Matrix<int> matrix1(3, 3, 4);
			Matrix<int> matrix2 = matrix1 * 9;
			Assert::IsTrue(matrix2.GetM() == 3 && matrix2.GetN() == 3 && matrix2(0, 0) == 36 && matrix2(0, 1) == 36 && matrix2(0, 2) == 36 && matrix2(1, 0) == 36 && matrix2(1, 1) == 36 && matrix2(1, 2) == 36 && matrix2(2, 0) == 36 && matrix2(2, 1) == 36 && matrix2(2, 2) == 36);
			Matrix<int> matrix4(3, 3, 5);
			Matrix<int> matrix5 = matrix4 * 0;
			Assert::IsTrue(matrix5.GetM() == 3 && matrix5.GetN() == 3 && matrix5(0, 0) == 0 && matrix5(0, 1) == 0 && matrix5(0, 2) == 0 && matrix5(1, 0) == 0 && matrix5(1, 1) == 0 && matrix5(1, 2) == 0 && matrix5(2, 0) == 0 && matrix5(2, 1) == 0 && matrix5(2, 2) == 0);
			
			Matrix<float> MatrixFloat(3, 3, 5);
			float a = 2.5; 
			Matrix<float> MatrixFloat2 = MatrixFloat * a; 
			Assert::IsTrue(MatrixFloat2.GetM() == 3 && MatrixFloat2.GetN() == 3 && MatrixFloat2(0, 0) == 12.5 && MatrixFloat2(0, 1) == 12.5 && MatrixFloat2(0, 2) == 12.5 && MatrixFloat2(1, 0) == 12.5 && MatrixFloat2(1, 1) == 12.5 && MatrixFloat2(1, 2) == 12.5 &&	MatrixFloat2(2, 0) == 12.5 && MatrixFloat2(2, 1) == 12.5 && MatrixFloat2(2, 2) == 12.5);

			Matrix<double> MatrixDouble(3, 3, 5);
			Matrix<double> MatrixDouble2 = MatrixDouble * 2.5; 
			Assert::IsTrue(MatrixDouble2.GetM() == 3 && MatrixDouble2.GetN() == 3 && MatrixDouble2(0, 0) == 12.5 && MatrixDouble2(0, 1) == 12.5 && MatrixDouble2(0, 2) == 12.5 && MatrixDouble2(1, 0) == 12.5 && MatrixDouble2(1, 1) == 12.5 && MatrixDouble2(1, 2) == 12.5 && MatrixDouble2(2, 0) == 12.5 && MatrixDouble2(2, 1) == 12.5 && MatrixDouble2(2, 2) == 12.5);
			bool check = false; 
			try
			{
				Matrix<int> MatrixInt(3, 3, 2);
				MatrixInt * 9.23;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
		}
		  
		TEST_METHOD(DivisionByAScalarTest)
		{
			Matrix<double> matrix1(3, 3, 9);
			double value = 9;
			float ValueFloat = 0;
			Matrix<double> matrix2 = matrix1 / value;
			Assert::IsTrue(matrix2.GetM() == 3 && matrix2.GetN() == 3 && matrix2(0, 0) == 1 && matrix2(0, 1) == 1 && matrix2(0, 2) == 1 && matrix2(1, 0) == 1 && matrix2(1, 1) == 1 && matrix2(1, 2) == 1 && matrix2(2, 0) == 1 && matrix2(2, 1) == 1 && matrix2(2, 2) == 1);
			Matrix<double> matrix4(3, 3, 5);
			value = -2;
			Matrix<double> matrix5 = matrix4 / value;
			Assert::IsTrue(matrix5.GetM() == 3 && matrix5.GetN() == 3 && matrix5(0, 0) == -2.5 && matrix5(0, 1) == -2.5 && matrix5(0, 2) == -2.5 && matrix5(1, 0) == -2.5 && matrix5(1, 1) == -2.5 && matrix5(1, 2) == -2.5 && matrix5(2, 0) == -2.5 && matrix5(2, 1) == -2.5 && matrix5(2, 2) == -2.5);
			bool check = false;
			try
			{
				int ValueInt = 0;
				Matrix<int> MatrixInt(3, 3, 2);
				MatrixInt / ValueInt;  
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				Matrix<float> MatrixFloat(3, 3, 2);
				MatrixFloat / ValueFloat; 
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				value = 0; 
				Matrix<double> MatrixDouble(3, 3, 2);
				MatrixDouble / value;  
			}
			catch (const char* ex)
			{
				cout << ex; 
				check = true; 
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				complex<float> ComplexFloatNumber(ValueFloat, ValueFloat); 
				Matrix<complex<float>> MatrixDouble(3, 3, (ValueFloat, ValueFloat)); 
				MatrixDouble / ComplexFloatNumber;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try 
			{
				value = 0;
				complex<double> ComplexDoubleNumber(value, value); 
				Matrix<complex<double>> MatrixDouble(3, 3, (value,value)); 
				MatrixDouble / ComplexDoubleNumber;  
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				Matrix<int> MatrixInt(3, 3, 2);
				MatrixInt / 9.23;
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
		}

		TEST_METHOD(ReadAndWriteValueTest)
		{
			Matrix<int> matrix1(3, 3, 1);
			bool check = false;
			try
			{
				matrix1(3, 2);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(2, 3);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(3, 3);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(2, 4);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(4, 2);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(4, 4);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(2, -1);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(-1, 2);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			check = false;
			try
			{
				matrix1(-1, -1);
			}
			catch (const char* ex)
			{
				cout << ex;
				check = true;
			}
			Assert::IsTrue(check == true);
			matrix1(0, 0) = 3;
			Assert::IsTrue(matrix1(0, 0) == 3);
			matrix1(0, 1) = 7;
			Assert::IsTrue(matrix1(0, 1) == 7);
		}
	};
}

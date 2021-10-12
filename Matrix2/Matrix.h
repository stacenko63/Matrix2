#pragma once
#include <iostream> 
using namespace std;
template <class T>
class Matrix
{
private:
	int n, m;
	T** arr;
	template <typename T1>
	bool CheckDivisionByZero(T1)
	{
		//if (number == 0) return true;
		return false;
	}
	template<>
	bool CheckDivisionByZero(int number)
	{
		if (number == 0) return true;
		return false;
	}
	template<>
	bool CheckDivisionByZero(float number)
	{
		if (number == 0) return true;
		return false;
	}
	template<>
	bool CheckDivisionByZero(double number)
	{
		if (number == 0) return true;
		return false;
	}
	
public:
	int GetN() const
	{
		return n;
	}
	int GetM() const
	{
		return m;
	}
	Matrix(int n, int m, T value)
	{
		if (n > 0 && m > 0)
		{
			this->n = n;
			this->m = m;
			arr = new T * [n];
			for (int i = 0; i < n; i++) {
				arr[i] = new T[m];
			}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					arr[i][j] = value;
				}
			}
		}
		else throw "Incorrect matrix sizes are specified!";
	}
	Matrix(const Matrix<T>& other)
	{
		this->n = other.n;
		this->m = other.m;
		arr = new T * [n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new T[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = other.arr[i][j];
			}
		}
	}
	~Matrix()
	{
		for (int i = 0; i < n; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	T MatrixTrace() const
	{
		T trace = 0;
		for (int i = 0, j = 0; i < n && j < m; i++, j++)
		{
			trace += arr[i][j];
		}
		return trace;
	}
	Matrix<T> operator*(T number)
	{
		Matrix<T> temp(n, m, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp.arr[i][j] = arr[i][j] * number;
			}
		}
		return temp;
	}

	template <typename AT1>
	Matrix<T> operator*(AT1)
	{
		throw "Matrix type and number type must be the same!";
	}


	


	Matrix<T> operator/(T number)
	{
		if (CheckDivisionByZero(number)) throw "Division by 0";
		Matrix<T> temp(n, m, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp.arr[i][j] = arr[i][j] / number;
				if (temp.arr[i][j] != temp.arr[i][j]) throw "Division by 0";
			}
		}
		return temp;
	}


	template <typename T1>
	Matrix<T> operator/(T1)
	{
		throw "Matrix type and number type must be the same!";
	}


	Matrix<T> operator*(const Matrix<T>& other)
	{
		if (this->m == other.n)
		{
			Matrix<T> temp(this->n, other.m, 0);
			for (int i = 0; i < this->n; i++)
			{
				for (int k = 0; k < other.m; k++)
				{
					for (int j = 0; j < this->m; j++)
					{
						temp.arr[i][k] += this->arr[i][j] * other.arr[j][k];
					}
				}
			}
			return temp;
		}
		throw "The number of columns of the first matrix must be equal to the number of rows of the second matrix!";
	}
	template <typename T1>
	Matrix<T> operator*(const Matrix<T1> &)
	{
		throw "The matrices must be of the same type!";
	}
	template <typename T2>
	Matrix<T> operator+(const Matrix<T2> &)
	{
		throw "The matrices must be of the same type!";
	}
	bool operator==(const Matrix<T>& other)
	{
		if (this->n != other.n || this->m != other.m) return false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (this->arr[i][j] != other.arr[i][j]) return false;
			}
		}
		return true;
	}
	template <typename T4>
	bool operator==(const Matrix<T4> &)
	{
		return false;
	}
	template <typename T5>
	bool operator!=(const Matrix<T5> &)
	{
		return true;
	}
	bool operator!=(const Matrix<T>& other)
	{
		return (!(*this == other));
	}
	Matrix<T> operator+(const Matrix<T>& other)
	{
		if (other.n == this->n && other.m == this->m)
		{
			Matrix<T> temp(other.n, other.m, 0);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					temp.arr[i][j] = this->arr[i][j] + other.arr[i][j];
				}
			}
			return temp;
		}
		throw "The matrices must be of the same dimension!\n";
	}
	Matrix<T> operator-(const Matrix<T>& other)
	{
		if (other.n == this->n && other.m == this->m)
		{
			Matrix<T> temp(other.n, other.m, 0);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					temp.arr[i][j] = this->arr[i][j] - other.arr[i][j];
				}
			}
			return temp;
		}
		throw "The matrices must be of the same dimension!";
	}
	template <typename T1>
	Matrix<T> operator-(const Matrix<T1> &)
	{
		throw "The matrices must be of the same type!";
	}
	T& operator()(const int row, const int col)
	{
		if (row >= 0 && col >= 0 && row < n && col < m)
		{
			return arr[row][col];
		}
		throw "The indexes are set incorrectly!";
	}
	T operator()(const int row, const int col) const
	{
		if (row >= 0 && col >= 0 && row < n && col < m)
		{
			return arr[row][col];
		}
		throw "The indexes are set incorrectly!";
	}

	template <typename T1>
	Matrix<T>& operator=(const Matrix<T1> other)
	{
		throw "The matrices must be of the same type!";

	}
	Matrix<T>& operator=(const Matrix<T>& other)
	{
		if (this == &other) return *this;
		if (this->n != other.n || this->m != other.m)
		{
			this->n = other.n;
			this->m = other.m;
			delete arr;
			this->arr = new T * [other.n];
			for (int i = 0; i < n; i++)
			{
				arr[i] = new T[other.m];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = other.arr[i][j];
			}
		}
		return *this;
	}
};


template <typename T>
ostream& operator <<(ostream& out, const Matrix<T>& matrix)
{
	for (int i = 0; i < matrix.GetN(); i++)
	{
		for (int j = 0; j < matrix.GetM(); j++)
		{
			out << matrix(i, j) << " ";
		}
		out << endl;
	}
	return out;

}
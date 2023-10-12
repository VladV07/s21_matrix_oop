#include <cmath>
#include <exception>
#include <iostream>
using namespace std;

#define EPS 0.0000001

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


class S21Matrix {
	private:
		int rows_;
		int cols_;
		double **matrix_;

	public:
		// пока паблик потом перенести в приват
		void MemoryMatrixSet();
		void MatrixDelete();
		void MatrixCheck();
		void MatrixCheck(const S21Matrix& matrix);
		void CheckZero(int nb);
		void CheckZero(double nb);
		void MatrixCheckSquare(const S21Matrix& matrix);
		void MatrixCopy(const S21Matrix& other);
		void MatrixReplase(S21Matrix&& other);
		S21Matrix MatrixReduce(int row, int col);
		void LU(const S21Matrix& A, S21Matrix& U, S21Matrix& L);
		//

		S21Matrix();
		S21Matrix(int rows, int cols);
		S21Matrix(const S21Matrix& other);
		S21Matrix(S21Matrix&& other) noexcept;
		~S21Matrix();

		double operator()(int i, int j) const;
		double& operator()(int i, int j);
		S21Matrix& operator=(const S21Matrix& other);
		S21Matrix& operator=(S21Matrix&& other) noexcept;
		S21Matrix operator+(const S21Matrix& other);
		S21Matrix operator-(const S21Matrix& other);
		S21Matrix operator*(const S21Matrix& other);
		S21Matrix operator*(int nb);
		S21Matrix operator*(double nb);
		S21Matrix& operator*=(double num);
		bool operator==(const S21Matrix& other);
		S21Matrix& operator+=(const S21Matrix& other);
		S21Matrix& operator-=(const S21Matrix& other);

		double Determinant();
		S21Matrix CalcComplements();
		S21Matrix InverseMatrix();
		S21Matrix Transpose();
		void MulNumber(const double num);
		bool EqMatrix(const S21Matrix& other);
		void SumMatrix(const S21Matrix& other);
		void MulMatrix(const S21Matrix& other);
		void SubMatrix(const S21Matrix& other);

		double** getMatrix() const;
		double getMatrix(int row, int col) const;
		int getRows() const;
		int getCols() const;

		void setMatrix(double** matrix);
		void setRows(int rows);
		void setCols(int cols);
};
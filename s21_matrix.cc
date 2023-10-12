
#include "s21_matrix_oop.h"
void S21Matrix::MemoryMatrixSet()
{
	printf("MemoryMatrixSet: \n");
	matrix_ = new double *[this->getRows()];
	for (int i = 0; i < this->getRows(); i++) 
	{
		matrix_[i] = new double [this->getCols()];
		for (int j = 0; j < this->getCols(); j++) 
			matrix_[i][j] = 0.0;
	}
}

void S21Matrix::MatrixDelete()
{
	printf("MatrixDelete: \n");
	for (int i = 0; i < this->getRows(); i++) 
		delete []matrix_[i];
	delete []matrix_;
	this->matrix_ = nullptr;
	this->rows_ = 0;
	this->cols_ = 0;
	printf("MatrixDelete: end\n");
}

// void S21Matrix::MemoryMatrixSet()
// {
// 	printf("MemoryMatrixSet: cols= %d\n", this->getCols());
// 	printf("MemoryMatrixSet: rows= %d\n", this->getRows());
// 	matrix_ = new double * [rows_];
// 	for (int i = 0; i < rows_; i++)
// 	{
// 		matrix_[i] = new double [cols_];
// 		for (int j = 0; j < cols_; j++) 
// 			matrix_[i][j] = 0.0;
// 	}
// }

void S21Matrix::MatrixCheck()
{
	printf("MatrixCheck: \n");
	if (this->getRows() <= 0 || this->getCols() <= 0)
		throw std::invalid_argument(
			"Rows and columns can't be 0 or less");
}

void S21Matrix::MatrixCheck(const S21Matrix& matrix)
{
	printf("MatrixCheck: \n");
	if (matrix.getRows() <= 0 || matrix.getCols() <= 0)
		throw std::invalid_argument(
			"Rows and columns can't be 0 or less");
}

void S21Matrix::MatrixCheckSquare(const S21Matrix& matrix)
{
	printf("MatrixCheckSquare: \n");
	if (matrix.getRows() != matrix.getCols())
		throw std::invalid_argument(
			"Matrix not square");
}

void S21Matrix::CheckZero(int nb)
{
	printf("CheckZero: \n");
	if (abs(nb) < EPS)
		throw std::invalid_argument(
			"Division by zero is prohibited");
}

void S21Matrix::CheckZero(double nb)
{
	printf("CheckZero: \n");
	if (abs(nb) < EPS)
		throw std::invalid_argument(
			"Division by zero is prohibited");
}

void S21Matrix::MatrixCopy(const S21Matrix& other)
{
	printf("MatrixCopy: \n");
	printf("MatrixCopy: cols= %d\n", this->getCols());
	printf("MatrixCopy: rows= %d\n", this->getRows());
	printf("MatrixCopy: other cols= %d\n", other.getCols());
	printf("MatrixCopy: other rows= %d\n", other.getRows());
	// this->MatrixCheck();
	MatrixCheck(other);
	if (this != &other)
	{
		// MatrixDelete();
		this->setRows(other.getRows());
		this->setCols(other.getCols());
		printf("MatrixCopy: cols= %d\n", this->getCols());
		printf("MatrixCopy: rows= %d\n", this->getRows());
		MemoryMatrixSet();
		for (int i = 0; i < this->getRows(); i++)
			for (int j = 0; j < this->getCols(); j++)
			{
				matrix_[i][j] = other(i, j);
				printf("MatrixCopy: matrix_[%d][%d]= %f\n", i ,j ,matrix_[i][j]);
			}
	}
}

double S21Matrix::operator()(int i, int j) const
{
	printf("operator()(int i, int j) const: \n");
	// printf("operator: cols= %d\n", this->getCols());
	// printf("operator: rows= %d\n", this->getRows());
	// printf("operator: i= %d\n", i);
	// printf("operator: j= %d\n", j);
	if (this->getRows() <= i || this->getCols() <= j || \
			i < 0 || j < 0)
		throw std::invalid_argument("Incorrect indexes.");
	if (abs(matrix_[i][j]) <= EPS)
		matrix_[i][j] = 0.0;
	return this->getMatrix(i, j);
}


double& S21Matrix::operator()(int i, int j)
{
	printf("operator(): \n");
	// 	printf("operator: cols= %d\n", this->getCols());
	// printf("operator: rows= %d\n", this->getRows());
	// printf("operator: i= %d\n", i);
	// printf("operator: j= %d\n", j);
	if (rows_ <= i || cols_ <= j || i < 0 || j < 0)
		throw std::invalid_argument("Incorrect indexes!");
	if (abs(matrix_[i][j]) <= EPS)
		matrix_[i][j] = 0.0;
	return matrix_[i][j];
}

S21Matrix::S21Matrix()
{
	printf("S21Matrix(): \n");
	this->cols_ = 0;
	this->rows_ = 0;
	this->setMatrix(nullptr);
}


S21Matrix::S21Matrix(int rows, int cols)
{
	printf("S21Matrix(int rows, int cols): \n");
	this->cols_ = cols;
	this->rows_ = rows;
	MatrixCheck();
	MemoryMatrixSet();
}

S21Matrix::S21Matrix(const S21Matrix& other)
{
	printf("S21Matrix(const S21Matrix& other): \n");
	MatrixCopy(other);
	printf("S21Matrix(const S21Matrix& other): end\n");
}

S21Matrix::S21Matrix(S21Matrix&& other)
{
	printf("S21Matrix(S21Matrix&& other): \n");
	MatrixReplase(std::move(other));
}

S21Matrix::~S21Matrix() { this->MatrixDelete(); }

void S21Matrix::MatrixReplase(S21Matrix&& other)
{
	printf("MatrixReplase: \n");
	printf("MatrixReplase: other cols= %d\n", other.getCols());
	printf("MatrixReplase: other rows= %d\n", other.getRows());
	this->rows_ = other.getRows();
	this->cols_ = other.getCols();
	this->matrix_ = other.getMatrix();
	other.rows_ = 0;
	other.cols_ = 0;
	other.matrix_ = nullptr;
	printf("MatrixReplase: cols= %d\n", this->getCols());
	printf("MatrixReplase: rows= %d\n", this->getRows());
	printf("MatrixReplase: end \n");
}

S21Matrix S21Matrix::MatrixReduce(int row, int col) {
	printf("MatrixReduce: \n");
	int i_new = 0;
	int j_new = 0;
	S21Matrix matrix_reduse(this->getRows() - 1, this->getCols() - 1);
	for (int i = 0; i < this->getRows(); i++)
	{
		if (i != row)
		{
			for (int j = 0; j < this->getCols(); j++)
				if (j != col)
				{
					matrix_reduse.matrix_[i_new][j_new++] = matrix_[i][j];
					printf("MatrixReduce: matrix_reduse[%d][%d]= %f\n",i_new, j_new - 1, matrix_reduse(i_new,j_new - 1));
				}
			j_new = 0;
			i_new++;
		}
	}
	printf("MatrixReduce: cols= %d\n", matrix_reduse.getCols());
	printf("MatrixReduce: rows= %d\n", matrix_reduse.getRows());
	printf("MatrixReduce: end\n");
	return matrix_reduse;
}

S21Matrix S21Matrix::operator=(const S21Matrix& other) {
	printf("operator=: \n");
	this->MatrixCopy(other);
	return *this;
}

S21Matrix S21Matrix::operator=(S21Matrix&& other) {
	printf("operator= &&: \n");
	if (this != &other)
	{
		this->MatrixDelete();
		this->MatrixReplase(std::move(other));
	}
	printf("operator= &&: end\n");
	return *this;
}

void S21Matrix::LU(const S21Matrix& A, S21Matrix& U, S21Matrix& L)
{
	printf("LU: \n");
	MatrixCheck(A);
	MatrixCheckSquare(A);
	S21Matrix tmpU(A.getRows(), A.getCols());
	S21Matrix tmpL(A.getRows(), A.getCols());
	int n = A.getRows();

	tmpU = A;

	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
		{
			CheckZero(tmpU(i, i));
			tmpL.matrix_[j][i] = tmpU(j, i) / tmpU(i, i);
		}
	for(int k = 1; k < n; k++)
	{
		for(int i = k-1; i < n; i++)
			for(int j = i; j < n; j++)
			{
				CheckZero(tmpU(i, i));
				tmpL.matrix_[j][i] = tmpU(j, i) / tmpU(i, i);
			}
		for(int i = k; i < n; i++)
			for(int j = k-1; j < n; j++)
				tmpU.matrix_[i][j] = tmpU(i, j) - tmpL(i, k - 1) * tmpU(k - 1, j);
	}
	// U.setCols(n);
	// L.setCols(n);
	// tmpU.setCols(n);
	// tmpL.setCols(n);
	U = std::move(tmpU);
	L = std::move(tmpL);
	printf("LU: end\n");
}

double S21Matrix::Determinant()
{
	printf("Determinant: \n");
	S21Matrix U;
	S21Matrix L;
	double detL = 0;
	double detU = 0;
	double detA = 0;

	LU(*this, U, L);
	// printf("\n %f, %f, %f \n", U(0,0), U(0,1), U(0,2));
	// printf(" %f, %f, %f \n", U(1,0), U(1,1), U(1,2));
	// printf(" %f, %f, %f \n", U(2,0), U(2,1), U(2,2));

	// printf("\n %f, %f, %f \n", L(0,0), L(0,1), L(0,2));
	// printf(" %f, %f, %f \n", L(1,0), L(1,1), L(1,2));
	// printf(" %f, %f, %f \n", L(2,0), L(2,1), L(2,2));
	for(int i = 0; i < this->getRows(); i++)
	{
		if (i == 0)
			detL = L(i,i);
		else
			detL *= L(i,i);
		// printf("L()=%f\n",L(i,i));
		// printf("detL=%f\n",detL);
	}
	for(int i = 0; i < this->getRows(); i++)
	{
		if (i == 0)
			detU = U(i,i);
		else
			detU *= U(i,i);
	}
	detA = detL * detU;
	printf("Determinant: end\n");
	return detA;
}

S21Matrix S21Matrix::CalcComplements()
{
	printf("CalcComplements: \n");
	double minor = 0;
	S21Matrix matrix_reduse(this->getRows() - 1, this->getCols() - 1);
	S21Matrix res(this->getRows(), this->getCols());
	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < this->getCols(); j++)
		{
			matrix_reduse = MatrixReduce(i, j);
			minor = matrix_reduse.Determinant();
			if ((i + j) % 2)
				minor = -minor;
			res.matrix_[i][j] = minor;
			minor = 0;
		}
	}
	printf("CalcComplements: end\n");
	return res;
}

S21Matrix S21Matrix::operator*=(double num)
{
	MulNumber(num);
	return *this;
}

void S21Matrix::MulNumber(const double num)
{
	this->MatrixCheck();
	for (int i = 0; i < this->getRows(); i++)
		for (int j = 0; j < this->getCols(); j++)
			matrix_[i][j] *= num;
}

S21Matrix S21Matrix::Transpose()
{
	printf("Transpose: \n");
	this->MatrixCheck();
	S21Matrix transp(this->getCols(), this->getRows());
	for (int i = 0; i < this->getRows(); i++)
		for (int j = 0; j < this->getCols(); j++)
			transp.matrix_[j][i] = (*this)(i, j);
	printf("Transpose: end\n");
	return transp;
}

S21Matrix S21Matrix::InverseMatrix()
{
	printf("InverseMatrix: end\n");
	MatrixCheckSquare(*this);
	S21Matrix invers(*this);
	double det = invers.Determinant();
	if (abs(det) > EPS)
	{
		if (invers.getRows() == 1)
		{
			CheckZero(invers(0, 0));
			invers.matrix_[0][0] = 1.0 / invers(0, 0);
		}
		else
		{
			invers = invers.CalcComplements();
			invers = invers.Transpose();
			invers.MulNumber(1.0 / det);
		}
	}
	else
		throw std::domain_error("Determinant is equal 0!");
	printf("InverseMatrix: end\n");
	return invers;
}

bool S21Matrix::EqMatrix(const S21Matrix& other)
{
	bool res;
	res = true;
	this->MatrixCheck();
	if (this->getRows() != other.getRows() || this->getCols() != other.getCols())
		res = false;
	else
	{
		for (int i = 0; i < this->getRows(); i++)
			for (int j = 0; j < this->getCols(); j++)
				if (abs(this->getMatrix(i, j) - other.getMatrix(i, j)) > EPS)
						res = false;
	}
	return res;
}

bool S21Matrix::operator==(const S21Matrix& other)
{
	return EqMatrix(other);
}

S21Matrix S21Matrix::operator+(const S21Matrix& other)
{
	S21Matrix res(*this);
	res.SumMatrix(other);
	return res;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other)
{
	this->SumMatrix(other);
	return *this;
}

void S21Matrix::SumMatrix(const S21Matrix& other)
{
	this->MatrixCheck();
	if (this->getRows() != other.getRows() || this->getCols() != other.getCols())
		throw std::invalid_argument("Invalid length of matrices.");
	for (int i = 0; i < this->getRows(); i++)
		for (int j = 0; j < this->getCols(); j++)
			matrix_[i][j] += other(i, j);
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
	S21Matrix res(*this);
	res.MulMatrix(other);
	return res;
}

S21Matrix S21Matrix::operator*(int nb) {
	S21Matrix res(*this);
	res.MulNumber((double)nb);
	return res;
}

S21Matrix S21Matrix::operator*(double nb) {
	S21Matrix res(*this);
	res.MulNumber(nb);
	return res;
}

void S21Matrix::MulMatrix(const S21Matrix& other)
{
	this->MatrixCheck();
	if (this->getCols() != other.getRows())
		throw std::invalid_argument(
			"The sizes of rows and columns for matrix multiplication do not match.");
	S21Matrix tmp(this->getRows(), other.getCols());
	for (int i = 0; i < this->getRows(); i++)
		for (int j = 0; j < other.getCols(); j++)
			for (int k = 0; k < this->getCols(); k++)
				tmp.matrix_[i][j] += matrix_[i][k] * other(k, j);
	*this = std::move(tmp);
}

void S21Matrix::SubMatrix(const S21Matrix& other)
{
	this->MatrixCheck();
	if (this->getRows() != other.getRows() || this->getCols() != other.getCols())
		throw std::invalid_argument("Invalid length of matrices.");
	for (int i = 0; i < this->getRows(); i++)
		for (int j = 0; j < this->getCols(); j++)
			matrix_[i][j] -= other(i, j);
}

S21Matrix S21Matrix::operator-(const S21Matrix& other)
{
	S21Matrix res(*this);
	res.SubMatrix(other);
	return res;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other)
{
	this->SubMatrix(other);
	return *this;
}
#include "testt.h"

/**
 * @brief 
 * Функция лочит память для матрицы, сначала для rows потом для cols и сразу
 * зануляет значения для избежания мусора в значениях.
 */

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

/**
 * @brief 
 * Удаление матрицы
 * @details
 * Сначала мы высвобождаем память, а потом зануляем значения.
 */


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
		this->rows_ = other.getRows();
		this->cols_ = other.getCols();
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

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
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

S21Matrix &S21Matrix::operator=(const S21Matrix& other) {
	printf(GREEN "operator=: \n");
	this->MatrixCopy(other);
	printf( RED "operator=: end\n" RESET);
	return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix&& other) noexcept {
	printf(GREEN "operator= &&: \n");
	if (this != &other)
	{
		this->MatrixDelete();
		this->MatrixReplase(std::move(other));
	}
	printf(RED "operator= &&: end\n" RESET);
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

S21Matrix& S21Matrix::operator*=(double num)
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

S21Matrix& S21Matrix::operator+=(const S21Matrix& other)
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

S21Matrix& S21Matrix::operator-=(const S21Matrix& other)
{
	this->SubMatrix(other);
	return *this;
}

double** S21Matrix::getMatrix() const
{
	return (this->matrix_);
}

double S21Matrix::getMatrix(int row, int col) const
{
	return (this->matrix_[row][col]);
}

int S21Matrix::getRows() const
{
	return (this->rows_);
}

int S21Matrix::getCols() const
{
	return (this->cols_);
}

void S21Matrix::setMatrix(double** matrix)
{
	this->matrix_ = matrix;
}

void S21Matrix::setRows(int rows)
{
	printf("	setRows:\n");
	printf("rows= %d\n", rows);
	int rows_new = this->getRows();
	int cols_new = this->getCols();
	if (rows < 0)
		throw std::invalid_argument("Count of rows can't be less than 0!");
	if (rows_ != rows && rows != 0)
	{
		if (rows != this->getRows())
			rows_new = rows;
		if (cols_new <= 0)
			cols_new = rows_new;
		printf("this->getCols()= %d\n", this->getCols());
		printf("rows_new= %d\n", rows_new);
		printf("cols_new= %d\n", cols_new);
		S21Matrix tmpMatrix(rows_new, cols_new);
		for (int i = 0; i < rows_new; i++) {
			for (int j = 0; j < cols_new; j++) {
				if (i < this->getRows())
					tmpMatrix.matrix_[i][j] = matrix_[i][j];
				else
					tmpMatrix.matrix_[i][j] = 0.0;
			}
		}
		*this = std::move(tmpMatrix);
		printf("	setRows: move\n");
	}
	else
	{
		this->rows_ = rows;
	}

	printf("	setRows: end\n");

}

void S21Matrix::setCols(int cols)
{
	printf(YELLOW "	setCols:\n");
	printf("cols= %d\n", cols);
	int rows_new = this->getRows();
	int cols_new = this->getCols();
	if (cols < 0)
		throw std::invalid_argument("Count of cols can't be less than 0!");
	if (cols_ != cols && cols != 0)
	{
		if (cols != this->getCols())
			cols_new = cols;
		if (rows_new <= 0)
			rows_new = cols_new;
		printf("this->getCols()= %d\n", this->getCols());
		printf("rows_new= %d\n", rows_new);
		printf("cols_new= %d\n", cols_new);
		S21Matrix tmpMatrix(rows_new, cols_new);
		for (int i = 0; i < rows_new; i++) {
			for (int j = 0; j < cols_new; j++) {
				if (j < this->getCols())
					tmpMatrix.matrix_[i][j] = matrix_[i][j];
				else
					tmpMatrix.matrix_[i][j] = 0.0;
			}
		}
		*this = std::move(tmpMatrix);
		printf("	setCols: move\n");
	}
	else
	{
		this->cols_ = cols;
	}

	printf(RED "	setCols: end\n" RESET);

}

/*

int main()
{
	printf(GREEN "///////////////////////////////////////////\n");
	printf("s t a r t\n");
	printf("///////////////////////////////////////////\n" RESET);
	S21Matrix A(3, 3);
	S21Matrix B(3, 3);
	S21Matrix C;

	A(0,0) = 1;
	A(0,1) = 1;
	A(0,2) = 1;
	A(1,0) = 1;
	A(1,1) = 1;
	A(1,2) = 1;
	A(2,0) = 1;
	A(2,1) = 1;
	A(2,2) = 1;

	A.setCols(3);
	A.setRows(3);
	printf("//////////////\n");


	



	printf("\n %f, %f, %f\n", A(0,0), A(0,1), A(0,2));
	printf(" %f, %f, %f \n", A(1,1), A(1,2), A(2,2));
	printf(" %f, %f, %f \n", A(2,1), A(2,2), A(2,2));
	// printf(" %f, %f, %f \n", A(3,1), A(3,2), A(3,2));
	// printf(" %f, %f, %f \n", A(4,1), A(4,2), A(4,2));

	printf("cols= %d\n", A.getCols());
	printf("rows= %d\n", A.getRows());

	A.setCols(5);
	A.setRows(5);


	printf("cols= %d\n", A.getCols());
	printf("rows= %d\n", A.getRows());
	
	printf("//////////////\n");
	A.MatrixCheck();
	A.CheckZero(1);
	A.MatrixCheckSquare(A);
	A.MemoryMatrixSet();

	
	


	B(0,0) = 2;
	B(0,1) = 2;
	B(0,2) = 2;
	B(1,0) = 2;
	B(1,1) = 2;
	B(1,2) = 2;
	B(2,0) = 2;
	B(2,1) = 2;
	B(2,2) = 2;


	// printf("\n %f, %f, %f, %f, %f \n", A(0,0), A(0,1), A(0,2), A(0,3), A(0,4));
	// printf("\n %f, %f, %f, %f, %f \n", A(1,0), A(1,1), A(1,2), A(1,3), A(1,4));
	// printf("\n %f, %f, %f, %f, %f \n", A(2,0), A(2,1), A(2,2), A(2,3), A(2,4));
	// printf("\n %f, %f, %f, %f, %f \n", A(3,0), A(3,1), A(3,2), A(3,3), A(3,4));
	// printf("\n %f, %f, %f, %f, %f \n", A(4,0), A(4,1), A(4,2), A(4,3), A(4,4));


	// A.setCols(2);
	// A.setRows(2);

	// printf(GREEN "cols= %d\n", A.getCols());
	// printf("rows= %d\n" RESET, A.getRows());

	// printf("\n %f, %f \n", A(0,0), A(0,1));
	// printf("\n %f, %f \n", A(1,0), A(1,1));

	// A.setCols(5);
	// A.setRows(5);

	// printf("\n %f, %f, %f, %f, %f \n", A(0,0), A(0,1), A(0,2), A(0,3), A(0,4));
	// printf("\n %f, %f, %f, %f, %f \n", A(1,0), A(1,1), A(1,2), A(1,3), A(1,4));
	// printf("\n %f, %f, %f, %f, %f \n", A(2,0), A(2,1), A(2,2), A(2,3), A(2,4));
	// printf("\n %f, %f, %f, %f, %f \n", A(3,0), A(3,1), A(3,2), A(3,3), A(3,4));
	// printf("\n %f, %f, %f, %f, %f \n", A(4,0), A(4,1), A(4,2), A(4,3), A(4,4));

	// B.MatrixCopy(A);

	// printf("\n %f, %f, %f \n", B(0,0), B(0,1), B(0,2));
	// printf(" %f, %f, %f \n", B(1,0), B(1,1), B(1,2));
	// printf(" %f, %f, %f \n", B(2,0), B(2,1), B(2,2));

	// C = std::move(A);

	

	C = A;

	printf("\n %f, %f, %f \n", C(0,0), C(0,1), C(0,2));
	printf(" %f, %f, %f \n", C(1,0), C(1,1), C(1,2));
	printf(" %f, %f, %f \n", C(2,0), C(2,1), C(2,2));

	C = A;

	printf("\n %f, %f, %f \n", C(0,0), C(0,1), C(0,2));
	printf(" %f, %f, %f \n", C(1,0), C(1,1), C(1,2));
	printf(" %f, %f, %f \n", C(2,0), C(2,1), C(2,2));

	

	B(0,0) = 2;
	B(0,1) = 1;
	B(0,2) = 2;
	B(1,0) = 1;
	B(1,1) = 1;
	B(1,2) = 1;
	B(2,0) = 2;
	B(2,1) = 1;
	B(2,2) = 2;

	// A.MatrixDelete();
	// A.MatrixReplase(std::move(B));

	printf("\n %f, %f, %f \n", A(0,0), A(0,1), A(0,2));
	printf(" %f, %f, %f \n", A(1,0), A(1,1), A(1,2));
	printf(" %f, %f, %f \n", A(2,0), A(2,1), A(2,2));

	printf("\n %f, %f, %f \n", B(0,0), B(0,1), B(0,2));
	printf(" %f, %f, %f \n", B(1,0), B(1,1), B(1,2));
	printf(" %f, %f, %f \n", B(2,0), B(2,1), B(2,2));
	printf("main: MatrixReduce start\n");
	C = B.MatrixReduce(1,1);
	printf("main: MatrixReduce end\n");
	printf("\n %f, %f \n", C(0,0), C(0,1));
	printf(" %f, %f \n", C(1,0), C(1,1));

	printf("\n %f, %f, %f \n", B(0,0), B(0,1), B(0,2));
	printf(" %f, %f, %f \n", B(1,0), B(1,1), B(1,2));
	printf(" %f, %f, %f \n", B(2,0), B(2,1), B(2,2));

	printf("\n %f, %f, %f \n", A(0,0), A(0,1), A(0,2));
	printf(" %f, %f, %f \n", A(1,0), A(1,1), A(1,2));
	printf(" %f, %f, %f \n", A(2,0), A(2,1), A(2,2));



	B(0,0) = 3;
	B(0,1) = 7;
	B(0,2) = 9;
	B(1,0) = 1;
	B(1,1) = 2;
	B(1,2) = 8;
	B(2,0) = 6;
	B(2,1) = 3;
	B(2,2) = 4;

	S21Matrix L;
	S21Matrix U;
	B.LU(B,U,L);

	printf("\n ////////////////////////////////// \n");

	printf("\n %f, %f, %f \n", B(0,0), B(0,1), B(0,2));
	printf(" %f, %f, %f \n", B(1,0), B(1,1), B(1,2));
	printf(" %f, %f, %f \n", B(2,0), B(2,1), B(2,2));

	printf("\n %f, %f, %f \n", U(0,0), U(0,1), U(0,2));
	printf(" %f, %f, %f \n", U(1,0), U(1,1), U(1,2));
	printf(" %f, %f, %f \n", U(2,0), U(2,1), U(2,2));

	printf("\n %f, %f, %f \n", L(0,0), L(0,1), L(0,2));
	printf(" %f, %f, %f \n", L(1,0), L(1,1), L(1,2));
	printf(" %f, %f, %f \n", L(2,0), L(2,1), L(2,2));


	double det = B.Determinant();
	printf("\ndet B = %f\n", det);


	S21Matrix inv;
	inv = B.InverseMatrix();

	printf("\n %f, %f, %f \n", inv(0,0), inv(0,1), inv(0,2));
	printf(" %f, %f, %f \n", inv(1,0), inv(1,1), inv(1,2));
	printf(" %f, %f, %f \n", inv(2,0), inv(2,1), inv(2,2));


	if (A == B)
		printf("\n A = B \n");
	else
		printf("\n A != B \n");

	if (A == A)
		printf("\n A = A \n");


	printf("\n rows A = %d\n", A.getRows());
	printf(" cols A = %d\n", A.getCols());
	printf("\n rows B = %d\n", B.getRows());
	printf(" cols B = %d\n", B.getCols());
	B.setCols(5);
	B.setRows(5);
	C = A + B;

	printf("\n %f, %f, %f \n", C(0,0), C(0,1), C(0,2));
	printf(" %f, %f, %f \n", C(1,0), C(1,1), C(1,2));
	printf(" %f, %f, %f \n", C(2,0), C(2,1), C(2,2));

	


	C = A * B;

	printf("\n %f, %f, %f \n", C(0,0), C(0,1), C(0,2));
	printf(" %f, %f, %f \n", C(1,0), C(1,1), C(1,2));
	printf(" %f, %f, %f \n", C(2,0), C(2,1), C(2,2));

	printf("C = A - B\n");
	C = A - B;

	printf("\n %f, %f, %f \n", C(0,0), C(0,1), C(0,2));
	printf(" %f, %f, %f \n", C(1,0), C(1,1), C(1,2));
	printf(" %f, %f, %f \n", C(2,0), C(2,1), C(2,2));

	printf("A -= B\n");
	A -= B;

	printf("\n %f, %f, %f \n", A(0,0), A(0,1), A(0,2));
	printf(" %f, %f, %f \n", A(1,0), A(1,1), A(1,2));
	printf(" %f, %f, %f \n", A(2,0), A(2,1), A(2,2));

	// A.setRows(5);

	printf("\n %f, %f, %f \n", A(0,0), A(0,1), A(0,2));
	printf(" %f, %f, %f \n", A(1,0), A(1,1), A(1,2));
	printf(" %f, %f, %f \n", A(2,0), A(2,1), A(2,2));
	// printf(" %f, %f, %f \n", A(3,0), A(3,1), A(3,2));



	printf("ok!\n");
	return 0;
}

*/
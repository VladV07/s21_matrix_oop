#include "s21_matrix_oop.h"

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
	int rows_new = 0;
	int cols_new = 0;
	if (rows < 0)
		throw std::invalid_argument("!Count of rows can't be less than 0!");
	if (rows_ != rows && rows != 0)
	{
		if (rows > this->getRows())
			rows_new = rows;
		else
			rows_new = this->getRows();
		if (this->getCols() > 0)
			cols_new = this->getCols();
		else
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
		// this->rows_ = rows;
		*this = std::move(tmpMatrix);
		printf("	setRows: move\n");
	}
	else
	{
		this->rows_ = rows;
	}

	// this->rows_ = rows_new;
	printf("	setRows: end\n");

	// this->rows_ = rows;
}

void S21Matrix::setCols(int cols)
{
	this->cols_ = cols;
}
#include "testt.h"

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
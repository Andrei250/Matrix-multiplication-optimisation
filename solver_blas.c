/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"
// #include "cblas.h"

/* 
 * Add your BLAS implementation here
 */

double *getTrans(int N, double *mt) {
	double *tr = (double *) malloc(sizeof(double) * N);
	int i, j;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			tr[i * N + j] = mt[j * N + i];
		}
	}

	return tr;
}

double* my_solver(int N, double *A, double *B) {
	return NULL;
	// double *C = calloc(N * N, sizeof(double));
	// double *trns = getTrans(N, A);

	// // Calculate A * A^t => matrix trns will have the answer
	// cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, N, N, 1.0, A, N, trns, N);

	// // Caculate C = B^t * B
	// cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1.0, B, N, B, N, 1.0, C, N);

	// // Calculate C = B * trsn + C
	// cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1.0, B, N, trns, N, 1.0, C, N);

	// free(trns);

	// return C;
}

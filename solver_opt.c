/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	double *C = (double *) malloc(N * N * sizeof(double));
	int i, j, k;

	double *AAt = (double *) malloc(N * N * sizeof(double));

	// Perform A * At
	for (i = 0; i < N; ++i) {
		register double *AAt_line = AAt + i * N;

		for (j = 0; j < N; ++j) {
			register double sum = 0;
			register double *first_opperand =  A + i * (N + 1);
			register double *second_operand = A + j * N + i;

			for (k = i; k < N; ++k) {
				sum += *first_opperand * *second_operand;
				first_opperand++;
				second_operand++;
			}

			*(AAt_line + j) += sum;
		}
	}

	// Perform C = B * AAt
	for (i = 0; i < N; ++i) {
		register double *B_saved = B + i * N;
		register double *C_line = C + i * N;

		for (k = 0; k < N; ++k) {
			register double *AAt_saved = AAt + k * N;
			register double value = *(B_saved + k);

			for (j = 0; j < N; ++j) {
				*(C_line + j) += value * *(AAt_saved + j);
			}
		}
	}

	// Calculate C + Bt * B
	double *C_saved = C;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			register double sum = 0;
			register double *B_line = B + i;
			register double *B_column = B + j;

			for (k = 0; k < N; ++k) {
				sum += *B_line * *B_column;
				B_line += N;
				B_column += N;
			}

			*C_saved = *C_saved + sum;
			C_saved++;
		}
	}

	free(AAt);

	return C;
}

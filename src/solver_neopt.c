/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */

double* my_solver(int N, double *A, double* B) {
	double *C = (double *) calloc(N * N, sizeof(double));
	double *AAt = (double *) calloc(N * N, sizeof(double));
	int i, j, k;

	// Calculate A * A^t into AAt matrix
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			for (k = i; k < N; ++k) {
				AAt[i * N + j] += A[i * N + k] * A[j * N + k];
			}
		}
	}

	// Calculate Bt * B
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			for (k = 0; k < N; ++k) {
				C[i * N + j] += B[k * N + i] * B[k * N + j];
			}
		}
	}

	// Calculate C + B * AAt
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			for (k = 0; k < N; ++k) {
				C[i * N + j] += B[i * N + k] * AAt[k * N + j];
			}
		}
	}

	free(AAt);

	return C;
}

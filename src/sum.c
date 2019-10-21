#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>

// idx is a list of integers
SEXP grouped_sum_dbl(SEXP x, SEXP indices, SEXP n_groups_) {

  int n_groups = Rf_asInteger(n_groups_);

  SEXP out = PROTECT(Rf_allocVector(REALSXP, n_groups));
  double *p_out = REAL(out);

  double *p_x = REAL(x);

  SEXP index;
  int *p_index;
  R_len_t index_size;

  double sum;

  for (int g = 0; g < n_groups; ++g) {
    sum = 0;

    index = VECTOR_ELT(indices, g);
    p_index = INTEGER(index);
    index_size = Rf_length(index);

    for (int i = 0; i < index_size; ++i) {
      int idx = p_index[i] - 1;
      sum += p_x[idx];
    }

    p_out[g] = sum;
  }

  UNPROTECT(1);
  return out;
}

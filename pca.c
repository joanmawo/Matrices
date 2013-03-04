
int main(int argc, char ** argv){

  FILE * file;
  file = fopen(argv[1], "r");

  int lineas;
  int columnas;

  gsl_matrix *datos;
  gsl_matrix *covarianzas;
  gsl_matrix *eigenVec;
  gsl_vector *eigenVal;

  columnas = 3;
  lineas = count_lines(argv[1]);

  datos = gsl_matrix_calloc(lineas, columnas);
  covarianzas = gsl_matrix_calloc(columnas, columnas);
  eigenVec = gsl_matrix_calloc(columnas, columnas);
  eigenVal = gsl_vector_calloc(columnas);

 

}

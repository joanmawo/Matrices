
int main(int argc, char ** argv){

  FILE * file;
  file = fopen(argv[1], "r");

  int lineas;
  int columnas;

  gsl_matrix *datos;
  gsl_matrix *covarianzas;
  gsl_matrix *eigenVec;
  gsl_vector *eigenVal;
  gsl_vector *Vgsl;

  columnas = 3;
  lineas = count_lines(argv[1]);

  datos = gsl_matrix_calloc(lineas, columnas);
  covarianzas = gsl_matrix_calloc(columnas, columnas);
  eigenVec = gsl_matrix_calloc(columnas, columnas);
  eigenVal = gsl_vector_calloc(columnas);
  Vgsl = gsl_vector_calloc(lineas);

  //Funcion que calcula promedios de componentes de vectores
  double calcularPromedio(gsl_vector *Vgsl, gsl_matrix *datos){

    double temp = 0.0;
    int j;
    for(j = 0; j < lineas; j ++){
      gsl_matrix_get_col(Vgsl, datos, j);
    }
    for(j = 0; j < lineas; j ++){
      temp += gsl_vector_get(Vgsl, j);
    }
   
    return = (temp/lineas);
  }

 
}

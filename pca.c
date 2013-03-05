#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_cblas.h>

void imprimir(gsl_matrix* eigenVec, int N);
int count_lines(char *filename);

int main(int argc, char ** argv){

  FILE* file;
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

  
  //Ejecucion de las funciones
  
  gsl_matrix_fscanf(file, datos);
  
  construirMatrizCovarianzas(datos, covarianzas, columnas, lineas);
  
  calcularAutovalores(covarianzas, eigenVal, eigenVec, columnas);
  
  imprimir(eigenVec, columnas);
  
  return 1;
}  
  
  //Funcion que cuenta el numero de lineas del archivo
  int count_lines(char *filename){
    FILE *in;
  int n_lines;
  int c;
  if(!(in=fopen(filename, "r"))){
    printf("problem opening file %s\n", filename);
    exit(1);
  }

  n_lines = 0;
  do{
    c = fgetc(in);
    if(c=='\n'){
      n_lines++;
    }
  }while(c!=EOF);
  
  fclose(in);
  return n_lines;
}

	//Funcion que cuenta el numero de lineas del archivo
int count_lines(char *filename){
  FILE *in;
  int n_lines;
  int c;
  if(!(in=fopen(filename, "r"))){
    printf("problem opening file %s\n", filename);
    exit(1);
  }

  n_lines = 0;
  do{
    c = fgetc(in);
    if(c=='\n'){
      n_lines++;
    }
  }while(c!=EOF);
  
  fclose(in);
  return n_lines;
}

  //Funcion que calcula promedios de componentes de vectores dandole como parametros el vector y su tamano.
  double calcularPromedio(gsl_vector* V, int M){

    double temp = 0.0;
    double promedio = 0.0;
    int j;
    for(j = 0; j < M; j ++){
	temp += gsl_vector_get(V, j);      
    }
    
    promedio = (temp/M);
    return promedio;
  }

//Funcion que calcula la covarianza de un par de  elementos
double calcularCovarianza(int i, int j, int M, gsl_matrix* datos){


	gsl_vector* datos_i = gsl_vector_calloc(M);
	gsl_vector* datos_j = gsl_vector_calloc(M);
	gsl_matrix_get_col(datos_i, datos, i);
	gsl_matrix_get_col(datos_j, datos, j);

	int k;	
	double cov;
	cov = 0.0;
	for (k = 0 ; k < M ; k++){	
	double d_ik = gsl_vector_get(datos_i,k);
	double d_jk = gsl_vector_get(datos_j,k);
	

	cov +=((d_ik - calcularPromedio(datos_i,M))*(d_jk - calcularPromedio(datos_j, M)));
	}

	cov = cov/(M-1);

	return cov;
}

//Funcion que construye la matriz cuadrada con las covarianzas	
void construirMatrizCovarianzas(gsl_matrix* datos, gsl_matrix* covarianzas, int N, int M){

	int i;
	int j;

	for(i = 0; i < N; i ++){
		for(j = 0; j < N; j ++){
			double temp;
			temp = calcularCovarianza(i, j, M, datos);
			gsl_matrix_set(covarianzas, i, j, temp);
		}
	}
}

//Funcion que calcula los autovalores de la matriz de covarianza y los ordena decrecientemente
void calcularAutovalores(gsl_matrix* covarianzas, gsl_vector* eigenVal, gsl_matrix* eigenVec, int N){

	gsl_eigen_symm_workspace *w;
	w = gsl_eigen_symm_alloc (N);

	//gsl_eigen_symm(covarianzas, eigenVal, w);
	gsl_eigen_symmv(covarianzas, eigenVal, eigenVec, w);

	gsl_eigen_symmv_sort(eigenVal, eigenVec, GSL_EIGEN_SORT_ABS_DESC);
	
	gsl_eigen_symmv_free(w);

	
}
 
//Funcion que imprime el archivo con los autovectores ordenados decrecientemente

void imprimir(gsl_matrix* eigenVec, int N){
  
  FILE *output;
  output = fopen("autovectores_3D_data.dat", "w");
  
  int i;
  for(i = 0; i < N; i ++){
    fprintf(output, "%f %f %f \n" , 
	    gsl_matrix_get(eigenVec, i, 0), gsl_matrix_get(eigenVec, i, 1) ,gsl_matrix_get(eigenVec, i, 2));
  }
}



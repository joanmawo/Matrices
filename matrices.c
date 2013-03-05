
#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_linalg.h>

int main(int argc, char **argv){


  float *datos;
  gsl_vector *posYgsl;
  gsl_matrix *Original;
  gsl_matrix *Ggsl;
  gsl_matrix *GTgsl;
  gsl_matrix *GtimeGTgsl;
  gsl_matrix *inverse;
  gsl_vector *Vgsl;

  int lines = 0;
  

FILE *file;
  file = fopen(argv[1], "r");

  int n_lines = 0;
  int columnas = 2;
  int c=0;

do{
    c = fgetc(file);
    if(c=='\n'){
      n_lines++;
    }
  }while(c!=EOF);

rewind(file);

 	Original = gsl_matrix_calloc (n_lines, 2);
 	gsl_matrix_fscanf (file, Original);
	lines = n_lines;
 	


	posYgsl = gsl_vector_calloc(lines);
	int i;
  for(i = 0; i<n_lines; i++){
    
    gsl_vector_set (posYgsl, i,gsl_matrix_get(Original, i,1)); 

  Ggsl = gsl_matrix_alloc(n_lines, 3);
	int i;
}
  for(i = 0; i<n_lines; i++){
    
    float temp1 = 1;
    float temp2 = gsl_matrix_get(Original,i, 1);
    float temp3 = (1/2)*gsl_matrix_get(Original,i, 2)*gsl_matrix_get(Original,i, 2);


    gsl_matrix_set(Ggsl, i, 0, temp1);
    gsl_matrix_set(Ggsl, i, 1, temp2);
    gsl_matrix_set(Ggsl, i, 2, temp3);

}


  GTgsl = gsl_matrix_alloc(3, lines);

 gsl_matrix_transpose_memcpy(GTgsl,Ggsl);
 gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, Ggsl, GTgsl, 0.0, GtimeGTgsl);
 

gsl_matrix *LU;
gsl_permutation *p=gsl_permutation_alloc (3);
int signum;

  gsl_linalg_LU_decomp(GtimeGTgsl, p, &signum);
  gsl_linalg_LU_invert(GtimeGTgsl,p,inverse);

Vgsl = gsl_vector_alloc (lines);
gsl_matrix *temp;
gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, inverse, GTgsl, 0.0, temp);

gsl_blas_dgemv (CblasNoTrans, 1.0, temp, posYgsl, 0.0, Vgsl);

FILE *output;
	output = fopen("parametros_movimiento.dat", "w");
	
	fprintf(output, "%f %f %f" ,gsl_vector_get (Vgsl, 0), gsl_vector_get (Vgsl, 1) ,gsl_vector_get (Vgsl, 2));


	return 1;

}









	



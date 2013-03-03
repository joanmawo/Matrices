
#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_matrix.h>
#include<gsl/gsl_blas.h>
#include <gsl/gsl_linalg.h>
int main(int argc, char **argv){

  // esto no es necesario -->char *filein;
  float *datos;
  //float *posY;
  gsl_vector *posYgsl;
  //float *G;
  gsl_matrix *Original
  gsl_matrix *Ggsl;
  //float *GT;
  gsl_matrix *GTgsl;
  //float *V;
  gsl_matrix *GtimeGTgsl;
  gsl_matriz *inverse;
  gsl_vector *Vgsl;

  int lines ;
  int columnas = 2;


 	

  *datos = load_data(*filein, &lines, &columnas);

  *posYgsl = construirY(&Original, &lines);

  *Ggsl = construirGgsl(&Original, &lines);

  transpose(&Ggsl, &GTgsl, &lines);

GtimesGtranspose(&Ggsl, &GTgsl, &GtimeGTgsl);

invert(&GtimeGTgsl);

Final (&inverse, &GTgsl, &posYgsl, &columnas);

print_file(&Vgsl);

}


//Funcion que carga los datos del archivo y los dispone en una matriz 'Original'
void *load_data( char *filein, int *nf, int *nc){
  //float *data;
  FILE *file;
  file = fopen(argv[1], "r");

  int n_lines = 0;
  int c = 0;
  //float dato1;
  //float dato2;

do{
    c = fgetc(file);
    if(c=='\n'){
      n_lines++;
    }
  }while(c!=EOF);

 	*Original = gsl_matrix_calloc (n_lines, 2);
 	gsl_matrix_fscanf (file, Original);
	lines=n_lines;
/**
 rewind(file);

  *nf = n_lines;
  *nc = 2;

  *data = malloc(n_lines*2*sizeof(float));
	int i;
  for(i = 0; i<n_lines; i++){
    fscanf("%f %f \n", &dato1, &dato2);
    
      data[i*2] = dato1;
      data[i*2 + 1] = dato2;
	}
  */
 
 //"Lo puse void" return data;
}

//Funcion que construye el vector con las posiciones en Y a partir de la matriz de datos 'data'
void *construirY(gsl_matrix *Original, int *nf){

  lines = *nf;
  //posY = malloc(n_lines*sizeof(float));
	*posYgsl = gsl_vector_calloc (lines);
	int i;
  for(i = 0; i<n_lines; i++){
    
 gsl_matrix_set (posYgsl, i, gsl_matrix_get(Original, 2i + 1)) //grandes dudas con este codigo 

   // posYgsl[i] = Original[2i + 1]
      
      }

 
    }

//Funcion que construye la matriz Ggsl de formato gsl_matrix con "la fisica del problema" a partir de la matriz de datos 'data'
void * construirGgsl(gsl_matrix *Original, int *nf){
  
  lines = *nf;
  
  //G = malloc(n_lines*3*sizeof(float));
  Ggsl = gsl_matrix_alloc(n_lines, 3);
	int i;
  for(i = 0; i<n_lines; i++){
    
    float temp1 = 1;
    float temp2 = Original[2*i];
    float temp3 = (1/2)*(Original[2*i])*(Original[2*i]);

    gsl_matrix_set(Ggsl, i, 0, temp1);
    gsl_matrix_set(Ggsl, i, 1, temp2);
    gsl_matrix_set(Ggsl, i, 2, temp3);
  
      }

  //return Ggsl;
    }

//Función que traspone la matriz 'Ggsl' en la matriz 'GTgsl'
void * transpose(gsl_matrix *Ggsl, gsl_matrix GTgsl, int *nf){

  lines = *nf;
  
  //GT = malloc(n_lines*3*sizeof(float));
  GTgsl = gsl_matrix_alloc(3, lines);
  //v = gsl_vector *gsl_vector_alloc(size_t n_lines); 
  //	int j;
  //for(j = 0; j < n_lines; j++){
  //  int gsl_matrix_get_col(gsl_vector *v, const gsl_matrix *m, size_t j);

gsl_matrix_transpose_memcpy (gsl_matrix *GTgsl, const gsl_matrix *Ggsl);

  }

//Funcion para multiplicar G y su traspuesta
void GtimesGtranspose(gsl_matrix *Ggsl, gsl_matrix *GTgsl, gsl_matriz *GtimeGTgsl){

gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, Ggsl, GTgsl, 0.0, GtimeGTgsl);
}

//Funcion que invierte GtimesGtranspose
void invert (gsl_matrix *GtimeGTgsl){

gsl_linalg_LU_decomp(GtimeGTgsl, gsl_permutation *p, int *signum)//no termino de entender este metodo

gsl_linalg_LU_invert (const gsl_matrix *LU, const gsl_permutation *p,inverse)
}

//GtimesGtranspose times Gtranspose, then times Y
void Final (gsl_matrix *inverse, gsl_matrix *GTgsl,gsl_vector *posYgsl, int *nf){

*nf = lines;
Vgsl = gsl_vector_alloc (size_t lines);
gsl_matrix *temp;
gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, inverse, GTgsl, 0.0, temp);}

gsl_blas_dgemv (CblasNoTrans, 1.0, temp, posYgsl, 0.0, Vgsl);

//Vgsl ahora contiene el resultado final. pero no esta inicializado en ningun lugar!!! Creo que ya lo he inicializado en esta misma funcion. 

}
void print_file (gsl_vector *Vgsl)
{
	FILE *output;
	output = fopen("parametros_movimiento.dat", "w");
	
	fprintf(output, "%f %f %f" ,gsl_vector_get (Vgsl, 0), gsl_vector_get (Vgsl, 1) ,gsl_vector_get (Vgsl, 2));
	
}

}
   
//organized_data =  organize_data(datos, nfilas, ncolumnas)

//transposed_data = transpose.data(organized_data, nfilas, ncolumnas)

//parameters =  get.parameter(organized_data, transposed_data, nfilas, ncolumnas)

//dump_parameters(fileout, parameters);



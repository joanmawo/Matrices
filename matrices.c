
#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_matrix.h>


int main(int argc, char **argv){
  char *filein;
  float *datos;
  float *posY;
  gsl_matrix *posYgsl;
  float *G;
  gsl_matrix *Ggsl;
  float *GT;
  gsl_matrix *GTgsl;
  float *V;
  gsl_vector *Vgsl;

  

  int n_row = 0;
  int n_column = 0;


  *datos = load_data(filein, &n_row, &n_column);

  *posY = construirY(datos, &n_row);

  *Ggsl = construirGgsl(datos, &n_row);

  *GT = transpose(G, &n_row);
}
//Función que carga los datos del archivo y los dispone en una matriz data 
float *load_data( char *filein, int *nf, int *nc){
  float *data;
  FILE *file;
  file = fopen(filein, "r");
  int n_lines = 0;
  int c = 0;
  float dato1;
  float dato2;

do{
    c = fgetc(file);
    if(c=='\n'){
      n_lines++;
    }
  }while(c!=EOF);

 rewind(file);

  *nf = n_lines;
  *nc = 2;

  *data = malloc(n_lines*2*sizeof(float));

  for(i = 0; i<n_lines; i++){
    fscanf("%f %f \n", &dato1, &dato2);
    
      data[i*2] = dato1;
      data[i*2 + 1] = dato2;
	}
    

  return data;
}
//Función que construye el vector con las posiciones en Y a partir de la matriz de datos 'data'
float * construirY(float *data, int *nf){

  *nf = n_lines;
  posY = malloc(n_lines*sizeof(float));
  for(i = 0; i<n_lines; i++){
    
    posY[i] = data[2i + 1]
      
      }

  return posY;
    }

//Función que construye la matriz Ggsl de formato gsl_matrix con "la física del problema" a partir de la matriz de datos 'data'
gsl_matrix * construirGgsl(float *data, int *nf){
  
  n_lines = *nf;
  
  //G = malloc(n_lines*3*sizeof(float));
  Ggsl = gsl_matrix_alloc(n_lines, 3);

  for(i = 0; i<n_lines; i++){
    
    float temp1 = 1;
    float temp2 = data[2*i];
    float temp3 = (1/2)*(data[2*i])*(data[2*i]);

    gsl_matrix_set(gsl_matrix *Ggsl, i, 0, temp1);
    gsl_matrix_set(gsl_matrix *Ggsl, i, 1, temp2);
    gsl_matrix_set(gsl_matrix *Ggsl, i, 2, temp3);
  
      }

  return Ggsl;
    }

//Función que trasponer
float * transpose(float *G, float *v, int *nf){

  n_lines = *nf;
  
  GT = malloc(n_lines*3*sizeof(float));
  GTgsl = 
  v = gsl_vector *gsl_vector_alloc(size_t n_lines); 
  
  for(j = 0; j < n_lines; j++){
    int gsl_matrix_get_col(gsl_vector *v, const gsl_matrix *m, size_t j);
  }

}
   
//organized_data =  organize_data(datos, nfilas, ncolumnas)

//transposed_data = transpose.data(organized_data, nfilas, ncolumnas)

//parameters =  get.parameter(organized_data, transposed_data, nfilas, ncolumnas)

//dump_parameters(fileout, parameters);

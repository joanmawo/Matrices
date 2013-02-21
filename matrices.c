
#include <stdio.h>
#include <gsl>


int main(int argc, char **argv){
  char *filein;
  float *data;
  float *posY;
  float *G;
  float *GT;
  

  int n_row = 0;
  int n_column = 0;


  datos = load_data(filein, &n_row, &n_column);

  posY = construirY(data, &n_row);

  G = construirG(data, &n_row);

  GT = transpose(G, &n_row);
}
//Función que carga los datos del archivo y los dispone en una matriz data 
float * load_data( char *filein, int *nf, int *nc){
  float * data;
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

  data = malloc(n_lines*2*sizeof(float));

  for(i = 0; i<n_lines; i++){
    fscanf("%f %f \n", &dato1, &dato2);
    
      data[i*2] = dato1;
      data[i*2 + 1] = dato2;
	}
    

  return data;
}
//Funciòn que construye el vector con las posiciones en Y a partir de la matriz de datos 'data'
float * construirY(float *data, int *nf){

  *nf = n_lines;
  posY = malloc(n_lines*sizeof(float));
  for(i = 0; i<n_lines; i++){
    
    posY[i] = data[2i + 1]
      
      }

  return posY;
    }

//Función que construye la matriz G con "la fìsica del problema" a partir de la matriz de datos 'data'
float * construirG(float *data, int *nf){
  
  n_lines = *nf;
  
  G = malloc(n_lines*3*sizeof(float));

  for(i = 0; i<n_lines; i++){
    
    G[i*3] = 1
    G[i*3 + 1] = data[2*i];
    G[i*3 + 2] = (1/2)*(data[2*i])*(data[2*i]);

      
      }

  return G;
    }

//Función que trasponer
float * transpose(float *G, int *nf){

  GT = malloc(n_lines*3*sizeof(float));
}
   
//organized_data =  organize_data(datos, nfilas, ncolumnas)

//transposed_data = transpose.data(organized_data, nfilas, ncolumnas)

//parameters =  get.parameter(organized_data, transposed_data, nfilas, ncolumnas)

//dump_parameters(fileout, parameters);

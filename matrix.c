#include <stdio.h>
#include<stdlib.h>
double *input_matrix(int* rows,int*  columns, char* name){
 ;
  /* First matrix */
  printf("%s\n",name);
  printf("Enter # of rows and cols: ");
  scanf("%d %d",rows,columns);

   int row = *rows;
   int col = *columns; 
  printf("Matrix, enter %d reals: \n",row*col);
 
  double *m1;
    m1= (double*)malloc(sizeof(double)*row*col); 
  int i=0,j=0;
  double input;
 
  for(i=0; i<row; i++){
    /* Allocate array, store pointer  */
  
  }
  for(i=0; i<row; i++){
    for(j=0; j<col; j++){
      
          scanf("%lf",&input);
          m1[i*col+j]= input;
       
 
      }
 
    
    
  }
  
 
  return(m1);
}
void output_matrix(double *m4, int row, int collumns) {     
  int i=0,j=0;
  for(i=0; i<row; i++){    /* Iterate of each row */
    for(j=0; j<collumns; j++){  /* In each row, go over each col element  */
      printf("%lf  ",m4[i*collumns+j]); /* Print each row element */
  
  }
  
  }
  printf("\n");
}

double *matrix_multiply(double *m1, int m1rows, int m1col, double *m2, int m2row, int m2col, double *m3){
                                                                                                                                                                     
  double sum;
  int c,d,k;

                                                      
  if (m1col== m2row){
    


    for (c = 0; c < m1rows; c++) {

      for (d = 0; d < m2col; d++) {
	for (k = 0; k < m2row; k++) {
	  sum = sum + ((m1+c)[k])*((m2+k)[d]);
          
	}

	m3[c*m2col+d] = sum;
	sum = 0;
     
      }
    }
  } else{
    return (NULL);
    

  }
  return(m3);
}


  int main(void) {

  double *m1,*m2,*m3;
  int m1_rows,m1_columns,m2_rows,m2_columns;

  if (((m1 = input_matrix(&m1_rows,&m1_columns,"Matrix 1")) != NULL) &&
      ((m2 = input_matrix(&m2_rows,&m2_columns,"Matrix 2")) != NULL) &&
      ((m3 = malloc(m1_rows*m2_columns*sizeof(double))) != NULL)) {
    printf("Matrix 1\n");
    output_matrix(m1,m1_rows,m1_columns);
    printf("Matrix 2\n");
    output_matrix(m2,m2_rows,m2_columns);
    if (matrix_multiply(m1,m1_rows,m1_columns,m2,m2_rows,m2_columns,m3)) {
      printf("Product\n");
      output_matrix(m3,m1_rows,m2_columns);
      free(m1);
      free(m2);
      free(m3);
      return(0);
    } else {
      printf("Error in dimensions\n");
      free(m1);
      free(m2);
      free(m3);
      return(-1);
    }
  } else {
    free(m1);
    free(m2);
    free(m3);
    printf("Error allocating memory\n");
    return(-2);
  }
  
}
  

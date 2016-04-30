#include <stdio.h>


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
double input_matrix(int rows,int  columns,char* name){
 
  double* mat;
  int i,j;
  double InputData;
  printf("type in the length of rows and collumns");
  scanf(" %d  %d", &rows,&columns);
  
  mat = (double*) malloc(columns*rows*sizeof(double));
  for(i=0;i<rows;i++){
    for(j=0;j<columns;j++){
      printf("Enter data");
	scanf("%d",&InputData);

         mat[i][j]= InputData;
    }
  }
  return(mat);
  }
}
double* matrix_Multiply(double* m1, int m1rows, int m1col, double* m2, int m2row, int m2col, double* m3){
  
  double multiply[][];
  int sum;
  int c,d,k;
  int m=sizeof(m1);
  int p= sizeof(m1)/sizeof(m1[0]);
  int q= sizeof(m2[0])/sizeof(m2[0][0]);  
  if (length(m2[1])== length(m1[1])){
      for (c = 0; c < p; c++){
	for (d = 0; d < q; d++){
	  scanf("%d", &m2[c][d]);
	}
      }
      for (c = 0; c < m; c++) {
	for (d = 0; d < q; d++) {
	  for (k = 0; k < p; k++) {
	    sum = sum + m1[c][k]*m2[k][d];
	  }
 
	  multiply[c][d] = sum;
	  sum = 0;
	}
      }
    }
  return(multiply);
}
void output_matrix( double* m3, int row, int collumns) {
  int numberOfLines= sizeof(m3)/sizeof(m3[0]);
  int numberColumns= sizeof(m3[0])/sizeof(m3[0][0]);

	     for (int row=0; row<numberOfLines; row++)
	       {
		 for(int columns=0; columns<numberColumns; columns++){
		   printf("%d     ", matrix[row][columns]);
		 printf("\n");
		 }
	       }
	     }

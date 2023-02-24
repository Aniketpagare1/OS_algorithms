#include <stdio.h>
#include <stdbool.h>
int main(){
  int n, m=3;
  printf("Enter the no of processes: ");
  scanf("%d",&n);
  int alloc[n][m];
  int i,j;
  for( i=0; i<n; i++){
    printf("\nEnter for allocation for  p%d \n",i+1);
    for(j=0; j<m; j++){
      
      scanf("%d",&alloc[i][j]);
    }
  }
  int finish[n];
  for(i=0; i<n; i++){
    finish[i] = 0;
  }
  
  int max[n][m];
  printf("\nEnter the max table: ");
  for(i=0; i<n; i++){
    printf("\nEnter max table for p%d \n",i+1);
    for(j=0; j<m; j++){
      
      scanf("%d",&max[i][j]);
    }
  }
  
  int avail[m];
  printf("\nEnter the avialable resources: \n");
  for(i=0; i<m; i++){
    printf("Available %d: ",i+1);
    scanf("%d",&avail[i]);
  }

  int need[n][m]; 
  for(i=0; i<n; i++){
    for(j=0;j<m; j++){
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }
  
  printf("Need: \n");
  for(i=0; i<n; i++){
    for(j=0; j<m; j++){
      printf("%d\t",need[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("Available: \n");
  for(i=0; i<m; i++){
    printf("%d\t",avail[i]);
  }
  printf("\n\n");
  int seq[n], pos = 0;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(finish[j] == 0){
        int flag=0,k;
        for( k=0; k<m; k++){
          if(need[j][k] > avail[k]){
            flag = 1;
            break;
          }
        }
        if(flag == 0){
          seq[pos++] = j;
          int y;
          for(y=0;y<m;y++){
            avail[y] += alloc[j][y];
          }
          finish[j] = 1;
        }
      }
    }
  }

  int flag = 1;
  for(i=0; i<n; i++){
    if(finish[i] == 0){
      flag = 0;
      printf("The processes will go to  unsafe state."); 
      break;
    }
  }
  
  if(flag == 1){
     printf("\nprocesses are in the safe state(Deadlock will not occur) ");
    printf("Safe Sequence: ");
    for(i=0;i<n;i++){
      printf("P%d,",seq[i]);
    }
  }
  return 0;
}


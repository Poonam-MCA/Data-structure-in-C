//PROGRAM TO SOLVE THE TOWER OF HANOI PROBLEM USING RECURSION 
#include <stdio.h>

#define NUM_RODS 3

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
  if (n > 0) {
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
  }
}

int main() {
  int num_disks;

  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  towerOfHanoi(num_disks, 'A', 'C', 'B');

  return 0;
}

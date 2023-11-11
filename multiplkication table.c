#include <stdio.h>

void print_table(int num, int count);

int main() {
  int num;

  printf("Enter a number to display its table: ");
  scanf("%d", & num);

  print_table(num, 1);

  return 0;
}

void print_table(int num, int count) {
  if (count <= 10) {
    printf("%d x %d = %d\n", num, count, num * count);
    print_table(num, count + 1);
  }
}

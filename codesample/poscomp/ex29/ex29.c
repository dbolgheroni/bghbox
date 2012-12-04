#include <stdio.h>

int F1(int X, int Y) {
  if (X < Y)
    return X;
  else
    return F1(X - Y, Y);
}

int F2(int X, int Y) {
  if (X < Y)
    return 0;
  else
    return 1 + F2(X - Y, Y);
}

void F3(int X, int Y) {
  if (X < Y)
    printf("%d", X);
  else {
    F3(F2(X, Y), Y);
    printf("%d", F1(X, Y));
  }
}

int main() {
  int A, B, R;

  printf("X: ");
  scanf("%d", &A);

  printf("Y: ");
  scanf("%d", &B);

  R = F2(A, B);
  printf("\nR: %d\n", R);

  return 0;
}

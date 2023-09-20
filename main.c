#include <stdio.h>
#include <stdlib.h>

// Минимум из двух целочисленных значений
int min(int a, int b)
{
  if (a < b)
    return a;
  return b;
}

// Рекурсивная функция, во
int getResult(int i, const int n, const int *array, int first_sum, int second_sum)
{
  if (i == n)
    return abs(first_sum - second_sum);
  int variant1 = getResult(i + 1, n, array, first_sum + array[i], second_sum);
  int variant2 = getResult(i + 1, n, array, first_sum, second_sum + array[i]);
  return min(variant1, variant2);
}

int main()
{
  int n;
  scanf("%d", &n);

  int *array = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &array[i]);
  }

  int result = getResult(0, n, array, 0, 0);
  printf("%d\n", result);
}
#include <stdio.h>
#include <stdlib.h>

unsigned int n;
unsigned int array[32];
unsigned long long all_sum;

// Рекурсивная функция
unsigned long long getResult(register unsigned int i, register unsigned long long first_sum)
{
  if (i == n)
  {
    register unsigned long long double_first_sum = (first_sum << 1);
    if (all_sum > double_first_sum)
      return all_sum - double_first_sum;
    else
      return double_first_sum - all_sum;
  }
  else
  {
    unsigned long long variant1 = getResult(i + 1, first_sum + array[i]);
    if (variant1 == 0)
      return 0;
    else
    {
      unsigned long long variant2 = getResult(i + 1, first_sum);
      if (variant1 <= variant2)
        return variant1;
      else
        return variant2;
    }
  }
}

int main()
{
  scanf("%d", &n);

  all_sum = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &array[i]);
    all_sum += array[i];
  }

  printf("%llu\n", getResult(0, 0));
}
#include <stdio.h>
#include <stdlib.h>

int n;
unsigned int array[32];
unsigned long long all_sum;

// Рекурсивная функция
unsigned long long getResult(int i, unsigned long long first_sum, unsigned int mask)
{
  if (mask > ~mask)
  {
    return all_sum;
  }
  else if (i == 0)
  {
    unsigned long long double_first_sum = (first_sum << 1);
    unsigned long long variant1;
    if (all_sum > double_first_sum)
      variant1 = all_sum - double_first_sum;
    else
      variant1 = double_first_sum - all_sum;

    unsigned long long variant2;
    double_first_sum += (array[i] << 1);
    if (all_sum > double_first_sum)
      variant2 = all_sum - double_first_sum;
    else 
      variant2 = double_first_sum - all_sum;

    if (variant1 < variant2)
      return variant1;
    else
      return variant2;
  }
  else if (i != 0)
  {
    const unsigned long long variant1 = getResult(i - 1, first_sum + array[i], mask | (1 << i));
    if (variant1 == 0)
      return 0;
    else
    {
      const unsigned long long variant2 = getResult(i - 1, first_sum, mask);
      if (variant1 <= variant2)
        return variant1;
      else
        return variant2;
    }
  }
  else
  {
    const unsigned long long double_first_sum = (first_sum << 1);
    if (all_sum > double_first_sum)
      return all_sum - double_first_sum;
    else
      return double_first_sum - all_sum;
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

  printf("%llu\n", getResult(n - 1, 0, 0));
}
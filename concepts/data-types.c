#include <stdio.h>

int main() {

  short short_number = 1;
  int integer_number = 13;
  long long_number = 13000000;
  long long longer_number = 13000000000;

  int random_result =
      short_number + integer_number - long_number + longer_number;

  printf("%d\n", random_result);

  random_result = integer_number; // Values can be reassigned.
  printf("%d\n", random_result);

  /*
   * C doesn't has strings, but has arrays of characters
   * char can be from -127 to 127;
   * see concepts/strings.c for more info
   */
  char character = 127;

  /*
   * Arrays have a static size
   * They cannot be initialized like int numbers[10] = [ ... ]
   * Each item has to be populated individually
   */
  int numbers[10];
  for (int i = 0; i < 10; i++) {
    numbers[i] = 13 - i;
    printf("%d, ", numbers[i]);
  }

  /* Arrays can be multidimensional */
  char vowels[2][5] = {
      {'A', 'E', 'I', 'O', 'U'},
      {'a', 'e', 'i', 'o', 'u'},
  };

  return 0;
}

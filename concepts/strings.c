#include <stdio.h>
#include <string.h> // Standard library for dealing with strings

int main() {

  /*
   * Strings so can be defined with pointers,
   * which make them "static"
   */
  char *name_pointer = "Guz013";
  /* or using an array, which makes them manipulatable */
  char name_array[] = "Guz013";
  /* both are equivalent */
  char name_array_2[6] = "Guz013";

  char language[] = "C Language";
  int age = 2023 - 1972;

  /*
   * String manipulation with printf
   * prints 'C is 51 years old as of 2023'
   */
  printf("%s is %d years old\n", language, age);

  /*
   * To get the length of the string, we use
   * function strlen() from <string.h>,
   * instead of something like 'hello'.length
   */
  printf("\"%s\" is %d characters long\n", name_array, strlen(name_array));

  /*
   * To compare two strings we use strncmp()
   * The last argument is the amount of characters to compare
   * it returns 0 if equal
   */
  if (strncmp(name_array, name_array_2, strlen(name_array)) == 0) {
    printf("You are %s!\n", name_array);
  } else {
    printf("You are not %s, go away!\n", name_array);
  }

  /*
   * String concatenation is made with strncat()
   * the last argument is the maximum number of character to be appended
   * THIS MODIFIES THE STRING PASSED as the first argument
   * and the modified string needs to have enough space to append more
   * characters
   */
  char verb[50] = "is learning the ";
  strncat(verb, language, strlen(language));
  printf("%s %s\n", name_array, verb);
}

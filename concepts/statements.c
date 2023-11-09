#include <stdio.h>

/*
 * Functions can have a fixed or variable amount
 * of arguments.
 *
 * The argument value is copied, so they can't be
 * modified outside of the function scope, to do
 * that we need to use pointers.
 *
 * And as you can see, they are declared with their
 * return type instead of something like "function x()"
 */
int sum(int num1, int num2) { return num1 + num2; }

void hello() { printf("I return nothing!\n"); }

/*
 * The static keyword
 *
 * By default, variables are limited to the scope
 * of their function, so when a function completes,
 * the variable is removed from memory. Using the
 * static keyword makes it available to the file's
 * scope and persistent between function calls.
 *
 * By default, functions are global, using static
 * makes it available just on the file where it
 * is declared
 */
static void local() { // This can be accessed just on this file
  static char persistent[] = "I\'m persistent between functions calls!";
}

int main() {
  int cat = 16;
  int dog = 19;

  /*
   * If conditions check if a statement is true or false
   * The available combinators are:
   * AND = &&
   * OR = ||
   */
  if (cat < dog) {
    printf("dog is older than cat\n");
  } else if (cat > dog) {
    printf("dog is younger than cat\n");
  } else {
    printf("dog and cat have the same age\n");
  }

  /* For loops uses a iterator */
  for (int i = 0; i < 10; i++) {
    printf("%d", i);
  }
  printf("\n");

  /*
   * While loops keep going until the condition is false
   * and probably should never be used, in any language
   */
  while (0) {
    break;    // This halts the loop
    continue; // This skips to the next iteration
  }

  return 0;
}

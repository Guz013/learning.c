#include <stdio.h>

void doubleNum(int *value) { *value *= 2; }

int main() {
  /**
   * Pointers are integer addresses to values in the program's memory,
   * instead of the actual value. The value of a pointer itself is a
   * int value, which is the number of a specific slice/row of memory.
   *
   * A pointer is created with the `int *` declaration, and it can point
   * to a variable's value using the & operator.
   */
  int variable = 13;

  int *pointer_to_variable = &variable;

  printf("The value of the variable is %d\n", variable);

  /**
   * Using a * when referencing a pointer is called "Deferencing", in
   * other words, it references the actual memory address' value instead
   * of the address itself.
   */
  printf("The value in address %d is %d\n", pointer_to_variable,
         *pointer_to_variable);

  /**
   * This is what happens under the hood when using arrays or C-String.
   *
   * Using arrays and the [0] index, we are referencing in a point in
   * memory, accessing the first item of the array, is the same of
   * deferencing the first value in a chunk of memory. Each value is
   * assigned a address in memory, and each address is one index greater
   * than the previous.
   *
   * int sequence[4]; // See note below*
   * sequence[0] = 13;
   * sequence[1] = 10;
   * sequence[2] = 7;
   * sequence[4] = 4;
   *
   * Memory:
   * | value | address |
   * | 13    | 235     |
   * | 10    | 236     |
   * | 7     | 237     |
   * | 4     | 238     |
   *
   * *: That's why we declare the size of the array. So the program can
   *    reserve a chunk of memory to that array, even if some addresses
   *    of the chunk ends up being empty, it needs to reserve all of them.
   *
   * The same happens do a C-String (char * var = "string"), which creates
   * a address in memory with the first letter, followed by other addresses
   * in sequence for the rest of the string, until the null terminator (the
   * and of the string, noted as "\0").
   *
   * char *var = "string";
   *
   * Memory:
   * | value | address |
   * | "s"   | 235     |
   * | "t"   | 236     |
   * | "r"   | 237     |
   * | "i"   | 238     |
   * | "n"   | 239     |
   * | "g"   | 240     |
   * | "\0"  | 241     |
   */

  /**
   * In the same way we can access a value in memory using * when referencing
   * a pointer (deferencing), we can also modify it.
   *
   * MODIFYING THE VALUE MODIFIES THE VALUE OF THE VARIABLE ALSO, because we
   * are modifying the value directly in memory the same way we would with a
   * variable.
   */
  variable = 20;
  *pointer_to_variable = 15;

  printf("Value of variable is %d\n", variable);

  /*
   * Because of this we can also break the barrier of the variable
   * scope and modify it inside function ("unpure functions, side-effects"),
   * without copying it.
   */
  doubleNum(pointer_to_variable);

  printf("Value of variable is %d\n", variable);

  return 0;
}

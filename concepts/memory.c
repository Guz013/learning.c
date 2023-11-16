#include <stdio.h>
#include <stdlib.h> // Standard library with contains malloc()

int main() {

  /**
   * DYNAMIC MEMORY ALLOCATION
   *
   * Dynamic memory allocation let us, as the name implies, allocate
   * a chunk of memory without knowing the exact size of the value/data,
   * this helps creating things such linked lists and other complex data
   * structures.
   *
   * Before allocating memory, we need a pointer to know where the location
   * of the chunk is. Said pointer can also then be used to free said memory,
   * which needs to be done MANUALLY AFTER we use it.
   *
   * As a example following learn-c.org, we can create a dynamically allocated
   * person structure.
   */
  typedef struct {
    char *name;
    int age;
  } person;

  /**
   * This signals the compiler to create a chunk of memory to allocate
   * enough to store a person struct in memory. And then returns a pointer
   * of type person to the variable guz.
   */
  person *myperson = (person *)malloc(sizeof(person));
  /**
   * There's a lot of details in this line:
   *
   * - The malloc function reserves said memory, with the space needed being
   *   passed with the first argument;
   *
   * - malloc returns a "void pointer" (a pointer without any type). So we use
   *   the (person *) to typecast the value to a pointer of person. Similar
   *   with things like `let var = "string" as Type`/`let var = <Type>"string"`
   *   in Typescript and other languages.
   *
   * - "sizeof" is not a actual function, because the compiler actually
   *   just transforms it into the actual memory size of person struct.
   */

  /**
   * Now we can store values of any size inside of the myperson struct
   */
  myperson->name = "Guz013";
  myperson->age = 19;

  printf("My person is named %s and is %d years old\n", (*myperson).name,
         (*myperson).age);

  /**
   * AND DON'T FORGET TO FREE THE MEMORY AFTER USING IT
   */
  free(myperson);
  /**
   * Note that free() DOES NOT DELETE the myperson pointer, it simply
   * frees/cleans the memory/data it points to. The myperson variable
   * will still point somewhere in memory, but we must not use that pointer
   * again until we allocate new data using it.
   */

  return 0;
}

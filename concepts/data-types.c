#include <stdio.h>

void draw(int x, int y) { printf("Drawing in coords: [%d,%d]", x, y); }

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
  printf("\n");

  /* Arrays can be multidimensional */
  char vowels[2][5] = {
      {'A', 'E', 'I', 'O', 'U'},
      {'a', 'e', 'i', 'o', 'u'},
  };

  /**
   * Structs are objects similar to objects or classes,
   * they contain several named variables inside them that can
   * be accessed via dot notation.
   *
   * Said variables need to be populated individually, like arrays.
   *
   * The most simple example can be a point (a object which has
   * x and y variables)
   *
   * This declares a type of Struct, similar with Typescript's
   * interface x {} or type x = {}.
   */
  struct point {
    int x;
    int y;
  };

  // "Declaring a variable of type struct<point>"
  struct point p;
  p.x = 3;
  p.y = 13;

  draw(p.x, p.y);

  /**
   * Typedefs allow the definition of custom types, which is
   * useful with things like pointers and structs. Following
   * the last example, we can short the syntax of "struct point p"
   * to just "point p" like any other variable declaration.
   */
  typedef struct {
    int x;
    int y;
  } point_type;

  point_type typed_p;
  typed_p.x = 6;
  typed_p.y = 26;

  /**
   * Structures can also hold pointers, **or pointers to other
   * structures** - the real power.
   *
   * An example of a vehicle could be:
   */
  typedef struct {
    char *brand;
    int model;
  } vehicle;

  vehicle motocycle;

  motocycle.brand = "Yamaha";
  motocycle.model = 2012;

  return 0;
}

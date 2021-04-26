#include <stdio.h>

void foo(const char * str, int i) {
   printf("%dth string: %d\n", i+1, str[i]);
}

void bar(const char * str) {
  printf("%c:%d %c:%d %c:%d %c:%d %c:%d\n", str[0], str[0], str[1],str[1], str[2], str[2], str[3], str[3], str[4], str[4]);
}

int main() {
  foo("\x03""www""\x01""a""\x02""pl", 4);
  foo("\x03""www""\x01""a""\x02""pl", 3);
  foo("\x03""www""\x01""a""\x02""pl", 2);
  
  bar("\x03www\x01a\x02pl");
  return 0;
}


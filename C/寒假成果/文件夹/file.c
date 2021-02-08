#include <stdio.h>
#include "file1.c"
int main() 
{
  extern void print();
  print();
}
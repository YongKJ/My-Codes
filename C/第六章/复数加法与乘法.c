#include <stdio.h>
struct complex
{
     int real;
     int image;
};
struct complex add(struct complex c1, struct complex c2) 
{
  struct complex c;
  c.real = c1.real + c2.real;
  c.image = c1.image + c2.image;
  return c;
}
struct complex mul(struct complex c1, struct complex c2) 
{
  struct complex c;
  c.real = c1.real * c2.real - c1.image * c2.image;
  c.image = c1.real * c2.image + c1.image * c2.real;
  return c;
}
int main()
{
  struct complex a, b,c,d;
  while (scanf("%d%d%d%d", &a.real, &a.image, &b.real, &b.image) != EOF) 
  {
    c = add(a, b);
    d = mul(a, b);
    printf("%d+(%di)\n%d+(%di)\n", c.real, c.image, d.real, d.image);
  }
}
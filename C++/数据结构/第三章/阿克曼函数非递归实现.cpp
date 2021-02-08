
#include <iostream>

using std::cout;

using std::endl;

const int maxN = 8500;

static int akm[maxN][maxN] ={0};



int Ackerman(int m, int n)

{

  for(int j = 0; j <maxN; j++)

     akm[0][j] = j+1;

  for(int i = 1; i <maxN; i++)

  {

    akm[i][0] = akm[i-1][1];

    for(int j = 1; j <= maxN; j++)

    {

       akm[i][j] = akm[i-1][akm[i][j-1]];

    }

  }

   return akm[m][n];

}

int main(int argc, char *argv[])

    {

  cout << "akm[" << 3 << "]"
       << "[" << 9 << "]"
       << " = " << Ackerman(3, 9) << endl;

  cout << "akm[" << 3 << "]"
       << "[" << 10 << "]"
       << " = " << Ackerman(3, 10) << endl;

  return 0;
}
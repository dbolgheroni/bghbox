#include <iostream>

using namespace std;

class PosComp1 {
public:
  int Calcula()
  {
    return 1;
  }
};

class PosComp2 : public PosComp1 {
public:
  virtual int Calcula()
  {
    return 2;
  }
};

class PosComp3 : public PosComp2 {
public:
  int Calcula()
  {
    return 3;
  }
};

int main()
{
  int Result = 0;
  PosComp1 *Objs[3];

  Objs[0] = new PosComp1();
  Objs[1] = new PosComp2();
  Objs[2] = new PosComp3();
  
  for (int i = 0; i < 3; i++)
    Result += Objs[i]->Calcula();

  cout << Result << endl;
  return 0;
}

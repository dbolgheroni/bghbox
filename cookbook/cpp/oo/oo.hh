class Test1 {
public:
  virtual int getValue(void) = 0;
};

class Test2 : public Test1 {
public:
  int getValue(void);
};

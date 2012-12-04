#include <iostream>
#include <memory>
#include <vector>
 
using namespace std;

class Animal {
public:
  void eat() {
    cout << "I eat like a generic animal.\n";
  }
  // polymorphic deletes require a virtual base destructor
  virtual ~Animal() {
  }
};
 
class Wolf : public Animal {
public:
  void eat() {
    cout << "I eat like a wolf!\n";
  }
};
 
class Fish : public Animal {
public:
  void eat() {
    cout << "I eat like a fish!\n";
  }
};
 
class GoldFish : public Fish {
public:
  void eat() {
    cout << "I eat like a goldfish!\n";
  }
};
 
class OtherAnimal : public Animal {
};
 
int main() {
  /*
  vector<unique_ptr<Animal>> animals;
 
  animals.push_back(unique_ptr<Animal>(new Animal));
  animals.push_back(unique_ptr<Animal>(new Wolf));
  animals.push_back(unique_ptr<Animal>(new Fish));
  animals.push_back(unique_ptr<Animal>(new GoldFish));
  animals.push_back(unique_ptr<Animal>(new OtherAnimal));
 
  for (auto it = animals.begin(); it != animals.end(); ++it) {
    (*it)->eat();
  }
  */

  Animal *objs[5];
  objs[0] = new Animal();
  objs[1] = new Wolf();
  objs[2] = new Fish();
  objs[3] = new GoldFish();
  objs[4] = new OtherAnimal();

  objs[0]->eat();
  objs[1]->eat();
  objs[2]->eat();
  objs[3]->eat();
  objs[4]->eat();

  /* When declared like this, 'virtual' has no function. */
  /*
  Animal animal;
  Wolf wolf;
  Fish fish;
  GoldFish goldfish;
  OtherAnimal otheranimal;

  animal.eat();
  wolf.eat();
  fish.eat();
  goldfish.eat();
  otheranimal.eat();
  */
}

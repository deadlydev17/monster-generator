#include <iostream>
#include <string>

class Monster {
public:
  enum class Type {
    dragon,
    goblin,
    ogre,
    orc,
    skeleton,
    troll,
    vampire,
    zombie,

    max_monster_types,
  };

private:
  Type m_type{};
  std::string m_name{};
  std::string m_roar{};
  int m_hitPoint{};

public:
  Monster(Type type, const std::string& name, const std::string& roar, int hitPoint) : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoint{hitPoint}{}
};

int main(){

  Monster skeleton{Monster::Type::skeleton, "Bones" , "rattle", 4};

  return 0;
}

#include <iostream>
#include <string>
#include <string_view>

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
  Monster(Type type, const std::string &name, const std::string &roar,
          int hitPoint)
      : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoint{hitPoint} {}

  std::string_view getTypeMonster() const {
    switch (m_type) {
    case Type::dragon:
      return "dragon";
    case Type::goblin:
      return "goblin";
    case Type::ogre:
      return "ogre";
    case Type::orc:
      return "orc";
    case Type::skeleton:
      return "skeleton";
    case Type::troll:
      return "troll";
    case Type::vampire:
      return "vampire";
    case Type::zombie:
      return "zombie";
    default:
      return "???";
    }
  };
  void print() const {
    std::cout << m_name << " the " << getTypeMonster() << " has " << m_hitPoint << " hit points and says *" << m_roar << "* \n";
  }
};

int main() {

  Monster skeleton{Monster::Type::skeleton, "Bones", "rattle", 4};
  skeleton.print();

  return 0;
}

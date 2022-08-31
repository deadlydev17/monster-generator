#include <array>
#include <iostream>
#include <random>
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
    std::cout << m_name << " the " << getTypeMonster() << " has " << m_hitPoint
              << " hit points and says *" << m_roar << "* \n";
  }
};

class MonsterGenerator {
public:
  std::array<std::string_view, 6> s_names{
      "Bob", "Jerry", "Alex", "Jack", "Mike", "Dick",
  };
  std::array<std::string_view, 6> s_rour{
      "rattle", "roar", "shiii", "bruhh", "Damn", "shit",
  };

  static int getRandomNumber(int min, int max) {
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution<> die{min, max};
    return die(mt);
  }

  static Monster generateMonster() {
    auto monsterType{static_cast<int>(getRandomNumber(
        0, static_cast<int>(Monster::Type::max_monster_types) - 1))};
    return Monster{static_cast<Monster::Type>(monsterType), "Bob", "rattle",
                   getRandomNumber(1, 100)};
  }
};

int main() {

  Monster skeleton{MonsterGenerator::generateMonster()};
  skeleton.print();

  return 0;
}

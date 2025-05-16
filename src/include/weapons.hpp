#include "items.hpp"
#include <nlohmann/json.hpp>

class Weapon : public items::Item {
    public:
        Weapon(std::string name, int baseValue, int monetaryValue, items::Rarity rarity,
            float dropRate, int damage)
            : items::Item(name, baseValue, monetaryValue, rarity, dropRate),
                damage(damage) {};

        int getDamage() const { return damage; }

        static std::vector<Weapon> loadWeapons();

    private:

        int damage;
};
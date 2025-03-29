#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <random>
#include <lua.hpp>

namespace items {

    enum class Rarity {
        COMMON,
        UNCOMMON,
        RARE,
        EPIC,
        LEGENDARY
    };

    struct Item {
        public:
            std::string name;
            int baseValue;
            int monetaryValue;
            Rarity rarity;
            float dropRate;

            Item(std::string name, int baseValue, int monetaryValue, Rarity rarity, float dropRate)
                : name(name), baseValue(baseValue), monetaryValue(monetaryValue), rarity(rarity), dropRate(dropRate) {};

            Item();

            virtual ~Item() {};

            int addItem(lua_State* L);

            void generateRandomItem();

        private:
            void randomizeItem(float dropRate);
            std::string rarityToString(Rarity rarity) const;


    };
};

#endif // !ITEMS_H
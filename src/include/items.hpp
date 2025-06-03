#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <string>
#include <random>
//#include <lua.hpp>

namespace items {

    enum class ItemSlot {
        WEAPON,
        ARMOR,
        TRINKET,
        CONSUMABLE
    };

    typedef ItemSlot ItemSlot;

    enum class Rarity {
        COMMON,
        UNCOMMON,
        RARE,
        EPIC,
        LEGENDARY
    };

    typedef Rarity Rarity;

    struct Item {
        public:
            std::string name;
            int baseValue;
            int monetaryValue;
            Rarity rarity;
            float dropRate(Rarity rarity) {
                switch (rarity) {
                    case Rarity::COMMON: return 0.9f;
                    case Rarity::UNCOMMON: return 0.7f;
                    case Rarity::RARE: return 0.5f;
                    case Rarity::EPIC: return 0.25f;
                    case Rarity::LEGENDARY: return 0.05f;
                    default: return 0.0f;
                }
            };

            float rarityDropRate = dropRate(rarity);

            Item(std::string name, int baseValue, int monetaryValue, Rarity rarity, float dropRate)
                : name(name), baseValue(baseValue), monetaryValue(monetaryValue), rarity(rarity), rarityDropRate(dropRate) {};

            Item();

            virtual ~Item() {};

            //int addItem(lua_State* L);

            void randomizeItem(float rarityDropRate);
            // generateRandomItem();

        private:
            std::string rarityToString(Rarity rarity);
    };
};

#endif // !ITEMS_HPP
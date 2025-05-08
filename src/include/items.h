#ifndef ITEMS_H
#define ITEMS_H

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

            Item(std::string name, int baseValue, int monetaryValue, Rarity rarity, float rarityDropRate)
                : name(name), baseValue(baseValue), monetaryValue(monetaryValue), rarity(rarity), rarityDropRate(rarityDropRate) {};

            Item();

            virtual ~Item() {};

            //int addItem(lua_State* L);

            void generateRandomItem();

        private:
            void randomizeItem(float *dropRate(Rarity rarity));
            std::string rarityToString(Rarity rarity) const;
    };
};

#endif // !ITEMS_H
#include "../../include/entities.hpp"
#include "../../include/player.hpp"
#include "../../include/items.hpp"

/*items::Item getEquippedItems(items::ItemSlot slot) const {
            auto idx = equippedItems.find(slot);
            if (idx != equippedItems.end()) {
                return idx->second;
            }
        }*/

 /**
         * @brief Checks what entity type it is
         * @param Entity* entity
         * @return (entity == Player) ? 1 : 0
         */
bool Entity::checkEntity(Entity* entity) const {
    return dynamic_cast<Player*>(entity) != nullptr;
}

void Entity::attack() {
    if (checkEntity(this)) {

    } else {

    }

}
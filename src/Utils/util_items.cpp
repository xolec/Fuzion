#include "util_items.h"

#include "util.h"
#include "../interfaces.h"
namespace Util
{
	namespace Items
	{
		std::string GetItemName(const enum ItemDefinitionIndex index)
		{
		    for( auto it : ItemDefinitionIndexMap ){
		        if( it.first != index )
		            continue;
                return it.second.entityName;
		    }
		    return "ITEM_INVALID";
		}

		std::string GetItemEntityName(ItemDefinitionIndex index)
		{
		    for( auto it : ItemDefinitionIndexMap ){
		        if( it.first != index )
		            continue;

                std::string entityName = it.second.entityName;
                if (entityName.find("weapon_") != std::string::npos)
                    entityName.erase(entityName.find("weapon_"), std::string("weapon_").length());

                return entityName;
            }

			return "INVALID";
		}

		std::string GetItemConfigEntityName(ItemDefinitionIndex index)
		{
            for( auto it : ItemDefinitionIndexMap ) {
                if (it.first != index)
                    continue;

                return it.second.entityName;
            }
			return "INVALID";
		}

		std::string GetItemDisplayName(ItemDefinitionIndex index)
		{
            for( auto it : ItemDefinitionIndexMap ) {
                if (it.first != index)
                    continue;
                if (it.first == ItemDefinitionIndex::INVALID)
                    return it.second.displayName;
                return Util::WstringToString(localize->FindSafe(it.second.displayName));
            }

			return "INVALID";
		}

        std::string GetItemModelName(ItemDefinitionIndex index)
        {
            for( auto it : ItemDefinitionIndexMap ) {
                if (it.first != index)
                    continue;
               return it.second.entityModel;
            }

            return "INVALID";
        }

        std::string GetItemKillIcon(ItemDefinitionIndex index)
        {
            for( auto it : ItemDefinitionIndexMap ) {
                if (it.first != index)
                    continue;
                return it.second.killIcon;
            }

            return "INVALID";
        }

		ItemDefinitionIndex GetItemIndex(const std::string itemName)
		{
            for( auto it : ItemDefinitionIndexMap ) {
                if( strcmp( it.second.entityName, itemName.c_str() ) )
                    continue;

                return it.first;
            }
            return ItemDefinitionIndex::INVALID;
		}

		bool IsIndexInMap( ItemDefinitionIndex index )
        {
		    for( auto it : ItemDefinitionIndexMap ) {
		        if( index == it.first )
		            return true;
		    }
		    return false;
        }
		bool IsKnife(ItemDefinitionIndex index)
		{
			switch (index)
			{
				case ItemDefinitionIndex::WEAPON_KNIFE:
				case ItemDefinitionIndex::WEAPON_KNIFE_T:
				case ItemDefinitionIndex::WEAPON_KNIFE_BAYONET:
				case ItemDefinitionIndex::WEAPON_KNIFE_FLIP:
				case ItemDefinitionIndex::WEAPON_KNIFE_GUT:
				case ItemDefinitionIndex::WEAPON_KNIFE_KARAMBIT:
				case ItemDefinitionIndex::WEAPON_KNIFE_M9_BAYONET:
				case ItemDefinitionIndex::WEAPON_KNIFE_TACTICAL:
				case ItemDefinitionIndex::WEAPON_KNIFE_BUTTERFLY:
				case ItemDefinitionIndex::WEAPON_KNIFE_FALCHION:
				case ItemDefinitionIndex::WEAPON_KNIFE_SURVIVAL_BOWIE:
				case ItemDefinitionIndex::WEAPON_KNIFE_PUSH:
				case ItemDefinitionIndex::WEAPON_KNIFE_URSUS:
				case ItemDefinitionIndex::WEAPON_KNIFE_GYPSY_JACKKNIFE:
				case ItemDefinitionIndex::WEAPON_KNIFE_STILETTO:
				case ItemDefinitionIndex::WEAPON_KNIFE_WIDOWMAKER:
				case ItemDefinitionIndex::WEAPON_KNIFE_CSS:
				case ItemDefinitionIndex::WEAPON_KNIFE_GHOST:
				//case ItemDefinitionIndex::WEAPON_KNIFEGG:
					return true;
				default:
					return false;
			}
		}

		bool IsUtility(ItemDefinitionIndex index)
		{
			switch (index)
			{
				case ItemDefinitionIndex::WEAPON_C4:
				case ItemDefinitionIndex::WEAPON_FLASHBANG:
				case ItemDefinitionIndex::WEAPON_HEGRENADE:
				case ItemDefinitionIndex::WEAPON_INCGRENADE:
				case ItemDefinitionIndex::WEAPON_MOLOTOV:
				case ItemDefinitionIndex::WEAPON_SMOKEGRENADE:
				case ItemDefinitionIndex::WEAPON_DECOY:
					return true;
				default:
					return false;
			}
		}

		bool IsGlove(ItemDefinitionIndex index)
		{
			switch (index)
			{
				case ItemDefinitionIndex::GLOVE_STUDDED_BLOODHOUND:
				case ItemDefinitionIndex::GLOVE_SPECIALIST:
				case ItemDefinitionIndex::GLOVE_CT_SIDE:
				case ItemDefinitionIndex::GLOVE_T_SIDE:
				case ItemDefinitionIndex::GLOVE_MOTORCYCLE:
				case ItemDefinitionIndex::GLOVE_SLICK:
				case ItemDefinitionIndex::GLOVE_SPORTY:
				case ItemDefinitionIndex::GLOVE_LEATHER_WRAP:
					return true;
				default:
					return false;
			}
		}

		bool IsCTWeapon(ItemDefinitionIndex index)
		{
			switch (index)
			{
				case ItemDefinitionIndex::WEAPON_M4A1:
				case ItemDefinitionIndex::WEAPON_M4A1_SILENCER:
				case ItemDefinitionIndex::WEAPON_HKP2000:
				case ItemDefinitionIndex::WEAPON_FIVESEVEN:
				case ItemDefinitionIndex::WEAPON_USP_SILENCER:
				case ItemDefinitionIndex::WEAPON_AUG:
				case ItemDefinitionIndex::WEAPON_SCAR20:
				case ItemDefinitionIndex::WEAPON_FAMAS:
				case ItemDefinitionIndex::WEAPON_MAG7:
				case ItemDefinitionIndex::WEAPON_MP9:
					return true;
				default:
					return false;
			}
		}

		bool IsTWeapon(ItemDefinitionIndex index)
		{
			switch (index)
			{
				case ItemDefinitionIndex::WEAPON_AK47:
				case ItemDefinitionIndex::WEAPON_GALILAR:
				case ItemDefinitionIndex::WEAPON_GLOCK:
				case ItemDefinitionIndex::WEAPON_SG556:
				case ItemDefinitionIndex::WEAPON_G3SG1:
				case ItemDefinitionIndex::WEAPON_TEC9:
				case ItemDefinitionIndex::WEAPON_SAWEDOFF:
				case ItemDefinitionIndex::WEAPON_MAC10:
					return true;
				default:
					return false;
			}
		}

		bool IsScopeable(ItemDefinitionIndex index)
		{
			switch (index)
			{
				case ItemDefinitionIndex::WEAPON_AUG:
				case ItemDefinitionIndex::WEAPON_AWP:
				case ItemDefinitionIndex::WEAPON_G3SG1:
				case ItemDefinitionIndex::WEAPON_SCAR20:
				case ItemDefinitionIndex::WEAPON_SG556:
				case ItemDefinitionIndex::WEAPON_SSG08:
					return true;
				default:
					return false;
			}
		}
	}
}

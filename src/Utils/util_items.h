#pragma once

#include <string>
#include "../SDK/definitions.h" //ItemDefIndex

namespace Util
{
	namespace Items
	{
		/*
		 * Look up a ItemDefinitionIndex ordinal value by the symbolic name
		 */
		enum ItemDefinitionIndex GetItemIndex(const std::string);

		/*
		 * Look up the symbolic name of a ItemDefinitionIndex ordinal value
		 */
		std::string GetItemName(const enum ItemDefinitionIndex);
		std::string GetItemEntityName(ItemDefinitionIndex index);
		std::string GetItemConfigEntityName(ItemDefinitionIndex index);
		std::string GetItemDisplayName(ItemDefinitionIndex index);
		std::string GetItemModelName(ItemDefinitionIndex index);
		std::string GetItemKillIcon(ItemDefinitionIndex index);
        bool IsIndexInMap( ItemDefinitionIndex index );

		bool IsKnife(ItemDefinitionIndex index);
		bool IsUtility(ItemDefinitionIndex index);
		bool IsGlove(ItemDefinitionIndex index);
		bool IsCTWeapon(ItemDefinitionIndex index);
		bool IsTWeapon(ItemDefinitionIndex index);
		bool IsScopeable(ItemDefinitionIndex index);
	}
}

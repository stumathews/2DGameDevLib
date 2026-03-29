#pragma once
#include <memory>

#include "resource/ResourceManager.h"


namespace gamelib
{
	enum class Direction;
	class GameObject;
}

namespace mazer
{

	class Room;
	class Player;
	class Level;
	class Enemy;

	class Pickup;

	class CharacterBuilder
	{
	public:

		// Builds a player character game object
		/**
		 *
		 * @param playerName Name of the player
		 * @param playerRoom Room the player is in by default
		 * @param playerResourceId The sprite graphic asset that will be used for animating the player
		 * @param nickName The nickname of the player
		 * @return Player
		 */
		static std::shared_ptr<Player> BuildPlayer(const std::string& playerName,
		                                           const std::shared_ptr<Room>& playerRoom,
		                                           int playerResourceId,
		                                           const std::string& nickName);

		// Builds a pickup game object
		static std::shared_ptr<mazer::Pickup> BuildPickup(const std::string& pickupName,
			const std::shared_ptr<Room>& pickupRoom,
			int pickupResourceId);

		// Builds an Enemy game object
		static std::shared_ptr<Enemy> BuildEnemy(const std::string& enemyName, const std::shared_ptr<Room>& enemyRoom,
			int enemySpriteResourceId,
			gamelib::Direction startingDirection,
			const std::shared_ptr<const Level>&
			level);
	};
}

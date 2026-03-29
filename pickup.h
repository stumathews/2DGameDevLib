#pragma once

#include <geometry/Coordinate.h>
#include <objects/DrawableGameObject.h>

namespace gamelib
{
	class AnimatedSprite;
	class SpriteAsset;
	class Asset;
}

namespace mazer
{

	class Player;

	class Pickup final : public gamelib::DrawableGameObject, public std::enable_shared_from_this<Pickup>
	{
	public:
		Pickup(const std::string& name, const std::string& type, int x, int y, int width,
		       int height, bool visible, int inRoomNumber);

		Pickup(const std::string& name, const std::string& type, gamelib::Coordinate<int> startingPoint, bool visible,
		       int inRoomNumber, std::shared_ptr<gamelib::SpriteAsset> asset);

		explicit Pickup(bool visible);

		gamelib::GameObjectType GetGameObjectType() override;

		std::string GetSubscriberName() override;
		std::string GetName() override;
		bool IsInSameRoomAsPlayer(std::shared_ptr<Player> player) const;
		gamelib::ListOfEvents HandleEvent(const std::shared_ptr<gamelib::Event>& event, unsigned long deltaMs) override;

		void Initialize();
		void Draw(SDL_Renderer* renderer) override;
		void Update(unsigned long deltaMs) override;

		int RoomNumber;
		std::shared_ptr<gamelib::Asset> Asset;

	protected:
		void SetBounds();

	private:
		int width;
		int height;
		std::shared_ptr<gamelib::AnimatedSprite> sprite;
	};
}

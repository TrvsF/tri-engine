#include "game.h"

namespace game
{
	inline void Game::AddGameObject(object::GameObject* game_object)
	{
		m_collision->AddCollisionObj(game_object);
		m_gameworld_objects.push_back(game_object);
	}

	inline void Game::SetPlayer(object::Player* player)
	{
		m_player = player;
	}

	inline const std::vector<object::GameObject*> Game::GetGameObjects() const
	{
		return m_gameworld_objects;
	}

	inline object::Player* Game::GetPlayer()
	{
		return m_player;
	}
}
#ifndef GAME_H_
#define GAME_H_

#include "../base/helper_macos.h"
#include "object/objects/game-object.h"
#include "object/objects/texture-object.h"

#include <vector>

namespace game
{
	class Game
	{
	private:
		static Game* s_instance;

		std::vector<object::GameObject*> m_game_objects;
		object::GameObject* m_player;
	public:
		Game();

		static void Create();
		static inline Game* Get();
		static void Destroy();

		inline void AddGameObject(object::GameObject* game_object);
		inline const std::vector<object::GameObject*> GetGameObjects() const;
		inline void SetPlayer(object::GameObject* player);
		inline object::GameObject* GetPlayer();

		void Start();
		void Tick();
	};
}

#include "game-inl.h"

#endif
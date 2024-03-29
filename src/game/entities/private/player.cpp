#include "../player.h"

namespace object
{
	Player::Player(GameObject* gameobject, const char* textureid)
		: TextureObject(gameobject, textureid)
	{
		SetEntityType(GameEntityType::Player);
		reset_tickvars();
	}

	void Player::Update()
	{
		m_offset_rotation.z = m_rotation;
		float yaw = (GetTransform().GetRotation().z + m_rotation) * DEG_TO_RAD;

		Vector2D direction_vec2d = { (float)cosf(yaw), (float)sin(yaw) };
		Vector2D pos_change_vec2d = direction_vec2d * m_velocity;

		m_offset_pos = { pos_change_vec2d.x, pos_change_vec2d.y };
		
		reset_tickvars();
	}
}
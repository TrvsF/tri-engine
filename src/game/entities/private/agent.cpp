#include "../agent.h"

namespace object
{
	Agent::Agent(GameObject* gameobject, int sides)
		: GeometryObject(gameobject, sides)
	{
		SetEntityType(GameEntityType::Agent);
		m_targetpos = VEC2_ZERO;
		m_velocity  = 0;
		m_turnspeed = 0;
		m_isturning = false;
		m_ismoving  = false;

		SetTargetpos({ 0, 0 });
	}

	void Agent::do_friction()
	{
		if (!m_ismoving)
		{
			m_velocity /= 1.1f;
			if (fabsf(m_velocity) < 0.05f) { m_velocity = 0; }
		}

		if (!m_isturning)
		{
			m_turnspeed /= 1.1f;
			if (fabsf(m_turnspeed) < 0.05f) { m_turnspeed = 0; }
		}

		m_isturning = false;
		m_ismoving  = false;
	}

	void Agent::calc_offsetpos()
	{
		float yaw = GetTransform().GetRotation().z * DEG_TO_RAD;

		Vector2D direction_vec2d  = { cosf(yaw), sinf(yaw) };
		Vector2D pos_change_vec2d = direction_vec2d * m_velocity;

		m_offset_pos	  = { pos_change_vec2d.x, pos_change_vec2d.y, 0 };
		m_offset_rotation = { 0, 0, m_turnspeed };
	}

	void Agent::TurnRight()
	{
		m_turnspeed = fminf(MAX_TURNSPEED, m_turnspeed + 0.5f);
		m_isturning = true;
	}

	void Agent::TurnLeft()
	{
		m_turnspeed = fmaxf(-MAX_TURNSPEED, m_turnspeed - 0.5f);
		m_isturning = true;
	}

	void Agent::MoveForward()
	{
		m_velocity = fminf(MAX_VELOCITY, m_velocity + 0.5f);
		m_ismoving = true;
	}

	void Agent::MoveBackward()
	{
		m_velocity = fmaxf(-MAX_VELOCITY, m_velocity - 0.5f);
		m_ismoving = true;
	}

	void Agent::SetTargetpos(Vector2D pos)
	{
		m_targetpos = pos;
	}

	void Agent::MoveToTargetPos()
	{
		float rotation = maths::GetAngleBetweenPoints({ GetPosition().x, GetPosition().y }, { m_targetpos });
		SetRotation(rotation);
		MoveForward();
	}

	void Agent::Update()
	{
		MoveToTargetPos();
		do_friction();
		calc_offsetpos();
	}
}
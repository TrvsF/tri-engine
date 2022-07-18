#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL.h>

#include "../src/util/vector2d.h"

namespace object
{
	class Texture
	{
	protected:
		SDL_Texture* m_texutre;

		Vector2D m_pos;
		int m_width;
		int m_height;
		float m_rotation;

	public:
		Texture();
		virtual ~Texture();

		void Set(SDL_Texture* texture);
		void Set(SDL_Texture* texture, float x, float y, float rotation);
		SDL_Texture* GetTexture();

		void Width(int width);
		int Width();

		void Height(int height);
		int Height();

		void Rotation(float rotation);
		float Rotation();

		void Pos(Vector2D pos);
		Vector2D Pos();
	};
}

#endif // !TEXTURE_H_
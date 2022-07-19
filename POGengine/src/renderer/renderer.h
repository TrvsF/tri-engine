#ifndef _RENDERER_H
#define _RENDERER_H

#include <SDL.h>
#include <SDL_image.h>

#include <vector>

#include "../src/engine/helper_macos.h"
#include "../src/object/texture.h"
#include "../src/renderer/assets.h"

namespace renderer
{
	class Renderer
	{
	private:
		static Renderer* s_instance;

		int m_width;
		int m_height;
		const char* m_title;

		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		Assets* m_assets;

		size_t m_num_texture_objects;
		std::vector<object::Texture*> m_texutre_objects;

		void add_texture_object(object::Texture* texture_object);
		void render_texture_object(object::Texture* texture_object);

		inline void resize_window();

	public:
		Renderer();
		virtual ~Renderer();

		static void Create();
		static Renderer* Get();
		static void Destroy();

		bool LoadTexture(const char* path_to_texture, object::Texture* texture_object);
		bool LoadTexture(const char* path_to_texture, object::Texture* texture_object, float x, float y, float rotation);

		bool Start(const char* window_title, int width, int height);

		void ClearBuffer();
		void Render();
		void Clean();

	};
}

#endif
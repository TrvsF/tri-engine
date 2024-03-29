#ifndef _RENDERER_H
#define _RENDERER_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

#include "../base/helper_macos.h"
#include "../game/object/component/aabb.h"
#include "../game/object/component/texture.h"
#include "../game/object/component/geometry.h"
#include "../base/console.h"
#include "../renderer/assets.h"

namespace renderer
{
	class Renderer
	{
	private:
		int				m_width;
		int				m_height;
		const char*		m_title;

		SDL_Window*		m_window;
		SDL_Renderer*	m_renderer;
		Assets*			m_assets;

		std::vector<object::AABB*>		m_aabbs;
		std::vector<object::Geometry*>	m_geometry_objects;
		std::vector<object::Texture*>	m_texutre_objects;

		void render_geometry_object(object::Geometry* geometry_object);
		void render_tri(object::Triangle* tri);

		void render_aabb(object::AABB* aabb);

		inline void add_texture_object(object::Texture* texture_object);
		inline void remove_texture_object(object::Texture* texture_object);
		void render_texture_object(object::Texture* texture_object);

		SDL_Texture* create_texture_from_text(const char* font, std::string text, SDL_Color colour);

		// console
		void render_console();

		void render_rect(SDL_Rect rect, SDL_Color colour);
		void render_fillrect(SDL_Rect rect, SDL_Color outline, SDL_Color fill);

		void set_window_icon();

		void clear_buffer();

		Renderer();
		virtual ~Renderer();
	public:
		static Renderer& SharedInstace() { static Renderer renderer; return renderer; }
		
		SDL_Texture* ReplaceText(const char* font, std::string text, SDL_Color colour, object::Texture* texture_obj);
		SDL_Texture* GetSetTextureObjFromText(const char* font, std::string text, SDL_Color colour, object::Texture* texture_obj);
		SDL_Texture* GetSetTextureObjFromId(const char* id, object::Texture* texture_obj);
		void LoadAllTextures();

		void LoadAllFonts();

		void LoadAABB(object::AABB* aabb);
		void LoadGeometry(object::Geometry* geometry_object); // TODO : system to unload these object

		inline SDL_Renderer* GetRendererObj();

		inline Vector2D GetScreensize();

		bool Start(const char* window_title, int width, int height);
		void Render();
		void Clean();
	};
}

#include "renderer-inl.h"

#endif
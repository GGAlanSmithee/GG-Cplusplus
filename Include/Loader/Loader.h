#ifndef LOADER_LOADER_H_INCLUDED
#define LOADER_LOADER_H_INCLUDED

#include <string>
#include "Engine/Renderer/Renderer.h"

class GG_TextureLoader
{
    public:
        friend GG_TextureLoader* const GG_CreateTextureLoader();
        friend void GG_DestroyTextureLoader(GG_TextureLoader*);
        friend SDL_Texture* const GG_LoadTexture(GG_TextureLoader* const, GG_Renderer* const, const std::string&);

    private:
        GG_TextureLoader() {}
        ~GG_TextureLoader() {}

        std::string _path = "../Gfx/";
};

/// Creates a GG_TextureLoader* instance
/// @author Alan Smithee
/// @date created 2015-02-09
/// @return a GG_TextureLoader*
/// @remarks friend of GG_TextureLoader
GG_TextureLoader* const GG_CreateTextureLoader();

/// Destroys a GG_TextureLoader* instance
/// @author Alan Smithee
/// @date created 2015-02-09
/// @param textureLoader the GG_TextureLoader* to destroy
/// @remarks friend of GG_TextureLoader
void GG_DestroyTextureLoader(GG_TextureLoader*);

/// Loads a SDL_Texture*
/// @author Alan Smithee
/// @date created 2015-02-09
/// @param textureLoader the loader to use to load the texture
/// @param renderer renderer used to convert the loaded surface to a texture
/// @param name the name of the texture to load
/// @return the loaded texture as a SDL_Texture*
/// @exception throws a file_not_found_error if the file could not be found
/// @exception throws a sdl_error if the SDL_Surface could not be converted to a SDL_Texture
SDL_Texture* const GG_LoadTexture(GG_TextureLoader* const, GG_Renderer* const, const std::string&);

#endif // LOADER_LOADER_H_INCLUDED

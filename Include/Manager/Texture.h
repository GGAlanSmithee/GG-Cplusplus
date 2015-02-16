#ifndef MANAGER_TEXTURE_H_INCLUDED
#define MANAGER_TEXTURE_H_INCLUDED

#include <memory>
#include <string>
#include <SDL.h>
#include <unordered_map>
#include "Loader/Texture.h"
#include "Engine/Renderer.h"

class GG_TextureManager
{
    public:
        GG_TextureManager(std::unique_ptr<GG_TextureLoader>);
        ~GG_TextureManager();

        friend const unsigned int GG_AddTexture(std::unique_ptr<GG_TextureManager> const&,
                                                std::unique_ptr<GG_Renderer> const&,
                                                const std::string&);
        friend SDL_Texture* const GG_GetTexture(std::unique_ptr<GG_TextureManager> const&, const unsigned int);
        friend void GG_SetDefaultTexture(std::unique_ptr<GG_TextureManager> const&,
                                         std::unique_ptr<GG_Renderer> const&,
                                         const std::string&);

    private:

        std::unique_ptr<GG_TextureLoader>              _textureLoader;
        SDL_Texture*                                   _defaultTexture;
        std::unordered_map<unsigned int, SDL_Texture*> _textures;
};

/// Adds a texture to the texture manager class and returns a handle to that texture
/// @author Alan Smithee
/// @date created 2015-02-08
/// @param textureManager the GG_TextureManager* to add the texture to
/// @param renderer the renderer used to load the texture
/// @param name the name of the texture to add
/// @return a unsigned int which is a handle used to retreive the added texture
/// @exception throws a std::invalid_argument exception if \a textureManager is null
/// @exception throws a std::invalid_argument exception if \a renderer is null
/// @remarks friend of the GG_TextureManager class
const unsigned int GG_AddTexture(std::unique_ptr<GG_TextureManager> const&,
                                 std::unique_ptr<GG_Renderer> const&,
                                 const std::string&);

/// Retreives a texture from the texture manager class
/// @author Alan Smithee
/// @date created 2015-02-08
/// @param textureManager the GG_TextureManager* to add the texture to
/// @param key the handle used to identify the texture
/// @return a SDL_Texture* if found, nullptr if not
/// @exception throws a std::invalid_argument exception if \a textureManager is null
/// @exception throws a std::invalid_argument exception if \a key is less than zero
/// @remarks friend of the GG_TextureManager class
SDL_Texture* const GG_GetTexture(std::unique_ptr<GG_TextureManager> const&, const unsigned int);

/// Sets the default texture of the \a textureManager
/// @author Alan Smithee
/// @date created 2015-02-09
/// @param textureManager the GG_TextureManager* to set the default texture on
/// @param renderer the GG_Renderer* used to convert a SDL_Surface* to a SDL_Texture*
/// @param name the name of the texture
/// @exception throws a std::invalid_argument exception if \a textureManager is null
/// @exception throws a std::invalid_argument exception if \a renderer is null
/// @remarks friend of GG_TextureManager
void GG_SetDefaultTexture(std::unique_ptr<GG_TextureManager> const&, GG_Renderer* const, const std::string&);

#endif // MANAGER_TEXTURE_H_INCLUDED
#ifndef MANAGER_TEXTURE_TEXTURE_H_INCLUDED
#define MANAGER_TEXTURE_TEXTURE_H_INCLUDED

#include <memory>
#include <string>
#include <SDL.h>
#include <unordered_map>
#include "Loader/Loader.h"
#include "Engine/Renderer/Renderer.h"

class GG_TextureManager
{
    public:
        friend GG_TextureManager* const GG_CreateTextureManager(GG_TextureLoader* const);
        friend void GG_DestroyTextureManager(GG_TextureManager*);
        friend const unsigned int GG_AddTexture(GG_TextureManager* const,
                                                std::unique_ptr<GG_Renderer> const&,
                                                const std::string&);
        friend SDL_Texture* const GG_GetTexture(GG_TextureManager* const, const unsigned int);
        friend void GG_SetDefaultTexture(GG_TextureManager* const,
                                         std::unique_ptr<GG_Renderer> const&,
                                         const std::string&);

    private:
        GG_TextureManager(GG_TextureLoader* const textureLoader) :
            _textureLoader(textureLoader)
        {
            // Empty
        }

        ~GG_TextureManager() { }

        GG_TextureLoader*                              _textureLoader;
        SDL_Texture*                                   _defaultTexture;
        std::unordered_map<unsigned int, SDL_Texture*> _textures;
};

/// Creates a GG_TextureManager* instance
/// @author Alan Smithee
/// @date created 2015-02-08
/// @date changed 2015-02-09
/// @param textureLoader the texture managers texture loader
/// @return a GG_TextureManager* instance
/// @remarks friend of the GG_TextureManager class
GG_TextureManager* const GG_CreateTextureManager(GG_TextureLoader* const);

/// Destroys a GG_TextureManager* instance
/// @author Alan Smithee
/// @date created 2015-02-08
/// @param textureManager the GG_TextureManager* to destroy
/// @remarks friend of the GG_TextureManager class
void GG_DestroyTextureManager(GG_TextureManager*);

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
const unsigned int GG_AddTexture(GG_TextureManager* const, std::unique_ptr<GG_Renderer> const&, const std::string&);

/// Retreives a texture from the texture manager class
/// @author Alan Smithee
/// @date created 2015-02-08
/// @param textureManager the GG_TextureManager* to add the texture to
/// @param key the handle used to identify the texture
/// @return a SDL_Texture* if found, nullptr if not
/// @exception throws a std::invalid_argument exception if \a textureManager is null
/// @exception throws a std::invalid_argument exception if \a key is less than zero
/// @remarks friend of the GG_TextureManager class
SDL_Texture* const GG_GetTexture(GG_TextureManager* const, const unsigned int);

/// Sets the default texture of the \a textureManager
/// @author Alan Smithee
/// @date created 2015-02-09
/// @param textureManager the GG_TextureManager* to set the default texture on
/// @param renderer the GG_Renderer* used to convert a SDL_Surface* to a SDL_Texture*
/// @param name the name of the texture
/// @exception throws a std::invalid_argument exception if \a textureManager is null
/// @exception throws a std::invalid_argument exception if \a renderer is null
/// @remarks friend of GG_TextureManager
void GG_SetDefaultTexture(GG_TextureManager* const, GG_Renderer* const, const std::string&);

#endif // MANAGER_TEXTURE_TEXTURE_H_INCLUDED

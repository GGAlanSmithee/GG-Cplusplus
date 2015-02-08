#ifndef MANAGER_TEXTURE_TEXTURE_H_INCLUDED
#define MANAGER_TEXTURE_TEXTURE_H_INCLUDED

#include <string>
#include <SDL.h>
#include <unordered_map>

class GG_TextureManager
{
    public:
        friend GG_TextureManager* const GG_CreateTextureManager();
        friend void GG_DestroyTextureManager(GG_TextureManager*);
        friend const unsigned int GG_AddTexture(GG_TextureManager* const, SDL_Texture*);
        friend SDL_Texture* const GG_GetTexture(GG_TextureManager* const, const unsigned int);

    private:
        GG_TextureManager() { };
        ~GG_TextureManager() { };

        SDL_Texture* _defaultTexture;
        std::unordered_map<unsigned int, SDL_Texture*> _textures;
};

/// Creates a GG_TextureManager* instance
/// @author Alan Smithee
/// @date created 2015-02-08
/// @return a GG_TextureManager* instance
/// @remarks friend of the GG_TextureManager class
GG_TextureManager* const GG_CreateTextureManager();

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
/// @param texture the texture to add
/// @return a unsigned int which is a handle used to retreive the added texture
/// @exception throws a std::invalid_argument exception if \a textureManager is null
/// @remarks friend of the GG_TextureManager class
const unsigned int GG_AddTexture(GG_TextureManager* const, SDL_Texture*);

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

#endif // MANAGER_TEXTURE_TEXTURE_H_INCLUDED

#include <dirent.h>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>
#include "Core.h"
#include "Graphics/Scene.h"
#include "Import.h"
#include "Resource.h"
#include "Utility/Utility.h"

namespace // private functions
{
    std::map<std::string, GGGraphics::Scene>   Scenes;
    std::map<std::string, GGGraphics::Texture> Textures;

    std::vector<std::string> AllowedImageEndings =
                            {
                                "png"
                            };

    void LoadTexture(const std::string& name, const GLenum unit = GL_TEXTURE0, const GLenum target = GL_TEXTURE_2D)
    {
        GGGraphics::Texture texture;

        texture.Target = target;
        texture.Unit = unit;

        SDL_Surface* surface = IMG_Load((GGResourceManager::GetTexturePath() + name).c_str());

        if (!surface)
        {
            //SetError("Failed to load surface: ", IMG_GetError());

            return;
        }

        int mode;

        if (surface->format->BytesPerPixel == 3) // RGB 24bit
        {
            mode = GL_RGB;
        }
        else if (surface->format->BytesPerPixel == 4) // RGBA 32bit
        {
            mode = GL_RGBA;
        }
        else
        {
            //SetError("Loaded image was of wrong format: ", name.c_str());

            SDL_FreeSurface(surface);

            return;
        }

        glGenTextures(1, &texture.Id);
        glBindTexture(texture.Target, texture.Id);
        glTexImage2D(texture.Target, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
        glTexParameteri(texture.Target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(texture.Target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(texture.Target, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(texture.Target, GL_TEXTURE_WRAP_T, GL_REPEAT);

        SDL_FreeSurface(surface);

        Textures[name] = texture;
    }
}

namespace GGResourceManager
{
    void LoadAllModels()
    {
        auto dir = opendir(GGResourceManager::GetModelPath().c_str());

        if (dir != nullptr)
        {
            struct dirent* entity = nullptr;

            while (entity = readdir(dir))
            {
                if (GGUtility::EndsWith(entity->d_name, GGResourceManager::GetGGFileEnding()))
                {
                    GGGraphics::Scene scene;

                    scene = ImportGGModel(entity->d_name);

                    /// @todo this should not be hardcoded!
                    scene.Textures.push_back("crate");

                    Scenes["test"] = scene;
                }
            }

            closedir(dir);
        }
    }

    void LoadAllTextures()
    {
        auto dir = opendir(GGResourceManager::GetTexturePath().c_str());

        if (dir != nullptr)
        {
            struct dirent* entity = nullptr;

            while (entity = readdir(dir))
            {
                std::string name(entity->d_name);

                if (GGUtility::Contains(AllowedImageEndings, name.substr(name.rfind(".") + 1)))
                {
                    LoadTexture(name);
                }
            }

            closedir(dir);
        }
    }

    const GGGraphics::Texture GetTexture(const std::string& texture)
    {
        return Textures[texture];
    }
}

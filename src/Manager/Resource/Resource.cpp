#include <dirent.h>
#include <glm/gtc/type_ptr.hpp>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Core.h"
#include "Graphics/Scene.h"
#include "Import.h"
#include "Manager/Logging/Logging.h"
#include "Resource.h"
#include "Utility/Utility.h"

namespace // private functions
{
    std::map<std::string, GGGraphics::Scene>   Scenes;
    std::map<std::string, GGGraphics::Texture> Textures;
    std::map<std::string, GGGraphics::Shader>  Shaders;

    std::vector<std::string> AllowedImageEndings =
                            {
                                "png"
                            };

    void LoadTexture(const std::string& name, const GLenum unit = GL_TEXTURE0, const GLenum target = GL_TEXTURE_2D)
    {
        GGGraphics::Texture texture;

        texture.Target = target;
        texture.Unit = unit;

        SDL_Surface* surface = IMG_Load((GGResource::GetTexturePath() + name).c_str());

        if (!surface)
        {
            GGLoggingManager::LogError("Failed to load surface: ", IMG_GetError());

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
            GGLoggingManager::LogError("Loaded image is of the wrong format: ", name.c_str());

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

        Textures[name.substr(0, name.rfind("."))] = texture;
    }

    void SetUniform1i(GGGraphics::Shader& shader, const GGEnum::Uniform uniform, const int value)
    {
        glUniform1i(shader.Uniforms[uniform], value);
    }

    void SetUniform1f(GGGraphics::Shader& shader, const GGEnum::Uniform uniform, const float value)
    {
        glUniform1f(shader.Uniforms[uniform], value);
    }

    void SetUniformMatrix4f(GGGraphics::Shader& shader, const GGEnum::Uniform uniform, const glm::mat4& value)
    {
        glUniformMatrix4fv(shader.Uniforms[uniform], 1, GL_FALSE, glm::value_ptr(value));
    }
}

namespace GGResource
{
    void LoadAllModels()
    {
//        auto dir = opendir(GGResource::GetModelPath().c_str());
//
//        if (dir == nullptr)
//        {
//            GGLoggingManager::LogError("Could not open model path: ",  GGResource::GetModelPath());
//
//            return;
//        }
//
//        struct dirent* entity = nullptr;
//
//        while (entity = readdir(dir))
//        {
//            if (GGUtility::EndsWith(entity->d_name, GGResource::GetGGModelFileEnding()))
//            {
//                auto scene = ImportGGModel(entity->d_name);
//
//                Scenes["test"] = scene;
//            }
//        }
//
//        closedir(dir);
    }

    void LoadAllTextures()
    {
        auto dir = opendir(GGResource::GetTexturePath().c_str());

        if (dir == nullptr)
        {
            GGLoggingManager::LogError("Could not open texture path: ",  GGResource::GetTexturePath());

            return;
        }

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

    void LoadAllShaders()
    {
//        auto dir = opendir(GGResource::GetShaderPath().c_str());
//
//        if (dir == nullptr)
//        {
//            GGLoggingManager::LogError("Could not open shader path: ", GGResource::GetShaderPath());
//            return;
//        }
//
//        struct dirent* entity = nullptr;
//
//        while (entity = readdir(dir))
//        {
//            if (GGUtility::EndsWith(entity->d_name, GGResource::GetGGShaderFileEnding()))
//            {
//                auto shader = ImportGGShader(entity->d_name);
//
//                if (!GGShaderWasImported())
//                {
//                    GGLoggingManager::LogError("One or more shader could not be loaded.");
//
//                    return;
//                }
//
//                Shaders[shader.Name] = shader;
//            }
//        }
//
//        closedir(dir);
    }

    const GGGraphics::Texture GetTexture(const std::string& texture)
    {
        return Textures[texture];
    }

    void UseShader(GGGraphics::Shader& shader)
    {
        glUseProgram(shader.Program);
    }

    void ActivateTexture(const std::string& texture)
    {
        glActiveTexture(GetTexture(texture).Unit);
        glBindTexture(GetTexture(texture).Target, GetTexture(texture).Id);
    }

    void SetMVPUniform(GGGraphics::Shader& shader, const glm::mat4& mvp)
    {
        SetUniformMatrix4f(shader, GGEnum::Uniform::MVP, mvp);
    }

    const GGGraphics::Scene GetScene(const std::string& scene)
    {
        for (auto kvp : Scenes)
        {
            auto f = kvp.first;
        }

        return Scenes[scene];
    }

    const GGGraphics::Shader GetShader(const std::string& shader)
    {
        return Shaders[shader];
    }
}

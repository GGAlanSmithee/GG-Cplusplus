#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED

namespace GGEnum
{
    /// Enumeration of different shader uniforms
    /// @author Alan Smithee
    /// @date created 2014-11-27
    enum class Uniform : int
    {
        MVP,
        TextureSampler
    };

    /// Enumeration of engine defined textures
    /// @author Alan Smithee
    /// @date created 2014-11-27
    /// @todo when implementing texture batching, this might be removed in favor of a map of texture (texture name / texture)
    enum class Texture : int
    {

    };
}

#endif // ENUM_H_INCLUDED

#ifndef MATH_VEC2_H_INCLUDED
#define MATH_VEC2_H_INCLUDED

#include <SDL.h>

/// 2d (x, y) floating point structure
/// @author Alan Smithee
/// @date created 2015-02-01
struct GG_Vec2f
{
    // Constructors
    GG_Vec2f();
    GG_Vec2f(const GG_Vec2f&);
    GG_Vec2f(const SDL_Rect&);
    GG_Vec2f(const int);
    GG_Vec2f(const float);
    GG_Vec2f(const int, const int);
    GG_Vec2f(const float, const float);

    // Comparison operators
    const bool operator==(const GG_Vec2f&) const;
    const bool operator!=(const GG_Vec2f&) const;

    // Unary operators
    const GG_Vec2f& operator=(const GG_Vec2f&);
    const GG_Vec2f& operator=(const SDL_Rect&);
    const GG_Vec2f& operator=(const int);
    const GG_Vec2f& operator=(const float);

    const GG_Vec2f& operator+=(const GG_Vec2f&);
    const GG_Vec2f& operator+=(const SDL_Rect&);
    const GG_Vec2f& operator+=(const int);
    const GG_Vec2f& operator+=(const float);

    const GG_Vec2f& operator-=(const GG_Vec2f&);
    const GG_Vec2f& operator-=(const SDL_Rect&);
    const GG_Vec2f& operator-=(const int);
    const GG_Vec2f& operator-=(const float);

    const GG_Vec2f& operator/=(const GG_Vec2f&);
    const GG_Vec2f& operator/=(const SDL_Rect&);
    const GG_Vec2f& operator/=(const int);
    const GG_Vec2f& operator/=(const float);

    const GG_Vec2f& operator*=(const GG_Vec2f&);
    const GG_Vec2f& operator*=(const SDL_Rect&);
    const GG_Vec2f& operator*=(const int);
    const GG_Vec2f& operator*=(const float);

    // Binary operators
    friend const GG_Vec2f operator+(const GG_Vec2f&, const GG_Vec2f&);
    friend const GG_Vec2f operator+(const GG_Vec2f&, const SDL_Rect&);
    friend const GG_Vec2f operator+(const GG_Vec2f&, const int);
    friend const GG_Vec2f operator+(const GG_Vec2f&, const float);

    friend const GG_Vec2f operator-(const GG_Vec2f&, const GG_Vec2f&);
    friend const GG_Vec2f operator-(const GG_Vec2f&, const SDL_Rect&);
    friend const GG_Vec2f operator-(const GG_Vec2f&, const int);
    friend const GG_Vec2f operator-(const GG_Vec2f&, const float);

    friend const GG_Vec2f operator/(const GG_Vec2f&, const GG_Vec2f&);
    friend const GG_Vec2f operator/(const GG_Vec2f&, const SDL_Rect&);
    friend const GG_Vec2f operator/(const GG_Vec2f&, const int);
    friend const GG_Vec2f operator/(const GG_Vec2f&, const float);

    friend const GG_Vec2f operator*(const GG_Vec2f&, const GG_Vec2f&);
    friend const GG_Vec2f operator*(const GG_Vec2f&, const SDL_Rect&);
    friend const GG_Vec2f operator*(const GG_Vec2f&, const int);
    friend const GG_Vec2f operator*(const GG_Vec2f&, const float);

    float x;
    float y;
};

#endif // MATH_VEC2_H_INCLUDED

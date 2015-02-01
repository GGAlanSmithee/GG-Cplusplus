#ifndef MATH_VEC2_H_INCLUDED
#define MATH_VEC2_H_INCLUDED

#include <SDL.h>

namespace GGMath
{
  /// 2d (x, y) floating point structure
  /// @author Alan Smithee
  /// @date created 2015-02-01
  struct Vec2
  {
    // Constructors
    Vec2();
    Vec2(const Vec2&);
    Vec2(const SDL_Rect&);
    Vec2(const int);
    Vec2(const float);
    Vec2(const int, const int);
    Vec2(const float, const float);

    // Comparison operators
    const bool operator==(const Vec2&) const;
    const bool operator!=(const Vec2&) const;

    // Unary operators
    const Vec2& operator=(const Vec2&);
    const Vec2& operator=(const SDL_Rect&);
    const Vec2& operator=(const int);
    const Vec2& operator=(const float);

    const Vec2& operator+=(const Vec2&);
    const Vec2& operator+=(const SDL_Rect&);
    const Vec2& operator+=(const int);
    const Vec2& operator+=(const float);

    const Vec2& operator-=(const Vec2&);
    const Vec2& operator-=(const SDL_Rect&);
    const Vec2& operator-=(const int);
    const Vec2& operator-=(const float);

    const Vec2& operator/=(const Vec2&);
    const Vec2& operator/=(const SDL_Rect&);
    const Vec2& operator/=(const int);
    const Vec2& operator/=(const float);

    const Vec2& operator*=(const Vec2&);
    const Vec2& operator*=(const SDL_Rect&);
    const Vec2& operator*=(const int);
    const Vec2& operator*=(const float);

    // Binary operators
    friend const Vec2 operator+(const Vec2&, const Vec2&);
    friend const Vec2 operator+(const Vec2&, const SDL_Rect&);
    friend const Vec2 operator+(const Vec2&, const int);
    friend const Vec2 operator+(const Vec2&, const float);

    friend const Vec2 operator-(const Vec2&, const Vec2&);
    friend const Vec2 operator-(const Vec2&, const SDL_Rect&);
    friend const Vec2 operator-(const Vec2&, const int);
    friend const Vec2 operator-(const Vec2&, const float);

    friend const Vec2 operator/(const Vec2&, const Vec2&);
    friend const Vec2 operator/(const Vec2&, const SDL_Rect&);
    friend const Vec2 operator/(const Vec2&, const int);
    friend const Vec2 operator/(const Vec2&, const float);

    friend const Vec2 operator*(const Vec2&, const Vec2&);
    friend const Vec2 operator*(const Vec2&, const SDL_Rect&);
    friend const Vec2 operator*(const Vec2&, const int);
    friend const Vec2 operator*(const Vec2&, const float);

    float x;
    float y;
  };
}

#endif // MATH_VEC2_H_INCLUDED

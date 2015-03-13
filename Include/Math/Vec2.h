#ifndef MATH_VEC2_H_INCLUDED
#define MATH_VEC2_H_INCLUDED

#include "Rect.h"

class GG_Rect;

/// 2d (x, y) floating point structure
/// @author Alan Smithee
/// @date created 2015-02-01
struct GG_Vec2f
{
    // Constructors
    GG_Vec2f();
    GG_Vec2f(GG_Vec2f const&);
    GG_Vec2f(GG_Rect const&);
    GG_Vec2f(const int);
    GG_Vec2f(const float);
    GG_Vec2f(const int, const int);
    GG_Vec2f(const float, const float);

    // Comparison operators
    const bool operator==(GG_Vec2f const&) const;
    const bool operator!=(GG_Vec2f const&) const;

    // Unary operators
    GG_Vec2f const& operator=(GG_Vec2f const&);
    GG_Vec2f const& operator=(const int);
    GG_Vec2f const& operator=(const float);

    GG_Vec2f const& operator+=(GG_Vec2f const&);
    GG_Vec2f const& operator+=(GG_Rect const&);
    GG_Vec2f const& operator+=(const int);
    GG_Vec2f const& operator+=(const float);

    GG_Vec2f const& operator-=(GG_Vec2f const&);
    GG_Vec2f const& operator-=(GG_Rect const&);
    GG_Vec2f const& operator-=(const int);
    GG_Vec2f const& operator-=(const float);

    GG_Vec2f const& operator/=(GG_Vec2f const&);
    GG_Vec2f const& operator/=(GG_Rect const&);
    GG_Vec2f const& operator/=(const int);
    GG_Vec2f const& operator/=(const float);

    GG_Vec2f const& operator*=(GG_Vec2f const&);
    GG_Vec2f const& operator*=(GG_Rect const&);
    GG_Vec2f const& operator*=(const int);
    GG_Vec2f const& operator*=(const float);

    // Binary operators
    friend const GG_Vec2f operator+(GG_Vec2f const&, GG_Vec2f const&);
    friend const GG_Vec2f operator+(GG_Vec2f const&, GG_Rect const&);
    friend const GG_Vec2f operator+(GG_Vec2f const&, const int);
    friend const GG_Vec2f operator+(GG_Vec2f const&, const float);

    friend const GG_Vec2f operator-(GG_Vec2f const&, GG_Vec2f const&);
    friend const GG_Vec2f operator-(GG_Vec2f const&, GG_Rect const&);
    friend const GG_Vec2f operator-(GG_Vec2f const&, const int);
    friend const GG_Vec2f operator-(GG_Vec2f const&, const float);

    friend const GG_Vec2f operator/(GG_Vec2f const&, GG_Vec2f const&);
    friend const GG_Vec2f operator/(GG_Vec2f const&, GG_Rect const&);
    friend const GG_Vec2f operator/(GG_Vec2f const&, const int);
    friend const GG_Vec2f operator/(GG_Vec2f const&, const float);

    friend const GG_Vec2f operator*(GG_Vec2f const&, GG_Vec2f const&);
    friend const GG_Vec2f operator*(GG_Vec2f const&, GG_Rect const&);
    friend const GG_Vec2f operator*(GG_Vec2f const&, const int);
    friend const GG_Vec2f operator*(GG_Vec2f const&, const float);

    float x;
    float y;
};

#endif // MATH_VEC2_H_INCLUDED

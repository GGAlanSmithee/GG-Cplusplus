#ifndef MATH_RECT_H_INCLUDED
#define MATH_RECT_H_INCLUDED

#include "Vec2.h"

class GG_Vec2f;

/// 4d (x, y, w, h) floating point structure representing a floating point rect
/// @author Alan Smithee
/// @date created 2015-03-01
struct GG_Rect
{
    // Constructors
    GG_Rect();
    GG_Rect(GG_Rect const&);
    GG_Rect(const int);
    GG_Rect(const float);
    GG_Rect(const int, const int, const int, const int);
    GG_Rect(const float, const float, const float, const float);

    // Comparison operators
    const bool operator==(GG_Rect const&) const;
    const bool operator!=(GG_Rect const&) const;

    // Unary operators
    GG_Rect const& operator=(GG_Rect const&);
    GG_Rect const& operator=(GG_Vec2f const&);
    GG_Rect const& operator=(const int);
    GG_Rect const& operator=(const float);

    GG_Rect const& operator+=(GG_Rect const&);
    GG_Rect const& operator+=(GG_Vec2f const&);
    GG_Rect const& operator+=(const int);
    GG_Rect const& operator+=(const float);

    GG_Rect const& operator-=(GG_Rect const&);
    GG_Rect const& operator-=(GG_Vec2f const&);
    GG_Rect const& operator-=(const int);
    GG_Rect const& operator-=(const float);

    GG_Rect const& operator/=(GG_Rect const&);
    GG_Rect const& operator/=(GG_Vec2f const&);
    GG_Rect const& operator/=(const int);
    GG_Rect const& operator/=(const float);

    GG_Rect const& operator*=(GG_Rect const&);
    GG_Rect const& operator*=(GG_Vec2f const&);
    GG_Rect const& operator*=(const int);
    GG_Rect const& operator*=(const float);

    // Binary operators
    friend const GG_Rect operator+(GG_Rect const&, GG_Rect const&);
    friend const GG_Rect operator+(GG_Rect const&, GG_Vec2f const&);
    friend const GG_Rect operator+(GG_Rect const&, const int);
    friend const GG_Rect operator+(GG_Rect const&, const float);

    friend const GG_Rect operator-(GG_Rect const&, GG_Rect const&);
    friend const GG_Rect operator-(GG_Rect const&, GG_Vec2f const&);
    friend const GG_Rect operator-(GG_Rect const&, const int);
    friend const GG_Rect operator-(GG_Rect const&, const float);

    friend const GG_Rect operator/(GG_Rect const&, GG_Rect const&);
    friend const GG_Rect operator/(GG_Rect const&, GG_Vec2f const&);
    friend const GG_Rect operator/(GG_Rect const&, const int);
    friend const GG_Rect operator/(GG_Rect const&, const float);

    friend const GG_Rect operator*(GG_Rect const&, GG_Rect const&);
    friend const GG_Rect operator*(GG_Rect const&, GG_Vec2f const&);
    friend const GG_Rect operator*(GG_Rect const&, const int);
    friend const GG_Rect operator*(GG_Rect const&, const float);

    float x;
    float y;
    float w;
    float h;
};

#endif // MATH_RECT_H_INCLUDED
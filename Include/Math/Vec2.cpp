#include "Vec2.h"

// Constructors
GG_Vec2f::GG_Vec2f()                             : x(0.0f), y(0.0f) {}
GG_Vec2f::GG_Vec2f(GG_Vec2f const& v)            : x(v.x),  y(v.y)  {}
GG_Vec2f::GG_Vec2f(GG_Rect const& r)             : x(r.x),  y(r.y)  {}
GG_Vec2f::GG_Vec2f(SDL_Rect const& r)            : x(r.x),  y(r.y)  {}
GG_Vec2f::GG_Vec2f(const int i)                  : x(i),    y(i)    {}
GG_Vec2f::GG_Vec2f(const float f)                : x(f),    y(f)    {}
GG_Vec2f::GG_Vec2f(const int x, const int y)     : x(x),    y(y)    {}
GG_Vec2f::GG_Vec2f(const float x, const float y) : x(x),    y(y)    {}

// Comparison operators
const bool GG_Vec2f::operator==(GG_Vec2f const& v) const
{
    return x == v.x && y == v.y;
}

const bool GG_Vec2f::operator!=(GG_Vec2f const& v) const
{
    return x != v.x || y != v.y;
}

// Unary operators
GG_Vec2f const& GG_Vec2f::operator=(GG_Vec2f const& v)
{
    x = v.x;
    y = v.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator=(SDL_Rect const& r)
{
    x = r.x;
    y = r.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator=(const int i)
{
    x = i;
    y = i;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator=(const float f)
{
    x = f;
    y = f;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator+=(GG_Vec2f const& v)
{
    x += v.x;
    y += v.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator+=(GG_Rect const& r)
{
    x += r.x;
    y += r.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator+=(SDL_Rect const& r)
{
    x += r.x;
    y += r.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator+=(const int i)
{
    x += i;
    y += i;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator+=(const float f)
{
    x += f;
    y += f;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator-=(GG_Vec2f const& v)
{
    x -= v.x;
    y -= v.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator-=(GG_Rect const& r)
{
    x -= r.x;
    y -= r.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator-=(SDL_Rect const& r)
{
    x -= r.x;
    y -= r.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator-=(const int i)
{
    x -= i;
    y -= i;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator-=(const float f)
{
    x -= f;
    y -= f;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator/=(GG_Vec2f const& v)
{
    x /= v.x;
    y /= v.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator/=(GG_Rect const& r)
{
    x /= r.x;
    y /= r.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator/=(SDL_Rect const& r)
{
    x /= r.x;
    y /= r.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator/=(const int i)
{
    x /= i;
    y /= i;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator/=(const float f)
{
    x /= f;
    y /= f;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator*=(GG_Vec2f const& v)
{
    x *= v.x;
    y *= v.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator*=(GG_Rect const& r)
{
    x *= r.x;
    y *= r.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator*=(SDL_Rect const& r)
{
    x *= r.x;
    y *= r.y;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator*=(const int i)
{
    x *= i;
    y *= i;

    return *this;
}

GG_Vec2f const& GG_Vec2f::operator*=(const float f)
{
    x *= f;
    y *= f;

    return *this;
}

// Binary operators
const GG_Vec2f operator+(GG_Vec2f const& v, GG_Vec2f const& v2)
{
    auto ret = v;
    ret += v2;

    return ret;
}

const GG_Vec2f operator+(GG_Vec2f const& v, GG_Rect const& r)
{
    auto ret = v;
    ret += r;

    return ret;
}

const GG_Vec2f operator+(GG_Vec2f const& v, SDL_Rect const& r)
{
    auto ret = v;
    ret += r;

    return ret;
}

const GG_Vec2f operator+(GG_Vec2f const& v, const int i)
{
    auto ret = v;
    ret += i;

    return ret;
}

const GG_Vec2f operator+(GG_Vec2f const& v, const float f)
{
    auto ret = v;
    ret += f;

    return ret;
}

const GG_Vec2f operator-(GG_Vec2f const& v, GG_Vec2f const& v2)
{
    auto ret = v;
    ret -= v2;

    return ret;
}

const GG_Vec2f operator-(GG_Vec2f const& v, GG_Rect const& r)
{
    auto ret = v;
    ret -= r;

    return ret;
}

const GG_Vec2f operator-(GG_Vec2f const& v, SDL_Rect const& r)
{
    auto ret = v;
    ret -= r;

    return ret;
}

const GG_Vec2f operator-(GG_Vec2f const& v, const int i)
{
    auto ret = v;
    ret -= i;

    return ret;
}

const GG_Vec2f operator-(GG_Vec2f const& v, const float f)
{
    auto ret = v;
    ret -= f;

    return ret;
}

const GG_Vec2f operator/(GG_Vec2f const& v, GG_Vec2f const& v2)
{
    auto ret = v;
    ret /= v2;

    return ret;
}

const GG_Vec2f operator/(GG_Vec2f const& v, GG_Rect const& r)
{
    auto ret = v;
    ret /= r;

    return ret;
}

const GG_Vec2f operator/(GG_Vec2f const& v, SDL_Rect const& r)
{
    auto ret = v;
    ret /= r;

    return ret;
}

const GG_Vec2f operator/(GG_Vec2f const& v, const int i)
{
    auto ret = v;
    ret /= i;

    return ret;
}

const GG_Vec2f operator/(GG_Vec2f const& v, const float f)
{
    auto ret = v;
    ret /= f;

    return ret;
}

const GG_Vec2f operator*(GG_Vec2f const& v, GG_Vec2f const& v2)
{
    auto ret = v;
    ret *= v2;

    return ret;
}

const GG_Vec2f operator*(GG_Vec2f const& v, GG_Rect const& r)
{
    auto ret = v;
    ret *= r;

    return ret;
}

const GG_Vec2f operator*(GG_Vec2f const& v, SDL_Rect const& r)
{
    auto ret = v;
    ret *= r;

    return ret;
}

const GG_Vec2f operator*(GG_Vec2f const& v, const int i)
{
    auto ret = v;
    ret *= i;

    return ret;
}

const GG_Vec2f operator*(GG_Vec2f const& v, const float f)
{
    auto ret = v;
    ret *= f;

    return ret;
}

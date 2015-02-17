#include "Vec2.h"

// Constructors
GG_Vec2f::GG_Vec2f()                             : x(0.0f), y(0.0f) {}
GG_Vec2f::GG_Vec2f(const GG_Vec2f& v)            : x(v.x),  y(v.y)  {}
GG_Vec2f::GG_Vec2f(const SDL_Rect& r)            : x(r.x),  y(r.y)  {}
GG_Vec2f::GG_Vec2f(const int i)                  : x(i),    y(i)    {}
GG_Vec2f::GG_Vec2f(const float f)                : x(f),    y(f)    {}
GG_Vec2f::GG_Vec2f(const int x, const int y)     : x(x),    y(y)    {}
GG_Vec2f::GG_Vec2f(const float x, const float y) : x(x),    y(y)    {}

// Comparison operators
const bool GG_Vec2f::operator==(const GG_Vec2f& v) const
{
    return x == v.x && y == v.y;
}

const bool GG_Vec2f::operator!=(const GG_Vec2f& v) const
{
    return x != v.x || y != v.y;
}

// Unary operators
const GG_Vec2f& GG_Vec2f::operator=(const GG_Vec2f& v)
{
    x = v.x;
    y = v.y;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator=(const SDL_Rect& r)
{
    x = r.x;
    y = r.y;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator=(const int i)
{
    x = i;
    y = i;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator=(const float f)
{
    x = f;
    y = f;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator+=(const GG_Vec2f& v)
{
    x += v.x;
    y += v.y;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator+=(const SDL_Rect& r)
{
    x += r.x;
    y += r.y;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator+=(const int i)
{
    x += i;
    y += i;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator+=(const float f)
{
    x += f;
    y += f;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator-=(const GG_Vec2f& v)
{
    x -= v.x;
    y -= v.y;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator-=(const SDL_Rect& r)
{
    x -= r.x;
    y -= r.y;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator-=(const int i)
{
    x -= i;
    y -= i;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator-=(const float f)
{
    x -= f;
    y -= f;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator/=(const GG_Vec2f& v)
{
    x /= v.x;
    y /= v.y;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator/=(const SDL_Rect& r)
{
    x /= r.x;
    y /= r.y;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator/=(const int i)
{
    x /= i;
    y /= i;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator/=(const float f)
{
    x /= f;
    y /= f;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator*=(const GG_Vec2f& v)
{
    x *= v.x;
    y *= v.y;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator*=(const SDL_Rect& r)
{
    x *= r.x;
    y *= r.y;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator*=(const int i)
{
    x *= i;
    y *= i;

    return *this;
}

const GG_Vec2f& GG_Vec2f::operator*=(const float f)
{
    x *= f;
    y *= f;

    return *this;
}

// Binary operators
const GG_Vec2f operator+(const GG_Vec2f& v1, const GG_Vec2f& v2)
{
    GG_Vec2f ret = v1;

    ret.x += v2.x;
    ret.y += v2.y;

    return ret;
}

const GG_Vec2f operator+(const GG_Vec2f& v, const SDL_Rect& r)
{
    GG_Vec2f ret = v;

    ret.x += r.x;
    ret.y += r.y;

    return ret;
}

const GG_Vec2f operator+(const GG_Vec2f& v, const int i)
{
    GG_Vec2f ret = v;

    ret.x += i;
    ret.y += i;

    return ret;
}

const GG_Vec2f operator+(const GG_Vec2f& v, const float f)
{
    GG_Vec2f ret = v;

    ret.x += f;
    ret.y += f;

    return ret;
}

const GG_Vec2f operator-(const GG_Vec2f& v1, const GG_Vec2f& v2)
{
    GG_Vec2f ret = v1;

    ret.x -= v2.x;
    ret.y -= v2.y;

    return ret;
}

const GG_Vec2f operator-(const GG_Vec2f& v, const SDL_Rect& r)
{
    GG_Vec2f ret = v;

    ret.x -= r.x;
    ret.y -= r.y;

    return ret;
}

const GG_Vec2f operator-(const GG_Vec2f& v, const int i)
{
    GG_Vec2f ret = v;

    ret.x -= i;
    ret.y -= i;

    return ret;
}

const GG_Vec2f operator-(const GG_Vec2f& v, const float f)
{
    GG_Vec2f ret = v;

    ret.x -= f;
    ret.y -= f;

    return ret;
}

const GG_Vec2f operator/(const GG_Vec2f& v1, const GG_Vec2f& v2)
{
    GG_Vec2f ret = v1;

    ret.x /= v2.x;
    ret.y /= v2.y;

    return ret;
}

const GG_Vec2f operator/(const GG_Vec2f& v, const SDL_Rect& r)
{
    GG_Vec2f ret = v;

    ret.x /= r.x;
    ret.y /= r.y;

    return ret;
}

const GG_Vec2f operator/(const GG_Vec2f& v, const int i)
{
    GG_Vec2f ret = v;

    ret.x /= i;
    ret.y /= i;

    return ret;
}

const GG_Vec2f operator/(const GG_Vec2f& v, const float f)
{
    GG_Vec2f ret = v;

    ret.x /= f;
    ret.y /= f;

    return ret;
}

const GG_Vec2f operator*(const GG_Vec2f& v1, const GG_Vec2f& v2)
{
    GG_Vec2f ret = v1;

    ret.x *= v2.x;
    ret.y *= v2.y;

    return ret;
}

const GG_Vec2f operator*(const GG_Vec2f& v, const SDL_Rect& r)
{
    GG_Vec2f ret = v;

    ret.x *= r.x;
    ret.y *= r.y;

    return ret;
}

const GG_Vec2f operator*(const GG_Vec2f& v, const int i)
{
    GG_Vec2f ret = v;

    ret.x *= i;
    ret.y *= i;

    return ret;
}

const GG_Vec2f operator*(const GG_Vec2f& v, const float f)
{
    GG_Vec2f ret = v;

    ret.x *= f;
    ret.y *= f;

    return ret;
}

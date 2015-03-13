#include "Rect.h"

// Constructors
GG_Rect::GG_Rect()                                                           : x(0.0f), y(0.0f), w(0.0f), h(0.0f) {}
GG_Rect::GG_Rect(GG_Rect const& r)                                           : x(r.x), y(r.y), w(r.w), h(r.h)     {}
GG_Rect::GG_Rect(const int i)                                                : x(i), y(i), w(i), h(i)             {}
GG_Rect::GG_Rect(const float f)                                              : x(f), y(f), w(f), h(f)             {}
GG_Rect::GG_Rect(const int x, const int y, const int w, const int h)         : x(x), y(y), w(w), h(h)             {}
GG_Rect::GG_Rect(const float x, const float y, const float w, const float h) : x(x), y(y), w(w), h(h)             {}

// Comparison operators
const bool GG_Rect::operator==(GG_Rect const& r) const
{
    return x == r.x && y == r.y && w == r.w && h == r.h;
}

const bool GG_Rect::operator!=(GG_Rect const& r) const
{
    return x != r.x || y != r.y || w != r.w || h != r.h;
}

// Unary operators
GG_Rect const& GG_Rect::operator=(GG_Rect const& r)
{
    x = r.x;
    y = r.y;
    w = r.w;
    h = r.h;

    return *this;
}

GG_Rect const& GG_Rect::operator=(GG_Vec2f const& v)
{
    x = v.x;
    y = v.y;

    return *this;
}

GG_Rect const& GG_Rect::operator=(const int i)
{
    x = i;
    y = i;
    w = i;
    h = i;

    return *this;
}

GG_Rect const& GG_Rect::operator=(const float f)
{
    x = f;
    y = f;
    w = f;
    h = f;

    return *this;
}

GG_Rect const& GG_Rect::operator+=(GG_Rect const& r)
{
    x += r.x;
    y += r.y;
    w += r.w;
    h += r.h;

    return *this;
}

GG_Rect const& GG_Rect::operator+=(GG_Vec2f const& v)
{
    x += v.x;
    y += v.y;

    return *this;
}

GG_Rect const& GG_Rect::operator+=(const int i)
{
    x += i;
    y += i;
    w += i;
    h += i;

    return *this;
}

GG_Rect const& GG_Rect::operator+=(const float f)
{
    x += f;
    y += f;
    w += f;
    h += f;

    return *this;
}

GG_Rect const& GG_Rect::operator-=(GG_Rect const& r)
{
    x -= r.x;
    y -= r.y;
    w -= r.w;
    h -= r.h;

    return *this;
}

GG_Rect const& GG_Rect::operator-=(GG_Vec2f const& v)
{
    x -= v.x;
    y -= v.y;

    return *this;
}

GG_Rect const& GG_Rect::operator-=(const int i)
{
    x -= i;
    y -= i;
    w -= i;
    h -= i;

    return *this;
}

GG_Rect const& GG_Rect::operator-=(const float f)
{
    x -= f;
    y -= f;
    w -= f;
    h -= f;

    return *this;
}

GG_Rect const& GG_Rect::operator/=(GG_Rect const& r)
{
    x /= r.x;
    y /= r.y;
    w /= r.w;
    h /= r.h;

    return *this;
}

GG_Rect const& GG_Rect::operator/=(GG_Vec2f const& v)
{
    x /= v.x;
    y /= v.y;

    return *this;
}

GG_Rect const& GG_Rect::operator/=(const int i)
{
    x /= i;
    y /= i;
    w /= i;
    h /= i;

    return *this;
}

GG_Rect const& GG_Rect::operator/=(const float f)
{
    x /= f;
    y /= f;
    w /= f;
    h /= f;

    return *this;
}

GG_Rect const& GG_Rect::operator*=(GG_Rect const& r)
{
    x *= r.x;
    y *= r.y;
    w *= r.w;
    h *= r.h;

    return *this;
}

GG_Rect const& GG_Rect::operator*=(GG_Vec2f const& v)
{
    x *= v.x;
    y *= v.y;

    return *this;
}

GG_Rect const& GG_Rect::operator*=(const int i)
{
    x *= i;
    y *= i;
    w *= i;
    h *= i;

    return *this;
}

GG_Rect const& GG_Rect::operator*=(const float f)
{
    x *= f;
    y *= f;
    w *= f;
    h *= f;

    return *this;
}

// Binary operators
const GG_Rect operator+(GG_Rect const& r, GG_Rect const& r2)
{
    auto ret = r;
    ret += r2;

    return ret;
}

const GG_Rect operator+(GG_Rect const& r, GG_Vec2f const& v)
{
    auto ret = r;
    ret += v;

    return ret;
}

const GG_Rect operator+(GG_Rect const& r, const int i)
{
    auto ret = r;
    ret += i;

    return ret;
}

const GG_Rect operator+(GG_Rect const& r, const float f)
{
    auto ret = r;
    ret += f;

    return ret;
}

const GG_Rect operator-(GG_Rect const& r, GG_Rect const& r2)
{
    auto ret = r;
    ret -= r2;

    return ret;
}

const GG_Rect operator-(GG_Rect const& r, GG_Vec2f const& v)
{
    auto ret = r;
    ret -= v;

    return ret;
}

const GG_Rect operator-(GG_Rect const& r, const int i)
{
    auto ret = r;
    ret -= i;

    return ret;
}

const GG_Rect operator-(GG_Rect const& r, const float f)
{
    auto ret = r;
    ret -= f;

    return ret;
}

const GG_Rect operator/(GG_Rect const& r, GG_Rect const& r2)
{
    auto ret = r;
    ret /= r2;

    return ret;
}

const GG_Rect operator/(GG_Rect const& r, GG_Vec2f const& v)
{
    auto ret = r;
    ret /= v;

    return ret;
}

const GG_Rect operator/(GG_Rect const& r, const int i)
{
    auto ret = r;
    ret /= i;

    return ret;
}

const GG_Rect operator/(GG_Rect const& r, const float f)
{
    auto ret = r;
    ret /= f;

    return ret;
}

const GG_Rect operator*(GG_Rect const& r, GG_Rect const& r2)
{
    auto ret = r;
    ret *= r2;

    return ret;
}

const GG_Rect operator*(GG_Rect const& r, GG_Vec2f const& v)
{
    auto ret = r;
    ret *= v;

    return ret;
}

const GG_Rect operator*(GG_Rect const& r, const int i)
{
    auto ret = r;
    ret *= i;

    return ret;
}

const GG_Rect operator*(GG_Rect const& r, const float f)
{
    auto ret = r;
    ret *= f;

    return ret;
}
#include "Vec2.h"

namespace GGMath
{
  // Constructors
  Vec2::Vec2()                             : x(0.0f), y(0.0f) {}
  Vec2::Vec2(const Vec2& v)                : x(v.x),  y(v.y)  {}
  Vec2::Vec2(const SDL_Rect& r)            : x(r.x),  y(r.y)  {}
  Vec2::Vec2(const int i)                  : x(i),    y(i)    {}
  Vec2::Vec2(const float f)                : x(f),    y(f)    {}
  Vec2::Vec2(const int x, const int y)     : x(x),    y(y)    {}
  Vec2::Vec2(const float x, const float y) : x(x),    y(y)    {}

  // Comparison operators
  const bool Vec2::operator==(const Vec2& v) const
  {
    return (x == v.x && y == v.y);
  }

  const bool Vec2::operator!=(const Vec2& v) const
  {
    return (x != v.x || y != v.y);
  }

  // Unary operators
  const Vec2& Vec2::operator=(const Vec2& v)
  {
    x = v.x;
    y = v.y;

    return (*this);
  }

  const Vec2& Vec2::operator=(const SDL_Rect& r)
  {
    x = r.x;
    y = r.y;

    return (*this);
  }

  const Vec2& Vec2::operator=(const int i)
  {
    x = i;
    y = i;

    return (*this);
  }

  const Vec2& Vec2::operator=(const float f)
  {
    x = f;
    y = f;

    return (*this);
  }

  const Vec2& Vec2::operator+=(const Vec2& v)
  {
    x += v.x;
    y += v.y;

    return (*this);
  }

  const Vec2& Vec2::operator+=(const SDL_Rect& r)
  {
    x += r.x;
    y += r.y;

    return (*this);
  }

  const Vec2& Vec2::operator+=(const int i)
  {
    x += i;
    y += i;

    return (*this);
  }

  const Vec2& Vec2::operator+=(const float f)
  {
    x += f;
    y += f;

    return (*this);
  }

  const Vec2& Vec2::operator-=(const Vec2& v)
  {
    x -= v.x;
    y -= v.y;

    return (*this);
  }

  const Vec2& Vec2::operator-=(const SDL_Rect& r)
  {
    x -= r.x;
    y -= r.y;

    return (*this);
  }

  const Vec2& Vec2::operator-=(const int i)
  {
    x -= i;
    y -= i;

    return (*this);
  }

  const Vec2& Vec2::operator-=(const float f)
  {
    x -= f;
    y -= f;

    return (*this);
  }

  const Vec2& Vec2::operator/=(const Vec2& v)
  {
    x /= v.x;
    y /= v.y;

    return (*this);
  }

  const Vec2& Vec2::operator/=(const SDL_Rect& r)
  {
    x /= r.x;
    y /= r.y;

    return (*this);
  }

  const Vec2& Vec2::operator/=(const int i)
  {
    x /= i;
    y /= i;

    return (*this);
  }

  const Vec2& Vec2::operator/=(const float f)
  {
    x /= f;
    y /= f;

    return (*this);
  }

  const Vec2& Vec2::operator*=(const Vec2& v)
  {
    x *= v.x;
    y *= v.y;

    return (*this);
  }

  const Vec2& Vec2::operator*=(const SDL_Rect& r)
  {
    x *= r.x;
    y *= r.y;

    return (*this);
  }

  const Vec2& Vec2::operator*=(const int i)
  {
    x *= i;
    y *= i;

    return (*this);
  }

  const Vec2& Vec2::operator*=(const float f)
  {
    x *= f;
    y *= f;

    return (*this);
  }

  // Binary operators
  const Vec2 operator+(const Vec2& v1, const Vec2& v2)
  {
    Vec2 ret = v1;

    ret.x += v2.x;
    ret.y += v2.y;

    return ret;
  }

  const Vec2 operator+(const Vec2& v, const SDL_Rect& r)
  {
    Vec2 ret = v;

    ret.x += r.x;
    ret.y += r.y;

    return ret;
  }

  const Vec2 operator+(const Vec2& v, const int i)
  {
    Vec2 ret = v;

    ret.x += i;
    ret.y += i;

    return ret;
  }

  const Vec2 operator+(const Vec2& v, const float f)
  {
    Vec2 ret = v;

    ret.x += f;
    ret.y += f;

    return ret;
  }

  const Vec2 operator-(const Vec2& v1, const Vec2& v2)
  {
    Vec2 ret = v1;

    ret.x -= v2.x;
    ret.y -= v2.y;

    return ret;
  }

  const Vec2 operator-(const Vec2& v, const SDL_Rect& r)
  {
    Vec2 ret = v;

    ret.x -= r.x;
    ret.y -= r.y;

    return ret;
  }

  const Vec2 operator-(const Vec2& v, const int i)
  {
    Vec2 ret = v;

    ret.x -= i;
    ret.y -= i;

    return ret;
  }

  const Vec2 operator-(const Vec2& v, const float f)
  {
    Vec2 ret = v;

    ret.x -= f;
    ret.y -= f;

    return ret;
  }

  const Vec2 operator/(const Vec2& v1, const Vec2& v2)
  {
    Vec2 ret = v1;

    ret.x /= v2.x;
    ret.y /= v2.y;

    return ret;
  }

  const Vec2 operator/(const Vec2& v, const SDL_Rect& r)
  {
    Vec2 ret = v;

    ret.x /= r.x;
    ret.y /= r.y;

    return ret;
  }

  const Vec2 operator/(const Vec2& v, const int i)
  {
    Vec2 ret = v;

    ret.x /= i;
    ret.y /= i;

    return ret;
  }

  const Vec2 operator/(const Vec2& v, const float f)
  {
    Vec2 ret = v;

    ret.x /= f;
    ret.y /= f;

    return ret;
  }

  const Vec2 operator*(const Vec2& v1, const Vec2& v2)
  {
    Vec2 ret = v1;

    ret.x *= v2.x;
    ret.y *= v2.y;

    return ret;
  }

  const Vec2 operator*(const Vec2& v, const SDL_Rect& r)
  {
    Vec2 ret = v;

    ret.x *= r.x;
    ret.y *= r.y;

    return ret;
  }

  const Vec2 operator*(const Vec2& v, const int i)
  {
    Vec2 ret = v;

    ret.x *= i;
    ret.y *= i;

    return ret;
  }

  const Vec2 operator*(const Vec2& v, const float f)
  {
    Vec2 ret = v;

    ret.x *= f;
    ret.y *= f;

    return ret;
  }
}

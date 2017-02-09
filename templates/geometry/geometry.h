#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <cmath>
#include <limits>
#include <istream>
#include <ostream>

namespace Geometry {
// private members
  template<typename T = long double>
  class _Vector2D {
  public:
    T x, y;
    _Vector2D(T x=0, T y=0): x(x), y(y) {}

    _Vector2D& operator+() { return *this; }
    _Vector2D operator-() { return _Vector2D(-x, -y); }

    _Vector2D& operator=(const _Vector2D& v) { x=v.x; y=v.y; return *this; }
    _Vector2D& operator+=(const _Vector2D& v) { x+=v.x; y+=v.y; return *this; }
    _Vector2D& operator-=(const _Vector2D& v) { x-=v.x; y-=v.y; return *this; }
    _Vector2D& operator*=(T t) { x*=t; y*=t; return *this; }
    _Vector2D& operator/=(T t) { x/=t; y/=t; return *this; }

    _Vector2D<T>& rotate(T ang) {
      T _x = x;
      T _y = y;
      x = _x * cos(ang) - _y * sin(ang);
      y = _x * sin(ang) + _y * cos(ang);
      return *this;
    }
  };

  template<typename T = long double>
  class _Point2D : public _Vector2D<T> {
  public:
    _Point2D(T x=0, T y=0): _Vector2D<T>(x, y) {}
  };

  template<typename T = long double>
  class _Line2D {
  private:
    _Point2D<T> base;
    // direction vector
    // TODO: unit vector ?
    _Vector2D<T> dir;
  public:
    // default: horizontal line passing through origin
    _Line2D(const _Point2D<T>& base = _Point2D<T>(0, 0),
            const _Vector2D<T>& dir = _Vector2D<T>(1, 0)): base(base), dir(dir) {}

    // define by two points
    _Line2D(const _Point2D<T>& base,
            const _Point2D<T>& end): base(base), dir(end-base) {}

    template<typename T_>
    friend size_t count_inter(const _Line2D<T_>&, const _Line2D<T_>&);

    template<typename T_>
    friend _Point2D<T_> get_inter(_Line2D<T_>, const _Line2D<T_>&);
  };

  template<typename T = long double>
  class _Segment2D {
  public:
    _Point2D<T> base, end;
    _Segment2D(const _Point2D<T>& base = _Point2D<T>(0, 0),
               const _Point2D<T>& end = _Point2D<T>()): base(base), end(end) {}
  };

  template<typename T = long double>
  class _Polygon2D {
  private:
    _Point2D<T>* __points;
    size_t __size;
  public:
    _Polygon2D(size_t size=0) {
      __points = new _Point2D<T>[size];
      __size = size;
    }

    _Point2D<T>& operator[](size_t i) { return __points[i]; }
    size_t size() const { return __size; }

    T area() const {
      T res = 0;
      for (size_t i=0; i<__size; i++)
        res += cross(__points[i], __points[(i+1)%__size]);
      return res/2;
    }
  };

// public members
  const long double EPS = 1e-10;
  const long double INF = std::numeric_limits<long double>::infinity();
  const size_t UNCOUNTABLE = std::numeric_limits<size_t>::max();
  const _Point2D<long double> NO_POINT(INF, INF);

  typedef _Vector2D<long double> Vector;
  typedef _Point2D<long double> Point;
  typedef _Line2D<long double> Line;
  typedef _Segment2D<long double> Segment;
  typedef _Polygon2D<long double> Polygon;

// functions
  template<typename T>
  int sgn(T x) {
    if (x > EPS)
      return 1;
    else if (x < -EPS)
      return -1;
    else
      return 0;
  }

  // _Vector2D
    template<typename T>
    _Vector2D<T>
    operator+(_Vector2D<T> u, const _Vector2D<T>& v) { u+=v; return u; }

    template<typename T>
    _Vector2D<T>
    operator-(_Vector2D<T> u, const _Vector2D<T>& v) { u-=v; return u; }

    template<typename T>
    _Vector2D<T>
    operator*(_Vector2D<T> v, T t) { v*=t; return v; }

    template<typename T>
    _Vector2D<T>
    operator*(T t, _Vector2D<T> v) { v*=t; return v; }

    template<typename T>
    _Vector2D<T>
    operator/(_Vector2D<T> v, T t) { v/=t; return v; }

    template<typename T>
    std::ostream&
    operator<<(std::ostream& os,
               const _Vector2D<T>& v) {
      os << '(' << v.x << ',' << v.y << ')';
      return os;
    }

    template<typename T>
    inline bool
    operator==(const _Vector2D<T>& u, const _Vector2D<T>& v) {
      return sgn(u.x-v.x) == 0
          && sgn(u.y-v.y) == 0;
    }

    template<typename T>
    inline bool
    operator!=(const _Vector2D<T>& u, const _Vector2D<T>& v) {
      return !(u == v);
    }


    template<typename T>
    T abs(const _Vector2D<T>& v) {
      return std::sqrt(v.x*v.x + v.y*v.y);
    }

    template<typename T>
    T arg(const _Vector2D<T>& v) {
      return std::atan2(v.y, v.x);
    }

    template<typename T>
    T dot(const _Vector2D<T>& u, const _Vector2D<T>& v) {
      return u.x*v.x + u.y*v.y;
    }

    template<typename T>
    T cross(const _Vector2D<T>& u, const _Vector2D<T>& v) {
      return u.x*v.y - u.y*v.x;
    }

    template<typename T>
    _Vector2D<T> rotate(_Vector2D<T> v, T ang) {
      v.rotate(ang);
      return v;
    }

    template<typename T>
    _Vector2D<T> project(const _Vector2D<T>& u, _Vector2D<T> v) {
      // u onto v
      v *= dot(u, v) / (v.x*v.x + v.y*v.y);
      return v;
    }
  // end _Vector2D

  // _Point2D
    template<typename T>
    _Point2D<T> rotate(_Point2D<T> p, const _Point2D<T>& origin, T ang) {
      p -= origin;
      p.rotate(ang);
      p += origin;
      return p;
    }
  // end _Point2D

  // _Line2D
    template<typename T>
    size_t count_inter(const _Line2D<T>& l, const _Line2D<T>& m) {
      if (sgn(cross(l.dir, m.dir)) == 0) {
        if (sgn(cross(l.dir, m.base-l.base)) == 0)
          return UNCOUNTABLE; // coincidence
        else
          return 0; // parallel
      } else {
        return 1;
      }
    }

    template<typename T>
    _Point2D<T> get_inter(_Line2D<T> l, const _Line2D<T>& m) {
      l.dir *= cross(m.base-l.base, m.dir) / cross(l.dir, m.dir);
      l.base += l.dir;
      if (count_inter(l, m) == 1)
        return l.base;
      else
        return NO_POINT;
    }
  // end _Line2D

  // _Segment2D
    // template<typename T>
    // bool _point_on_collinear_seg(const _Point2D<T>& p, const _Segment2D<T>& s) {
    //   return sgn(p.x - s.base.x) * sgn(p.x - s.end.x) <= 0
    //       && sgn(p.y - s.base.y) * sgn(p.y - s.end.y) <= 0;
    // }

    template<typename T>
    bool point_on_seg(const _Point2D<T>& p, const _Segment2D<T>& s) {
      return sgn(cross(s.base-p, s.end-p)) == 0
          && sgn(dot(s.base-p, s.end-p)) <= 0;
    }

    template<typename T>
    bool _collinear_seg_inter(const _Segment2D<T>& s, const _Segment2D<T>& t) {
      return point_on_seg(t.base, s)
          || point_on_seg(t.end, s)
          || point_on_seg(s.base, t)
          || point_on_seg(s.end, t);
    }

    template<typename T>
    size_t count_inter(const _Segment2D<T>& s, const _Segment2D<T>& t) {
      T c1 = cross(s.end-s.base, t.base-s.base);
      T c2 = cross(s.end-s.base, t.end-s.base);
      T c3 = cross(t.end-t.base, s.base-t.base);
      T c4 = cross(t.end-t.base, s.end-t.base);
      if ((sgn(c1) == 0 && sgn(c2) == 0 && _collinear_seg_inter(s, t))
       || (sgn(c3) == 0 && sgn(c4) == 0 && _collinear_seg_inter(s, t)))
        return UNCOUNTABLE;
      else if ((sgn(c1) * sgn(c2) < 0 && sgn(c3) * sgn(c4) < 0) // cross
            || (sgn(c1) == 0 && point_on_seg(t.base, s))
            || (sgn(c2) == 0 && point_on_seg(t.end, s))
            || (sgn(c3) == 0 && point_on_seg(s.base, t))
            || (sgn(c4) == 0 && point_on_seg(s.end, t)))
        return 1;
      else
        return 0;
    }

    template<typename T>
    _Point2D<T> get_inter(const _Segment2D<T>& s, const _Segment2D<T>& t) {
      _Line2D<T> l(s.base, s.end-s.base);
      _Line2D<T> m(t.base, t.end-t.base);
      if (count_inter(s, t) == 1)
        return get_inter(l, m);
      else
        return NO_POINT;
    }
  // end _Segment2D

  // _Polygon2D
    template<typename T>
    _Polygon2D<T> rotate(_Polygon2D<T> pg, const _Point2D<T>& origin, T ang) {
      for (size_t i=0; i<pg.size(); i++)
        pg[i] = rotate(pg[i], origin, ang);
      return pg;
    }

    template<typename T>
    bool inside(const _Point2D<T>& p, const _Polygon2D<T>& pg) {
      size_t n = pg.size();
      int wn = 0;
      for (int i=0; i<n; i++) {
        const _Point2D<T>& s1 = pg[i];
        const _Point2D<T>& s2 = pg[(i+1)%n];
        if (point_on_seg(p, _Segment2D<T>(s1, s2)))
          return -1; // on side
        int k = cross(s2-s1 , p-s1);
        int d1 = s1.y - p.y;
        int d2 = s2.y - p.y;
        if (k > 0 && d1 <= 0 && d2 > 0)
          wn++; // 逆時針穿過，繞數+1
        if (k < 0 && d1 > 0 && d2 <= 0)
          wn--; // 順時針穿過，繞數-1
      }
      return wn != 0;
    }

    // template<typename T>
    // _Polygon2D<T> scale(_Polygon2D<T> pg, const _Point2D<T>& origin, T t) {}
  // end _Polygon2D
};

#endif // GEOMETRY_H

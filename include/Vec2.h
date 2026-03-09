#pragma once
#include <ostream>

struct Vec2 { 
    double x; 
    double y; 

    Vec2 operator+(const Vec2& other) const{
        return {x + other.x, y + other.y};
    }

    Vec2 operator-(const Vec2& other) const{
        return {x - other.x, y - other.y};
    }

    Vec2 operator*(double scalar) const{
        return {x * scalar, y * scalar};
    }

    Vec2 operator/(double scalar) const{
        return {x / scalar, y / scalar};
    }

    Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
};

inline double length_sq(const Vec2& v) {
    return v.x * v.x + v.y * v.y;
}

inline Vec2 operator*(double s, const Vec2& v) {
    return {s * v.x , s * v.y};
}

inline std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}


#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>


class Vector {
public:
    float x, y;

    // Constructors
    Vector(float x, float y) : x(x), y(y) {}
    Vector() : x(0.0f), y(0.0f) {}

    // Instance methods
    std::string toString() const {
        std::ostringstream ss;
        ss << "<" << std::fixed << std::setprecision(6) << x << ", " 
           << std::fixed << std::setprecision(6) << y << ">";
        return ss.str();
    }
    
    Vector copy() const {
        return Vector(x, y);
    }
    
    bool equals(const Vector& other) const {
        return x == other.x && y == other.y;
    }
    
    void add(const Vector& b) {
        x += b.x;
        y += b.y;
    }
    
    void sub(const Vector& b) {
        x -= b.x;
        y -= b.y;
    }
    
    void mult(float scalar) {
        x *= scalar;
        y *= scalar;
    }
    
    float magSquared() const {
        return x * x + y * y;
    }
    
    float mag() const {
        return std::sqrt(magSquared());
    }
    
    void normalize() {
        float m = mag();
        if (m > 0) {
            mult(1.0f / m);
        }
    }

    // Static methods
    static Vector add(const Vector& a, const Vector& b) {
        return Vector(a.x + b.x, a.y + b.y);
    }
    
    static Vector sub(const Vector& a, const Vector& b) {
        return Vector(a.x - b.x, a.y - b.y);
    }
    
    static Vector mult(const Vector& a, float scalar) {
        return Vector(a.x * scalar, a.y * scalar);
    }
    
    static float dot(const Vector& a, const Vector& b) {
        return a.x * b.x + a.y * b.y;
    }
};
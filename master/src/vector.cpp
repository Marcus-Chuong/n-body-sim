#include "vector.h"
#include <cmath>
#include <sstream>
#include <iomanip>

// Constructors
Vector::Vector(float x, float y) : x(x), y(y) {}
Vector::Vector() : x(0.0f), y(0.0f) {}

// Instance methods
std::string Vector::toString() const {
    std::ostringstream ss;
    ss << "<" << std::fixed << std::setprecision(6) << x << ", "
       << std::fixed << std::setprecision(6) << y << ">";
    return ss.str();
}

Vector Vector::copy() const {
    return Vector(x, y);
}

bool Vector::equals(const Vector& other) const {
    return x == other.x && y == other.y;
}

void Vector::add(const Vector& b) {
    x += b.x;
    y += b.y;
}

void Vector::sub(const Vector& b) {
    x -= b.x;
    y -= b.y;
}

void Vector::mult(float scalar) {
    x *= scalar;
    y *= scalar;
}

float Vector::magSquared() const {
    return x * x + y * y;
}

float Vector::mag() const {
    return std::sqrt(magSquared());
}

void Vector::normalize() {
    float m = mag();
    if (m > 0) {
        mult(1.0f / m);
    }
}

// Static methods
Vector Vector::add(const Vector& a, const Vector& b) {
    return Vector(a.x + b.x, a.y + b.y);
}

Vector Vector::sub(const Vector& a, const Vector& b) {
    return Vector(a.x - b.x, a.y - b.y);
}

Vector Vector::mult(const Vector& a, float scalar) {
    return Vector(a.x * scalar, a.y * scalar);
}

float Vector::dot(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y;
}

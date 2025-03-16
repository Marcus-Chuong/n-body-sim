#pragma once
#include <string>

class Vector {
public:
    float x, y;

    // Constructors
    Vector(float x, float y);
    Vector();

    // Instance methods
    std::string toString() const;
    Vector copy() const;
    bool equals(const Vector& other) const;
    void add(const Vector& b);
    void sub(const Vector& b);
    void mult(float scalar);
    float magSquared() const;
    float mag() const;
    void normalize();

    // Static methods
    static Vector add(const Vector& a, const Vector& b);
    static Vector sub(const Vector& a, const Vector& b);
    static Vector mult(const Vector& a, float scalar);
    static float dot(const Vector& a, const Vector& b);
    float dist(const Vector& other) const;
};
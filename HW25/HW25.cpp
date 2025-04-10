#include <iostream>
#include <cmath>

class Vector2d {
private:
    float x, y;
    static int instanceCount;

public:
    Vector2d(float x = 0.0f, float y = 0.0f) : x(x), y(y) { instanceCount++; }
    Vector2d(float x0, float y0, float x1, float y1) : x(x1 - x0), y(y1 - y0) { instanceCount++; }
    Vector2d(const Vector2d& other) : x(other.x), y(other.y) { instanceCount++; }
    Vector2d& operator=(const Vector2d& other)
    {
        if (this != &other)
        {
            x = other.x;
            y = other.y;
        }
        return *this;
    }
    ~Vector2d() { instanceCount--; }
    Vector2d operator+(const Vector2d& secondVector) const { return Vector2d(x + secondVector.x, y + secondVector.y); }
    Vector2d operator-(const Vector2d& secondVector) const { return Vector2d(x - secondVector.x, y - secondVector.y); }
    float& operator[](std::size_t idx)
    {
        if (idx == 0) return x;
        if (idx == 1) return y;
        throw std::out_of_range("Index out of range");
    }

    void print() const { std::cout << "{" << x << "; " << y << "}" << std::endl; }

    static int getInstanceCount() { return instanceCount; }
    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vec);

    float dotProduct(const Vector2d& other) const {
        return x * other.x + y * other.y;
    }

    Vector2d negate() const {
        return Vector2d(-x, -y);
    }

    enum class VectorRelativeState {
        Identical, coDirected, OppositeDirected, AcuteAngle, ObtuseAngle, RightAngle
    };

    VectorRelativeState getRelativeState(const Vector2d& other) const {
        float dot = dotProduct(other);
        float magThis = std::sqrt(x * x + y * y);
        float magOther = std::sqrt(other.x * other.x + other.y * other.y);

        if (x == other.x && y == other.y) {
            return VectorRelativeState::Identical;
        }
        else if (dot == magThis * magOther) {
            return VectorRelativeState::coDirected;
        }
        else if (dot == -magThis * magOther) {
            return VectorRelativeState::OppositeDirected;
        }
        else if (dot == 0) {
            return VectorRelativeState::RightAngle;
        }
        else if (dot > 0) {
            return VectorRelativeState::AcuteAngle;
        }
        else {
            return VectorRelativeState::ObtuseAngle;
        }
    }

    void scale(float factorX, float factorY) {
        x *= factorX;
        y *= factorY;
    }
};

int Vector2d::instanceCount = 0;

std::ostream& operator<<(std::ostream& os, const Vector2d& vec)
{
    os << "{" << vec.x << "; " << vec.y << "}";
    return os;
}

int main() {
    Vector2d vec1{ 1.2f, 5.6f };
    Vector2d vec2{ 3.4f, 7.8f };

    std::cout << "vec1: " << vec1 << std::endl;
    std::cout << "vec2: " << vec2 << std::endl;

    Vector2d vec3 = vec1 + vec2;
    std::cout << "vec1 + vec2: " << vec3 << std::endl;

    Vector2d vec4 = vec1 - vec2;
    std::cout << "vec1 - vec2: " << vec4 << std::endl;

    std::cout << "vec1[0]: " << vec1[0] << ", vec1[1]: " << vec1[1] << std::endl;

    std::cout << "Active instances: " << Vector2d::getInstanceCount() << std::endl;

    Vector2d vec5{ 0.0f, 0.0f, 1.0f, 1.0f };
    std::cout << "vec5: " << vec5 << std::endl;

    float dot = vec1.dotProduct(vec2);
    std::cout << "Dot product of vec1 and vec2: " << dot << std::endl;

    Vector2d negatedVec1 = vec1.negate();
    std::cout << "Negated vec1: " << negatedVec1 << std::endl;

    Vector2d::VectorRelativeState state = vec1.getRelativeState(vec2);
    std::cout << "Relative state of vec1 and vec2: " << static_cast<int>(state) << std::endl;

    vec1.scale(2.0f, 3.0f);
    std::cout << "Scaled vec1: " << vec1 << std::endl;

    return 0;
}
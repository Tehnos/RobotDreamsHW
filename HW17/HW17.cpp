#include <iostream>

class Vector2d {
private:
    float x, y;
    static int instanceCount; 

public:
    Vector2d(float x = 0.0f, float y = 0.0f) : x(x), y(y) {instanceCount++;}
    Vector2d(const Vector2d& other) : x(other.x), y(other.y) {instanceCount++;}
    Vector2d& operator=(const Vector2d& other) 
    {
        if (this != &other)
        {
            x = other.x;
            y = other.y;
        }
        return *this;
    }
    ~Vector2d() {instanceCount--;}
    Vector2d operator+(const Vector2d& secondVector) const {return Vector2d(x + secondVector.x, y + secondVector.y);}
    Vector2d operator-(const Vector2d& secondVector) const { return Vector2d(x - secondVector.x, y - secondVector.y);}
    float& operator[](std::size_t idx) 
    {
        if (idx == 0) return x;
        if (idx == 1) return y;
    }

    void print() const {std::cout << "{" << x << "; " << y << "}" << std::endl;}

    static int getInstanceCount() {return instanceCount;}
    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vec);
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

    return 0;
}
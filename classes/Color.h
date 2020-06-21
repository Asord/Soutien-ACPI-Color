#ifndef COLOR_SLP_COLOR_H
#define COLOR_SLP_COLOR_H

#include <cstdint>
#include <vector>
#include <iostream>

struct coefficients {
    float rg=0.0f; float rb=0.0f; float gr=0.0f; float gb=0.0f; float br=0.0f; float bg=0.0f;
};

class Color
{
public:
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Yellow;
    static const Color Cyan;
    static const Color Magenta;
    static const Color White;
    static const Color Black;

protected:
    union {
        struct { uint8_t  _alpha, _blue, _green, _red;};
        uint32_t _color;
    };

public:
    Color();
    Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
    Color(uint8_t red, uint8_t green, uint8_t blue);
    Color(uint32_t color);

    uint8_t getRed() const;
    void setRed(uint8_t red);

    uint8_t getGreen() const;
    void setGreen(uint8_t green);

    uint8_t getBlue() const;
    void setBlue(uint8_t blue);

    uint8_t getAlpha() const;
    void setAlpha(uint8_t alpha);

    uint32_t getColor() const;
    void setColor(uint32_t color);

    Color& fromHue(float hue);
    Color& fromHSV(float hue, float saturation, float value);

    void toHSV(float* hsv) const;

    Color& random(int seed=0);
    Color& randomColor(float min=0.0f, float max=360.0f, int seed=0);

    Color& black();
    Color& white();
    Color& gray(uint8_t factor);
    void   normalize(float& nr, float& ng, float& nb);
    void   setNormals(const float& nr, const float& ng, const float& nb);
    void   enhance(coefficients& c);

    Color& invert();
    Color& grayscale();

    Color& coef(float coefr, float coefg, float coefb);

    Color& operator++();
    Color& operator--();

    Color operator+(const Color& rhs) const;
    Color& operator+=(const Color& rhs);

    Color operator-(const Color& rhs) const;
    Color& operator-=(const Color& rhs);

    Color operator*(const float& rhs) const;
    Color& operator*=(const float& rhs);

    Color operator/(const float& rhs) const;
    Color& operator/=(const float& rhs);

    Color operator%(const unsigned char& rhs) const;
    Color& operator%=(const unsigned char& rhs);

    bool operator==(const Color &rhs) const;
    bool operator!=(const Color &rhs) const;

    friend std::ostream& operator<<(std::ostream& os, Color& c);


};

typedef std::vector<Color> colorVector;

#endif //COLOR_SLP_COLOR_H

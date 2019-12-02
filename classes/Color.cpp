#include "Color.h"
#include "../tools/AsMath.h"
#include <stdexcept>


/* TODO 4 b: Définir les couleurs préfaites de notre classe Color
 * Les couleurs qui doivent être définies sont:
 * Les 3 couleurs primaires (Rouge, Vert, Bleu)
 * Les 3 couleurs secondaires (Jaune, Cyan, Magenta)
 * Le Blanc et le Noir.
 */

// TODO 15: écrire les définitions des constructeurs

// TODO 16: écrire les définitions des acesseurs (getter/setter)

Color &Color::fromHue(float hue) {
    /**
     * \brief Modifie la couleur selon une teinte
     *
     * \arg hue la teinte de la couleur en degrée de 0.0f à 360.0°f
     * \return Une référence de l'objet courant coloré selon la teinte
     */
    float h60 = hue / 60.0f;
    uint8_t h60f = (uint8_t)h60;

    float f = h60 - h60f;

    switch (h60f)
    {
        case 0:
            this->_color = 0xff0000ff | (uint32_t)(f * 255) << 8;
            break;
        case 1:
            this->_color = 0xff00ff00 | (255 - (uint32_t)(f * 255));
            break;
        case 2:
            this->_color = 0xff00ff00 | (uint32_t)(f * 255) << 16;
            break;
        case 3:
            this->_color = 0xffff0000 | (255 - (uint32_t)(f * 255)) << 8;
            break;
        case 4:
            this->_color = 0xffff0000 | (uint32_t)(f * 255);
            break;
        case 5:
            this->_color = 0xff0000ff | (255 - (uint32_t)(f * 255)) << 16;
            break;
        default:
            break;
    }

    return *this;
}

Color &Color::fromHSV(float h, float s, float v) {
    /**
     * \brief Modifie la couleur selon des données HSV
     *
     * \arg hue la teinte de la couleur noté en dégrée de 0.0f à 360.0f
     * \arg saturation la saturation de la coueleur noté de 0.0f (blanc) à 1.0f (coloré)
     * \arg value la valeur de la couleur (aussi dit son intensité) noté de 0.0f (noir) à 1.0f (coloré)
     * \return une référence de l'objet actuel coloré selon les valeurs HSV
     */
    float h60 = h / 60.0f;
    uint32_t h60f = (uint32_t)h60;

    float f = h60 - h60f;

    float p = v * (1.0f - s);
    float q = v * (1.0f - f * s);
    float t = v * (1.0f - (1.0f - f) * s);

    switch (h60f)
    {
        case 0:
            this->_color = 0xff000000
                           | (uint8_t)(v * 255)
                           | (uint8_t)(t * 255) << 8
                           | (uint8_t)(p * 255) << 16;
            break;
        case 1:
            this->_color = 0xff000000
                           | (uint8_t)(q * 255)
                           | (uint8_t)(v * 255) << 8
                           | (uint8_t)(p * 255) << 16;
            break;
        case 2:
            this->_color = 0xff000000
                           | (uint8_t)(p * 255)
                           | (uint8_t)(v * 255) << 8
                           | (uint8_t)(t * 255) << 16;
            break;
        case 3:
            this->_color = 0xff000000
                           | (uint8_t)(p * 255)
                           | (uint8_t)(q * 255) << 8
                           | (uint8_t)(v * 255) << 16;
            break;
        case 4:
            this->_color = 0xff000000
                           | (uint8_t)(t * 255)
                           | (uint8_t)(p * 255) << 8
                           | (uint8_t)(v * 255) << 16;
            break;
        case 5:
            this->_color = 0xff000000
                           | (uint8_t)(v * 255)
                           | (uint8_t)(p * 255) << 8
                           | (uint8_t)(q * 255) << 16;
            break;
        default: break;
    }
    return *this;
}

void Color::toHSV(float& hue, float& saturation, float& value) const {
    /**
     * \brief Transforme la couleur actuelle en ces valeurs HSV
     *
     * \arg hue référence de la teinte de la couleur noté en dégrée de 0.0f à 360.0f
     * \arg saturation référence de la saturation de la coueleur noté de 0.0f (blanc) à 1.0f (coloré)
     * \arg value référence de la valeur de la couleur (aussi dit son intensité) noté de 0.0f (noir) à 1.0f (coloré)
     */

    float r = (float)this->_red / 255.0f;
    float g = (float)this->_green / 255.0f;
    float b = (float)this->_blue / 255.0f;

    float mx = Asemco::f3max(r, g, b);
    float mn = Asemco::f3min(r, g, b);

    float df = mx - mn;

    float _t;

    if (mx == mn) hue = 0;

    else if (mx == r)
    {
        _t = 60.0f * ((g - b) / df) + 360.0f;
        hue = (float)Asemco::ufmodf(_t, 360.0f);
    }
    else if (mx == g)
    {
        _t = 60.0f * ((b - r) / df) + 120.0f;
        hue = (float)Asemco::ufmodf(_t, 360.0f);
    }
    else if (mx == b)
    {
        _t = 60.0f * ((r - g) / df) + 240.0f;
        hue = (float)Asemco::ufmodf(_t, 360.0f);
    }

    if ((uint32_t)mx == 0) saturation = 0.0f;
    else saturation = df / mx;

    value = mx;
}

// TODO 17: écrire les définitions des méthodes "autres"

// TODO 18: écrire les définitions des operateurs

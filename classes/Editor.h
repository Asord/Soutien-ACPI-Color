#pragma once
#include "Color.h"
#include <vector>

// définie un type vect2Df comme un vecteur2D de float
typedef std::vector<std::vector<float>> vect2Df;

class Kernel
{
    /**
     * \brief Dans le domaine du traitement d'image, un kernel est un tableau carré de valeurs que l'on applique
     * à chaque pixel 1 à 1 selon les valeurs de ses pixels voisin. Pour plus d'informations:
     * https://fr.wikipedia.org/wiki/Noyau_(traitement_d%27image)
     *
     * \var mat un tableau2D de float représentant le kernel
     * \var matHeight la hauteur du kernel
     * \var matWidth la largeur du kernel
     * \var heightShift l'indice indiquant le centre du kernel selon sa hauteur
     * \var widthShift l'indice indiquant le centre du kernel selon sa largeur
     * \var matDiv le diviseur de du kernel(voire la page wikipedia)
     */
private:
    vect2Df mat;
    unsigned int matHeight, matWidth;
    unsigned int heightShift, widthShift;
    int matDiv;

protected:
    void ApplyKernelToPixel(const colorVector &input, colorVector &output, unsigned x, unsigned y);
public:
    Kernel(const vect2Df &vect);
    void ApplyKernelToImage(const colorVector &input, colorVector &output, unsigned width, unsigned height);
};

void blendLayersUsingAlpha(colorVector& background, colorVector& foreground, colorVector& output);

void convertToGrayscale(colorVector& image);


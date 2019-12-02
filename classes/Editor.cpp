#include "Editor.h"
#include "../tools/AsMath.h"

Kernel::Kernel(const vect2Df &vect)
{
    /**
     * \brief crée un kernel à partir d'un vecteur2D de float
     *
     * \arg vect un vecteur2D de float
     */
    this->mat = vect;
    this->matHeight = this->mat.size();
    this->matWidth = this->mat[0].size();

    this->heightShift = (this->matHeight - 1) / 2;
    this->widthShift = (this->matWidth - 1) / 2;

    this->matDiv = 0;
    for (auto h: this->mat)
        for (auto w: h)
            this->matDiv += w;

    if (this->matDiv == 0)
        this->matDiv = 1;
}


void Kernel::ApplyKernelToPixel(const colorVector &input, colorVector &output, unsigned x, unsigned y){
    /**
     * \brief Applique le kernel à un pixel de coordonnée x,y
     *
     * \arg input un vecteur de couleurs représentant une image d'entrée
     * \arg output un vecteur de couleur représentant une image de sortie
     * \arg x la coordonnée x dans l'image ou appliquer le kernel
     * \arg y la coordonnée y dans l'image ou appliquer le kernel
     */
    float sum[3] = {0, 0, 0};
    unsigned char* rgb;

    for (char k = 0; k < this->matHeight; ++k)
        for (char j = 0; j < this->matWidth; ++j) {
            rgb = (unsigned char *) &input[(y - j - this->heightShift + x - k - this->widthShift)];

       sum[0] += this->mat[j][k] * rgb[0];
       sum[1] += this->mat[j][k] * rgb[1];
       sum[2] += this->mat[j][k] * rgb[2];
    }

    output[y + x].setRed(   Asemco::floatToChar(sum[0] / this->matDiv));
    output[y + x].setGreen( Asemco::floatToChar(sum[1] / this->matDiv));
    output[y + x].setBlue(  Asemco::floatToChar(sum[2] / this->matDiv));
}

void Kernel::ApplyKernelToImage(const colorVector &input, colorVector &output, unsigned width, unsigned height)
{
    /**
     * \brief Applique le kernel à une image
     *
     * \arg input un vecteur de couleurs représentant une image d'entrée
     * \arg output un vecteur de couleur représentant une image de sortie
     * \arg width la longeur de l'image
     * \arg height la hauteur de l'image
     */
    unsigned y;
    for(unsigned long _y = 1; _y < height-1; ++_y)
    {
        y = _y*width;
        for(unsigned long x = 1; x < width-1; ++x)
        {
            this->ApplyKernelToPixel(input, output, x, y);
        }
    }
}

void blendLayersUsingAlpha(colorVector& background, colorVector& foreground, colorVector& output)
{
    /**
     * \brief mélange 2 image selon le canal alpha de l'image de devant (foreground)
     *
     * \arg background l'image au dernier plan
     * \arg foreground l'image au premier plan
     * \arg output l'image de sortie
     */
    float alpha = 0;
    if(background.size() == foreground.size())
    {
        for(unsigned int i = 0; i < background.size(); ++i)
        {
            if(foreground[i].getAlpha() == 255)
            {
                output[i] = foreground[i];
            }
            else if(foreground[i].getAlpha() == 0)
            {
                output[i] = background[i];
            }
            else
            {
                alpha = foreground[i].getAlpha()/255.0f;
                output[i] = foreground[i]*alpha + background[i]*(1-alpha);
            }
        }
    }
}


void convertToGrayscale(colorVector& image)
{
    /**
     * \brief convertie toute une image en niveau de gris
     *
     * \arg image l'image à modifier
     */
    for(unsigned long i = 0; i < image.size(); ++i)
    {
        image[i] = image[i].grayscale();
    }
}
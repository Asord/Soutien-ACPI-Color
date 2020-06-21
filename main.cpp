#include <iostream>
#include "classes/Color.h"
#include "classes/PNG.h"
#include "classes/Editor.h"

int main(int argc, char* argv[])
{
    /******************* GET IMAGE DATA *******************/
    // Récupération de deux noms de fichiers placés en arguments ou définitions de noms de fichiers par défauts
    // Pour que le programme s'exécute correctement, il faut donc soit posséder deux arguments représentants
    // deux fichiers PNG sois avoir les fichiers "test.png" et "layer1.png" présents à l'emplacement de l'executable.

    //const char* background = argc > 1 ? argv[1] : "test.png";
    //const char* layer1     = argc > 2 ? argv[2] : "layer1.png";


    // Création d'un vecteur de couleur représentant les pixels de l'arière plan
    // Création d'un objet PNG stockant les informations de l'image d'arrière plan
    // Et récupération des pixels depuis les données de l'objet PNG

    //colorVector backgroundPixels;
    //Asemco::PNG backgroundImage(background);
    //backgroundImage.bytesToColor(backgroundPixels);

    // Création d'un vecteur de couleur représentant les pixels du premier plan
    // Création d'un objet PNG stockant les informations de l'image du premier plan
    // Et récupération des pixels depuis les données de l'objet PNG
    //colorVector layer1Pixels;
    //Asemco::PNG layer1Image(layer1);
    //layer1Image.bytesToColor(layer1Pixels);

    // Création d'un vecteur de couleur représentant les pixels du fichier de sortie
    // Redimentionnement du vecteur de pixels selon la taille du premier plan
    // Création d'un objet PNG représentant l'image de sortie
    // Redimentionnement de l'image PNG selon les dimentions du premier plan

    uint32_t height = 512;
    uint32_t width  = 720.0;

    colorVector outputPixels;
    outputPixels.resize(width*height);
    Asemco::PNG outputImage;
    outputImage.reserve(height, width);


    /******************* EDIT IMAGE *******************/
    coefficients coefs;
    coefs.gr = 0.60;
    coefs.br = 0.45;
    coefs.bg = 0.25;

    float hue, saturation, value;
    for(uint32_t v = 0; v < height; ++v)
    {
        for(uint32_t h = 0; h < width; ++h)
        {
            hue   = h/2;
            saturation = 1.0f - (v/2.0f)/(height/2.0f);
            value = 1.0f ;

            outputPixels[width * v + h].fromHSV(hue, saturation, value);
            outputPixels[width * v + h].enhance(coefs);
            //outputPixels[width * v + h].coef(1.0f, 2.38f, 3.33f);
        }
    }

    /******************* SAVE IMAGE *******************/
    // Récupération des informations des pixels dans l'objet PNG de sortie
    outputImage.colorsToBytes(outputPixels);
    // Création du nom de fichier de sortie comme étant "out_[nom du fichier d'arrière plan]"
    std::string newFile = std::string("output/base_low.png");
    // Sauvegarde de l'objet PNG dans le fichier PNG de sortie
    outputImage.saveToFile(newFile.c_str());

    return 0;
}



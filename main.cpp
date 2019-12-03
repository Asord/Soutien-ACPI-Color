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
    const char* background = argc > 1 ? argv[1] : "test.png";
    const char* layer1     = argc > 2 ? argv[2] : "layer1.png";


    // Création d'un vecteur de couleur représentant les pixels de l'arière plan
    // Création d'un objet PNG stockant les informations de l'image d'arrière plan
    // Et récupération des pixels depuis les données de l'objet PNG
    colorVector backgroundPixels;
    Asemco::PNG backgroundImage(background);
    backgroundImage.bytesToColor(backgroundPixels);

    // Création d'un vecteur de couleur représentant les pixels du premier plan
    // Création d'un objet PNG stockant les informations de l'image du premier plan
    // Et récupération des pixels depuis les données de l'objet PNG
    colorVector layer1Pixels;
    Asemco::PNG layer1Image(layer1);
    layer1Image.bytesToColor(layer1Pixels);

    // Création d'un vecteur de couleur représentant les pixels du fichier de sortie
    // Redimentionnement du vecteur de pixels selon la taille du premier plan
    // Création d'un objet PNG représentant l'image de sortie
    // Redimentionnement de l'image PNG selon les dimentions du premier plan
    colorVector outputPixels;
    outputPixels.resize(layer1Image.getSize());
    Asemco::PNG outputImage;
    outputImage.reserve(layer1Image.getHeight(), layer1Image.getWidth());


    /******************* EDIT IMAGE *******************/
    // Création d'un Kernel de flou gaussin
    // Pour plus de détails sur le fonctionnement d'un kernel en traitement d'image, voir la page wikipédia dédié:
    // https://fr.wikipedia.org/wiki/Noyau_(traitement_d%27image)
    Kernel kernel({
        { 1, 2, 1},
        { 2, 4, 2},
        { 1, 2, 1}});

    // Application de la modification du kernel sur l'image de fond
    kernel.ApplyKernelToImage(backgroundPixels, outputPixels, outputImage.getWidth(), outputImage.getHeight());
    // Fusion du premier plan avec l'arrière plan selon le canal alpha du premier plan
    blendLayersUsingAlpha(outputPixels, layer1Pixels, outputPixels);
    // Convertion de l'image en nuance de gris
    convertToGrayscale(outputPixels);



    /******************* SAVE IMAGE *******************/
    // Récupération des informations des pixels dans l'objet PNG de sortie
    outputImage.colorsToBytes(outputPixels);

    // Création du nom de fichier de sortie comme étant "out_[nom du fichier d'arrière plan]"
    std::string newFile = std::string("out_") + background;
    // Sauvegarde de l'objet PNG dans le fichier PNG de sortie
    outputImage.saveToFile(newFile.c_str());

    return 0;
}



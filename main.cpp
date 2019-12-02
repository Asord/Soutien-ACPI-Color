#include <iostream>
#include "classes/Color.h"
#include "classes/PNG.h"
#include "classes/Editor.h"

int main(int argc, char* argv[])
{
    /******************* GET IMAGE DATA *******************/
    const char* background = argc > 1 ? argv[1] : "test.png";
    const char* layer1     = argc > 2 ? argv[2] : "layer1.png";

    colorVector backgroundPixels;
    Asemco::PNG backgroundImage(background);
    backgroundImage.bytesToColor(backgroundPixels);

    colorVector layer1Pixels;
    Asemco::PNG layer1Image(layer1);
    layer1Image.bytesToColor(layer1Pixels);

    colorVector outputPixels;
    outputPixels.resize(layer1Image.getSize());
    Asemco::PNG outputImage;
    outputImage.reserve(layer1Image.getHeight(), layer1Image.getWidth());


    /******************* EDIT IMAGE *******************/
    Kernel kernel({
        { 1, 2, 1},
        { 2, 4, 2},
        { 1, 2, 1}});

    kernel.ApplyKernelToImage(backgroundPixels, outputPixels, outputImage.getWidth(), outputImage.getHeight());
    blendLayersUsingAlpha(outputPixels, layer1Pixels, outputPixels);
    convertToGrayscale(outputPixels);



    /******************* SAVE IMAGE *******************/
    outputImage.colorsToBytes(outputPixels);

    std::string newFile = std::string("out_") + background;
    outputImage.saveToFile(newFile.c_str());

    return 0;
}



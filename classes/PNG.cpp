#include "PNG.h"
#include "../tools/lodepng.h"
#include <iostream>

namespace Asemco
{
    PNG::PNG()
    {
        this->_width = 0;
        this->_height = 0;
        this->_size = 0;
    }

    PNG::PNG(const char *filename){
        this->loadFromFile(filename);
    }

    const std::vector<unsigned char> &PNG::getBytes() const {
        return this->_bytes;
    }

    unsigned int PNG::getWidth() const {
        return this->_width;
    }

    unsigned int PNG::getHeight() const {
        return this->_height;
    }

    unsigned long PNG::getSize() const {
        return this->_size;
    }


    void PNG::reserve(unsigned int height, unsigned int width) {
        /**
         * \brief réserve la place mémoire nécessaire pour stocker l'image prévue
         *
         * \arg height la hauteur de l'image (en pixels)
         * \arg width la largeur de l'image (en pixels)
         */
        this->_height = height;
        this->_width = width;
        this->_size = height * width;
        this->_bytes.resize(this->_size*4);
    }

    void PNG::bytesToColor(colorVector& pixels) const
    {
        /**
         * \brief transforme tous les bytes de l'image en vecteur de couleur
         *
         * \arg pixels un vecteur de couleur (colorVector, voir Color.h)
         */
        pixels.reserve(this->_size);
        for(auto it = this->_bytes.begin(); it != this->_bytes.end(); it += 4)
            pixels.emplace_back( Color(*(unsigned int*)&(*it) ));
    }

    void PNG::colorsToBytes(const colorVector& pixels)
    {
        /**
         * \brief remplaces les bytes de l'image selon un vecteur de couleur
         *
         * \arg pixels un vecteur de couleur (colorVector, voir Color.h)
         */
        unsigned long pos;
        for(unsigned long i = 0; i < this->_bytes.size(); i += 4)
        {
            pos = i / 4;
            *(unsigned int*)&this->_bytes[i] = pixels[pos].getColor();
            /*this->bytes[i+0] = pixels[pos].getRed();
            this->bytes[i+1] = pixels[pos].getGreen();
            this->bytes[i+2] = pixels[pos].getBlue();
            this->bytes[i+3] = pixels[pos].getAlpha();*/
        }
    }

    void PNG::loadFromFile(const char *filename) {
        // charge une image depuis un fichier PNG
        unsigned int error = lodepng::decode(this->_bytes, this->_width, this->_height, filename);
        if (error)
            std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

        this->_size = this->_width * this->_height;
    }

    void PNG::saveToFile(const char *filename) {
        // sauvegarde une image dans un fichier PNG
        unsigned int error = lodepng::encode(filename, this->_bytes, this->_width, this->_height);
        if (error)
            std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }



}
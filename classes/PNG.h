#ifndef COLOR_SLP_PNG_H
#define COLOR_SLP_PNG_H
#include <vector>
#include "Color.h"

// Monstruosité permétant de convertir un itérateur de vector<uint8_t> en un pointeur d'unsigned int
#define ITER_TO_UINT *(unsigned int*)&

namespace Asemco {

    class PNG{
        /**
         * \brief class container d'un fichier PNG
         *
         * \var _bytes les composantes des pixels de l'image
         * \var _width la largeur de l'image
         * \var _height la hauteur de l'image
         * \var _size la taille totale de l'image (le nombre de composantes de pixels)
         */
    protected:
        std::vector<unsigned char> _bytes;
        unsigned int _width, _height;
        unsigned long _size;

    public:
        PNG();
        PNG(const char* filename);

        void reserve(unsigned int height, unsigned int width);

        const std::vector<unsigned char>& getBytes() const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;
        unsigned long getSize() const;

        void colorsToBytes(const colorVector& colors);
        void bytesToColor(colorVector& colors) const;

        void loadFromFile(const char *filename);
        void saveToFile(const char *filename);
    };

}

#endif //COLOR_SLP_PNG_H

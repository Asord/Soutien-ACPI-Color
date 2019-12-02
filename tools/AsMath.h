#pragma once
#include <cmath>
#include <random>

namespace Asemco
{

    // définie une méthode préprocesseur qui effectue un aléatoire bornée.
	#define randRange(n_min, n_max) rand() % (n_max - n_min + 1) + n_min

	inline void normalize(float & num1, float & num2)
    {
	    /**
	     * \brief normalise 2 nombres selon le nombre le plus grand.
	     * \example:
	     *  float f1 = 4.0f; float f2 = 2.0f;
	     *  normalize(f1, f2);
	     *  // f1 -> 1.0 et f2 -> 0.5
	     *
	     * \arg num1 une référence d'un float strictement positif
	     * \arg num2 une référence d'un float strictement positif
	     */
        if (num1 > num2)
        {
            num2 = (1.0f / num1)*num2;
            num1 = 1.0f;
        }
        else
        {
            num1 = (1.0f / num2)*num1;
            num2 = 1.0f;
        }
    }

	inline float f3min(float f1, float f2, float f3)
    {
	    /**
	     * \brief retourne le minimum entre 3 float f1, f2 et f3
	     */
        float tmp = (float)fmin(f1, f2);
        return (float)fmin(tmp, f3);
    }

	inline float f3max(float f1, float f2, float f3)
    {
	    /**
	     * \brief retourne le maximum entre 3 float f1, f2 et f3
	     */
        float tmp = (float)fmax(f1, f2);
        return (float)fmax(tmp, f3);
    }

	inline float ufmodf(float fnum, float fmod)
    {
	    /**
	     * \brief opération modulaire entre 2 float qui retourne la valeur absolue du résultat
	     *
	     * \arg fnum un float sur lequel effectuer l'opération modulaire
	     * \arg fmod un float qui représente la base dans l'aquelle effectuer l'opération modulaire
	     * \return un float valant la valeur absolue de fnum % fmod
	     */
        float r = fmodf(fnum, fmod);
        return r = (r < 0) ? (fmod - r * -1.0f) : r;
    }


    inline unsigned char floatToChar(float f){
	    /**
	     * \brief convertie un type float en type char (byte)
	     *
	     * \arg f un nombre réel quelconque
	     * \return 0 si f < 0, 255 si f > 255, la valeur de f tronquée sinon.
	     */
        if(f < 0)     return 0;
        if( f > 255 ) return 255;
        return (char)f;
	}

}
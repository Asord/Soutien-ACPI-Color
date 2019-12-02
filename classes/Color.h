#ifndef COLOR_SLP_COLOR_H
#define COLOR_SLP_COLOR_H

#include <stdint-gcc.h>
#include <vector>

/* TODO 0: A lire avant de pondre votre code:
 * Cette classe Color est une classe utilitaire devant être utilisable dans de nombreux projets sans qu'il
 * soit nécessaire de modifier son code.
 *
 * Elle se doit donc d'être logiquement implémenté (pas de méthodes inutiles) et doit être suffisement
 * optimisée pour gérer un grand nombre de calcules.
 *
 * Pour qu'elle puisse être utilisée dans notre projet, vous devrez implémenter les méthodes en respectant
 * les noms originaux ainsi que le nombre d'arguments nécessaires.
 *
 * Lors de la conception de cette classe, je vous demanderai d'utiliser uniquement ces types:
 * - float: un nombre réel
 * - int:   un entié signée
 * - uint8_t: un entié non signée (>= 0) de la taille de 8 bits (1 octet) -- c'est un équivalent de "unsigned char"
 * - uint32_t: un entié non signée (>= 0) de la taille de 32 bits (4 octet) -- c'est un équivalent de "unsigned int"
 *
 * Pour ne pas se mélanger, l'ordre des couleurs (et des arguments des méthodes) sera toujours:
 *              rouge, vert, bleu (, alpha)
 */

class Color
{
public:
    /* TODO 4: Déclarer les couleurs préfaites de notre classe Color
     * Les couleurs qui doivent être définies sont:
     * Les 3 couleurs primaires (Rouge, Vert, Bleu)
     * Les 3 couleurs secondaires (Jaune, Cyan, Magenta)
     * Le Blanc et le Noir.
     *
     * Astuce: pensez à utiliser le mot-clé static.
     */

protected:
    /* TODO 1: Créer une union "anonyme" entre:
     * - une structure "anonyme" composée de 4 uint8_t (_red, _green, _blue, _alpha)
     * - un uint32_t (_color)
     */

public:
    /* TODO 2: Créer les constructeurs
     * Nous avons besoins de 4 constructeurs:
     * Constructeur par défaut qui intialise les couleurs à 0 (noir) et alpha à 1 (opaque)
     * Constructeur RGB qui prend les valeurs de 3 arguments RGB et qui définit alpha à 1 (opaque)
     * Constructeur RGBA qui prend les valeurs de 4 arguments RGBA
     * Constructeur couleur qui prend la valeur d'un entié signé et l'assigne à _color
     */

    // TODO 3: Créer les acesseurs (getters/setters) de _red, _green, _blue, _alpha et _color

    Color& fromHue(float hue);
    Color& fromHSV(float hue, float saturation, float value);

    void toHSV(float& hue, float& saturation, float& value) const;

    /* TODO 10: Créer 2 méthodes pour créer des couleurs de manière aléatoire.
     * La prémière méthode crée une couleur complètement aléatoirement (random RGB)
     * La seconde méthode crée une couleur aléatoirement suivant sa teinte (modèle HSV) - voire Color::fromHue(float)
     *
     * Pour ces deux méthodes, nous avons besoins d'y défnir une graine d'aléatoire (seed) qui aura par
     * défaut la valeur 0)
     *
     * Pour la seconde méthode, nous voulons pouvoir bornée notre teinte aléatoire entre un minimum et
     * un maximum (par défaut: 0.0f et 360.0f respéctivement). Utilisez la méthode "fromHue" pour attribuer la couleur.
     *
     * Les 2 méthodes doivent retourner une référence de l'objet courent.
     *
     * methodes: random(int) | randomColor(float min, float max, int seed)
     */

    /* TODO 11: Créer 3 méthodes pour redéfinir la couleur actuelle en noir, blanc ou en gris.
     * Seul la méthode pour grisée la couleur comporte comme argument une valeur entre 0 et 255
     *
     * Les 3 méthodes doivent retourner une référence de l'objet courent.
     *
     * signature: black() | white() | gray(uint8_t)
     */

    /* TODO 12: Créer une méthode pour inversé la couleur actuelle.
     * Astuce: l'inverse de la composante rouge est 255-rouge...
     *
     * La méthode doit retourner une référence de l'objet courent.
     *
     * signature: invert()
     */

    /* TODO 13: Créer une méthode qui grise la couleur actuelle.
     * Astuce: il suffit de faire la moyenne des 3 composantes RGB et d'utiliser notre méthode "gris"
     *
     * La méthode doit retourner une référence de l'objet courent.
     *
     * signature: grayscale()
     */

    /* TODO 14: Créer une méthide qui modifie la couleur actuelle selon des coéficients d'intensités.
     * Explication: sur certain appareils utilisant des leds RGB, les couleurs émises se trouvent être
     * différentes des couleurs souhaités (trop bleus, pas assez rouge...)
     * Cette méthode doit permettre de définir des coéficients modificateurs pour palier à ce problème.
     * Les 3 coéficiants modificateurs sont représentés de 0.0f à 1.0f.
     *
     * La méthode doit retourner une référence de l'objet courent.
     *
     * signature: coef(float, float, float)
     */

    /* TODO 5: Créer les opétaeurs incrémentation et décrémentation qui incrémentent et décrémentent
     * les 3 composantes.
     *
     * Les opérateurs doivent retourner une référence de l'objet courent.
     */

    /* TODO 6: Créer les opérateurs + et - entre 2 couleurs
     * Ces opérateurs effectuent les opérations sur chacune des composantes RGB de la couleur.
     * Nous souhaitons en plus des opérateurs + et -, les opérateurs += et -=.
     *
     * Les opérateurs += et -= doivent retourner une référence de l'objet courent.
     */

    /* TODO 7: créer les opérateurs * et / entre une couleur et un float
     * Ces opérateurs éféctuent les opérations sur chacune des composantes RGB de la couleur.
     * Nous souhaitons en plus des opérateurs * et /, les opérateurs *= et /=.
     *
     * Les opérateurs *= et /= doivent retourner une référence de l'objet courent.
     *
     * Pensez à définir l'opérateur "float * Color" aussi (avec la méthode friend)
     */

    /* TODO 8: Créer l'opérateur % (modulo) entre une couleur et un uint8_t
     * Cet opérateur effectue l'opération modulo sur chacune des composantes RGB de la couleur.
     * Nous souhaitons en plus de l'opérateur %, l'opérateur %=
     *
     * L'opérateur %= doit retourner une référence de l'objet courent.
     */

    /* TODO 9: Créer les opérateurs d'égalité (== et !=)
     * Ces opérateurs effectue une comparaison sur chacune des composantes RGB de la couleur.
     */
};

// Définition d'une valeur préprocesseur colorVector pour simplifié la visibilité du code exploitant cette classe.
#define colorVector std::vector<Color>

#endif //COLOR_SLP_COLOR_H

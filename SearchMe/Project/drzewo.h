#ifndef DRZEWO_H
#define DRZEWO_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/** \brief Element złożonej listy dynamicznej.
*
* Definicja elementu złożonej dynamicznej listy liter.
*/
struct Znak
{
    ///Wpisywany znak.
    char napis;
    ///Wkaźniki przypisywane do elementu struktury Znak.
    Znak *child,*parent,*bro;
};
/** \brief Funkcja tworząca element typu Znak
 *
 * Funkcja tworzy dynamicznie element typu Znak za pomocą operatora new.
 * Element dodawany jest pod wskaźnikiem *child.
 * \param head początek listy
 * \param v element dodawany
 */
void dodajDziecko(Znak *&head, char v);
/** \brief Funkcja tworząca element typu Znak
 *
 * Funkcja tworzy dynamicznie element typu Znak za pomocą operatora new.
 * Element dodawany jest pod wskaźnikiem *bro.
 * \param head początek listy
 * \param v element dodawany
 */
void dodajBrata(Znak *&head, char v);
/** \brief Funkcja budująca drzewo
 *
 * Funkcja buduje drzewo trie z wyrazów dostępnych w pliku tekstowym
 * \param root początek listy
 */
void budowanieDrzewa(Znak *&root);
/** \brief Funkcja podpowiadająca
 *
 * Funkcja podpowiada dostępne do napisania wyrazy
 * \param root początek listy
 * \param v wpisywana przez użytkownika litera
 * \return podpowiedz wskaźnik na element od którego ma być wyświetlane drzewo
 */
Znak * podpowiedz(Znak *&root,char v);
/** \brief Funkcja usuwająca drzewo
 *
 * Funkcja usuwa drzewo
 * \param e początek listy
 */
void usunDrzewo(Znak *e);
#endif // DRZEWO_H

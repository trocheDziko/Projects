#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include "drzewo.h"
using namespace std;
/** \brief Funkcja wyświetlająca drzewo
 *
 * Funkcja przechodzi przed drzewo, dodając napotkane litery do parametru funkcji.
 * Następnie je wyświetla
 * \param root początek listy
 * \param prefix przechowuje napotkane litery podczas przechodzenia po drzewie
 */
void WyswietlDrzewo (Znak *root, string prefix)    //Funkjcę przeniosłem do maina, zgodnie z Pana uwagą.
{
if (root->child!= NULL) {
    prefix+=root->napis;
    Znak *pom=root->child;
    while(pom)
        {
        WyswietlDrzewo(pom,prefix);
        pom=pom->bro;
        }
    } else
    {
        cout<<prefix+root->napis<<endl;;
    }
}
void PokazDrzewo(Znak *root){
    Znak* pomoc;
    Znak* brat=root;
    Znak* kontrol=root;
   // Znak* brat=kontrol->bro;
    if(kontrol!=NULL){
        cout<<kontrol->napis<<endl;
        while(kontrol->bro!=NULL){
        while(kontrol->child!=NULL){
            pomoc=kontrol->child;
            cout<<" "<<pomoc->napis<<endl;
            while(pomoc->bro!=NULL){
                cout<<"  "<<pomoc->napis<<endl;
                pomoc=pomoc->bro;
            }
            kontrol=kontrol->child;
        }
        cout<<endl;
        kontrol=brat->bro;
        brat=brat->bro;
       // brat=brat->bro;
    }
  }
}

int main()
{
    Znak *korzen=NULL;
    string slowo,slowobez;
    char zmienna;
    Znak *pom;
    budowanieDrzewa(korzen);
    PokazDrzewo(korzen);
    /* cout<<"Witam w moim projekcie z Zasad Programowania Strukturalnego II!"<<endl;
     cout<<"Aby rozpoczaczac zacznij pisac wyraz:"<<endl;
    while(1){
            zmienna=getch();
            if(zmienna==13) break;
            if(zmienna>='A'&&zmienna<='Z'){
                zmienna=tolower(zmienna);
            }
            if(!(zmienna>='a'&&zmienna<='z')){
                cout<<"Mozna wpisywac aby litery. Sprobuj jeszcze raz"<<endl;
                continue;
            }
            system("cls");
            slowobez=slowo;
            slowo=slowo+zmienna;
            cout<<slowo<<endl;
            if(pom!=NULL)
            {
            pom=podpowiedz(korzen,zmienna);
            if(pom!=NULL) WyswietlDrzewo(pom,"");
            if(pom==NULL) {
                cout<<"Niestety brak dalszych podpowiedzi."<<endl;
                cout<<"Ostatnie znalezione slowo "<<slowobez<<"."<<endl;
            break;
            }
            if(korzen->child!=NULL )korzen=korzen->child;
            }
        }*/
    usunDrzewo(korzen);
    return 0;
}





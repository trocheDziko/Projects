#include "drzewo.h"
void dodajDziecko(Znak *&head, char v)
{
    Znak *p, *e;
    e = new Znak;
    e->child = NULL;
    e->bro = NULL;
    e->napis= v;
    p=head;
    if(p)
    {
        while(p->child) p=p->child;
        p->child=e;
        e->parent=p;
    }
    else head = e;
}
void dodajBrata(Znak *&head, char v)
{
    Znak *p, *e;
    e = new Znak;
    e->child = NULL;
    e->bro = NULL;
    e->napis= v;
    p=head;
    if(p)
    {
        while(p->bro) p=p->bro;
        p->bro=e;
        e->parent=p->parent;
    }
    else head = e;
}
void budowanieDrzewa(Znak *&root)
{
    Znak *kontrol;
    string wyraz;
    ifstream iplik("Slownik.txt");
    if(!iplik.good())
    {
        return;
    }
    while(!iplik.eof())
    {
        getline(iplik,wyraz);
        int i=wyraz.size();
        if(root == NULL)
        {
            for(int j=0;j<i;j++)
            {
                dodajDziecko(root,wyraz[j]);
            }
        }
        else
        {
            int a=0;
            kontrol=root;
            while((kontrol->bro)!=NULL)
            {
                if((wyraz[a])==(kontrol->napis))
                {
                   break;
                }
                kontrol=kontrol->bro;
            }
            if(kontrol->napis==wyraz[a])
            {
                kontrol=kontrol->child;
                a++;
                for(int k=a;k<i;k++)
                {
                    if(kontrol->napis==wyraz[k])
                    {
                        a++;
                        kontrol=kontrol->child;
                    } else break;
                }
                while(kontrol->bro!=NULL)
                {
                    if(kontrol->napis==wyraz[a]){
                        kontrol=kontrol->child;
                        a++;
                        for(int p=a;p<i;p++)
                        {
                            if(kontrol->napis==wyraz[p])
                            {
                                a++;
                                kontrol=kontrol->child;
                            } else break;
                        }
                        while(kontrol->bro!=NULL)
                        kontrol=kontrol->bro;
                        break;
                    }
                kontrol=kontrol->bro;
                }
                if(kontrol->bro==NULL){
                    if(kontrol->napis==wyraz[a]){
                        kontrol=kontrol->child;
                        a++;
                        for(int p=a;p<i;p++)
                        {
                            if(kontrol->napis==wyraz[p])
                            {
                                a++;
                                kontrol=kontrol->child;
                            } else break;
                        }
                        while(kontrol->bro!=NULL)
                        kontrol=kontrol->bro;
                    }
                }
                dodajBrata(kontrol,wyraz[a]);
                kontrol=kontrol->bro;
                for(int s=a+1;s<i;s++)
                dodajDziecko(kontrol,wyraz[s]);

            }
            else
            {
            dodajBrata(kontrol,wyraz[a]);

            kontrol=kontrol->bro;
            for(int z=a+1;z<i;z++)
                {
                dodajDziecko(kontrol,wyraz[z]);
                }
                }
            }
        }
    iplik.close();
}
Znak * podpowiedz(Znak *&root,char v)
{
    if(root->napis==v)
    return root;
    else
    {
    while(root->napis!=v)
    {
        if(root->bro != NULL) root=root->bro;
        else {
         return NULL;
        }
    }
    return root;
    }
}
void usunDrzewo(Znak *e){
    if(e==0) return;
    Znak *ch=e->child;
    Znak *bro=e->bro;
    delete e;

    usunDrzewo(ch);
    usunDrzewo(bro);
}

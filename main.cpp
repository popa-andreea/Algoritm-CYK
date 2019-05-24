#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

class gramaticaFNC
{
    vector<pair<char, pair<char,char> > >  productii;
    int numarProductii;

public:

    gramaticaFNC();
    void afisare();
    bool algoritmCYK();
    ~gramaticaFNC();

};

gramaticaFNC::gramaticaFNC()
{
    ifstream f("gramatica.txt");
    f >> numarProductii;
    char stanga,dreapta1,dreapta2;

    while(f>>stanga)
    {
        f>>dreapta1;
        if(islower(dreapta1))
            dreapta2='\0';
        else
            f>>dreapta2;
        productii.push_back(make_pair(stanga,make_pair(dreapta1,dreapta2)));
    }
}

void gramaticaFNC::afisare()
{
    int i;

    for(i=0;i<numarProductii;i++)
    {
        cout<<productii[i].first<<"->";
        cout<<productii[i].second.first;
        if(productii[i].second.second!='\0')
            cout<<productii[i].second.second;
        cout<<endl;
    }
}


bool gramaticaFNC::algoritmCYK()
{
    unsigned int i,j,k,l,m,n,o,ok;

    char cuvant[20];
    cout<<"Introduceti un cuvant:";
    cin>>cuvant;

    char matrice[strlen(cuvant)][strlen(cuvant)][100];
    int adancime[strlen(cuvant)][strlen(cuvant)];

    for(i=0;i<strlen(cuvant);i++)
        for(j=0;j<strlen(cuvant);j++)
            adancime[i][j]=0;

    for(i=0;i<strlen(cuvant);i++) //completez prima linie din matrice
        for(j=0;j<numarProductii;j++)
            if(productii[j].second.first==cuvant[i]) //caut productiile in care se regaseste a i-a litera din cuvant
            {
                matrice[0][i][adancime[0][i]++]=productii[j].first;//adaug neterminalul in matrice

            }

    for(i=1;i<strlen(cuvant);i++) //pargugem liniile incepand cu linia a doua
        for(j=0;j<strlen(cuvant)-i;j++) //coloana
            for(k=0;k<i;k++) //index CYK
               for(l=0;j<adancime[k][j];l++)
                  for(m=0;m<adancime[i-k-1][j+k+1];m++)
                    for(o=0;o<numarProductii;o++)
                      if(productii[n].second.first==matrice[k][j][l] && productii[n].second.second==matrice[i-k-1][j+k+1][m])
                        {
                            ok=true;
                            for(o=0;o<adancime[i][j];o++)
                                if(productii[n].first==matrice[i][j][o])
                                   ok=false;
                            if(ok)
                                matrice[i][j][adancime[i][j]++]=productii[n].first;
                        }

    for(i=0;i<adancime[strlen(cuvant)-1][0];i++)
        if(matrice[strlen(cuvant)-1][0][i]=='S')
           return true;

    return false;
 }

gramaticaFNC::~gramaticaFNC()
{
    numarProductii=0;
    productii.clear();
}

int main()
{
    gramaticaFNC G;
    G.afisare();
    if(G.algoritmCYK()==true)
        cout<<"Cuvantul este acceptat.";
    else
        cout<<"Cuvantul nu este acceptat.";
    return 0;
}

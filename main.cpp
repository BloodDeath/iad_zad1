#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include "gnuplot_i.hpp"
#define GNUPLOT_PATH "C:\\gnuplot\\bin"
#define IRIS_PATH "..\\iris.data"


//1. sepal length in cm
//2. sepal width in cm
//3. petal length in cm
//4. petal width in cm
void writetofile(double*** data, std::string file)
{
std::fstream plik;
plik.open(file, std::ios::out);
if(plik.good())
{
for(int i=0;i<3;i++) {
plik<<"Iris nr:"<<i+1<<std::endl;
for (int j = 0; j < 50; j++) {

for (int k = 0; k < 4; k++) {
plik << data[i][j][k]<<",";
}
plik << std::endl;
}
}
}
else
{
std::cout<<"Plik do zapisu nie do zamkniecia"<<std::endl;
}
plik.close();
}

void quicksort(double*** tab, int left, int right, int q, int w){
    int i=left;
    int j=right;
    double x=tab[q][(left+right)>>1][w];
    do{
        while(tab[q][i][w]<x) i++;
        while(tab[q][j][w]>x) j--;
        if(i<=j){
            double temp=tab[q][i][w];
            tab[q][i][w]=tab[q][j][w];
            tab[q][j][w]=temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(left<j) quicksort(tab,left,j,q,w);
    if(right>i) quicksort(tab,i,right,q,w);
}

void quicksort_alltable(double tab[4][150], int left, int right,int q){
    int i=left;
    int j=right;
    double x=tab[q][(left+right)>>1];
    do{
        while(tab[q][i]<x) i++;
        while(tab[q][j]>x) j--;
        if(i<=j){
            double temp=tab[q][i];
            tab[q][i]=tab[q][j];
            tab[q][j]=temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(left<j) quicksort_alltable(tab,left,j,q);
    if(right>i) quicksort_alltable(tab,i,right,q);
}


class Iris
{
private:
   double data[3][50][4];
     //std::string name;
public:
    Iris()
    {
    }
public: void add_tab(double x[3][50][4])
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<50;j++)

            {
                for (int k=0;k<4;k++)
                {
                    data[i][j][k] = x[i][j][k];
                }

            }


        }

    }
public: void add_number(double number, int tab_0, int tab_1)
    {
       // data [tab_0][tab_1] = number;
    }
public: void cout_alldata()
    {
        for (int i=0;i<50;i++)
        {
            for(int j=0;j<4;j++)
            {
                std::cout<<data[i][j]<<" , ";
            }
            std::cout<<std::endl;
        }

    }
public: void alldata_tofile()
    {
        std::fstream plik;
        plik.open("..\\wynikowy", std::ios::out);
        if(plik.good())
        {
            for(int i=0;i<3;i++) {
                plik<<"Iris nr:"<<i+1<<std::endl;
                for (int j = 0; j < 50; j++) {

                    for (int k = 0; k < 4; k++) {
                        plik << data[i][j][k]<<",";
                    }
                    plik << std::endl;
                }
            }
        }
        else
        {
            std::cout<<"Plik do zapisu nie do zamkniecia"<<std::endl;
        }
        plik.close();
    }
public: void rysuj_obanaraz()
    {
        // RYSOWANIE WYKRESU
        Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
        Gnuplot wykres;
        wykres.set_title("Wykres");
        wykres.set_xlabel("sepal length ");
        wykres.set_ylabel("sepal width");
        wykres.set_style("points");
        wykres.set_grid();
        wykres.set_pointsize(1.0);
        wykres.set_xrange(0,10);
        wykres.set_yrange(0,10);
        std::vector<double> osx;
        std::vector<double> osy;
        for (int i= 0; i<50; i++)
        {
            osx.push_back(data[0][i][0]);
            osy.push_back(data[0][i][1]);
        }

        wykres.plot_xy(osx,osy, "Setosa");
        osx.clear();
        osy.clear();
       // wykres.set_color("\"cyan\"");
        //wykres.set_style("boxes");
        for (int i= 0; i<50; i++)
        {
            osx.push_back(data[1][i][0]);
            osy.push_back(data[1][i][1]);
        }
        wykres.plot_xy(osx,osy, "Versicolor");
        osx.clear();
        osy.clear();
      //  wykres.set_color("\"red\"");
        for (int i= 0; i<50; i++)
        {
            osx.push_back(data[2][i][0]);
            osy.push_back(data[2][i][1]);
        }

        wykres.plot_xy(osx,osy, "Viriginica");
        osx.clear();
        osy.clear();

        // RYSOWANIE WYKRESU
       // Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
        Gnuplot drugiwykres;
        drugiwykres.set_title("Wykres");
        drugiwykres.set_xlabel("peta length ");
        drugiwykres.set_ylabel("peta width");
        drugiwykres.set_style("points");
        drugiwykres.set_grid();
        drugiwykres.set_pointsize(1.0);
        drugiwykres.set_xrange(0,10);
        drugiwykres.set_yrange(0,10);
        //std::vector<double> osx;
        //std::vector<double> osy;
        for (int i= 0; i<50; i++)
        {
            osx.push_back(data[0][i][2]);
            osy.push_back(data[0][i][3]);
        }

        drugiwykres.plot_xy(osx,osy, "Setosa");
        osx.clear();
        osy.clear();
        // wykres.set_color("\"cyan\"");
        //wykres.set_style("boxes");
        for (int i= 0; i<50; i++)
        {
            osx.push_back(data[1][i][2]);
            osy.push_back(data[1][i][3]);
        }
        drugiwykres.plot_xy(osx,osy, "Versicolor");
        osx.clear();
        osy.clear();
        //  wykres.set_color("\"red\"");
        for (int i= 0; i<50; i++)
        {
            osx.push_back(data[2][i][2]);
            osy.push_back(data[2][i][3]);
        }

        drugiwykres.plot_xy(osx,osy, "Viriginica");
        osx.clear();
        osy.clear();
        system("pause");

    }
public: void rysuj_wykres(Gnuplot wykres)
    {
        // RYSOWANIE WYKRESU


        wykres.set_title("Wykres");
        wykres.set_xlabel("sepal length ");
        wykres.set_ylabel("sepal width");
        wykres.set_style("points");
        wykres.set_grid();
        wykres.set_pointsize(1.0);
        wykres.set_xrange(0,10);
        wykres.set_yrange(0,10);
        std::vector<double> osx;
        std::vector<double> osy;
        for (int i= 0; i<50; i++)
        {
            osx.push_back(data[0][i][0]);
            osy.push_back(data[0][i][1]);
        }

        wykres.plot_xy(osx,osy, "Setosa");
        osx.clear();
        osy.clear();
        for (int i= 0; i<50; i++)
        {
            osx.push_back(data[1][i][0]);
            osy.push_back(data[1][i][1]);
        }
        wykres.plot_xy(osx,osy, "Versicolor");
        osx.clear();
        osy.clear();
        //  wykres.set_color("\"red\"");
        for (int i= 0; i<50; i++)
        {
            osx.push_back(data[2][i][0]);
            osy.push_back(data[2][i][1]);
        }

        wykres.plot_xy(osx,osy, "Viriginica");
        osx.clear();
        osy.clear();
    }
public: void rysuj_drugiwykres(Gnuplot wykres)
    {
        // RYSOWANIE WYKRESU


        wykres.set_title("Wykres");
        wykres.set_xlabel("peta length ");
        wykres.set_ylabel("peta width");
        wykres.set_style("points");
        wykres.set_grid();
        wykres.set_pointsize(1.0);
        wykres.set_xrange(0,10);
        wykres.set_yrange(0,10);
        std::vector<double> osx;
        std::vector<double> osy;
        for (int i= 0; i<50; i++)
        {
            osx.push_back(data[0][i][2]);
            osy.push_back(data[0][i][3]);
        }

        wykres.plot_xy(osx,osy, "Setosa");
        osx.clear();
        osy.clear();
        // wykres.set_color("\"cyan\"");
        //wykres.set_style("boxes");
        for (int i= 0; i<50; i++)
        {
            osx.push_back(data[1][i][2]);
            osy.push_back(data[1][i][3]);
        }
        wykres.plot_xy(osx,osy, "Versicolor");
        osx.clear();
        osy.clear();
        //  wykres.set_color("\"red\"");
        for (int i= 0; i<50; i++)
        {
            osx.push_back(data[2][i][2]);
            osy.push_back(data[2][i][3]);
        }

        wykres.plot_xy(osx,osy, "Viriginica");
        osx.clear();
        osy.clear();
 //       system("pause");
    }
    void gettab(double*** tab)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<50;j++)

            {
                for (int k=0;k<4;k++)
                {
                    tab[i][j][k]=data[i][j][k];
                }

            }


        }
    }
    void min_max_rozstep()
    {
        double*** tab;
        tab=new double**[3];
        tab[0]=new double*[50];
        tab[1]=new double*[50];
        tab[2]=new double*[50];
        for(int i=0;i<50;i++)
        {
            tab[0][i]=new double[4];
            tab[1][i]=new double[4];
            tab[2][i]=new double[4];
        }
        double alltable[4][150];
        gettab(tab);
        for(int i=0;i<4;i++)
            for(int j=0;j<150;j++)
            {
                alltable[i][j]=tab[j/50][j%50][i];
            }
        for(int i=0;i<4;i++)
        quicksort_alltable(alltable,0,149,i);
        double table[4][4][3]={0};             // 1 min, 2 max, 3 rozstep
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                table[i][j][0]=tab[i%3][0][j];
            }

        for(int q=0;q<3;q++)
            for(int w=0;w<4;w++)
            {
                quicksort(tab,0,49,q,w);
            }
        writetofile(tab,"D:\\Studia\\IAD\\lab1\\posortowane");

        for(int q=0;q<3;q++)
            for(int e=0;e<50;e++)
           for(int w=0;w<4;w++)
           {
               if(table[q][w][0]>tab[q][e][w]) table[q][w][0]=tab[q][e][w];
               if(table[q][w][1]<tab[q][e][w]) table[q][w][1]=tab[q][e][w];



           }

            for(int i=0;i<4;i++)
            {
                table[3][i][0]=table[0][i][0];
            }
        for(int j=0;j<3;j++)
            for(int i=0;i<4;i++)
            {
                if(table[3][i][0]>table[j][i][0])table[3][i][0]=table[j][i][0];
                if(table[3][i][1]<table[j][i][1])table[3][i][1]=table[j][i][1];
            }
        for(int i=0;i<4;i++)
        for(int q=0;q<4;q++)
        {
            table[i][q][2]=table[i][q][1]-table[i][q][0];
        }

        for(int i=0;i<4;i++) {
            for (int j = 0; j < 4; j++) {
                for (int z = 0; z < 3; z++) {
                    std::cout << table[i][j][z] << "    ";
                }
                std::cout << std::endl;
            }
            std::cout<<std::endl<<std::endl;
        }
        licz_kwartyle(tab);
        for(int i=0;i<4;i++)
        {
            std::cout<<"Cecha numer: "<<i<<std::endl;

        std::cout<<alltable[i][49]<<"   ";
        std::cout<<alltable[i][99]<<"   ";
        std::cout<<alltable[i][149]<<std::endl;
        }
        srednia(tab,-1);
        srednia(tab,0);
        srednia(tab,1);
        srednia(tab,2);
        for(int i=0;i<50;i++)
        {
            delete tab[0][i];
            delete tab[1][i];
            delete tab[2][i];
        }
        delete tab[0];
        delete tab[1];
        delete tab[2];
        delete tab;
    }
    void licz_kwartyle(double*** tab)
    {
        std::cout<<"1szy    2gi 3ci"<<std::endl;

        for(int j=0;j<4;j++)
        {
            std::cout<<j+1<<" cecha"<<std::endl;
        for(int i=0;i<3;i++)
        {
            std::cout<<tab[i][13][j]<<" "; // 1 szy kwantyl
            std::cout<<tab[i][25][j]<<" "; // 2 kwantyl
            std::cout<<tab[i][38][j]<<" "; // 3 kwantyl
            std::cout<<std::endl;
        }
            std::cout<<std::endl;
        }
    }

    void srednia (double*** tab, double rzad) {
        std::cout << "Licze srednia rzedu " << rzad << std::endl; // komunikat ktory rzad liczymy
        double n = 50; // ilosc irysow w rodzaju
        double sum[4][4] = {0}; // tabelka na srednie poszczegolnych parametrow i rodzajow, ostatni param to avg wszystkiego

        // RZAD 0 przypadek szczegolny (srednia geometryczna)
        if (rzad == 0) {
            // licze sume logarytmow POSZCZEGOLNYCH RODZAJOW
            for (int i = 0; i < 3; i++) { // petelka i jedzie po rodzajach
                for (int j = 0; j < 50; j++) { // petelka j jedzie po wszzystkich itemach
                    for (int k = 0; k < 4; k++) { // petelka k jedzie po kolejnych parametrach
                        sum[i][k] += log(tab[i][j][k]);
                    }
                }
            }
            // licze sume logarytmow WSZYSTKIEGO
            for (int k = 0; k < 4; k++) { // petelka k jedzie po kolejnych parametrach
                sum[3][k] = sum[0][k] + sum[1][k] + sum[2][k];
            }
            // teraz wszystkie sumy logarytmów do exp i pierwiastka POSZCZEGOLNYCH RODZAJOW
            for (int i = 0; i < 3; i++) { // petelka i jedzie po rodzajach
                for (int k = 0; k < 4; k++) { // petelka k jedzie po kolejnych parametrach
                    sum[i][k] = pow(exp(sum[i][k]), 1/n);
                }
            }
            // sumy logarytmów do exp i pierwiastka WSZYSTKIEGO
            for (int k = 0; k < 4; k++) { // petelka k jedzie po kolejnych parametrach
                sum[3][k] = pow(exp(sum[3][k]), 1/(3*n));
            }
        } else {
            // licze sume poteg POSZCZEGOLNYCH RODZAJOW
            for (int i = 0; i < 3; i++) { // petelka i jedzie po rodzajach
                for (int j = 0; j < 50; j++) { // petelka j jedzie po wszzystkich itemach
                    for (int k = 0; k < 4; k++) { // petelka k jedzie po kolejnych parametrach
                        sum[i][k] += pow(tab[i][j][k], rzad);
                    }
                }
            }
            // licze sume poteg WSZYSTKIEGO
            for (int k = 0; k < 4; k++) { // petelka k jedzie po kolejnych parametrach
                sum[3][k] = sum[0][k] + sum[1][k] + sum[2][k];
            }
            // teraz wszystkie sumy poteg POSZCZEGOLNYCH RODZAJOW przez n i pierwiastek rzędu
            for (int i = 0; i < 3; i++) { // petelka i jedzie po rodzajach
                for (int k = 0; k < 4; k++) { // petelka k jedzie po kolejnych parametrach
                    sum[i][k] = pow((sum[i][k]/n), 1/rzad);
                }
            }
            // sumy poteg WSZYSTKIEGO przez n i pierwiastek rzędu
            for (int k = 0; k < 4; k++) { // petelka k jedzie po kolejnych parametrach
                sum[3][k] = pow((sum[3][k]/(n*3)), 1/rzad);
            }

        }

        // wyswietlanie przybytku
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                std::cout << sum[i][j] << " ";
            std::cout << std::endl;
        }
    }
};





//Iris setosa("setosa");
//Iris versicolor("versicolor");
//Iris virginica("virginica");
Iris iris;
void readfile() {
    std::fstream plik;
    plik.open(IRIS_PATH,std::ios::in);
    double tablica[3][50][4];
//    double*** array = 0;
  //  array = (double ***) tablica;
    if(plik.good())
    {
        std::string s;
        double tab[4];

        // otowrzenie pliku
        int setosa_i=0;
        int versicolor_i=0;
        int virginica_i=0;
        int liczba_petli=0;
        while(!plik.eof())
        {
            liczba_petli++;
            getline(plik,s);
            std::stringstream stream(s);
            double n;
            int i=0;
            while(stream >> n)
            {
                if (stream.peek()==',') stream.ignore();
                //stream>>n;
                std::cout<<n<<std::endl;
                tab[i]=n;
                std::cout<<"wartosc i:"<<i++<<std::endl;
            }
            std::cout<<"koncowa wartosc i:"<<i<<std::endl;
            i=0;

            if (s.find("Iris-setosa") != std::string::npos)
            {
                for (int licznik=0; licznik<4;licznik++)
                {
                    tablica[0][setosa_i][licznik]=tab[licznik];
                }
                setosa_i++;

            }
            else if (s.find("Iris-versicolor") != std::string::npos)
            {
                for (int licznik=0; licznik<4;licznik++)
                {
                    tablica[1][versicolor_i][licznik]=tab[licznik];
                }
                versicolor_i++;
            }
            else if(s.find("Iris-virginica") != std::string::npos)
            {
                for (int licznik=0; licznik<4;licznik++)
                {
                    tablica[2][virginica_i][licznik]=tab[licznik];
                }
                virginica_i++;

            }
            else std::cout << "Linia pominieta, poniewaz nie spelnia wymagan parsera." << std::endl;
        }
        plik.close();
    }
    else std::cout<<"Can't open file"<<std::endl;
    iris.add_tab( tablica);
   // return array;
}

int main() {
    Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
//
//    double*** array=readfile();

//    std::cout<<array[0][0][0];
readfile();
    iris.alldata_tofile();
    iris.rysuj_obanaraz();

//    Gnuplot wykres1;
//    Gnuplot wykres2;
//iris.rysuj_wykres(wykres1);
//    iris.rysuj_drugiwykres(wykres2);
//    std::vector<double> osx;
//    std::vector<double> osy;
//    osx.push_back(0);
//    osy.push_back(0);
  //  wykres1.plot_xy(osx,osy);
   // wykres2.plot_xy(osx,osy);


    iris.min_max_rozstep();
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
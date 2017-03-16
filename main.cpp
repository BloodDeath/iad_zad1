#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "gnuplot_i.hpp"
#define GNUPLOT_PATH "D:\\Programy\\gnuplot\\bin"
#define IRIS_PATH "D:\\Studia\\IAD\\lab1\\iris.data"


//1. sepal length in cm
//2. sepal width in cm
//3. petal length in cm
//4. petal width in cm
class Iris
{
private:
   double data[3][150][4];
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
        plik.open("D:\\Studia\\IAD\\lab1\\wynikowy", std::ios::out);
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
    void funkcja_gowno()
    {
        system ("pause");
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
        funkcja_gowno();
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
            else std::cout<<"Cos sie popsulo"<<std::endl;
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
    system("pause");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
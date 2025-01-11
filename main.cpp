#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>


int game(int maxnum);
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ARVAUSPELI_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    int maxnum;
    std::cout << "Anna pelin maksiminumero: ";
    std::cin >> maxnum;

    int arvausten_maara = game(maxnum);

    std::cout << "Sait oikean vastauksen " << arvausten_maara << " arvauksella!" << std::endl;

    return a.exec();
}
int game(int maxnum){
    int arvaus;
    int arvausten_maara = 0;


    std::srand(std::time(0)); // Asetetaan siemenluku, joka arvotaan ajan mukaan

    int luku = std::rand() % maxnum + 1; // Arvotaan luku 1-maxnum
    std::cout <<"Tervetuloa arvauspeliin arvaa luku 1 - " << maxnum << "." << std::endl;

    while(true){ //aloitetaan while loop jotta päästään takaisin jos arvaus ei ole oikea
        std::cout <<"Arvaa numero"<<std::endl;
        std::cin >>arvaus; //kysytään käyttäjän arvaus
        arvausten_maara++;

        if (arvaus < luku){ //verrataan lukuja
            std::cout <<"luku on suurempi"<<std::endl;

        }
        if (arvaus > luku){
            std::cout <<"luku on pienempi"<<std::endl;

        }
        if(arvaus == luku){
            std::cout <<"oikea vastaus"<<std::endl;
            break; //pysäytetään loop jotta peli päättyy
        }
    }
    return arvausten_maara;
}

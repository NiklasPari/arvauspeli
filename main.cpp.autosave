#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>

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

    int arvaus;
    std::srand(std::time(0)); // Asetetaan siemenluku, joka arvotaan ajan mukaan

    int luku = std::rand() % 20 + 1; // Arvotaan luku 1-20
    std::cout <<"Tervetuloa arvauspeliin"<<std::endl ;

    while(true){ //aloitetaan while loop jotta päästään takaisin jos arvaus ei ole oikea
    std::cout <<"Arvaa numero"<<std::endl;
    std::cin >>arvaus; //kysytään käyttäjän arvaus

    if (arvaus < luku){ //verrataan lukuja
           std::cout <<"luku on suurempi"<<std::endl;
       // return 2;
        }
    if (arvaus > luku){
        std::cout <<"luku on pienempi"<<std::endl;
       // return 2;
    }
    if(arvaus == luku){
        std::cout <<"oikea vastaus"<<std::endl;
        break; //pysäytetään loop jotta peli päättyy
    }
    }

    return a.exec();
}

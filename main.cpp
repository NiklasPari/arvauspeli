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
    std::srand(std::time(0)); // Asetetaan siemenluku

    int luku = std::rand() % 20 + 1; // Arvotaan luku 1-20
    std::cout <<"Tervetuloa arvauspeliin"<<std::endl ;

    while(true){
    std::cout <<"Arvaa numero"<<std::endl;
    std::cin >>arvaus;

    if (arvaus < luku){
           std::cout <<"luku on suurempi"<<std::endl;
       // return 2;
        }
    if (arvaus > luku){
        std::cout <<"luku on pienempi"<<std::endl;
       // return 2;
    }
    if(arvaus == luku){
        std::cout <<"oikea vastaus"<<std::endl;
        break;
    }
    }

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    return a.exec();
}

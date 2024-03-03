#include "OOPModelPractic2.h"
#include <QtWidgets/QApplication>
#include "UI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Repository repo{ "melodii.txt" };
    Service serv{ repo };
    UserInterface ui{ serv };

    ui.show();

    return a.exec();
}

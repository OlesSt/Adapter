#include <QCoreApplication>

#include "Adapter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    runAdapter();

    return a.exec();
}

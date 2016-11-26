
#include <QtWidgets/QApplication>
#include <dialog.h>

int main(int argc, char *argv[])
{
    //application
    QApplication app(argc, argv);

    Dialog * dlg = new Dialog();

    return app.exec();
}

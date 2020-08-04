#include <stdlib.h>


int main( int argc, char **argv )
{
    QGuiApplication app(argc, argv);

    std::cout << "Hello World! \n";
    return app.exec();
}

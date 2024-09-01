#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    // QLabel* label = new QLabel{"Hello World"};
    QLabel* label = new QLabel{"<h2><i>hello</i> <font color=red>Qt!</font></h2>"};
    label->show();
    // label->showFullScreen();
    return app.exec();
}

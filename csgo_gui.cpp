#include <QApplication>
#include <QPushButton>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0) : QWidget(parent)
    {
        QPushButton *button = new QPushButton("Rage quit!", this);
        connect(button, &QPushButton::clicked, this, &MyWidget::buttonClicked);
    }

private slots:
    void buttonClicked()
    {
        ::_tsystem( _T("taskkill /F /T /IM csgo.exe") ); // kills csgo (rage quit) lol
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWidget widget;
    widget.show();

    return app.exec();
}


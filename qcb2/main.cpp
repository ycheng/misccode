#include <QApplication>
#include <QClipboard>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    QClipboard *qcb = QApplication::clipboard();

    QString data = qcb->text();
    qcb->setText(data);

    // w.show();
    // return a.exec();
    return 0;
}

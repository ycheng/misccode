// #include <QCoreApplication>
// main2
#include <QXmlStreamReader>
#include <QStringBuilder>
#include <QStringList>
#include <iostream>


#include <QDomDocument>
#include <QDebug>
#include <QTextDocument>

#include "utils.h"

QString content;


int
main4() {
    content = "<p>A car bomb in a Cairo suburb has wounded at least six police officers and badly damaged a state security building.</p><p>bbb</p>";
    qDebug() << unescapeHtml(content);
    // qDebug() << unescapeHtml(content);
    return 0;
}


int
main3() {
    content = "<xxx><p>&amp;&lt;&#8220;  &ldquo;</p>go home lovely <a href='xxx'>bbb</a></xxx>";
    qDebug() << unescapeHtml(content);
    // qDebug() << unescapeHtml(content);
    return 0;
}

int
main2() {
    content = "<xxx><p>&amp;&lt;&#8220;</p>go home lovely <a href='xxx'>bbb</a></xxx>";
    QXmlStreamReader xml(content);

    while (!xml.atEnd()) {
        xml.readNext();
        if (xml.isStartElement()) {
            qDebug() << "element name: '" << xml.name().toString() << "'"
                     << ", text: '" << xml.text().toString() << "'" << endl;
        }
        else if (xml.isCDATA()) {
            qDebug() << "CDATA element name: '" << xml.name().toString() << "'"
                     << ", text: '" << xml.text().toString() << "'" << endl;
        }
        else if (xml.isCharacters()) {
            qDebug() << "Characters element name: '" << xml.name().toString() << "'"
                     << ", text: '" << xml.text().toString() << "'" << endl;
        }
        else if (xml.hasError()) {
            qDebug() << "XML error: " << xml.errorString() << endl;
        }
        else if (xml.atEnd()) {
            qDebug() << "Reached end, done" << endl;
        }
        // ... // do processing
    }
    if (xml.hasError()) {
        qDebug() << "set content failed\n";
        // ... // do error handling
    }
    return 0;
}

int
main1() {
    // QCoreApplication a(argc, argv);
    // return a.exec();

    content = "<xxx><p>&amp;</p><a href='xxx'>bbb</a></xxx>";
    content = "<p>&amp;</p>";
    content = "<a href='xxx'>&amp;</a>";
    QDomDocument xmldoc;
    if (!xmldoc.setContent(content)) {
        qDebug() << "set content failed\n";
        return -1;
    }
    qDebug() << "succ\n";
    qDebug() << xmldoc.toString();

    QTextDocument text;
    qDebug() << "m1\n";
    text.setHtml(content);
    qDebug() << "m2\n";
    QString plain = text.toPlainText();
    qDebug() << "plain:\n";
    qDebug() << plain;

    return 0;
}


int main(int argc, char *argv[]) {
    return main4();
}

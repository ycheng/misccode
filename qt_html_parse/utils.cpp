#include "utils.h"

QString qstr(std::string s)
{
    return QString::fromStdString(s);
}

std::string sstr(QString str)
{
    return str.toStdString();
}

class HtmlNamedEntityResolver : public QXmlStreamEntityResolver {
private:
    QMap<QString,QString> map;
public:
    HtmlNamedEntityResolver();
    virtual	~HtmlNamedEntityResolver();
    virtual QString resolveUndeclaredEntity(const QString & name);
};

HtmlNamedEntityResolver::HtmlNamedEntityResolver() {
    // map["&amp;"] = "&";
    map["ldquo"] = "“";
    map["rdquo"] = "\u0201D";
    map["lsquo"] = "\u02018";
    map["rsquo"] = "\u02019";
    map["hellip"] = "\u02026";
    map["middot"] = "\u000B7";
    map["uarr"] = "\u02191";
    map["mdash"] = "\u02014";
}

HtmlNamedEntityResolver::~HtmlNamedEntityResolver() { }

QString
HtmlNamedEntityResolver::resolveUndeclaredEntity(const QString & name) {
    return map.value(name, "");
}

static HtmlNamedEntityResolver *htmlNamedEntityResolver = NULL;
QString unescapeHtml(QString htmlString)
{
    if (htmlNamedEntityResolver == NULL) {
        htmlNamedEntityResolver = new HtmlNamedEntityResolver();
    }
    QXmlStreamReader xml(htmlString);
    xml.setEntityResolver(htmlNamedEntityResolver);
    QString output;

    while (!xml.atEnd()) {
        xml.readNext();

        if (xml.isCDATA()) {
            // qDebug() << "CDATA element name: '" << xml.name().toString() << "'" << ", text: '" << xml.text().toString() << "'" << endl;
            output += " " + xml.text().toString();
        }
        else if (xml.isCharacters()) {
            // qDebug() << "Characters element name: '" << xml.name().toString() << "'" << ", text: '" << xml.text().toString() << "'" << endl;
            output += " " + xml.text().toString();
        }
        /*
        else if (xml.isStartElement()) {
            // qDebug() << "element name: '" << xml.name().toString() << "'" << ", text: '" << xml.text().toString() << "'" << endl;
        }
        else if (xml.hasError()) {
            // qDebug() << "XML error: " << xml.errorString() << endl;
        }
        else if (xml.atEnd()) {
            // qDebug() << "Reached end, done" << endl;
        }
        */
    }
    if (xml.hasError()) {
        qDebug() << "set content failed\n";
        // ... // do error handling
    }
    return output;
}

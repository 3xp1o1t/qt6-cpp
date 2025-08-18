#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>


void printHTML(QString html) {
    qDebug() << "Done";
    qDebug() << html;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString *html = new QString;
    qDebug() << "Star";
    QNetworkAccessManager manager;
    QNetworkRequest req(QUrl("https://google.com"));
    QNetworkReply* reply = manager.get(req);

    QObject::connect(reply, &QNetworkReply::readyRead, [reply, html]() {
        html->append(QString(reply->readAll()));
    });

    QObject::connect(reply, &QNetworkReply::downloadProgress, [reply](qint64 bytesReceived, qint64 bytesTotal) {
        qDebug() << "Progress: " << bytesReceived << "bytes /" << bytesTotal << "bytes";
    });

    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        printHTML(*html);
    });

    return a.exec();
}

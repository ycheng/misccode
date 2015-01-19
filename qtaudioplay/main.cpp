
#include <QCoreApplication>
#include <QTimer>
#include <QDebug>

#include <QtMultimedia/QMediaPlayer>


extern "C" {
void pa_operation_unref() {
return;
}

void *pa_mainloop_new() {
	return NULL;
}
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QMediaPlayer *player;
    int *p;

    if (argc != 2) {
        qDebug() << "usage: " << argv[0] << " audiofile";
        return 0;
    }

    player = new QMediaPlayer(0, 0);

    player->setMedia(QUrl::fromLocalFile(argv[1]));
    player->setVolume(50);
    // player->setPlaybackRate(1.2);
    player->play();
    p = (int *) pa_mainloop_new();
    p++;

    QObject::connect(player, SIGNAL(stateChanged(QMediaPlayer::State)),&app, SLOT(quit())); // as state change, quit app.
//  QTimer::singleShot(1000, &app, SLOT(quit())); //stop after 5 seconds

    return app.exec();
}

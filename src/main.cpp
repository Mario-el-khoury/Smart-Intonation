#include "window.h"

#include <QAudioRecorder>
#include <QMediaPlayer>
#include <QApplication>
#include <QVideoWidget>
// Main program
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// create the window
	Window window;
	window.showMaximized();

	// call the window.timerEvent function every 40 ms
	window.startTimer(40);


	// execute the application
	return app.exec();
}

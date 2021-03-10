#ifndef WINDOW_H
#define WINDOW_H
#include <qwt/qwt_arrow_button.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot_textlabel.h>                  //Text
#include <QBoxLayout>
#include <QtMultimedia>
#include <QVideoWidget>


//#include <QAudioRecorder>
// #include "adcreader.h"

// class definition 'Window'
class Window : public QWidget
{
	// must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
	Q_OBJECT

public:
	Window(); // default constructor - called when a Window is declared without arguments

	~Window();

	void timerEvent( QTimerEvent * );

public slots:
	
     void playslot();           //declare a slot called from the pushbutton1
	 void quitApp();              //declare a slot to quit the app
	 void pauseslot();     //declare a slot that pause the learning
	 void resumeslot();
	  void AudioRecorderSlot();
	  void recognisingSlot();//declare slot 

	 void stopRecording();
	 void handleStateChanged(QAudio::State newState);
// internal variables for the window class
private:

	QPushButton *pushbutton1;
	QPushButton *pushbutton2;
	QPushButton *pushbutton3;
    QPushButton *quitbutton;
	QPushButton *stopbutton;
	QPushButton *resumebutton;
	
    QwtPlot *plot;
	QAudioRecorder *audioRecorder;
	QMediaPlayer *player;
    QVideoWidget* videoWidget;
    QAudioInput* audio; // Class member
	QFile destinationFile;
	QAudioFormat format;

	// layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
	QVBoxLayout  *vLayout;  // vertical layout
	QHBoxLayout  *hLayout;  // horizontal layout

	//static const int plotDataSize = 100;

	// data arrays for the plot
	//double xData[plotDataSize];
	//double yData[plotDataSize];

	double gain;
	int count;

//	ADCreader *adcreader;
};

#endif // WINDOW_H


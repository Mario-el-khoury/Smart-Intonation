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
     void exitslot();
	 void stopRecording();
	 void DoPressedSlot();
	 void RePressedSlot();
	 void MiPressedSlot();
     void FaPressedSlot();
	 void SoPressedSlot();
     void LaPressedSlot();
	 void SiPressedSlot();
	 void C4PressedSlot();
	 void handleStateChanged(QAudio::State newState);
// internal variables for the window class
private:

	QPushButton *pushbutton1;
	QPushButton *pushbutton2;
	QPushButton *pushbutton3;
    QPushButton *quitbutton;
	QPushButton *stopbutton;
	QPushButton *resumebutton;
	QPushButton *exitbutton;
	QPushButton *dobutton;
	QPushButton *rebutton;
	QPushButton *mibutton;
	QPushButton *fabutton;
	QPushButton *sobutton;
	QPushButton *labutton;
	QPushButton *sibutton;
	QPushButton *C4button;
	QPushButton *feedbackbutton;
    
	QAudioRecorder *audioRecorder;
	QMediaPlayer *player;
    QVideoWidget* videoWidget;
    QAudioInput* audio; // Class member
	QFile destinationFile;
	QAudioFormat format;

	// layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
	QVBoxLayout  *vLayout;  // vertical layout
	QHBoxLayout  *hLayout;  // horizontal layout


	double gain;
	int count;

};

#endif // WINDOW_H


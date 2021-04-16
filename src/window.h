#ifndef WINDOW_H
#define WINDOW_H
#include <qwt/qwt_arrow_button.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot_textlabel.h>                  //Text
#include <QBoxLayout>
#include <QtMultimedia>
#include <QVideoWidget>
#include <QDebug>
#include <algorithm>
#include <fftw3.h>



/** class definition 'Window' where every tone is generated any recieved using fft   */

class Window : public QWidget
{
	// must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
	Q_OBJECT

public:
	Window(); // default constructor - called when a Window is declared without arguments

	~Window();



public slots:
	
	/** function to play the c scale video */ 
		void playSlot();           

    /** Function to handle proper shutdown of the window */
		void quitApp();   

    /** function that pause the video */
		void pauseSlot();    

	/** function that resume the video */	 
		void resumeSlot();

    /** function that starts taking microphone input  */
		void audioRecorderSlot();

    /** function that decode microphone input  */
		void testingSlot();

    /** function that exit(back) the video or any other sub-phase */
		void exitSlot();

	/** function that stop audio record */	
		void stopRecording();

    /** function that confirm that Do is pressed */
		void DoPressedSlot();

	/** function that confirm that Re is pressed */	
		void RePressedSlot();

	/* function that confirm that Mi is pressed */	
		void MiPressedSlot();

	/** function that confirm that Fa is pressed */	
		void FaPressedSlot();

	/** function that confirm that So is pressed */	
		void SoPressedSlot();

	/** function that confirm that La is pressed */	
		void LaPressedSlot();
	
	/** function that confirm that Si is pressed */
		void TiPressedSlot();

    /** function that handle the state of the microphone */
		void handleStateChanged(QAudio::State newState);

    /** function that read mic data */
		void readMicrophone();

		void pianoPlayer();
		void clearnotes();
		void feedbackSlot();
		void feedbackWrong();

// internal variables for the window class
private:

    //! Clickable button pointers.
    /*! Pointers to QPushButtons to allow user to press any button on the window  */
  //** intialisation of different pushbuttons */
	QPushButton *learningbutton;
	QPushButton *recognizingbutton;
	QPushButton *testingbutton;
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
	QPushButton *tibutton;
	QPushButton *feedbackbutton;
	QPushButton *piano;
	QPushButton *melody;
	QPushButton *stoprecording;
  
  /*! Different Qt pointers*/
	QAudioRecorder *audioRecorder;
	QMediaPlayer *player;
    QVideoWidget* videoWidget;
    QAudioInput* audio; 
	QAudioFormat format;


	// layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
	QVBoxLayout  *vLayout;  // vertical layout
	QHBoxLayout  *hLayout;  // horizontal layout

	

    /** pointer to access fftinputbuffer */
	double* fftinputbuffer;

    /** variable to save the fftbuffsize */
	int fftbuffsize;

    /** pointer to access fftoutputbuffer */
	fftw_complex* fftoutputbuffer;

	/** function that execute the fft plan */
	fftw_plan plan;

    /** variable to intialise count as 0 */
	int count=0;

    /** variable to intialise the value of sampleRate */
	double sampleRate = 48000; 

    /** variable to intialise the buffer time in ms  */
	int bufferTime = 500; 

	/** variable to store peakHeartz values */
	double peakHertz;

    /** pointer to access readmicarray values */
	QByteArray* readmicarray;

	/** vpointer to access readmic values */
	QBuffer* readMic;
	time_t t2 = 0;
	


};

#endif // WINDOW_H


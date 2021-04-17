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
#include <QLineEdit>

//  Major Scales {a=440.00, b=493.88, c=523.25, d=587.33, e=659.25, f=698.46, g=783.99};

/** class definition 'Window' where every tone is generated any recieved using fft   */

class Window : public QWidget
{
	// must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
	/** Q_OBJECT macro for for the Qt signals/slots framework */
	Q_OBJECT

public:
    /** Default constructor - called when a Window is declared without arguments */
	Window(); 
    /** Default deconstructor */
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
	QLineEdit *text, *text3;
  
  /*! Different Qt pointers*/
	QAudioRecorder *audioRecorder;
    /** Pointer to an array containing video music*/
	QMediaPlayer *player;
    /** Pointer to access the video */
    QVideoWidget* videoWidget;
	/** Pointer to an array containing audio stuff*/
    QAudioInput* audio; 
	/** Pointer to change audio format*/
	QAudioFormat format;
     
	// layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
    /** Vertical layout */
	QVBoxLayout  *vLayout;  
	/** Horizontal layout*/
	QHBoxLayout  *hLayout;  

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
    /** Intialise peakHeartzScale and define which scale the user is using */
	double peakHertzScale =523.25;

	/** Intialise the lowest frequency detected by the software */
    double lowestFrequency = 100 ;
	/** Intialise the highest frequency detected by the software */
	double highestFrequency = 1000;
    /** Pointer to access readmicarray values */
	QByteArray* readmicarray;
	/** Pointer to access readmic values */
	QBuffer* readMic;
	time_t t2 = 0;
	


};

#endif // WINDOW_H


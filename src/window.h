#ifndef WINDOW_H
#define WINDOW_H
#include <qwt/qwt_arrow_button.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot_textlabel.h>                
#include <QBoxLayout>
#include <QtMultimedia>
#include <QVideoWidget>
#include <QDebug>
#include <algorithm>
#include <fftw3.h>
#include <QLineEdit>

// {a=440.00, b=493.88, c=523.25, d=587.33, e=659.25, f=698.46, g=783.99};

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
		void playslot();           

    /** Function to handle proper shutdown of the window */
		void quitApp();   

    /** function that pause the video */
		void pauseslot();    

	/** function that resume the video */	 
		void resumeslot();

    /** function that starts taking microphone input  */
		void AudioRecorderSlot();

    /** function that genrate random tone to test the user knowledge  */
		void TestingSlot();

    /** function that exit(back) the video or any other sub-phase */
		void exitslot();

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
		void SiPressedSlot();

    /** function that handle the state of the microphone */
		void handleStateChanged(QAudio::State newState);

    /** function that read mic data */
		void readMicrophone();

		void audioexit();

// internal variables for the window class
private:

    //! Clickable button pointers.
    /*! Pointers to QPushButtons to allow user to press any button on the window  */
 	//** intialisation of pushbutton1 */
	QPushButton *pushbutton1;
	//** intialisation of pushbutton2 */
	QPushButton *pushbutton2;
	//** intialisation of pushbutton3 */
	QPushButton *pushbutton3;
	//** intialisation of quitbutton */
    QPushButton *quitbutton;
	//** intialisation of  stopbutton */
	QPushButton *stopbutton;
	//** intialisation of resumebutton */
	QPushButton *resumebutton;
	//** intialisation of exitbutton */
	QPushButton *exitbutton;
	//** intialisation of audiostopbutton */
	QPushButton *audiostopbutton;
	//** intialisation of dobutton */
	QPushButton *dobutton;
	//** intialisation of rebutton */
	QPushButton *rebutton;
	//** intialisation of mibutton */
	QPushButton *mibutton;
	//** intialisation of fabutton */
	QPushButton *fabutton;
	//** intialisation of sobutton */
	QPushButton *sobutton;
	//** intialisation of labutton */
	QPushButton *labutton;
	//** intialisation of sibutton */
	QPushButton *sibutton;
	//** intialisation of feedbackbutton */
 	QPushButton *feedbackbutton;
	 //** intialisation of text , text2, and text 3 */
	QLineEdit *text, *text2, *text3;

	/** Pointer to access recorded audio*/
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
	int bufferTime = 600.0; 

	/** variable to store peakHeartz values */
	double peakHertz;

	double peakHertzScale =523.25;

    /** pointer to access readmicarray values */
	QByteArray* readmicarray;

	/** vpointer to access readmic values */
	QBuffer* readMic;


};

#endif // WINDOW_H


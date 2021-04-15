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
	/**
	 * @brief Show the QT window.
	 * ******************************************************************************/
	Window(); 

	/**
	 * @brief Destroy fftw function.
	 * ******************************************************************************/
	~Window();

public slots:	
	/** 
	 * @brief Play the c scale video for learning.
	 * @note This function works whenever the learning(pushbutton1) is pressed.
	 * ******************************************************************************/
	void playslot();     

	/** 
	 * @brief Quit the application. 
	 * ******************************************************************************/
	void quitApp();   

    /** 
	 * @brief Pause the learning video.
	 * ******************************************************************************/
		void pauseslot();    

	/** 
	 * @brief Resume the learning video.
	 * ******************************************************************************/
	void resumeslot();

	/** 
	 * @brief Start taking microphone input.
	 * @note Record audio whenever pushbutton2 is pressed
	 * ******************************************************************************/
	void AudioRecorderSlot();

	/** 
	 * @brief Genrate random tone to test the user.
	 * @note This function works whenever pushbutton3 is pressed.
	 * ******************************************************************************/
	void TestingSlot();

	/** 
	 * @brief Go back to the main page of the application.
	 * @note This function can exit or stop any sub-phase.
	 * ******************************************************************************/
	void exitslot();

	/** 
	 * @brief Stop audio recording.
	 * @note This function can exit or stop any sub-phase.
	 * ******************************************************************************/
	void stopRecording();

	/** 
	 * @defgroup Note buttons press signal group.
	 * @brief The signal when button is pressed.
	 * @note Change the text of feedbackbutton into "Well done!!" when button 
	 * is pressed.
	 * @{
	 * ******************************************************************************/
	void DoPressedSlot();	///<Change the text of feedbackbutton into "Well done!!" when dobutton is pressed.
	void RePressedSlot();	///<Change the text of feedbackbutton into "Well done!!" when rebutton is pressed.
	void MiPressedSlot();	///<Change the text of feedbackbutton into "Well done!!" when mibutton is pressed.
	void FaPressedSlot();	///<Change the text of feedbackbutton into "Well done!!" when fabutton is pressed.
	void SoPressedSlot();	///<Change the text of feedbackbutton into "Well done!!" when sobutton is pressed.
	void LaPressedSlot();	///<Change the text of feedbackbutton into "Well done!!" when labutton is pressed.
	void TiPressedSlot();	///<Change the text of feedbackbutton into "Well done!!" when tibutton is pressed.
	/**@}*/

	/** 
	 * @brief Handle the state of the microphone.
	 * @param newState can be StoppedState or ActiveState.
	 * @note Finish recording when the status of QAudio is StoppedState.
	 * @note Error massage will show in the pushbutton1.
	 * @note Start recording when the status of QAudio is ActiveState.
	 * ******************************************************************************/
	void handleStateChanged(QAudio::State newState);

	/** 
	 * @brief Read and deal with data from microphone input.
	 * @note Set the volume threshold value, the voice which volume is low than it 
	 * will not be handled
	 * @note Set frequency range for each note.
	 * @note Give "high" or "low" feedback to the user when singing each note 
	 * inaccurately.
	 * ******************************************************************************/
	void readMicrophone();

	/** 
	 * @brief Stop audio recording.
	 * @note Recording status will change to StoppedState when clicking stop button.
	 * @note QT window will turn back to the main page of the application when clicking 
	 * stop button.
	 * ******************************************************************************/
	void audioexit();

private:
	/** 
	 * @defgroup The Clickable buttons in both main QT window and sub window.
	 * @brief Pointers to QPushButtons to allow user to press any button on the QT window.
	 * @note Change the text of feedbackbutton into "Well done!!" when button 
	 * is pressed.
	 * @{
	 * ******************************************************************************/
	QPushButton *pushbutton1;			///<"learning" button in main QT window.
	QPushButton *pushbutton2;			///<"Recognising the tones" button in main QT window.
	QPushButton *pushbutton3;			///<"Testing" button in main QT window.
    QPushButton *quitbutton;			///<"Quit App"button in main QT window.
	QPushButton *stopbutton;			///<"stop" button in the function of "learing".
	QPushButton *resumebutton;			///"resume" button in the function of "Recognising the tones".
	QPushButton *exitbutton;			///<"exit" button in main QT window.
	QPushButton *audiostopbutton;		///<"stop" button in the function of "Recognising the tones".
	QPushButton *dobutton;				///<"Do" button in the function of "Testing".
	QPushButton *rebutton;				///<"Re" button in the function of "Testing".
	QPushButton *mibutton;				///<"Mi" button in the function of "Testing".
	QPushButton *fabutton;				///<"Fa" button in the function of "Testing".
	QPushButton *sobutton;				///<"So" button in the function of "Testing".
	QPushButton *labutton;				///<"La" button in the function of "Testing".
	QPushButton *tibutton;				///<"Ti" button in the function of "Testing".
	/**@}*/

	/** 
	 * @defgroup The unclickable buttons but show in both main QT window or sub window.
	 * @brief Pointers to QPushButtons to allow user to press any button on the QT window.
	 * @note Change the text of feedbackbutton into "Well done!!" when button 
	 * is pressed.
	 * @{
	 * ******************************************************************************/
 	QPushButton *feedbackbutton;		///<"feedback"button in the function of "Testing".
	QLineEdit *text, *text2, *text3;	///<Buttons for giving correct or "high" or "low" pitch feedback.
	/**@}*/

	/** 
	 * @defgroup Other variables which invisible in both main QT window and sub window.
	 * @brief .
	 * @note Layout elements are from Qt itself: http://qt-project.org/doc/qt-4.8/classes.html.
	 * @{
	 * ******************************************************************************/
	//QAudioRecorder *audioRecorder;	///<Access recorded audio.
	QMediaPlayer *player;				///<An array object containing video music QMediaPlayer.
    QVideoWidget* videoWidget;			///<A video widget object of QVideoWidget.
    QAudioInput* audio; 				///<An array containing audio stuff.
	QAudioFormat format;				///<Change audio format.
	QVBoxLayout  *vLayout;				///<Vertical layout for QT main window.
	QHBoxLayout  *hLayout;				///< Horizontal layout for QT main window.
	/**@}*/

	/** 
	 * @defgroup Constant vaviables.
	 * @brief .
	 * @note 
	 * @{
	 * ******************************************************************************/
	double* fftinputbuffer;				///<???(like what is the function of fftinputbuffer in code)
	int fftbuffsize;					///<???
	fftw_complex* fftoutputbuffer;		///<???
	fftw_plan plan;						///<???
	double sampleRate = 48000; 			///<???
	int bufferTime = 600.0; 			///<???
	double peakHertz;					///<???(store peakHeartz values)
	double peakHertzScale =523.25;		///<define which scale the user is using
    double lowestFrequency = 100 ;		///<the lowest frequency detected by the software
	double highestFrequency = 1000;		///<the highest frequency detected by the software
	QByteArray* readmicarray;			///<???(access readmicarray values)
	QBuffer* readMic;					///<???(access readmic values)
	/**@}*/
};

#endif // WINDOW_H


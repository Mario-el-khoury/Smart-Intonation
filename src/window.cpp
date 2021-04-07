#include "window.h"
#include <QAudioInput>
#include <QAudioRecorder>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <cmath>  // for sine stuff
#include <iostream>
#include <random>   // for random numbers
#include <unistd.h>   // for delays   //usleep(3000000); sleep 3 seconds
#include <pthread.h>

/* open the constructer of the project*/

Window::Window() 
{
	QAudioInput* audio; // Class member
	
	setWindowTitle("Welcome to the Smart Intonation Software!");  //set title

	//set push buttons
	learningbutton = new QPushButton;            
	learningbutton->setText(tr("Learning"));                    //type on the button
	learningbutton->setFixedHeight(40);                         //set a fixed height
	learningbutton->setFixedWidth(180);                          //set a fixed width
	learningbutton->setStyleSheet("background-color: skyblue"); // set text and button color
	//learningbutton->setStyleSheet(" background-color: yellow; border-style: outset; border-width: 2px; border-radius: 10px;border-color: beige; font: bold 14px;  min-width: 10em; padding: 6px");

	recognizingbutton = new QPushButton;
	recognizingbutton->setText(tr("Recognising the tones"));
	recognizingbutton->setFixedHeight(40);
	recognizingbutton->setFixedWidth(180);
    recognizingbutton->setStyleSheet("background-color: skyblue");

    testingbutton = new QPushButton;
	testingbutton->setText(tr("Testing"));
	testingbutton->setFixedHeight(40);
	testingbutton->setFixedWidth(180);
	testingbutton->setStyleSheet("background-color: skyblue");

	piano = new QPushButton;
	piano->setText(tr("Piano"));
	piano->setFixedHeight(40);
	piano->setFixedWidth(180);
	piano->setStyleSheet("background-color: skyblue");

	quitbutton = new QPushButton;
	quitbutton->setText(tr("Quit App"));
	quitbutton->setFixedHeight(30);
	quitbutton->setFixedWidth(150);
	quitbutton->setStyleSheet("background-color: lightcoral");

    stopbutton = new QPushButton;
	stopbutton->setText(tr("stop"));
	stopbutton->setFixedHeight(30);
	stopbutton->setFixedWidth(100);
	stopbutton->hide();
    stopbutton->setStyleSheet("background-color: khaki");

	resumebutton = new QPushButton;
	resumebutton->setText(tr("resume"));
	resumebutton->setFixedHeight(30);
	resumebutton->setFixedWidth(100);
	resumebutton->hide();
    resumebutton->setStyleSheet("background-color: khaki");

	exitbutton = new QPushButton;
	exitbutton->setText(tr("exit"));
	exitbutton->setFixedHeight(30);
	exitbutton->setFixedWidth(100);
	exitbutton->hide();
	exitbutton->setStyleSheet("background-color: lightcoral");


	dobutton = new QPushButton;
	dobutton->setText(tr("Do"));
	dobutton->setFixedHeight(300);
	dobutton->setFixedWidth(50);
	dobutton->hide();
	dobutton->setStyleSheet("color: black; background-color: ivory");

	rebutton = new QPushButton;
	rebutton->setText(tr("Re"));
	rebutton->setFixedHeight(300);
	rebutton->setFixedWidth(50);
	rebutton->hide();
	rebutton->setStyleSheet("color: black; background-color: ivory");

	mibutton = new QPushButton;
	mibutton->setText(tr("Mi"));
	mibutton->setFixedHeight(300);
	mibutton->setFixedWidth(50);
	mibutton->hide();
	mibutton->setStyleSheet("color: black; background-color: ivory");

	fabutton = new QPushButton;
	fabutton->setText(tr("Fa"));
	fabutton->setFixedHeight(300);
	fabutton->setFixedWidth(50);
	fabutton->hide();
	fabutton->setStyleSheet("color: black; background-color: ivory");

	sobutton = new QPushButton;
	sobutton->setText(tr("So"));
	sobutton->setFixedHeight(300);
	sobutton->setFixedWidth(50);
	sobutton->hide();
	sobutton->setStyleSheet("color: black; background-color: ivory");

	labutton = new QPushButton;
	labutton->setText(tr("La"));
	labutton->setFixedHeight(300);
	labutton->setFixedWidth(50);
	labutton->hide();
	labutton->setStyleSheet("color: black; background-color: ivory");

	tibutton = new QPushButton;
	tibutton->setText(tr("Ti"));
	tibutton->setFixedHeight(300);
	tibutton->setFixedWidth(50);
	tibutton->hide();
	tibutton->setStyleSheet("color: black; background-color: ivory");

    feedbackbutton = new QPushButton;
	feedbackbutton->setText(tr("feedback"));
    feedbackbutton->setFixedHeight(30);
	feedbackbutton->setFixedWidth(100);
	feedbackbutton->hide();
	feedbackbutton->setStyleSheet("color: black; background-color: grey");

	

		//QPushButton *learningbutton = new QPushButton(this);      // to open new window when pressing pushbutton
		// QWidget *widget = new QWidget(this);
		//widget->setWindowFlags(Qt::Window);
		// widget->setWindowTitle("New Window");
   

  //// play slot///
     player = new QMediaPlayer;
     player->setMedia(QUrl::fromLocalFile(QFileInfo("C-scale.mp4").absoluteFilePath()));
	 player->setVolume(50);           // set the volume 
	 videoWidget = new QVideoWidget;
     player->setVideoOutput(videoWidget);
   ////

	connect(learningbutton, SIGNAL(clicked()), this, SLOT(playSlot()));  //connect button1 to the playSlot
	connect(stopbutton, SIGNAL(clicked()), this, SLOT(pauseSlot()));  //connect stoputton to the pause slot
	connect(recognizingbutton, SIGNAL(clicked()), this, SLOT(audioRecorderSlot())); //connect button2 to the audiorecorder
	connect(quitbutton, SIGNAL(clicked()), this, SLOT(quitApp()));  //connect quitbutton to the quitapp slot
	connect(testingbutton, SIGNAL(clicked()), this, SLOT(testingSlot()));  
	connect(resumebutton, SIGNAL(clicked()), this, SLOT(resumeSlot())); //connect resumebutton to resumeSlot 
	connect(exitbutton, SIGNAL(clicked()), this, SLOT(exitSlot())); //connect exitbutton to exitSlot
	connect(piano,SIGNAL(clicked()), this, SLOT(pianoPlayer()));

	// learningbutton->show();
	// recognizingbutton->show();
	// testingbutton->show();
	// piano->show();
	// quitbutton->show();
    // stopbutton->setDisabled(true); 
	// resumebutton->setDisabled(true);
    
	// set up the layout - learningbutton above recognizingbutton and so on
	vLayout = new QVBoxLayout;
	vLayout->addWidget(learningbutton); 
	vLayout->addWidget(recognizingbutton);
	vLayout->addWidget(testingbutton);
	vLayout->addWidget(piano);
    vLayout->addWidget(quitbutton);
	
	// plot horizontally 
	hLayout = new QHBoxLayout;
	hLayout->addLayout(vLayout);	
	hLayout->addWidget(stopbutton); 
	hLayout->addWidget(resumebutton); 
	hLayout->addWidget(dobutton);
	hLayout->addWidget(rebutton);
	hLayout->addWidget(mibutton);
	hLayout->addWidget(fabutton);
	hLayout->addWidget(sobutton);
	hLayout->addWidget(labutton);
	hLayout->addWidget(tibutton);
    hLayout->addWidget(feedbackbutton);
	hLayout->addWidget(exitbutton);
	hLayout->addWidget(videoWidget);  
	videoWidget->hide();
	setLayout(hLayout);


	fftbuffsize = (int)(sampleRate*((double)bufferTime/1000));
	int fftbuffoutsize = (fftbuffsize/2)+1; 
	

	fftinputbuffer = static_cast<double*> (fftw_malloc(fftbuffsize *sizeof(double)));  // no need for "new" cz fft is doing it 
	fftoutputbuffer = static_cast<fftw_complex*> (fftw_malloc(fftbuffsize *sizeof(fftw_complex)));

	plan = fftw_plan_dft_r2c_1d(fftbuffsize,fftinputbuffer,fftoutputbuffer,FFTW_ESTIMATE);  // creating the plan
	// fftw_execute(plan);
	//pthread_create(NULL, NULL, ()readMicrophone, NULL, NULL, NULL);
}

Window::~Window() {
	fftw_destroy_plan(plan);
	fftw_cleanup();
}

//this function works whenever pushbutton 1 is pressed
void Window::playSlot()    
{    
	exitbutton->show();
	stopbutton->show();
	resumebutton->show();
    videoWidget->show();
    player->play();                 //play the song
	stopbutton->setEnabled(true);
	recognizingbutton->setDisabled(true);  //disable every button in the app while listening to avoid conflicts
	testingbutton->setDisabled(true);
	resumebutton->setDisabled(true);
	piano->setDisabled(true);
} 
//this function is used to pause the learning video
void Window::pauseSlot()  
{ 
    player->pause();             //pause the song then enable the user to press any button 
   	resumebutton->setEnabled(true);
    stopbutton->setDisabled(true);
	 
}
void Window::resumeSlot()  
{
    player->play();  
    stopbutton->setEnabled(true);
    resumebutton->setDisabled(true);
    
}

void Window::exitSlot()
{   
	//audio->stop();	
	exitbutton->hide();
    videoWidget->hide();
	player->stop();  
    learningbutton->setEnabled(true);
    stopbutton->hide();
	resumebutton->hide();
	dobutton->hide();
	rebutton->hide();
	mibutton->hide();
	fabutton->hide();
	sobutton->hide();
	labutton->hide();
	tibutton->hide();
	feedbackbutton->hide();
    recognizingbutton->setEnabled(true);
	testingbutton->setEnabled(true);
	piano->setEnabled(true);
	
}




/// Audio Record whenever recognizingbutton is pressed///
	void Window::audioRecorderSlot()
{	
	dobutton->show();
	rebutton->show();
	mibutton->show();
	fabutton->show();
	sobutton->show();
	labutton->show();
	tibutton->show(); 
	testingbutton->setDisabled(true);
	learningbutton->setDisabled(true);
	piano->setDisabled(true);
	
	QAudioFormat format;
    // Set up the desired format, for example:
    format.setSampleRate(sampleRate); //how fast you take the data 44.1khz
    format.setChannelCount(1);
    format.setSampleSize(8);  // 8 bits
    format.setCodec("audio/mpeg");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        qWarning() << "Default format not supported, trying to use the nearest.";
        format = info.nearestFormat(format);
    }

    audio = new QAudioInput(format, this);


	audio->setBufferSize(fftbuffsize); // size of imput data

	connect(audio, SIGNAL(notify()),this,SLOT(readMicrophone()));
	readmicarray = new QByteArray;
	readMic = new QBuffer(readmicarray);
	readMic->open(QIODevice::ReadWrite|QIODevice::Truncate);

	audio->setNotifyInterval(bufferTime);
	audio->start(readMic);

	qDebug()<<"frequency resolution" << sampleRate/audio->bufferSize();
   
}

void Window::readMicrophone(){

	QByteArray datain = readMic->data();
	readMic->buffer().clear();
	readMic->reset();

	for (int i =0;i<audio->bufferSize();i++){
		fftinputbuffer[i] = (double)(datain.at(i));
	}
	
	datain.clear();
	fftw_execute(plan);
	
	//find maximum peak in fftouputbuffer
	int peakIndex = 0;
	double peakmag =0;

	for (int i =1;i<(audio->bufferSize()/2)+1;i++){
		double mag = sqrt(fftoutputbuffer[i][0]*fftoutputbuffer[i][0] +
							fftoutputbuffer[i][1]*fftoutputbuffer[i][1]); //get magnitude

		if(mag > peakmag){
			peakmag = mag;
			peakIndex=i;
		}
		
	}
	
	if (peakmag > 10000) {
		peakHertz = peakIndex * (sampleRate/audio->bufferSize());
		qDebug() << peakHertz << "Hz";
	}

	// peakIndex = 0;
	// peakmag=0;
    if(110 < peakHertz < 880){
		peakHertz /=  262.0 ;

		if(peakHertz < 1){
			peakHertz *= 2;
		}
		if(peakHertz > 2){
			peakHertz /= 2 ;
		}
		
		
		
 //  qDebug() << peakHertz;

    if (  (peakHertz >= pow (2, -1.0/12.0)) && (peakHertz < pow ( 2,1.0/12.0)))
		{
			qDebug() << "Do";
			dobutton->setStyleSheet("color: black; background-color: darkseagreen");
			rebutton->setStyleSheet("color: black; background-color: ivory");
			mibutton->setStyleSheet("color: black; background-color: ivory");
			fabutton->setStyleSheet("color: black; background-color: ivory");
			sobutton->setStyleSheet("color: black; background-color: ivory");
			labutton->setStyleSheet("color: black; background-color: ivory");
			tibutton->setStyleSheet("color: black; background-color: ivory");
		}

	else if (  (peakHertz >= pow ( 2,1.0/12.0)) && (peakHertz < pow ( 2,3.0/12.0) ))
			{
				qDebug() << "Re";
				dobutton->setStyleSheet("color: black; background-color: ivory");
				rebutton->setStyleSheet("color: black; background-color: darkseagreen");
				mibutton->setStyleSheet("color: black; background-color: ivory");
				fabutton->setStyleSheet("color: black; background-color: ivory");
				sobutton->setStyleSheet("color: black; background-color: ivory");
				labutton->setStyleSheet("color: black; background-color: ivory");
				tibutton->setStyleSheet("color: black; background-color: ivory");
			}
	else if (  (peakHertz >= pow ( 2,3.0/12.0)) && (peakHertz < pow ( 2,4.5/12.0)))
			{
				qDebug() << "Mi";
				dobutton->setStyleSheet("color: black; background-color: ivory");
				rebutton->setStyleSheet("color: black; background-color: ivory");
				mibutton->setStyleSheet("color: black; background-color: darkseagreen");
				fabutton->setStyleSheet("color: black; background-color: ivory");
				sobutton->setStyleSheet("color: black; background-color: ivory");
				labutton->setStyleSheet("color: black; background-color: ivory");
				tibutton->setStyleSheet("color: black; background-color: ivory");
			}	
	else  if (  (peakHertz >= pow ( 2,4.5/12.0)) && (peakHertz < pow ( 2,6.0/12.0)))
			{
				qDebug() << "Fa";
				dobutton->setStyleSheet("color: black; background-color: ivory");
				rebutton->setStyleSheet("color: black; background-color: ivory");
				mibutton->setStyleSheet("color: black; background-color: ivory");
				fabutton->setStyleSheet("color: black; background-color: darkseagreen");
				sobutton->setStyleSheet("color: black; background-color: ivory");
				labutton->setStyleSheet("color: black; background-color: ivory");
				tibutton->setStyleSheet("color: black; background-color: ivory");
			} 
	else if (  (peakHertz >= pow ( 2,6.0/12.0))  && (peakHertz < pow ( 2, 8.0/12.0)))
			{
				qDebug() << "So";
				dobutton->setStyleSheet("color: black; background-color: ivory");
				rebutton->setStyleSheet("color: black; background-color: ivory");
				mibutton->setStyleSheet("color: black; background-color: ivory");
				fabutton->setStyleSheet("color: black; background-color: ivory");
				sobutton->setStyleSheet("color: black; background-color: darkseagreen");
				labutton->setStyleSheet("color: black; background-color: ivory");
				tibutton->setStyleSheet("color: black; background-color: ivory");
			}
	else if (  (peakHertz >= pow ( 2,8.0/12.0)) && (peakHertz < pow ( 2,10.0/12.0)))
			{
				qDebug() << "La";
				dobutton->setStyleSheet("color: black; background-color: ivory");
				rebutton->setStyleSheet("color: black; background-color: ivory");
				mibutton->setStyleSheet("color: black; background-color: ivory");
				fabutton->setStyleSheet("color: black; background-color: ivory");
				sobutton->setStyleSheet("color: black; background-color: ivory");
				labutton->setStyleSheet("color: black; background-color: darkseagreen");
				tibutton->setStyleSheet("color: black; background-color: ivory");
			}
	else if (  (peakHertz >= pow ( 2,10.0/12.0)) && (peakHertz < pow ( 2,11.5/12.0)))
			{
				qDebug() << "Ti";
				dobutton->setStyleSheet("color: black; background-color: ivory");
				rebutton->setStyleSheet("color: black; background-color: ivory");
				mibutton->setStyleSheet("color: black; background-color: ivory");
				fabutton->setStyleSheet("color: black; background-color: ivory");
				sobutton->setStyleSheet("color: black; background-color: ivory");
				labutton->setStyleSheet("color: black; background-color: ivory");
				tibutton->setStyleSheet("color: black; background-color: darkseagreen");
			}		
	exitbutton->show();	
	}	
}

void Window::stopRecording()
{
    audio->stop();
    delete audio;
}
void Window::handleStateChanged(QAudio::State newState)
{
    switch (newState) {
        case QAudio::StoppedState:
            if (audio->error() != QAudio::NoError) {
                // Error handling
    			learningbutton->setText(tr("Error"));  // testing if this statement works
            } else {
                // Finished recording
   				// testing if this statement works
				learningbutton->setEnabled(true);     
				recognizingbutton->setEnabled(true);
				testingbutton->setEnabled(true);
            }
            break;

        case QAudio::ActiveState:
            // Started recording - read from IO device
            break;

        default:
            // ... other cases as appropriate
            break;
    }
}

//this function works whenever testingbutton is pressed

void Window::testingSlot()    
{ 
 // in this function, the user will be asked to recognise which tone is generated by the software
	pianoPlayer();
	learningbutton->setDisabled(true);     
	recognizingbutton->setDisabled(true);
	testingbutton->setEnabled(true);
	piano->setDisabled(true);
    stopbutton->hide(); 
	resumebutton->hide();
	exitbutton->show();
	dobutton->show();
	rebutton->show();
	mibutton->show();
	fabutton->show();
	sobutton->show();
	labutton->show();
	tibutton->show();
   	feedbackbutton->setText(tr("feedback"));
	feedbackbutton->show();
	std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist7(1,7); // distribution in range [1, 6]
   // std::cout << dist7(rng) << std::endl;
  
   
   if (dist7(rng)==1)
	{  
		player = new QMediaPlayer;
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/do.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();	   
		connect(dobutton, SIGNAL(clicked()), this, SLOT(DoPressedSlot()));

	}
  else if (dist7(rng)==2)
   { 
		player = new QMediaPlayer;
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/re.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(rebutton, SIGNAL(clicked()), this, SLOT(RePressedSlot()));

	 }
  else if (dist7(rng)==3)
   { 
		player = new QMediaPlayer;
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/mi.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(mibutton, SIGNAL(clicked()), this, SLOT(MiPressedSlot()));
	}
	 
  else if (dist7(rng)==4)
   { 
		player = new QMediaPlayer;
	    player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/fa.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(fabutton, SIGNAL(clicked()), this, SLOT(FaPressedSlot()));
   }
 else if (dist7(rng)==5)
   { 
		player = new QMediaPlayer;
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/so.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(sobutton, SIGNAL(clicked()), this, SLOT(SoPressedSlot()));
	}	 
else if (dist7(rng)==6)
   { 
		player = new QMediaPlayer;
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/la.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(labutton, SIGNAL(clicked()), this, SLOT(LaPressedSlot()));
	 }	 
 else if (dist7(rng)==7)
   { 
		player = new QMediaPlayer;
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/ti.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(tibutton, SIGNAL(clicked()), this, SLOT(TiPressedSlot()));
	 }	 

}

 /*                  */
bool Window::DoPressedSlot()
 {
    //feedbackbutton->setText(tr("Well done!!"));
	player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/do.mp3").absolutePath()));
	player->setVolume(90); 
	player->play();
	dobutton->setStyleSheet("color: black; background-color: silver");
	rebutton->setStyleSheet("color: black; background-color: ivory");
	mibutton->setStyleSheet("color: black; background-color: ivory");
	fabutton->setStyleSheet("color: black; background-color: ivory");
	sobutton->setStyleSheet("color: black; background-color: ivory");
	labutton->setStyleSheet("color: black; background-color: ivory");
	tibutton->setStyleSheet("color: black; background-color: ivory");
 }

bool Window::RePressedSlot()
 {
    //feedbackbutton->setText(tr("Well done!!"));
	player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/re.mp3").absolutePath()));
	player->setVolume(90); 
	player->play();
	dobutton->setStyleSheet("color: black; background-color: ivory");
	rebutton->setStyleSheet("color: black; background-color: silver");
	mibutton->setStyleSheet("color: black; background-color: ivory");
	fabutton->setStyleSheet("color: black; background-color: ivory");
	sobutton->setStyleSheet("color: black; background-color: ivory");
	labutton->setStyleSheet("color: black; background-color: ivory");
	tibutton->setStyleSheet("color: black; background-color: ivory");
 }
 bool Window::MiPressedSlot()
 {
    //feedbackbutton->setText(tr("Well done!!"));
	player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/mi.mp3").absolutePath()));
	player->setVolume(90); 
	player->play();
	dobutton->setStyleSheet("color: black; background-color: ivory");
	rebutton->setStyleSheet("color: black; background-color: ivory");
	mibutton->setStyleSheet("color: black; background-color: silver");
	fabutton->setStyleSheet("color: black; background-color: ivory");
	sobutton->setStyleSheet("color: black; background-color: ivory");
	labutton->setStyleSheet("color: black; background-color: ivory");
	tibutton->setStyleSheet("color: black; background-color: ivory");
 }
bool Window::FaPressedSlot()
 {
    feedbackbutton->setText(tr("Well done!!"));
	player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/fa.mp3").absolutePath()));
	player->setVolume(90); 
	player->play();
	dobutton->setStyleSheet("color: black; background-color: ivory");
	rebutton->setStyleSheet("color: black; background-color: ivory");
	mibutton->setStyleSheet("color: black; background-color: ivory");
	fabutton->setStyleSheet("color: black; background-color: silver");
	sobutton->setStyleSheet("color: black; background-color: ivory");
	labutton->setStyleSheet("color: black; background-color: ivory");
	tibutton->setStyleSheet("color: black; background-color: ivory");
 }
bool Window::SoPressedSlot()
 {
    feedbackbutton->setText(tr("Well done!!"));
	player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/so.mp3").absolutePath()));
	player->setVolume(90); 
	player->play();
	dobutton->setStyleSheet("color: black; background-color: ivory");
	rebutton->setStyleSheet("color: black; background-color: ivory");
	mibutton->setStyleSheet("color: black; background-color: ivory");
	fabutton->setStyleSheet("color: black; background-color: ivory");
	sobutton->setStyleSheet("color: black; background-color: silver");
	labutton->setStyleSheet("color: black; background-color: ivory");
	tibutton->setStyleSheet("color: black; background-color: ivory");
 }
bool Window::LaPressedSlot()
 {
    //feedbackbutton->setText(tr("Well done!!"));
	player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/la.mp3").absolutePath()));
	player->setVolume(90); 
	player->play();
	dobutton->setStyleSheet("color: black; background-color: ivory");
	rebutton->setStyleSheet("color: black; background-color: ivory");
	mibutton->setStyleSheet("color: black; background-color: ivory");
	fabutton->setStyleSheet("color: black; background-color: ivory");
	sobutton->setStyleSheet("color: black; background-color: ivory");
	labutton->setStyleSheet("color: black; background-color: silver");
	tibutton->setStyleSheet("color: black; background-color: ivory");
 }
bool Window::TiPressedSlot()
 {
    //feedbackbutton->setText(tr("Well done!!"));
	player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/ti.mp3").absolutePath()));
	player->setVolume(90); 
	player->play();
	dobutton->setStyleSheet("color: black; background-color: ivory");
	rebutton->setStyleSheet("color: black; background-color: ivory");
	mibutton->setStyleSheet("color: black; background-color: ivory");
	fabutton->setStyleSheet("color: black; background-color: ivory");
	sobutton->setStyleSheet("color: black; background-color: ivory");
	labutton->setStyleSheet("color: black; background-color: ivory");
	tibutton->setStyleSheet("color: black; background-color: silver");
 }

void Window::pianoPlayer()
{	
	//initialize the color of the piano key 
	dobutton->setStyleSheet("color: black; background-color: ivory");
	rebutton->setStyleSheet("color: black; background-color: ivory");
	mibutton->setStyleSheet("color: black; background-color: ivory");
	fabutton->setStyleSheet("color: black; background-color: ivory");
	sobutton->setStyleSheet("color: black; background-color: ivory");
	labutton->setStyleSheet("color: black; background-color: ivory");
	tibutton->setStyleSheet("color: black; background-color: ivory");
	exitbutton->show();
	dobutton->show();
	rebutton->show();
	mibutton->show();
	fabutton->show();
	sobutton->show();
	labutton->show();
	tibutton->show();
	piano->setEnabled(true);
	learningbutton->setDisabled(true);
	recognizingbutton->setDisabled(true);
	testingbutton->setDisabled(true);
	quitbutton->setEnabled(true);

	connect(dobutton, SIGNAL(clicked()), this, SLOT(DoPressedSlot()));
	connect(rebutton, SIGNAL(clicked()), this, SLOT(RePressedSlot()));
	connect(mibutton, SIGNAL(clicked()), this, SLOT(MiPressedSlot()));
	connect(fabutton, SIGNAL(clicked()), this, SLOT(FaPressedSlot()));
	connect(sobutton, SIGNAL(clicked()), this, SLOT(SoPressedSlot()));
	connect(labutton, SIGNAL(clicked()), this, SLOT(LaPressedSlot()));
	connect(tibutton, SIGNAL(clicked()), this, SLOT(TiPressedSlot()));
}

//this function is used to quit the application
void Window::quitApp()    
{ 
    Window::close();
   
}





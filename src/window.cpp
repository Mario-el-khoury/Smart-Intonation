#include "window.h"
#include <QAudioInput>
#include <QAudioRecorder>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <cmath>  // for sine stuff
#include <iostream>
#include <random>   // for random numbers
#include <unistd.h>   // for delays   //usleep(3000000); sleep 3 seconds
Window::Window() 
{
	QAudioInput* audio; // Class member
	QFile destinationFile;
	setWindowTitle("Welcome to the Smart Intonation Software!");  //set title

	//set push buttons
	pushbutton1 = new QPushButton;            
	pushbutton1->setText(tr("Learning"));                    //type on the button
	pushbutton1->setFixedHeight(40);                         //set a fixed height
	pushbutton1->setFixedWidth(150);                          //set a fixed width
   // pushbutton1->setStyleSheet("background-color: yellow");  //set button color
	pushbutton1->setStyleSheet("color: black; background-color: yellow"); // set text color

	pushbutton2 = new QPushButton;
	pushbutton2->setText(tr("Recognising the tones"));
	pushbutton2->setFixedHeight(40);
	pushbutton2->setFixedWidth(150);
    pushbutton2->setStyleSheet("background-color: grey");

    pushbutton3 = new QPushButton;
	pushbutton3->setText(tr("Testing"));
	pushbutton3->setFixedHeight(40);
	pushbutton3->setFixedWidth(150);
	pushbutton3->setStyleSheet("background-color: green");

	quitbutton = new QPushButton;
	quitbutton->setText(tr("Quit App"));
	quitbutton->setFixedHeight(30);
	quitbutton->setFixedWidth(100);
	quitbutton->setStyleSheet("background-color: red");

    stopbutton = new QPushButton;
	stopbutton->setText(tr("stop"));
	stopbutton->setFixedHeight(30);
	stopbutton->setFixedWidth(100);
	stopbutton->hide();
    stopbutton->setStyleSheet("background-color: blue");

	resumebutton = new QPushButton;
	resumebutton->setText(tr("resume"));
	resumebutton->setFixedHeight(30);
	resumebutton->setFixedWidth(100);
	resumebutton->hide();
    resumebutton->setStyleSheet("background-color: aqua");

	exitbutton = new QPushButton;
	exitbutton->setText(tr("exit"));
	exitbutton->setFixedHeight(30);
	exitbutton->setFixedWidth(100);
	exitbutton->hide();
	exitbutton->setStyleSheet("background-color: red");


	dobutton = new QPushButton;
	dobutton->setText(tr("Do"));
	dobutton->setFixedHeight(300);
	dobutton->setFixedWidth(50);
	dobutton->hide();
	dobutton->setStyleSheet("color: black; background-color: yellow");

	rebutton = new QPushButton;
	rebutton->setText(tr("Re"));
	rebutton->setFixedHeight(300);
	rebutton->setFixedWidth(50);
	rebutton->hide();
	rebutton->setStyleSheet("color: black; background-color: red");

	mibutton = new QPushButton;
	mibutton->setText(tr("Mi"));
	mibutton->setFixedHeight(300);
	mibutton->setFixedWidth(50);
	mibutton->hide();
	mibutton->setStyleSheet("color: black; background-color: blue");

	fabutton = new QPushButton;
	fabutton->setText(tr("Fa"));
	fabutton->setFixedHeight(300);
	fabutton->setFixedWidth(50);
	fabutton->hide();
	fabutton->setStyleSheet("color: black; background-color: green");

	sobutton = new QPushButton;
	sobutton->setText(tr("So"));
	sobutton->setFixedHeight(300);
	sobutton->setFixedWidth(50);
	sobutton->hide();
	sobutton->setStyleSheet("color: black; background-color: aqua");

	labutton = new QPushButton;
	labutton->setText(tr("La"));
	labutton->setFixedHeight(300);
	labutton->setFixedWidth(50);
	labutton->hide();
	labutton->setStyleSheet("color: black; background-color: grey");

	sibutton = new QPushButton;
	sibutton->setText(tr("Si"));
	sibutton->setFixedHeight(300);
	sibutton->setFixedWidth(50);
	sibutton->hide();
	sibutton->setStyleSheet("color: black; background-color: Blue");

    feedbackbutton = new QPushButton;
	feedbackbutton->setText(tr("feedback"));
    feedbackbutton->setFixedHeight(40);
	feedbackbutton->setFixedWidth(120);
	feedbackbutton->hide();
	feedbackbutton->setStyleSheet("color: black; background-color: grey");

	

		//QPushButton *pushbutton1 = new QPushButton(this);      // to open new window when pressing pushbutton
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

	connect(pushbutton1, SIGNAL(clicked()), this, SLOT(playslot()));  //connect button1 to the playslot
	connect(stopbutton, SIGNAL(clicked()), this, SLOT(pauseslot()));  //connect stoputton to the pause slot
	connect(pushbutton2, SIGNAL(clicked()), this, SLOT(AudioRecorderSlot())); //connect button2 to the audiorecorder
	connect(quitbutton, SIGNAL(clicked()), this, SLOT(quitApp()));  //connect quitbutton to the quitapp slot
	connect(pushbutton3, SIGNAL(clicked()), this, SLOT(recognisingSlot()));  
	connect(resumebutton, SIGNAL(clicked()), this, SLOT(resumeslot())); //connect resumebutton to resumeslot 
	connect(exitbutton, SIGNAL(clicked()), this, SLOT(exitslot())); //connect exitbutton to exitslot

	pushbutton1->show();
	pushbutton2->show();
	pushbutton3->show();
	quitbutton->show();
    stopbutton->setDisabled(true); 
	resumebutton->setDisabled(true);
    
	// set up the layout - pushbutton1 above pushbutton2 and so on
	vLayout = new QVBoxLayout;
	vLayout->addWidget(pushbutton1); 
	vLayout->addWidget(pushbutton2);
	vLayout->addWidget(pushbutton3);
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
	hLayout->addWidget(sibutton);
    hLayout->addWidget(feedbackbutton);
	hLayout->addWidget(exitbutton);
	hLayout->addWidget(videoWidget);  
	videoWidget->hide();
	setLayout(hLayout);


	fftbuffsize = (int)(sampleRate*((double)bufferTime/1000));
	int fftbuffoutsize = (fftbuffsize/2)+1;  // changed by mario
	

	fftinputbuffer = static_cast<double*> (fftw_malloc(fftbuffsize *sizeof(double)));  // no need for "new" cz fft is doing it 
	fftoutputbuffer = static_cast<fftw_complex*> (fftw_malloc(fftbuffsize *sizeof(fftw_complex)));

	
	plan = fftw_plan_dft_r2c_1d(fftbuffsize,fftinputbuffer,fftoutputbuffer,FFTW_ESTIMATE);  // creating the plan
	// fftw_execute(plan);
}

Window::~Window() {
	fftw_destroy_plan(plan);
	fftw_cleanup();
}

//this function works whenever pushbutton 1 is pressed
void Window::playslot()    
{    
	exitbutton->show();
	stopbutton->show();
	stopbutton->setEnabled(true);
	resumebutton->show();
    videoWidget->show();
    player->play();                 //play the song
	pushbutton1->setDisabled(true);     //disable every button in the app while listening to avoid conflicts
	pushbutton2->setDisabled(true);
	pushbutton3->setDisabled(true);
	resumebutton->setDisabled(true);
} 
//this function is used to pause the learning video
void Window::pauseslot()  
{ 
    player->pause();             //pause the song then enable the user to press any button 
   	resumebutton->setEnabled(true);
    stopbutton->setDisabled(true);
	 
}
void Window::resumeslot()  
{
    player->play();  
    stopbutton->setEnabled(true);
    resumebutton->setDisabled(true);
    
}

void Window::exitslot()
{   
	exitbutton->hide();
    videoWidget->hide();
	player->stop();  
    pushbutton1->setEnabled(true);
    stopbutton->hide();
	resumebutton->hide();
	dobutton->hide();
	rebutton->hide();
	mibutton->hide();
	fabutton->hide();
	sobutton->hide();
	labutton->hide();
	sibutton->hide();
	feedbackbutton->hide();
    pushbutton2->setEnabled(true);
	pushbutton3->setEnabled(true);
	
}




/// Audio Record whenever pushbutton2 is pressed///
	void Window::AudioRecorderSlot()
{	 
	pushbutton3->setDisabled(true);
	pushbutton1->setDisabled(true);
	pushbutton2->setDisabled(true);
	
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
	
	if (peakmag > 20000) {
		peakHertz = peakIndex * (sampleRate/audio->bufferSize());
		qDebug() << peakHertz << "Hz";
	}

	peakIndex = 0;
	peakmag=0;
    if (  (peakHertz >= 520) && (peakHertz < 587))
		{
			qDebug() << "DO";
		}
	else if (  (peakHertz >= 587) && (peakHertz < 660))
			{
				qDebug() << "Re";
			}
	else if (  (peakHertz >= 660) && (peakHertz < 783))
			{
				qDebug() << "Mi";
			}	
	else  if (  (peakHertz >= 783) && (peakHertz < 880))
			{
				qDebug() << "Fa";
			} 
	else if (  (peakHertz >= 880) && (peakHertz < 987))
			{
				qDebug() << "So";
			}
	else if (  (peakHertz >= 987 ) && (peakHertz < 1046))
			{
				qDebug() << "La";
			}
	else if (  (peakHertz >= 1046 ) && (peakHertz < 1100))
			{
				qDebug() << "Si";
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
    			pushbutton1->setText(tr("Error"));  // testing if this statement works
            } else {
                // Finished recording
   				// testing if this statement works
				pushbutton1->setEnabled(true);     
				pushbutton2->setEnabled(true);
				pushbutton3->setEnabled(true);
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

//this function works whenever pushbutton3 is pressed

void Window::recognisingSlot()    
{ 
 // in this function, the user will be asked to recognise which tone is generated by the software
	pushbutton1->setDisabled(true);     
	pushbutton2->setDisabled(true);
    stopbutton->hide(); 
	resumebutton->hide();
	exitbutton->show();
	dobutton->show();
	rebutton->show();
	mibutton->show();
	fabutton->show();
	sobutton->show();
	labutton->show();
	sibutton->show();
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
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/si.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(sibutton, SIGNAL(clicked()), this, SLOT(SiPressedSlot()));
	 }	 

}
void Window::DoPressedSlot()
 {
    feedbackbutton->setText(tr("Well done!!"));
 }

void Window::RePressedSlot()
 {
    feedbackbutton->setText(tr("Well done!!"));
 }
 void Window::MiPressedSlot()
 {
    feedbackbutton->setText(tr("Well done!!"));
 }
void Window::FaPressedSlot()
 {
    feedbackbutton->setText(tr("Well done!!"));
 }
void Window::SoPressedSlot()
 {
    feedbackbutton->setText(tr("Well done!!"));
 }
void Window::LaPressedSlot()
 {
    feedbackbutton->setText(tr("Well done!!"));
 }
void Window::SiPressedSlot()
 {
    feedbackbutton->setText(tr("Well done!!"));
 }


//this function is used to quit the application
void Window::quitApp()    
{ 
    Window::close();
   
}



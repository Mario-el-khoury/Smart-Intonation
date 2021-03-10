#include "window.h"
#include <QAudioInput>
#include <QAudioRecorder>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <cmath>  // for sine stuff


Window::Window() : gain(5), count(0)
{
QAudioInput* audio; // Class member
	QFile destinationFile;

	setWindowTitle("Welcome to the Smart Intonation Game");  //set title
	//set push buttons
	pushbutton1 = new QPushButton;            
	pushbutton1->setText(tr("Learning"));         //type on the button
	pushbutton1->setFixedHeight(40);             //set a fixed height
	pushbutton1->setFixedWidth(150);            //set a fixed width

	pushbutton2 = new QPushButton;
	pushbutton2->setText(tr("Testing"));
	pushbutton2->setFixedHeight(40);
	pushbutton2->setFixedWidth(150);

    pushbutton3 = new QPushButton;
	pushbutton3->setText(tr("Recognising"));
	pushbutton3->setFixedHeight(40);
	pushbutton3->setFixedWidth(150);

	quitbutton = new QPushButton;
	quitbutton->setText(tr("Quit"));
	quitbutton->setFixedHeight(30);
	quitbutton->setFixedWidth(100);

    stopbutton = new QPushButton;
	stopbutton->setText(tr("stop"));
	stopbutton->setFixedHeight(30);
	stopbutton->setFixedWidth(100);

	resumebutton = new QPushButton;
	resumebutton->setText(tr("resume"));
	resumebutton->setFixedHeight(30);
	resumebutton->setFixedWidth(100);


	//set pushbuttons colors
	//setStyleSheet("QPushButton::checked{background-color: red;color: white;} "
    //  "\n "
    // "QPushButton{background-color:  black;color: white;}");
					   
    //QPushButton *pushbutton1 = new QPushButton(this);      // to open new window when pressing pushbutton
    // QWidget *widget = new QWidget(this);
    //widget->setWindowFlags(Qt::Window);
     // widget->setWindowTitle("New Window");
   //connect(pushbutton1, SIGNAL(clicked()), widget, SLOT(show()));

   connect(pushbutton1, SIGNAL(clicked()), this, SLOT(playslot()));  //connect button1 to the playslot
   connect(stopbutton, SIGNAL(clicked()), this, SLOT(pauseslot()));  //connect stoputton to the pause slot
   connect(pushbutton2, SIGNAL(clicked()), this, SLOT(AudioRecorderSlot())); //connect button2 to the audiorecorder
   connect(quitbutton, SIGNAL(clicked()), this, SLOT(quitApp()));  //connect quitbutton to the quitapp slot
   connect(pushbutton3, SIGNAL(clicked()), this, SLOT(recognisingSlot()));
   connect(resumebutton, SIGNAL(clicked()), this, SLOT(resumeslot()));
	pushbutton1->show();
	pushbutton2->show();
    pushbutton3->show();
	quitbutton->show();
    
   
	// set up the initial plot data
	//for( int index=0; index<plotDataSize; ++index )
	//{
		//xData[index] = index;
		//yData[index] = gain * sin( M_PI * index/50 );
	//}

	//curve = new QwtPlotCurve;
	
	// make a plot curve from the data and attach it to the plot
	//curve->setSamples(xData, yData, plotDataSize);
	//curve->attach(plot);

	//plot->replot();
//	plot->show();
       
	// set up the layout - knob above thermometer
	vLayout = new QVBoxLayout;
	vLayout->addWidget(pushbutton1); 
	vLayout->addWidget(pushbutton2);
	vLayout->addWidget(pushbutton3);
    vLayout->addWidget(quitbutton);
	
	// plot to the left of knob and thermometer
	hLayout = new QHBoxLayout;
	hLayout->addLayout(vLayout);	
	//hLayout->addWidget(plot);           ///plot the graph on the same interface
    
	setLayout(hLayout);

}

Window::~Window() {
	// tells the thread to no longer run its endless loop
//	adcreader->quit();
	// wait until the run method has terminated
//	adcreader->wait();
//	delete adcreader;
}

void Window::timerEvent( QTimerEvent * )
{
	//double inVal = gain * sin( M_PI * count/50.0 );
	//++count;

	// add the new input to the plot
	//memmove( yData, yData+1, (plotDataSize-1) * sizeof(double) );
	//yData[plotDataSize-1] = inVal;
  
	//curve->setSamples(xData, yData, plotDataSize);
	//plot->replot();

	// set the thermometer value
	//thermo->setValue( inVal + 10 );
}




//this function works whenever pushbutton 1 is pressed
void Window::playslot()    
{  
	 stopbutton->show();
	 hLayout->addWidget(stopbutton); 
	 
	 player = new QMediaPlayer;
	 player->setMedia(QUrl::fromLocalFile("/home/mario/Test/qwt-example/C-scale.mp3"));
	 player->setVolume(50);           // set the volume 
	// videoWidget = new QVideoWidget;
    // player->setVideoOutput(videoWidget);
    // videoWidget->show();
     player->play();                 //play the song
	 pushbutton1->setDisabled(true);     //disable every button in the app while listening to avoid conflicts
	 pushbutton2->setDisabled(true);
	 pushbutton3->setDisabled(true);
} 
//this function is used to pause the learning video
void Window::pauseslot()  
{ 
     player->pause();             //pause the song then enable the user to press any button 
     pushbutton1->setEnabled(true);     
	 pushbutton2->setEnabled(true);
	 pushbutton3->setEnabled(true);
	 resumebutton->show();
	 hLayout->addWidget(resumebutton); 
	 stopbutton->hide();
}
void Window::resumeslot()  
{
     player->play();  
     stopbutton->show();
     resumebutton->hide();
     pushbutton1->setDisabled(true);   

}

/// Audio Record whenever pushbutton2 is pressed///
	void Window::AudioRecorderSlot()
{	 
	pushbutton3->setDisabled(true);
	pushbutton1->setDisabled(true);
	pushbutton2->setDisabled(true);
	destinationFile.setFileName("/home/mario/project2/test.mp3");
    destinationFile.open( QIODevice::WriteOnly | QIODevice::Truncate );

	QAudioFormat format;
    // Set up the desired format, for example:
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        qWarning() << "Default format not supported, trying to use the nearest.";
        format = info.nearestFormat(format);
    }

    audio = new QAudioInput(format, this);
    connect(audio, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));

    QTimer::singleShot(3000, this, SLOT(stopRecording()));
    audio->start(&destinationFile);

   
}
void Window::stopRecording()
{
    audio->stop();
    destinationFile.close();
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
   // player = new QMediaPlayer;

}

//this function is used to quit the application
void Window::quitApp()    
{ 
    Window::close();
   
}



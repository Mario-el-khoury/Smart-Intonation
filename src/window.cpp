#include "window.h"
#include <QAudioInput>
#include <QAudioRecorder>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <cmath>  // for sine stuff
#include <iostream>
#include <random>   // for random numbers
#include <unistd.h>   // for delays   
#include <cstdlib>
#include <ctime>
#include "time.h"
#include <QString>

// open the constructer of the project

Window::Window() 
{
	QAudioInput* audio; // Class member
	
	setWindowTitle("Welcome to the Smart Intonation Software!");  //set title

	// set push buttons 
	pushbutton1 = new QPushButton;            
	pushbutton1->setText(tr("Learning"));                    //type on the button
	pushbutton1->setFixedHeight(40);                         //set a fixed height
	pushbutton1->setFixedWidth(180);                          //set a fixed width
	pushbutton1->setStyleSheet("color: black; background-color: yellow"); // set text and button color
	//pushbutton1->setStyleSheet(" background-color: yellow; border-style: outset; border-width: 2px; border-radius: 10px;border-color: beige; font: bold 14px;  min-width: 10em; padding: 6px");

	pushbutton2 = new QPushButton;
	pushbutton2->setText(tr("Recognising the tones"));
	pushbutton2->setFixedHeight(40);
	pushbutton2->setFixedWidth(180);
    pushbutton2->setStyleSheet("background-color: grey");

    pushbutton3 = new QPushButton;
	pushbutton3->setText(tr("Testing"));
	pushbutton3->setFixedHeight(40);
	pushbutton3->setFixedWidth(180);
	pushbutton3->setStyleSheet("background-color: green");
    
	pianobutton = new QPushButton;
	pianobutton->setText(tr("Piano"));
	pianobutton->setFixedHeight(40);
	pianobutton->setFixedWidth(180);
	pianobutton->setStyleSheet("background-color: skyblue");
	
	quitbutton = new QPushButton;
	quitbutton->setText(tr("Quit App"));
	quitbutton->setFixedHeight(30);
	quitbutton->setFixedWidth(150);
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

	audiostopbutton=new QPushButton;
	audiostopbutton->setText(tr("stop"));
	audiostopbutton->setFixedHeight(30);
	audiostopbutton->setFixedWidth(100);
	audiostopbutton->hide();
	audiostopbutton->setStyleSheet("background-color: red");

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
    
	melody = new QPushButton;
	melody->setText(tr("Melody here!"));
	melody->setFixedHeight(600);
	melody->setFixedWidth(100);
	melody->hide();
	melody->setStyleSheet("color: black; background-color: white");
	
    text= new QLineEdit();
	text->setReadOnly(true);
	text->setFixedHeight(30);
	text->setFixedWidth(70);
	text->hide();
    //text->setStyleSheet("color: black; background-color: red");

    text2= new QLineEdit();
	text2->setReadOnly(true);
	text2->setFixedHeight(30);
	text2->setFixedWidth(70);
	text2->hide();
    //text2->setStyleSheet("color: black; background-color: red");

	text3= new QLineEdit();
	text3->setReadOnly(true);
	text3->setFixedHeight(30);
	text3->setFixedWidth(70);
	text3->hide();
    //text3->setStyleSheet("color: black; background-color: red");
	//QPushButton *pushbutton1 = new QPushButton(this);      // to open new window when pressing pushbutton
    // QWidget *widget = new QWidget(this);
    //widget->setWindowFlags(Qt::Window);
    // widget->setWindowTitle("New Window");
   


    // Player  declaration
     player = new QMediaPlayer;
    // Set player as a C-scale video located in the src directory 
     player->setMedia(QUrl::fromLocalFile(QFileInfo("C-scale.mp4").absoluteFilePath()));
	// Set sound volume 
	 player->setVolume(50);   
	// Intialise video widget        
	 videoWidget = new QVideoWidget;
	// Allocate the video to Player 
     player->setVideoOutput(videoWidget);
  
    // Connect pushbutton1 to the playslot that starts the video 
	connect(pushbutton1, SIGNAL(clicked()), this, SLOT(playslot()));  
	// Connect stopbutton to the pauseslot that pause the video 
	connect(stopbutton, SIGNAL(clicked()), this, SLOT(pauseslot()));  
	// Connect pushbutton2 to the AudioRecorderSlot that take the audio input 
	connect(pushbutton2, SIGNAL(clicked()), this, SLOT(AudioRecorderSlot()));
	// Connect quitbutton to the quitApp that quit the main window 
	connect(quitbutton, SIGNAL(clicked()), this, SLOT(quitApp()));
	// Connect pushbutton3 to the TestingSlot that genrate random tones to the user to recognise it 
	connect(pushbutton3, SIGNAL(clicked()), this, SLOT(TestingSlot()));  
	// Connect resumebutton to the resumeslot that resume the video 
	connect(resumebutton, SIGNAL(clicked()), this, SLOT(resumeslot())); 
	// Connect exitbutton to the exitslot that exit the video and other windows
	connect(exitbutton, SIGNAL(clicked()), this, SLOT(exitslot())); //connect exitbutton to exitslot
    // Connect pianobutton to the pianoPlayer slot that play a piano
    connect(pianobutton,SIGNAL(clicked()), this, SLOT(pianoPlayer()));
	// Connect melodybutton to the clearnotes slot that to clear the notes in the melody text
	connect(melody,SIGNAL(clicked()), this, SLOT(clearnotes()));
	//
	connect(audiostopbutton, SIGNAL(clicked()),this, SLOT(audioexit()));

    
	// set up the layout - pushbutton1 above pushbutton2 and so on
	vLayout = new QVBoxLayout;
	vLayout->addWidget(pushbutton1); 
	vLayout->addWidget(pushbutton2);
	vLayout->addWidget(pushbutton3);
	vLayout->addWidget(pianobutton);
    vLayout->addWidget(quitbutton);
	
	// plot horizontally 
	hLayout = new QHBoxLayout;
	hLayout->addLayout(vLayout);	
	hLayout->addWidget(stopbutton); 
	hLayout->addWidget(resumebutton);
	hLayout->addWidget(melody);
	hLayout->addWidget(dobutton);
	hLayout->addWidget(rebutton);
	hLayout->addWidget(mibutton);
	hLayout->addWidget(fabutton);
	hLayout->addWidget(sobutton);
	hLayout->addWidget(labutton);
	hLayout->addWidget(tibutton);
    hLayout->addWidget(feedbackbutton);
    hLayout->addWidget(text);
	hLayout->addWidget(text2);
	hLayout->addWidget(text3);	
	hLayout->addWidget(audiostopbutton);
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

}

Window::~Window() {
	// destroy fftw function 
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
	dobutton->hide();
	rebutton->hide();
	mibutton->hide();
	fabutton->hide();
	sobutton->hide();
	labutton->hide();
	tibutton->hide();
	melody->hide();
	feedbackbutton->hide();

    videoWidget->show();
	// video will play 
    player->play();   
	 // disable every button in the app while listening to avoid conflicts             
        
	pushbutton2->setDisabled(true);
	pushbutton3->setDisabled(true);
	pianobutton->setDisabled(true);
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

void Window::audioexit(){
	audio->stop();
	audiostopbutton->hide();
	this->exitslot();
}

void Window::exitslot()
{   
	
	text->hide();
	text2->hide();
	text3->hide();
	exitbutton->hide();
    videoWidget->hide();
	player->stop();  
    stopbutton->hide();
	resumebutton->hide();
	dobutton->hide();
	rebutton->hide();
	mibutton->hide();
	fabutton->hide();
	sobutton->hide();
	labutton->hide();
	tibutton->hide();
	melody->hide();
	feedbackbutton->hide();
	audiostopbutton->hide();
	pushbutton1->setEnabled(true);
    pushbutton2->setEnabled(true);
	pushbutton3->setEnabled(true);
	pianobutton->setEnabled(true);
}




/// Audio Record whenever pushbutton2 is pressed///
	void Window::AudioRecorderSlot()
{	 

	pushbutton3->setDisabled(true);
	pushbutton1->setDisabled(true);
	pushbutton2->setDisabled(true);
    pianobutton->setDisabled(true);

    dobutton->show();
	rebutton->show();
	mibutton->show();
	fabutton->show();
	sobutton->show();
	labutton->show();
	tibutton->show(); 
	melody->show();
	exitbutton->hide();
	audiostopbutton->show();
	text->show();	
	text2->show();
	text3->show();

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
	// initialise new audio	
    audio = new QAudioInput(format, this);
	// size of imput data
	audio->setBufferSize(fftbuffsize); 
	// slot connection between audio and readmicrophone data
	connect(audio, SIGNAL(notify()),this,SLOT(readMicrophone()));
	// initialise new array 
	readmicarray = new QByteArray;
	//assing the readmicarray to readMic
	readMic = new QBuffer(readmicarray);
	readMic->open(QIODevice::ReadWrite|QIODevice::Truncate);
	audio->start(readMic);
	// delay to catch samples and detect the pitch 
	audio->setNotifyInterval(bufferTime);
	
	qDebug()<<"frequency resolution" << sampleRate/audio->bufferSize();
   
}

void Window::readMicrophone()
{
    static QString str = "melody(click here to hide!): ";
	QByteArray datain = readMic->data();
	readMic->buffer().clear();
	readMic->reset();

	for (int i =0;i<audio->bufferSize();i++){
		fftinputbuffer[i] = (double)(datain.at(i));
	}
	
	datain.clear();
	// execute the fft function to find the frequency 
	fftw_execute(plan);
	
	//find maximum peak in fftouputbuffer
	int peakIndex = 0;
	double peakmag =0;
    // find the magnitude of the signal between two intervals
	for (int i =(int)((lowestFrequency *audio->bufferSize())/sampleRate); i<(int)((highestFrequency*audio->bufferSize())/sampleRate); i++) {						
		double mag = sqrt(fftoutputbuffer[i][0]*fftoutputbuffer[i][0] +
		fftoutputbuffer[i][1]*fftoutputbuffer[i][1]); 
		if(mag > peakmag){
			peakmag = mag;
			peakIndex=i;
		}
		
	}
	

	if (peakmag > 50000) {
		time_t t1=time(NULL);
		static double duration = 0.3;
		peakHertz = peakIndex * (sampleRate/audio->bufferSize());
		
		if((peakHertz > 110) && (peakHertz < 880)){
		qDebug() << peakHertz << "HZ "<< "t1:" << ctime(&t1);
		peakHertz /=  262.0;
		while(peakHertz < 1){
			peakHertz *= 2;
		}
		while(peakHertz >= 2){ 
			peakHertz /= 2;
		}

		if   ((peakHertz >= pow (2,	-1.0/12.0)) && (peakHertz < pow ( 2,1.0/12.0)) && (difftime(t1, t2) > duration))
			{   
				//double note = pow (2, 0.0/12.0);
				qDebug() << "Do"<< " "<< "t2:" << ctime(&t2) << "______";
			    str.append("1 "); 
			    melody->setText(str);
		    	t2 = t1;
			    dobutton->setStyleSheet("color: black; background-color: darkseagreen");
			    rebutton->setStyleSheet("color: black; background-color: ivory");
			    mibutton->setStyleSheet("color: black; background-color: ivory");
			    fabutton->setStyleSheet("color: black; background-color: ivory");
			    sobutton->setStyleSheet("color: black; background-color: ivory");
			    labutton->setStyleSheet("color: black; background-color: ivory");
			    tibutton->setStyleSheet("color: black; background-color: ivory");
				 
 			if ((peakHertz <= pow (2, 0.3/12.0))&& (peakHertz >= pow (2,-0.3/12.0)))	
			 {
					    text->clear();	
						text3->clear();
						text2->setText("Bang On!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: green");
					}
			 else if ((peakHertz > pow (2, 0.3/12.0)) &&  (peakHertz < pow ( 2,1.0/12.0)))	
			 {
							text->clear();	
							text2->clear();
							text3->setText("High!");
							text->setStyleSheet("color: black; background-color: white");
							text2->setStyleSheet("color: black; background-color: white");
							text3->setStyleSheet("color: black; background-color: red");
						}
			else	if ((peakHertz < pow (2,-0.3/12.0)) && (peakHertz > pow (2,-1.0/12.0)))	
			 {	
							text2->clear();
							text3->clear();
							text->setText("Low!");
							text2->setStyleSheet("color: black; background-color: white");
							text3->setStyleSheet("color: black; background-color: white");
							text->setStyleSheet("color: black; background-color: red");
						}		
			}

		else if ((peakHertz >= pow ( 2,1.0/12.0)) && (peakHertz < pow ( 2,3.0/12.0) )&& (difftime(t1, t2) > duration))
				{
			     
				 qDebug() << "Re"<< " "<< "t2:" << ctime(&t2) << "______";;
				 str.append("2 "); 
				 melody->setText(str);
				 t2 = t1;
				 dobutton->setStyleSheet("color: black; background-color: ivory");
				 rebutton->setStyleSheet("color: black; background-color: darkseagreen");
				 mibutton->setStyleSheet("color: black; background-color: ivory");
				 fabutton->setStyleSheet("color: black; background-color: ivory");
				 sobutton->setStyleSheet("color: black; background-color: ivory");
				 labutton->setStyleSheet("color: black; background-color: ivory");
				 tibutton->setStyleSheet("color: black; background-color: ivory");
		        // double note = pow (2, 2.0/12.0);
					if ((peakHertz >= pow (2,1.7/12.0))&& (peakHertz <= pow (2,2.3/12.0)))	{
							text->clear();	
							text3->clear();
                            text2->setText("Bang On!");
							text->setStyleSheet("color: black; background-color: white");
							text3->setStyleSheet("color: black; background-color: white");
							text2->setStyleSheet("color: black; background-color: green");
						}

				else	 if ((peakHertz > pow (2,2.3/12.0))&& (peakHertz < pow (2,3.0/12.0)))	{
							text->clear();	
							text2->clear();
							text3->setText("High!");
							text->setStyleSheet("color: black; background-color: white");
					    	text2->setStyleSheet("color: black; background-color: white");
							text3->setStyleSheet("color: black; background-color: red");
						}
				else	 if ((peakHertz > pow (2,1.0/12.0))&& (peakHertz < pow (2,1.7/12.0)))	{	
							text2->clear();
							text3->clear();
							text->setText("Low!");
							text2->setStyleSheet("color: black; background-color: white");
							text3->setStyleSheet("color: black; background-color: white");
							text->setStyleSheet("color: black; background-color: red");
						}
				}
		else if (  (peakHertz >= pow ( 2,3.0/12.0)) && (peakHertz < pow ( 2,4.5/12.0))&& (difftime(t1, t2) > duration))
				{
					qDebug() << "Mi"<< " "<< "t2" << " " << ctime(&t2) << "______";;
				    str.append("3 ");
				    melody->setText(str); 
				    t2 = t1;
				    std::cout << "t2"  << ctime(&t2);
				    dobutton->setStyleSheet("color: black; background-color: ivory");
				    rebutton->setStyleSheet("color: black; background-color: ivory");
				    mibutton->setStyleSheet("color: black; background-color: darkseagreen");
				    fabutton->setStyleSheet("color: black; background-color: ivory");
				    sobutton->setStyleSheet("color: black; background-color: ivory");
				    labutton->setStyleSheet("color: black; background-color: ivory");
				    tibutton->setStyleSheet("color: black; background-color: ivory");
				//	double note = pow (2, 3.75/12.0);
					if ((peakHertz >= pow (2,3.525/12.0))&& (peakHertz <= pow (2,3.975/12.0)))	
					{
						text->clear();	
						text3->clear();
						text2->setText("Bang On!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: Green");
						}
			else	if ((peakHertz > pow (2,3.975/12.0))&& (peakHertz < pow (2,4.5/12.0)))	
			        {
						text->clear();	
						text2->clear();
						text3->setText("High!");
						text->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: white");
                        text3->setStyleSheet("color: black; background-color: red");
						}
			else	 if ((peakHertz > pow (2,3.0/12.0))&& (peakHertz <= pow (2,3.525/12.0)))	
			        {
						text2->clear();
						text3->clear();
						text->setText("Low!");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
						}	
				}	
		else	if(  (peakHertz >= pow ( 2,4.5/12.0)) && (peakHertz < pow ( 2,6.0/12.0))&& (difftime(t1, t2) > duration))
				{
					qDebug() << "Fa"<< " "<< "t2:" << ctime(&t2) << "______";;
				    str.append("4 "); 
				    melody->setText(str);
				    t2 = t1;
				    dobutton->setStyleSheet("color: black; background-color: ivory");
				    rebutton->setStyleSheet("color: black; background-color: ivory");
				    mibutton->setStyleSheet("color: black; background-color: ivory");
				    fabutton->setStyleSheet("color: black; background-color: darkseagreen");
				    sobutton->setStyleSheet("color: black; background-color: ivory");
				    labutton->setStyleSheet("color: black; background-color: ivory");
				    tibutton->setStyleSheet("color: black; background-color: ivory");
				//	double note = pow (2, 5.25/12.0);
					if ((peakHertz >= pow (2, 5.025/12.0))&& (peakHertz <= pow (2,5.475/12.0)))	
					{
						text->clear();	
						text3->clear();
						text2->setText("Bang On!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: green");
						}
			else	if ((peakHertz > pow (2,5.475/12.0))&& (peakHertz < pow (2,6.0/12.0)))	
			        {
		 				text->clear();	
						text2->clear();
						text->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");
						text3->setText("High!");
					    }
			else	 if ((peakHertz > pow (2,4.5/12.0))&& (peakHertz < pow (2,5.025/12.0)))	
			        {	
						text2->clear();
						text3->clear();
						text->setText("Low!");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
						
						}
				} 
		else	if (  (peakHertz >= pow ( 2,6.0/12.0))  && (peakHertz < pow ( 2, 8.0/12.0))&& (difftime(t1, t2) > duration))
				{
				    qDebug() << "So"<< " "<< "t2:" << ctime(&t2) << "______";;
				    QString note = str.append("5 "); 
				    melody->setText(str);
				    t2 = t1;
				    dobutton->setStyleSheet("color: black; background-color: ivory");
				    rebutton->setStyleSheet("color: black; background-color: ivory");
				    mibutton->setStyleSheet("color: black; background-color: ivory");
				    fabutton->setStyleSheet("color: black; background-color: ivory");
				    sobutton->setStyleSheet("color: black; background-color: darkseagreen");
				    labutton->setStyleSheet("color: black; background-color: ivory");
				    tibutton->setStyleSheet("color: black; background-color: ivory");
				//  double note = pow (2, 7.0/12.0);
					if ((peakHertz >= pow (2,6.7/12.0))&& (peakHertz <= pow (2,7.3/12.0)))
					{
						text->clear();	
						text3->clear();
						text2->setText("Bang On!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: green");
						}
			else if ((peakHertz > pow (2,7.3/12.0))&& (peakHertz < pow (2,8.0/12.0)))	
			        {
						text->clear();	
						text2->clear();
						text3->setText("High!");
						text->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");

						}
			else	if ((peakHertz > pow (2,6.0/12.0))&& (peakHertz < pow (2,6.7/12.0)))
			     	{
						text2->clear();
						text3->clear();
						text->setText("Low!");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
						}	
				}
		else if(  (peakHertz >= pow ( 2,8.0/12.0)) && (peakHertz < pow ( 2,10.0/12.0))&& (difftime(t1, t2) > duration))
				{
					qDebug() << "La"<< " "<< "t2:" << ctime(&t2) << "______";;
			     	QString note = str.append("6 ");
	     			melody->setText(str); 
	    			t2 = t1;
	    			dobutton->setStyleSheet("color: black; background-color: ivory");
		    		rebutton->setStyleSheet("color: black; background-color: ivory");
		     		mibutton->setStyleSheet("color: black; background-color: ivory");
			    	fabutton->setStyleSheet("color: black; background-color: ivory");
	     			sobutton->setStyleSheet("color: black; background-color: ivory");
    				labutton->setStyleSheet("color: black; background-color: darkseagreen");
		     		tibutton->setStyleSheet("color: black; background-color: ivory");
	       		//	double note = pow (2, 9.0/12.0);
					
				if ((peakHertz >= pow (2,8.7/12.0))&& (peakHertz <= pow (2,9.3/12.0)))
				{
					text->clear();	
						text->clear();
						text3->clear();
						text2->setText("Bang On!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: green");
						}
			else	if ((peakHertz > pow (2,9.3/12.0))&& (peakHertz < pow (2,10.0/12.0)))	
			    {
						text->clear();	
						text2->clear();
						text->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");
						text3->setText("High!");
						}
			else	if ((peakHertz > pow (2,8.0/12.0))&& (peakHertz < pow (2,8.7/12.0)))	
			    {
					text->clear();	
						text2->clear();
						text3->clear();
						text->setText("Low!");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");

						}				
				}
		else if (  (peakHertz >= pow ( 2,10.0/12.0)) && (peakHertz < pow ( 2,11.5/12.0))&& (difftime(t1, t2) > duration))
				{
					qDebug() << "Ti"<< " "<< "t2:" << ctime(&t2) << "______";;
		     		QString note = str.append("7 ");
		     		melody->setText(str);
	    			t2 = t1;
	    			dobutton->setStyleSheet("color: black; background-color: ivory");
	    			rebutton->setStyleSheet("color: black; background-color: ivory");
	    			mibutton->setStyleSheet("color: black; background-color: ivory");
	    			fabutton->setStyleSheet("color: black; background-color: ivory");
	    			sobutton->setStyleSheet("color: black; background-color: ivory");
	    			labutton->setStyleSheet("color: black; background-color: ivory");
	    			tibutton->setStyleSheet("color: black; background-color: darkseagreen");
		        // 	double note = pow (2, 10.75/12.0);
		     	if ((peakHertz >= pow (2,10.525/12.0))&& (peakHertz <= pow (2,10.975/12.0)))
				 	{
						text->clear();
						text3->clear();
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: green");
						text2->setText("Bang On!");
						}
			else if ((peakHertz > pow (2, 10.975/12.0)) &&  (peakHertz < pow ( 2,11.5/12.0)))
			        {
					    text->clear();	
						text2->clear();
						text->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");
						text3->setText("High!");
						}
			else	if ((peakHertz < pow (2, 10.525/12.0)) && (peakHertz > pow (2,10/12.0)))	
				    {
						text2->clear();
						text3->clear();
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
						text->setText("Low!");
						}
				}
			}
		else 
 				{   text->clear();
				    text3->clear();
					text2->setStyleSheet("color: black; background-color: white");
					text3->setStyleSheet("color: black; background-color: white");
					text->setStyleSheet("color: black; background-color: white");
                	text2->setText("Out of Interval");
				}

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
				pianobutton->setEnabled(true);
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

void Window::TestingSlot()    
{ 
 // in this function, the user will be asked to recognise which tone is generated by the software
	pianoPlayer();
	pushbutton1->setDisabled(true);     
	pushbutton2->setDisabled(true);
	pianobutton->setDisabled(true);
	pushbutton3->setEnabled(true);
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
	feedbackbutton->setStyleSheet("color: black; background-color: grey"); 
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
		connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
		connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
	}
  else if (dist7(rng)==2)
   { 
		player = new QMediaPlayer;
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/re.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
		connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
	 }
  else if (dist7(rng)==3)
   { 
		player = new QMediaPlayer;
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/mi.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
		connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
	}
	 
  else if (dist7(rng)==4)
   { 
		player = new QMediaPlayer;
	    player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/fa.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
		connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
   }
 else if (dist7(rng)==5)
   { 
		player = new QMediaPlayer;
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/so.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
		connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
	}	 
else if (dist7(rng)==6)
   { 
		player = new QMediaPlayer;
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/la.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
		connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
	 }	 
 else if (dist7(rng)==7)
   { 
		player = new QMediaPlayer;
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/ti.mp3").absolutePath()));
		player->setVolume(90); 
		player->play();
		connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
	 }	 

}

void Window::feedbackSlot()
{
	feedbackbutton->setText(tr("Well done!!"));
	feedbackbutton->setStyleSheet("color: black; background-color: darkseagreen");
}

void Window::feedbackWrong()
{
	feedbackbutton->setText(tr("Wrong!!"));
	feedbackbutton->setStyleSheet("color: black; background-color: lightcoral");
}

 /*                  */
void Window::DoPressedSlot()
 {
    
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

void Window::RePressedSlot()
 {
    // feedbackbutton->setText(tr("Well done!!"));
	// feedbackbutton->setStyleSheet("color: black; background-color: lightcoral");
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
 void Window::MiPressedSlot()
 {
    // feedbackbutton->setText(tr("Well done!!"));
	// feedbackbutton->setStyleSheet("color: black; background-color: lightcoral");
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
void Window::FaPressedSlot()
 {
    // feedbackbutton->setText(tr("Well done!!"));
	// feedbackbutton->setStyleSheet("color: black; background-color: lightcoral");
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
void Window::SoPressedSlot()
 {
    // feedbackbutton->setText(tr("Well done!!"));
	// feedbackbutton->setStyleSheet("color: black; background-color: lightcoral");
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
void Window::LaPressedSlot()
 {
    // feedbackbutton->setText(tr("Well done!!"));
	// feedbackbutton->setStyleSheet("color: black; background-color: lightcoral");
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
void Window::TiPressedSlot()
 {
    // feedbackbutton->setText(tr("Well done!!"));
	// feedbackbutton->setStyleSheet("color: black; background-color: lightcoral");
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
	pianobutton->setEnabled(true);
	pushbutton1->setDisabled(true);
	pushbutton2->setDisabled(true);
	pushbutton3->setDisabled(true);
	quitbutton->setEnabled(true);

	connect(dobutton, SIGNAL(clicked()), this, SLOT(DoPressedSlot()));
	connect(rebutton, SIGNAL(clicked()), this, SLOT(RePressedSlot()));
	connect(mibutton, SIGNAL(clicked()), this, SLOT(MiPressedSlot()));
	connect(fabutton, SIGNAL(clicked()), this, SLOT(FaPressedSlot()));
	connect(sobutton, SIGNAL(clicked()), this, SLOT(SoPressedSlot()));
	connect(labutton, SIGNAL(clicked()), this, SLOT(LaPressedSlot()));
	connect(tibutton, SIGNAL(clicked()), this, SLOT(TiPressedSlot()));
}

void Window::clearnotes()
{
	melody->hide();
	melody->setText(tr("Melody here!"));
}

//  Function is used to quit the application 
void Window::quitApp()    
	{ 
			Window::close();
	
	}





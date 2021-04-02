#include "window.h"
#include <QAudioInput>
#include <QAudioRecorder>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <cmath>  // for sine stuff
#include <iostream>
#include <random>   // for random numbers
#include <unistd.h>   // for delays   

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
    feedbackbutton->setFixedHeight(30);
	feedbackbutton->setFixedWidth(100);
	feedbackbutton->hide();
	feedbackbutton->setStyleSheet("color: black; background-color: grey");

	
    text= new QLineEdit();
	text->setReadOnly(true);
	text->setFixedHeight(30);
	text->setFixedWidth(100);
	text->hide();
    //text->setStyleSheet("color: black; background-color: red");

    text2= new QLineEdit();
	text2->setReadOnly(true);
	text2->setFixedHeight(30);
	text2->setFixedWidth(100);
	text2->hide();
    //text2->setStyleSheet("color: black; background-color: red");

	text3= new QLineEdit();
	text3->setReadOnly(true);
	text3->setFixedHeight(30);
	text3->setFixedWidth(100);
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

	connect(audiostopbutton, SIGNAL(clicked()),this, SLOT(audioexit()));

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
	hLayout->addWidget(audiostopbutton);
	hLayout->addWidget(videoWidget);  
	hLayout->addWidget(text);
	hLayout->addWidget(text2);
	hLayout->addWidget(text3);
	

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

    videoWidget->show();
	// video will play 
    player->play();   
	 // disable every button in the app while listening to avoid conflicts             
	pushbutton1->setDisabled(true);     
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
	audio->start(readMic);
	audio->setNotifyInterval(bufferTime);
	
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
    // find the magnitude of the signal 
	for (int i =1;i<(audio->bufferSize()/2)+1;i++){
		double mag = sqrt(fftoutputbuffer[i][0]*fftoutputbuffer[i][0] +
							fftoutputbuffer[i][1]*fftoutputbuffer[i][1]); //get magnitude

		if(mag > peakmag){
			peakmag = mag;
			peakIndex=i;
		}
		
	}
	
	bool peakflag= false;
	QString textEditString("Your voice frequency is ");

	if (peakmag > 15000) {
		peakHertz = peakIndex * (sampleRate/audio->bufferSize());
		qDebug() << peakHertz << "Hz";
		// assign the frequency values to textEditString 
		textEditString.append(QString("%L0").arg(peakHertz,0,'f',2));
		peakflag = true;
	}
	// convert double peakHertz to string strpeakHertz and put no number after the commas
  	// QString  strpeakHertz = QString::number(peakHertz, 'f', 0 );
	peakIndex = 0;
	peakmag=0;

   	if (peakflag)
   		{

		// peakHertz /=  261.63 ;	//c major
		peakHertz /= peakHertzScale;
		

		//while(peakHertz < pow (2,-1/12.0))  //0.94
		while(peakHertz < 1)
			peakHertz *= 2;

		//while(peakHertz > pow (2,11.5/12.0)) //1.94
		while(peakHertz > 2)
			peakHertz /= 2 ;

		if   ((peakHertz >= pow (2,	-1.0/12.0)) && (peakHertz < pow ( 2,1.0/12.0)))
			{   
				double note = pow (2, 0.0/12.0);
				 
 			if ((peakHertz <= pow (2, 0.3/12.0))&& (peakHertz >= pow (2,-0.3/12.0)))	{
						text->clear();	
						text3->clear();
						text2->setText("Do, Bang On!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: green");
					}
			 else if ((peakHertz > pow (2, 0.3/12.0)) &&  (peakHertz < pow ( 2,1.0/12.0)))	{
							text->clear();	
							text2->clear();
							text3->setText("High Do!");
							text->setStyleSheet("color: black; background-color: white");
							text2->setStyleSheet("color: black; background-color: white");
							text3->setStyleSheet("color: black; background-color: red");
						}
			else	if ((peakHertz < pow (2,-0.3/12.0)) && (peakHertz >= pow (2,-1.0/12.0)))	{	
							text2->clear();
							text3->clear();
							text->setText("Low Do!");
							text2->setStyleSheet("color: black; background-color: white");
							text3->setStyleSheet("color: black; background-color: white");
							text->setStyleSheet("color: black; background-color: red");
						}		
				// terminal plot 
				qDebug() << "Do";
				// assign the second string to textEditString depending on the tone 	
			//textEditString.append("Hz, its a Do");

			}

		else if (  (peakHertz >= pow ( 2,1.0/12.0)) && (peakHertz < pow ( 2,3.0/12.0) ))
				{
					qDebug() << "Re";
		            double note = pow (2, 2.0/12.0);
					if ((peakHertz >= pow (2,1.7/12.0))&& (peakHertz <= pow (2,2.3/12.0)))	{
							text->clear();	
							text3->clear();
                            text2->setText("Re, Bang On!");
							text->setStyleSheet("color: black; background-color: white");
							text3->setStyleSheet("color: black; background-color: white");
							text2->setStyleSheet("color: black; background-color: green");
						}

				else	 if (peakHertz > note)	{
							text->clear();	
							text2->clear();
							text3->setText("High Re!");
							text->setStyleSheet("color: black; background-color: white");
					    	text2->setStyleSheet("color: black; background-color: white");
							text3->setStyleSheet("color: black; background-color: red");
						}
				else	 if (peakHertz < note)	{	
							text2->clear();
							text3->clear();
							text->setText("Low Re!");
							text2->setStyleSheet("color: black; background-color: white");
							text3->setStyleSheet("color: black; background-color: white");
							text->setStyleSheet("color: black; background-color: red");
						}

					// assign the second string to textEditString depending on the tone 	
				//	textEditString.append("Hz, its a Re");
				}
		else if (  (peakHertz >= pow ( 2,3.0/12.0)) && (peakHertz < pow ( 2,4.5/12.0)))
				{
					qDebug() << "Mi";
					double note = pow (2, 3.75/12.0);
					if ((peakHertz >= pow (2,3.525/12.0))&& (peakHertz <= pow (2,3.975/12.0)))	{
						text->clear();	
						text3->clear();
						text2->setText("Mi, Bang On!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: Green");
						}
			else	if (peakHertz > note)	{
						text->clear();	
						text2->clear();
						text3->setText("High Mi!");
						text->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: white");
                        text3->setStyleSheet("color: black; background-color: red");
						}
			else	 if (peakHertz < note)	{
						text2->clear();
						text3->clear();
						text->setText("Low Mi!");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
						}

					// assign the second string to textEditString depending on the tone 	
				//	textEditString.append("Hz, its a Mi");
					
				}	
	else	if(  (peakHertz >= pow ( 2,4.5/12.0)) && (peakHertz < pow ( 2,6.0/12.0)))
				{
					qDebug() << "Fa";
					double note = pow (2, 5.25/12.0);
					if ((peakHertz >= pow (2, 5.025/12.0))&& (peakHertz <= pow (2,5.475/12.0)))	{
						text->clear();	
						text3->clear();
						text2->setText("Fa, Bang On!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: green");
						}
			else	if (peakHertz > note)	{
						text->clear();	
						text2->clear();
						text->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");
						text3->setText("High Fa!");
					}
			else	 if (peakHertz < note)	{	
						text2->clear();
						text3->clear();
						text->setText("Low Fa!");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
						
						}
					// assign the second string to textEditString depending on the tone 	
				//textEditString.append("Hz, its a Fa");
					
				} 
	else	if (  (peakHertz >= pow ( 2,6.0/12.0))  && (peakHertz < pow ( 2, 8.0/12.0)))
				{
					qDebug() << "So";
					double note = pow (2, 7.0/12.0);
					if ((peakHertz >= pow (2,6.7/12.0))&& (peakHertz <= pow (2,7.3/12.0))){
						text->clear();	
						text3->clear();
						text2->setText("So, Bang On!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: green");
						}
			else if (peakHertz > note)	{
					
						text->clear();	
						text2->clear();
						text3->setText("High So!");
						text->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");

						}
			else	if (peakHertz < note)	{
						
						text2->clear();
						text3->clear();
						text->setText("Low So!");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
						}
					// assign the second string to textEditString depending on the tone 	
				//	textEditString.append("Hz, its a So");
					
				}
		else if(  (peakHertz >= pow ( 2,8.0/12.0)) && (peakHertz < pow ( 2,10.0/12.0)))
				{
					qDebug() << "La";
					double note = pow (2, 9.0/12.0);
					if ((peakHertz >= pow (2,8.7/12.0))&& (peakHertz <= pow (2,9.3/12.0)))	{
		
					text->clear();	
						text->clear();
						text3->clear();
						text2->setText("La, Bang On!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: green");
						}
			else	if (peakHertz > note)	{
				
						text->clear();	
						text2->clear();
						text->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");
						text3->setText("High La!");
						}
			else	if (peakHertz < note)	{
					text->clear();	
						text2->clear();
						text3->clear();
						text->setText("Low La!");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");

						}
					// assign the second string to textEditString depending on the tone 	
					//textEditString.append("Hz, its a La");
					
				}
		else if (  (peakHertz >= pow ( 2,10.0/12.0)) && (peakHertz < pow ( 2,11.5/12.0)))
				{
					qDebug() << "Si";
		    		 double note = pow (2, 10.75/12.0);
		     	if ((peakHertz >= pow (2,10.525/12.0))&& (peakHertz <= pow (2,10.975/12.0)))	{
					//	textEditString.append("bang on!");
						text->clear();
						text3->clear();
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: green");
						text2->setText("Si, Bang On!");
						}

			else if (peakHertz > note)	{
					//	textEditString.append("high!");
					    text->clear();	
						text2->clear();
						text->setStyleSheet("color: black; background-color: white");
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");
						text3->setText("High Si!");
						}
			else	if (peakHertz < note)	{
					//	textEditString.append("low!");	
						text2->clear();
						text3->clear();
						text2->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
						text->setText("Low Si!");
						}
					// assign the second string to textEditString depending on the tone 	
					//textEditString.append("Hz, its a Si");
				}
			}
		  else 
 				{   text->clear();
				    text3->clear();
					text2->setStyleSheet("color: black; background-color: white");
					text3->setStyleSheet("color: black; background-color: white");
					text->setStyleSheet("color: black; background-color: white");
                	text2->setText("out of interval");
				}
			
					
				
   	// assing the textEditTring to the text showed on the window 
	//text->setText(textEditString);
	audiostopbutton->show();	
	text->show();	
	text2->show();
	text3->show();
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

void Window::TestingSlot()    
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
   
  
   
   if (dist7(rng)==1)
	{   
		// reset player from begining 
		player = new QMediaPlayer;
		// Assign the do.mp3 to player 
		player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/do.mp3").absolutePath()));
		// Set player volume 
		player->setVolume(90); 
		// Play the player audio 
		player->play();	  
		// Connect dobutton to detect if do is pressed by the user  
		connect(dobutton, SIGNAL(clicked()), this, SLOT(DoPressedSlot()));

	}
  		else if (dist7(rng)==2)
  		 { 
				// reset player from begining 
				player = new QMediaPlayer;
				// Assign the re.mp3 to player 
				player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/re.mp3").absolutePath()));
				// Set player volume 
				player->setVolume(90); 
				// Play the player audio 
				player->play();	  
				// Connect dobutton to detect if re is pressed by the user  
				connect(rebutton, SIGNAL(clicked()), this, SLOT(RePressedSlot()));

			}
		else if (dist7(rng)==3)
		{  
				// reset player from begining 
				player = new QMediaPlayer;
				// Assign the mi.mp3 to player 
				player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/mi.mp3").absolutePath()));
				// Set player volume 
				player->setVolume(90); 
				// Play the player audio 
				player->play();	  
				// Connect dobutton to detect if mi is pressed by the user  
				connect(mibutton, SIGNAL(clicked()), this, SLOT(MiPressedSlot()));
			}
			
		else if (dist7(rng)==4)
		{    
				// reset player from begining 
				player = new QMediaPlayer;
				// Assign the fa.mp3 to player 
				player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/fa.mp3").absolutePath()));
				// Set player volume 
				player->setVolume(90); 
				// Play the player audio 
				player->play();	  
				// Connect dobutton to detect if fa is pressed by the user  
				connect(fabutton, SIGNAL(clicked()), this, SLOT(FaPressedSlot()));
		}
		else if (dist7(rng)==5)
		{    
				// reset player from begining 
				player = new QMediaPlayer;
				// Assign the so.mp3 to player 
				player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/so.mp3").absolutePath()));
				// Set player volume 
				player->setVolume(90); 
				// Play the player audio 
				player->play();	  
				// Connect dobutton to detect if so is pressed by the user  
				connect(sobutton, SIGNAL(clicked()), this, SLOT(SoPressedSlot()));
			}	 
		else if (dist7(rng)==6)
		{   
				// reset player from begining 
				player = new QMediaPlayer;
				// Assign the la.mp3 to player 
				player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/la.mp3").absolutePath()));
				// Set player volume 
				player->setVolume(90); 
				// Play the player audio 
				player->play();	  
				// Connect dobutton to detect if la is pressed by the user  
				connect(labutton, SIGNAL(clicked()), this, SLOT(LaPressedSlot()));
			}	 
		else if (dist7(rng)==7)
		{   
				// reset player from begining 
				player = new QMediaPlayer;
				// Assign the si.mp3 to player 
				player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/si.mp3").absolutePath()));
				// Set player volume 
				player->setVolume(90); 
				// Play the player audio 
				player->play();	  
				// Connect dobutton to detect if si is pressed by the user  
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

 
//  Function is used to quit the application 
void Window::quitApp()    
	{ 
   		 Window::close();
   
	}





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

	melody = new QPushButton;
	melody->setText(tr("Melody here!"));
	melody->setFixedHeight(100);
	melody->setFixedWidth(1000);
	melody->hide();
	melody->setStyleSheet("color: black; background-color: white");

	stoprecording = new QPushButton;
	stoprecording->setText(tr("Stop"));
	stoprecording->setFixedHeight(30);
	stoprecording->setFixedWidth(100);
	stoprecording->hide();
	stoprecording->setStyleSheet("color: black; background-color: lightcoral");

	text= new QLineEdit();
	text->setReadOnly(true);
	text->setFixedHeight(30);
	text->setFixedWidth(70);
	text->hide();

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

	connect(learningbutton, SIGNAL(clicked()), this, SLOT(playSlot()));  //connect button1 to the playSlot
	connect(stopbutton, SIGNAL(clicked()), this, SLOT(pauseSlot()));  //connect stoputton to the pause slot
	connect(recognizingbutton, SIGNAL(clicked()), this, SLOT(audioRecorderSlot())); //connect button2 to the audiorecorder
	connect(quitbutton, SIGNAL(clicked()), this, SLOT(quitApp()));  //connect quitbutton to the quitapp slot
	connect(testingbutton, SIGNAL(clicked()), this, SLOT(testingSlot()));  
	connect(resumebutton, SIGNAL(clicked()), this, SLOT(resumeSlot())); //connect resumebutton to resumeSlot 
	connect(exitbutton, SIGNAL(clicked()), this, SLOT(exitSlot())); //connect exitbutton to exitSlot
	connect(piano,SIGNAL(clicked()), this, SLOT(pianoPlayer()));
	connect(stoprecording, SIGNAL(clicked()),this, SLOT(stopRecording()));
	connect(melody,SIGNAL(clicked()), this, SLOT(clearnotes()));
    
	// set up the layout - learningbutton above recognizingbutton and so on
	vLayout = new QVBoxLayout;
	vLayout->addWidget(melody);
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
	hLayout->addWidget(text);
	hLayout->addWidget(text3);	
	hLayout->addWidget(stoprecording);
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
	text->hide();
	text3->hide();
	feedbackbutton->hide();
	stoprecording->hide();
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
	melody->show();
	stoprecording->show();
	testingbutton->setDisabled(true);
	learningbutton->setDisabled(true);
	piano->setDisabled(true);
	text->show();
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
	fftw_execute(plan);
	
	//find maximum peak in fftouputbuffer
	int peakIndex = 0;
	double peakmag =0;
    // find the magnitude of the signal between two intervals
	for (int i =(int)((lowestFrequency *audio->bufferSize())/sampleRate); i<(int)((highestFrequency*audio->bufferSize())/sampleRate); i++) {						
		double mag = sqrt(fftoutputbuffer[i][0]*fftoutputbuffer[i][0] +
							fftoutputbuffer[i][1]*fftoutputbuffer[i][1]); //get magnitude

		if(mag > peakmag){
			peakmag = mag;
			peakIndex=i;
		}
		
	}
	
	if (peakmag > 100000){
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

			if(( peakHertz >= pow (2, -1.0/12.0)) && (peakHertz < pow ( 2,1.0/12.0)) && (difftime(t1, t2) > duration)){	
				//peakHertz(Do) = pow (2, 0/12.0));
				if((peakHertz <= pow (2, 0.5/12.0)) && (peakHertz >= pow (2,-0.5/12.0))){
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
				}
				else if((peakHertz > pow (2, 0.5/12.0)) &&  (peakHertz < pow (2, 1.0/12.0))){
					text->clear();	
					text3->setText("High Do!");
					text->setStyleSheet("color: black; background-color: white");
					text3->setStyleSheet("color: black; background-color: red");
				}
				else if((peakHertz < pow (2, -0.5/12.0)) && (peakHertz > pow (2, -1.0/12.0))){	
					text3->clear();
					text->setText("Low Do!");
					text3->setStyleSheet("color: black; background-color: white");
					text->setStyleSheet("color: black; background-color: red");	
				}
			}	
			else if ((peakHertz >= pow (2, 1.0/12.0)) && (peakHertz < pow (2, 3.0/12.0)) && (difftime(t1, t2) > duration)){
					//peakHertz(Re) = pow (2, 2/12.0));
					if((peakHertz >= pow (2,1.5/12.0))&& (peakHertz <= pow (2,2.5/12.0))){
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
					}
					else if((peakHertz > pow (2,2.5/12.0))&& (peakHertz < pow (2,3.0/12.0))){
						text->clear();	
						text3->setText("High Re!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");
					}
					else if((peakHertz > pow (2,1.0/12.0))&& (peakHertz < pow (2,1.5/12.0))){	
						text3->clear();
						text->setText("Low Re!");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
					}
			}
			else if ((peakHertz >= pow (2, 3.0/12.0)) && (peakHertz < pow (2, 4.5/12.0)) && (difftime(t1, t2) > duration)){
					//peakHertz(Mi) = pow (2, 4/12.0);
					if ((peakHertz >= pow (2,3.75/12.0))&& (peakHertz <= pow (2,4.25/12.0))){
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
					}
					else if((peakHertz > pow (2, 4.25/12.0)) && (peakHertz < pow (2, 4.5/12.0))){
						text->clear();	
						text3->setText("High Mi!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");
					}
					else if((peakHertz > pow (2, 3.0/12.0)) && (peakHertz <= pow (2, 3.75/12.0))){
						text3->clear();
						text->setText("Low Mi!");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
					}	
			}	
			else if((peakHertz >= pow ( 2,4.5/12.0)) && (peakHertz < pow ( 2,6.0/12.0))&& (difftime(t1, t2) > duration)){
					//	peakHertz(Fa)= pow (2, 5/12.0);
					if ((peakHertz >= pow (2, 4.75/12.0)) && (peakHertz <= pow (2, 5.5/12.0))){
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
					}
					else if((peakHertz > pow (2, 5.5/12.0)) && (peakHertz < pow (2, 6.0/12.0))){
						text->clear();	
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");
						text3->setText("High Fa!");
					}
					else if((peakHertz > pow (2, 4.5/12.0)) && (peakHertz < pow (2, 4.75/12.0))){	
						text3->clear();
						text->setText("Low Fa!");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
					}
			} 
			else if ((peakHertz >= pow ( 2, 6.0/12.0))  && (peakHertz < pow ( 2, 8.0/12.0))&& (difftime(t1, t2) > duration)){
					//  peakHertz(So)= pow (2, 7.0/12.0);
					if ((peakHertz >= pow (2, 6.5/12.0)) && (peakHertz <= pow (2, 7.5/12.0))){
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
					}
					else if ((peakHertz > pow (2, 7.5/12.0)) && (peakHertz < pow (2, 8.0/12.0))){
						text->clear();	
						text3->setText("High So!");
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");
					}
					else if ((peakHertz > pow (2, 6.0/12.0)) && (peakHertz < pow (2, 6.5/12.0))){
						text3->clear();
						text->setText("Low So!");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
					}	
			}
			else if((peakHertz >= pow (2, 8.0/12.0)) && (peakHertz < pow (2, 10.0/12.0))&& (difftime(t1, t2) > duration)){
					//	peakHertz(La)= pow (2, 9.0/12.0);			
					if ((peakHertz >= pow (2, 8.5/12.0)) && (peakHertz <= pow (2, 9.5/12.0))){
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
					}
					else if((peakHertz > pow (2, 9.5/12.0)) && (peakHertz < pow (2, 10.0/12.0))){
						text->clear();	
						text->setStyleSheet("color: black; background-color: white");
						text3->setStyleSheet("color: black; background-color: red");
						text3->setText("High La!");
					}
					else if((peakHertz > pow (2, 8.0/12.0)) && (peakHertz < pow (2, 8.5/12.0))){
						text->clear();	
						text3->clear();
						text->setText("Low La!");
						text3->setStyleSheet("color: black; background-color: white");
						text->setStyleSheet("color: black; background-color: red");
					}				
			}
			else if ((peakHertz >= pow (2, 10.0/12.0)) && (peakHertz < pow (2, 12.0/12.0)) && (difftime(t1, t2) > duration)){		
					// 	peakHertz(Ti) = pow (2, 11/12.0);
					if ((peakHertz >= pow (2, 10.5/12.0)) && (peakHertz <= pow (2, 11.5/12.0))){
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
					}
				else if ((peakHertz > pow (2, 11.5/12.0)) &&  (peakHertz < pow ( 2,12/12.0))){
							text->clear();	
							text->setStyleSheet("color: black; background-color: white");
							text3->setStyleSheet("color: black; background-color: red");
							text3->setText("High Ti!");
				}	
				else if ((peakHertz < pow (2, 10.5/12.0)) && (peakHertz > pow (2, 10/12.0))){
							text3->clear();
							text3->setStyleSheet("color: black; background-color: white");
							text->setStyleSheet("color: black; background-color: red");
							text->setText("Low Ti!");
				}
			}
			else{  
				text->clear();
				text3->setStyleSheet("color: black; background-color: white");
				text->setStyleSheet("color: black; background-color: white");
				pianoPlayer();
			}
		}
	}
}

void Window::stopRecording()
{
    audio->stop();
    delete audio;
	exitSlot();
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
	feedbackbutton->setStyleSheet("color: black; background-color: grey");   
	feedbackbutton->show();
    srand((unsigned) time(0));
    int randomNumber;
    for (int index = 0; index < 1; index++) {
    randomNumber = (rand() % 7) + 1;
    qDebug() << randomNumber;
	}
   
   if (randomNumber==1)
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
		connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
		connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		
	}
  		else if (randomNumber==2)
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
				connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
				connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));

			}
		else if (randomNumber==3)
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
				connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
				connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
			}
			
		else if (randomNumber==4)
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
				connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
				connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
		}
		else if (randomNumber==5)
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
				connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
				connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
			}	 
		else if (randomNumber==6)
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
				connect(dobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(rebutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(mibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(fabutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(sobutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));
				connect(labutton, SIGNAL(clicked()), this, SLOT(feedbackSlot()));
				connect(tibutton, SIGNAL(clicked()), this, SLOT(feedbackWrong()));			}	 
		else if (randomNumber==7)
		{   
				// reset player from begining 
				player = new QMediaPlayer;
				// Assign the si.mp3 to player 
				player->setMedia(QUrl::fromLocalFile(QDir("../audiofiles/ti.mp3").absolutePath()));
				// Set player volume 
				player->setVolume(90); 
				// Play the player audio 
				player->play();	  
				// Connect dobutton to detect if ti is pressed by the user  
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
	feedbackbutton->setStyleSheet("color: black; background-color: red");
}

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

void Window::clearnotes()
{
	melody->hide();
	melody->setText(tr("Melody here!"));
}

//this function is used to quit the application
void Window::quitApp()    
{ 
    Window::close();
}





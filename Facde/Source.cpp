#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\opencv.hpp>
#include <iostream> 
#include <stdlib.h>

using namespace cv;
using namespace std;

class photo_input
{
public:
    void Photo_Input()
    {
        CascadeClassifier faceDetection; // ->the cv::CascadeClassifier class to detect
                                         // objects in a video stream OR in image

        if (!faceDetection.load("D:\\OPENCV\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml"))
            //-> OpenCV already contains many pre-trained classifiers 
            //haarcascade_frontalface_default. xml is a haar cascade designed 
            //by OpenCV to detect the frontal face.
        {
            cout << " \n!!! You'r file is not loded properly !!!";
            exit(0); //stdlib.h
        }
        char path[100];
        cout << "\n Enter your path for face detction ::";
        cin.getline(path, 100); //Take the entery of image path
        cin >> path;
        Mat img = imread(path, IMREAD_UNCHANGED); // MAT: containing information such as the size of the matrix
                                                  // imread: Loads an image from a file.
                                                  // IMREAD_UNCHANGED: It loads the image in the original form
        if (img.empty())

        {
            cout << "\n!! Image is not loaded properly !!";
        }

        else
        {
            for (int i = 0; i < 90; i++)
            {
                printf("\xdb");
            }
            cout << "\n";
            cout << "\n!! Image is found !!" << endl;
            cout << "\n";
            for (int i = 0; i < 90; i++)
            {
                printf("\xdb");
            }
            cout << "\n Processing.......\n\n"
                << endl;

            vector<Rect> faces;
            // vector is a sequence container that encapsulates dynamic size arrays.
            // face will be detected around rectangles
            faceDetection.detectMultiScale(img, faces); //Decting here
                            //detectMultiScale function is used to detect the faces. 
                            //This function will return a rectangle with coordinates (x,y,w,h) around the detected face.
            for (int i = 0; i < faces.size(); i++)
            {
                Point pt1(faces[i].x, faces[i].y);
                Point pt2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width));
                rectangle(img, pt1, pt2, Scalar(20, 1000, 100), 2, 8, 0);
            }
            imwrite("C:\Photo_output\\Output.jpg", img);
            for (int i = 0; i < 90; i++)
            {
                printf("\xdb");
            }
            cout << "\n\n\n!! Face Detected !!\n\n\n"
                << endl;
            for (int i = 0; i < 90; i++)
            {
                printf("\xdb");
            }
            // Show thw output of the photo After detecting the face in the image
            string path = "C:\Photo_output\\Output.jpg";
            Mat img = imread(path, IMREAD_UNCHANGED);
            if (img.empty())
            {
                cout << endl;
                cout << "\t::Image path is incorrect ::\t\t";
            }
            else
            {
                imshow("Image", img);
                waitKey(0);
            }
        }
    }
};
class web_cam
{
public:
    int Web_Cam()
    {
        double scale = 4.0;
        CascadeClassifier faceCascade; // ->the cv::CascadeClassifier class to detect
                                       // objects in a video stream OR in image
        faceCascade.load("D:\\OPENCV\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml");
        //-> OpenCV already contains many pre-trained classifiers 
        //haarcascade_frontalface_default. xml is a haar cascade designed 
        //by OpenCV to detect the frontal face.
        VideoCapture cap(0);  //open the web cam

        if (!cap.isOpened())
            return -1;
        for (;;) //infinite loop for geting the frame(WebCam) 
        {
            Mat frame;
            cap >> frame;
            Mat grayscale;
            cvtColor(frame, grayscale, COLOR_BGR2GRAY);
            //converting the colour image into gray scale
            resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));
            //resize:: help us to get the fast responce it work more efficient
            //it will reduce the size of image 4 times to actual one
            vector<Rect> faces;
            //help to make rectanle around the face
            faceCascade.detectMultiScale(grayscale, faces);//Detect hear
                      //detectMultiScale function is used to detect the faces. 
                      //This function will return a rectangle with coordinates (x,y,w,h) around the detected face.
            for (Rect area : faces)
            {
                Scalar drawColor = Scalar(20, 100, 100);//colout of the rectangle (Blue)

                //rectangle is a function help in the formation of rectangle
                rectangle(frame, Point(cvRound(area.x * scale), cvRound(area.y * scale)),//top left point of rectangle
                    Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)), drawColor);
                //bottom right point of rectangle     

            }

            imshow("Webcam Frame", frame);//display the fram which will detect face

            if (waitKey(1) >= 0)
                break;
        }
    }
};
class click_photo
{
public:
    int Click_Photo()
    {

        //Open the first webcam plugged in the computer
        VideoCapture camera(0);
        if (!camera.isOpened())
        {
            cerr << "ERROR: Could not open camera" << std::endl;
            return 1;
        }

        //Create a window to display the images from the webcam
        namedWindow("Frame");

        //Pick up a new frame and display it until you press a key
        while (1)
        {
            //This will contain the image from the webcam
            Mat frame;

            //Capture the next frame from the webcam
            camera >> frame;

            //Show the image on the window
            imshow("Frame", frame);

            //Wait for a key to be pressed
            if (waitKey(1) >= 0) break;
        }
        //image will be saved 
        VideoCapture cap(0);
        // Get the frame
        Mat img;

        cap >> img;

        if (img.empty())
        {
            cerr << "Something is wrong with the webcam, could not get frame." << endl;
        }
        // Save the frame into a file
        imwrite("C:\Photo_output\\Output.jpg", img);
        // A JPG FILE IS BEING SAVED Success.
        // if the image is not save then if statement become true
        if (img.empty())
        {
            cout << "\n";
            cout << "\n";
            cout << endl;
            for (int i = 0; i < 90; i++)
            {
                printf("\xdb");
            }
            cout << endl;
            cout << "\t\t!!!!!!!!!!!!!!!!! Compilation not completed !!!!!!!!!!!!!!!!!";
            cout << endl;
            for (int i = 0; i < 90; i++)
            {
                printf("\xdb");
            }
            cout << endl;
            cout << "\n";
            cout << "\n";
        }

        else
        {

            CascadeClassifier faceDetection; // ->the cv::CascadeClassifier class to detect
                                                 // objects in a video stream OR in image

            if (!faceDetection.load("D:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml"))
                //-> OpenCV already contains many pre-trained classifiers for `
                // face XML files are stored in opencv/data/haarcascades/ folder.
            {
                cout << " \n!!! You'r file is not loded properly !!!";
                exit(0); //stdlib.h
            }
            string path = "C:\Photo_output\\Output.jpg";

            Mat img = imread(path, IMREAD_UNCHANGED); // MAT: containing information such as the size of the matrix
                                                      // imread: Loads an image from a file.
                                                      // IMREAD_UNCHANGED: It loads the image in the original form
            if (img.empty())

            {
                cout << "\n!! Image is not loaded properly !!";
            }
            else
            {
                for (int i = 0; i < 90; i++)
                {
                    printf("\xdb");
                }
                cout << "\n";
                cout << "\n!! Image is found !!" << endl;

                cout << "\n Processing.......\n\n"
                    << endl;
                for (int i = 0; i < 90; i++)
                {
                    printf("\xdb");
                }
                vector<Rect> faces;
                faceDetection.detectMultiScale(img, faces); //Decting here
                //detectMultiScale function is used to detect the faces. 
                //This function will return a rectangle with coordinates (x,y,w,h) around the detected face.
                for (int i = 0; i < faces.size(); i++)
                {
                    Point pt1(faces[i].x, faces[i].y);
                    Point pt2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width));
                    rectangle(img, pt1, pt2, Scalar(20, 100, 100), 2, 8, 0);
                }
                imwrite("C:\\Output_Photo\\Output.jpg", img);
                for (int i = 0; i < 90; i++)
                {
                    printf("\xdb");
                }
                cout << "\n";
                cout << "\n\n\n!! Face Detected !!\n\n\n"
                    << endl;
                for (int i = 0; i < 90; i++)
                {
                    printf("\xdb");
                }
                cout << "\n";
                // Show thw output of the photo After detecting the face in the image
                string path = "C:\\Output_Photo\\Output.jpg";
                Mat img = imread(path, IMREAD_UNCHANGED);
                if (img.empty())
                {
                    cout << endl;
                    cout << "\t::Image path is incorrect ::\t\t";
                }
                else
                {
                    imshow("Image", img);
                    waitKey(0);
                }
            }
        }

        return 0;
    }

};
int main()
{
    system("Color 0A");
    photo_input a1;
    web_cam a2;
    click_photo a3;

    int a;
    for (int i = 0; i < 90; i++)
    {
        printf("\xdb");
    }
    cout << "\n";
    cout << "\t\tPress { 1 } for face detection through WebCam ::\t\t "
        << endl
        << "Press { 2 } for face detection through giving a path of a photo stored in your system  :: "
        << endl
        << "Press { 3 } for face detection through Click live photo through your systeam Webcam  :: "
        << endl;
    for (int i = 0; i < 90; i++)
    {
        printf("\xdb");
    }
    cout << "\n";
    cin >> a;
    if (a == 2)
    {
        a1.Photo_Input();
    }
    if (a == 1)
    {
        a2.Web_Cam();
    }
    if (a == 3)
    {
        a3.Click_Photo();
    }
    return 0;
}
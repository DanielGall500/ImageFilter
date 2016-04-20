//
//  main.cpp
//  ImageFilter
//
//  Created by Daniel Gallagher on 19/04/2016.
//  Copyright (c) 2016 Developer Co. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main(int argc, const char * argv[]) {
    
    std::string imgName = "/Users/dannyg/Desktop/OpenCV/OpenCVTest/Resources/StarryNightRGB.jpg";
    std::string windowName = "Image Filter";
    int filterInput;
    
    Mat img = imread(imgName);
    Mat dst;
    
    if(!img.data)
    {
        return -1;
    }
    
    Mat kernel; // the kernel to be scanned through the image
    int kernel_size;
    
    Point anchor; // position of the anchor relative to the kernel; (-1,-1) = kernel center
    
    double delta; // a value to be added to each pixel during the convolution
    
    int ddepth; //the destination of the destination image
                //(a negative value indicates the depth is same as source
    
    namedWindow(windowName, CV_WINDOW_AUTOSIZE);
    
    int ind = 0;
    int c;
    
    std::cout << "Choose a filter: Blur[0]; Brightness[1]" << std::endl;
    std::cin >> filterInput;
    
    if(filterInput == 0)
    {
        anchor = Point(-1,-1);
        delta = 0;
        ddepth = -1;
        
        while (true)
        {
            c = waitKey(500);

            kernel_size = 3 + 2 * (ind%5);
            kernel = Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size*kernel_size);
            
            filter2D(img, dst, ddepth, kernel, anchor, delta, BORDER_DEFAULT);
            
            imshow(windowName, dst);
            ind++;
            
        }
    }
    else if (filterInput == 1)
    {
        anchor = Point(-1,-1);
        delta = 0;
        ddepth = -1;
        
        while(true)
        {
            c = waitKey(500);
            
            kernel_size = 3 + 2 * (ind%5);
            kernel = Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size*kernel_size);
            
            filter2D(img, dst, ddepth, kernel, anchor, delta, BORDER_DEFAULT);
            
            imshow(windowName, dst);
            delta += 10;
            
        }
    }
    else
    {
        std::cout << "No Filter ID Found: " << filterInput << std::endl;
        return -1;
    }
    
    
    
}



























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
    
    anchor = Point(-1,-1);
    delta = 0;
    ddepth = -1;
    
    int ind = 0;
    int c;
    
    while (true)
    {
        c = waitKey(500);
        
        if((char)c == 27)
            break;
        
        kernel_size = 3 + 2 * (ind%5);
        kernel = Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size*kernel_size);
        
        filter2D(img, dst, ddepth, kernel, anchor, delta, BORDER_DEFAULT);
        imshow(windowName, dst);
        ind++;
    }
    
    
    
}



























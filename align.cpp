
//#include "TestFaceDetection.inc.h"

//using namespace FaceInception;
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <cstring>
#include <string>
#include "dataInput.hpp"

//#include <typeinfo>
// #include "json/json.h"
using namespace std;
using namespace FaceInception;
using nlohmann::json; 
using std::cout;
using std::endl;
using cv::Mat;

//vector<vector<cv::Point2d>> getPoints(string filename);

int main()
{   
    //vector<Point2d> target_points = { {17.5847, 24.7613},{43.8201, 24.7886},{30.9560, 39.2175},{19.1454, 45.3803},{41.9191, 45.6016} };
    std::vector<cv::Point2d> target_points = {{13.5847, 20.7613}, {39.8201, 20.7886}, {26.9560, 35.2175}, {14.1454, 41.3803}, {37.9191, 41.6016}};

    //cv:Mat image =imread("")

    //vector<vector<Point2d>> points;
    //std::cout << target_points[0].x << ", " << target_points[0].y << std::endl;
    //std::cout << target_points.size() << std::endl;
    string json_filename = "/Users/bin/Desktop/mark_det_pose_demo_py27/result/pose_result.json";
    
    // auto points = getPoints(json_filename);
    auto points = getPointsSinglePic(json_filename);

    Mat show_image = image.clone();

    vector<Mat> croppedImages;
    for(int i=0; i<points.size(); i++){
        cout << points[i]<< endl;

        vector<string> v;
        //     ../../AdienceBenchmark/face/faces/63153065@N07/coarse_tilt_aligned_face.243.9157547453_fc979e7025_o.jpg
        SplitString(points[i].second, v, "/")
        string read_root_path = "/workspace/mnt/group/face-det/zhubin/AdienceBenchmark/face/faces/" ///////////////////
        string write_root_path = "/workspace/mnt/group/face-det/zhubin/detection_keypoint2/detection_keypoint/keypoint_dir/"  ////////////////////////////////////////////////////////

        write_root_dir = write_root_path + v[5];
        if(! dirExists(write_root_dir)){
            system(write_root_dir)；
        }
        string pic_path = write_root_path + "/" + v[6];

        read_root_path = read_root_path + v[5] + "/" + v[6];



        Mat image = imread(read_root_path);



        Mat trans_inv;
        Mat trans = findSimilarityTransform(points[i].first, target_points, trans_inv);
        Mat cropImage;
        warpAffine(image, cropImage, trans, Size(56, 56));
        
        
        
        
        imwrite(pic_path, cropImage);
        //imshow("cropImage", cropImage);
        //croppedImages.push_back(cropImage);

        // display rotated bounding box 
        // vector<Point2d> rotatedVertex;
        // transform(getVertexFromBox(Rect(0,0,56,56)), rotatedVertex, trans_inv);
        // for (int i = 0; i < 4; i++)
        //     line(show_image, rotatedVertex[i], rotatedVertex[(i + 1) % 4], Scalar(0, 255, 0), 2);
        // imshow("cropImage", show_image);
        // waitKey(0);
    }



    // cout << "dasddsds" << endl;
    // for(const auto& pt : points)
    // {
    //     cout << pt << endl;
    // }
    
    


    // std::ifstream jsonConfigFileStream(json_filename, std::ifstream::in);
    // json jsonConfigRoot;

    // if (jsonConfigFileStream.is_open()) {
    //     jsonConfigFileStream >> jsonConfigRoot;
    // }
    // std::cout << jsonConfigRoot["result"] << endl;




    
    // std::vector <json> allJson;
    // std::ifstream i(json_filename);
    // json j = json::parse(i);
    // std::cout << j << endl;
    // std::cout << "---1111111---------------------" << endl;
    // for(auto it=j.begin(); it!=j.end(); ++it){
    //     //std::cout << it << endl;
    //     std::cout << "------------------------" << endl;
    // }


    // std::ifstream jsonConfigFileStream(json_filename, std::ifstream::in);
    // json jsonConfigRoot;

    // if (jsonConfigFileStream.is_open()) {
    //     jsonConfigFileStream >> jsonConfigRoot;
    // }
    // std::cout << jsonConfigRoot << endl;

    // std::ifstream ifs (json_filename, std::ifstream::in);
    // json jsonConfigRoot;

    // char c = ifs.get();
    

    // while (ifs.good()) {
        
    //     std::cout << "s";
    //     c.erase(0,c.find_first_not_of(" "));
    //     c.erase(c.find_last_not_of(" ") + 1);
    //     c >> jsonConfigRoot;

    //     c = ifs.get();
    // }

    // ifs.close();


    // json j2 = {
    //     {"pi", 3.141},
    //     {"happy", true},
    //     {"name", "Niels"},
    //     {"nothing", nullptr},
    //     {"answer", {{"everything", 42}}},
    //     {"list", {1, 0, 2}},
    //     {"object", {{"currency", "USD"}, {"value", 42.99}}}
    // };

    // cout << j2["pi"] << endl;
    // cout << j2.dump() << endl;

    return 0;
}


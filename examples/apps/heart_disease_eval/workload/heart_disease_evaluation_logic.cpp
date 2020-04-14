/* Copyright 2019 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <string>
#include <cmath>
#include "heart_disease_evaluation_logic.h"

// Calculate risk of having heart disease given input parameters.

HeartDiseaseEvalLogic::HeartDiseaseEvalLogic() {}

HeartDiseaseEvalLogic::~HeartDiseaseEvalLogic() {}

template<typename Out>
void split(const std::string &str, char delim, Out result) {
        std::size_t current, previous = 0;

        current = str.find(delim);
        while (current != std::string::npos) {
                std::string item = str.substr(previous, current - previous);
                if (item.compare("") != 0)
                        *(result++) = item;
                previous = current + 1;
                current = str.find(delim, previous);
        }

        std::string item = str.substr(previous, current - previous);
        if (item.compare("") != 0)
                *(result++) = item;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

int HeartDiseaseEvalLogic::score_1(const std::string &str) {
    int score;
    if(str == "Y"){
        score = 60;
    }
    else {
        score = 0;
    }
    return score;
}

int HeartDiseaseEvalLogic::score_2(const std::string &str) {
    int score;
    if(str == "Y"){
        score = 15;
    }
    else {
        score = 0;
    }
    return score;
}

int HeartDiseaseEvalLogic::score_3(const std::string &str) {
    int score;
    if(str == "Y"){
        score = 15;
    }
    else {
        score = 0;
    }
    return score;
}

int HeartDiseaseEvalLogic::score_4(const std::string &str) {
    int score;
    if(str == "Y"){
        score = 29;
    }
    else {
        score = 0;
    }
    return score;
}

int HeartDiseaseEvalLogic::score_5(const std::string &str) {
    int score;
    if(str == "Y"){
        score = 0;
    }
    else {
        score = 0;
    }
    return score;
}

int HeartDiseaseEvalLogic::score_6(const std::string &str) {
    int score;
    if(str == "Y"){
        score = 0;
    }
    else {
        score = 0;
    }
    return score;
}

int HeartDiseaseEvalLogic::score_7(const std::string &str) {
    int score;
    if(str == "Y"){
        score = 0;
    }
    else {
        score = 0;
    }
    return score;
}

int HeartDiseaseEvalLogic::score_8(const std::string &str) {
    int score;
    if(str == "Y"){
        score = -15;
    }
    else {
        score = 0;
    }
    return score;
}

// Process work order input for heart disease risk factors
std::string HeartDiseaseEvalLogic::executeWorkOrder(
        std::string decrypted_user_input_str) {
    std::string resultString;
    static int totalTests = 0;
    static int possitiveTests = 0;


    try {
        std::string dataString;
        std::vector<std::string> inputString =
            split(decrypted_user_input_str, ':');
        if (inputString.size() > 1)
            dataString = inputString[1];

        std::vector<std::string> medData = split(dataString, ' ');
        switch (medData.size()) {
        case 1: {
            if(totalTests > 0){
                if(possitiveTests == 0){
                    resultString = "None of the users seems to have COVID symptoms";
                }
                else {
                    int percentage = possitiveTests * 100 / totalTests;
                    resultString = std::to_string(percentage) + "% of the users present COVID_19 symptoms";
                }
            }
        }
        case 8: { // return individual calculation
            try {
                int risk = score_1(medData[0])
                    + score_2(medData[1])
                    + score_3(medData[2])
                    + score_4(medData[3])
                    + score_5(medData[4])
                    + score_6(medData[5])
                    + score_7(medData[6])
                    + score_8(medData[7]);
                if (risk > 30) {
                    possitiveTests++;    
                }
                totalTests++;
                resultString = "User info processed";
                break;
            } catch (std::invalid_argument& ia) {
                resultString = "Invalid data found in input data";
                break;
            }
        }
        case 9: { // return individual calculation
            try {
                int risk = score_1(medData[0])
                    + score_2(medData[1])
                    + score_3(medData[2])
                    + score_4(medData[3])
                    + score_5(medData[4])
                    + score_6(medData[5])
                    + score_7(medData[6])
                    + score_8(medData[7]);

                // Format the result
                if (risk > 30) {
                    resultString = "It is possible that you have the COVID-19 please take a look at the advices";
                }
                else {
                    resultString = "Probably you don't have the COVID-19 but take care";
                }
                break;
            } catch (std::invalid_argument& ia) {
                resultString = "Invalid data found in input data";
                break;
            }
        }
        default: // error
            return "Error with missing or incorrect input format";
        }
    } catch (...) {
        resultString = "Caught exception while processing workload data";
    }
    return resultString;
}


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
#include <vector>

class HeartDiseaseEvalLogic {
private:
        int score_1(const std::string &str);
        int score_2(const std::string &str);
        int score_3(const std::string &str);
        int score_4(const std::string &str);
        int score_5(const std::string &str);
        int score_6(const std::string &str);
        int score_7(const std::string &str);
        int score_8(const std::string &str);

public:
        HeartDiseaseEvalLogic(void);
        ~HeartDiseaseEvalLogic(void);

        std::string executeWorkOrder(std::string decrypted_user_input_str);
};


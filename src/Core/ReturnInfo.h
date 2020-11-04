//
// Created by ilya on 03.11.2020.
//

#ifndef DAC_RETURNINFO_H
#define DAC_RETURNINFO_H

#include <iostream>

/*
 * This namespace is in charge
 * of operation result
 *
 * @author Ilya Dmitriev
 */

namespace Return{

   /*
    * Structures containing info
    * about the execute result of
    * service request.
    */
    struct Info {
        enum class Type {
            SUCCESS,
            FAILURE
        };
        Type result;
        std::string error;
    };

   /*
    * Function that creates struct Info
    */
    static Info create(bool result, std::string error){
        Info return_info;
        if (result) {
            return_info.result = Info::Type::SUCCESS;
        }
        else {
            return_info.result = Info::Type::FAILURE;
        }
        return_info.error = error;
        return return_info;
    }

}
#endif //DAC_RETURNINFO_H

//
// Created by ilya on 03.11.2020.
//

#ifndef DAC_EXECUTER_H
#define DAC_EXECUTER_H

#include "Core/DACService.h"

namespace executer{
    /*
     *
     * @return [error code]
     * 0 - everything is ok.
     * 1 - incorrect number of arguments
     * 2 - not an absolute path
     * 3 - service directory not enough rights to create here
     * 4 - directory is already used by another instance of application
     */
    static int run(int argc, char *argv[]){
        if(argc != 2){
            std::cout << "Incorrect number of arguments!\n";
            return 1;
        }
        auto service = std::make_unique<DACService>(argv[1]);

        auto response = service->is_absolute();
        if(response.result == Return::Info::Type::FAILURE){
            std::cout << "path: "<< argv[1]<< " is not an absolute path!\n";
            return 2;
        }

        auto response_exists = service->exists();
        if (response_exists.result == Return::Info::Type::SUCCESS){
            std::cout<<"This directory already exists.\n";
        }

        auto response_permisson = service->permission();
        if (response_permisson.result == Return::Info::Type::SUCCESS){
            std::cout << "You have the rights to create here\n";
        }
        else {
            std::cout <<response_permisson.error;
            return 3;
        }

        if (service->is_used().result == Return::Info::Type::SUCCESS){
            std::cout<<"This directory is already used by another instance of application!\n";
            return 4;
        }
        else {
            service->mark_as_used();
            std::cout<<"This instance just has been started using this directory.\n";
        }
        std::cout<<"Press any key to finish!\n";
        getchar();

        return 0;
    }

}

#endif //DAC_EXECUTER_H

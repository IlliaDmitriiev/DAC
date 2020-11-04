//
// Created by ilya on 03.11.2020.
//

#ifndef DAC_SERVICE_H
#define DAC_SERVICE_H

#include "ReturnInfo.h"
#include <experimental/filesystem>
namespace filesystem = std::experimental::filesystem;

/*
 * Directory access checker.
 * Service which able to do
 * all the required requests.
 */
class Service{
public:
    /*
     * creates directory by given path
     */
    virtual Return::Info create_directory() = 0;
    /*
     * checks if the directory
     * by given path exists
     */
    virtual Return::Info exists() = 0;
    /*
     * checks if the user has
     * permission to create smth
     * in directory by given path
     */
    virtual Return::Info permission() = 0;
    /*
     * checks if the other instanse of
     * this application uses the given
     * directory
     */
    virtual Return::Info is_used() = 0;
    /*
     * checks if the other given path
     *  is absolute
     */
    virtual Return::Info is_absolute() = 0;
    /*
     * marks that the given
     * directory is used
     */
    virtual void mark_as_used() = 0;

    virtual ~Service() = default;

};

#endif //DAC_SERVICE_H

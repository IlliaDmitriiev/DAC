//
// Created by ilya on 03.11.2020.
//

#ifndef DAC_DACSERVICE_H
#define DAC_DACSERVICE_H

#include "Service.h"

class DACService: public Service {

public:
    DACService(filesystem::path path): path_(path){
        origin_ =filesystem::status(path).permissions();
    }

public:
    /* method: сreates directory.
     *
     * @return object containing info about possible error occurred
     * or info that operation is successful.
     */
    Return::Info create_directory() override;
    /* method: checks for folder presence.
     *
     * @return object containing info about possible error occurred
     * or info that operation is successful.
     */
    Return::Info exists() override;
    /* method: checks for permission
     *
     * @return object containing info about possible error occurred
     * or info that operation is successful.
     */
    Return::Info permission() override;
    /*
     * checks if the other given path
     *  is absolute
     */
    Return::Info is_absolute() override;
    /* method: checks if other application uses this dir.
     *
     * @return object containing info about possible error occurred
     * or info that operation is successful.
     */
    Return::Info is_used() override;
    /* method: marks directory as used
     */
    void mark_as_used() override;
    /*
     * Stop using the directory
     * and allow to use it others.
     */
    ~DACService() override;

private:
    filesystem::path path_;
    filesystem::perms origin_;
};

#endif //DAC_DACSERVICE_H

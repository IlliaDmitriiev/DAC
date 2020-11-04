//
// Created by ilya on 03.11.2020.
//

#include "DACService.h"
#include <exception>

Return::Info DACService::create_directory() {
    bool result = filesystem::create_directories(path_);
    return Return::create(result, "");
}

Return::Info DACService::exists() {
    bool result = filesystem::exists(path_);
    return Return::create(result, "");
}

Return::Info DACService::permission() {
    bool result = true;
    std::string error;

    try {
        create_directory();
    }
    catch (std::exception) {
        error = "Permission denied. You don't have rights to create files in this directory.\n";
        result = false;
        return Return::create(result, error);
    }
    return Return::create(result, error);
}

Return::Info DACService::is_used() {
    filesystem::file_status file_status = status(path_);
    auto res = file_status.permissions();
    if (filesystem::perms::owner_read == res) {
        return Return::create(true, "");
    }
    else {
        return Return::create(false, "");
    }
}

Return::Info DACService::is_absolute() {
    return Return::create(path_.is_absolute(),"");
}

void DACService::mark_as_used() {
    filesystem::permissions(path_,filesystem::perms::owner_read);
}

DACService::~DACService(){
    try {
        filesystem::permissions(path_, origin_);
    }
    catch (std::exception e) {
        std::cout << "Service directory\n";
    }
}

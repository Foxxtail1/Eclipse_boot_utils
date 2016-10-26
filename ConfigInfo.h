//
// Created by Alex on 10/26/2016.
//

#ifndef ECLIPSE_AUTO_WORKSPACE_CONFIGINFO_H
#define ECLIPSE_AUTO_WORKSPACE_CONFIGINFO_H
#include "all_inlcudes.h"

static const string CONFIG_FILE_NAME = "config.conf";
static const string CONFIG_WORKSPACE_PARAM = "workspace_path=";
static const string ECLIPSE_EXE_PATH = "C:\\eclipse\\eclipse.exe";

class ConfigInfo {
    private:
        string rawPath;
        char driveLetter;
    public:
    ConfigInfo();
    string getRawPath();
    void setRawPath(string pConfigPath);
    char getDriveLetter();
    void setDriveLetter();
    string buildFullPath();
};

string findRawPath(string pPath);
char findDriveLetter();
bool doesPathExist(string pPath);
bool doesFileExist(string pPath);
bool createConfig(string pPath);

#endif //ECLIPSE_AUTO_WORKSPACE_CONFIGINFO_H

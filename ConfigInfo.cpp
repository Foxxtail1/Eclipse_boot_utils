//
// Created by Alex on 10/26/2016.
//

#include "ConfigInfo.h"
#include "all_inlcudes.h"


ConfigInfo::ConfigInfo()
{
    setRawPath(CONFIG_FILE_NAME);
    setDriveLetter();
    buildFullPath();
}
//SET==================================================
void ConfigInfo::setRawPath(string pConfigPath)
{
   rawPath = findRawPath(pConfigPath);
}
void ConfigInfo::setDriveLetter()
{
    driveLetter = findDriveLetter();
}
//GET==================================================
string ConfigInfo::getRawPath()
{
    return rawPath;
}
char ConfigInfo::getDriveLetter()
{
   return driveLetter;
}
//MISC OF CLASS========================================
string ConfigInfo::buildFullPath()
{
    string drive = "";
    drive += getDriveLetter();
    return drive + ":\\" + getRawPath();
}
//MISC=================================================
bool doesPathExist(string pPath)
{
    bool output = false;
    DWORD path = GetFileAttributesA(pPath.c_str());
    if (path != INVALID_FILE_ATTRIBUTES)
    {
        if (path & FILE_ATTRIBUTE_DIRECTORY)
        {
            //path exist
            output = true;
        }
    }
    return output;
}

bool doesFileExist(string pPath)
{
    ifstream output(pPath.c_str());
    return output.good();
}
string findRawPath(string pPath)
{
    string output = " ";
    ifstream input(pPath.c_str());
    if (input.is_open())
    {
        cout << "its opened" << endl;
        input >> output;
        size_t pos = CONFIG_WORKSPACE_PARAM.length();
        output.erase(0, pos);
    }
    return output;
}
char findDriveLetter()
{
    char output[255];
    _getcwd(output,255);
    return output[0];
}
bool createConfig(string pPath)
{
bool out = false;
ofstream output("config.conf");
if (output.is_open()) {
output << CONFIG_WORKSPACE_PARAM << pPath;
output.close();
out = true;
}
return out;
}

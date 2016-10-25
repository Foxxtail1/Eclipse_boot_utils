#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <afxres.h>
#include <Shlwapi.h>
#include <windows.h>

using namespace std;

const string CONFIG_FILE_NAME = "config.conf";
const string CONFIG_WORKSPACE_PARAM = "workspace_path=";
const string ECLIPSE_EXE_PATH = "C:\\eclipse\\eclipse.exe";

bool doesExist(string pPath);
bool createConfig(string pPath);
string readConfig();
bool doesPathExist(string pPath);
string addDriveToPath(string pPath);

struct stat info;

int main()
{
    string path;
    string command;
    //Does the config file exist?
    if (!doesExist(CONFIG_FILE_NAME))
    {
        //Create new config
        cout << "Pleas enter the path of the workspace: ";
        cin >> path;
        if(!createConfig(path))
        {
            cout << "An error has prevented the creation of a config file" << endl;
        }
    }
    else
    {
        //Read
        cout << "READING CONFIG" << endl;
        path = readConfig();
        cout << "This is the path: " << path << endl;
        if(path.empty())
        {
            cout << "No path could be found in the config" << endl;
            cout << path;
        }
        else
        {
           if(doesPathExist(ECLIPSE_EXE_PATH.c_str()))
            {
                cout << "Could not find Eclipse.exe in default path " << ECLIPSE_EXE_PATH << endl;
            }
            else
           {
               command = ECLIPSE_EXE_PATH + " -data " + path;
               cout << "can execute here is the command: " << command << endl;
               system(command.c_str());
               //LPSTR s = const_cast<char *>(command.c_str());
               //CreateProcess(NULL, s,NULL,NULL,false,0,NULL,NULL,NULL,NULL);
               system("exit");
               //ShellExecute(0,"open","cmd.exe", command.c_str(), 0, SW_HIDE);
           }


        }

    }
    return 0;
}
bool doesExist(string pPath)
{
    ifstream f(pPath.c_str());
    return f.good();
}
bool doesPathExist(string pPath)
{
    bool out = stat(pPath.c_str(), &info);
    cout << "The path exists: " << out << endl;
    return out;
}
string addDriveToPath(string pPath)
{
    char buff[255];
    _getcwd(buff,255);
    string bu = buff;
    bu.erase(1, bu.length());
    string out = bu + ":" + pPath;
    return out.c_str();
}

string readConfig()
{
    string out = "";

    ifstream input(CONFIG_FILE_NAME.c_str());
    cout << "got to read" << endl;
    if (input.is_open())
    {
        cout << "its opened" << endl;
        input >> out;
        cout << "before erase" << endl;
        cout << out << endl;
        cout << "now calculation erase buffer" << endl;
        size_t pos = CONFIG_WORKSPACE_PARAM.length();

        cout << pos << endl;
        out.erase(0, pos);
        cout << "After erase" << endl;
        cout << out << endl;
        out = addDriveToPath(out);
    }
    return out;
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
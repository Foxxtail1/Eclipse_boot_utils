#include "all_inlcudes.h"
#include "ConfigInfo.h"

int main()
{
    string path;
    string command;
    //Does the config file exist?
    if (!doesFileExist(CONFIG_FILE_NAME))
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
        ConfigInfo reader;
        //Read
        if(reader.getRawPath().empty() || !doesPathExist(reader.buildFullPath()))
        {
            cout << "No valid path could be found in the config" << endl;
        }
        else
        {


                if (doesPathExist(ECLIPSE_EXE_PATH))
                {
                    cout << "Could not find Eclipse.exe in default path " << ECLIPSE_EXE_PATH << endl;
                }
                else {
                    command = ECLIPSE_EXE_PATH + " -data " + reader.buildFullPath();
                    cout << "The state of existance is: " << doesPathExist(reader.buildFullPath()) << endl;

                    cout << "can execute here is the command: " << command << endl;
                    // system(command.c_str());
                    //LPSTR s = const_cast<char *>(command.c_str());
                    //CreateProcess(NULL, s,NULL,NULL,false,0,NULL,NULL,NULL,NULL);
                    system("exit");
                    //ShellExecute(0,"open","cmd.exe", command.c_str(), 0, SW_HIDE);
                }

        }
    }
    return 0;
}


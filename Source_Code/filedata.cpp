#include "filedata.h"

fileData::fileData() : _exitstatus(-1)
{


}

fileData::~fileData()
{


}

fileData::fileData(QString directory,QString filename) : _directory(directory) , _filename(filename), _exitstatus(-1)
{

}

void fileData::setDirectory(QString directory)
{
    _directory = directory;
}

void fileData::setFileName(QString filename)
{
    _filename = filename;
}

void fileData::setExitStatus(int exit)
{
     _exitstatus = exit;
}

QString fileData::getDirectory()
{
    return(_directory);
}

QString fileData::getFileName()
{
    return(_filename);
}

int fileData::getExitStatus()
{
    return(_exitstatus);
}

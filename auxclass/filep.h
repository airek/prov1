#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class FileP
{
public:
    /*! Constructors */
    FileP();
    FileP(FileP &wzor){mFile=wzor.mFile;}
    FileP(string &file){mFile=file;}
    /*! Destructor */
    virtual ~FileP(){}

    void setFile(string file);
    string getFile();

    /*! methods */
    virtual bool addRefLine(string &line); /// add data to file  which are sending by ref
    virtual bool addValLine(string line); /// adding data to file which are sending by val
    virtual string readLine()const; /// read first line from the file
    virtual bool readLine(string *wsk)const; /// this function read data and assign it to the string pointer if action was success the return true
    virtual bool readFile(string *wsk)const; /// this function read whole file and assign it to the string pointer. If action was successful the return true
    virtual bool readLastLine(string *wsk); /// this function read only last line from the whole file !!! currently this doesn't work properly


protected:
    string mFile;
};

#endif // FILE_H

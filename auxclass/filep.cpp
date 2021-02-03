#include "filep.h"
#include <vector>

/*! **********************************************************
  \Class FileP
  resposnible for service the files on the disk.
  Class offers posibility to read an write data to the file

  \Author:Ireneusz Karbownik

  \Date:24.08.2011

  **********************************************************/
FileP::FileP()
{

}
/*! setter file */
void FileP::setFile(string file)
{
    mFile=file;
}
/*! getter file name */
string FileP::getFile()
{
    return mFile;
}
/*! this method add new data to the file according recived  by ref argument*/
bool FileP::addRefLine(string &line)
{
    ofstream stream; /// stream to write data

    stream.open(mFile.c_str(),ios::out|ios::app);

    if(stream.good())
    {
        stream<<line<<endl;

    }else{return false;}

    stream.close();
    return true;

}
/*! this method add new data to the file according recived  by val argument*/
bool FileP::addValLine(string line)
{
    ofstream stream; /// stream to write data

    stream.open(mFile.c_str(),ios::out|ios::app);

    if(stream.good())
    {
        stream<<line<<endl;

    }else{return false;}

    stream.close();
    return true;

}
/*! This function read first line of the mFile and return string reference */
string FileP::readLine()const
{
    string line;
    string falseResult("False");

    ifstream strum;/// stream to the file

    /// opening file
    strum.open(mFile.c_str(),ios::in);
    /// cjecking if result is ok
    if(strum.good())
    {
        getline(strum,line);
        strum.close();
        return line;
    }

        return falseResult;

}
/*! this function read data from file and writes results
  to string pointer if an error occure then 0 ist reurtn
  else 1 is return */
bool FileP::readLine(string *wsk)const
{
    ifstream strum;
    string line;

    strum.open(mFile.c_str(),ios::in);

    if(strum.good())
    {
        getline(strum,line);
        *wsk=line;
        strum.close();
        return true;
    }

        return false;

}
/*! this function read whole file till the eol
  data are assigned to pointer if file was open then
  return 1 else 0 means file was not open */
bool FileP::readFile(string *wsk)const
{
    string line;
    ifstream strum;

    /// strum opening
    strum.open(mFile.c_str(),ios::in);

    ///if file is open
    if(strum.good())
    {
        /// reading whole file
        while(!strum.eof())
        {
            getline(strum,line);
            *wsk+=line;
            line.clear();

        }
            strum.close();
            return true;
    }
            return false;


}
/*! This function read last line of the file
  and return if opening was successful or false if not
  line is assigning to string pointer */
bool FileP::readLastLine(string *wsk)
{
    string line;
    ifstream strum;
    vector<string>fileConetnt;
    strum.open(mFile.c_str(),ios::in);
    /// if filewas not open the false
    if(strum.good()){
        while(!strum.eof())
        {
            getline(strum,line);
            if(!line.empty())
                fileConetnt.push_back(line);

        }
            /// closing file
            strum.close();
            ///to check the vector size
            int fileContentSize;
            fileContentSize=fileConetnt.size();
            /// assigning to pointer
            *wsk=fileConetnt[fileContentSize-1];

            return true;

        }else{
            return false;
        }

}
